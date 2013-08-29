#include <iostream>
#include <vector>

//prototypes
template <class T>
void merge(T&,T&, int, int, int);

template <class T>
void merge_sort(T &a, T &b, int start, int end)
{
  int half;
  if (start < end)
  {
    half = (start+end) / 2; //halfpoint will round down because (int)
    merge_sort(a,b,start,half); //first half
    merge_sort(a,b,half+1, end); //second half
    merge(a,b,start,half, end);  
  }
}

template <class T>
void merge(T &a, T &b, int start, int half, int end)
{
  int h,i,j,k;
  h=start; i=start;
  j=half+1;

  while ((h<=half) && (j<=end))
  {
    if (a[h] <= a[j])
      b[i] = a[h++];
    else
      b[i] = a[j++];
    ++i;
  }
  if (h > half)
  {
    for (k=j; k<=end; k++)
    {
      b[i] = a[k];
      ++i; 
    }
  }
  else
  {
    for (k=h; k<=half; k++)
    {
      b[i] = a[k];
      ++i;
    }    
  }

  for (k=start; k<=end; k++)
    a[k] = b[k];
}


int main()
{
  int a[9] = {2,5,2,5,4,3,0,9,8};  
  int b[9];
  merge_sort(a,b, 0, 8);
  
  for (int i = 0; i<9; ++i)  std::cout<<a[i]<<" ";
  std::cout<<std::endl;
  return 0;
}
