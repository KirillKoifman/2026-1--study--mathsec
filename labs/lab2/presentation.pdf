---
marp: true
title: Marp
paginate: true
backgroundColor: grey
---

## Лабораторная работа №2
### Шифры перестановки
<br/>
дисциплина:  Математические основы защиты информации и информационной безопасности

Студент: Койфман Кирилл Дмитриевич
Группа: НФИмд-01-25

---

__Цель работы__
Получение практических навыков реализации алгоритмов, применяющих метод перестановки.

__Задачи__
1. Реализовать алгоритм маршрутного шифрования
   
2. Реализовать алгоритм шифрования Виженера

---
## 1 задание
Для решения задач данной работы - реализации алгоритмов шифрования применялся язык Julia:
```
function encrypt()
    encrypted_message = ""

    #access password symbol culumn
    for col_idx in password_order
        #collect each symbol from the password symbol column 
        for row in 0:(parm_m-1)
            index = row * parm_n + col_idx
            if index <= length(openMessage_chars)
                encrypted_message *= openMessage_chars[index]
            end
        end
    end

    return encrypted_message
end
```
---
## 1 задание
```
Route cipher's work demonstration
--------------------------------------
[!!!]Please, follow the instructions!

Enter open message: Entered open message: нельзянедооцениватьпротивника

Enter parameter n: Entered parameter n value: 6
The source message was added extra symbols: нельзянедооцениватьпротивникаа
Parameter m value: 5

Enter password(without repeating symbols & must equals parm-n): Entered password: пароль
Columns order: [2, 5, 4, 1, 3, 6]
Encrypted message: еенпнзоатаьовокннеьвлдирияцтиа
```

---
## 2 задание
```
function create_shifted_matrix_detailed()
    n = length(alphabet_chars)
    matrix = Array{Char}(undef, n, n)

    println("Shifted symbols matrix:")
    for i in 1:n
        shift = i - 1
        #print("Строка $i (сдвиг $shift):\t")

        for j in 1:n
            original_index = j
            shifted_index = ((j - 1) + shift) % n + 1
            matrix[i, j] = alphabet_chars[shifted_index]

            #print("$(alphabet_chars[shifted_index]) ")
        end
        #println()
    end

    return matrix
end

function encrypt()
    password_message_char_matrix = Array{Char}(undef, strings, columns)

    for i in 1:strings
        for j in 1:columns
            if i == 1
                index = ((j - 1) % length(password_chars)) + 1
                password_message_char_matrix[i, j] = password_chars[index]
                #print("$(password_message_char_matrix[i, j]) ")
            elseif i == 2
                password_message_char_matrix[i, j] = openMessage_chars[j]
                #print("$(password_message_char_matrix[i, j]) ")
            end
        end
        #println()
    end

    encrypted_message::String = ""
    for index in 1:length(openMessage_chars)
        horizontal_alphabet_symbol = password_message_char_matrix[1, index]
        encrypting_string_symbol_index = 1
        for i in 1:length(alphabet_chars)
            if shifted_matrix[1, i] == horizontal_alphabet_symbol
                encrypting_string_symbol_index = i
            end
        end

        vertical_alphabet_symbol = password_message_char_matrix[2, index]
        encrypting_column_symbol_index = 1
        for i in 1:length(alphabet_chars)
            if shifted_matrix[1, i] == vertical_alphabet_symbol
                encrypting_column_symbol_index = i
            end
        end
        encrypted_message *= shifted_matrix[encrypting_string_symbol_index, encrypting_column_symbol_index]
        #print("$(shifted_matrix[encrypting_string_symbol_index, encrypting_column_symbol_index]) ")
    end
    encrypted_message_chars = collect(encrypted_message)

    return encrypted_message_chars
end
```
---
## 2 задание
```
Vizgener cipher's work demonstration
--------------------------------------
[!!!]Please, follow the instructions!

Enter password(without repeating symbols): Entered password: математика

Enter open message: Entered open message: криптографиясерьезнаянаука
Shifted symbols matrix:

Encrypted message: ['ц', 'р', 'ь', 'ф', 'я', 'о', 'х', 'ш', 'к', 'ф', 'ф', 'я', 'д', 'к', 'э', 'ь', 'ч', 'п', 'ч', 'а', 'л', 'н', 'т', 'ш', 'ц', 'а']

Decrypted message: ['к', 'р', 'и', 'п', 'т', 'о', 'г', 'р', 'а', 'ф', 'и', 'я', 'с', 'е', 'р', 'ь', 'е', 'з', 'н', 'а', 'я', 'н', 'а', 'у', 'к', 'а']
```
---
## Спасибо за внимание!