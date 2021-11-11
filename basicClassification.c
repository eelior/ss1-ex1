
#include "NumClass.h"
#include <math.h>

int isPrime(int n)
{
    if (n == 0)
    {
        return 0;
    }
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isStrong(int num)
{
    int res = 0;
    int currdigit, temp;
    temp = num;
    while (temp > 0)
    {
        int fact = 1;
        currdigit = temp % 10;
        temp = temp / 10;
        for (int i = 1; i <= currdigit; i++)
        {
            fact = fact * i;
        }
        res += fact;
    }
    if (res == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}