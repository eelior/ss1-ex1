#include <math.h>
#include "NumClass.h"

int digitsLen(int num)
{
    int counter = 0;
    while (num > 0)
    {
        num = num / 10;
        counter++;
    }
    return counter;
}

int isArmstrong(int num)
{
    int length = digitsLen(num);
    int lastDigit;
    int power;
    int sum = 0;
    int number = num;

    while (number > 0)
    {
        lastDigit = number % 10;
        power = pow(lastDigit, length);
        sum += power;
        number = number / 10;
    }
    if (sum == num)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(int num)
{
    int temp = 0;
    int remainder; 
    int originalNum = num;

    while (num != 0)
    {
        remainder = num % 10;
        temp = temp * 10 + remainder;
        num = num / 10;
    }
    if (num == originalNum)
    {
        return 1;
    }
    return 0;
}
