bits 32
default rel

section .text
    global drawcall
    extern DrawBuffer

drawloop:
    ;DO DRAW
    inc bl
    mov ebx, dl
    mov ecx, 2
    mul ebx
    add eax, ebx
    mov ebx, cl
    mov ecx, 2
    mul ebx
    sub eax, ebx

drawcondition:
    cmp eax, 0
    jg drawloop
    
    ;DO DRAW
    mov ebx, dl
    mov ecx, 2
    mul ebx
    add eax,ebx

drawcall:
    mov ebp, esp

    ;x0,y0,x1,y1
    mov al, [ebp+8]
    mov bl, [ebp+12]
    mov cl, [ebp+16]
    mov dl, [ebp+20]

    sub cl, al
    sub dl, bl
    mov ah, al
    mov bh, bl
    
    mov eax, cl
    sub eax, dl
    mov ebx, 2
    mul eax

