
os.iso: kernel_build

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

all: qemu

qemu: os.iso  
	make -C kernel clean
	qemu-system-i386 -boot d -drive format=raw,media=cdrom,file=os.iso -m 4G -serial file:logs/serial.log

debug: os.iso
	qemu-system-i386 -boot d -drive format=raw,media=cdrom,file=os.iso -m 4G -serial file:logs/serial.log -s -S

kernel_build:
	make -C kernel

clean:
	make -C kernel clean
	rm -rf *.o os.iso


.PHONY: all clean qemu kernel_build
	