CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings -g
COPS = -Wall -Werror -g -O2 -nostdlib -nostartfiles -ffreestanding 

test.bin : helper.c pa03.s pa03.ld
	$(CROSS_COMPILE)-gcc -c -mcpu=arm926ej-s helper.c -o helper.o
	$(CROSS_COMPILE)-as $(AOPS) -mcpu=arm926ej-s pa03.s -o pa03.o
	$(CROSS_COMPILE)-ld -T pa03.ld helper.o pa03.o -o pa03.elf
	$(CROSS_COMPILE)-objcopy -O binary pa03.elf pa03.bin

