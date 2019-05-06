/*
 * MIT License
 *
 * Copyright(c) 2011-2019 The Maintainers of Nanvix
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef NANVIX_HAL_CORE_CACHE_H_
#define NANVIX_HAL_CORE_CACHE_H_

	/* Core Interface Implementation */
	#include <nanvix/hal/core/_core.h>

/*============================================================================*
 * Interface Implementation Checking                                          *
 *============================================================================*/

#if defined(__INTERFACE_CHECK) || defined(__INTERFACE_CHECK_CORE_AL) || defined(__INTERFACE_CHECK_CACHE)

	/* Constants */
	#ifndef CACHE_LINE_SIZE
	#error "CACHE_LINE_SIZE not defined"
	#endif

	/* Functions */
	#ifndef __dcache_invalidate_fn
	#error "dcache_invalidate() not defined?"
	#endif

#endif

/*============================================================================*
 * Cache Interface                                                             *
 *============================================================================*/

/**
 * @addtogroup kernel-hal-core-cache Cache
 * @ingroup kernel-hal-core
 *
 * @brief Memory Cache HAL Interface
 */
/**@{*/

	#include <nanvix/const.h>

	/**
	 * @brief Invalidates the data cache.
	 */
	EXTERN void dcache_invalidate(void);

/**@}*/

#endif /* NANVIX_HAL_CORE_CACHE_H_ */
