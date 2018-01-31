/**   
 * \par Copyright (C), 2017-2018, MakeBlock
 * \brief       Dtr request
 * @file        codey_dtr_req.c
 * @author      Leo lu
 * @version V1.0.0
 * @date        2017/11/03
 *
 * \par Copyright
 * This software is Copyright (C), 2012-2016, MakeBlock. Use is subject to license \n
 * conditions. The main licensing options available are GPL V2 or Commercial: \n
 *
 * \par Open Source Licensing GPL V2
 * This is the appropriate option if you want to share the source code of your \n
 * application with everyone you distribute it to, and you also want to give them \n
 * the right to share who uses it. If you wish to use this software under Open \n
 * Source Licensing, you must contribute all your source code to the open source \n
 * community in accordance with the GPL Version 2 when your application is \n
 * distributed. See http://www.gnu.org/copyleft/gpl.html
 *
 * \par Description
 * This file include some system function.
 *
 * \par Method List:
 *
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Leo lu             2017/11/03      1.0.0              Build the new.
 * </pre>
 *
 */
 
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "codey_utils.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "codey_comm_protocol.h"
#include "codey_wlan.h"
#include "codey_dtr_req.h"

/******************************************************************************
 DEFINE MACROS
 ******************************************************************************/ 
#undef    TAG
#define   TAG                           ("DTR_REQ")
#define   DTR_REQ_EXP_DATA_LEN          (1)
#define   DTR_REQ_CMD                   (0x01)
#define   DTR_RSP_CMD                   (0x02)
#define   DTR_RESTRAT_WAIT_TIME         (2000) // ms
                                            
/******************************************************************************
 DEFINE TYPES & CONSTANTS
 ******************************************************************************/  

/******************************************************************************
 DEFINE PRIVATE DATAS
 ******************************************************************************/
extern SemaphoreHandle_t s_sys_dtr_cmd_require_sema;
extern SemaphoreHandle_t s_sys_dtr_cmd_respond_sema;

/******************************************************************************
 DECLARE PRIVATE FUNCTIONS
 ******************************************************************************/

/******************************************************************************
 DEFINE PUBLIC FUNCTIONS
 ******************************************************************************/
void codey_dtr_req(channel_data_tag_t chn, uint8_t *data, uint32_t len, uint8_t *output_buf, uint32_t *output_len)
{
  if(!data || !len || !output_len || !output_buf)
  {
    return;
  }

  if(DTR_REQ_EXP_DATA_LEN != len)
  {
    return;
  }

  if(DTR_REQ_CMD == data[0])
  {
    // Request to pull dtr
    ESP_LOGI(TAG, "Preparing for pull DTR");

    // Call other funciton to ready
    xSemaphoreGive(s_sys_dtr_cmd_require_sema); 
    if(xSemaphoreTake(s_sys_dtr_cmd_respond_sema, DTR_RESTRAT_WAIT_TIME / portTICK_PERIOD_MS) == pdTRUE)
    {
      output_buf[0] = DTR_RSP_CMD;
      *output_len = 1;
    }
    else
    {
      *output_len = 0;
    }
  }
  else
  {
    *output_len = 0;
  }
}

/******************************************************************************
 DEFINE PRIVATE FUNCTIONS
 ******************************************************************************/


