CC = sdcc

HEX2BIN_PATH=/home/luckybb/Downloads/hot51/Hex2bin-2.5

all:timer.bin


timer.rel:timer.c delay.h
	sdcc -c timer.c

delay.rel:delay.c
	sdcc -c delay.c

timer.ihx: timer.rel delay.rel
	sdcc timer.rel delay.rel

timer.hex:timer.ihx
	packihx timer.ihx > timer.hex

timer.bin:timer.ihx
	${HEX2BIN_PATH}/hex2bin timer.hex > timer.bin

clean:
	rm -rf *.asm *.lst *.mem *.rst *.map *.lk *.sym *.rel *.ihx
