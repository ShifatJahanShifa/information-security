#include <iostream>
#include <bitset>
#include <string>

int main() {
    unsigned long long int value = 1;

    // Convert the value to a binary string
    std::string binaryString = std::bitset<64>(value).to_string();

    std::cout<<binaryString.size()<<"\n";
    // Pad the binary string to 8 characters
    if (binaryString.size() < 8) {
        binaryString = std::string(8 - binaryString.size(), '0') + binaryString;
    }

    // Now, binaryString contains an 8-character string representing the 64-bit value.
    std::cout << binaryString << std::endl;

    return 0;
}
