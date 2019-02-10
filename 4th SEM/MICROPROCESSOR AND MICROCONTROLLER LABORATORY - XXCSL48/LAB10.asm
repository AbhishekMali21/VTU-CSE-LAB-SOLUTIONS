.model large
.stack 100
.data
n  equ 6
pa equ 0e880h
pb equ 0e881h
pc equ 0e882h
ctrl equ 0e883h

.code
mov ax,@data
mov ds,ax
mov dx,ctrl
mov al,80h
out dx,al
mov bh,n

up:mov al,0eeh
   call step
   mov al,0ddh
   call step
   mov al,0bbh
   call step
   mov al,077h
   call step
   dec bh
   jnz up
   
   mov ah,4ch
   int 21h

   step proc near
   push bx
   mov dx,pc
   out dx,al
   mov bx,0ffffh

again:mov cx,05fffh

agn:loop agn
    dec bx
    jnz again
    pop bx
    ret
    step endp
    end

