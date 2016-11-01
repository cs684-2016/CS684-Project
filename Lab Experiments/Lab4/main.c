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
#include "driverlib/adc.h"
#include "driverlib/rom.h"
void UARTIntHandler(void)
{
 uint32_t ui32Status;
 ui32Status = UARTIntStatus(UART0_BASE, true); //get interrupt status
 UARTIntClear(UART0_BASE, ui32Status); //clear the asserted interrupts
	while(UARTCharsAvail(UART0_BASE)) //loop while there are chars
	{
		UARTCharPutNonBlocking(UART0_BASE, UARTCharGetNonBlocking(UART0_BASE)); //echo character
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2); //blink LED
		SysCtlDelay(SysCtlClockGet() / (1000 * 3)); //delay ~1 msec
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0); //turn off LED
	}
}

int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //enable GPIO port for LED
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //enable pin for LED PF2
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
	(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	IntMasterEnable(); //enable processor interrupts
	IntEnable(INT_UART0); //enable the UART interrupt
	UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT); //only enable RX and TX interrupts
	UARTCharPut(UART0_BASE, 'E');
	UARTCharPut(UART0_BASE, 'n');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 'r');
	UARTCharPut(UART0_BASE, ' ');
	UARTCharPut(UART0_BASE, 'T');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 'x');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, ':');
	UARTCharPut(UART0_BASE, ' ');
/* while (1) //let interrupt handler do the UART echo function
 {
	// if (UARTCharsAvail(UART0_BASE)) UARTCharPut(UART0_BASE, UARTCharGet(UART0_BASE));
 }*/


 	uint32_t ui32ADC0Value[4];
 	volatile uint32_t ui32TempAvg;
 	volatile uint32_t ui32TempValueC;
 	volatile uint32_t ui32TempValueF;
 	//ROM_SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
 	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
 	ROM_ADCHardwareOversampleConfigure(ADC0_BASE, 64);
 	ROM_ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
 	ROM_ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_TS);
 	ROM_ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_TS);
 	ROM_ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);
 	ROM_ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
 	ROM_ADCSequenceEnable(ADC0_BASE, 1);

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
 	ROM_ADCHardwareOversampleConfigure(ADC0_BASE, 64);
 	ROM_ADCSequenceConfigure(ADC1_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
 	ROM_ADCSequenceStepConfigure(ADC1_BASE, 1, 0,  ADC_CTL_TS);
 	ROM_ADCSequenceStepConfigure(ADC1_BASE, 1, 1, ADC_CTL_TS);
 	ROM_ADCSequenceStepConfigure(ADC1_BASE, 1, 2, ADC_CTL_TS);
 	ROM_ADCSequenceStepConfigure(ADC1_BASE,1,3,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
 	ROM_ADCSequenceEnable(ADC1_BASE, 1);
 	while(1)
 	{
 		ROM_ADCIntClear(ADC0_BASE, 1);
 		ROM_ADCProcessorTrigger(ADC0_BASE, 1);
 		while(!ROM_ADCIntStatus(ADC0_BASE, 1, false))
 		{
 		}
 		ROM_ADCSequenceDataGet(ADC0_BASE, 1, ui32ADC0Value);
 		ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
 		ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
 		ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;
 	}
}
