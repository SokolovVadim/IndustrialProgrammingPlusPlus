//ATTENTION! THIS CODE WAS EDITED BY MAXIM MOREV (HIGHOC)
#include "Stack.h"

template<typename T>
Stack<T>::Stack() :
	data_(new T[STACKSIZE]),
	size_(0),
	capacity_(STACKSIZE)
{
	fprintf(Log, "Constructor was called\n");
}

template<typename T>
Stack<T>::~Stack()
{
	fprintf(Log, "Destructor was called\n");
	delete[] data_;
	data_ = nullptr; //?
	size_ = POISON;
}

template<typename T>
bool Stack<T>::Push(const T value)
{
	Dump();
	data_[size_ ++] = value;
	fprintf(Log, "PUSH: ");
	PrintElem(data_[size_ - 1]);
	return true;
}

template<typename T>
Stype Stack<T>::Pop()
{
	Dump();
	Stype value = data_[size_ - 1];
	data_[size_-1] = 0.0;
	size_--;
	fprintf(Log, "POP: ");
	PrintElem(value);
	return value;
}

//for(auto& elem: v)

template<typename T>
bool Stack<T>::OK()
{
	bool errorflag = true;
	if (size_ < 0)
	{
		ERRORWORD = ERRORWORD | SIZEMIN;
		errorflag = false;
	}
	if (size_ > capacity_)
	{
		ERRORWORD = ERRORWORD | SIZEMAX;
		errorflag = false;
	}
	if (data_ == nullptr)
	{
		ERRORWORD = ERRORWORD | data_NULL;
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
		fprintf(Log, "Counter = %d\n", size_);
		fprintf(Log, "Size    = %d\n", capacity_ );
		for (unsigned counter(0); counter < size_; counter++)
		{

			fprintf(Log, "*\tdata_[%d] = ", counter);
			PrintElem(data_[counter]);
			
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
	if (!resizer_) {

	T* pointer = realloc(data_, stksize*sizeof(T));
	//new
	//swap or move
	//delete

	if (pointer == nullptr)
	{
		fprintf(Log, "REALLOC HAS BEEN FAILED!\n");
		return false;
	}

	else
	{

		resizer_  = true;
		capacity_ = stksize;
		
		data_     = (T*)pointer;

		fprintf(Log, "REALLOC HAS BEEN CALLED\n");
		return true;
	}

	}
	else
	{
		return false;
	}
}

//Engine engine();
//engine.run();

template<typename T>
void Stack<T>::PrintElem()
{
	fout << data_[size];
	assert(!"Cannot Print! Type of data_ was not declared.\n");

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


