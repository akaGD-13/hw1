#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  for(int count = 0; count < 4; ++count)
	{
dat.push_back("test");
cout << dat.get(0) << endl;
dat.pop_back();

cout << dat.size() << endl << endl;;  // prints 3 since there are 3 strings stored
}
}
