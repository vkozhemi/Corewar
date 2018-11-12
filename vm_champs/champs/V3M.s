.name "V3M"
.comment ""

start:
	sti r1, %:live, %1
	ld %11, r2
	ld %1, r4
	and r3, %0, r3

live:	live %1

debut:
	sti r1,%:lives,%1
	sti r1,%:lives,%6
	sti r1,%:lives,%11

lives:
	live %0
	live %0
	live %0

copy:
	sti r4, %:lines, %1
	sti r2, %:lines, %0

prost:
	fork %:start

lines:
	
