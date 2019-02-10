.model small
.stack 10
.data
	m1 db 'palindrome$'
	m2 db 'not palindrome$'
	str1 db 'aabbaa$'
	l1 dw $-str1-1
	str2 db 25 dup(?)

.code
	mov ax,@data
	mov ds,ax
	mov es,ax
	mov si,0
	mov di,l1
	mov str2[di],'$'
	mov cx,l1
	dec di

up:	mov al,0
	mov al,str1[si]
	mov str2[di],al
	dec di
	inc si
	loop up

	mov si,offset str1
	mov di,offset str2
	mov cx,l1
	cld
	repe cmpsb
	jz pal
	mov dx,offset m2
	jmp exit

pal:	mov dx,offset m1

exit:	mov ah,09h
	int 21h
int 3
end

