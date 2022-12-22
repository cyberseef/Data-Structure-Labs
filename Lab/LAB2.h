#pragma once
#include<iostream>
#include<string.h>
#include<cmath>

template<typename T>
T Add(T x, T y)
{
	return x + y;
}

template<typename T>
T Add(T *x, T *y)
{
    for (i = 0; i <= 3; i++)
    {
        T add[i] = x[i] + y[i];
        return add;
    }
}

template<typename T>
T Sub(T x, T y)
{
	return x - y;
}

template<typename T>
T Div(T x, T y)
{
	return x / y;
}

template<typename T>
T Prime(T x)
{
    while (x % 2 == 0)
    {
        cout << 2 << " ";
        x = x / 2;
    }

    for (int i = 3; i <= sqrt(x); i = i + 2)
    {

        while (x % i == 0)
        {
            x = x / i;
        }
    }

    if (x > 2)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

template<typename T>
T Factorial(T x)
{
    T fact;
    if (x > 1)
    {
        return fact = x * Factorial(x - 1);
    }
    else
    {
        return fact;
    }
}

template<typename T>
T SQRT(T x)
{
    return sqrt(x);
}
