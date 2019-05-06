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

#ifndef NANVIX_HAL_TARGET_SYNC_H_
#define NANVIX_HAL_TARGET_SYNC_H_

	/* Target Interface Implementation */
	#include <nanvix/hal/target/_target.h>

/*============================================================================*
 * Interface Implementation Checking                                          *
 *============================================================================*/

#if defined(__INTERFACE_CHECK) || defined(__INTERFACE_CHECK_TARGET_AL) || defined(__INTERFACE_CHECK_SYNC)

	/* Feature Checking */
	#ifndef TARGET_HAS_SYNC
	#error "does this target feature a synchronization service?"
	#endif

	/* Has Stadard Output Device */
	#if (TARGET_HAS_SYNC)

		/* Constants */
		#ifndef SYNC_ONE_TO_ALL
		#error "SYNC_ONE_TO_ALL not defined"
		#endif
		#ifndef SYNC_ALL_TO_ONE
		#error "SYNC_ALL_TO_ONE not defined"
		#endif
		#ifndef SYNC_CREATE_MAX
		#error "SYNC_CREATE_MAX not defined"
		#endif
		#ifndef SYNC_OPEN_MAX
		#error "SYNC_OPEN_MAX not defined"
		#endif

		/* Functions */
		#ifndef __sync_create_fn
		#error "sync_create() not defined?"
		#endif
		#ifndef __sync_open_fn
		#error "sync_open() not defined?"
		#endif
		#ifndef __sync_unlink_fn
		#error "sync_unlink() not defined?"
		#endif
		#ifndef __sync_close_fn
		#error "sync_close_() not defined?"
		#endif
		#ifndef __sync_wait_fn
		#error "sync_wait() not defined?"
		#endif
		#ifndef __sync_signal_fn
		#error "sync_signal() not defined?"
		#endif

	#else

		/* Constants */
		#define SYNC_ONE_TO_ALL 0
		#define SYNC_ALL_TO_ONE 1
		#define SYNC_CREATE_MAX 1
		#define SYNC_OPEN_MAX   1

	#endif

#endif

/*============================================================================*
 * Provided Interface                                                         *
 *============================================================================*/

/**
 * @defgroup kernel-hal-target-sync Syncrhonization service
 * @ingroup kernel-hal-target
 *
 * @brief Target Standard Output HAL Interface
 */
/**@{*/

	#include <nanvix/klib.h>

	/**
	 * @brief Allocates and configures the receiving side of the synchronization point.
	 *
	 * @param nodes  IDs of target NoC nodes.
	 * @param nnodes Number of target NoC nodes.
	 * @param type   Type of synchronization point.
	 *
	 * @return The tag of underlying resource ID.
	 */
#if (TARGET_HAS_SYNC)
	EXTERN int sync_create(const int *nodes, int nnodes, int type);
#else
	static inline int sync_create(const int *nodes, int nnodes, int type)
	{
		UNUSED(nodes);
		UNUSED(nnodes);
		UNUSED(type);

		return (0);
	}
#endif

	/**
	 * @brief Allocates and configures the sending side of the synchronization point.
	 *
	 * @return The tag of underlying resource ID.
	 */
#if (TARGET_HAS_SYNC)
	EXTERN int sync_open(void);
#else
	static inline int sync_open(void)
	{
		return (0);
	}
#endif

	/**
	 * @brief Releases and cleans receiver buffer.
	 *
	 * @param syncid Resource ID.
	 *
	 * @return Zero if free the resource and non zero otherwise.
	 */
#if (TARGET_HAS_SYNC)
	EXTERN int sync_unlink(int syncid);
#else
	static inline int sync_unlink(int syncid)
	{
		UNUSED(syncid);

		return (0);
	}
#endif

	/**
	 * @brief Releases the sender resources on a specific DMA channel.
	 *
	 * @param syncid Resource ID.
	 *
	 * @return Zero if free the resource and non zero otherwise.
	 */
#if (TARGET_HAS_SYNC)
	EXTERN int sync_close(int syncid);
#else
	static inline int sync_close(int syncid)
	{
		UNUSED(syncid);

		return (0);
	}
#endif

	/**
	 * @brief Wait signal on a specific synchronization point.
	 *
	 * @param syncid Resource ID.
	 *
	 * @return Zero if wait signal correctly and non zero otherwise.
	 */
#if (TARGET_HAS_SYNC)
	EXTERN int sync_wait(int syncid);
#else
	static inline int sync_wait(int syncid)
	{
		UNUSED(syncid);

		return (0);
	}
#endif

	/**
	 * @brief Send signal on a specific synchronization point.
	 *
	 * @param syncid Resource ID.
	 * @param nodes  IDs of target NoC nodes.
	 * @param nnodes Number of target NoC nodes.
	 * @param type   Type of synchronization point.
	 *
	 * @return Zero if send signal correctly and non zero otherwise.
	 */
#if (TARGET_HAS_SYNC)
	EXTERN int sync_signal(int syncid, const int *nodes, int nnodes, int type);
#else
	static inline int sync_signal(int syncid, const int *nodes, int nnodes, int type)
	{
		UNUSED(syncid);
		UNUSED(nodes);
		UNUSED(nnodes);
		UNUSED(type);

		return (0);
	}
#endif

/**@}*/

#endif /* NANVIX_HAL_TARGET_SYNC_H_ */
