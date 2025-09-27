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