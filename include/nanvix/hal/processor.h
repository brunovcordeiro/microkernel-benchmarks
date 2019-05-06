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

#ifndef NANVIX_HAL_PROCESSOR_H_
#define NANVIX_HAL_PROCESSOR_H_

	#ifndef __NEED_HAL_PROCESSOR
		#error "include <nanvix/hal/target.h> instead"
	#endif

	/* Processor Interface Implementation */
	#include <nanvix/hal/processor/_processor.h>

	#include <nanvix/hal/processor/clusters.h>
	#include <nanvix/hal/processor/noc.h>

/*============================================================================*
 * Processor Interface                                                        *
 *============================================================================*/

/**
 * @defgroup kernel-hal-processor Processor
 * @ingroup kernel-hal
 *
 * @brief Processor HAL Interface
 */
/**@{*/

	/**
	 * @brief Number of Compute Clusters in the processor.
	 */
	#define PROCESSOR_CCLUSTERS _PROCESSOR_CCLUSTERS_NUM

	/**
	 * @brief Number of IO Clusters in the processor.
	 */
	#define PROCESSOR_IOCLUSTERS_NUM _PROCESSOR_IOCLUSTERS_NUM

	/**
	 * @brief Total number of clusters in the processor.
	 */
	#define PROCESSOR_CLUSTERS_NUM \
		(_PROCESSOR_IOCLUSTERS_NUM + _PROCESSOR_CCLUSTERS_NUM)

/**@}*/

#endif /* NANVIX_HAL_PROCESSOR_H_ */
