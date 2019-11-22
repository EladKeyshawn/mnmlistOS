global set_gdt

set_gdt:
   mov   eax, [esp + 4]
   lgdt  [eax]
   
   
   push 0x08
   push complete_flush
   retf
   
complete_flush:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret