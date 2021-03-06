# Axel Fahy - Rudolf Hohn
# 16.10.2015
#
# Makefile for kernel
#
# 'make'					build ELF file of kernel
# 'make run'				run the operating system on QEMU
# 'make clean'				removes all .o files
# 'make MODE=-DTEST run 	make in DEBUG mode
#

MAKE=make
KERNEL=kernel.iso
FS=fs.img
X=1024			# Block size
Y=100			# Number of file entries
Z=1000			# Number of data blocks available
FT_SPLASH=splash_screen

.PHONY: run, clean

$(KERNEL): kernel.elf $(FS)
	grub-mkrescue -o $@ .

arch: kernel.elf $(FS)
	grub-mkrescue -d /usr/lib/grub/i386-pc -o $(KERNEL) .

kernel.elf:
	$(MAKE) -C kernel DEBUG=$(MODE)
	mkdir -p boot/grub
	cp kernel/kernel.elf boot/
	cp grub/grub.cfg boot/grub/

$(FS):
	$(MAKE) -C tools
	$(MAKE) -C user
	cp user/shell tools/shell
	cp user/shell.txt tools/shell.txt
	cp user/connect4 tools/connect4
	cp user/connect4_board.txt tools/connect4_board.txt
	cp user/magic tools/magic
	cp user/joke.txt tools/joke.txt
	cp user/a.txt tools/a.txt
	cp user/b.txt tools/b.txt
	cp user/c.txt tools/c.txt
	cd tools && ./pfscreate $(FS) $(X) $(Y) $(Z)
	cd tools && ./pfsadd $(FS) $(FT_SPLASH)
	cd tools && ./pfsadd $(FS) shell
	cd tools && ./pfsadd $(FS) shell.txt
	cd tools && ./pfsadd $(FS) connect4
	cd tools && ./pfsadd $(FS) connect4_board.txt
	cd tools && ./pfsadd $(FS) magic
	cd tools && ./pfsadd $(FS) joke.txt
	cd tools && ./pfsadd $(FS) a.txt
	cd tools && ./pfsadd $(FS) b.txt
	cd tools && ./pfsadd $(FS) c.txt
	cd tools && ./pfsadd $(FS) fileA
	cd tools && ./pfsadd $(FS) fileB
	cd tools && ./pfsadd $(FS) fileC
	cp tools/$(FS) ./

run: $(KERNEL)
	qemu-system-i386 -monitor stdio -cdrom $(KERNEL) -hda $(FS)

clean:
	rm -f *.o
	rm -rf boot/
	rm -f common/*.o
	rm -f $(KERNEL)
	rm -f $(FS)
	rm -f tools/shell
	rm -f tools/shell.txt
	rm -f tools/connect4
	rm -f tools/connect4_board.txt
	rm -f tools/magic
	rm -f tools/joke.txt
	rm -f tools/a.txt
	rm -f tools/b.txt
	rm -f tools/c.txt
	$(MAKE) -C kernel clean
	$(MAKE) -C tools clean
	$(MAKE) -C user clean
