#include "complex_fraction.h"

int main()
{
  complex_fraction my_comp1 = complex_fraction("20/1", "-4/1");
  complex_fraction my_comp2 = complex_fraction("3/1", "2/1");
  std::cout << my_comp1.to_string() << "\n";
  std::cout << my_comp2.to_string() << "\n";
  std::cout << (my_comp1 / my_comp2).to_string() << "\n";
}