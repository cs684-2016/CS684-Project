////lab5 part 2
//#include <stdint.h>
//#include <stdbool.h>
//#include "inc/hw_memmap.h"
//#include "inc/hw_types.h"
//#include "driverlib/sysctl.h"
//#include "driverlib/gpio.h"
//#include "inc/hw_gpio.h"
//#include "driverlib/adc.h"
//#include "driverlib/rom.h"
//#include "hexcode.h"
//uint8_t ui8PinData=2;
//
//void glcd_cmd(unsigned char cmd){
//	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
//	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, 0x00);
//
//	GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x00);
//
//	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, cmd);
//	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, cmd);
//
//	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x01);
//	SysCtlDelay(1340);
//	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x00);
//}
//
//void glcd_data(unsigned char data){
//	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
//	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, 0x00);
//
//	GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x40);
//
//	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, data);
//	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, data);
//
//	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x01);
//	SysCtlDelay(1340);
//	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x00);
//}
//
//
//void glcd_init(){
//	SysCtlDelay(134000);
//	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x00);
//	SysCtlDelay(134000);
//	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x20);
//	SysCtlDelay(134000);
//	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x00);
//
//	glcd_cmd(0xC0);
//
//	glcd_cmd(0xB8);
//
//	glcd_cmd(0x40);
//
//	glcd_cmd(0x3F);
//
//
//
//	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x08);
//	glcd_cmd(0xC0);
//
//	glcd_cmd(0xB8);
//
//	glcd_cmd(0x40);
//
//	glcd_cmd(0x3F);
//
//}
//
//
//void glcd_setpage(unsigned char page){
//	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x00);
//	glcd_cmd(0xB8|page);
//	//glcd_cmd(page);
//	SysCtlDelay(1000);
//
//	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x08);
//	glcd_cmd(0xB8|page);
//	//glcd_cmd(page);
//	SysCtlDelay(1000);
//}
//
//void glcd_setcolumn(unsigned char column){
//	if(column<64){
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x00);
//		glcd_cmd(0x40|column);
//		//glcd_cmd(column);
//		SysCtlDelay(6700);
//	}
//	else{
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x08);
//		glcd_cmd(0x40|(column-64));
//		//glcd_cmd((column-64));
//		SysCtlDelay(6700);
//	}
//}
//
//void glcd_cleardisplay(){
//	unsigned char i,j;
//	for(i=0;i<8;i++){
//		glcd_setpage(i);
//		for(j=0;j<128;j++){
//			glcd_setcolumn(j);
//			glcd_data(0x00);
//		}
//	}
//}
//
//void glcd_displayimage(unsigned char a[]){
//	unsigned char j=0;
//	unsigned char p=0;
//	unsigned char i;
//	while(p<8){
//		glcd_setpage(p);
//		for(i=0;i<128;i++){
//			glcd_setcolumn(i);
//			glcd_data(a[j]);
//			j++;
//		}
//		p++;
//	}
//}
//
//void glcd_displaypoint(unsigned char row, unsigned char col){
//   glcd_cleardisplay();
//   glcd_setpage(row);
//   glcd_setcolumn(col);
//   glcd_data(0xFF);
//}
//
//int main(void)
//{
//	uint32_t ui32ADC0Value[4];
//	uint32_t ui32ADC1Value[4];
//	volatile uint32_t ui32HorizontalAvg;
//	volatile uint32_t ui32VerticalAvg;
//
//	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
//
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
//	ADCHardwareOversampleConfigure(ADC0_BASE, 64);
//
//	ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
//	ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH6);
//	ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_CH6);
//	ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_CH6);
//	ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_CH6|ADC_CTL_IE|ADC_CTL_END);
//	ADCSequenceEnable(ADC0_BASE, 1);
//
//
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
//	ADCHardwareOversampleConfigure(ADC1_BASE, 64);
//
//	ADCSequenceConfigure(ADC1_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
//	ADCSequenceStepConfigure(ADC1_BASE, 1, 0, ADC_CTL_CH7);
//	ADCSequenceStepConfigure(ADC1_BASE, 1, 1, ADC_CTL_CH7);
//	ADCSequenceStepConfigure(ADC1_BASE, 1, 2, ADC_CTL_CH7);
//	ADCSequenceStepConfigure(ADC1_BASE,1,3,ADC_CTL_CH7|ADC_CTL_IE|ADC_CTL_END);
//	ADCSequenceEnable(ADC1_BASE, 1);
//
//	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
//	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
//	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
//
//	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_6);
//	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);
//	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3);
//	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5);
//	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
//
//
//	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
//
//	glcd_init();
//
//	glcd_cleardisplay();
//	glcd_displayimage(a);
//	while(1)
//	{
//
//		ADCIntClear(ADC0_BASE, 1);
//		ADCProcessorTrigger(ADC0_BASE, 1);
//
//		ADCIntClear(ADC1_BASE, 1);
//		ADCProcessorTrigger(ADC1_BASE, 1);
//
//		while(!ADCIntStatus(ADC1_BASE, 1, false) && !ADCIntStatus(ADC0_BASE, 1, false)) {
//		}
//
//		ADCSequenceDataGet(ADC0_BASE, 1, ui32ADC0Value);
//		ui32HorizontalAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
//
//		ADCSequenceDataGet(ADC1_BASE, 1, ui32ADC1Value);
//		ui32VerticalAvg = (ui32ADC1Value[0] + ui32ADC1Value[1] + ui32ADC1Value[2] + ui32ADC1Value[3] + 2)/4;
//
//		unsigned char col = ui32HorizontalAvg/32;
//		unsigned char row = ui32VerticalAvg/512;
//		glcd_displaypoint((7-row),(127-col));
//
//
//		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8PinData);
//		SysCtlDelay(2000000);
//		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
//		SysCtlDelay(2000000);
//		if(ui8PinData==8) {ui8PinData=2;} else {ui8PinData=ui8PinData*2;}
//	}
//
//}
