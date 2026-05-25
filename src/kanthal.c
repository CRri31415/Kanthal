// SPDX-License-Identifier: GPL-2.0-only
#include "kanthal.h"



arena* arena_init(uint32_t ani_size)
    { arena *ani_ptr=malloc(sizeof(arena))
    ; if(ani_ptr==NULL)
        { error_raise(ERROR_ARENA_INIT)
        ; return NULL
        ; }
      (*ani_ptr).space=malloc(ani_size+KANTHAL_CACHELINE_SIZE*2)
    ; if((*ani_ptr).space==NULL)
        { free(ani_ptr)
        ; error_raise(ERROR_ARENA_INIT)
        ; return NULL
        ; }
      (*ani_ptr).space[(KANTHAL_CACHELINE_SIZE*2-((*ani_ptr).space&KANTHAL_CACHELINE_SIZE))-1]=(uint8_t)(KANTHAL_CACHELINE_SIZE*2-((*ani_ptr).space&KANTHAL_CACHELINE_SIZE))
    ; (*ani_ptr).space+=(KANTHAL_CACHELINE_SIZE*2-((*ani_ptr).space&KANTHAL_CACHELINE_SIZE))
    ; (*ani_ptr).size_limit=ani_size-(*ani_ptr).space[-1]
    ; (*ani_ptr).hot_offset=0
    ; (*ani_ptr).cold_offset=(*ani_ptr).size_limit
    ; return ani_ptr
    ; }

uint32_t arena_alloc(arena* aac_arena,uint8_t aac_datatype,uint8_t aac_datasize)
    { if (*aac_arena)/
    }
