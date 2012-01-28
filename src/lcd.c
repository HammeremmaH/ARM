#include "lcd.h"
#include "stdlib.h"

void LCD_InitGPIO()
{
	LCD_InitControlGPIO();
	LCD_InitDataInGPIO();
}

void LCD_InitControlGPIO()
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = LCD_RS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_RS_GPIO, &GPIO_InitStructure);
	LCD_RS_GPIO->BRR |= LCD_RS_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_RW_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_RW_GPIO, &GPIO_InitStructure);
	LCD_RW_GPIO->BRR |= LCD_RW_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_E_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_E_GPIO, &GPIO_InitStructure);
	LCD_E_GPIO->BRR |= LCD_E_PIN;
}

void LCD_InitDataOutGPIO()
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = LCD_DB0_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB0_GPIO, &GPIO_InitStructure);
	LCD_DB0_GPIO->BRR |= LCD_DB0_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB1_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB1_GPIO, &GPIO_InitStructure);
	LCD_DB1_GPIO->BRR |= LCD_DB1_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB2_GPIO, &GPIO_InitStructure);
	LCD_DB2_GPIO->BRR |= LCD_DB2_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB3_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB3_GPIO, &GPIO_InitStructure);
	LCD_DB3_GPIO->BRR |= LCD_DB3_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB4_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB4_GPIO, &GPIO_InitStructure);
	LCD_DB4_GPIO->BRR |= LCD_DB4_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB5_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB5_GPIO, &GPIO_InitStructure);
	LCD_DB5_GPIO->BRR |= LCD_DB5_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB6_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB6_GPIO, &GPIO_InitStructure);
	LCD_DB6_GPIO->BRR |= LCD_DB6_PIN;

	GPIO_InitStructure.GPIO_Pin = LCD_DB7_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB7_GPIO, &GPIO_InitStructure);
	LCD_DB7_GPIO->BRR |= LCD_DB7_PIN;
}

void LCD_InitDataInGPIO()
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = LCD_DB0_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB0_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB1_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB1_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB2_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB3_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB3_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB4_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB4_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB5_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB5_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB6_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB6_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LCD_DB7_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_DB7_GPIO, &GPIO_InitStructure);
}

void LCD_WriteData(uint8_t data)
{
	LCD_InitDataOutGPIO();

	if (data & (1<<7))
		LCD_DB7_GPIO->BSRR |= LCD_DB7_PIN;
	if (data & (1<<6))
		LCD_DB6_GPIO->BSRR |= LCD_DB6_PIN;
	if (data & (1<<5))
		LCD_DB5_GPIO->BSRR |= LCD_DB5_PIN;
	if (data & (1<<4))
		LCD_DB4_GPIO->BSRR |= LCD_DB4_PIN;
	if (data & (1<<3))
		LCD_DB3_GPIO->BSRR |= LCD_DB3_PIN;
	if (data & (1<<2))
		LCD_DB2_GPIO->BSRR |= LCD_DB2_PIN;
	if (data & (1<<1))
		LCD_DB1_GPIO->BSRR |= LCD_DB1_PIN;
	if (data & (1<<0))
		LCD_DB0_GPIO->BSRR |= LCD_DB0_PIN;
}

uint8_t LCD_ReadData()
{
	LCD_InitDataInGPIO();
	
	uint8_t data = 0;
		
	if (LCD_DB7_GPIO->IDR & LCD_DB7_PIN)
		data |= 1<<7;
	if (LCD_DB6_GPIO->IDR & LCD_DB6_PIN)
		data |= 1<<6;
	if (LCD_DB5_GPIO->IDR & LCD_DB5_PIN)
		data |= 1<<5;
	if (LCD_DB4_GPIO->IDR & LCD_DB4_PIN)
		data |= 1<<4;
	if (LCD_DB3_GPIO->IDR & LCD_DB3_PIN)
		data |= 1<<3;
	if (LCD_DB2_GPIO->IDR & LCD_DB2_PIN)
		data |= 1<<2;
	if (LCD_DB1_GPIO->IDR & LCD_DB1_PIN)
		data |= 1<<1;	
	if (LCD_DB0_GPIO->IDR & LCD_DB0_PIN)
		data |= 1<<0;	
			
	return data;
}

void LCD_SendCommand(uint8_t command)
{
	LCD_WaitBusyFlag();
	
	LCD_RS_GPIO->BRR |= LCD_RS_PIN;
	LCD_RW_GPIO->BRR |= LCD_RW_PIN;
	LCD_E_GPIO->BSRR |= LCD_E_PIN;

	LCD_WriteData(command);

	SysTick_DelayUs(1);

	LCD_E_GPIO->BRR |= LCD_E_PIN;

	LCD_InitDataInGPIO();
}

void LCD_SendData(uint8_t data)
{
	LCD_WaitBusyFlag();
	
	LCD_RS_GPIO->BSRR |= LCD_RS_PIN;
	LCD_RW_GPIO->BRR |= LCD_RW_PIN;
	LCD_E_GPIO->BSRR |= LCD_E_PIN;

	LCD_WriteData(data);

	SysTick_DelayUs(1);

	LCD_E_GPIO->BRR |= LCD_E_PIN;

	LCD_InitDataInGPIO();
}

uint8_t LCD_ReceiveBusyFlagAndAddress()
{
	uint8_t busyFlagAndAddress;
	
	LCD_RS_GPIO->BRR |= LCD_RS_PIN;
	LCD_RW_GPIO->BSRR |= LCD_RW_PIN;
	LCD_E_GPIO->BSRR |= LCD_E_PIN;

	busyFlagAndAddress = LCD_ReadData();

	SysTick_DelayUs(1);

	LCD_E_GPIO->BRR |= LCD_E_PIN;

	return busyFlagAndAddress;
}

uint8_t LCD_ReceiveData()
{
	LCD_WaitBusyFlag();
	
	uint8_t data;
	
	LCD_RS_GPIO->BSRR |= LCD_RS_PIN;
	LCD_RW_GPIO->BSRR |= LCD_RW_PIN;
	LCD_E_GPIO->BSRR |= LCD_E_PIN;

	data = LCD_ReadData();

	SysTick_DelayUs(1);
	
	LCD_E_GPIO->BRR |= LCD_E_PIN;

	return data;
}

void LCD_WaitBusyFlag()
{
	if (LCD_initComplete)
	{
		while (LCD_ReceiveBusyFlagAndAddress() & LCD_RBFAA_BUSY_FLAG_MASK);
	}
}

void LCD_Clear()
{
	LCD_SendCommand(0b00000001);
}

void LCD_ReturnHome()
{
	LCD_SendCommand(0b00000010);
}

void LCD_EntryModeSet(uint8_t cursor, uint8_t display)
{
	LCD_SendCommand(0b00000100 | ((cursor & 1)<<1) | ((display & 1)<<0));
}

void LCD_DisplayOnOffControl(uint8_t display, uint8_t cursor, uint8_t blinking)
{
	LCD_SendCommand(0b00001000 | ((display & 1)<<2) | ((cursor & 1)<<1) | ((blinking & 1)<<0));
}

void LCD_CursorOrDisplayShift(uint8_t target, uint8_t direction)
{
	LCD_SendCommand(0b00010000 | ((target & 1)<<3) | ((direction & 1)<<2));
}

void LCD_FunctionSet(uint8_t dataLength, uint8_t numberOfLines, uint8_t fontType)
{
	LCD_SendCommand(0b00100000 | ((dataLength & 1)<<4) | ((numberOfLines & 1)<<3) | ((fontType & 1)<<2));
}

void LCD_SetCgramAddress(uint8_t address)
{
	LCD_SendCommand(0b01000000 | (address & 0b00111111));
}

void LCD_SetDdramAddress(uint8_t address)
{
	LCD_SendCommand(0b10000000 | (address & 0b01111111));
}

void LCD_Init()
{
	LCD_initComplete = 0;

	LCD_InitCodePage();

	LCD_InitGPIO();

	SysTick_DelayMs(40);
	LCD_FunctionSet(LCD_FS_DATALENGTH_8BIT, LCD_FS_NUMBEROFLINES_2, LCD_FS_FONTTYPE_5X8);
	SysTick_DelayUs(39);
	LCD_FunctionSet(LCD_FS_DATALENGTH_8BIT, LCD_FS_NUMBEROFLINES_2, LCD_FS_FONTTYPE_5X8);

	LCD_initComplete = 1;

	LCD_DisplayOnOffControl(LCD_DOOC_DISPLAY_ON, LCD_DOOC_CURSOR_OFF, LCD_DOOC_BLINKING_OFF);
	LCD_Clear();
	LCD_EntryModeSet(LCD_EMS_CURSOR_INCREMENT, LCD_EMS_DISPLAY_SHIFT_DISABLE);
}

void LCD_PrintString(char *string)
{
	while (*string != 0)
	{
		LCD_SendData(LCD_GetCodeFromAscii(*string));
		string++;
	}
}

void LCD_SetCursor(uint8_t line, uint8_t position)
{
	LCD_SetDdramAddress((line % 2 + position / 0x40) * 0x40 + (position % 0x40));
}

void LCD_CursorLeft()
{
	LCD_CursorOrDisplayShift(LCD_CODS_TARGET_CURSOR, LCD_CODS_DIRECTION_LEFT);
}

void LCD_CursorRight()
{
	LCD_CursorOrDisplayShift(LCD_CODS_TARGET_CURSOR, LCD_CODS_DIRECTION_RIGHT);
}

void LCD_DisplayLeft()
{
	LCD_CursorOrDisplayShift(LCD_CODS_TARGET_DISPLAY, LCD_CODS_DIRECTION_LEFT);
}

void LCD_DisplayRight()
{
	LCD_CursorOrDisplayShift(LCD_CODS_TARGET_DISPLAY, LCD_CODS_DIRECTION_RIGHT);
}


void LCD_InitCodePage()
{
	LCD_codePage[0x00] = 0x00;
	LCD_codePage[0x01] = 0x01;
	LCD_codePage[0x02] = 0x02;
	LCD_codePage[0x03] = 0x03;
	LCD_codePage[0x04] = 0x04;
	LCD_codePage[0x05] = 0x05;
	LCD_codePage[0x06] = 0x06;
	LCD_codePage[0x07] = 0x07;
	LCD_codePage[0x08] = 0x08;
	LCD_codePage[0x09] = 0x09;
	LCD_codePage[0x0A] = 0x0A;
	LCD_codePage[0x0B] = 0x0B;
	LCD_codePage[0x0C] = 0x0C;
	LCD_codePage[0x0D] = 0x0D;
	LCD_codePage[0x0E] = 0x0E;
	LCD_codePage[0x0F] = 0x0F;

	LCD_codePage[' '] = 0x20;
	LCD_codePage['!'] = 0x21;
	LCD_codePage['"'] = 0x22;
	LCD_codePage['#'] = 0x23;
	LCD_codePage['$'] = 0x24;
	LCD_codePage['%'] = 0x25;
	LCD_codePage['&'] = 0x26;
	LCD_codePage['\''] = 0x27;
	LCD_codePage['('] = 0x28;
	LCD_codePage[')'] = 0x29;
	LCD_codePage['*'] = 0x2A;
	LCD_codePage['+'] = 0x2B;
	LCD_codePage[','] = 0x2C;
	LCD_codePage['-'] = 0x2D;
	LCD_codePage['.'] = 0x2E;
	LCD_codePage['/'] = 0x2F;
	LCD_codePage[':'] = 0x3A;
	LCD_codePage[';'] = 0x3B;
	LCD_codePage['<'] = 0x3C;
	LCD_codePage['='] = 0x3D;
	LCD_codePage['>'] = 0x3E;
	LCD_codePage['?'] = 0x3F;
	LCD_codePage['@'] = 0x40;
	LCD_codePage['['] = 0x5B;
	LCD_codePage[']'] = 0x5D;
	LCD_codePage['^'] = 0x5E;
	LCD_codePage['_'] = 0x5F;
	LCD_codePage['`'] = 0x60;
	LCD_codePage['¹'] = 0xCC;
	LCD_codePage['~'] = 0xE9;

	LCD_codePage['0'] = 0x30;
	LCD_codePage['1'] = 0x31;
	LCD_codePage['2'] = 0x32;
	LCD_codePage['3'] = 0x33;
	LCD_codePage['4'] = 0x34;
	LCD_codePage['5'] = 0x35;
	LCD_codePage['6'] = 0x36;
	LCD_codePage['7'] = 0x37;
	LCD_codePage['8'] = 0x38;
	LCD_codePage['9'] = 0x39;

	LCD_codePage['A'] = 0x41;
	LCD_codePage['B'] = 0x42;
	LCD_codePage['C'] = 0x43;
	LCD_codePage['D'] = 0x44;
	LCD_codePage['E'] = 0x45;
	LCD_codePage['F'] = 0x46;
	LCD_codePage['G'] = 0x47;
	LCD_codePage['H'] = 0x48;
	LCD_codePage['I'] = 0x49;
	LCD_codePage['J'] = 0x4A;
	LCD_codePage['K'] = 0x4B;
	LCD_codePage['L'] = 0x4C;
	LCD_codePage['M'] = 0x4D;
	LCD_codePage['N'] = 0x4E;
	LCD_codePage['O'] = 0x4F;
	LCD_codePage['P'] = 0x50;
	LCD_codePage['Q'] = 0x51;
	LCD_codePage['R'] = 0x52;
	LCD_codePage['S'] = 0x53;
	LCD_codePage['T'] = 0x54;
	LCD_codePage['U'] = 0x55;
	LCD_codePage['V'] = 0x56;
	LCD_codePage['W'] = 0x57;
	LCD_codePage['X'] = 0x58;
	LCD_codePage['Y'] = 0x59;
	LCD_codePage['Z'] = 0x5A;


	LCD_codePage['a'] = 0x61;
	LCD_codePage['b'] = 0x62;
	LCD_codePage['c'] = 0x63;
	LCD_codePage['d'] = 0x64;
	LCD_codePage['e'] = 0x65;
	LCD_codePage['f'] = 0x66;
	LCD_codePage['g'] = 0x67;
	LCD_codePage['h'] = 0x68;
	LCD_codePage['i'] = 0x69;
	LCD_codePage['j'] = 0x6A;
	LCD_codePage['k'] = 0x6B;
	LCD_codePage['l'] = 0x6C;
	LCD_codePage['m'] = 0x6D;
	LCD_codePage['n'] = 0x6E;
	LCD_codePage['o'] = 0x6F;
	LCD_codePage['p'] = 0x70;
	LCD_codePage['q'] = 0x71;
	LCD_codePage['r'] = 0x72;
	LCD_codePage['s'] = 0x73;
	LCD_codePage['t'] = 0x74;
	LCD_codePage['u'] = 0x75;
	LCD_codePage['v'] = 0x76;
	LCD_codePage['w'] = 0x77;
	LCD_codePage['x'] = 0x78;
	LCD_codePage['y'] = 0x79;
	LCD_codePage['z'] = 0x7A;

	LCD_codePage['À'] = 0x41;
	LCD_codePage['Á'] = 0xA0;
	LCD_codePage['Â'] = 0x42;
	LCD_codePage['Ã'] = 0xA1;
	LCD_codePage['Ä'] = 0xE0;
	LCD_codePage['Å'] = 0x45;
	LCD_codePage['¨'] = 0xA2;
	LCD_codePage['Æ'] = 0xA3;
	LCD_codePage['Ç'] = 0xA4;
	LCD_codePage['È'] = 0xA5;
	LCD_codePage['É'] = 0xA6;
	LCD_codePage['Ê'] = 0x4B;
	LCD_codePage['Ë'] = 0xA7;
	LCD_codePage['Ì'] = 0x4D;
	LCD_codePage['Í'] = 0x48;
	LCD_codePage['Î'] = 0x4F;
	LCD_codePage['Ï'] = 0xA8;
	LCD_codePage['Ð'] = 0x50;
	LCD_codePage['Ñ'] = 0x43;
	LCD_codePage['Ò'] = 0x54;
	LCD_codePage['Ó'] = 0xA9;
	LCD_codePage['Ô'] = 0xAA;
	LCD_codePage['Õ'] = 0x58;
	LCD_codePage['Ö'] = 0xE1;
	LCD_codePage['×'] = 0xAB;
	LCD_codePage['Ø'] = 0xAC;
	LCD_codePage['Ù'] = 0xE2;
	LCD_codePage['Ú'] = 0xAD;
	LCD_codePage['Û'] = 0xAE;
	LCD_codePage['Ý'] = 0xAF;
	LCD_codePage['Þ'] = 0xB0;
	LCD_codePage['ß'] = 0xB1;

	LCD_codePage['à'] = 0x61;
	LCD_codePage['á'] = 0xB2;
	LCD_codePage['â'] = 0xB3;
	LCD_codePage['ã'] = 0xB4;
	LCD_codePage['ä'] = 0xE3;
	LCD_codePage['å'] = 0x65;
	LCD_codePage['¸'] = 0xB5;
	LCD_codePage['æ'] = 0xB6;
	LCD_codePage['ç'] = 0xB7;
	LCD_codePage['è'] = 0xB8;
	LCD_codePage['é'] = 0xB9;
	LCD_codePage['ê'] = 0xBA;
	LCD_codePage['ë'] = 0xBB;
	LCD_codePage['ì'] = 0xBC;
	LCD_codePage['í'] = 0xBD;
	LCD_codePage['î'] = 0x6F;
	LCD_codePage['ï'] = 0xBE;
	LCD_codePage['ð'] = 0x70;
	LCD_codePage['ñ'] = 0x63;
	LCD_codePage['ò'] = 0xBF;
	LCD_codePage['ó'] = 0x79;
	LCD_codePage['ô'] = 0xE4;
	LCD_codePage['õ'] = 0x78;
	LCD_codePage['ö'] = 0xE5;
	LCD_codePage['÷'] = 0xC0;
	LCD_codePage['ø'] = 0xC1;
	LCD_codePage['ù'] = 0xE6;
	LCD_codePage['ú'] = 0xC2;
	LCD_codePage['û'] = 0xC3;
	LCD_codePage['ü'] = 0xC4;
	LCD_codePage['ý'] = 0xC5;
	LCD_codePage['þ'] = 0xC6;
	LCD_codePage['ÿ'] = 0xC7;
}

uint8_t LCD_GetCodeFromAscii(uint8_t ascii)
{
	return LCD_codePage[ascii];
}
