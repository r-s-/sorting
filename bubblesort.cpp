#include <iostream>
#include <vector>

template <class T>
void bubble_sort(T &a)
{
  for (auto i = 0; i<a.size()-1; ++i)
  {
    for (auto j = 0; j<=a.size()-2-i ; ++j)
    {
      if (a[j] > a[j+1])
      {
	auto t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
}

int main()
{
  std::vector<int> vec = {5,9,2,7,1};
  bubble_sort(vec);

  for (auto i : vec) std::cout<<i<<" ";
  return 0;
}
