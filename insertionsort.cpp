#include <iostream>
#include <vector>

//insertion sort function

template <class T>
void insertion_sort(T &a)
{  
  for (auto i = a.begin() + 1; i < a.end(); ++i)
  {
    auto k = *i; 
    auto j = i - 1;
    while(j >= a.begin() && *j > k)  
    {
      *(j + 1) = *j; 
      j--;
    }
      *(j + 1) = k;
  }  
}

int main()
{
  std::vector<int> vec = {1,6,2,4,5,2,6,2};
  insertion_sort(vec);
  for (auto i : vec) std::cout<<i<<" ";

  return 0;
}
