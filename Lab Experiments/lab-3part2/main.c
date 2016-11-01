#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

int sw1value=1;
int sw2value=1;
int sw1presscount=0;
int sw2presscount=0;
int count1=0;
int count=0;
uint32_t ui32Period;
volatile uint32_t ui32Load;
volatile uint32_t ui32PWMClock;
	volatile uint8_t ui8Adjust = 83;


#define PWM_FREQUENCY 55
int main(void)
{


	ROM_SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	ROM_GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
	ROM_GPIOPinConfigure(GPIO_PD0_M1PWM0);
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
	ROM_GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
	ROM_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	ui32PWMClock = SysCtlClockGet() / 64;
	ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
	PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);
	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
	ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_0);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);


	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);

		ui32Period = (SysCtlClockGet() / 10) / 2;
		TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period -1);

		IntEnable(INT_TIMER0A);
		TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
		IntMasterEnable();

		TimerEnable(TIMER0_BASE, TIMER_A);
 /*while(1)
 {
	if(ROM_GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)==0x00)
	{
		ui8Adjust--;
		if (ui8Adjust < 56)
		{
			ui8Adjust = 56;
		}
		ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
	}
	if(ROM_GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==0x00)
	{
		ui8Adjust++;
		if (ui8Adjust > 111)
		{
				ui8Adjust = 111;
		}
		ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
	}
	ROM_SysCtlDelay(100000);
 }*/
}

void Timer0IntHandler(void)
{
	// Clear the timer interrupt

	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

	sw1value=ROM_GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
	if(sw1value==0){
		count1++;
		if(count1==2){
			sw1presscount++;
		}
	}
	else{

			count1=0;

	}

	    if(sw1value==0){
				count1++;
				if(count1==2){
					sw1presscount++;
								ui8Adjust--;
								if (ui8Adjust < 56)
								{
									ui8Adjust = 56;
								}
								ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
				}
			}
			else{
					count1=0;
			}

		sw2value=ROM_GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0);
		if(sw2value==0x00){
			count++;
						if(count==2){
							sw2presscount++;
										ui8Adjust++;
										if (ui8Adjust > 111)
										{
												ui8Adjust = 111;
										}
										ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
						}
		}
		else{
				count=0;
		}



}


	/*value=GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0);
	if(value==0){
         count++;
		if(count==2){
			if(ui8PinData==8){
				ui8PinData=2;
			}
			else
			{
				ui8PinData=ui8PinData*2;
			}
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8PinData);
		 count=0;
		}
	}
	else{
		if(count==1){
			count=0;
		}
	}*/



