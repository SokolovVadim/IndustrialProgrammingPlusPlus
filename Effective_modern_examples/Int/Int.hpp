//
// Created by vadim on 11.01.19.
//

#ifndef INT_INT_HPP
#define INT_INT_HPP

#include <iostream>
#include <string>

// copy constructor

typedef int int_type;

enum COMPONENTS
{
    MAX_OPER_EQ_NUMBER = 3
};

class Int
{
public:

    Int                             ();
    explicit Int                             (int_type value);
    Int(const Int&);
    Int & operator =                (const Int &);
    Int & operator +  (const Int &);
    Int & operator -  (const Int &);
    Int & operator ++ ();
    Int   operator *  (const Int &) const;
    Int   operator /  (const Int &) const;
    const Int operator ++ ( int_type);
    const Int operator -- ( int_type);
    friend std::ostream& operator<<(std::ostream & stream, const Int & digit);
    void setValue                   (int_type value);
    void printValue();
    void dump();
    ~Int                            ();

    inline const int_type getValue() const
    {
        return _value;
    }

private:

    int_type _value;
    int_type _counter;
};


#endif //INT_INT_HPP
