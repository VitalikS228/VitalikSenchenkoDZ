// Task 2 condition
// Введіть послідовність дійсних ненульових чисел (тобто введення закнічується коли ми вводимо 0).
// Визначити величину найбільшого серед від'ємних членів цієї послідовності.
// Якщо від'ємних чисел немає, вивести намйенший серед додатних членів.

// Performed by: Vitaly Viktorovych Senchenko, group: computer mathematics 1
#include <iostream>
#include <cmath>


int main() {
  // Initialize the largest negative number to negative infinity and the smallest positive number to positive infinity
  double largestNegative = -INFINITY;
  double smallestPositive = INFINITY;
  // A variable for the temporary number we enter
  double input;

  std::cout << "Enter a sequence of real non-zero numbers (enter 0 to end):" << std::endl;

  // Read in the input numbers
  while (true) {
    std::cin >> input;

    // Check if we have reached the end of the input
    if (input == 0) {
      break;
    }

    // Update the largest negative number if necessary
    if (input < 0) {
      if (input > largestNegative) {
        largestNegative = input;
      }
    } else {
      // Update the smallest positive number if necessary
      if (input < smallestPositive) {
        smallestPositive = input;
      }
    }
  }

  // Print the result
  if (largestNegative != -INFINITY) {
    std::cout << "The largest negative number is: " << largestNegative << std::endl;
  } else if (smallestPositive != INFINITY) {
    std::cout << "The smallest positive number is: " << smallestPositive << std::endl;
  } else {
    std::cout << "There were no non-zero numbers entered." << std::endl;
  }

  return 0;
}
