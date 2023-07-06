#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> vect{};
    // Variables
    char input{};
    int number{0};

    do
    {
        std::cout << "\nWelcome!\n"
                  << "Enter commands: \n"
                  << "P - Print numbers\n"
                  << "A - Add a number\n"
                  << "M - Display mean of the numers\n"
                  << "S - Display the smallest number\n"
                  << "L - Display the largest number\n"
                  << "Q - Quit\n"
                  << std::endl;
        std::cin >> input;

        if (input == 'P' || input == 'p')
        { // Print list
            if (vect.size() != 0)
            {
                std::cout << "[ ";
                for (int i : vect)
                {
                    std::cout << i << " ";
                }
                std::cout << "]\n";
            }
            else
            {
                std::cout << "[] - the list is empty\n";
            }
        }
        else if (input == 'A' || input == 'a')
        { // Add a number
            std::cout << "Enter a number: ";
            std::cin >> number;
            vect.push_back(number);
            std::cout << "Number " << number << " added" << std::endl;
        }
        else if (input == 'M' || input == 'm')
        {
            if (vect.size() != 0)
            {
                int sum{0};
                double average{0};
                for (int i = 0; i < vect.size(); ++i)
                {
                    std::cout << sum << std::endl;
                    sum += vect.at(i);
                }
                average = (double)sum / (double)vect.size();
                std::cout << "The mean value of the elements of the list is: " << average << std::endl;
            }
            else
            {
                std::cout << "Unable to calculate the mean - no data available in the list" << std::endl;
            }
        }
        else if (input == 'S' || input == 's')
        {
            if (vect.size() != 0)
            {
                std::cout << "The smallest element within the list is: " << *min_element(vect.begin(), vect.end()) << std::endl;
            }
            else
            {
                std::cout << "Unable to determine the smallest number - the list is empty" << std::endl;
            }
        }
        else if (input == 'L' || input == 'l')
        {
            if (vect.size() != 0)
            {
                std::cout << "The largest element within the list is: " << *max_element(vect.begin(), vect.end()) << std::endl;
            }
            else
            {
                std::cout << "Unable to determine the largest number - the list is empty" << std::endl;
            }
        }
    } while (input != 'Q' and input != 'q');
    std::cout << "Goodbye" << std::endl;
    return 0;
}