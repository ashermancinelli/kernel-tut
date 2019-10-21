[bits 32]

VID_MEM equ 0xb8000
WHITE equ 0x0
BLACK equ 0xf
WHITE_ON_BLACK equ WHITE << 1 + BLACK
_WHITE_ON_BLACK equ 0x0f

print_string_pm:
    pusha
    mov edx, VID_MEM

print_string_pm_loop:
    mov al, [ebx]
    mov ah, WHITE_ON_BLACK
    cmp al, 0               ; return on null char
    je done
    mov [edx], ax

    add ebx, 1
    add edx, 2
    jmp print_string_pm_loop

done:
    popa
    ret


