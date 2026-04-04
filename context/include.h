#ifndef FCONTEXT  
#define FCONTEXT  
  
#ifdef __cplusplus  
extern "C" {  
#endif  
  
#include <stddef.h>  
  
/* fcontext_t type - opaque pointer */  
typedef void* fcontext_t;  
  
/* transfer_t structure for context switching */  
typedef struct {  
    fcontext_t fctx;  
    void* data;  
} transfer_t;  
  
/* Core context functions */  
transfer_t jump_fcontext(fcontext_t const to, void* vp);  
fcontext_t make_fcontext(void* sp, size_t size, void (*fn)(transfer_t));  
transfer_t ontop_fcontext(fcontext_t const to, void* vp, transfer_t (*fn)(transfer_t));  
  
#ifdef __cplusplus  
}  
#endif  
  
#endif /* FCONTEXT */
