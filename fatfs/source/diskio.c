/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "../../fatfstest.h" // SECCOUNT

/* Definitions of physical drive number for each drive */
#define DEV_RAM		0	/* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB		2	/* Example: Map USB MSD to physical drive 2 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	int result;


	return 0;
}




/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/
int fno=-1;

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
  printf("disk_initialize\n");
  if (fno == -1)
    fno = open("abc.dat", O_SYNC|O_RDWR, S_IRUSR|S_IWUSR);
  lseek(fno, 0, SEEK_SET);
  return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res;
	int result;

	printf("disk_read %d %ld %d\n", fno, sector, count);
	lseek(fno, sector*512, SEEK_SET);
	read(fno, buff, 512*count);

	return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res;
	int result;
	printf("disk_write %d %ld %d\n", fno, sector, count);	
	lseek(fno, sector*512, SEEK_SET);
	write(fno, buff, 512*count);
	return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
	int result;

	printf("disk_ioctl %d %d\n", pdrv, cmd);
	if (cmd == 3) { // sector size
	  *((WORD*)buff) = 512;
	  return RES_OK;
	}
	if (cmd == 1) { // total count
	  *((DWORD*)buff) = SECCOUNT;
	  return RES_OK;	  
	}
	if (cmd == CTRL_SYNC) {
	  return RES_OK;	  
	}
	return RES_PARERR;
}


DWORD get_fattime() { return 0; };

void disk_flush() {
}
