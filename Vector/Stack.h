#pragma once
#include "Array.h"



/*void f() {
	int *t = new int;
	if ()
	{
		return;
	}

}*/

//Stack s();
//Stack s2 = s;


template<typename T>
class Stack : public Array<T>
{
public:

	Stack();
	//Stack(const Stack<T>& s) = delete;
	Stack(const Stack<T>& that);


	//stack(stack<t>&& s);
	//
	//void operator=(stack s)
	//{
	//
	//}

	~Stack();

	//bool push(T&& value); s.push(getValue()) std::move(...)

	//bool              Resize       (unsigned size);

;




private:

	//smart_ptr (unique_ptr, shared_ptr sp(*), weak_ptr)
	


	T*                data_;
	unsigned          size_;
	unsigned          capacity_;
	unsigned          ERRORWORD = 0;


	//Stack(const Stack& s);

};


template<typename T>
Stack<T>::Stack() :
	Array(new T[STACKSIZE], 0, STACKSIZE)
{

	fout << "Constructor was called: " << __FUNCSIG__ << "\n";
}


template<typename T>
Stack<T>::Stack(const Stack<T>& that) :
	Array(that)
{
	fout << "Copy constructor was called: " << __FUNCSIG__ << "\n";
}



template<typename T>
Stack<T>::~Stack()
{

	fout << "Stack destructor was called: " << __FUNCSIG__ << "\n";
	//delete[] data_;
	//data_ = nullptr;
	//size_ = POISON;
}



#define asserted || fout<<"WARNING! ASSERT WAS CALLED ON LINE %d\n"<<__LINE__;
