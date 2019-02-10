.model small
.stack 10
.data
msg db 13,10,"the time is:"
time db ?,?,':',?,?,"$"

.code
mov ax,@data
mov ds,ax
mov ah,2ch
int 21h

mov dx,cx
mov cx,0
mov cl,dh
call convert

mov time,al
mov time+1,ah
mov cl,dl
call convert

mov time+3,al
mov time+4,ah
lea dx,msg              
mov ah,09h
int 21h
mov ah,4ch
int 21h

convert proc
mov ax,0
cmp cl,0
jz down

up:     add al,1
        daa
        loop up
        mov bl,10h
        div bl

down:   add al,30h
        add ah,30h
        ret
        convert endp
end
