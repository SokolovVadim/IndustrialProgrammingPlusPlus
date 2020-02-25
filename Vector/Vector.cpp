#include "Vector.h"
#include <boost/shared_ptr.hpp>

int main()
{
	

	Vector <double> Tool;
	Vector <int>   IntTool;
	Vector <char>  CharTool;


	Tool.Push(12.1212);
	Tool.Push(124134.512);

	for (int i(0); i < 5; i++)
	{
		IntTool.Push(i)       asserted;
		//IntTool[i] = 5;
		fout << IntTool[i] << std::endl;
	}


	

	//Tool.Dump();
	//IntTool.Dump();
	//CharTool.Dump();

	CharTool.Push('v')        asserted;
	CharTool.Push('a')        asserted;
	CharTool.Push('d')        asserted;
	CharTool.Push('i')        asserted;
	CharTool.Push('m')        asserted;


	CharTool.Pop();
	CharTool.Pop();
	CharTool.Pop();
	CharTool.Pop();
	

	Vector <int> v4(IntTool);


	if (v4 == IntTool)
		fout << "They are similar!\n";


	Vector <double> b = Tool;



	Vector <char> Vchar = CharTool;



	Vchar.Push('U');
	Vchar.Pop();


	Vector<double> v2(Tool);



	CharTool.Dump();

	Tool.Push(12.121)         asserted;
	Tool.Push(18.743)         asserted;
	Tool.Push(87652.121)      asserted;
	Tool.Push(1432.253)       asserted;
	Tool.Push(99382.134)      asserted;


	IntTool.Push(1234)        asserted;

	Vector <int> V1 (IntTool);

	V1.Push(1234567)          asserted;


	Vector <double> v3(Tool);

	//Tool.Resize(Tool, 50);    // copy constructor is calling

	Tool.Dump();

	//Tool.Push(498528.1)       asserted;
	//Tool.Push(1.000001)       asserted;
	//Tool.Push(189.7482)       asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	//Tool.Push(87231.131313)   asserted;
	
	Tool.Pop();
	Tool.Pop();
	Tool.Pop();

	Tool.Dump();

}



#undef asserted
