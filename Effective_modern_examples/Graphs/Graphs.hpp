/
// Created by vadim on 16.01.19.
//

#ifndef DIAGRAMS_GRAPHS_HPP
#define DIAGRAMS_GRAPHS_HPP
#include <iostream>
#include <string>
#include <typeinfo>

enum ERRORS
{
    ENO = 0x0,
    EOUT = 0x1,
    EBIG = 0x2
};


template <typename T>
class Graph
{
public:
    explicit Graph(int size);

    Graph() :
            _size(0),
            _data_array(nullptr),
            _error(ENO)
    {};
    ~Graph();

    const T operator[](int number);
    void fillWith(T value);

    const int getSize()const { return _size; };
    void dump();
private:
    int _size;
    T * _data_array;
    ERRORS _error;
};

template <typename T>
Graph<T>::Graph(const int size):
        _size(size),
        _data_array(new T[_size]),
        _error(ENO)
{
    std::cout << "constructed with type " << typeid(T).name() << std::endl;
}

template <typename T>
Graph<T>::~Graph()
{
    delete[] _data_array;
    _size = 0;
    std::cout << "destructor" << std::endl;
}

template <typename T>
void Graph<T>::dump()
{
    using std::cout;
    using std::endl;
    cout << "---------------------------DUMP-------------------------------" << endl;
    cout << "///\t\tdata type: " << typeid(T).name() << endl;

    cout << "///\t\tsize = " << _size << endl;
    for(int i(0); i < _size; ++i)
    {
        cout << "///\t\tdata_array[" << i << ", ";
        cout << &_data_array[i] << "] = " << _data_array[i] << endl;
    }

    cout << "---------------------------DUMP-------------------------------" << endl;
}

template <typename T>
const T Graph<T>::operator[](const int number)
{
    if((number >= 0) && (number < _size))
        return _data_array[number];
    else
    {
        std::cout << "Error! Index is out of range!" << std::endl;
        _error = EOUT;
        return _error;
    }
}

template <typename T>
void Graph<T>::fillWith(T value)
{
    for(int i(0); i < _size; ++i)
    {
        _data_array[i] = value;
    }
}

#endif //DIAGRAMS_GRAPHS_HPP
