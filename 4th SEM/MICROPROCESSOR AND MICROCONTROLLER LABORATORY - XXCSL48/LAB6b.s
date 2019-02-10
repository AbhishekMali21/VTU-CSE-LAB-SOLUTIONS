	area pgm,code,readonly
entry
start
	mov r0,#0
	mov r1,#1
	and r2,r1,r0
	orr r3,r1,r0
	eor r4,r1,r0
	bx lr
end