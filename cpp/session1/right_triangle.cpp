#include <algorithm>
#include <cassert>
#include <iostream>

bool isRightTriangle(int a, int b, int c) {
  // write your solution here...
  // Hint: Use Pythagorean theorem: a² + b² = c² (where c is the largest side)
  int a2{0},b2{0},c2{0};
  bool returnValue = false;
  a2 = a * a;
  b2 = b * b;
  c2 = c * c;
  if(c2 == (a2 + b2))
  {
    returnValue = true;
  }
  else if(a2 == (c2 + b2))
  {
    returnValue = true;
  }
  else if(b2 == (c2 + a2))
  {
    returnValue = true;
  }
  else
  {
    returnValue = false;
  }
  return returnValue;
}

int main() {
  std::cout << "==============================================\n";
  std::cout << "      RIGHT ANGLE TRIANGLE CHECKER\n";
  std::cout << "==============================================\n\n";

  // Test the isRightTriangle function
  // Test classic Pythagorean triples
  assert(isRightTriangle(3, 4, 5) == true);
  assert(isRightTriangle(4, 3, 5) == true);
  assert(isRightTriangle(5, 3, 4) == true);
  assert(isRightTriangle(5, 4, 3) == true);

  // Test other Pythagorean triples
  assert(isRightTriangle(5, 12, 13) == true);
  assert(isRightTriangle(12, 5, 13) == true);
  assert(isRightTriangle(13, 12, 5) == true);

  assert(isRightTriangle(8, 15, 17) == true);
  assert(isRightTriangle(15, 8, 17) == true);
  assert(isRightTriangle(17, 15, 8) == true);

  assert(isRightTriangle(7, 24, 25) == true);
  assert(isRightTriangle(24, 7, 25) == true);

  // Test scaled Pythagorean triples
  assert(isRightTriangle(6, 8, 10) == true);   // 3-4-5 * 2
  assert(isRightTriangle(9, 12, 15) == true);  // 3-4-5 * 3
  assert(isRightTriangle(10, 24, 26) == true); // 5-12-13 * 2

  // Test non-right triangles
  assert(isRightTriangle(1, 2, 3) == false);
  assert(isRightTriangle(2, 3, 4) == false);
  assert(isRightTriangle(5, 6, 7) == false);
  assert(isRightTriangle(1, 1, 1) == false);
  assert(isRightTriangle(2, 2, 2) == false);

  // Test invalid triangles (violate triangle inequality)
  assert(isRightTriangle(1, 1, 5) == false);
  assert(isRightTriangle(1, 2, 4) == false);
  assert(isRightTriangle(10, 1, 1) == false);

  std::cout
      << "\n\n[✓] All tests passed! Right triangle checker works correctly.\n";
  std::cout << "Function correctly identifies right triangles using "
               "Pythagorean theorem.\n";

  return 0;
}
