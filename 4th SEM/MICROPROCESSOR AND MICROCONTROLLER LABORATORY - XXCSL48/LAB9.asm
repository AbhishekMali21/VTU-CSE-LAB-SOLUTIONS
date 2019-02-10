.model small
.stack 64
.data
pa equ 0e880h
pb equ 0e881h
pc equ 0e882h
ctrl equ 0e883h

fire db 71h,11h,0ah,61h
help db 91h,61h,0e3h,31h
msg db 'press any key on kbd to return to dos','$'

.code
mov ax,@data
mov ds,ax
mov al,90h
mov dx,ctrl
out dx,al
mov ah,09h
lea dx,msg
int 21h

again:lea bp,fire
      call disp
      call delay

      lea bp,help
      call disp
      call delay

      mov ah,6h
      mov dl,0ffh
      int 21h
      jz again
      mov ah,4ch
      int 21h
      delay proc
      mov ax,08fffh

 agn1:mov cx,05fffh

 agn:loop agn
     dec ax
     jnz agn1
     ret
     delay endp
     disp proc
     mov si,3

nxtchr:mov ah,8
       mov al,ds:[bp+si]

nxtseg:mov dx,pb
       out dx,al
       mov ch,al
       mov al,0

       mov dx,pc
       out dx,al
       mov al,0f0h
       out dx,al
       dec ah
       jz below
       mov al,ch
       ror al,1
       jmp nxtseg

below:  dec si
        cmp si,-1
        jne nxtchr
        ret
        disp endp
        end
