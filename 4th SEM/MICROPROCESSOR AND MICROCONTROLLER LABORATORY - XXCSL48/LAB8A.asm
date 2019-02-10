.model small
.stack  20
.data
pa equ 0e880h
pb equ 0e881h
pc equ 0e882h
ctrl equ 0e883h

.code
mov ax,@data
mov ds,ax
mov al,80h
mov dx,ctrl
out dx,al
mov al,00h

aa: add al,00h
    daa
    mov dx,pa
    out dx,al
    mov bx,5fffh

bb: mov cx,8fffh

cc: loop cc
    dec bx
    jnz bb
    add al,01h
    cmp al,9ah
    jnz aa

mov ah,4ch
int 21h
int 3
end
