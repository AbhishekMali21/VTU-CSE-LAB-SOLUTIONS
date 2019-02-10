	area prg1,code,readonly
entry
start
	ldr r1=value
	ldr r2,[r1]
	ldr r4=value
	str r3,[r4]
	bx lr
value
	dcd 0x22222222
	end