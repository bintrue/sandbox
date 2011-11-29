#include <iostream>


int main()
{
  char c = 77;
  int NBITS = 8;
  for ( int i = NBITS-1; i >= 0; --i )
  {
    std::cout << ( (c>>i) % 2 );
    //c>>1;
  }
}




