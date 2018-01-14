#include "ff.h"
#include "fatfstest.h"

DIR d;
void main()
{
  FILINFO fn;
  FATFS fs;
  FCHK(f_mount(&fs, "", 0)); 
  
  FCHK(f_opendir(&d, "/abc"));
  printf("d.fn %s\n", d.fn);
  
  for (;;) {
    if (f_readdir(&d, &fn) != FR_OK || fn.fname[0] == '\0') break;
    printf("fn.name %s\n", fn.fname);
  }
  
  FCHK(f_closedir(&d));
}
