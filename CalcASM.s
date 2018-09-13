// CECS 525	Matthew Vierling
// asm for c calculator
.data

.global remainder		//global var to hold division remainder
.type remainder, %object
remainder:
	.word 0

.text

.global cadd
cadd:
	add r0, r0, r1
	mov pc,lr		//move lr to pc to return to main

.global csub
csub:
	sub r0, r0, r1
	mov pc,lr		//move lr to pc to return to main

.global cmult
cmult:
	mul r0, r0, r1
	mov pc,lr		//move lr to pc


negnum:
	mov r5, #1
	rsb r0, r0, #0		//negate r0
	b ret1

negdem:
	mov r6, #1
	rsb r1, r1, #0		//negate r1
	b ret2

.global cdiv
cdiv:
	cmp r0, #0		//if numerator is negative
	bmi negnum
	mov r5, #0
ret1:
	cmp r1, #0		//if denominator is negative
	bmi negdem
	mov r6, #0
ret2:
	mov r3, #0
	b l			//branch to l
a:
	add r3, #1		//count
l:
	subs r0, r0, r1
	bpl a			//continue looping if positive
	add r4, r0, r1		//add r1 to r0 to store remainder in r4
	mov r0, r3		//put quotient in r0 to be returned

	cmp r5, r6
	beq skip
	rsb r0, r0, #0		//negate the quotient

skip:
	ldr r3, =remainder	//remainder address into r3
	str r4, [r3]		//store remainder in remainder

	mov pc,lr		//move lr to pc

	.end
