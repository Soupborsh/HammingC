CFLAGS = -Wall -O3
CC=cc
TARGET_ARCH?=

ifdef TARGET_ARCH
	CC=zig cc --target=$(TARGET_ARCH)
endif

hamc: hamc.c bits.h bits.c
	$(CC) $(CFLAGS) hamc.c bits.c -o hamc

clean:
	rm ./hamc
