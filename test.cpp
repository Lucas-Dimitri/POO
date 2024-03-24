#include <iostream>
#include <string>

int main() {
    // Declare a string variable
    std::string greeting = "Hello, world!";

    // Print the string
    std::cout << greeting << std::endl;

    // Append to the string
    greeting += " How are you?";
    std::cout << greeting << std::endl;

    // Get the length of the string
    std::cout << "Length of the string: " << greeting.length() << std::endl;

    // Access individual characters
    std::cout << "First character: " << greeting[0] << std::endl;

    // Iterate over the string
    for (char c : greeting) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // Find a substring
    size_t pos = greeting.find("world");
    if (pos != std::string::npos) {
        std::cout << "Substring found at position " << pos << std::endl;
    } else {
        std::cout << "Substring not found" << std::endl;
    }

    return 0;
}
