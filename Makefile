all:
	cc fmkfs.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o fmkfs
	cc mkd.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o mkd
	cc rd.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o rd
	cc cf.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o cf
	cc cf2.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o cf2
	cc rf.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o rf
	cc rf2.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o rf2
	cc xf.c fatfs/source/diskio.c  fatfs/source/ff.c -I fatfs/source -g -o xf




