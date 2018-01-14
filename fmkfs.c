#include "ff.h"
#include "fatfstest.h"

void main()
{
  char b[4096];
  FATFS fs;

  int fno = open("abc.dat", O_CREAT|O_SYNC|O_RDWR, S_IRUSR|S_IWUSR);
  printf("fno = %d\n", fno);
  int i = 0;
  char buf[512]={0};
  while (i < SECCOUNT) {
    //    printf("size = %ld\n", write(fno, buf, 512));
    write(fno, buf, 512);
    i++;
  }
  close(fno);
  fno = -1;
  //  f_mount(&fs, "", 0); 
  //  f_mkfs("", FM_FAT, 2*512, b, 4096);
  FCHK(f_mkfs("", FM_SFD|FM_FAT, 0, b, 4096));  
}
