#include <stdio.h>
#include "simple_op.h"
#include "complex_op.h"
int main() {
int a=10, b=2;
printf("addition result : %d\n" , add(a,b));
printf("subtraction result : %d\n" , subtract(a,b));
printf("power result : %d\n" , power(a,b));
}
