/* Author: Vo Son Tung HUST */
#include "ST47_FLASH.h"

/*1.Lay sector flash */
//void fnFlash_GetAddress(uint32_t address)
//{
//	uint32_t sector = 0;
//	if((address >= ADDR_FLASH_SECTOR_0) && (address <= ADDR_FLASH_SECTOR_1))				sector = FLASH_SECTOR_0;
//	else if((address >= ADDR_FLASH_SECTOR_1) && (address <= ADDR_FLASH_SECTOR_2))		sector = FLASH_SECTOR_1;
//	else if((address >= ADDR_FLASH_SECTOR_2) && (address <= ADDR_FLASH_SECTOR_3))		sector = FLASH_SECTOR_2;
//	else if((address >= ADDR_FLASH_SECTOR_3) && (address <= ADDR_FLASH_SECTOR_4))		sector = FLASH_SECTOR_3;
//	else if((address >= ADDR_FLASH_SECTOR_4) && (address <= ADDR_FLASH_SECTOR_5))		sector = FLASH_SECTOR_4;
//	else if((address >= ADDR_FLASH_SECTOR_5) && (address <= ADDR_FLASH_SECTOR_6))		sector = FLASH_SECTOR_5;
//	else if((address >= ADDR_FLASH_SECTOR_6) && (address <= ADDR_FLASH_SECTOR_7))		sector = FLASH_SECTOR_6;	
//	else if((address >= ADDR_FLASH_SECTOR_7) && (address <= (uint32_t)0x0807FFFF))	sector = FLASH_SECTOR_7;
//}
/*1.Xoa sector flash */
void fnFlash_Erase(uint8_t sector)
{
	HAL_FLASH_Unlock();															// Unlock Flash first
	FLASH_Erase_Sector(sector,VOLTAGE_RANGE_3);			// Xoa theo sector
	HAL_FLASH_Lock();																// Lock Flash
}

/*2.Ghi flash*/
void fnFlash_Write(void *BufferW,uint32_t addr, uint8_t BufferSize, DataTypedef Datatype)
{
	uint32_t vrMyAddress = addr;
	HAL_FLASH_Unlock();		
	switch(Datatype)
	{
		case DATA_BYTE_8:
			for(uint8_t i=0;i<BufferSize;i++)
			{
				HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,vrMyAddress,((uint8_t *)BufferW)[i]);
				vrMyAddress ++;
			}
			break;
		case DATA_BYTE_16:
			for(uint16_t i=0;i<BufferSize;i++)
			{
				HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,vrMyAddress,((uint16_t *)BufferW)[i]);
				vrMyAddress += 2;
			}
			break;
		case DATA_BYTE_32:
			for(int i=0;i<BufferSize;i++)
			{
				HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,vrMyAddress,((uint32_t *)BufferW)[i]);
				vrMyAddress += 4;
			}
			break;
	}
	HAL_FLASH_Lock();
}

void fnFlash_Read(void *BufferR, uint32_t start_addr, uint32_t end_addr, DataTypedef DataType)
{
	uint32_t vrMyAddress = start_addr;
	switch(DataType)
	{
		case DATA_BYTE_8:
			for(int i=0;i<(end_addr - start_addr + 1);i++)
			{
				((uint8_t*)BufferR)[i] = *((uint8_t*)vrMyAddress);
				vrMyAddress++;
			}
			break;
		case DATA_BYTE_16:
			for(uint16_t i=0;i<(end_addr-start_addr+1);i++)
			{
				((uint16_t*)BufferR)[i] = *((uint16_t*)vrMyAddress);
				vrMyAddress += 2;
			}
			break;
		case DATA_BYTE_32:
			for(uint32_t i=0;i<(end_addr-start_addr+1);i++)
			{
				((uint32_t*)BufferR)[i] = *((uint32_t*)vrMyAddress);
				vrMyAddress += 4;
			}
			break;
		}
}