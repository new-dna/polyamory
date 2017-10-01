/**
  ******************************************************************************
  * @file    adc.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    17-February-2017
  * @brief   This example code shows how to use LCD drawing features.
  ******************************************************************************
  * @attention

  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* globals */
ADC_HandleTypeDef adcHandle;

/**
  * @brief  ADC demo
  * @param  None
  * @retval None
  */
void ConfigureADC(void)
{
    GPIO_InitTypeDef gpioInit;


    __GPIOC_CLK_ENABLE();
    __ADC1_CLK_ENABLE();

    gpioInit.Pin = GPIO_PIN_1;
    gpioInit.Mode = GPIO_MODE_ANALOG;
    gpioInit.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &gpioInit);

    HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(ADC_IRQn);

    ADC_ChannelConfTypeDef adcChannel;

    adcHandle.Instance = ADC1;

    adcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
    adcHandle.Init.Resolution = ADC_RESOLUTION_12B;
    adcHandle.Init.ScanConvMode = DISABLE;
    adcHandle.Init.ContinuousConvMode = ENABLE;
    adcHandle.Init.DiscontinuousConvMode = DISABLE;
    adcHandle.Init.NbrOfDiscConversion = 0;
    adcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    adcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
    adcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    adcHandle.Init.NbrOfConversion = 1;
    adcHandle.Init.DMAContinuousRequests = ENABLE;
    adcHandle.Init.EOCSelection = DISABLE;


    adcChannel.Channel = ADC_CHANNEL_11;
    adcChannel.Rank = 1;
    adcChannel.SamplingTime = ADC_SAMPLETIME_480CYCLES;
    adcChannel.Offset = 0;

    if (HAL_ADC_ConfigChannel(&adcHandle, &adcChannel) != HAL_OK)
    {
        asm("bkpt 255");
    }
}

void ADC_demo(void)
{
	uint32_t ADCValue;
	int MeasurementNumber;
	ConfigureADC();
	HAL_ADC_Init(&adcHandle);
	HAL_ADC_Start(&adcHandle);
	    for (;;)
	    {
	        if (HAL_ADC_PollForConversion(&adcHandle, 1000000) == HAL_OK)
	        {
	        	ADCValue = HAL_ADC_GetValue(&adcHandle);
	        	MeasurementNumber++;
	        }
	        if(CheckForUserInput() > 0)
	            {
	                return;
	            }
	    }

}

