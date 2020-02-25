

template<typename T>
class Vector
{
private:
	T*            data_;
	unsigned          size_;
	unsigned          capacity_;
	unsigned          errorword = 0;
	

public:
	Vector(T* data, unsigned size, unsigned capacity);
	Vector(const Vector& that);

	~Vector();

	bool              Push      (const T value);
	T             Pop       ();
	bool              Dump      ();


	T& operator[](size_t index)
	{
		return data_[index];
	}

};

template<typename T>
Vector<T>::Vector(T* data, unsigned size, unsigned capacity) :
	data_     (new T[VECTORSIZE]),
	size_     (0),
	capacity_ (VECTORSIZE)
{
	fout << "Vector constructor was called: " << __FUNCSIG__ << "\n";
}


















