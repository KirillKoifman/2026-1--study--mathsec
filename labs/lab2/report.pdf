# РОССИЙСКИЙ УНИВЕРСИТЕТ ДРУЖБЫ НАРОДОВ

### Факультет физико-математических и естественных наук 

<br/>
<br/>
<br/>
<br/>

ОТЧЕТ
ПО ЛАБОРАТОРНОЙ РАБОТЕ №2
===============
## Тема:  Шифры перестановки
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
дисциплина:  Математические основы защиты информации и информационной безопасности

Студент: Койфман Кирилл Дмитриевич

Группа: НФИмд-01-25

<br/>
<br/>
<br/>
<br/>

## Введение
### Цель работы
Получение практических навыков реализации алгоритмов, применяющих метод перестановки.

### Задачи
1. Реализовать алгоритм маршрутного шифрования
2. Реализовать алгоритм шифрования Виженера

## Теория
Данный способ шифрования разработал французский математик Франсуа
Виет. Открытый текст записывают в некоторую геометрическую фигуру (обычно
прямоугольник) по некоторому пути, а затем, выписывая символы по другому
пути, получают шифртекст. Пусть m и n — целые положительные числа, большие
1. Открытый текст разбивается на блоки равной длины, состоящие из числа
символов, равному произведению mn. Если последний блок получится меньше
остальных, то в него следует дописать требуемое количество произвольных
символов. Составляется таблица размерности mn. Блоки вписывается построчно в
таблицу. Криптограмма получается выписыванием букв из таблицы в
соответствии с некоторым маршрутом. Ключом такой криптограммы является
маршрут и числа m и n. Обычно буквы выписывают по столбцам, которые
упорядочивают согласно паролю: внизу таблицы приписывается слово из n
неповторяющихся букв и столбцы нумеруются по алфавитному порядку букв пароля.

При работе шифра Виженера открытый текст разбивается на блоки длины n. Ключ представляет собой
последовательность из n натуральных чисел: а_1, а_2, ..., а_n. Далее в каждом блоке
первая буква циклически сдвигается вправо по алфавиту на а_1 позиций, вторая
буква — на а_2 позиций, последняя — на а_n позиций. Для лучшего запоминания в
качестве ключа можно взять осмысленное слово, а алфавитные номера входящих
в него букв использовать для осуществления сдвигов.

## Ход работы
### 1 задание
---
Для решения поставленной задачи - реализации алгоритма маршрутного шифрования воспользуемся языком Julia, чтобы написать скрипт, который будет выполнять шифрование вводимого сообщения по заданным параметрам алгоритма (Листинг-1):


```
println("Route cipher's work demonstration\n--------------------------------------")
println("[!!!]Please, follow the instructions!")

print("\nEnter open message: ")
openMessage::String = "нельзянедооцениватьпротивника"
println("Entered open message: $(openMessage)")
openMessage_chars = collect(openMessage)

print("\nEnter parameter n: ")
parm_n::Int32 = 6
println("Entered parameter n value: $(parm_n)")

if length(openMessage_chars) % parm_n != 0
    padding_needed = parm_n - (length(openMessage_chars) % parm_n)
    openMessageLastSymbol = openMessage_chars[length(openMessage_chars)]
    openMessage *= string(openMessageLastSymbol)^padding_needed
    openMessage_chars = collect(openMessage)
    println("The source message was added extra symbols: $openMessage")
end

parm_m::Int32 = length(openMessage_chars) ÷ parm_n
println("Parameter m value: $(parm_m)")


print("\nEnter password(without repeating symbols & must equals parm-n): ")
password::String = "пароль"
println("Entered password: $(password)")
password_chars = collect(password)


password_order = sortperm(password_chars)
println("Columns order: ", password_order)

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

result = encrypt()
println("Encrypted message: ", result)
```
<br/>*Листинг-1(фрагмент алгоритма, реализующего метод маршрутного шифрования)*

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
<br/>*Листинг-2(результаты работы алгоритма маршрутного шифрования)*

Исходя из полученных результатов (Листинг-2), можно судить о том, что данный алгоритм успешно провёл шифрование вводимого текста.

### 2 задание
---
Для реализации 2-го метода шифрования - метода Виженера, напишем алгоритм на языке Julia и проверим его работоспособность (Листинг-3, Листинг-4):
```
println("Vizgener cipher's work demonstration\n--------------------------------------")
println("[!!!]Please, follow the instructions!")

alphabet::String = "абвгдежзийклмнопрстуфхцчшщьыэюя"
alphabet_chars = collect(alphabet)
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

print("\nEnter password(without repeating symbols): ")
password::String = "математика"
println("Entered password: $(password)")
password_chars = collect(password)

print("\nEnter open message: ")
openMessage::String = "криптографиясерьезнаянаука"
println("Entered open message: $(openMessage)")
openMessage_chars = collect(openMessage)

shifted_matrix = create_shifted_matrix_detailed()

strings = 2
columns = length(openMessage_chars)
password_message_char_matrix = Array{Char}(undef, strings, columns)
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

function decrypt(encryptedMessage)
    decrypted_message::String = ""
    for index in 1:length(encryptedMessage)
        
        decrypted_symbol_vertical_index = 1
        for i in 1:length(alphabet_chars)
            if shifted_matrix[1, i] == password_chars[(index - 1) % length(password_chars) + 1]
                decrypted_symbol_vertical_index = i
                break
            end
        end

        decrypted_symbol_horizontal_index = 1
        for i in 1:length(alphabet_chars)
            if shifted_matrix[decrypted_symbol_vertical_index, i] == encryptedMessage[index]
                decrypted_symbol_horizontal_index = i
                break
            end
        end

        #print("$(shifted_matrix[1, decrypted_symbol_horizontal_index]) ")
        decrypted_message *= shifted_matrix[1, decrypted_symbol_horizontal_index]
    end
    decrypted_message_chars = collect(decrypted_message)


    return decrypted_message_chars
end

encryptedMessage = encrypt()
println("\nEncrypted message: $(encryptedMessage)")

decrypted_message = decrypt(encryptedMessage)
println("\nDecrypted message: $(decryptedMessage)")
```
<br/>*Листинг-3(фрагмент алгоритма, реализующего метод шифрования Виженера)*

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
<br/>*Листинг-4(результаты работы алгоритма шифрования Виженера)*

Исходя из полученных данных (Листинг-4), можно утверждать о том, что данный алгоритм успешно провёл шифрование вводимого текста, а позднее и дешифрование произведённого шифртекста.

## Заключение
В ходе проделанной лабораторной работы мной были усвоены знания по принципам работы с шифрами перестановки, а также получены навыки по их реализации.