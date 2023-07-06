#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){

    std::string message {};
    std::string encryptedMessage{}; 
    std::string key {"QWERasdfZXCVtyuiGHJbnmOPKLqwerASDFzxcvTYUIghjBNMopkl"};
    std::string alphabets {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};


    do{
        std::cout << "Welcome to message decryper!\n\n" << "Enter a message; press enter to confirm the message." << std::endl;

        std::getline(std::cin, message);

        std::cout << "Message entered. Decrypting message...\n\n" << "---------------------\n";
        for (char c: message){
            size_t data = alphabets.find(c);
            if (data != std::string::npos){
                char new_char {key.at(data)};
                encryptedMessage += new_char;
            }
            else{
                encryptedMessage += c;
            }

        }
        std::cout << "Decryption is complete!" << "\n---------------------\n";
        std::cout << encryptedMessage << std::endl;
        message = {};
        for (char c: encryptedMessage){
            size_t data = key.find(c);
            if (data != std::string::npos){
                char new_char {alphabets.at(data)};
                message += new_char;
            }
            else{
                message += c;
            }

        }
        std::cout << "Your message translation is complete! \n" << "---------------------\n";
        std::cout << "Your message is: " << message << std::endl;
        std::cout << std::endl;
    } while(message != "exit");
    return 0;
}