global _start;
[bits 32]

; Renamed to '_start' because that is the label gcc looks
; for when compiling, so defining it removes the warning
; of an implicit starting point.
_start:
    [extern kernel_main]   ; Define calling point. Must have same name as kernel.c 'main' function
    call kernel_main       ; Calls the C function. The linker will know where it is placed in memory
    jmp $           ; loops indefinitely
