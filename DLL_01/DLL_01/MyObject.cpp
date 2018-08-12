
#include <stdio.h>

#define MYDLL_EXPORTS
#include "MyObject.h"


MyObject::MyObject(int v)
:value(v)
{

}



void MyObject::Print()
{
	printf("value: %d \n", value);
}
