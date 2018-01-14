CSRCS += ff.c diskio.c

DEPPATH += --dep-path app/fatfs/source
VPATH += :app/fatfs/source

CFLAGS += "-I$(LVGL_DIR)/app -I$(LVGL_DIR)/fatfs/source"
