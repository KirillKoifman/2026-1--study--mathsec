#include <iostream>
#include <array>

int algorithmEuclid(int a, int b)
{
    if (b > a)
        std::swap(a, b);
    
    //d=НОД(a, b)
    int d = 0;

    int gamma_prev = a;
    int gamma_curr = b;
    int gamma_next = 0;
    while (true)
    {
        int remainder = gamma_prev % gamma_curr;
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

int binaryAlgorithmEuclid(int a, int b)
{
    if (b > a)
        std::swap(a, b);
    
    //d=НОД(a, b)
    int d = 0;

    int g = 1;
    //until one in pair (a or b) becomes odd
    while (a % 2 == 0 && b % 2 == 0)
    {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
    }

    int u = a;
    int v = b;
    while (u != 0)
    {
        if (u % 2 == 0)
            u = u / 2;

        if (v % 2 == 0)
            v = v / 2;

        if (u >= v)
            u = u - v;
        else
            v = v - u;
    }
    d = g * v;

    return d;
}

struct EuclidAlgoVars
{
    int d, x, y;
};

EuclidAlgoVars extendedAlgorithmEuclid(int a, int b)
{
    bool swapXY = false;
    if (b > a)
    {
        swapXY = true;
        std::swap(a, b);
    }
        
    //a * x + b * y = d
    int d = 0;
    int x = 0;
    int y = 0;

    //gamma_0{i-1}
    int gamma_prev = a;
    //gamma_1{i}
    int gamma_curr = b;
    //gamma_{i+1}
    int gamma_next = 0;

    //x_0{i-1}
    int x_prev = 1;
    //x_1{i}
    int x_curr = 0;
    //x_{i+1}
    int x_next = 0;

    //y_0{i-1}
    int y_prev = 0;
    //y_1{i}
    int y_curr = 1;
    //y_{i+1}
    int y_next = 0;

    while (true)
    {
        int remainder = gamma_prev / gamma_curr;
        //q_i = remainder
        int q_curr = remainder;
        //gamma_{i+1} = gamma_{i-1} - q_i * gamma_i
        gamma_next = gamma_prev - q_curr * gamma_curr;

        if (gamma_next == 0)
        {
            d = gamma_curr;
            x = x_curr;
            y = y_curr;
            break;
        }
        else
        {
            x_next = x_prev - q_curr * x_curr;
            y_next = y_prev - q_curr * y_curr;

            gamma_prev = gamma_curr;
            gamma_curr = gamma_next;

            x_prev = x_curr;
            x_curr = x_next;

            y_prev = y_curr;
            y_curr = y_next;
        }
    }

    if (swapXY)
        std::swap(x, y);
    
    return EuclidAlgoVars{ d,x,y };
}

EuclidAlgoVars binaryExtendedAlgorithmEuclid(int a, int b)
{
    bool swapXY = false;
    if (b > a)
    {
        swapXY = true;
        std::swap(a, b);
    }
    //a * x + b * y = d
    int d = 0;
    int x = 0;
    int y = 0;

    int g = 1;
    //until one in pair (a or b) becomes odd
    while (a % 2 == 0 && b % 2 == 0)
    {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
    }

    int u = a;
    int v = b;
    int A = 1;
    int B = 0;
    int C = 0;
    int D = 1;

    while (u != 0)
    {
        if (u % 2 == 0)
        {
            u = u / 2;
            if (A % 2 == 0 && B % 2 == 0)
            {
                A = A / 2;
                B = B / 2;
            }
            else
            {
                A = (A + b) / 2;
                B = (B - a) / 2;
            }
        }

        if (v % 2 == 0)
        {
            v = v / 2;
            if (C % 2 == 0 && D % 2 == 0)
            {
                C = C / 2;
                D = D / 2;
            }
            else
            {
                C = (C + b) / 2;
                D = (D - a) / 2;
            }
        }

        if (u >= v)
        {
            u = u - v;
            A = A - C;
            B = B - D;
        }
        else
        {
            v = v - u;
            C = C - A;
            D = D - B;
        }
        
    }
    d = g * v;
    x = C;
    y = D;

    if (swapXY)
        std::swap(x, y);
    
    return EuclidAlgoVars{ d,x,y };
}


int main()
{
    std::cout << "[!]Note: a >= b\n";
    std::array<std::pair<int, int>, 6> integersPairs;
    integersPairs[0] = { 14, 21 };
    integersPairs[1] = { 48, 36 };
    integersPairs[2] = { 17, 51 };
    integersPairs[3] = { 75, 250 };
    integersPairs[4] = { 72, 120 };
    integersPairs[5] = { 81, 65 };

    std::cout << "--------------------------Testing GCD-algorithms--------------------------\n";
    for (int index = 0; index < integersPairs.size(); ++index)
    {
        int a = integersPairs[index].first;
        int b = integersPairs[index].second;
        std::cout << "TEST-" << index + 1 << ": a = " << a << ", b = " << b << '\n';
            
        std::cout << "Great Common Divisor(GCD) for pair{a=" << a << ", b=" << b << "} with [1]Euclid Algorithm: " << algorithmEuclid(a, b) << '\n';
        std::cout << "Great Common Divisor(GCD) for pair{a=" << a << ", b=" << b << "} with [2]Binary Euclid Algorithm: " << binaryAlgorithmEuclid(a, b) << '\n';
        auto result_1 = extendedAlgorithmEuclid(a, b);
        std::cout << std::boolalpha << "Great Common Divisor(GCD) for pair{a=" << a << ", b=" << b << "} with [3]Extended Euclid Algorithm: " << result_1.d << " with condition that a * x + b * y = d"
            << ", d = " << result_1.d << ", x = " << result_1.x << ", y = " << result_1.y << ":\n" << a << " * " << result_1.x << " + " << b << " * " << result_1.y
            << " = " << result_1.d << '(' << ((a * result_1.x + b * result_1.y) == result_1.d) << ')' << '\n';
        auto result_2 = binaryExtendedAlgorithmEuclid(a, b);
        std::cout << std::boolalpha << "Great Common Divisor(GCD) for pair{a=" << a << ", b=" << b << "} with [4]Binary Extended Euclid Algorithm: " << result_2.d << " with condition that a * x + b * y = d"
            << ", d = " << result_2.d << ", x = " << result_2.x << ", y = " << result_2.y << ":\n" << a << " * " << result_2.x << " + " << b << " * " << result_2.y
            << " = " << result_2.d << '(' << ((a * result_2.x + b * result_2.y) == result_2.d) << ')' << '\n';

        std::cout << std::endl;
    }
    
    return 0;
}