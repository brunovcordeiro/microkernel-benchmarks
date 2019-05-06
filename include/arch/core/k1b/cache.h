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

#ifndef CORE_K1B_CACHE_H_
#define CORE_K1B_CACHE_H_

/**
 * @addtogroup k1b-core-cache Memory Cache
 * @ingroup k1b-core
 *
 * @brief k1b Memory Cache Interface
 */
/**@{*/

	#include <nanvix/const.h>

	/**
	 * @brief Cache line size log2.
	 */
	#if defined(__k1bdp__)
		#define K1B_CACHE_LINE_SIZE_LOG2 6
	#else
		#define K1B_CACHE_LINE_SIZE_LOG2 6
	#endif

	/**
	 * @brief Cache line size (in bytes).
	 */
	#define K1B_CACHE_LINE_SIZE (1 << K1B_CACHE_LINE_SIZE_LOG2)

	/**
	 * @brief Cache size log2.
	 */
	#if defined(__k1bdp__)
		#define K1B_CACHE_SIZE_LOG2 13
	#else
		#define K1B_CACHE_SIZE_LOG2 15
	#endif

	/**
	 * @brief Cache size.
	 */
	#define K1B_CACHE_SIZE (1 << K1B_CACHE_SIZE_LOG2)

#ifndef _ASM_FILE_

	/**
	 * @brief Invalidates the data cache.
	 *
	 * The k1b_dcache_inval() function invalidates the data cache of
	 * the underlying core. First, it purges the write buffer, then it
	 * waits all pending write operations of other cores to complete,
	 * and finally it performs a full invalidation in the data cache.
	 */
	static inline void k1b_dcache_inval(void)
	{
		__builtin_k1_wpurge();
		__builtin_k1_fence();
		__builtin_k1_dinval();
	}

#endif /* !_ASM_FILE_ */

/**@}*/

/*============================================================================*
 * Exported Interface                                                         *
 *============================================================================*/

/**
 * @cond k1b
 */

	/**
	 * @name Provided Interface
	 */
	/**@{*/
	#define __dcache_invalidate_fn /**< dcache_invalidate() */
	/**@}*/

	/**
	 * @see K1B_CACHE_LINE_SIZE_LOG2.
	 */
	#define CACHE_LINE_SIZE_LOG2 K1B_CACHE_LINE_SIZE_LOG2

	/**
	 * @see K1B_CACHE_LINE_SIZE.
	 */
	#define CACHE_LINE_SIZE K1B_CACHE_LINE_SIZE

	/**
	 * @see K1B_CACHE_SIZE_LOG2.
	 */
	#define CACHE_SIZE_LOG2 K1B_CACHE_SIZE_LOG2

	/**
	 * @see K1B_CACHE_SIZE.
	 */
	#define CACHE_SIZE K1B_CACHE_SIZE

#ifndef _ASM_FILE_

	/**
	 * @see k1b_dcache_inval().
	 */
	static inline void dcache_invalidate(void)
	{
		k1b_dcache_inval();
	}

#endif /* _ASM_FILE_ */

/**@endcond*/

#endif /* CORE_K1B_CACHE_H_ */
