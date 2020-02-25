#include "shared.hpp"


RefCounter::RefCounter():
	ref_counter_(0)
{
	std::cout << "Ref counter created!" << std::endl;
}

RefCounter::RefCounter(ref_counter_type ref_counter):
	ref_counter_(ref_counter)
{
	std::cout << "Ref counter created with value " << ref_counter << std::endl;
}

RefCounter::RefCounter(ref_counter_type* ref_counter_ptr):
	ref_counter_(*ref_counter_ptr)
{
	std::cout << "Ref counter created with ptr " << ref_counter_ptr << std::endl;
}


const ref_counter_type RefCounter::getRefCounter() const
{
	return this->ref_counter_;
}

void RefCounter::operator++()
{
	ref_counter_++;
}

void RefCounter::operator++(int) // dummy int param
{
	ref_counter_++;
}

void RefCounter::operator--()
{
	ref_counter_--;
}

void RefCounter::operator--(int) // also dummy int param
{
	ref_counter_--;
}

std::ostream& operator<<(std::ostream& os, const RefCounter & ref_counter)
{
	os << "Reference counter value: " << ref_counter.ref_counter_ << std::endl;
	return os;
}


RefCounter::~RefCounter()
{
	std::cout << "RefCounter destructed!" << std::endl;
}
