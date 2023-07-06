// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

template <typename T>
void display(const std::deque<T> &d){
    std::cout << "[";
    for (const char &elemt: d)
        std::cout << elemt << " ";
    std::cout << "]" << std::endl;    
}
bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> deQueFront{};
    std::deque<char> deQueBack{}; // NOT needed when not using the comparison with char only

    //deQueFront.push_front('a');
    for(const int elemt: s){
        //s.at(elemt) will lead to out of bounds error since 

        // if( (s[elemt] >= 'a' && s[elemt] <= 'z' ) || (s[elemt] >= 'A' && s[elemt] <= 'Z') ){
        //      deQueFront.push_front(std::toupper(elemt));
        //      deQueBack.push_back(std::toupper(elemt)); // NOT needed when not using the comparison with char only
        // }
        //// OR more efficient
        if(std::isalpha(elemt)){
            deQueFront.push_front(std::toupper(elemt));
            deQueBack.push_back(std::toupper(elemt)); // NOT needed when not using the comparison with char only
        }
    }
    if(deQueFront == deQueBack){ // needed when using the comparison with deque only
        return true;
    }
    else{
        return false;
    }
    /*
    // Needed with when using only 1 deque -> deQueFront only!
    char c1 {}, c2 {};
    while(deQueFront.front() > 1){
        c1 = deQueFront.front();
        c2 = deQue.Front.back();
        deQueFront.pop_front();
        deQueFront.pop_back();
        if(c1 != c2)
            return false;
    }
    return true;
    */
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome", "MEGALOLAGEM"};
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
} 