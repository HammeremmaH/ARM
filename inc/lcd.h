#ifndef LCD_H
#define LCD_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "systick.h"

#define LCD_RS_GPIO GPIOA
#define LCD_RS_PIN GPIO_Pin_12

#define LCD_RW_GPIO GPIOB
#define LCD_RW_PIN GPIO_Pin_5

#define LCD_E_GPIO GPIOA
#define LCD_E_PIN GPIO_Pin_13

#define LCD_DB0_GPIO GPIOB
#define LCD_DB0_PIN GPIO_Pin_4

#define LCD_DB1_GPIO GPIOA
#define LCD_DB1_PIN GPIO_Pin_14

#define LCD_DB2_GPIO GPIOB
#define LCD_DB2_PIN GPIO_Pin_3

#define LCD_DB3_GPIO GPIOA
#define LCD_DB3_PIN GPIO_Pin_15

#define LCD_DB4_GPIO GPIOD
#define LCD_DB4_PIN GPIO_Pin_2

#define LCD_DB5_GPIO GPIOC
#define LCD_DB5_PIN GPIO_Pin_10

#define LCD_DB6_GPIO GPIOC
#define LCD_DB6_PIN GPIO_Pin_12

#define LCD_DB7_GPIO GPIOC
#define LCD_DB7_PIN GPIO_Pin_11

#define LCD_RBFAA_BUSY_FLAG_MASK (1<<7)
#define LCD_RBFAA_ADDRESS_MASK (~(1<<7))

#define LCD_EMS_CURSOR_DECREMENT 0
#define LCD_EMS_CURSOR_INCREMENT 1
#define LCD_EMS_DISPLAY_SHIFT_DISABLE 0
#define LCD_EMS_DISPLAY_SHIFT_ENABLE 1

#define LCD_DOOC_DISPLAY_OFF 0
#define LCD_DOOC_DISPLAY_ON 1
#define LCD_DOOC_CURSOR_OFF 0
#define LCD_DOOC_CURSOR_ON 1
#define LCD_DOOC_BLINKING_OFF 0
#define LCD_DOOC_BLINKING_ON 1

#define LCD_CODS_TARGET_CURSOR 0
#define LCD_CODS_TARGET_DISPLAY 1
#define LCD_CODS_DIRECTION_LEFT 0
#define LCD_CODS_DIRECTION_RIGHT 1

#define LCD_FS_DATALENGTH_4BIT 0
#define LCD_FS_DATALENGTH_8BIT 1
#define LCD_FS_NUMBEROFLINES_1 0
#define LCD_FS_NUMBEROFLINES_2 1
#define LCD_FS_FONTTYPE_5X8 0
#define LCD_FS_FONTTYPE_5X11 1

uint8_t LCD_initComplete;
uint8_t LCD_codePage[256];

void LCD_InitGPIO();
void LCD_InitControlGPIO();
void LCD_InitDataOutGPIO();
void LCD_InitDataInGPIO();

void LCD_WriteData(uint8_t data);
uint8_t LCD_ReadData();

void LCD_SendCommand(uint8_t command);
void LCD_SendData(uint8_t data);
uint8_t LCD_ReceiveBusyFlagAndAddress();
uint8_t LCD_ReceiveData();

void LCD_WaitBusyFlag();

void LCD_Clear();
void LCD_ReturnHome();
void LCD_EntryModeSet(uint8_t cursor, uint8_t display);
void LCD_DisplayOnOffControl(uint8_t display, uint8_t cursor, uint8_t blinking);
void LCD_CursorOrDisplayShift(uint8_t target, uint8_t direction);
void LCD_FunctionSet(uint8_t dataLength, uint8_t numberOfLines, uint8_t fontType);
void LCD_SetCgramAddress(uint8_t address);
void LCD_SetDdramAddress(uint8_t address);

void LCD_Init();

void LCD_PrintString(char *string);
void LCD_SetCursor(uint8_t line, uint8_t position);
void LCD_CursorLeft();
void LCD_CursorRight();
void LCD_DisplayLeft();
void LCD_DisplayRight();

void LCD_InitCodePage();
uint8_t LCD_GetCodeFromAscii(uint8_t ascii);

#endif
