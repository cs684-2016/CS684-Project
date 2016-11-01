////lab5 part1
//#include <stdint.h>
//#include <stdbool.h>
//#include "inc/hw_memmap.h"
//#include "inc/hw_types.h"
//#include "driverlib/sysctl.h"
//#include "driverlib/gpio.h"
//#include "inc/hw_gpio.h"
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
//	//glcd_cmd(0xC0);
//
//	//glcd_cmd(0xB8);
//
//	//glcd_cmd(0x40);
//
//	glcd_cmd(0x3F);
//
//	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x08);
//	//glcd_cmd(0xC0);
//
//	//glcd_cmd(0xB8);
//
//	//glcd_cmd(0x40);
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
//			glcd_data(0xFF);
//		}
//	}
//}
//
///*void glcd_displayimage(unsigned char a[]){
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
//}*/
//
//void glcd_displayimage(unsigned char a[]){
//	int j=0;
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
//int main(void)
//{
//	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
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
//
//	while(1){
//
//	}
//
//}
