//
// Created by vadim on 11.01.19.
//

#include "Int.hpp"

Int::Int():
        _value(0),
        _counter(0)
{
    std::cout << "Int has initialised by zeroooooo!" << std::endl;
}

Int::Int(const int_type value):
    _value(value),
    _counter(0)
{
    std::cout << "Int has initialised by your value! Or not..." << std::endl;
}

Int::~Int()
{
    std::cout << "Destructor!" << std::endl;
}

void Int::setValue(const int_type value)
{
    _value = value;
}

void Int::printValue()
{
    std::cout << "value = " << _value << std::endl;
}

void Int::dump()
{
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "-\t\tvalue   = " << _value   << std::endl;
    std::cout << "-\t\tcounter = " << _counter << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
}

Int & Int::operator = (const Int & curInt)
{

//    if(this == &curInt)
//        return *this;
    std::cout << "in operator =" << std::endl;
    _counter++;
    if(!_counter % MAX_OPER_EQ_NUMBER)
    {
        std::cout << "Type your favourite book" << std::endl;
        std::string answer;
        std::getline(std::cin, answer);
        std::cout << "OK! Your answer is" << std::endl << answer << std::endl;
    }
    _value = -curInt._value;

    return *this;
}

std::ostream& operator<<(std::ostream & stream, const Int & digit)
{
    stream << digit._value;
    return stream;
}

Int & Int::operator+(const Int & rv)
{
    std::cout << "in operator +" << std::endl;
    Int * temp = new Int(this->_value);
    temp->_value += rv._value;
    return *temp;
}

Int & Int::operator-(const Int & rv)
{
    std::cout << "in operator -" << std::endl;
    this->_value -= rv._value;
    return *this;
}

Int Int::operator*(const Int & other) const
{
    std::cout << "in operator *" << std::endl;
    return Int(_value * other._value);
}


Int Int::operator/(const Int & other) const
{
    std::cout << "in operator /" << std::endl;
    return Int(_value / other._value);
}

Int & Int::operator++()
{
    std::cout << "in operator ++value" << std::endl;
    this->_value++;
    return *this;
}

const Int Int::operator++(const int_type value)
{
    std::cout << "in operator value++" << std::endl;
    Int result(*this);
    ++(*this);
    return result;
}

const Int Int::operator--(const int_type value)
{
    std::cout << "in operator --" << std::endl;
    this->_value --;
    return *this;
}


// copy constructor realisation

Int::Int(const Int& other):
    _value  (other._value),
    _counter(other._counter)
{
    std::cout << "copied Int" << std::endl;
}




