#include <iostream>


int main()
{
  char c;
  std::cin >> std::ws;
  c = std::cin.peek();
  std::cout << "__" << c << "__" << std::endl;
  if ( '0' <= c && c <= '9' )
  {
    int number;
    std::cin >> number; 
    std::cout << "This is a number: " << number << std::endl;
  }
  else if ( 'q' == c )
  {
    std::cout << "quitting now..." << std::endl;
  }
  else
  {
    std::cout << "Invalid input." << std::endl;
  }
}



