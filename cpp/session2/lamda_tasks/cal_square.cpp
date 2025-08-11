#include <iostream>

int main() {
  int number{0};
  std::cout << "enter the number\n";
  std::cin >> number;
  [&number]()
  {
    std::cout << "the square of a number = " << number * number << std::endl;
  }();
  return 0;
}
