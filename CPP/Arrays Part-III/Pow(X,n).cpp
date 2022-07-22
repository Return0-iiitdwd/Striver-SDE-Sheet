// Link: - https://leetcode.com/problems/powx-n/

#include <iostream>
using namespace std;

// Approach: - 1 (Brute Force) Time: - O(n)
// Recursive - Space: - O(n)
class Solution
{
    double power(double x, long long exp)
    {
        if (exp == 0)
        {
            return 1;
        }

        return x * power(x, exp - 1);
    }

public:
    double myPow(double x, int n)
    {
        bool isNegative = false;
        long long exp = n;
        if (n < 0)
        {
            isNegative = true;
            exp = -1 * (long long)n;
        }

        double ans = power(x, exp);
        return isNegative ? 1 / ans : ans;
    }
};

// Iterative - Space: - O(n)
class Solution
{
public:
    double myPow(double x, int n)
    {
        bool isNegative = false;
        long long exp = n;
        if (n < 0)
        {
            isNegative = true;
            exp = -1 * (long long)n;
        }

        double ans = 1.0;
        for (int i = 0; i < exp; i++)
        {
            ans *= x;
        }
        return isNegative ? 1 / ans : ans;
    }
};

// Approach 2 : - (Binary Exponentiation) Time: - O(logn)
// Recursive - O(logn)
class Solution
{
    double power(double x, long long exp)
    {
        if (exp == 0)
        {
            return 1;
        }
        double fac = 1;
        if (exp % 2 != 0)
        {
            fac = x;
        }

        return fac * power(x * x, exp / 2);
    }

public:
    double myPow(double x, int n)
    {
        long long exp = abs(n);
        double ans = power(x, exp);
        return n < 0 ? 1 / ans : ans;
    }
};

// Iterative - O(1)
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long exp = abs(n);
        double ans = 1.0;
        while (exp > 0)
        {
            if (exp % 2 == 0)
            {
                x = x * x;
                exp /= 2;
            }
            else
            {
                ans *= x;
                exp--;
            }
        }
        return n < 0 ? 1 / ans : ans;
    }
};

// Bit Manipulate Space: - O(1)
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long exp = abs(n);
        double ans = 1.0;
        while (exp > 0)
        {
            int lastBit = (exp & 1);
            if (lastBit)
            {
                ans *= x;
            }
            x = x * x;
            exp = exp >> 1;
        }
        return n < 0 ? 1 / ans : ans;
    }
};