#include "ff.h"
#include "fatfstest.h"

void main()
{
  FATFS fs;
  FCHK(f_mount(&fs, "", 1)); 
  
  FCHK(f_mkdir("/abc"));
  FCHK(f_mkdir("/def"));  
}
