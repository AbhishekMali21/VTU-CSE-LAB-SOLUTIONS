	area pgm3,code,readonly
entry
start
	ldr r0=0x00000002
	ldr r1=0x00000003
	add r2,r1,r0
	muls r3,r1,r0
	bx lr
end