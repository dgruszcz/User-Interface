/*
 * Struct&Fun.c
 *
 *  Created on:
 *      Author:
 */

#include <stdbool.h>

#include "MenuAndSubMenu.h"

//------------------------Menu--------------------------------------

void moje_urzadzenie_tryb_pracy (LCD_PCF8574_HandleTypeDef* lcd)
{
	 LCD_SetLocation(lcd, 0, 1);
	 LCD_WriteString(lcd, "2. Mode     ");


	if (isPressed)
	{
		submenu1 trybPracy = stworzSubMenu1();
		isPressed = 0;
		TIM1->CNT=8;
		while(1)
		{
			pulse_count = TIM1->CNT; // przepisanie wartosci z rejestru timera
			positions = pulse_count/4; // zeskalowanie impulsow do liczby stabilnych pozycji walu enkodera

			switch( positions % 3)
			{
				case 2 :
					trybPracy.manual(lcd);
					break;
				case 1 :
					trybPracy.automat(lcd);
					break;
				case 0 :
					LCD_SetLocation(lcd, 0, 1);
					LCD_WriteString(lcd, "3. Exit     ");
					if(isPressed == 1){
						isPressed = 0;
						TIM1->CNT=8;
						return;
					}
					break;
			}
			isPressed = 0;
		}
	}
}
 void moje_urzadzenie_zaprogram(LCD_PCF8574_HandleTypeDef* lcd)
 {
	 LCD_SetLocation(lcd, 0, 1);
	 LCD_WriteString(lcd, "1. Program  ");

	 /* sth to do */

 }

 void moje_urzadzenie_zamknij (LCD_PCF8574_HandleTypeDef* lcd)
 {
	 LCD_SetLocation(lcd, 0, 1);
	 LCD_WriteString(lcd, "4. Exit    ");

	 /* sth to do */
 }

 menu stworz (void)
 {
   menu moje_menu;
   moje_menu.zaprogram = moje_urzadzenie_zaprogram;
   moje_menu.zamknij = moje_urzadzenie_zamknij;
   moje_menu.tryb = moje_urzadzenie_tryb_pracy;
   return moje_menu;
 }

 //---------------------SubMenu1------------------------------------------------------

 void tryb_manual (LCD_PCF8574_HandleTypeDef* lcd)
  {
 	 LCD_SetLocation(lcd, 0, 1);
 	 LCD_WriteString(lcd, "1. Manual  ");
 	 if (isPressed)
 	 {
 		 /* sth to do */
 	 }
  }

  void tryb_automat (LCD_PCF8574_HandleTypeDef* lcd)
  {
 	 LCD_SetLocation(lcd, 0, 1);
 	 LCD_WriteString(lcd, "2. Automat  ");
 	if (isPressed){

 	 	/* sth to do */

 	}
  }

  submenu1 stworzSubMenu1 (void)
  {
    submenu1 moje_submenu1;
    moje_submenu1.manual = tryb_manual;
    moje_submenu1.automat = tryb_automat;
    return moje_submenu1;
  }

