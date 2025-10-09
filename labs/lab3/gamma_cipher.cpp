#include <iostream>
#include <cstdint>
#include <map>

std::wostream& operator<<(std::wostream& out, const std::map<wchar_t, std::uint32_t>& alphabet)
{
    out << "Alphabet:\n";
    int i = 0;
    for (const auto& pair : alphabet)
    {
        out << '[' << pair.first << ']' << '{' << pair.second << '}' << '\t';
        if (++i % 10 == 0)
            out << '\n';
    }

    return out;
}

void printTextCodes(const std::wstring& enteredText, const std::map<wchar_t, std::uint32_t>& alphabet)
{
    for (const auto& symbol : enteredText)
    {
        std::wcout << alphabet.at(symbol) << '\t';
    }
}

int main()
{
    setlocale(LC_ALL, "");

    //Define an alphabet with use of map
    const wchar_t alphabetBeginSymbol = L'А';
    const wchar_t alphabetEndSymbol = L'Я';
    const int alphabethLength = alphabetEndSymbol - alphabetBeginSymbol + 1;
    std::map<wchar_t, std::uint32_t> alphabet{};
    for (std::uint32_t symbol_index = 1; symbol_index <= alphabethLength; ++symbol_index)
    {
        alphabet.insert({ alphabetBeginSymbol + (symbol_index - 1), symbol_index });
    }
    std::wcout << alphabet << '\n';
    std::wcout << "Alphabet length: " << alphabethLength << '\n';

    //Define input open message
    std::wstring enteredMessage = L"ПРИКАЗ";
    size_t enteredMessageLength = enteredMessage.size();
    //std::wcin >> enteredMessage;
    std::wcout << "Entered message: " << enteredMessage << '\n';
    std::wcout << "Entered message(codes):\n";
    printTextCodes(enteredMessage, alphabet);
    std::wcout << '\n';

    //Define input gamma
    std::wstring enteredGamma = L"ГАММА";
    size_t enteredGammaLength = enteredGamma.size();
    //!std::wcin >> enteredGamma;
    std::wcout << "Entered gamma: " << enteredGamma << '\n';
    std::wcout << "Entered gamma(codes):\n";
    printTextCodes(enteredGamma, alphabet);
    std::wcout << '\n';

    //Perform encrypting (by applying gamma)
    std::wcout << "-----------------------------------ENCRYPTING-----------------------------------\n";
    std::wstring encryptedMessage;

    for (std::uint32_t symbol_index = 0; symbol_index < enteredMessageLength; ++symbol_index)
    {
        //ENCRYPTED_SYMBOL_CODE = ENTERED_MESSAGE_CODE + ENTERED_GAMMA % ALPHABET_LENGTH
        std::uint32_t encryptedSymbolCode = (alphabet.at(enteredGamma[symbol_index % enteredGammaLength]) +
            (alphabet.at(enteredMessage[symbol_index]) % alphabethLength)) % alphabethLength;

        for (auto& element : alphabet)
            if (element.second == encryptedSymbolCode)
            {
                encryptedMessage += element.first;
                break;
            }
    }

    std::wcout << "Encrypted message: " << encryptedMessage << '\n';
    std::wcout << "Encrypted message(codes):\n";
    printTextCodes(encryptedMessage, alphabet);
    std::wcout << '\n';
}