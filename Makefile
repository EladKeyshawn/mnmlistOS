
os.iso: kernel/kernel.elf
	cp kernel/kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
				-b boot/grub/stage2_eltorito    \
                -no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o os.iso                       \
				iso

run: os.iso
	make clean
	bochs -f bochsrc.txt -q

qemu: os.iso
	qemu-system-x86_64 -boot d -cdrom os.iso -m 512 -serial file:logs/serial.log

debug: os.iso
	qemu-system-x86_64 -boot d -cdrom os.iso -m 512 -serial file:logs/serial.log -s -S

kernel/kernel.elf:
	make -C kernel
	
clean:
	make -C kernel clean
	rm -rf *.o os.iso