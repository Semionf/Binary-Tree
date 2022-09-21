#include <stdio.h>
#include "Utilities.h"

int Add(int);
int aaa();
int bbb();

int main2()
{
	int a = Add(1);

	return 0;
}

int Add(int num)
{
	if (num == 101)
	{
		return;
	}
	printf("Num %d\n", num);
	return Add(num + 1) + 1;
}

int aaa()
{
	bbb();
	return 0;
}

int bbb()
{
	return 0;
}
