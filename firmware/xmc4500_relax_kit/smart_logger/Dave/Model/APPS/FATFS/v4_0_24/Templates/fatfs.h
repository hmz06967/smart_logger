/**
 * @file fatfs.h
 * @date 2016-07-20
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is
 * regenerated.
 */
/**
 * @cond
 ***********************************************************************************************************************
 * FATFS v4.0.24 Provides the support for FATFS library
 *
 * Copyright (c) 2015-2018, Infineon Technologies AG
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
 *     - Initial version<br>
 *
 * @endcond
 *
 */

#ifndef FATFS_H
#define FATFS_H

/*********************************************************************************************************************
 * HEADER FILES
 ********************************************************************************************************************/
#include <xmc_common.h>
#include <DAVE_Common.h>

#include "ff_Src/ffconf.h"
#include "ff_Src/diskio.h"
#include "ff_Src/ff.h"

#include "fatfs_conf.h"

#include "SDMMC_BLOCK/SDMMC_BLOCK.h"

#if (FF_FS_REENTRANT == 1U)
#include "CMSIS_RTOS_RTX/INC/cmsis_os.h"
#endif

#if ((FF_FS_NORTC == 0U) && (FF_FS_READONLY == 0U))
#include "xmc_rtc.h"
#include "RTC/rtc.h"
#endif



/*********************************************************************************************************************
 * MACROS
 ********************************************************************************************************************/
#define FATFS_MAX_LOGICAL_DRIVES   (3U)
/*********************************************************************************************************************
 * ENUMS
 ********************************************************************************************************************/
/**
 * @ingroup FATFS_enumerations
 * @{
 */
/**
 * Initialization status.
 */
typedef enum FATFS_STATUS
{
  FATFS_STATUS_SUCCESS = 0U,   /**< Status success */
  FATFS_STATUS_FAILURE         /**< Status failure */
} FATFS_STATUS_t;

/**
 * @}
 */
/*********************************************************************************************************************
                         Global Variable Definitions
*********************************************************************************************************************/
/**
 * Function Pointer pointing to the Block Layer's disk initialize function.
 */
typedef SDMMC_BLOCK_STATUS_t (*InitializeFunc)(SDMMC_BLOCK_t *const handle);
/**
 * Function Pointer pointing to the Block Layer's  get disk status function.
 */
typedef uint8_t (*GetStatusFunc)(SDMMC_BLOCK_t *const handle);
/**
 * Function Pointer pointing to the Block Layer's read block function.
 */
typedef SDMMC_BLOCK_STATUS_t (*ReadBlkFunc)(SDMMC_BLOCK_t *const handle, uint8_t* buffer, uint32_t sectnumber, uint8_t count);
/**
 * Function Pointer pointing to the Block Layer's write block function.
 */
typedef SDMMC_BLOCK_STATUS_t (*WriteBlkFunc)(SDMMC_BLOCK_t *const handle, uint8_t* buffer, const uint32_t sectnumber, const uint8_t count);
/**
 * Function Pointer pointing to the Block Layer's IOCTL function.
 */
typedef SDMMC_BLOCK_STATUS_t (*IoctlFunc)(SDMMC_BLOCK_t *const handle, const uint8_t cmd, void * buffer );
/*********************************************************************************************************************
 * DATA STRUCTURES
 *********************************************************************************************************************/
/**
 * This structure holds the block layers' devices' function pointers data type
 * as member fields
 */
typedef struct FATFS_DEVICEFUNCTYPE
{
  InitializeFunc InitializePtr; /* Disk initialize function ptr */
  GetStatusFunc GetStatusPtr;   /* Get disk status function ptr */
  ReadBlkFunc ReadBlkPtr;       /* Read block of data from disk function ptr */
  WriteBlkFunc WriteBlkPtr;     /* Write blocks of data on disk function ptr */
  IoctlFunc IoctlPtr;           /* Ioctl function ptr */
} FATFS_DEVICEFUNCTYPE_t;

/**
 * @ingroup FATFS_datastructures
 * @{
 */
/**
 * This structure holds the FATFS handle configuration
 */
typedef struct FATFS
{
#if (FF_FS_NORTC == 0U)
  RTC_t * rtc_handle; /** < RTC APP handle pointer */
#endif
  bool initialized;  /**< FATFS initialization status*/
} FATFS_t;
/**
 * @}
 */
/*********************************************************************************************************************
 * API PROTOTYPES
 *********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup FATFS_apidoc
 * @{
 */

/**
 * @brief This API gets FATFS APP version.
 * @return @ref DAVE_APP_VERSION_t APP version information (major, minor and
 *                                 patch number)
 *
 * \par<b>Description: </b><br>
 * The function can be used to check application software compatibility with a
 * specific version of the APP.
 * @code
 * #include <DAVE.h>
 *
 * int main(void)
 * {
 *   DAVE_APP_VERSION_t version;
 *   DAVE_Init();
 *   version = FATFS_GetAppVersion();
 *   if(version.major != 4U)
 *   {
 *   }
 *   while(1)
 *   {}
 *   return 0;
 * }
 * @endcode<BR> </p>
 */
DAVE_APP_VERSION_t FATFS_GetAppVersion(void);
/**
 * @brief This API initializes FATFS APP instance.
 * @param handle Constant pointer to constant structure of type @ref FATFS_t
 * @return @ref FATFS_STATUS_t
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * Pre-requisite: Instantiate one instance of FATFS APP
 * @code
 *  #include <DAVE.h>
 *
 *  int main(void)
 *  {
 *    DAVE_Init();  // FATFS_Init(&FATFS_0) is called within DAVE_Init()
 *    while(1)
 *    {}
 *    return 0;
 *  }
 * @endcode<BR> </p>
 *
 */
FATFS_STATUS_t FATFS_Init(FATFS_t *const handle);

#ifdef __cplusplus
}
#endif

#include "fatfs_extern.h"

#endif
/**
 *@}
 */
/**
 * @}
 */
