
HEX2BIN_PATH=/home/luckybb/Downloads/hot51/Hex2bin-2.5


flowlight.hex:flowlight.c
	sdcc flowlight.c
	packihx flowlight.ihx > flowlight.hex

hex2bin:
	${HEX2BIN_PATH}/hex2bin flowlight.hex

clean:
	rm -rf *.asm *.lst *.mem *.rst *.map *.lk *.sym *.rel *.ihx
