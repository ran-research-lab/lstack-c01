// Su nombre aqui


#include "Stack.h"
#include "LStack.h"
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************


int main() {
	LStack S(20);
	for(int i = 0; i < 10; i++) S.push(i*10);
    expect( S.toString() == "90 80 70 60 50 40 30 20 10 0 ");
  int ctr = 0;

  S.pop(); S.pop();
  expect( S.toString() == "70 60 50 40 30 20 10 0 ");

  expect(S.topValue() == 70);
  expect(S.pop() == 70);
  expect(S.topValue() == 60);

  S.push(42);
  expect( S.toString() == "42 60 50 40 30 20 10 0 ");


  assertionReport();
}
