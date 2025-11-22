#include <iostream>
#include <cmath>

namespace functions
{
    long long function_with_compression_behavior_1(long long x, long long n)
    {
        return static_cast<long long>(std::pow(x, 2) + 5) % n;
    }
}

using compressing_function_t = long long(*)(long long, long long);

long long algorithmEuclid(long long a, long long b)
{
    if (b > a)
        std::swap(a, b);

    if (a <= 0 || b <= 0)
        return 1;

    long long d = 0;
    long long gamma_prev = a;
    long long gamma_curr = b;
    long long gamma_next = 0;

    while (true)
    {
        long long remainder = gamma_prev % gamma_curr;
        gamma_next = remainder;

        if (gamma_next == 0)
        {
            d = gamma_curr;
            break;
        }
        else
        {
            gamma_prev = gamma_curr;
            gamma_curr = gamma_next;
        }
    }

    return d;
}

int algorithmPollard(long long n, long long c = 1, compressing_function_t function = functions::function_with_compression_behavior_1)
{
    long long a = c;
    long long b = c;
    long long d = 0;

    std::cout << "|a\tb\td|\n--------------------------------------\n";

    while (true)
    {
        a = function(a, n);
        b = function(b, n);
        b = function(b, n);

        d = algorithmEuclid(std::abs(a - b), n);

        std::cout << a << '\t' << b << '\t' << d << '\n';

        if (d > 1 && d < n)
        {
            return d;
        }
        else if (d == n)
        {
            return -1;
        }
        else if (d == 1)
        {
            continue;
        }
    }
}

int main()
{

    long long chosenValue = 1'359'331;
    long long result = algorithmPollard(chosenValue);
    std::cout << "Chosen value: " << chosenValue << '\n';
    if (result > 0)
    {
        std::cout << "\nDivider = " << result << std::endl;
        std::cout << "Result tests: \n[1]" << chosenValue << " / " << result << " = " << chosenValue / result
            << "\n[2]" << result << " * " << chosenValue / result << " = " << result * (chosenValue / result) << std::endl;
    }
    else
    {
        std::cout << "\nDivider was not found!" << std::endl;
    }

    return 0;
}