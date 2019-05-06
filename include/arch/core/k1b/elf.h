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

#ifndef ARCH_CORE_K1B_ELF_H_
#define ARCH_CORE_K1B_ELF_H_

	#ifndef __NEED_K1B_ELF
		#error "do not include this file"
	#endif

/**
 * @addtogroup k1b-core-elf ELF
 * @ingroup k1b-core
 *
 * @brief ELF Sections
 */
/**@{*/

	/**
	 * @name Binary Sections
	 */
	/**@{*/
	#define SECTION_TEXT __attribute__((section(".locked_text")))        /**< Text section.              */
	#define SECTION_BINDESC __attribute__((section(".locked.binaries"))) /**< Binary descriptor section. */
	/**@}*/

#ifndef _ASM_FILE_

	/**
	 * @name Binary Symbols
	 */
	/**@{*/
	extern int _bin_start_frame;   /**< Binary start frame.     */
	extern int _bin_end_frame;     /**< Binary end frame.       */
#ifdef __k1io__
	extern int _ddr_frame_start;   /**< DDR start frame.        */
	extern int _ddr_frame_end;     /**< DDR end frame.          */
	extern int __dtb_debut_offset; /**< Device tree offset.     */
	extern int __dtb_size;         /**< Device tree Size.       */
#endif
	extern int _user_stack_start;  /**< User stack start.       */
	extern int _user_stack_end;    /**< User stack end.         */
	extern int _vstart;            /**< Hypervisor entry point. */
	extern int _scoreboard_offset; /**< Scoreboard offset.      */
	extern int _kend;              /**< Kernel end address.     */
	/**@}*/

#endif /* _ASM_FILE_ */

/**@}*/

#endif /* ARCH_CORE_K1B_ELF_H_ */
