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

#ifndef PROCESSOR_BOSTAN_NOC_DMA_H_
#define PROCESSOR_BOSTAN_NOC_DMA_H_

/**
 * @addtogroup processor-bostan-noc
 * @ingroup processor-bostan
 */
/**@*/

/* Processor Interface Implementation */
#include <arch/processor/bostan/_bostan.h>

#include <arch/processor/bostan/noc/ctag.h>
#include <arch/processor/bostan/noc/dtag.h>
#include <errno.h>

/*============================================================================*
 * Control DMA Interface                                                      *
 *============================================================================*/

	/**
	 * @brief Allocates and configures the control receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the control receiver buffer.
	 * @param mask      Initial value of the buffer.
	 *
	 * @return Zero if create sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_control_create(int interface, int tag, uint64_t mask);

	/**
	 * @brief Re-configure C-NoC control receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the control receiver buffer.
	 * @param mask      Initial value of the buffer.
	 *
	 * @return Zero if configure sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_control_config(int interface, int tag, uint64_t mask);

	/**
	 * @brief Allocates the control transfer buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the control transfer buffer.
	 *
	 * @return Zero if open sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_control_open(int interface, int tag);

	/**
	 * @brief Releases and cleans the control receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the control transfer buffer.
	 *
	 * @return Zero if unlink sucefully and non zero otherwise.
	 */
	static inline int bostan_dma_control_unlink(int interface, int tag)
	{
		if (!bostan_cnoc_rx_is_valid(interface, tag))
			return (-EINVAL);

		bostan_cnoc_rx_clear(interface, tag);
		bostan_cnoc_rx_free(interface, tag);

		return (0);
	}

	/**
	 * @brief Releases the control transfer buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the control transfer buffer.
	 *
	 * @return Zero if close sucefully and non zero otherwise.
	 */
	static inline int bostan_dma_control_close(int interface, int tag)
	{
		if (!bostan_cnoc_tx_is_valid(interface, tag))
			return (-EINVAL);

		bostan_cnoc_tx_free(interface, tag);

		return (0);
	}

	/**
	 * @brief Wait an event on the control receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the control transfer buffer.
	 *
	 * @return Zero if wait sucefully and non zero otherwise.
	 */
	static inline int bostan_dma_control_wait(int interface, int tag)
	{
		if (!bostan_cnoc_rx_is_valid(interface, tag))
			return (-EINVAL);

		return bostan_cnoc_rx_wait(interface, tag);
	}

	/**
	 * @brief Configure and send a signal on a control transfer buffer.
	 *
	 * @param interface    Number of the DMA channel.
	 * @param source_node  Source Node ID.
	 * @param source_tag   Number of the control transfer buffer.
	 * @param target_nodes Target Node IDs.
	 * @param ntargets     Amount of targets.
	 * @param target_tag   Number of the target control receiver buffer.
	 * @param mask         Signal value.
	 *
	 * @return Zero if send sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_control_signal(
		int interface,
		int source_node,
		int source_tag,
		const int *target_nodes,
		int ntargets,
		int target_tag,
		uint64_t mask
	);

/*============================================================================*
 * Data DMA Interface                                                         *
 *============================================================================*/

	/**
	 * @brief Allocates the data receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the data receiver buffer.
	 *
	 * @return Zero if create sucefully and non zero otherwise.
	 */
	static inline int bostan_dma_data_create(int interface, int tag)
	{
		if (!bostan_dnoc_rx_is_valid(interface, tag))
			return (-EINVAL);

		return bostan_dnoc_rx_alloc(interface, tag);
	}

	/**
	 * @brief Allocates the data transfer buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the data transfer buffer.
	 *
	 * @return Zero if open sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_data_open(int interface, int tag);

	/**
	 * @brief Releases and cleans the data receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the data transfer buffer.
	 *
	 * @return Zero if unlink sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_data_unlink(int interface, int tag);

	/**
	 * @brief Releases the data transfer buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the data transfer buffer.
	 *
	 * @return Zero if close sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_data_close(int interface, int tag);

	/**
	 * @brief Wait an event on the data receiver buffer.
	 *
	 * @param interface Number of the DMA channel.
	 * @param tag       Number of the data transfer buffer.
	 *
	 * @return Zero if wait sucefully and non zero otherwise.
	 */
	EXTERN int bostan_dma_data_wait(int interface, int tag);

	/**
	 * @todo Provide a detailed comment for this.
	 */
	EXTERN int bostan_dma_data_read(
		int interface,
		int tag
		/* Note: New parameters will be inserted during portal and mailbox development. */
	);


	/**
	 * @todo Provide a detailed comment for this.
	 */
	EXTERN int bostan_dma_data_write(
		int interface,
		int tag
		/* Note: New parameters will be inserted during portal and mailbox development. */
	);

/**@}*/

#endif /* PROCESSOR_BOSTAN_NOC_DMA_H_ */
