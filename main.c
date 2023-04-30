/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: User
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"

void INT0_ISR(void);

void main(){

    PORT_voidInit();

    EXTI_voidINT0Init();

    GIE_voidEnable();

/*   EXTI_u8INT0SetCallback(INT0_ISR);
 *
 *   MISRA Rule : put & before pointer to function */

    EXTI_u8INT0SetCallback(&INT0_ISR);

	while(1){

	}
}




void INT0_ISR(void){
	DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN0,DIO_U8PIN_HIGH);
}
