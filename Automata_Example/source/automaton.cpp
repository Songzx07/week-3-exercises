#include "automaton.h"
#include <stdexcept>

Automaton::Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S) : alphabet(A), transition_matrix(M), accepting_states(S) {}

bool Automaton::Read(string word)
{
  if (word.empty())
  {
    throw std::invalid_argument("Input string cannot be empty.");
  }

  for (auto &c : word)
  {
    // a map's find method returns an iterator to the key-value pair for the given key
    // iterators have syntax similar to pointers:
    // (*it) gives the key-value pair
    // -> can be used to access methods of the key value pair
    auto it = alphabet.find(c);
    if (it == alphabet.end())
    {
      throw std::runtime_error("Invalid character: " + string(1, c));
    }

    // it->first gives the key, it->second gives the value
    int j = it->second;
    state = transition_matrix[state][j];
  }

  return std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
}