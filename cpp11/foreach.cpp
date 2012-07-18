
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
  std::map<int,std::string> myMap;
  myMap[0] = "asdf";
  myMap[1] = "hahaha";

  for ( auto i : myMap )
  {
    std::cout << "K: " << i.first << " V: " << i.second << std::endl;
  }

  std::for_each( begin(myMap), end(myMap), []( std::pair<int,std::string> const & i ) // auto can't be used here
  {
    std::cout << "K: " << i.first << " V: " << i.second << std::endl;
  });
}


