#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//Function declations
void print_menu();
void select_menu(char &input, std::vector<int> &v);
void print_numbers(const std::vector<int> &v); 
void add_numbers(std::vector<int> &v); //std::vector<int> 
void mean_numbers(const std::vector<int> &v);
void display_small(const std::vector<int> &v);
void display_large(const std::vector<int> &v);
double calculate_mean(const std::vector<int> &v);
void find_number(const std::vector<int> &v);
bool find(const std::vector<int> &v, int target);


int main(){

    std::vector<int> vect{};
    char input{};
    
    do{
        print_menu();
        select_menu(input, vect);
    } while(input != 'Q' and input != 'q');
    std::cout << "Goodbye" << std::endl;

    return 0;
}

void print_menu(){
            std::cout << "\nWelcome!\n"
                  << "Enter commands: \n"
                  << "P - Print numbers\n"
                  << "A - Add a number\n"
                  << "M - Display mean of the numers\n"
                  << "S - Display the smallest number\n"
                  << "L - Display the largest number\n"
                  << "F - Find a number\n"
                  << "Q - Quit\n"
                  << std::endl;
}

void select_menu(char &input, std::vector<int> &v){
            std::cin >> input;

        if (input == 'P' || input == 'p'){
            print_numbers(v);
        }
        if (input == 'A' || input == 'a'){
            add_numbers(v);
        }
        if (input == 'M' || input == 'm'){
            mean_numbers(v);
        }
        if (input == 'S' || input == 's'){
            display_small(v);
        }
        if (input == 'L' || input == 'l'){
            display_large(v);
        }
        if (input == 'F' || input == 'f'){
            find_number(v);
        }
}

void print_numbers(const std::vector<int> &v){
    if(v.size() != 0){
        std::cout << "[ ";
        for (int i: v){
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }
    else{
        std::cout << "[] - The list is empty" << std::endl << std::endl;
    }
} 

void add_numbers(std::vector<int> &v){
    int number{0};
    std::cout << "Enter a number: " << std::endl;
    std::cin >> number;
    v.push_back(number);
    std::cout << "Number " << number << " added " << std::endl << std::endl;
    //return v;
}

void mean_numbers(const std::vector<int> &v){
    if(v.size() != 0){
        std::cout << "The mean value of the elements of the list is: " << calculate_mean(v) << std::endl << std::endl;
    }
    else{
        std::cout << "[] - The list is empty" << std::endl << std::endl;
    }
}

double calculate_mean(const std::vector<int> &v){
        int sum{};
        for(int i: v){
            sum += i;
        }
        return static_cast <double> (sum)/v.size();
}

void display_small(const std::vector<int> &v){
    if(v.size() != 0){
        std::cout << "The smallest element within the array is: " << *min_element(v.begin(), v.end()) << std::endl << std::endl;
    }
    else{
        std::cout << "Unable to determine the smallest number - the list is empty" << std::endl;
    }
}

void display_large(const std::vector<int> &v){
    if(v.size() != 0){
        std::cout << "The largest element within the array is: " << *max_element(v.begin(), v.end()) << std::endl << std::endl;
    }
    else{
        std::cout << "Unable to determine the largest number - the list is empty" << std::endl << std::endl;
    }
}

void find_number(const std::vector<int> &v){
    int target{};
    std::cout << "Enter a number to find: " << std::endl << std::endl;
    std::cin >> target;
    if (find(v, target))
        std::cout << target << " was found" << std::endl << std::endl;
    else
        std::cout << target << " was not found" << std::endl << std::endl;    
}

bool find(const std::vector<int> &v, int target){
    for(int num: v){
        if (num == target){
            return true;
        }
    }
    return false;
}