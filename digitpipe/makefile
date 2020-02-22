
HEX2BIN_PATH=/home/luckybb/Downloads/hot51/Hex2bin-2.5


digitpipe.hex:digitpipe.c
	sdcc digitpipe.c
	packihx digitpipe.ihx > digitpipe.hex

hex2bin:
	${HEX2BIN_PATH}/hex2bin digitpipe.hex

clean:
	rm -rf *.asm *.lst *.mem *.rst *.map *.lk *.sym *.rel *.ihx
