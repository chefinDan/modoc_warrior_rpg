#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <cstring>

inline int getValidInt()
{
  double num;
  while(!(std::cin>>num) || (int)num != num)
  {
    std::cout << "Invalid input\n";
    if(std::cin.rdstate() != 0){std::cout << "Enter an integer: ";}
    else{std::cout << "Enter an integer with no decimals:";}
    std::cin.clear();
    std::cin.ignore(100, '\n');
  }
  return (int)num;
}

inline int getValidInt(int lo, int hi)
{
  double num;
  while(!(std::cin>>num) || (int)num != num || num<lo || num>hi)
  {
    std::cout << "Invalid input\n";
    if(std::cin.rdstate() != 0){std::cout << "Enter an integer: ";}
    else
    {
      if((int)num != num){std::cout << "Enter a positive integer: ";}
      else if(num<lo){std::cout << "Enter an integer no less than " << lo;}
      else if(num>hi){std::cout << "Enter an integer no greater than " << hi;}
    }
    std::cin.clear();
    std::cin.ignore(100, '\n');
  }
  return (int)num;
}
#endif
