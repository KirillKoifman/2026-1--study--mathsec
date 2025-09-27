println("Cesar cipher's work demonstration\n--------------------------------------")
println("[!!!]Please, follow the instructions!")

alphabet::String = "абвгдежзийклмнопрстуфхцчшщъыьэюя "
alphabet_chars = collect(alphabet)
println("\nUsed alphabet(use symbols ONLY from the defined alphabet): ")
for (char_index, symbol) in enumerate(alphabet_chars)
    symbolCode = convert(Int32, symbol)
    print("$(symbol)[$(symbolCode)]{$(char_index-1)} ")
    if (char_index % 10) == 0
        println()
    end
end


print("\nEnter key: ")
key::Int32 = 5
println("Entered key: $(key)")


print("\nEnter password(without repeating symbols): ")
password::String = "пароль"
println("Entered password: $(password)")


print("\nEnter open message: ")
openMessage::String = "этаглавауспешнозавершена"
println("Entered open message: $(openMessage)")


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

encryptedMessage::String = encrypt()
println("\nEncrypted message: $(encryptedMessage)")

function decrypt()
    println("----DECRYPTING----")

    decryptedMessage::String = ""
    for symbol in encryptedMessage
        pos = findMessageSymbolPosition(symbol, alphabet_chars)
        print("$(symbol) - position: $(pos - 1)")

        # Шифрование
        decrypted_pos = (pos - 1 - key) % length(alphabet_chars)
        if decrypted_pos < 0
            decrypted_pos = length(alphabet_chars) + decrypted_pos
        end
        decrypted_symbol = alphabet_chars[decrypted_pos+1]
        decryptedMessage *= decrypted_symbol
        println("------> $(decrypted_symbol) - position: $(findMessageSymbolPosition(decrypted_symbol, alphabet_chars) - 1)")
    end
    return decryptedMessage
end

decryptedMessage::String = decrypt()
println("\nDecrypted message: $(decryptedMessage)")