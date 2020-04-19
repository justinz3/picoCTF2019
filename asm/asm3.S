asm3:
	<+0>:	push   ebp
	<+1>:	mov    ebp,esp
	<+3>:	xor    eax,eax
	<+5>:	mov    ah,BYTE PTR [ebp+0x9]
	<+8>:	shl    ax,0x10
	<+12>:	sub    al,BYTE PTR [ebp+0xf]
	<+15>:	add    ah,BYTE PTR [ebp+0xd]
	<+18>:	xor    ax,WORD PTR [ebp+0x10]
	<+22>:	nop
	<+23>:	pop    ebp
	<+24>:	ret    

c 5 2 3 b 1 e c d 0 8 c d f f 1 4 7 f c 8 5

1100
0101
0010
0011
1011
0001
1110
1100
1101
0000
0100
1100
1101
1111
1111
0001
0100
0111
1111
1100
0100
0101

