global isr_wrapper
extern interrupt_handler

%macro ISR_NOERR
    pushad
    cld /* C code following the sysV ABI requires DF to be clear on function entry */
    call interrupt_handler
    popad
    iret