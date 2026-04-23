// SPDX-License-Identifier: GPL-2.0-only
#ifndef KANTHAL_H_INCLUDED
#define KANTHAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief error raise function.
 * @param err_msg error message within 255 characters.
 * @param err_msg_len length of error message.
 * @return returns nothing.
*/
void error_raise(char *err_msg,uint8_t err_msg_len);



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
    { char *space
    ; size_t sizlimit
    ; size_t offset
    ; } arena;

/**
 * @brief initialize and make arena.
 * @param ani_size size of arena. (byte)
 * @param ani_retnull arena_init returns null pointer when malloc() has failed and ani_retnull is True. And calls error_raise() when ani_retnull is False.
 * @return returns address of arena
 * @warning please use with arena_demoli().
*/
arena* arena_init(size_t ani_size,bool ani_retnull);

/**
 * @brief frees arena.
 * @param adm_arena address of arena.
 * @return returns nothing.
*/
void arena_demoli(arena *adm_arena);

/** @} */ /* arena_group closed. */



/**
 * @brief scheme of heapsort.
 * @param hss_cnt count of object.
 * @param hss_cmp compare function. (addr0, addr1, arena_offset)
 * @param hss_swp swap function. (addr0, addr1, arena_offset)
 * @param hss_arena_offset arena offset of object.
 * @note hss_cmp should return uint8_t 1,0,-1. return 1 when addr0 is prioritized, WLOG.
 * @return returns nothing.
*/
void heapsort_scheme(uint32_t hss_cnt,uint8_t (*hss_cmp)(uint32_t,uint32_t,size_t),void (*hss_swp)(uint32_t,uint32_t,size_t),size_t hss_arena_offset);

#endif
