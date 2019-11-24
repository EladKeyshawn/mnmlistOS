extern isr_handler

%macro ISR_NOERR 1
        global isr%1
        isr%1:
            cli
            push 0 ; save err code 0
            push %1 ; save interrupt number
            jmp common_isr
%endmacro

%macro ISR_ERR 1
        global isr%1
        isr%1:
            cli
            push %1 ; save interrupt number
            jmp common_isr
%endmacro


common_isr:
    pushad ; push EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI
    ; cld /* C code following the sysV ABI requires DF to be clear on function entry */
    call isr_handler
    popad
    sti
    iret


; define all isr handlers

ISR_NOERR 1
