---
marp: true
title: Marp
paginate: true
backgroundColor: grey
---

## Лабораторная работа №1
### Шифры простой замены
<br/>
дисциплина:  Математические основы защиты информации и информационной безопасности

Студент: Койфман Кирилл Дмитриевич
Группа: НФИмд-01-25

---

__Цель работы__
Получение практических навыков реализации алгоритмов, применяющих метод простой замены.

__Задачи__
1. Реализовать алгоритм шифрования Цезаря с произвольным ключом k
   
2. Реализовать алгоритм шифрования Атбаш

---
## 1 задание
Для решения задач данной работы - реализации 2-х алгоритмом шифрования применялся язык Julia:
```
function findMessageSymbolPosition(symbol::Char, chars::Vector{Char})
    for char_index in 1:length(chars)
        #print("$(chars[char_index])?=$(symbol)\n")
        if chars[char_index] == symbol
            return char_index
        end
    end
    return -1
end

function encrypt()
    println("----ENCRYPTING----")
    encryptedMessage::String = ""
    for symbol in openMessage
        pos = findMessageSymbolPosition(symbol, alphabet_chars)
        print("$(symbol) - position: $(pos - 1)")

        encrypted_pos = (pos - 1 + key) % length(alphabet_chars)
        encrypted_symbol = alphabet_chars[encrypted_pos+1]
        encryptedMessage *= encrypted_symbol
        println("------> $(encrypted_symbol) - position: $(findMessageSymbolPosition(encrypted_symbol, alphabet_chars) - 1)")
    end
    return encryptedMessage
end
```
---
## 1 задание
```
Cesar cipher's work demonstration
--------------------------------------
[!!!]Please, follow the instructions!

Used alphabet(use symbols ONLY from the defined alphabet): 
а[1072]{0} б[1073]{1} в[1074]{2} г[1075]{3} д[1076]{4} е[1077]{5} ж[1078]{6} з[1079]{7} и[1080]{8} й[1081]{9} 
к[1082]{10} л[1083]{11} м[1084]{12} н[1085]{13} о[1086]{14} п[1087]{15} р[1088]{16} с[1089]{17} т[1090]{18} у[1091]{19} 
ф[1092]{20} х[1093]{21} ц[1094]{22} ч[1095]{23} ш[1096]{24} щ[1097]{25} ъ[1098]{26} ы[1099]{27} ь[1100]{28} э[1101]{29} 
ю[1102]{30} я[1103]{31}  [32]{32} 
Enter key: Entered key: 5

Enter password(without repeating symbols): Entered password: пароль

Enter open message: Entered open message: этаглавауспешнозавершена
----ENCRYPTING----
э - position: 29------> б - position: 1
т - position: 18------> ч - position: 23
а - position: 0------> е - position: 5
г - position: 3------> и - position: 8
л - position: 11------> р - position: 16
а - position: 0------> е - position: 5
в - position: 2------> з - position: 7
а - position: 0------> е - position: 5
у - position: 19------> ш - position: 24
с - position: 17------> ц - position: 22
п - position: 15------> ф - position: 20
е - position: 5------> к - position: 10
ш - position: 24------> э - position: 29
н - position: 13------> т - position: 18
о - position: 14------> у - position: 19
з - position: 7------> м - position: 12
а - position: 0------> е - position: 5
в - position: 2------> з - position: 7
е - position: 5------> к - position: 10
р - position: 16------> х - position: 21
ш - position: 24------> э - position: 29
е - position: 5------> к - position: 10
н - position: 13------> т - position: 18
а - position: 0------> е - position: 5

Encrypted message: бчеирезешцфкэтумезкхэкте
```

---
## 2 задание
```
function findMessageSymbolPosition(symbol::Char, alphabet_chars::Vector{Char})
    for char_index in 1:length(alphabet_chars)
        if alphabet_chars[char_index] == symbol
            return char_index
        end
    end
end


function encrypt()
    println("----ENCRYPTING----")

    encryptedMessage::String = ""
    for symbol in openMessage
        pos = findMessageSymbolPosition(symbol, alphabet_chars)
        print("$(symbol) - position: $(pos - 1)")

        encrypted_pos = (pos - 1 + key) % length(alphabet_chars)
        encrypted_symbol = alphabet_chars[encrypted_pos + 1]
        encryptedMessage *= encrypted_symbol
        println("------> $(encrypted_symbol) - position: $(findMessageSymbolPosition(encrypted_symbol, alphabet_chars) - 1)")
    end
    return encryptedMessage
end
```
---
## 2 задание
```
Atbash cipher's work demonstration
--------------------------------------
[!!!]Please, follow the instructions!

Used alphabet(use symbols ONLY from the defined alphabet): 
а[1072]{0} б[1073]{1} в[1074]{2} г[1075]{3} д[1076]{4} е[1077]{5} ж[1078]{6} з[1079]{7} и[1080]{8} й[1081]{9} 
к[1082]{10} л[1083]{11} м[1084]{12} н[1085]{13} о[1086]{14} п[1087]{15} р[1088]{16} с[1089]{17} т[1090]{18} у[1091]{19} 
ф[1092]{20} х[1093]{21} ц[1094]{22} ч[1095]{23} ш[1096]{24} щ[1097]{25} ъ[1098]{26} ы[1099]{27} ь[1100]{28} э[1101]{29} 
ю[1102]{30} я[1103]{31}  [32]{32} 
Enter key: Entered key: 32

Enter open message: Entered open message: этаглавауспешнозавершена
----ENCRYPTING----
э - position: 29------> ь - position: 28
т - position: 18------> с - position: 17
а - position: 0------>   - position: 32
г - position: 3------> в - position: 2
л - position: 11------> к - position: 10
а - position: 0------>   - position: 32
в - position: 2------> б - position: 1
а - position: 0------>   - position: 32
у - position: 19------> т - position: 18
с - position: 17------> р - position: 16
п - position: 15------> о - position: 14
е - position: 5------> д - position: 4
ш - position: 24------> ч - position: 23
н - position: 13------> м - position: 12
о - position: 14------> н - position: 13
з - position: 7------> ж - position: 6
а - position: 0------>   - position: 32
в - position: 2------> б - position: 1
е - position: 5------> д - position: 4
р - position: 16------> п - position: 15
ш - position: 24------> ч - position: 23
е - position: 5------> д - position: 4
н - position: 13------> м - position: 12
а - position: 0------>   - position: 32
```
---
## Спасибо за внимание!