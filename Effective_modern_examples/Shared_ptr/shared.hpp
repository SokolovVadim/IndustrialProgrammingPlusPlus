#include <iostream>
#include <typeinfo>


// lite types like basic C types
typedef std::size_t ref_counter_type;


class RefCounter
{
public:
	RefCounter();
	RefCounter(ref_counter_type* ref_counter_ptr);
	RefCounter(ref_counter_type ref_counter);
	const ref_counter_type getRefCounter() const;
	void operator++();
	void operator++(int); // dummy parameter
	void operator--();
	void operator--(int); // dummy parameter

	friend std::ostream& operator<<(std::ostream& os, const RefCounter & ref_counter);


	~RefCounter();


private:
	ref_counter_type ref_counter_;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr();
	SharedPtr(T*);
	SharedPtr(SharedPtr<T>&);
	const ref_counter_type getRefCounter() const;
	template<class Y>
	friend std::ostream& operator<<(std::ostream& os, SharedPtr<T>& that);

	~SharedPtr();
private:
	T* ptr_;
	RefCounter* ref_counter_;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, SharedPtr<T>& that) 
{ 
    os << "Ptr: " << that.getRefCounter() << std::endl; 
    std::cout << *(that.ref_counter_) << std::endl;
    return os;
}

template<typename T>
SharedPtr<T>::SharedPtr():
	ptr_(NULL),
	ref_counter_(0)
{
	std::cout << "Shared ptr with type " << typeid(T).name() << " created!" << std::endl;
}

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr):
	ptr_(ptr),
	ref_counter_(new RefCounter())
{
	if(ptr)
	{
		(*ref_counter_)++;
	}
	std::cout << "Shared ptr with type " << typeid(T).name() << " created! Ptr was: " << ptr  << std::endl;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& that)
{
	this->ptr_ = that.ptr_;
	this->ref_counter_ = that.ref_counter_;
	(*ref_counter_)++;
}

template<typename T>
const ref_counter_type SharedPtr<T>::getRefCounter() const
{
	return this->ref_counter_->getRefCounter();
}



template<typename T>
SharedPtr<T>::~SharedPtr()
{
	std::cout << "Destructor SharedPtr: ref_counter before destruction: " << this->ref_counter_->getRefCounter() << std::endl; 
	(*ref_counter_)--;
	if(this->ref_counter_->getRefCounter() == 0)
	{
		delete this->ref_counter_;
		delete this->ptr_;
	}
	std::cout << "Shared ptr with type " << typeid(T).name() << " destructed!" << std::endl;
}



