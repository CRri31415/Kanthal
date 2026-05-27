// SPDX-License-Identifier: GPL-2.0-only
#include "kanthal.h"

arena* arena_init(uintptr_t ani_size)
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
      uintptr_t ani_offset=KANTHAL_CACHELINE_SIZE-(((uintptr_t)(*ani_ptr).space)%KANTHAL_CACHELINE_SIZE)
    ; (*ani_ptr).space[ani_offset-1]=(uint8_t)ani_offset
    ; (*ani_ptr).space+=ani_offset
    ; (*ani_ptr).size_limit=ani_size-(ani_size%KANTHAL_CACHELINE_SIZE)-ani_offset
    ; (*ani_ptr).hot_offset=0
    ; (*ani_ptr).cold_offset=(*ani_ptr).size_limit-1
    ; return ani_ptr
    ; }

uintptr_t arena_alloc(arena* aac_arena,uintptr_t aac_datasize,bool aac_datatype)
    { if(aac_arena==NULL)
        { error_raise(ERROR_NULL_POINTER)
        ; return 0
        ; }
      if(aac_datasize>(*aac_arena).cold_offset-(*aac_arena).hot_offset+1)
        { error_raise(ERROR_ARENA_ALLOC_EXHAUSTED)
        ; return 0
        ; }
      if(aac_datatype)
        { (*aac_arena).cold_offset-=aac_datasize
        ; return (*aac_arena).cold_offset+aac_datasize
        ; }
      else
        { (*aac_arena).hot_offset+=aac_datasize
        ; return (*aac_arena).hot_offset-aac_datasize
        ; }
    }

void arena_demoli(arena *adm_arena)
    { free((*adm_arena).space-(uintptr_t)(*adm_arena).space[-1])
    ; free(adm_arena)
    ; return
    ; }
