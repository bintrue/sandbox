#include <iostream>
#include <boost/shared_ptr.hpp>

class MyType
{
  public:
    MyType() {}
    ~MyType()
    {
      std::cout << "DESCTRUCTED" << std::endl;
    }
};

template<class T>
void print( boost::shared_ptr<T>& sptr )
{
  std::cout << "GET:  " << sptr.get() << std::endl <<
               "REFC: " << sptr.use_count() << std::endl;
}

int main()
{
  boost::shared_ptr< MyType > sptr;
  print( sptr );

  sptr.reset( new MyType );

  print( sptr );

  {
    boost::shared_ptr< MyType > sptr2;
    sptr2 = sptr;
    print( sptr );
  }
  print( sptr );
  
}

