#include <stdio.h>
#include "ff.h"

main()
{
  FIL f;
  int w;
  FATFS fs;
  f_mount(&fs, "", 1); 
  if (f_open(&f, "/abc/a.txt", FA_CREATE_ALWAYS|FA_READ|FA_WRITE) == FR_OK) {
    f_write(&f, "abc\ndef\n", 8, &w);
    printf("open & write %d\n", w);
  } else {
    printf("open error\n");
  }
  f_close(&f);
}
