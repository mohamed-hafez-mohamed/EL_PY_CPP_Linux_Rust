#include <iostream>
#include <algorithm>

bool des(int a, int b)
{
  return a > b;
}
int main() {
  int arr[4] = {10, 4, 20, 0};
  std::sort(arr, arr + 4,[](int a, int b){return a > b;});
  for(int i = 0;i < 4;i++)
  {
    std::cout << arr[i] << std::endl;
  }
  std::sort(arr, arr + 4,[](int a, int b){return a < b;});
  std::cout << std::endl;
  for(int i = 0;i < 4;i++)
  {
    std::cout << arr[i] << std::endl;
  }
  return 0;
}
