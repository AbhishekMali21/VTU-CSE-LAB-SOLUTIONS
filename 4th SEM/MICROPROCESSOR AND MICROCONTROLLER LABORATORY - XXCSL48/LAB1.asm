.model small
.stack 10
.data
a dw 05h,10h,15h,20h,25h,30h,35h
n equ 07
key dw 10h
msg1 db 'Key found$'
msg2 db 'Key not found$'

.code
mov ax,@data
mov ds,ax
mov ax,key
mov cx,0
mov dx,n
add dx,dx
sub dx,1

next:	cmp cx,dx
	jg notfound
	mov bx,dx
	add bx,cx
	mov si,bx
	shr bx,1
	jnc count
	sub si,1

count:	cmp ax,a[si]
	je found
	jl lhalf
	add si,2
	mov cx,si
	jmp next

lhalf:	sub si,2
	mov dx,si
	jmp next

found: 	mov dx,offset msg1
	jmp exit

notfound: mov dx,offset msg2

exit: 	mov ah,09h
	int 21h

mov ah,4ch
int 21h
int 3
end
