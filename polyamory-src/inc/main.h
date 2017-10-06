/*
 * osc.c
 *
 *  Created on: Oct 6, 2017
 *      Author: Nick McCarty
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32412g_discovery.h"
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_audio.h"
#include <stdio.h>

/* Global Macro Defines */
#define BUFF_LEN_DIV4           1 // number of samples <==> XX ms latency at 48kHz
#define BUFF_LEN_DIV2           2
#define BUFF_LEN                4  // Audio buffer length : count in 16bits half-words

#endif /* __MAIN_H */


