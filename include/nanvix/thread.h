/*
 * MIT License
 *
 * Copyright(c) 2018 Pedro Henrique Penna <pedrohenriquepenna@gmail.com>
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

/**
 * @defgroup kernel- Thread System
 * @ingroup kernel
 *
 * @brief Thread System
 */

#ifndef NANVIX_THREAD_H_
#define NANVIX_THREAD_H_

	/* External dependencies. */
	#include <nanvix/hal/hal.h>
	#include <nanvix/const.h>

/*============================================================================*
 *                                Thread System                               *
 *============================================================================*/

	/**
	 * @brief Maximum number of kernel threads.
	 */
	#define KTHREAD_MAX CORES_NUM

	/**
	 * @brief Maximum number of user threads.
	 */
	#define THREAD_MAX (KTHREAD_MAX - 1)

	/**
	 * @name Thread States
	 */
	/**@{*/
	#define THREAD_NOT_STARTED 0 /**< Not Started */
	#define THREAD_STARTED     1 /**< Started     */
	#define THREAD_RUNNING     2 /**< Running     */
	#define THREAD_SLEEPING    3 /**< Sleeping    */
	#define THREAD_TERMINATED  4 /**< Terminated  */
	/**@}*/

	/**
	 * @name Features
	 */
	/**@{*/
	#define KERNEL_THREAD_BAD_START 0 /**< Check for bad thread start routine? */
	#define KERNEL_THREAD_BAD_ARG   0 /**< Check for bad thread argument?      */
	#define KERNEL_THREAD_BAD_JOIN  0 /**< Check for bad thread join?          */
	#define KERNEL_THREAD_BAD_EXIT  0 /**< Check for bad thread exit?          */
	/**@}*/

	/**
	 * @brief Thread.
	 */
	struct thread
	{
		int tid;               /**< Thread ID.              */
		int state;             /**< State.                  */
		void *arg;             /**< Argument.               */
		void *(*start)(void*); /**< Starting routine.       */
		struct thread *next;   /**< Next thread in a queue. */
	};

	/**
	 * @brief Thread table.
	 */
	EXTERN struct thread threads[KTHREAD_MAX];

	/**
	 * @brief NULL thread ID.
	 */
	#define KTHREAD_NULL_TID -1

	/**
	 * @brief Master thread.
	 */
	#define KTHREAD_MASTER (&threads[0])

	/**
	 * @brief ID of master thread.
	 */
	#define KTHREAD_MASTER_TID 0

	/**
	 * @brief Gets the currently running thread.
	 *
	 * The thread_get() function returns a pointer to the thread
	 * that is running in the underlying core.
	 *
	 * @returns A pointer to the thread that is running in the
	 * underlying core.
	 */
	static inline struct thread *thread_get_curr(void)
	{
		return (&threads[core_get_id()]);
	}

	/**
	 * @brief Gets the core ID of a thread.
	 *
	 * @param t Target thread.
	 *
	 * The thread_get_coreid() function returns the ID of the core
	 * that the thread pointed to by @p t is running.
	 *
	 * @returns The ID of the core that the target thread is running.
	 */
	static inline int thread_get_coreid(const struct thread *t)
	{
		return (t - threads);
	}

	/**
	 * @brief Gets the ID of a thread.
	 *
	 * @param t Target thread.
	 *
	 * The thread_get_id() function returns the ID of the thread
	 * pointed to by @p t.
	 *
	 * @returns The ID of the target thread.
	 *
	 * @author Pedro Henrique Penna
	 */
	static inline int thread_get_id(const struct thread *t)
	{
		return (t->tid);
	}

	/**
	 * @brief Creates a thread.
	 *
	 * @param tid   Place to store the ID of the thread.
	 * @param start Thread start routine.
	 * @param arg   Argument for thread start routine.
	 *
	 * @returns Upon successful completion zero is returned. Upon
	 * failure, a negative error code is returned instead.
	 */
	EXTERN int thread_create(int *tid, void*(*start)(void*), void *arg);

	/**
	 * @brief Terminates the calling thread.
	 *
	 * @param retval Return value.
	 */
	EXTERN NORETURN void thread_exit(void *retval);

	/**
	 * @brief Waits for a thread to terminate.
	 *
	 * @param tid    Target thread to wait for.
	 * @param retval Target location to store return value.
	 *
	 * @returns Upon successful completion zero is returned. Upon
	 * failure, a negative error code is returned instead.
	 */
	EXTERN int thread_join(int tid, void **retval);

	/**
	 * @brief Atomically puts the calling thread to sleep.
	 *
	 * @param lock  Spinlock to release and acquire.
	 */
	EXTERN void thread_asleep(spinlock_t *lock);

	/**
	 * @brief Wakes up a thread.
	 *
	 * @param t Target thread.
	 */
	EXTERN void thread_wakeup(struct thread *t);

/*============================================================================*
 *                        Condition Variables Facility                        *
 *============================================================================*/

	/**
	 * @brief Condition variable.
	 */
	struct condvar
	{
		spinlock_t lock;      /**< Lock for sleeping queue. */
		struct thread *queue; /**< Sleeping queue.          */
	};

	/**
	 * @brief Static initializer for condition variables.
	 *
	 * The @p COND_INITIALIZER macro statically initiallizes a
	 * conditional variable.
	 */
	#define COND_INITIALIZER { .lock = SPINLOCK_UNLOCKED, .queue = NULL }

	/**
	 * @brief Initializes a condition variable.
	 *
	 * @param cond Target condition variable.
	 */
	static inline void cond_init(struct condvar *cond)
	{
		cond->lock = SPINLOCK_UNLOCKED;
		cond->queue = NULL;
	}

	/**
	 * @brief Waits on a condition variable.
	 *
	 * @param cond Target condition variable.
	 * @param lock Target spinlock to acquire.
	 *
	 * @returns Upon successful completion zero is returned. Upon
	 * failure, a negative error code is returned instead.
	 */
	EXTERN int cond_wait(struct condvar *cond, spinlock_t *lock);

	/**
	 * @brief Unlocks all threads waiting on a condition variable.
	 *
	 * @param cond Target condition variable.
	 *
	 * @returns Upon successful completion zero is returned. Upon
	 * failure, a negative error code is returned instead.
	 */
	EXTERN int cond_broadcast(struct condvar *cond);

/*============================================================================*
 *                            Semaphores Facility                             *
 *============================================================================*/

	/**
	 * @brief Semahore
	 */
	struct semaphore
	{
		int count;           /**< Semaphore counter.  */
		spinlock_t lock;     /**< Semaphore lock.     */
		struct condvar cond; /**< Condition variable. */
	};

	/**
	 * @brief Static initializer for semaphores.
	 *
	 * The @p SEMAPHORE_INIT macro statically initializes the fields of
	 * a semaphore. The initial value of the semaphore is set to @p x
	 * in the initialization.
	 *
	 * @param x Initial value for semaphore.
	 */
	#define SEMAPHORE_INITIALIZER(x) \
	{                                \
		.count = (x),                \
		.lock = SPINLOCK_UNLOCKED,   \
		.cond = COND_INITIALIZER,    \
	}

	/**
	 * @brief Initializes a semaphore.
	 *
	 * The semaphore_init() function dynamically initializes the
	 * fields of the semaphore pointed to by @p sem. The initial value
	 * of the semaphore is set to @p x in the initialization.
	 *
	 * @param sem Target semaphore.
	 * @param x   Initial semaphore value.
	 */
	static inline void semaphore_init(struct semaphore *sem, int x)
	{
		KASSERT(x >= 0);
		KASSERT(sem != NULL);

		sem->count = x;
		sem->lock = SPINLOCK_UNLOCKED;
		cond_init(&sem->cond);
	}

	/**
	 * @brief Performs a down operation in a semaphore.
	 *
	 * @param sem Target semaphore.
	 */
	EXTERN void semaphore_down(struct semaphore *sem);

	/**
	 * @brief Performs an up operation in a semaphore.
	 *
	 * @param sem target semaphore.
	 */
	EXTERN void semaphore_up(struct semaphore *sem);

#endif /* NANVIX_THREAD_H_ */

/**@}*/
