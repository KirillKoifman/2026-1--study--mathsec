#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
#include <vector>

int generateRandomInteger(int min, int max)
{
    static std::mt19937 generator(static_cast<unsigned int>(time(NULL)));
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);

    //return rand() % (max - min + 1) + min;
}

int power(int base, int exp)
{
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base;
    
    int init_base = base;
    for (int i = exp; i > 1; --i)
        base *= init_base;

    return base;
}
namespace IsPrime
{
    bool FermTest(int n)
    {
        if (n < 5)
            return false;
        if (n % 2 == 0)
            return false;

        //take random number in [2, n - 2]
        int a = generateRandomInteger(2, n - 2);

        int gamma = static_cast<int>(std::pow(a, n - 1)) % n;

        return gamma == 1 ? true : false;
    }

    int JacobiSymbolAlgo(int n, int a)
    {
        int g = 1;

        while (true)
        {
            if (a == 0)
                return 0;
            if (a == 1)
                return g;

            int k = 0;
            int a1 = a;
            while (a1 % 2 == 0)
            {
                a1 /= 2;
                k++;
            }

            int s = 1;
            if (k % 2 != 0)
            {
                if ((n - 1) % 8 == 0 || (n + 1) % 8 == 0)
                {
                    s = 1;
                }
                else if ((n - 3) % 8 == 0 || (n + 3) % 8 == 0)
                {
                    s = -1;
                }
            }

            if (a1 == 1)
                return g * s;

            if ((n - 3) % 4 == 0 && (a1 - 4) % 3 == 0)
            {
                s = -s;
            }

            a = n % a1;
            n = a1;
            g = g * s;
        }
    }

    bool SolovayShtrassenTest(int n)
    {
        if (n < 5)
            return false;
        if (n % 2 == 0)
            return false;

        int a = generateRandomInteger(2, n - 2);

        int gamma = static_cast<int>(std::pow(a, (n - 1) / 2.0)) % n;

        if (gamma != 1 && gamma != n - 1)
            return false;

        int s = JacobiSymbolAlgo(n, a);

        if ((gamma - s) % n == 0)
            return false;
        else
            return true;
    }

    bool MillerRabinTest(int n)
    {
        if (n < 5)
            return false;
        if (n % 2 == 0)
            return false;

        int a = generateRandomInteger(2, n - 2);

        int gamma = static_cast<int>(std::pow(a, (n - 1) / 2.0)) % n;

        if (gamma != 1 && gamma != n - 1)
            return false;

        int s = JacobiSymbolAlgo(n, a);

        if ((gamma - s) % n == 0)
            return false;
        else
            return true;
    }
}

int main()
{
    std::cout << "-----------------------------------------------TESTING THE PRIMINESS OF INTEGERS[]-----------------------------------------------\n";
    std::vector<int> testing_integers{47, 101 , 13, 7, 23, 59, 811};
    //0 <= a < n
    int a = 3;

    int test_value_index = 0;
    for (const auto& value : testing_integers)
    {
        std::cout << "\n[" << ++test_value_index << "]Checking value: " << value;


        bool FermTestResult = IsPrime::FermTest(value);
        std::cout << "\nFerm\'s Test: " << value;
        FermTestResult == true ? std::cout << " is PROBABLY prime!" : std::cout << " is NOT prime!";

        //std::cout << "\nJacobi symbol test: " << IsPrime::JacobiSymbolAlgo(value, a) << " with a=" << a;

        bool SolovayShtrassenTestResult = IsPrime::SolovayShtrassenTest(value);
        std::cout << "\nSolovay-Shtrassen\'s Test: " << value;
        SolovayShtrassenTestResult == true ? std::cout << " is prime!" : std::cout << " is NOT prime!";
        std::cout << '\n';
    }
    std::cout << std::endl;
    return 0;
}