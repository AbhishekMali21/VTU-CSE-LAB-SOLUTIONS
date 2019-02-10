.model small
.stack 10
.data
n dw 4
r dw 2
org 10h
ncr dw ?
res dw ?

.code
mov ax,@data
mov ds,ax
mov ax,r
call fact
mov bx,res

mov ax,n
sub ax,r
call fact
mov ax,res
mul bx
mov bx,ax

mov ax,n
call fact
mov ax,res
div bx
mov ncr,ax
int 3

fact proc
cmp ax,0h
je exit
push ax
dec ax
call fact

pop ax
mul res
mov res,ax
ret

exit:mov res,1h
ret
fact endp
end
