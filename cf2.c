#include "ff.h"
#include "fatfstest.h"

void main()
{
  FIL f;
  int w;
  FATFS fs;
  FCHK(f_mount(&fs, "", 1)); 
  if (f_open(&f, "0:a.txt", FA_CREATE_ALWAYS|FA_READ|FA_WRITE) == FR_OK) {
    FCHK(f_write(&f, "abc\ndef\n", 9, &w));
    printf("open & write %d\n", w);
    FCHK(f_sync(&f));
    FCHK(f_close(&f));
  } else {
    printf("open error\n");
  }
}
