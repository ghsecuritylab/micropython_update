/**   
 * \par Copyright (C), 2017-2018, MakeBlock
 * \brief     Heard for all makeblock codey_message.c.
 * @file      codey_message.h
 * @author    Leo
 * @version   V1.0.0
 * @date      2017/10/13
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
 * This file is a header message up function.
 *
 * \par Method List:
 *
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 *   Leo              2017/10/13      1.0.0              build the new.
 * </pre>
 *
 */

#ifndef _CODEY_MESSAGE_H_
#define _CODEY_MESSAGE_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "codey_comm_protocol.h"

extern const mp_obj_type_t codey_message_type;

extern void codey_message_recv(channel_data_tag_t chn, uint8_t *data, uint32_t len, uint8_t *output_buf, uint32_t *output_len);

#endif /* _CODEY_MESSAGE_H_ */
