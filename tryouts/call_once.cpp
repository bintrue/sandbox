
#include <mutex>
#include <iostream>

void func()
{
  std::cout << "im called once." << std::endl;
}

struct functor
{
  void
  operator()()
  {
    std::cout << "im called once, functor" << std::endl;
  }
};

int main()
{
  std::once_flag flag;
  std::call_once( flag, functor() );
}

