#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/debug.h"
#include "driverlib/adc.h"


int main(void) {
	uint32_t ui32ADC0Value[4];
	uint32_t ui32ADC1Value[4];
	volatile uint32_t ui32HorizontalAvg;
	volatile uint32_t ui32VerticalAvg;
	char temp1, temp2;

	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	ADCHardwareOversampleConfigure(ADC0_BASE, 64);

	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH6);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_CH6);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_CH6);
	ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_CH6|ADC_CTL_IE|ADC_CTL_END);
	ADCSequenceEnable(ADC0_BASE, 1);


	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
	ADCHardwareOversampleConfigure(ADC1_BASE, 64);

	ADCSequenceConfigure(ADC1_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC1_BASE, 1, 0, ADC_CTL_CH7);
	ADCSequenceStepConfigure(ADC1_BASE, 1, 1, ADC_CTL_CH7);
	ADCSequenceStepConfigure(ADC1_BASE, 1, 2, ADC_CTL_CH7);
	ADCSequenceStepConfigure(ADC1_BASE,1,3,ADC_CTL_CH7|ADC_CTL_IE|ADC_CTL_END);
	ADCSequenceEnable(ADC1_BASE, 1);

	UARTCharPut(UART0_BASE, 'H');
	UARTCharPut(UART0_BASE, ' ');
	UARTCharPut(UART0_BASE, 'V');
	UARTCharPut(UART0_BASE, '\n');

	while(1) {
		ADCIntClear(ADC0_BASE, 1);
		ADCProcessorTrigger(ADC0_BASE, 1);

		ADCIntClear(ADC1_BASE, 1);
		ADCProcessorTrigger(ADC1_BASE, 1);

		while(!ADCIntStatus(ADC1_BASE, 1, false) && !ADCIntStatus(ADC0_BASE, 1, false)) {
		}

		ADCSequenceDataGet(ADC0_BASE, 1, ui32ADC0Value);
		ui32HorizontalAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;

		ADCSequenceDataGet(ADC1_BASE, 1, ui32ADC1Value);
		ui32VerticalAvg = (ui32ADC1Value[0] + ui32ADC1Value[1] + ui32ADC1Value[2] + ui32ADC1Value[3] + 2)/4;

		temp1 = (char)( ui32HorizontalAvg / 32 );
		UARTCharPut(UART0_BASE, temp1 );
		UARTCharPut(UART0_BASE, ' ');
		temp2 = (char)( ui32VerticalAvg / 32 );
		UARTCharPut(UART0_BASE, temp2 );
		UARTCharPut(UART0_BASE, '\n');
		SysCtlDelay(670000);
	}
}
