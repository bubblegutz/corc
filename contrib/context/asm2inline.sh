#!/bin/sh  
# Generate monolithic inline assembly header from ALL boostorg/context asm files  
  
set -e  
  
OUTPUT_HEADER="boost_context_asm.h"  
  
printf "Generating monolithic assembly header...\n"  
  
# Start generating header  
cat > "$OUTPUT_HEADER" << 'EOF'  
/* Monolithic inline assembly from boostorg/context */  
#ifndef BOOST_CONTEXT_ASM_H  
#define BOOST_CONTEXT_ASM_H  
  
#include <stddef.h>  
  
/* Context structure definitions */  
typedef struct fcontext_t *fcontext_t;  
typedef struct {  
    fcontext_t fctx;  
    void *data;  
} transfer_t;  
  
EOF
  
# Find all assembly files  
printf "Processing all assembly files...\n"  
find src/asm -name "*.S" -o -name "*.asm" | sort | while read -r asm_file; do  
    # Extract function type and platform info from filename  
    basename=$(basename "$asm_file")  
      
    # Parse filename: make_x86_64_sysv_elf_gas.S  
    func_type=$(printf "%s\n" "$basename" | cut -d'_' -f1)  
    arch=$(printf "%s\n" "$basename" | cut -d'_' -f2)  
    abi=$(printf "%s\n" "$basename" | cut -d'_' -f3)  
    format=$(printf "%s\n" "$basename" | cut -d'_' -f4)  
    assembler=$(printf "%s\n" "$basename" | cut -d'_' -f5 | cut -d'.' -f1)  
      
    printf "Processing: %s (func=%s, arch=%s, abi=%s, format=%s, assembler=%s)\n" \
           "$basename" "$func_type" "$arch" "$abi" "$format" "$assembler"  
      
    # Generate preprocessor condition  
    cat >> "$OUTPUT_HEADER" << EOF  
  
#if defined(__${arch}__) && defined(__${abi}__) && defined(__${format}__) && defined(__${assembler}__)  
/* Inline assembly for ${func_type}_${arch}_${abi}_${format}_${assembler} */  
EOF
      
    # Convert assembly to inline C  
    printf "static inline\n" >> "$OUTPUT_HEADER"  
      
    case "$func_type" in  
        "make")  
            printf "fcontext_t %s_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {\n" \
                   "$func_type" >> "$OUTPUT_HEADER"  
            ;;  
        "jump")  
            printf "transfer_t %s_fcontext(fcontext_t const to, void *vp) {\n" \
                   "$func_type" >> "$OUTPUT_HEADER"  
            ;;  
        "ontop")  
            printf "transfer_t %s_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {\n" \
                   "$func_type" >> "$OUTPUT_HEADER"  
            ;;  
    esac  
      
    printf '    __asm__ volatile (\n' >> "$OUTPUT_HEADER"  
      
    # Process assembly file line by line  
    while IFS= read -r line; do  
        # Skip comments, empty lines, and preprocessor directives  
        case "$line" in  
            \/*|*\*|""|" "*) continue ;;  
            \#*) continue ;;  
        esac  
          
        # Skip directives that don't work in inline asm  
        case "$line" in  
            .file*|.globl*|.hidden*|.type*|.align*|.size*|.section*) continue ;;  
            .def*|.scl*|.endef*|.set*) continue ;;  
            .code|.text|.data) continue ;;  
            .endprolog|.seh_proc*|.seh_endprologue*) continue ;;  
            BOOST_CONTEXT_EXPORT*) continue ;;  
            .ent|.frame|.mask|.fmask) continue ;;  
            .p2align*|.balign*|.pushsection*|.popsection) continue ;;  
            .long*|.asciz*) continue ;;  
            AREA|PROC|ENDP) continue ;;  
        esac  
          
        # Handle label definitions (remove trailing colon for inline asm)  
        if printf "%s\n" "$line" | grep -q '^[a-zA-Z_][a-zA-Z0-9_]*:$'; then  
            label=$(printf "%s\n" "$line" | sed 's/:$//')  
            printf "        \"%s:\\n\"\n" "$label" >> "$OUTPUT_HEADER"  
            continue  
        fi  
          
        # Handle MASM directives  
        case "$line" in  
            .386|.XMM|.model|.code|.PROTO) continue ;;  
        esac  
          
        # Escape quotes and add to inline asm (NO \n - each line is separate)  
        escaped_line=$(printf "%s\n" "$line" | sed 's/"/\\"/g')  
        printf "        \"%s\"\n" "$escaped_line" >> "$OUTPUT_HEADER"  
    done < "$asm_file"  
      
    printf '    : /* no output */\n' >> "$OUTPUT_HEADER"  
    printf '    : /* no input */\n' >> "$OUTPUT_HEADER"  
    printf '    : \"memory\", \"cc\"\n' >> "$OUTPUT_HEADER"  
    printf '    );\n' >> "$OUTPUT_HEADER"  
      
    # Add return statement based on function type  
    case "$func_type" in  
        "make")  
            printf '    return (fcontext_t)sp; /* Simplified return */\n' >> "$OUTPUT_HEADER"  
            ;;  
        "jump"|"ontop")  
            printf '    transfer_t t = {0, vp}; return t; /* Simplified return */\n' >> "$OUTPUT_HEADER"  
            ;;  
    esac  
      
    printf '}\n' >> "$OUTPUT_HEADER"  
    printf '#endif /* defined(__%s__) && defined(__%s__) && defined(__%s__) && defined(__%s__) */\n' \
           "$arch" "$abi" "$format" "$assembler" >> "$OUTPUT_HEADER"  
done  
  
cat >> "$OUTPUT_HEADER" << 'EOF'  
  
#endif /* BOOST_CONTEXT_ASM_H */  
EOF
  
printf "Generated monolithic header: %s\n" "$OUTPUT_HEADER"
