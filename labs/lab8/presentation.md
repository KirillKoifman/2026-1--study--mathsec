---
marp: true
title: Marp
paginate: true
backgroundColor: #7c7b7bff
---

## Лабораторная работа №8
### Целочисленная арифметика многократной точности
<br/>
дисциплина:  Математические основы защиты информации и информационной безопасности

Студент: Койфман Кирилл Дмитриевич
Группа: НФИмд-01-25

---

__Цель работы__
Получение практических навыков реализации алгоритмов, выполняющих арифметические операции с большими целыми числами.

__Задачи__
1. Реализовать алгоритмы, выполняющие арифметические операции с большими целыми числами.
2. Протестировать работу реализованных алгоритмов.
  
---
## 1 задание
Для решения задачи данной работы была написана программа на C++, реализующая описанныные в работе алгоритмы:
```cpp
Value algorithm_1(const Value& u, const Value& v, int b){
    //define max number of digits
    int n = std::max(u.size(), v.size());
    //define the result value
    Value w(n + 1, 0);
    int k = 0;
    //main cycle
    for (int i = 0; i < n; ++i){
        int sum = k;
        if (i < u.size())
            sum += u[i];
        if (i < v.size())
            sum += v[i];
        w[i] = sum % b;
        k = sum / b;
    }
    w[n] = k;
    normalize(w);
    return w;
}
Value algorithm_2(const Value& u, const Value& v, int b){
    //define the result value and init borrow value
    Value w = u;
    int k = 0;
    //main cycle
    for (size_t i = 0; i < w.size(); ++i){
        w[i] -= k;
        if (i < v.size())
            w[i] -= v[i];
        if (w[i] < 0){
            k = 1;
            w[i] += b;
        }
        else
            k = 0;
    }
    normalize(w);
    return w;
}
```
---
## 1 задание
```cpp
Value algorithm_3(const Value& u, const Value& v, int b){
    //define sizes number of digits for each of two values
    int n = u.size();
    int m = v.size();
    //define result value
    Value w(n + m, 0);
    //main cycle
    for (int j = 0; j < m; ++j){
        if (v[j] == 0)
        {
            w[j] = 0;
            continue;
        }
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            int t = u[i] * v[j] + w[i + j] + k;
            w[i + j] = t % b;
            k = t / b;
        }
        w[n + j] = k;
    }
    normalize(w);
    return w;
}
Value algorithm_4(const Value& u, const Value& v, int b){
    //define sizes number of digits for each of two values
    int n = u.size();
    int m = v.size();
    //define result value
    Value w(n + m, 0);
    long long t = 0;
    //main cycle
    for (int s = 0; s < m + n; ++s)
    {
        for (int i = std::max(0, s - m + 1); i <= std::min(s, n - 1); ++i){
            int j = s - i;
            if (j >= 0 && j < m)
                t += (long long)u[i] * v[j];
        }
        w[s] = t % b;
        t /= b;
    }
    normalize(w);
    return w;
}
```
---
## 2 задание
Далее протестируем работу данных алгоритмов:
```cpp
---------------------------Testing basic arithmetic operations algorithms for big non-negative integers---------------------------
System base number b = 10
Value u = 253, value v = 941
u + v = 1194
v - u = 688
u * v (slow) = 238073
u * v (fast) = 238073
```
---
## Спасибо за внимание!