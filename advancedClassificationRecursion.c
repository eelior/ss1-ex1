#include <math.h>
#include "NumClass.h"

int getNumLen(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return 1 + getNumberLength(num / 10);
}

int getArmstrongSum(int numLength, int num)
{
    if (num == 0)
    {
        return 0;
    }
    return pow((num % 10), numLength) + getArmstrongSum(numLength, num / 10);
}

int isArmstrong(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    int count = getNumLen(num);
    if (num == getArmstrongSum(count, num))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getReversedNum(int num, int reversedNum)
{
    if (num == 0)
    {
        return reversedNum;
    }
    return (getReversedNum(num / 10, (reversedNum * 10) + (num % 10)));
}

int isPalindrome(int num)
{

    if (getReversedNum(num, 0) == num)
    {
        return 1;
    }

    return 0;
}