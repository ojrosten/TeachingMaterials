#include "Probability.h"
#include "Foo.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <variant>

class vector
{
public:
    void sort();
};

enum class dir_entry { directory, file};

class GithubEntry
{
public:
    GithubEntry(dir_entry d) : m_DirEntry{d}
    {}
private:
    dir_entry m_DirEntry{};
};

class File
{};

class Directory
{
public:

private:
    std::vector<File> m_Files;
};

using GithubEntry2 = std::variant<Directory, File>;

template<class Node, class Edge>
class Graph
{
    
};

template<class G>
void dfs(const G& g);

int main()
{
  try
  {
      using namespace math;

      std::cout << sizeof(float) << '\n' << sizeof(double) << '\n';
      std::cout << sizeof(Probability<float>) << '\n' << sizeof(Probability<double>) << '\n';

      Probability<double> p{0.5}, q{p};
      raw_value(p);
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}
