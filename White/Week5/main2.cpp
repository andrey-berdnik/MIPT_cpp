// Example program
#include <iostream>
#include <string>
#define MAX(a, b) a >= b ? a : b

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << MAX(1 , 2) << "!\n";
}
// Example program
#include <iostream>
#include <string>
#define MAX(a, b) a >= b ? a : b

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << 3 << "!\n";
}
