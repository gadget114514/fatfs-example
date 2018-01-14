# fatfs-example
elm chan fatfs example 

This is generic example of fatfs on linux in order to learn basic behavior of fatfs.

The backend (diskio.c) is constructed with "open, read, write, close, lseek" basic Unix API.
So it is very simple for beginners to use fatfs.



In order to build,

```
% make
```
several commands are generated.

- create disk image
```
% ./fmkfs     
```
the generated disk image is abc.dat. At first, it opens "abc.dat" and writes 512 bytes data with zero value SECTORCOUNT times. Then it call f_mkfs with super floppy and fat options.
```
% ls abc.dat
abc.dat
```

- test commands
```
% ./mkd
% ./cf
% ./rf
% ./cf2
% ./rf2
% ./rd
```

...

# Notice

- abc.dat is the disk image.
- SECCOUNT in fatfstest.h defines size of image (512 * SECCOUNT).
- fatfs is mostly configured as default except enabling mkfs.

# Minimus size of disk image

- the size of disk image is 64K. Probablly it is the minimum size of fat.
- the sector count is 128 and format is super floppy image and fat12.
   you can see disk_ioctl() in diskio.c. it returns 512 as sector size
   and 128 as sector count.
