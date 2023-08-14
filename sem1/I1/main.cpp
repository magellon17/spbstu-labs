#include <iostream>
<<<<<<< HEAD
#include <string>
#include "fun.h"
#include "struct.h"

short sum;
trio trio1;
int main()
{
<<<<<<< HEAD
  int sum = 0, number1, number2, number3;
  std::cin >> number1;
<<<<<<< HEAD
<<<<<<< HEAD
  if (number1 == 0){
    std::cout<<sum;
  }
  std::cin >> number2;
  if (number2 == 0){
    std::cout<<sum;
  }
  while (std::cin>>number3 && number3 != 0)
  {
    sum += ((number2 > number3 && number2 > number1) ? 1 : 0);
    number1 = number2;
    number2 = number3;
=======
=======
>>>>>>> 6d91e5f (Inception)
  if (!number1)
  {
    std::cout << sum;
    return 0;
  }
  std::cin >> number2;
  if (!number2)
  {
    std::cout << sum;
    return 0;
  }
  while (std::cin >> number3 && number3)
  {
    sum += ((number2 > number3 && number2 > number1) ? 1 : 0);
    (number1, number2) = (number2, number3);
<<<<<<< HEAD
>>>>>>> 597cf4b (Add I1)
=======
>>>>>>> 6d91e5f (Inception)
=======

  trio1.num1 = enter_num();
  trio1.num2 = enter_num();
  while (true)
  {
    trio1.num3 = enter_num();
    sum += check_trio(trio1.num1, trio1.num2, trio1.num3);
    trio1.num1 = trio1.num2;
    trio1.num2 = trio1.num3;
>>>>>>> 42313e7 (Unception 2.0)
  }
  std::cout << sum;
}
=======
#include "logic.h"
#include "CheckIfSecondMax.h"

int main()
{
  siobko::CheckIfSecondMax checkIfSecondMax;
  int num1, num2, num3, sum = 0;
  try
  {
    num1 = siobko::enter_num();
  }
  catch (const std::invalid_argument &err)
  {
    std::cout << err.what() << "\n";
    return 0;
  }
  try
  {
    num2 = siobko::enter_num();
  }
  catch (const std::invalid_argument &err)
  {
    std::cout << err.what() << "\n";
    return 0;
  }
  while (true)
  {
    try
    {
      num3 = siobko::enter_num();
    }
    catch (const std::invalid_argument &err)
    {
      std::cout << err.what() << "\n";
      return 0;
    }
    if (num3 == 0)
    {
      std::cout << sum;
      return 0;
    }
    try
    {
      bool ResultOfCondition = checkIfSecondMax(num1, num2, num3);
      int value = ((ResultOfCondition) ? 1 : 0);
      siobko::check_overflow(sum, value);
      sum += value;
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what() << "\n";
      return 0;
    }
    num1 = num2;
    num2 = num3;
  }
  std::cout << sum;
}
>>>>>>> siobko.boris/I1
