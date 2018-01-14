#ifndef FATFSTEST_H
#define FATFSTEST_H 1
#include "ff.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define FCHK(a)   { FRESULT res = a; printf("call %s res %d %s\n", #a, res, fatfs_error_to_string(res)); };

static const char *fatfs_error_to_string(FRESULT err)
{
  switch (err) {
  case FR_OK: return "Succeeded";
  case FR_DISK_ERR: return "FATFS: A hard error occurred in the low level disk I/O layer";
  case FR_INT_ERR: return "FATFS: Assertion failed (check for corruption)";
  case FR_NOT_READY: return "FATFS: The physical drive cannot work";
  case FR_NO_FILE: return "FATFS: Could not find the file";
  case FR_NO_PATH: return "FATFS: Could not find the path";
  case FR_INVALID_NAME: return "FATFS: The path name format is invalid";
  case FR_DENIED: return "FATFS: Access denied due to prohibited access or directory full";
  case FR_EXIST: return "FATFS: Destination file already exists";
  case FR_INVALID_OBJECT: return "FATFS: The file/directory object is invalid";
  case FR_WRITE_PROTECTED: return "FATFS: The physical drive is write protected";
  case FR_INVALID_DRIVE: return "FATFS: The logical drive number is invalid";
  case FR_NOT_ENABLED: return "FATFS: The volume has no work area";
  case FR_NO_FILESYSTEM: return "FATFS: There is no valid FAT volume";
  case FR_MKFS_ABORTED: return "FATFS: f_mkfs() aborted due to a parameter error. Try adjusting the partition size.";
  case FR_TIMEOUT: return "FATFS: Could not get a grant to access the volume within defined period";
  case FR_LOCKED: return "FATFS: The operation is rejected according to the file sharing policy";
  case FR_NOT_ENOUGH_CORE: return "FATFS: LFN working buffer could not be allocated";
  case FR_TOO_MANY_OPEN_FILES: return "FATFS: Number of open files > _FS_SHARE";
  default:
  case FR_INVALID_PARAMETER: return "FATFS: Invalid parameter";
  }
}

/* minimum 128 */
#define SECCOUNT 128

#endif
