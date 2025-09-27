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

decryptedMessage = decrypt(encryptedMessage)
println("\nDecrypted message: $(decryptedMessage)")