
#include <iostream>


class Exception
{
public:
   Exception(const std::string& msg) : msg_(msg) {}
  ~Exception() {}

   const std::string& getMessage() const {
	   return(msg_);
   }

private:
   std::string msg_;
};

void Trigger()
{
	throw(Exception("Not like Schmitt trigger"));
}

int main()
{
	try {
		Trigger();
	}
	catch(const Exception & e)
	{
		std::cout << "Stupid Triggered message: " << e.getMessage() << std::endl;
	}

}
