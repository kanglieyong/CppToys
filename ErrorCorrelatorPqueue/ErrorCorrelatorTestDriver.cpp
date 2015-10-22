#include "ErrorCorrelator.h"

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

using std::out_of_range;

int main()
{
  ErrorCorrelator ec;

  ec.addError(Error(3, "Unable to read file"));
  ec.addError(Error(1, "Incorrect entry user"));
  ec.addError(Error(10, "Unable to allocate memory"));

  while (true) {
    try {
      Error e = ec.getError();
      cout << e << endl;
    } catch (const out_of_range&) {
      cout << "Finished processing errors" << endl;
      break;
    }
  }

  return 0;
}