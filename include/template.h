/**
 * Template support facilities
 * ExtendedC
 *
 * Copyright (C) 2012 Justin Spahr-Summers
 * Released under the MIT license
 */

#ifndef EXTC_TEMPLATE_H
#define EXTC_TEMPLATE_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stddef.h>
#include "exception.h"

/**
 * Represents a generalized function for comparing arbitrary data.
 * memcmp() fits this definition and is suitable in many cases.
 */
typedef int (*template_compare_function)(const void *, const void *, size_t);

/**
 * N1256 6.2.6:
 * "All pointers to union types shall have the same representation and alignment
 *  requirements as each other. Pointers to other types need not have the same
 *  representation or alignment requirements."
 *
 * Therefore, we use a meaningless union when we need pointers that can be
 * accessed and modified without knowing the templated type (but knowing its
 * size).
 *
 * On all platforms I know of, unions do not have trailing padding (though such
 * is technically allowed), so this does not incur any overhead.
 */
#define template_type(T) \
    union {                     \
        unsigned char unused_;  \
        T value;                \
    }

/**
 * Exception thrown by ExtendedC templates when a given index is out-of-bounds.
 *
 * The 'data' field is set to the templated container.
 */
exception_declaration(IndexOutOfBoundsException);

#endif
