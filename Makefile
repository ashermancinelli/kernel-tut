
all: nasm

nasm:
	nasm boot_sec.asm -f bin -o boot_sec.bin

run:
	qemu-system-x86_64 boot_sec.bin
