#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <cstring>
#include <string>
#include <boost\smart_ptr.hpp>


std::ifstream Fin("INPUT.txt");
std::ofstream fout("Log.txt");



template<typename T>
class Vector;

template<typename T>
bool operator ==(const Vector<T> & Left, const Vector<T> & Right)
{
	return Left.size_ == Right.size_;
}


template<typename T>
class Vector
{
public:
	
	Vector				           ();
	Vector                         (const Vector<T>& that);
	Vector                         (size_t size);
	Vector                         (Vector<T> && that);

	bool                Resize     (Vector<T>& that, unsigned vectorsize);
	bool                Push       (const T value);
	bool                Dump       ();
	T                   Pop();


	inline bool         PrintElem  (unsigned size);
	inline bool         OK         ();


	Vector & operator = (const Vector &that);

	//void* operator new (size_t size, void* place);
		
	void swap(Vector & that);
	T operator [](size_t index);
	friend bool operator==<T>(const Vector & Left, const Vector & Right);
	Vector & operator =(Vector && that);





	enum NUMBERS
	{
		VECTORSIZE = 10,
		POISON     = 718,
		ERRORCOUNT = 4
	};


	enum ERROSR
	{
		SIZEMIN  = 1 << 0,
		SIZEMAX  = 1 << 1,
		DATANULL = 1 << 2,
		STKNULL  = 1 << 3
	};

	~Vector();
;

private:


	T*     data_;
	size_t capacity_;
	size_t size_;
	size_t errorword;

};


template<typename T>
Vector<T> & Vector<T>::operator = (const Vector &that)
{
	fout << "Operator = was called\n";
	
	if (this == &that)
	{
		return *this;
	}

	Vector<T> temp(that);
	temp.swap(*this);
	return *this;
}

//void* operator new (size_t size, void* place)
//{
//	return place;
//}


template<typename T>
T Vector<T>::operator [](size_t index)
{
	fout << "Operator[] was called\n";
	return data_[index];
}

template<typename T>
Vector<T> & Vector<T>::operator =(Vector && that)
{
	fout << "Move operator was used" << std::endl;
	swap(that);
}


template<typename T>
void Vector<T>::swap(Vector & that)
{
	fout << "Function swap was called" << std::endl;
	std::swap(size_, that.size_);
	std::swap(capacity_,that.capacity_);
	std::swap(data_, that.data_);
}


template<typename T>
Vector<T>::Vector():
	data_(new T[VECTORSIZE]{}),
	capacity_(VECTORSIZE),
	size_(0),
	errorword(0)
{

	fout << "Constructor was called: " << __FUNCSIG__ << "\n";
}

template<typename T>
Vector<T>::Vector(size_t size):
	size_(0),
	capacity_(size)
{
	if (size == 0)
		data_ = (new T[1]);
	fout << "Constructor Vector(size) was called\n";
}




template<typename T>
bool Vector<T>::Push(const T value)
{
	Dump();
	data_[size_++] = value;
	fout << "PUSH: ";
	PrintElem(size_ - 1);
	return true;
}


template<typename T>
Vector<T>::Vector(const Vector & that) :
	size_(that.size_),
	capacity_(VECTORSIZE)
{
	data_ = new T[that.capacity_];
	std::copy(that.data_, that.data_ + that.size_, data_);

	fout << "Vector copy constructor was called: " << __FUNCSIG__ << "\n";
}


template<typename T>
Vector<T>::Vector(Vector<T> && that):
	capacity_(that.capacity_),
	size_(that.size_),
	data_(that.data_)
{
	fout << "Move constructor was called!\n";

	that.data_ = nullptr;
}




template<typename T>
T Vector<T>::Pop()
{
	Dump();
	fout << "POP: ";
	PrintElem(size_ - 1);
	T value = data_[size_ - 1];
	data_[size_ - 1] = {};
	size_--;

	return value;
}


template<typename T>
bool Vector<T>::PrintElem(unsigned size)
{
	if ((size < capacity_) && (size < size_))
		fout << data_[size] << "\n";
	else
		return false;
	return true;

}


template<typename T>
bool Vector<T>::OK()
{
	bool errorflag = true;
	if (size_ < 0)
	{
		errorword = errorword | SIZEMIN;
		errorflag = false;
	}
	if (size_ > capacity_)
	{
		errorword = errorword | SIZEMAX;
		errorflag = false;
	}
	if (data_ == nullptr)
	{
		errorword = errorword | DATANULL;
		errorflag = false;
	}

	if (!errorflag) {


		fout << "FUNC: " << __FUNCSIG__ << "\nOK started\n\t{\n";


		for (unsigned counter(0); counter < ERRORCOUNT; ++counter)
		{
			if ((errorword)&(1 << counter))
			{

				fout << "\t\tERROR " << counter << "\n";
			}
		}

		fout << "\n\t}\nOK ended\n\n";

		return false;

	}

	return true;
}



template<typename T>
bool Vector<T>::Dump()
{
	if (OK())
	{
		fout << "\n*****************************DUMP*START****************************\n\n" <<
			"FUNC: " << __FUNCSIG__ <<
			"\nSize\t\t = " << size_ << "\nCapacity\t = " << capacity_ << "\n";

		for (unsigned counter(0); counter < size_; counter++)
		{
			fout << "*\tdata_[" << counter << "] = ";

			PrintElem(counter);

		}
		fout << "\n*****************************DUMP*END******************************\n\n";

		return true;
	}
	else
	{
		fout << "Vector has been crashed!\n";


		exit(EXIT_SUCCESS);
		return 0;
	}

}


template<typename T>
bool Vector<T>::Resize(Vector& that, unsigned vectorsize)
{
	fout << "\nResize was called: ";
	if (vectorsize > that.capacity_)
	{
		that.capacity_ = vectorsize;

		Vector<T> v1 (that); // copy constructor is calling
		fout << "succeded\n";
		return true;
	}
	else {
		fout << "failed\n";
		return false;
	}
}





template<typename T>
Vector<T>::~Vector()
{
	fout << "Vector destructor was called: " << __FUNCSIG__ << "\n";
	delete[] data_;
}



#define asserted || fout<<"WARNING! ASSERT WAS CALLED ON LINE %d\n"<<__LINE__;
