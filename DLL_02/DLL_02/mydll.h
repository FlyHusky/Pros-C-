#ifndef _MYDLL_H
#define _MYDLL_H

#ifdef MYDLL_EXPORTS
#define MYDLL __declspec(dllexport)
#else
#define MYDLL __declspec(dllimport)
#endif

MYDLL int Add(int a , int b);

#endif
 