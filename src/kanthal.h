// SPDX-License-Identifier: GPL-2.0-only
#ifndef KANTHAL_H_INCLUDED
#define KANTHAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "kanthal_error.h"

#define KANTHAL_CACHELINE_SIZE 64 /* must leq than 255 */
#define KANTHAL_PAGE_SIZE 65536

/**
 * @defgroup arena_group
 * @brief implementation of arena allocation.
 * @{
*/

/**
 * @struct arena
 * @brief structure of arena allocation.
*/
typedef struct
    { uint8_t *space
    ; uintptr_t size_limit
    ; uintptr_t hot_offset
    ; uintptr_t cold_offset
    ; } arena;

/**
 * @brief initialize and make arena.
 * @param ani_size size of arena. (byte)
 * @return returns address of arena.
 * @note arena_init calls error_raise() when failed.
 * @warning please use with arena_demoli().
*/
arena* arena_init(uintptr_t ani_size);

/**
 * @brief allocation arena variable.
 * @param aac_arena address of arena.
 * @param aac_datatype hot - 1, cold - 0
 * @param aac_datasize bytes of allocation size.
 * @return returns address of variable on the arena.
*/
uintptr_t arena_alloc(arena *aac_arena,uint8_t aac_datatype,uint8_t aac_datasize);

/**
 * @brief frees arena.
 * @param adm_arena address of arena.
 * @return returns nothing.
*/
void arena_demoli(arena *adm_arena);

/** @} */ /* arena_group closed. */



void specialized_sort

#endif
