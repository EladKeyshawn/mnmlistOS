global flush_gdt

flush_gdt:
   mov   eax, [esp + 4]
   lgdt  [eax]
   
  	mov 	ax, 0x10 	; Kernel DataSeg
	mov 	ds, ax
	mov 	es, ax
	mov 	fs, ax
	mov 	gs, ax
	mov 	ss, ax
	jmp 	0x08:complete_flush_gdt	; Kernel CodeSeg

complete_flush_gdt:
	ret
