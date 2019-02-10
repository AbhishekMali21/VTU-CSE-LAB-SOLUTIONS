.model small
.stack 18
.data
pa equ 0e880h
pb equ 0e881h
pc equ 0e882h
ctrl equ 0e883h

.code
mov ax,@data
mov ds,ax

  mov al,8ah
  mov dx,ctrl
  out dx,al

  mov dx,pb
  in al,dx
  mov bl,al

  mov dx,pc
  in al,dx
  mov cl,04h

  ror al,cl
  mul bl
  mov dx,pa
  out dx,al

mov ah,4ch
int 21h
int 3
end


