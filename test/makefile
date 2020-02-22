
HEX2BIN_PATH=/home/luckybb/Downloads/hot51/Hex2bin-2.5


test.hex:test.c
	sdcc test.c
	packihx test.ihx > test.hex

hex2bin:
	${HEX2BIN_PATH}/hex2bin test.hex

clean:
	rm -rf *.asm *.lst *.mem *.rst *.map *.lk *.sym *.rel *.ihx
