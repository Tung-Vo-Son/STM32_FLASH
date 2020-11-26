#include "stm32f4xx_hal.h"
/* Author: Vo Son Tung HUST */

/* Define Sector */
#define ADDR_FLASH_SECTOR_0 (uint32_t)0x08000000			//Sector 0 - 16Kbyte
#define ADDR_FLASH_SECTOR_1 (uint32_t)0x08004000			//Sector 1 - 16Kbyte
#define ADDR_FLASH_SECTOR_2 (uint32_t)0x08008000 			//Sector 2 - 16Kbyte
#define ADDR_FLASH_SECTOR_3 (uint32_t)0x0800C000 			//Sector 3 - 16Kbyte
#define ADDR_FLASH_SECTOR_4 (uint32_t)0x08010000 			//Sector 4 - 64Kbyte
#define ADDR_FLASH_SECTOR_5 (uint32_t)0x08020000 			//Sector 5 - 128Kbyte
#define ADDR_FLASH_SECTOR_6 (uint32_t)0x08040000 			//Sector 6 - 128Kbyte
#define ADDR_FLASH_SECTOR_7 (uint32_t)0x08060000 			//Sector 7 - 128Kbyte

typedef enum
{
	DATA_BYTE_8,
	DATA_BYTE_16,
	DATA_BYTE_32,
}DataTypedef;

//void fnFlash_GetAddress(uint32_t address);
void fnFlash_Erase(uint8_t sector);
void fnFlash_Write(void *BufferW, uint32_t addr, uint8_t BufferSize, DataTypedef DataType);
void fnFlash_Read(void *BufferR, uint32_t start_addr, uint32_t end_addr, DataTypedef DataType);

