#include <stdio.h>

#define MYDLL_EXPORTS

#include "mydll.h"

int PingFang(int a)
{
	return a*a;
}