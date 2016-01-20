extern main
global entrypoint
global exitpoint

section .entrypoint
align 4

entrypoint:
    mov     [stack_ptr],esp
    call    main
exitpoint:
    mov     esp,[stack_ptr]
    iret

section .text
align 4

section .bss
stack_ptr:
    resd 1    ; uninitialized dword (32 bits)
