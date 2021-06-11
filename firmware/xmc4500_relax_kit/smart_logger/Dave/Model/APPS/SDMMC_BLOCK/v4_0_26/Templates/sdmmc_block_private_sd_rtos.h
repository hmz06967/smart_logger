
/**
 * @file sdmmc_block_private_sd_rtos.c
 * @date 2016-08-24
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * SDMMC_BLOCK v4.0.26 - Configures the SD host to interface with the SDMMC card.
 *
 * Copyright (c) 2016-2018, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2016-02-05:
 *     - Initial version. <br>
 *
 * 2016-02-08:
 *     - Help doc updated. <br>
 *     - bug fixes. <br>
 *
 * 2016-04-05
 *     - MISRA fixes <br>
 *
 * @endcond
 */



#ifndef SDMMC_BLOCK_SD_H
#define SDMMC_BLOCK_SD_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include <string.h>
#include "sdmmc_block.h"

#ifdef SDMMC_BLOCK_SD

/***********************************************************************************************************************
 * LOCAL DATA
 **********************************************************************************************************************/

extern const XMC_SDMMC_COMMAND_t sdmmc_block_command[40];
extern const uint8_t sdmmc_block_sd_hash_table[65];

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/**
 * @brief This structure stores the command register fields.
 */
#define SDMMC_BLOCK_COMMON_COMMAND(c) sdmmc_block_command[sdmmc_block_sd_hash_table[c]]
#define SDMMC_BLOCK_SD_COMMAND(c)     SDMMC_BLOCK_COMMON_COMMAND(c)

#define SDMMC_BLOCK_ERROR_CMD_STATUS_BITMASK        (0x000FU) /* Command line Int errors status bit-mask */
#define SDMMC_BLOCK_ERROR_DATA_STATUS_BITMASK       (0x0070U) /* Data line Error status bitmask */
#define SDMMC_BLOCK_TX_BLOCK_SIZE_VALUE             (0x0200U) /* Transfer block register */
#define SDMMC_BLOCK_HC_RESPONSE1_BITPOS             (0x10U)   /* Response register */
#define SDMMC_BLOCK_SWITCH_FUNC_GRP1_STATUS_BITMASK (0x0000000FU) /* Switch speed function bit-mask */
#define SDMMC_BLOCK_SWITCH_FUNC_GRP1_STATUS_BITPOS  (0x0U)    /* Switch speed function bit-position */

/*
 * Append by 3 zeros since the SYSTIMER APP takes
 * time in microseconds
 */
#define SDMMC_BLOCK_CARD_POWER_DELAY       (20U)   /* Card power delay */
#define SDMMC_BLOCK_DELAY_IN_TRANSFER      (1000U) /* Transfer delay */
#define SDMMC_BLOCK_RESET_IN_DATA_TRANSFER (1000U) /* Reset in data transfer */
#define SDMMC_BLOCK_DELAY_IN_COMMAND       (1000U) /* Command delay */
#define SDMMC_BLOCK_RESET_DELAY            (500U)  /* Reset delay */
#define SDMMC_BLOCK_CLOCK_STABLE_DELAY     (1000U) /* Clock stable delay */

#define SDMMC_BLOCK_NUM_CARD_RESET_RETRIES (2U)   /* Number of reset retries at card init */
#define SDMMC_BLOCK_BLOCK_SIZE             (512U) /* Block Size in bytes */
#define SDMMC_BLOCK_NUM_QUADLETS_IN_BLOCK  (SDMMC_BLOCK_BLOCK_SIZE >> 2U) /* Block size in quad bytes */

/* Command index  */
#define SDMMC_BLOCK_GO_IDLE_STATE          (0x00U) /* CMD0 */
#define SDMMC_BLOCK_MMC_SEND_OP_COND       (0x01U) /* MMC CMD1 */
#define SDMMC_BLOCK_ALL_SEND_CID           (0x02U) /* CMD2 */
#define SDMMC_BLOCK_SEND_RELATIVE_ADDR     (0x03U) /* CMD3 */
#define SDMMC_BLOCK_SET_DSR                (0x04U) /* CMD4 */
#define SDMMC_BLOCK_MMC_SLEEP_AWAKE        (0x05U) /* MMC CMD5  */
#define SDMMC_BLOCK_SWITCH_FUNC            (0x06U) /* CMD6 */
#define SDMMC_BLOCK_SELECT_DESELECT_CARD   (0x07U) /* CMD7 */
#define SDMMC_BLOCK_SD_SEND_IF_COND        (0x08U) /* SD CMD8 */
#define SDMMC_BLOCK_MMC_SEND_EXT_CSD       (0x08U) /* MMC CMD8 */
#define SDMMC_BLOCK_SEND_CSD               (0x09U) /* CMD9 */
#define SDMMC_BLOCK_SEND_CID               (0x0AU) /* CMD10 */
#define SDMMC_BLOCK_STOP_TRANSMISSION      (0x0CU) /* CMD12 */
#define SDMMC_BLOCK_SEND_STATUS            (0x0DU) /* CMD13 */
#define SDMMC_BLOCK_GO_INACTIVE_STATE      (0x0FU) /* CMD15 */
#define SDMMC_BLOCK_SET_BLOCKLEN           (0x10U) /* CMD16 */
#define SDMMC_BLOCK_READ_SINGLE_BLOCK      (0x11U) /* CMD17 */
#define SDMMC_BLOCK_READ_MULTIPLE_BLOCK    (0x12U) /* CMD18 */
#define SDMMC_BLOCK_WRITE_BLOCK            (0x18U) /* CMD24 */
#define SDMMC_BLOCK_WRITE_MULTIPLE_BLOCK   (0x19U) /* CMD25 */
#define SDMMC_BLOCK_PROGRAM_CSD            (0x1BU) /* CMD27 */
#define SDMMC_BLOCK_SET_WRITE_PROT         (0x1CU) /* CMD28 */
#define SDMMC_BLOCK_CLR_WRITE_PROT         (0x1DU) /* CMD29 */
#define SDMMC_BLOCK_SEND_WRITE_PROT        (0x1EU) /* CMD30 */
#define SDMMC_BLOCK_ERASE_WR_BLK_START     (0x20U) /* CMD32 */
#define SDMMC_BLOCK_ERASE_WR_BLK_END       (0x21U) /* CMD33 */
#define SDMMC_BLOCK_ERASE_GROUP_START      (0x23U) /* CMD35 */
#define SDMMC_BLOCK_ERASE_GROUP_END        (0x24U) /* CMD36 */
#define SDMMC_BLOCK_ERASE                  (0x26U) /* CMD38 */
#define SDMMC_BLOCK_LOCK_UNLOCK            (0x2AU) /* CMD42 */
#define SDMMC_BLOCK_APP_CMD                (0x37U) /* CMD55 */
#define SDMMC_BLOCK_GEN_CMD                (0x38U) /* CMD56 */
#define SDMMC_BLOCK_SET_BUS_WIDTH          (0x06U) /* ACMD6 */
#define SDMMC_BLOCK_SD_STATUS              (0x0DU) /* ACMD13 */
#define SDMMC_BLOCK_SEND_NUM_WR_BLOCKS     (0x16U) /* ACMD22 */
#define SDMMC_BLOCK_SET_WR_BLK_ERASE_COUNT (0x17U) /* ACMD23 */
#define SDMMC_BLOCK_SD_SEND_OP_COND        (0x29U) /* ACMD41 */
#define SDMMC_BLOCK_SET_CLR_CARD_DETECT    (0x2AU) /* ACMD42 */
#define SDMMC_BLOCK_SEND_SCR               (0x33U) /* ACMD51 */

/* Start of Card Status Register i.e CSR Error Bits bitmask */
#define SDMMC_BLOCK_SD_CSR_OUT_OF_RANGE_BITMASK       (0x80000000U)
#define SDMMC_BLOCK_SD_CSR_ADDRESS_ERROR_BITMASK      (0x40000000U)
#define SDMMC_BLOCK_SD_CSR_BLOCK_LEN_ERROR_BITMASK    (0x20000000U)
#define SDMMC_BLOCK_SD_CSR_ERASE_SEQ_ERROR_BITMASK    (0x10000000U)
#define SDMMC_BLOCK_SD_CSR_ERASE_PARAM_BITMASK        (0x08000000U)
#define SDMMC_BLOCK_SD_CSR_WP_VIOLATION_BITMASK       (0x04000000U)
#define SDMMC_BLOCK_SD_CSR_LOCK_UNLOCK_FAILED_BITMASK (0x01000000U)
#define SDMMC_BLOCK_SD_CSR_COM_CRC_ERROR_BITMASK      (0x00800000U)
#define SDMMC_BLOCK_SD_CSR_ILLEGAL_COMMAND_BITMASK    (0x00400000U)
#define SDMMC_BLOCK_SD_CSR_CARD_ECC_FAILED_BITMASK    (0x00200000U)
#define SDMMC_BLOCK_SD_CSR_CC_ERROR_BITMASK           (0x00100000U)
#define SDMMC_BLOCK_SD_CSR_ERROR_BITMASK              (0x00080000U)
#define SDMMC_BLOCK_SD_CSR_CSD_OVERWRITE_BITMASK      (0x00010000U)
#define SDMMC_BLOCK_SD_CSR_WP_ERASE_SKIP_BITMASK      (0x00008000U)
#define SDMMC_BLOCK_SD_SWITCH_ERROR_BITMASK           (0x00000080U)
#define SDMMC_BLOCK_SD_CSR_ASK_SEQ_ERROR_BITMASK      (0x00000008U)
#define SDMMC_BLOCK_SD_CSR_CARD_IS_LOCKED_BITMASK     (0x02000000U)
#define SDMMC_BLOCK_SD_CSR_CURRENT_STATE_BITMASK      (0x00001D00U)
#define SDMMC_BLOCK_SD_CSR_CURRENT_STATE_BITPOS       (0x00000009U)
#define SDMMC_BLOCK_SD_CSR_CURRENT_STATE_TRANS_VALUE  (0x00000004U)
#define SDMMC_BLOCK_SD_CSR_CARD_IS_LOCKED_BITMASK     (0x02000000U)

/* Normal and error interrupt status defines */
#define SDMMC_BLOCK_NORMAL_INT_STATUS_ENABLE          (0x00F3U)
#define SDMMC_BLOCK_ERROR_INT_STATUS_ENABLE           (0xE0FFU)
#define SDMMC_BLOCK_NORMAL_INT_SIGNAL_ENABLE          (0x0033U)
#define SDMMC_BLOCK_ERROR_INT_SIGNAL_ENABLE           (0xE0FFU)

/***********************************************************************************************************************
 * ENUMS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * API PROTOTYPES
 **********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetLockStatus(SDMMC_BLOCK_t *const obj, SDMMC_BLOCK_CARD_LOCK_STATUS_t *lock_stat);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_CardIdentificationProcess(SDMMC_BLOCK_t *const obj);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetSdStatus(SDMMC_BLOCK_t *const obj, void *buf);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetSectorCount(SDMMC_BLOCK_t *const obj, void *buf);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetCid(SDMMC_BLOCK_t *const obj, void *buf);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetOcr(SDMMC_BLOCK_t *const obj, void *buf);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetCsd(SDMMC_BLOCK_t *const obj, void *buf);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetCardType(SDMMC_BLOCK_t *const obj, uint32_t *card_type);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_EraseBlock(SDMMC_BLOCK_t *const obj, uint32_t start_addr, uint32_t end_addr);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetSectorSize(SDMMC_BLOCK_t *const obj, void *buf);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_GetBlockSize(SDMMC_BLOCK_t *const obj, void *buf);

uint8_t
SDMMC_BLOCK_SD_GetState(SDMMC_BLOCK_t *const obj);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_Init(SDMMC_BLOCK_t *const obj);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_CheckLockStatus(SDMMC_BLOCK_t *const obj,
		                       SDMMC_BLOCK_CARD_LOCK_STATUS_t mode);

SDMMC_BLOCK_STATUS_t
SDMMC_BLOCK_SD_ReadBlock(SDMMC_BLOCK_t *const obj,
                         uint8_t *read_buf,
                         uint32_t sector_num,
                         uint8_t sector_count);

SDMMC_BLOCK_STATUS_t
SDMMC_BLOCK_SD_WriteBlock(SDMMC_BLOCK_t *const obj,
                          const uint8_t *write_buf,
                          uint32_t sector_num,
                          uint8_t sector_count);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_LockUnlockCard(SDMMC_BLOCK_t *const obj,
                              SDMMC_BLOCK_LOCK_STRUCTURE_t *lock,
							  SDMMC_BLOCK_CARD_LOCK_STATUS_t mode);

SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_EjectCard(SDMMC_BLOCK_t *const obj);

#ifdef __cplusplus
}
#endif

#endif /* #ifdef SDMMC_BLOCK_SD */

#endif /* SDMMC_BLOCK_SD_H */
