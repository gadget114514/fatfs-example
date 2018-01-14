#include "ff.h"
#include "fatfstest.h"

void main()
{
  FIL f;
  int w;
  FATFS fs;
  char buf[1024];
  FCHK(f_mount(&fs, "", 1)); 
  if (f_open(&f, "/abc/a.txt", FA_OPEN_EXISTING|FA_READ) == FR_OK) {
    FCHK(f_read(&f, buf, 9, &w));
    printf("open & write %d %s\n", w, buf);
    FCHK(f_close(&f));
  } else {
    printf("open error\n");
  }
}
