#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"
#include "/user/cse320/lib/bitlib.h"

float mult( float num_1, float num_2)
{
  union sp_item num_one;
  union sp_item num_two;
  union sp_item fraction;
  //  union sp_item temp;
  signed one_expo;
  signed two_expo;
  unsigned long long result;
  union production;
  //>>> true exponent
  num_one.frep = num_1;
  one_expo = ((num_one.irep >> 23) & 0xff) - 0x7f;
  if(one_expo == -0x3FE)
  {
    num_1 = 0;
    num_one.frep = 0;
  }
  num_two.frep = num_2;
  two_expo = ((num_two.irep >> 23) & 0xff) - 0x7f;
  if(two_expo == -0x3FE)
  {
    num_2 = 0;
    num_two.frep = 0;
  }
  float product;
  //if either operand is not-a-number, the result is not-a-number.
  if (num_one.irep == 0x7fc00000 || num_two.irep == 0x7fc00000)
  {
    product = NAN;
  }
  //If neither operand is not-a-number and either operand is infinity, the result is infinity.
  else if ((num_1 != 0x7fc00000 && num_2 != 0x7fc00000)
    && (num_1 == INFINITY || num_2 == INFINITY)){
    product = INFINITY;
  }

  //If neither operand is not-a-number nor infinity and either operand is zero, the result is zero.
  else if ((num_1 != 0x7fc00000 && num_2 != 0x7fc00000)
    && (num_1 != INFINITY && num_2 != INFINITY)
    && (num_1 == 0x00000000 || num_2 == 0x00000000)){
    product = 0x00000000;
  }
  //>>> after handling the special cases
  else
  {
    unsigned e = (num_one.irep & 0x7f800000) -0x3f800000 + (num_two.irep & 0x7f800000);
    result = (unsigned long long )((num_one.irep & 0x007fffff) + 0x00800000) *
    (unsigned long long )((num_two.irep & 0x007fffff) + 0x00800000);
    unsigned result_32 = (result>>24) & 0xffffff;
    unsigned test=0x00800000,n=0;
    while ((result_32 & test) != test){
        test>>=1;
        n++;
    }
    result_32<<=n;
    n<<=23;
    result_32 -= n;
    fraction.irep = result_32;
    //same sign(extract sign) always positive
    if ((num_one.irep >> 31) == (num_two.irep >> 31)){
      fraction.irep = 0x0  | (result_32  + e);
    }
    //different sign (always negative)
    else
    {
      fraction.irep = (0x80000000) | (result_32 + e);
    }
    if (e == 0x00000000 && fraction.irep == 0x00000000)//denormal
    {
      product = 0;
    }
    else //good
    {
      product = fraction.frep;
    }
  }
  return product;
}
