#include "StackHeader.h"

int main()
{
	fopen_s(&Log, "Log.txt", "w");
	
	Stack <Stype> Tool;
	Stack <int>   IntTool;
	Stack <char>  CharTool;

	for (int i(0); i < 5; i++)
	{
		IntTool.Push(i)       asserted;
	}
	
	Tool.Dump();
	IntTool.Dump();
	CharTool.Dump();

	CharTool.Push('v')        asserted;
	CharTool.Push('a')        asserted;
	CharTool.Push('d')        asserted;
	CharTool.Push('i')        asserted;
	CharTool.Push('m')        asserted;

	CharTool.Dump();

	Tool.Push(12.121)         asserted;
	Tool.Push(18.743)         asserted;
	Tool.Push(87652.121)      asserted;
	Tool.Push(1432.253)       asserted;
	Tool.Push(99382.134)      asserted;


	IntTool.Push(1234)        asserted;

	Tool.Resize(50);

	Tool.Dump();

	Tool.Push(498528.1)       asserted;
	Tool.Push(1.000001)       asserted;
	Tool.Push(189.7482)       asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;
	Tool.Push(87231.131313)   asserted;

	Tool.Pop();
	Tool.Pop();
	Tool.Pop();

	Tool.Dump();

}

template<typename T>
Stack<T>::Stack()
{
	fprintf(Log, "Constructor was called\n");
	data = new T[STACKSIZE];
	Stack::count    = 0;
	Stack::size     = STACKSIZE;
	Stack::resizer  = false;
}

template<typename T>
Stack<T>::~Stack()
{
	fprintf(Log, "Destructor was called\n");
	delete [] Stack::data;
	count = POISON;
}

template<typename T>
bool Stack<T>::Push(const T value)
{
	Dump();
	data[count++] = value;
	fprintf(Log, "PUSH: ");
	PrintElem(data[count-1]);
	return true;
}

template<typename T>
Stype Stack<T>::Pop()
{
	Dump();
	Stype value = data[count-1];
	data[count-1] = 0.0;
	count--;
	fprintf(Log, "POP: ");
	PrintElem(value);
	return value;
}



template<typename T>
bool Stack<T>::OK()
{
	bool errorflag = true;
	if (count < 0)
	{
		ERRORWORD = ERRORWORD | SIZEMIN;
		errorflag = false;
	}
	if (count > size)
	{
		ERRORWORD = ERRORWORD | SIZEMAX;
		errorflag = false;
	}
	if (data == nullptr)
	{
		ERRORWORD = ERRORWORD | DATANULL;
		errorflag = false;
	}

	if (!errorflag){

	fprintf(Log, "\nFUNC: %s\nOK started\n\t{\n", __FUNCSIG__);

	
	for (unsigned counter(0); counter < ERRORCOUNT; ++counter)
	{
		if ((ERRORWORD)&(1 << counter))
		{
			fprintf(Log, "ERROR %d\n", counter);
		}
	}
	fprintf(Log, "\n\t}\nOK ended\n\n");

	return false;

	}
	
	return true;
}



template<typename T>
bool Stack<T>::Dump()
{
	if (OK())
	{
		fprintf(Log, "\n*****************************DUMP*START****************************\n\n");
		fprintf(Log, "Counter = %d\n", count);
		fprintf(Log, "Size    = %d\n", size );
		for (unsigned counter(0); counter < count; counter++)
		{

			fprintf(Log, "*\tdata[%d] = ", counter);
			PrintElem(data[counter]);
			
		}
		fprintf(Log, "\n*****************************DUMP*END******************************\n\n");
		return true;
	}
	else
	{
		fprintf(Log, "Stack has been crashed!\n");
		fclose(Log);
		abort();
		return 0;
	}
	
}



template<typename T>
bool Stack<T>::Resize(unsigned stksize)
{
	if (!resizer) {

	void* pointer = realloc(data, stksize*sizeof(T));

	if (pointer == nullptr)
	{
		fprintf(Log, "REALLOC HAS BEEN FAILED!\n");
		return false;
	}

	else
	{

		resizer  = true;
		size = stksize;
		
		data     = (T*)pointer;

		fprintf(Log, "REALLOC HAS BEEN CALLED\n");
		return true;
	}

	}
	else
	{
		return false;
	}
}



template<typename T>
void Stack<T>::PrintElem()
{
	assert(!"Cannot Print! Type of data was not declared.\n");

}

template<typename T>
void Stack<T>::PrintElem(const int elem)    const {

	assert(Log);
	fprintf(Log, "%d\n", elem);
}

template<typename T>
void Stack<T>::PrintElem(const double elem) const {
	assert(Log);
	fprintf(Log, "%lg\n", elem);
}

template<typename T>
void Stack<T>::PrintElem(const char elem)   const {
	assert(Log);
	fprintf(Log, "%c\n", elem);
}

template <typename T>
void Stack<T>::PrintElem(const float elem)  const {
	assert(Log);
	fprintf(Log, "%f\n", elem);
}

#undef asserted
