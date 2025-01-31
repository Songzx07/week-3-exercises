#include "automaton.h"
#include <vector>
#include <map>
#include <iostream>

using std::map;
using std::string;
using std::vector;

int main()
{
  vector<vector<int>> M{{0, 1}, {0, 1}};
  map<char, int> A{{'a', 0}, {'b', 1}};
  vector<int> S{1};
  Automaton ends_with_b(A, M, S);

  string a;
  string b;

  while (true)
  {
    std::cout << "Input a string of a's and b's: ";
    std::cin >> a;
    try
    {
      bool result_a = ends_with_b.Read(a);

      std::cout << "Read " << a << " = " << result_a << std::endl;
      break;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  };

  return 0;
}