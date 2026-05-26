// SPDX-License-Identifier: GPL-2.0-only

#ifndef KANTHAL_ERROR_H_INCLUDED
#define KANTHAL_ERROR_H_INCLUDED

enum kanthal_error_code
    { ERROR_SUCCESS=0
    , ERROR_UNKNOWN=1
    , ERROR_ARENA_INIT=2
    , ERROR_ARENA_ALLOC_EXHAUSTED=3
    };

/**
 * @brief error raise function.
 * @param err_code error code.
 * @return returns nothing.
*/
void error_raise(uint16_t err_code);

#endif
