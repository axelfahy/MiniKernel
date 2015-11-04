# Axel Fahy - Rudolf Hohn
# 16.10.2015
#
# Makefile for kernel
#
# 'make'		build ELF file of kernel
# 'make run'	run the operating system on QEMU
# 'make clean'	removes all .o files
# 


.PHONY: run, clean

kernel.iso: kernel.elf
	grub-mkrescue -o $@ .
	
kernel.elf:
	cd kernel && $(MAKE) DEBUG=$(MODE)
	mkdir -p boot/grub
	cp kernel/kernel.elf boot/
	cp grub/grub.cfg boot/grub/

# Before the run, we clean the files because of compatibility problem
# with computer from hepia
run: clean kernel.iso
	qemu-system-i386 -hda kernel.iso

clean:
	rm -f *.o
	rm -rf boot/
	rm -f kernel.iso
	rm -f doc/*.aux
	rm -f doc/*.log
	cd kernel && $(MAKE) clean


