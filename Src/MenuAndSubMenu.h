/*
 * Struct&Fun.h
 *
 *  Created on: 30.11.2017
 *      Author:
 */

#ifndef MENUANDSUBMENU_H_
#define MENUANDSUBMENU_H_
#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "hd44780.h"
#include "pcf8574.h"

extern volatile uint16_t pulse_count; // Licznik impulsow TRZEBA PODPI�� D8 (A) i D7  volatile uint16_t pulse_count; // Licznik impulsow TRZEBA PODPI�� D8 (A) i D7 (B)volatile uint16_t pulse_count; // Licznik impulsow TRZEBA PODPI�� D8 (A) i D7 (B)
extern volatile uint16_t positions; //licznik enkodera
extern bool isPressed; //czy guzik wcisniety

//------------------------Menu--------------------------------------

struct menu {
   void (*zaprogram)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*zamknij)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*tryb)(LCD_PCF8574_HandleTypeDef* lcd);
 };
typedef struct menu menu;

menu stworz (void);

//---------------------SubMenu1------------------------------------------------------

struct submenu1 {
   void (*manual)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*automat)(LCD_PCF8574_HandleTypeDef* lcd);
 };
typedef struct submenu1 submenu1;

submenu1 stworzSubMenu1 (void);

#endif /* MENUANDSUBMENU_H_ */
