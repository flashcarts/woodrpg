// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2023
// SPDX-FileContributor: lifehackerhansol, 2023

#include <nds/ndstypes.h>

#include "ioa3p.h"
#include "libtwl_card.h"

// Initialize the driver. Returns true on success.
bool startup(void)
{
	return true;
}

// Returns true if a card is present and initialized.
bool is_inserted(void)
{
	return true;
}

// Reads 512 byte sectors into a buffer that may be unaligned. Returns true on
// success.
bool read_sectors(uint32_t sector, uint32_t num_sectors, void *buffer)
{
  int i;
	for (i = 0; i < num_sectors; i++)
	{
		ioA3PSDReadSector((sector + i), buffer);
		buffer = (u8 *)buffer + 0x200;
	}
	return true;
}

// Writes 512 byte sectors from a buffer that may be unaligned. Returns true on
// success.
bool write_sectors(uint32_t sector, uint32_t num_sectors, const void *buffer)
{
  int i;
	for (i = 0; i < num_sectors; i++)
	{
		ioA3PSDWriteSector((sector + i), buffer);
		buffer = (u8 *)buffer + 0x200;
	}
	return true;
}

// Clear error flags from the card. Returns true on success.
bool clear_status(void)
{
	return true;
}

// Shutdowns the card. This may never be called.
bool shutdown(void)
{
	return true;
}

/*
void ioR4CryptedRead(u32 address,u32* destination,u32 length)
{
  u8 command[8];

  command[7] = 0xb6;
  command[6] = (address >> 24) & 0xff;
  command[5] = (address >> 16) & 0xff;
  command[4] = (address >> 8)  & 0xff;
  command[3] =  address        & 0xff;
  command[2] = 0;
  command[1] = 0;
  command[0] = 0;
  ioR4CardWaitReady(0xa7586000, command);
  command[7] = 0xbf;
  cardPolledTransfer(0xa1586000, destination, length, command);
}

void ioR4SendMap(u32 address)
{
  u8 command[8];

  command[7] = 0xb4;
  command[6] = (address >> 24) & 0xff;
  command[5] = (address >> 16) & 0xff;
  command[4] = (address >> 8)  & 0xff;
  command[3] =  address        & 0xff;
  command[2] = 0;
  command[1] = 0;
  command[0] = 0;

  ioR4CardWaitReady(0xa7586000,command);
}
*/

// Ace3DS+ uses sector addressing unconditionally
u32 isSDHC(void)
{
  return 1;
}

u32 ioVersion(void)
{
  return 0;
}

u32 ioSize(void)
{
  return 1;
}

int ioSD(void)
{
  return 0;
}
