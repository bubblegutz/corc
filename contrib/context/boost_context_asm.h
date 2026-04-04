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
  
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_arm64_aapcs_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".global jump_fcontext"
        "jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for jump_arm64_aapcs_macho_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".private_extern _jump_fcontext"
        "_jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__)  
/* Inline assembly for jump_arm64_aapcs_pe_armasm */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        ";      Copyright Edward Nevill + Oliver Kowalke 2015"
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";         http://www.boost.org/LICENSE_1_0.txt)"
        "jump_fcontext proc"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armclang__)  
/* Inline assembly for jump_arm64_aapcs_pe_armclang */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "*******************************************************/"
        "jump_fcontext:
"
        ".seh_endproc"
        ".ascii \" -export:\\"jump_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armclang__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_arm_aapcs_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".syntax unified"
        "jump_fcontext:
"
        "@ Mark that we don't need executable stack."
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for jump_arm_aapcs_macho_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".private_extern _jump_fcontext"
        "_jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__)  
/* Inline assembly for jump_arm_aapcs_pe_armasm */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        ";            Copyright Oliver Kowalke 2009."
        ";   Distributed under the Boost Software License, Version 1.0."
        ";      (See accompanying file LICENSE_1_0.txt or copy at"
        ";          http://www.boost.org/LICENSE_1_0.txt)"
        ";*/"
        "jump_fcontext PROC"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__) */
  
#if defined(__combined__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for jump_combined_sysv_macho_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__combined__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__clang__)  
/* Inline assembly for jump_i386_ms_pe_clang */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "_jump_fcontext:
"
        ".ascii \" -export:\\"_jump_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__clang__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__gas__)  
/* Inline assembly for jump_i386_ms_pe_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "_jump_fcontext:
"
        ".ascii \" -export:\\"jump_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__masm__)  
/* Inline assembly for jump_i386_ms_pe_masm */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        ";           Copyright Oliver Kowalke 2009."
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";           http://www.boost.org/LICENSE_1_0.txt)"
        ";  ---------------------------------------------------------------------------------"
        ";  |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |"
        ";  ---------------------------------------------------------------------------------"
        ";  |    0h   |   04h   |   08h   |   0ch   |   010h  |   014h  |   018h  |   01ch  |"
        ";  ---------------------------------------------------------------------------------"
        ";  | fc_mxcsr|fc_x87_cw| fc_strg |fc_deallo|  limit  |   base  |  fc_seh |   EDI   |"
        ";  ---------------------------------------------------------------------------------"
        ";  ---------------------------------------------------------------------------------"
        ";  |    8    |    9    |   10    |    11   |    12   |    13   |    14   |    15   |"
        ";  ---------------------------------------------------------------------------------"
        ";  |   020h  |  024h   |  028h   |   02ch  |   030h  |   034h  |   038h  |   03ch  |"
        ";  ---------------------------------------------------------------------------------"
        ";  |   ESI   |   EBX   |   EBP   |   EIP   |    to   |   data  |  EH NXT |SEH HNDLR|"
        ";  ---------------------------------------------------------------------------------"
        ".model flat, c"
        "jump_fcontext PROC BOOST_CONTEXT_EXPORT"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "jump_fcontext ENDP"
        "END"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__masm__) */
  
#if defined(__i386__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_i386_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for jump_i386_sysv_macho_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".private_extern _jump_fcontext"
        "_jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__x86__) && defined(__64__) && defined(__sysv__)  
/* Inline assembly for jump_i386_x86_64_sysv */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__x86__) && defined(__64__) && defined(__sysv__) */
  
#if defined(__loongarch64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_loongarch64_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__loongarch64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__mips32__) && defined(__o32__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_mips32_o32_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".ent jump_fcontext"
        "jump_fcontext:
"
        ".end jump_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__mips32__) && defined(__o32__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__mips64__) && defined(__n64__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_mips64_n64_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".ent jump_fcontext"
        "jump_fcontext:
"
        ".end jump_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__mips64__) && defined(__n64__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__ppc64__) && defined(__sysv__) && defined(__macho__)  
/* Inline assembly for jump_ppc32_ppc64_sysv_macho */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__ppc64__) && defined(__sysv__) && defined(__macho__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_ppc32_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for jump_ppc32_sysv_macho_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".private_extern _jump_fcontext"
        "_jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__)  
/* Inline assembly for jump_ppc32_sysv_xcoff_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "jump_fcontext:
"
        ".jump_fcontext:"
        "use_entry_arg:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_ppc64_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "	.text"
        "	.align 2"
        "jump_fcontext:
"
        "	.section \".opd\",\"aw\""
        "	.align 3"
        "jump_fcontext:
"
        ".L.jump_fcontext:"
        ".jump_fcontext:"
        "	.size jump_fcontext, .-jump_fcontext"
        "use_entry_arg:
"
        "	.size .jump_fcontext, .-.L.jump_fcontext"
        "	.size .jump_fcontext, .-.jump_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for jump_ppc64_sysv_macho_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".private_extern _jump_fcontext"
        "_jump_fcontext:
"
        "use_entry_arg:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__)  
/* Inline assembly for jump_ppc64_sysv_xcoff_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "jump_fcontext:
"
        ".jump_fcontext:"
        "use_entry_arg:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__) */
  
#if defined(__riscv64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_riscv64_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".global jump_fcontext"
        "jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__riscv64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__s390x__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_s390x_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        ".global	jump_fcontext"
        "typedef void*   fcontext_t;"
        "struct transfer_t {"
        "};"
        "transfer_t jump_fcontext( fcontext_t const to,"
        "			  void * data);"
        "Incoming args"
        "r2 - Hidden argument to the location where the return transfer_t needs to be returned"
        "r3 - Context we want to switch to"
        "r4 - Data pointer"
        "*/"
        "jump_fcontext:
"
        "	.machine \"z10\""
        "	/* Reserve stack space to store the current context.  */"
        "	aghi	%r15,-CONTEXT_SIZE"
        "	/* Save the argument register holding the location of the return value.  */"
        "	stg	%r2,GR_OFFSET(%r15)"
        "	/* Save the call-saved general purpose registers.  */"
        "	stmg	%r6,%r14,GR_OFFSET+8(%r15)"
        "	/* Save call-saved floating point registers.  */"
        "	std	%f8,FP_OFFSET(%r15)"
        "	std	%f9,FP_OFFSET+8(%r15)"
        "	std	%f10,FP_OFFSET+16(%r15)"
        "	std	%f11,FP_OFFSET+24(%r15)"
        "	std	%f12,FP_OFFSET+32(%r15)"
        "	std	%f13,FP_OFFSET+40(%r15)"
        "	std	%f14,FP_OFFSET+48(%r15)"
        "	std	%f15,FP_OFFSET+56(%r15)"
        "	/* Save the return address as current pc.  */"
        "	stg	%r14,PC_OFFSET(%r15)"
        "	/* Save the floating point control register.  */"
        "	stfpc	FPC_OFFSET(%r15)"
        "	/* Backup the stack pointer pointing to the old context-data into r1.  */"
        "	lgr	 %r1,%r15"
        "	/* Load the new context pointer as stack pointer.  */"
        "	lgr	%r15,%r3"
        "	/* Restore the call-saved GPRs from the new context.  */"
        "	lmg	%r6,%r14,GR_OFFSET+8(%r15)"
        "	/* Restore call-saved floating point registers.  */"
        "	ld	%f8,FP_OFFSET(%r15)"
        "	ld	%f9,FP_OFFSET+8(%r15)"
        "	ld	%f10,FP_OFFSET+16(%r15)"
        "	ld	%f11,FP_OFFSET+24(%r15)"
        "	ld	%f12,FP_OFFSET+32(%r15)"
        "	ld	%f13,FP_OFFSET+40(%r15)"
        "	ld	%f14,FP_OFFSET+48(%r15)"
        "	ld	%f15,FP_OFFSET+56(%r15)"
        "	/* Load the floating point control register.  */"
        "	lfpc	FPC_OFFSET(%r15)"
        "	/* Restore PC - the location where we will jump to at the end.  */"
        "	lg	%r5,PC_OFFSET(%r15)"
        "	ltg	%r2,GR_OFFSET(%r15)"
        "	jnz	use_return_slot"
        "	/* We're restoring a context created by make_fcontext."
        "	   This is going to be the argument of the entry point"
        "	   of the fiber. We're placing it on top of the ABI"
        "	   defined register save area of the fiber's own stack. */"
        "	la	%r2,REG_SAVE_AREA_SIZE(%r15)"
        "	/* REG_SAVE_AREA_SIZE + sizeof(transfer_t) */"
        "	aghi	%r15,-(REG_SAVE_AREA_SIZE+16)"
        "use_return_slot:
"
        "	/* Save the two fields in transfer_t.  When calling a"
        "	   make_fcontext function this becomes the function argument of"
        "	   the target function, otherwise it will be the return value of"
        "	   jump_fcontext.  */"
        "	stg	%r1,0(%r2)"
        "	stg	%r4,8(%r2)"
        "	/* Free the restored context.  */"
        "	aghi	%r15,CONTEXT_SIZE"
        "	/* Jump to the PC loaded from the new context.  */"
        "	br	%r5"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__s390x__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__sparc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for jump_sparc64_sysv_elf_gas */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".global jump_fcontext"
        "jump_fcontext:
"
        "	# prepare stack"
        "	save	%sp, -CC64FSZ, %sp"
        "	# store framepointer and return address in slots reserved"
        "	# for arguments"
        "	stx %fp, [%sp + BIAS + SP]"
        "	stx %i7, [%sp + BIAS + I7]"
        "	mov %sp, %o0"
        "	# force flush register windows to stack and with that save context"
        "	flushw"
        "	# get SP (pointing to new context-data) from %i0 param"
        "	mov %i0, %sp"
        "	# load framepointer and return address from context"
        "	ldx [%sp + BIAS + SP], %fp"
        "	ldx [%sp + BIAS + I7], %i7"
        "	ret"
        "	 restore %o0, %g0, %o0"
        "	# restore old %sp (pointing to old context-data) in %o0"
        "	# *data stored in %o1 was not modified"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__sparc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for jump_x86_64_ms_pe */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "jump_fcontext:
"
        ".seh_endproc"
        ".ascii \" -export:\\"jump_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for jump_x86_64_ms_pe */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "jump_fcontext:
"
        ".seh_endproc"
        ".ascii \" -export:\\"jump_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for jump_x86_64_ms_pe */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        ";           Copyright Oliver Kowalke 2009."
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";           http://www.boost.org/LICENSE_1_0.txt)"
        ";  ----------------------------------------------------------------------------------"
        ";  |     0   |     1   |     2    |     3   |     4   |     5   |     6   |     7   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |    0x0  |    0x4  |    0x8   |    0xc  |   0x10  |   0x14  |   0x18  |   0x1c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |     8   |    9    |    10    |    11   |    12   |    13   |    14   |    15   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x20  |  0x24   |   0x28   |   0x2c  |   0x30  |   0x34  |   0x38  |   0x3c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    16   |    17   |    18   |    19    |    20   |    21   |    22   |    23   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xe40  |   0x44 |   0x48  |   0x4c   |   0x50  |   0x54  |   0x58  |   0x5c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    24   |   25    |    26    |   27    |    28   |    29   |    30   |    31   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x60  |   0x64  |   0x68   |   0x6c  |   0x70  |   0x74  |   0x78  |   0x7c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    32   |   32    |    33    |   34    |    35   |    36   |    37   |    38   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x80  |   0x84  |   0x88   |   0x8c  |   0x90  |   0x94  |   0x98  |   0x9c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    39   |   40    |    41    |   42    |    43   |    44   |    45   |    46   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xa0  |   0xa4  |   0xa8   |   0xac  |   0xb0  |   0xb4  |   0xb8  |   0xbc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  | fc_mxcsr|fc_x87_cw|     <alignment>    |       fbr_strg    |      fc_dealloc   |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    47   |   48    |    49    |   50    |    51   |    52   |    53   |    54   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xc0  |   0xc4  |   0xc8   |   0xcc  |   0xd0  |   0xd4  |   0xd8  |   0xdc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        limit      |         base       |         R12       |         R13       |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    55   |   56    |    57    |   58    |    59   |    60   |    61   |    62   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xe0  |   0xe4  |   0xe8   |   0xec  |   0xf0  |   0xf4  |   0xf8  |   0xfc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        R14        |         R15        |         RDI       |        RSI        |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    63   |   64    |    65    |   66    |    67   |    68   |    69   |    70   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x100  |  0x104  |  0x108   |  0x10c  |  0x110  |  0x114  |  0x118  |  0x11c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        RBX        |         RBP        |       hidden      |        RIP        |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    71   |   72    |    73    |   74    |    75   |    76   |    77   |    78   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x120  |  0x124  |  0x128   |  0x12c  |  0x130  |  0x134  |  0x138  |  0x13c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                                   parameter area                               |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    79   |   80    |    81    |   82    |    83   |    84   |    85   |    86   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x140  |  0x144  |  0x148   |  0x14c  |  0x150  |  0x154  |  0x158  |  0x15c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |       FCTX        |        DATA        |                                       |"
        ";  ----------------------------------------------------------------------------------"
        "jump_fcontext PROC BOOST_CONTEXT_EXPORT FRAME"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "jump_fcontext ENDP"
        "END"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__elf__)  
/* Inline assembly for jump_x86_64_sysv_elf */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        "jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__elf__) */
  
#if defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__macho__)  
/* Inline assembly for jump_x86_64_sysv_macho */  
static inline
transfer_t jump_fcontext(fcontext_t const to, void *vp) {
    __asm__ volatile (
        "*/"
        ".private_extern _jump_fcontext"
        "_jump_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__macho__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_arm64_aapcs_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".global make_fcontext"
        "make_fcontext:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for make_arm64_aapcs_macho_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _make_fcontext"
        "_make_fcontext:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__)  
/* Inline assembly for make_arm64_aapcs_pe_armasm */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        ";      Copyright Edward Nevill + Oliver Kowalke 2015"
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";         http://www.boost.org/LICENSE_1_0.txt)"
        "make_fcontext proc"
        "trampoline"
        "finish"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armclang__)  
/* Inline assembly for make_arm64_aapcs_pe_armclang */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "*******************************************************/"
        "make_fcontext:
"
        "trampoline:
"
        "finish:
"
        ".seh_endproc"
        ".ascii \" -export:\\"make_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armclang__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_arm_aapcs_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".syntax unified"
        "make_fcontext:
"
        "finish:
"
        "@ Mark that we don't need executable stack."
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for make_arm_aapcs_macho_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _make_fcontext"
        "_make_fcontext:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__)  
/* Inline assembly for make_arm_aapcs_pe_armasm */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        ";            Copyright Oliver Kowalke 2009."
        ";   Distributed under the Boost Software License, Version 1.0."
        ";      (See accompanying file LICENSE_1_0.txt or copy at"
        ";          http://www.boost.org/LICENSE_1_0.txt)"
        ";*/"
        "make_fcontext PROC"
        "finish"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__) */
  
#if defined(__combined__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for make_combined_sysv_macho_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__combined__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__clang__)  
/* Inline assembly for make_i386_ms_pe_clang */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "_make_fcontext:
"
        "	/* set fiber-storage to zero */"
        "	xorl  %ecx, %ecx"
        "walk:
"
        "found:
"
        "trampoline:
"
        "finish:
"
        ".ascii \" -export:\\"_make_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__clang__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__gas__)  
/* Inline assembly for make_i386_ms_pe_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "_make_fcontext:
"
        "	/* set fiber-storage to zero */"
        "	xorl  %ecx, %ecx"
        "walk:
"
        "found:
"
        "trampoline:
"
        "finish:
"
        ".ascii \" -export:\\"make_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__masm__)  
/* Inline assembly for make_i386_ms_pe_masm */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        ";           Copyright Oliver Kowalke 2009."
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";           http://www.boost.org/LICENSE_1_0.txt)"
        ";  ---------------------------------------------------------------------------------"
        ";  |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |"
        ";  ---------------------------------------------------------------------------------"
        ";  |    0h   |   04h   |   08h   |   0ch   |   010h  |   014h  |   018h  |   01ch  |"
        ";  ---------------------------------------------------------------------------------"
        ";  | fc_mxcsr|fc_x87_cw| fc_strg |fc_deallo|  limit  |   base  |  fc_seh |   EDI   |"
        ";  ---------------------------------------------------------------------------------"
        ";  ---------------------------------------------------------------------------------"
        ";  |    8    |    9    |   10    |    11   |    12   |    13   |    14   |    15   |"
        ";  ---------------------------------------------------------------------------------"
        ";  |   020h  |  024h   |  028h   |   02ch  |   030h  |   034h  |   038h  |   03ch  |"
        ";  ---------------------------------------------------------------------------------"
        ";  |   ESI   |   EBX   |   EBP   |   EIP   |    to   |   data  |  EH NXT |SEH HNDLR|"
        ";  ---------------------------------------------------------------------------------"
        ".model flat, c"
        "; standard C library function"
        "_exit PROTO, value:SDWORD"
        "make_fcontext PROC BOOST_CONTEXT_EXPORT"
        "	; set fiber-storage to zero"
        "	xor  ecx, ecx"
        "walk:
"
        "found:
"
        "trampoline:
"
        "finish:
"
        "make_fcontext ENDP"
        "END"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__masm__) */
  
#if defined(__i386__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_i386_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "make_fcontext:
"
        "1:  popl  %ecx"
        "2:  popl  %ecx"
        "trampoline:
"
        "finish:
"
        "3:  popl  %ebx"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for make_i386_sysv_macho_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _make_fcontext"
        "_make_fcontext:
"
        "1:  popl  %ecx"
        "2:  popl  %ecx"
        "trampoline:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__x86__) && defined(__64__) && defined(__sysv__)  
/* Inline assembly for make_i386_x86_64_sysv */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__x86__) && defined(__64__) && defined(__sysv__) */
  
#if defined(__loongarch64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_loongarch64_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "make_fcontext:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__loongarch64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__mips32__) && defined(__o32__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_mips32_o32_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".ent make_fcontext"
        "make_fcontext:
"
        ".cpload $t9"
        "finish:
"
        ".end make_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__mips32__) && defined(__o32__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__mips64__) && defined(__n64__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_mips64_n64_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".ent make_fcontext"
        "make_fcontext:
"
        ".cpload $t9"
        "finish:
"
        ".end make_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__mips64__) && defined(__n64__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__ppc64__) && defined(__sysv__) && defined(__macho__)  
/* Inline assembly for make_ppc32_ppc64_sysv_macho */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__ppc64__) && defined(__sysv__) && defined(__macho__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_ppc32_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "make_fcontext:
"
        "1:  mflr  %r4"
        "trampoline:
"
        "finish:
"
        "2:  mflr   %r30"
        ".Ltoc = . + 0x8000"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for make_ppc32_sysv_macho_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _make_fcontext"
        "_make_fcontext:
"
        "L1:
"
        "Ltrampoline:
"
        "Lfinish:
"
        "L2:
"
        ".const_data"
        "Lexitp:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__)  
/* Inline assembly for make_ppc32_sysv_xcoff_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "make_fcontext:
"
        ".make_fcontext:"
        ".Label:"
        ".L_finish:"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_ppc64_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "	.text"
        "	.align 2"
        "make_fcontext:
"
        "	addis	%r2, %r12, .TOC.-make_fcontext@ha"
        "	addi	%r2, %r2, .TOC.-make_fcontext@l"
        "	.localentry make_fcontext, . - make_fcontext"
        "	.section \".opd\",\"aw\""
        "	.align 3"
        "make_fcontext:
"
        "	.quad	.L.make_fcontext,.TOC.@tocbase,0"
        "	.type	make_fcontext,@function"
        "	.text"
        "	.align 2"
        ".L.make_fcontext:"
        "	.hidden	.make_fcontext"
        "	.globl	.make_fcontext"
        "	.quad	.make_fcontext,.TOC.@tocbase,0"
        "	.size	make_fcontext,24"
        "	.type	.make_fcontext,@function"
        "	.text"
        "	.align 2"
        ".make_fcontext:"
        "1:"
        "finish:
"
        "	.size make_fcontext, .-make_fcontext"
        "	.size .make_fcontext, .-.L.make_fcontext"
        "	.size .make_fcontext, .-.make_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for make_ppc64_sysv_macho_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _make_fcontext"
        "_make_fcontext:
"
        "l1:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__)  
/* Inline assembly for make_ppc64_sysv_xcoff_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "make_fcontext:
"
        ".make_fcontext:"
        ".Label:"
        ".L_finish:"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__) */
  
#if defined(__riscv64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_riscv64_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".global make_fcontext"
        "make_fcontext:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__riscv64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__s390x__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_s390x_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        ".global	make_fcontext"
        "fcontext_t make_fcontext( void * sp, std::size_t size, void (* fn)( transfer_t) );"
        "Create and return a context below SP to call FN."
        "Incoming args"
        "r2 - The stack location where to create the context"
        "r3 - The size of the context"
        "r4 - The address of the context function"
        "*/"
        "make_fcontext:
"
        "	.machine \"z10\""
        "	/* Align the stack to an 8 byte boundary.  */"
        "	nill    %r2,0xfff8"
        "	/* Allocate stack space for the context.  */"
        "	aghi	%r2,-CONTEXT_SIZE"
        "	/* Set the r2 save slot to zero.  This indicates jump_fcontext"
        "	   that this is a special context.  */"
        "	mvghi	GR_OFFSET(%r2),0"
        "	/* Save the floating point control register.  */"
        "	stfpc	FPC_OFFSET(%r2)"
        "	/* Store the address of the target function as new pc.  */"
        "	stg	%r4,PC_OFFSET(%r2)"
        "	/* Store a pointer to the finish routine as r14. If a function"
        "	   called via context routines just returns that value will be"
        "	   loaded and used as return address.  Hence the program will"
        "	   just exit.  */"
        "	larl	%r1,finish"
        "	stg	%r1,R14_OFFSET(%r2)"
        "	/* Return as usual with the new context returned in r2.  */"
        "	br	%r14"
        "finish:
"
        "	/* In finish tasks, you load the exit code and exit the"
        "	   make_fcontext This is called when the context-function is"
        "	   entirely executed.  */"
        "	lghi	%r2,0"
        "	brasl	%r14,_exit@PLT"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__s390x__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__sparc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for make_sparc64_sysv_elf_gas */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".global make_fcontext"
        "make_fcontext:
"
        "	save	%sp, -CC64FSZ, %sp"
        "	# shift address in %i0 (allocated stack) to lower 16 byte boundary"
        "	and	%i0, -0xf, %i0"
        "	# reserve space for two frames on the stack"
        "	# the first frame is for the call the second one holds the data"
        "	# for jump_fcontext"
        "	sub	%i0, 2 * CC64FSZ, %i0"
        "	# third argument of make_fcontext() is the context-function to call"
        "	# store it in the first stack frame, also clear %fp there to indicate"
        "	# the end of the stack."
        "	stx	%i2, [%i0 + CC64FSZ + I7]"
        "	stx	%g0, [%i0 + CC64FSZ + FP]"
        "	# On OpenBSD stackghost prevents overriding the return address on"
        "	# a stack frame. So this code uses an extra trampoline to load"
        "	# to call the context-function and then do the _exit(0) dance."
        "	# Extract the full address of the trampoline via pc relative addressing"
        "1:"
        "	rd	%pc, %l0"
        "	add	%l0, (trampoline - 1b - 8), %l0"
        "	stx	%l0, [%i0 + I7]"
        "	# Save framepointer to first stack frame but first subtract the BIAS"
        "	add	%i0, CC64FSZ - BIAS, %l0"
        "	stx	%l0, [%i0 + SP]"
        "	# Return context-data which is also includes the BIAS"
        "	ret"
        "	 restore %i0, -BIAS, %o0"
        "trampoline:
"
        "	ldx	[%sp + BIAS + I7], %l0"
        "	# no need to setup transfer_t, already in %o0 and %o1"
        "	jmpl	%l0, %o7"
        "	 nop"
        "	call	_exit"
        "	 clr	%o0"
        "	unimp"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__sparc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for make_x86_64_ms_pe */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "make_fcontext:
"
        "	/* set fiber-storage to zero */"
        "	/* save MMX control- and status-word */"
        "trampoline:
"
        "finish:
"
        ".seh_endproc"
        ".ascii \" -export:\\"make_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for make_x86_64_ms_pe */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "make_fcontext:
"
        "	/* set fiber-storage to zero */"
        "	/* save MMX control- and status-word */"
        "trampoline:
"
        "finish:
"
        ".seh_endproc"
        ".ascii \" -export:\\"make_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for make_x86_64_ms_pe */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        ";           Copyright Oliver Kowalke 2009."
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";           http://www.boost.org/LICENSE_1_0.txt)"
        ";  ----------------------------------------------------------------------------------"
        ";  |     0   |     1   |     2    |     3   |     4   |     5   |     6   |     7   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |    0x0  |    0x4  |    0x8   |    0xc  |   0x10  |   0x14  |   0x18  |   0x1c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |     8   |    9    |    10    |    11   |    12   |    13   |    14   |    15   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x20  |  0x24   |   0x28   |   0x2c  |   0x30  |   0x34  |   0x38  |   0x3c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    16   |    17   |    18   |    19    |    20   |    21   |    22   |    23   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xe40  |   0x44 |   0x48  |   0x4c   |   0x50  |   0x54  |   0x58  |   0x5c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    24   |   25    |    26    |   27    |    28   |    29   |    30   |    31   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x60  |   0x64  |   0x68   |   0x6c  |   0x70  |   0x74  |   0x78  |   0x7c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    32   |   32    |    33    |   34    |    35   |    36   |    37   |    38   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x80  |   0x84  |   0x88   |   0x8c  |   0x90  |   0x94  |   0x98  |   0x9c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    39   |   40    |    41    |   42    |    43   |    44   |    45   |    46   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xa0  |   0xa4  |   0xa8   |   0xac  |   0xb0  |   0xb4  |   0xb8  |   0xbc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  | fc_mxcsr|fc_x87_cw|     <alignment>    |       fbr_strg    |      fc_dealloc   |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    47   |   48    |    49    |   50    |    51   |    52   |    53   |    54   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xc0  |   0xc4  |   0xc8   |   0xcc  |   0xd0  |   0xd4  |   0xd8  |   0xdc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        limit      |         base       |         R12       |         R13       |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    55   |   56    |    57    |   58    |    59   |    60   |    61   |    62   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xe0  |   0xe4  |   0xe8   |   0xec  |   0xf0  |   0xf4  |   0xf8  |   0xfc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        R14        |         R15        |         RDI       |        RSI        |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    63   |   64    |    65    |   66    |    67   |    68   |    69   |    70   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x100  |  0x104  |  0x108   |  0x10c  |  0x110  |  0x114  |  0x118  |  0x11c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        RBX        |         RBP        |       hidden      |        RIP        |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    71   |   72    |    73    |   74    |    75   |    76   |    77   |    78   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x120  |  0x124  |  0x128   |  0x12c  |  0x130  |  0x134  |  0x138  |  0x13c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                                   parameter area                               |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    79   |   80    |    81    |   82    |    83   |    84   |    85   |    86   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x140  |  0x144  |  0x148   |  0x14c  |  0x150  |  0x154  |  0x158  |  0x15c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |       FCTX        |        DATA        |                                       |"
        ";  ----------------------------------------------------------------------------------"
        "; standard C library function"
        "EXTERN  _exit:PROC"
        "; generate function table entry in .pdata and unwind information in"
        "make_fcontext PROC BOOST_CONTEXT_EXPORT FRAME"
        "	; set fiber-storage to zero"
        "	xor  rcx, rcx"
        "	; save MMX control- and status-word"
        "trampoline:
"
        "finish:
"
        "make_fcontext ENDP"
        "END"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__elf__)  
/* Inline assembly for make_x86_64_sysv_elf */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "make_fcontext:
"
        "1:"
        "trampoline:
"
        "2:"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__elf__) */
  
#if defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__macho__)  
/* Inline assembly for make_x86_64_sysv_macho */  
static inline
fcontext_t make_fcontext(void *sp, size_t size, void (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _make_fcontext"
        "_make_fcontext:
"
        "trampoline:
"
        "finish:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    return (fcontext_t)sp; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__macho__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_arm64_aapcs_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".global ontop_fcontext"
        "ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for ontop_arm64_aapcs_macho_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _ontop_fcontext"
        ".global _ontop_fcontext"
        "_ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__)  
/* Inline assembly for ontop_arm64_aapcs_pe_armasm */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        ";      Copyright Edward Nevill + Oliver Kowalke 2015"
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";         http://www.boost.org/LICENSE_1_0.txt)"
        "ontop_fcontext proc BOOST_CONTEXT_EXPORT"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__) */
  
#if defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armclang__)  
/* Inline assembly for ontop_arm64_aapcs_pe_armclang */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "*******************************************************/"
        "ontop_fcontext:
"
        ".seh_endproc"
        ".ascii \" -export:\\"ontop_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm64__) && defined(__aapcs__) && defined(__pe__) && defined(__armclang__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_arm_aapcs_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".syntax unified"
        "ontop_fcontext:
"
        "@ Mark that we don't need executable stack."
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for ontop_arm_aapcs_macho_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _ontop_fcontext"
        "_ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__arm__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__)  
/* Inline assembly for ontop_arm_aapcs_pe_armasm */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        ";            Copyright Oliver Kowalke 2009."
        ";   Distributed under the Boost Software License, Version 1.0."
        ";      (See accompanying file LICENSE_1_0.txt or copy at"
        ";          http://www.boost.org/LICENSE_1_0.txt)"
        ";*/"
        "ontop_fcontext PROC"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__arm__) && defined(__aapcs__) && defined(__pe__) && defined(__armasm__) */
  
#if defined(__combined__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for ontop_combined_sysv_macho_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__combined__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__clang__)  
/* Inline assembly for ontop_i386_ms_pe_clang */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "_ontop_fcontext:
"
        "	/* pass parent fcontext_t */"
        "	movl  %ecx, 0x30(%eax)"
        "	/* pass data */"
        "	movl  %ecx, 0x34(%eax)"
        ".ascii \" -export:\\"_ontop_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__clang__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__gas__)  
/* Inline assembly for ontop_i386_ms_pe_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "_ontop_fcontext:
"
        "	/* pass parent fcontext_t */"
        "	movl  %ecx, 0x30(%eax)"
        "	/* pass data */"
        "	movl  %ecx, 0x34(%eax)"
        ".ascii \" -export:\\"ontop_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__masm__)  
/* Inline assembly for ontop_i386_ms_pe_masm */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        ";           Copyright Oliver Kowalke 2009."
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";           http://www.boost.org/LICENSE_1_0.txt)"
        ";  ---------------------------------------------------------------------------------"
        ";  |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |"
        ";  ---------------------------------------------------------------------------------"
        ";  |    0h   |   04h   |   08h   |   0ch   |   010h  |   014h  |   018h  |   01ch  |"
        ";  ---------------------------------------------------------------------------------"
        ";  | fc_mxcsr|fc_x87_cw| fc_strg |fc_deallo|  limit  |   base  |  fc_seh |   EDI   |"
        ";  ---------------------------------------------------------------------------------"
        ";  ---------------------------------------------------------------------------------"
        ";  |    8    |    9    |   10    |    11   |    12   |    13   |    14   |    15   |"
        ";  ---------------------------------------------------------------------------------"
        ";  |   020h  |  024h   |  028h   |   02ch  |   030h  |   034h  |   038h  |   03ch  |"
        ";  ---------------------------------------------------------------------------------"
        ";  |   ESI   |   EBX   |   EBP   |   EIP   |    to   |   data  |  EH NXT |SEH HNDLR|"
        ";  ---------------------------------------------------------------------------------"
        ".model flat, c"
        "ontop_fcontext PROC BOOST_CONTEXT_EXPORT"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "	; pass parent fcontext_t"
        "	mov  [eax+030h], ecx"
        "	; pass data"
        "	mov  [eax+034h], ecx"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "ontop_fcontext ENDP"
        "END"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__ms__) && defined(__pe__) && defined(__masm__) */
  
#if defined(__i386__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_i386_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for ontop_i386_sysv_macho_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _ontop_fcontext"
        "_ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__i386__) && defined(__x86__) && defined(__64__) && defined(__sysv__)  
/* Inline assembly for ontop_i386_x86_64_sysv */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__i386__) && defined(__x86__) && defined(__64__) && defined(__sysv__) */
  
#if defined(__loongarch64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_loongarch64_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__loongarch64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__mips32__) && defined(__o32__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_mips32_o32_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".ent ontop_fcontext"
        "ontop_fcontext:
"
        ".end ontop_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__mips32__) && defined(__o32__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__mips64__) && defined(__n64__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_mips64_n64_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".ent ontop_fcontext"
        "ontop_fcontext:
"
        ".end ontop_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__mips64__) && defined(__n64__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__ppc64__) && defined(__sysv__) && defined(__macho__)  
/* Inline assembly for ontop_ppc32_ppc64_sysv_macho */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__ppc64__) && defined(__sysv__) && defined(__macho__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_ppc32_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for ontop_ppc32_sysv_macho_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _ontop_fcontext"
        "_ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__ppc32__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__)  
/* Inline assembly for ontop_ppc32_sysv_xcoff_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "ontop_fcontext:
"
        ".ontop_fcontext:"
        "return_to_ctx:
"
        "use_entry_arg:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc32__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_ppc64_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "	.text"
        "	.align 2"
        "ontop_fcontext:
"
        "	.section \".opd\",\"aw\""
        "	.align 3"
        "ontop_fcontext:
"
        ".L.ontop_fcontext:"
        ".ontop_fcontext:"
        "return_to_ctx:
"
        "	.size ontop_fcontext, .-ontop_fcontext"
        "use_entry_arg:
"
        "	.size .ontop_fcontext, .-.L.ontop_fcontext"
        "	.size .ontop_fcontext, .-.ontop_fcontext"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__macho__) && defined(__gas__)  
/* Inline assembly for ontop_ppc64_sysv_macho_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _ontop_fcontext"
        "_ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__macho__) && defined(__gas__) */
  
#if defined(__ppc64__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__)  
/* Inline assembly for ontop_ppc64_sysv_xcoff_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "ontop_fcontext:
"
        ".ontop_fcontext:"
        "return_to_ctx:
"
        "use_entry_arg:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__ppc64__) && defined(__sysv__) && defined(__xcoff__) && defined(__gas__) */
  
#if defined(__riscv64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_riscv64_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".global ontop_fcontext"
        "ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__riscv64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__s390x__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_s390x_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        ".global ontop_fcontext"
        "typedef void*   fcontext_t;"
        "struct transfer_t {"
        "};"
        "transfer_t ontop_fcontext( fcontext_t const to,"
        "			   void * vp,"
        "			   transfer_t (* fn)( transfer_t) );"
        "Incoming args"
        "r2 - Hidden argument to the location where the return transfer_t needs to be returned"
        "r3 - Target context"
        "r4 - Data pointer"
        "r5 - Function to be executed"
        "This implementation assumes that ontop_fcontext will never be called with target contexts"
        "created via make_fcontext."
        "*/"
        "ontop_fcontext:
"
        "	/* Reserve stack space to store the current context.  */"
        "	aghi	%r15,-CONTEXT_SIZE"
        "	/* Save the argument register holding the location of the return value.  */"
        "	stg	%r2,GR_OFFSET(%r15)"
        "	/* Save the call-saved general purpose registers.  */"
        "	stmg	%r6,%r14,GR_OFFSET+8(%r15)"
        "	/* Save call-saved floating point registers.  */"
        "	std	%f8,FP_OFFSET(%r15)"
        "	std	%f9,FP_OFFSET+8(%r15)"
        "	std	%f10,FP_OFFSET+16(%r15)"
        "	std	%f11,FP_OFFSET+24(%r15)"
        "	std	%f12,FP_OFFSET+32(%r15)"
        "	std	%f13,FP_OFFSET+40(%r15)"
        "	std	%f14,FP_OFFSET+48(%r15)"
        "	std	%f15,FP_OFFSET+56(%r15)"
        "	/* Save the return address as current pc.  */"
        "	stg	%r14,PC_OFFSET(%r15)"
        "	/* Save the floating point control register.  */"
        "	stfpc   FPC_OFFSET(%r15)"
        "	/* Backup the stack pointer pointing to the old context-data into r1.  */"
        "	lgr	%r1,%r15"
        "	/* Load the new context pointer as stack pointer.  */"
        "	lgr	%r15,%r3"
        "	/* Restore the call-saved GPRs from the new context.  */"
        "	lmg	%r6,%r14,GR_OFFSET+8(%r15)"
        "	/* Restore call-saved floating point registers.  */"
        "	ld	%f8,FP_OFFSET(%r15)"
        "	ld	%f9,FP_OFFSET+8(%r15)"
        "	ld	%f10,FP_OFFSET+16(%r15)"
        "	ld	%f11,FP_OFFSET+24(%r15)"
        "	ld	%f12,FP_OFFSET+32(%r15)"
        "	ld	%f13,FP_OFFSET+40(%r15)"
        "	ld	%f14,FP_OFFSET+48(%r15)"
        "	ld	%f15,FP_OFFSET+56(%r15)"
        "	/* Load the floating point control register.  */"
        "	lfpc   FPC_OFFSET(%r15)"
        "	/* Store the transfer_t values located in the saved context.  */"
        "	stg	%r1,0(%r1)	       /* transfer_t.fctx = old context */"
        "	stg	%r4,8(%r1)             /* transfer_t.data = data */"
        "	/* Set up the arguments for the target function.  */"
        "	lg	%r2,GR_OFFSET(%r15)"
        "	lgr	%r3,%r1"
        "	/* Deallocate the context.  */"
        "	aghi	%r15,CONTEXT_SIZE"
        "	br	%r5"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__s390x__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__sparc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__)  
/* Inline assembly for ontop_sparc64_sysv_elf_gas */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".global ontop_fcontext"
        "ontop_fcontext:
"
        "	# prepare stack"
        "	save	%sp, -CC64FSZ, %sp"
        "	# store framepointer and return address in slots reserved"
        "	# for arguments"
        "	stx %fp, [%sp + BIAS + SP]"
        "	stx %i7, [%sp + BIAS + I7]"
        "	mov %sp, %o0"
        "	# force flush register windows to stack and with that save context"
        "	flushw"
        "	# get SP (pointing to new context-data) from %i0 param"
        "	mov %i0, %sp"
        "	# load framepointer and return address from context"
        "	ldx [%sp + BIAS + SP], %fp"
        "	ldx [%sp + BIAS + I7], %i7"
        "	# ontop_fcontext requires to directly call a function on top of the"
        "	# current frame so restore register window before doing the jump"
        "	# to the context function which then is in %o2. Do not clobber"
        "	# %o7 in the jump so that (*fn)() returns to that address."
        "	restore %o0, %g0, %o0"
        "	# restore old %sp (pointing to old context-data) in %o0"
        "	# *data stored in %o1 was not modified"
        "	jmpl %o2, %g0"
        "	 nop"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__sparc64__) && defined(__sysv__) && defined(__elf__) && defined(__gas__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for ontop_x86_64_ms_pe */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "ontop_fcontext:
"
        ".seh_endproc"
        ".ascii \" -export:\\"ontop_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for ontop_x86_64_ms_pe */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "**************************************************************************************/"
        "ontop_fcontext:
"
        ".seh_endproc"
        ".ascii \" -export:\\"ontop_fcontext\\"\""
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__)  
/* Inline assembly for ontop_x86_64_ms_pe */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        ";           Copyright Oliver Kowalke 2009."
        ";  Distributed under the Boost Software License, Version 1.0."
        ";     (See accompanying file LICENSE_1_0.txt or copy at"
        ";           http://www.boost.org/LICENSE_1_0.txt)"
        ";  ----------------------------------------------------------------------------------"
        ";  |     0   |     1   |     2    |     3   |     4   |     5   |     6   |     7   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |    0x0  |    0x4  |    0x8   |    0xc  |   0x10  |   0x14  |   0x18  |   0x1c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |     8   |    9    |    10    |    11   |    12   |    13   |    14   |    15   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x20  |  0x24   |   0x28   |   0x2c  |   0x30  |   0x34  |   0x38  |   0x3c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    16   |    17   |    18   |    19    |    20   |    21   |    22   |    23   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xe40  |   0x44 |   0x48  |   0x4c   |   0x50  |   0x54  |   0x58  |   0x5c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    24   |   25    |    26    |   27    |    28   |    29   |    30   |    31   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x60  |   0x64  |   0x68   |   0x6c  |   0x70  |   0x74  |   0x78  |   0x7c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    32   |   32    |    33    |   34    |    35   |    36   |    37   |    38   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0x80  |   0x84  |   0x88   |   0x8c  |   0x90  |   0x94  |   0x98  |   0x9c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                          SEE registers (XMM6-XMM15)                            |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    39   |   40    |    41    |   42    |    43   |    44   |    45   |    46   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xa0  |   0xa4  |   0xa8   |   0xac  |   0xb0  |   0xb4  |   0xb8  |   0xbc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  | fc_mxcsr|fc_x87_cw|     <alignment>    |       fbr_strg    |      fc_dealloc   |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    47   |   48    |    49    |   50    |    51   |    52   |    53   |    54   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xc0  |   0xc4  |   0xc8   |   0xcc  |   0xd0  |   0xd4  |   0xd8  |   0xdc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        limit      |         base       |         R12       |         R13       |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    55   |   56    |    57    |   58    |    59   |    60   |    61   |    62   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |   0xe0  |   0xe4  |   0xe8   |   0xec  |   0xf0  |   0xf4  |   0xf8  |   0xfc  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        R14        |         R15        |         RDI       |        RSI        |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    63   |   64    |    65    |   66    |    67   |    68   |    69   |    70   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x100  |  0x104  |  0x108   |  0x10c  |  0x110  |  0x114  |  0x118  |  0x11c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |        RBX        |         RBP        |       hidden      |        RIP        |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    71   |   72    |    73    |   74    |    75   |    76   |    77   |    78   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x120  |  0x124  |  0x128   |  0x12c  |  0x130  |  0x134  |  0x138  |  0x13c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |                                   parameter area                               |"
        ";  ----------------------------------------------------------------------------------"
        ";  ----------------------------------------------------------------------------------"
        ";  |    79   |   80    |    81    |   82    |    83   |    84   |    85   |    86   |"
        ";  ----------------------------------------------------------------------------------"
        ";  |  0x140  |  0x144  |  0x148   |  0x14c  |  0x150  |  0x154  |  0x158  |  0x15c  |"
        ";  ----------------------------------------------------------------------------------"
        ";  |       FCTX        |        DATA        |                                       |"
        ";  ----------------------------------------------------------------------------------"
        "ontop_fcontext PROC BOOST_CONTEXT_EXPORT FRAME"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "IFNDEF BOOST_USE_TSX"
        "ENDIF"
        "ontop_fcontext ENDP"
        "END"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__ms__) && defined(__pe__) */
  
#if defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__elf__)  
/* Inline assembly for ontop_x86_64_sysv_elf */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        "ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__elf__) */
  
#if defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__macho__)  
/* Inline assembly for ontop_x86_64_sysv_macho */  
static inline
transfer_t ontop_fcontext(fcontext_t const to, void *vp, transfer_t (*fn)(transfer_t)) {
    __asm__ volatile (
        "*/"
        ".private_extern _ontop_fcontext"
        "_ontop_fcontext:
"
    : /* no output */
    : /* no input */
    : \"memory\", \"cc\"
    );
    transfer_t t = {0, vp}; return t; /* Simplified return */
}
#endif /* defined(__x86__) && defined(__64__) && defined(__sysv__) && defined(__macho__) */
  
#endif /* BOOST_CONTEXT_ASM_H */  
