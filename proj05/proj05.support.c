#include <stdio.h>

int convert(int input, unsigned int base, char cha[]){
  int result = 0;
  int index = 0;
  int positive = 0; // 0 = negative
  int value = 0;
  int temp_value = 0;
  char ch;
  int i =0;
  char temp_ch;

  if (base >= 2 && 36 >= base)
  {
    result = 1;
  }

  if (input ==0)
  {
    cha[1] = '0';
    cha[0] = '+';
    cha[3] = '\0';
    return result;

  }
  else
  {
    if (input < 0)
  	{
  		positive = 0;
      input = input * (-1);
  	}

    else
    {
      positive = 1;
    }

    if (result == 1)
    {
      while (input != 0)
      {
        value = input % base;
        temp_value = input / base;

        if ( 0 <= value && value <= 9 )
        {
          ch = value + '0';
        }

        else if ( 10 <= value && value <= 35 )
        {
          ch = value + 'A' - 10;
        }

        cha[index] = ch;
        input = temp_value;
        index++;
      }

      if (positive == 0)
        cha[index] = '-';

      else
        cha[index] = '+';


      while (i<index/2)
      {
        temp_ch = cha[i];
        cha[i] = cha[index];
        cha[index] = temp_ch;
        i++;
      }
    }

    else if(result == 0)
    {
      char ch[0];
      cha = ch;
    }


    cha[index+1] = '\0';
    return result;
  }
}
