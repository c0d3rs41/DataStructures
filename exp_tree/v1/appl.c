#include "impl.h"

void main()
{
	struct AddrStack *s;
	s = (struct AddrStack*)malloc(sizeof(struct AddrStack));

	initAddrStack(s,3);

	push(s,createNode('1'));
	push(s,createNode('2'));
	push(s,createNode('3'));
	push(s,createNode('4'));
	display(s);

	pop(s);
	display(s);

	printf("\nTop element = %c",top(s)->c);
}
