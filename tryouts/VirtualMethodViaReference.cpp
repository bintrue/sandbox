#include <iostream>


class Base
{
  public:
  virtual void method()
  {
    std::cout << "Base\n";
  }
  // make noncopyable:
  //private:
  //  Base& operator=( const Base &);
  //  Base(const Base&);
};

class Derived : public Base
{
  public:
  void method()
  {
    std::cout << "Derived\n";
  }
};

int main()
{
  Derived d1;
  d1.method(); // simple case, Derived::method called.

  Base & ref1 = d1;
  ref1.method(); // dynamic binding via reference, Derived::method called.

  Base cpy1 = d1; // copy ctor called, "slicing" happening, not a reference
  cpy1.method();  // there is no binding, Base::method called.

  Base * ptr = &d1;
  ptr->method(); // dynamic binding via pointer, Derived::method called
}


