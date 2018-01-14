#include "ff.h"
#include "fatfstest.h"

void main()
{
  FATFS fs;
  FILINFO fn;
  FIL f;
  char buf[512];
  int r;
  FCHK(f_mount(&fs, "", 0)); 
  FCHK(f_open(&f, "/abc/a.txt", FA_READ));
  FCHK(f_read(&f, buf, 512, &r));
  FCHK(f_close(&f));
  printf("read %d\n", r);
  printf("read %s\n", buf);  
}
