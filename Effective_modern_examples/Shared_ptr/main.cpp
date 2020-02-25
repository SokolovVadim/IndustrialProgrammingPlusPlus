#include "shared.hpp"
#include <iostream>

class Example
{
public:
	Example():
		value_(0)
	{}
	Example(int value):
		value_(value)
	{}
	~Example()
	{
		std::cout << "Example destructor" << std::endl;
	}
	Example(const Example& ex)
	{
		std::cout << "Example copy constructor" << std::endl;
		this->value_ = ex.value_;
	}
private:
	int value_;
};



int main()
{
	// Example* ptr0 = nullptr;
	SharedPtr<Example> ptr1(new Example(718));
	std::cout << "ptr 1 ref counter: " << ptr1.getRefCounter() << std::endl;
	SharedPtr<Example> ptr2 = ptr1;
	std::cout << "ptr 1 ref counter: " << ptr1.getRefCounter() << std::endl;
	std::cout << "ptr 2 ref counter: " << ptr2.getRefCounter() << std::endl;
	{
		SharedPtr<Example> ptr3(ptr2);
		std::cout << "ptr 1 ref counter: " << ptr1.getRefCounter() << std::endl;
		std::cout << "ptr 2 ref counter: " << ptr2.getRefCounter() << std::endl;
	    std::cout << "ptr 3 ref counter: " << ptr3.getRefCounter() << std::endl;
	}
	std::cout << "ptr 1 ref counter: " << ptr1.getRefCounter() << std::endl;
	std::cout << "ptr 2 ref counter: " << ptr2.getRefCounter() << std::endl;
	/*std::cout << "ptr 1 ref counter: " << ptr1.getRefCounter() << std::endl;
	SharedPtr<Example> ptr2 = ptr1;
	std::cout << "ptr 2 ref counter: " << ptr2.getRefCounter() << std::endl;
	ptr1 = ptr2;
	std::cout << "ptr 1 ref counter: " << ptr1.getRefCounter() << std::endl;*/
}

