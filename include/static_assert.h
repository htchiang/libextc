/**
 * Compile-time assertions
 * ExtendedC
 *
 * Copyright (C) 2012 Justin Spahr-Summers
 * Released under the MIT license
 */

#ifndef EXTC_HEADER_STATIC_ASSERT_H
#define EXTC_HEADER_STATIC_ASSERT_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/**
 * Asserts at compile-time that COND is true, aborting compilation if not.
 * COND must be evaluatable at compile-time.
 */
#define static_assert(COND) \
    extern int static_assertion_FAILED[((long)(COND)) ? 1 : -1]

#endif
