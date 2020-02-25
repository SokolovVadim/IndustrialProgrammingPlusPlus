#pragma once
#include <iostream>
#include <cassert>
#include <cstdio>

#define asserted || fprintf(Log, "WARNING! ASSERT WAS CALLED ON LINE %d\n", __LINE__);

FILE* Log = nullptr;
unsigned ERRORWORD = 0;

typedef double Stype;
enum NUMBERS
{
	STACKSIZE  = 10,
	POISON     = 718,
	ERRORCOUNT = 4
};

enum ERROSR
{
	SIZEMIN   = 1 << 0,
	SIZEMAX   = 1 << 1,
	DATANULL  = 1 << 2,
	STKNULL   = 1 << 3
};


template<typename T>
class Stack
{
private:

	T*                data;
	unsigned          count;
	unsigned          size;
	bool              resizer;


public:
	Stack();
	~Stack();
	bool              Push         (T value);
	bool              Resize       (unsigned size);
	Stype             Pop          ();
	inline bool       OK           ();
	bool              Dump         ();
	
	inline void       PrintElem    ();
	inline void       PrintElem    (const int    elem)    const;
	inline void       PrintElem    (const double elem)    const;
	inline void       PrintElem    (const float  elem)    const;
	inline void       PrintElem    (const char   elem)    const;
};
