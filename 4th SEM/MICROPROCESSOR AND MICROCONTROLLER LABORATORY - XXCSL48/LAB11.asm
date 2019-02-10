.model small
.stack 20
.data
pa equ 0e880h
pb equ 0e881h
pc equ 02882h
ctrl equ 0e883h
msg db 'press any key to return to DOS$'
tble db 80h,96h,0ABh,0D2h,0C0h,0ABh,096h,080h
     db 69h,54h,40h,2Dh,1Dh,11h,07h,01h,00h
     db 01h,07,11h,1Dh,2Dh,40h,54h,69h,80h

.code
mov ax,@data
mov ds,ax
mov dx,offset msg
mov ah,09
int 21h
mov al,80h
mov dx,ctrl
out dx,al
mov bx,offset tble

up:	mov ah,06h
	mov dl,0FFh
	int 21h
	jnz quit
	mov dx,pa
	mov ch,4Fh

up1:  mov cl,00

up2:	mov al,cl
	xlat
	out dx,al
	inc cl
	cmp cl,37
	jnz up2
	dec ch
	jnz up1
	jmp up

quit:mov ah,4ch
int 21h
end