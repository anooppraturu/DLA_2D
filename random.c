#include "random.h"

Real rand_u(void)
{
   return ((Real) rand()) / RAND_MAX;
}
