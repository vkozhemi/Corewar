.name 		"turtle"
.comment	"TURTLE FFS U LAMA"

entry:
	sti			r1, %:zork, %1
	sti			r1, %:ardef, %1
	sti			r1, %:avdef, %1
	sti			r1, %:ernrtry_l1, %1
	ld			%0, r16
	fork		%:zork

ernrtry_l1:
	live		%42
	ld			%439025904, r2
	ld			%0, r16
	fork		%:avdef

################################################################################

ardef:
	live		%42
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	st			r2, -400
	zjmp		%:ardef

################################################################################

zork:
	live		%42
	zjmp		%:zork

################################################################################

avdef:
	live		%42
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	st			r2, 400
	zjmp		%:avdef

################################################################################
