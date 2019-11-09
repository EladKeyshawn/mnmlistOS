global loader                       ; entry symbol for ELF


    extern kmain                    ; our main kernel C code entry point
    ; CONSTANTS
    MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
    FLAGS        equ 0x0            ; multiboot flags
    CHECKSUM     equ -MAGIC_NUMBER  ; (magic number + checksum + flags should equal 0)
                                    
    KERNEL_STACK_SIZE equ 4096                  ; size of stack in bytes

    section .bss
    align 4
        kernel_stack:                               ; start of kernel stack label
            resb KERNEL_STACK_SIZE                  ; reserve stack for the kernel

    
    
    section .text                   ; start of the text (code) section
    align 4                         ; the code must be 4 byte aligned
        dd MAGIC_NUMBER             ; write the magic number to the machine code,
        dd FLAGS                    ; the flags,
        dd CHECKSUM                 ; and the checksum

    ; remember right now we're dropped of by GRUB in protected mode
    
    loader:                         ; the loader label (defined as entry point in linker script)
        mov eax, 0xCAFEBABE         ; place the number 0xCAFEBABE in the register eax
        mov esp, kernel_stack + KERNEL_STACK_SIZE   ; point esp to the start of the

        
        call kmain
    .loop:
        jmp .loop                   ; loop forever


    
