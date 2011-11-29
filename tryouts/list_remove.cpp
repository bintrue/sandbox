#include <list>
#include <iostream>
#include <algorithm>

/**
 *  Exercise: write a function:
 *    remove( list& l, int n )
 *    which removes every n-th element from l.
 *
 *  Possible pitfall: iterator invalidation
 *
 *  NOTE: std::list's erase method returns an iterator, which points to the next element
 *
 *  NOTE: contains C++11 features.  -std=gnu++0x
 */


template<class T>
void remove( std::list<T> & lst, int n )
{
  int c = 1;
  for ( auto i = lst.begin(); i != lst.end(); )
  {
    if ( (c % n) == 0 )
    {
      // avoid iterator invalidation.
      // Postincrement iterator behaviour:
      // iterator operator++(int, iterator& it)
      // {
      //   iterator tmp = it;
      //   it = it->next; // step to next node
      //   return tmp;
      // }
      //
      // In this way, 'i' still valid
      lst.erase( i++ );

      // other way:
      //i = lst.erase(i);
    
    else
    {
      ++i;
    }
    ++c;
  }
}

template<class T>
void print( const std::list<T> & lst )
{
  std::for_each( lst.begin(), lst.end(), [](int n)
  {
    std::cout << n << "," ;
  } );
  std::cout << std::endl;
}

int main()
{
  srand( time(0) );
  std::list<int> lst;

  std::generate_n( std::back_inserter( lst ), 20, []()
  {
    return rand() % 1000;
  });

  print(lst);
  remove(lst, 3);
  
  std::cout << "AFTER:\n";
  print(lst);

}
