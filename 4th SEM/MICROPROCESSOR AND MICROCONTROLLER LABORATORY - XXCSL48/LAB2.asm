.model small
.stack 10
.data
	org 01h
	a db 03h,01h,04h,02h
	count dw 04

.code
mov ax,@data
mov ds,ax
mov bx,count
dec bx

outloop:mov cx,bx
	mov si,0

inloop:	mov al,a[si]
	inc si
	cmp al,a[si]
	jl down
	xchg al,a[si]
	mov a[si-1],al

down:	loop inloop
	dec bx
	jnz outloop

mov ah,4ch
int 21h
end

