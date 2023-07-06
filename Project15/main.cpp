// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "PrintException.h"

//using namespace std;

struct Student{
    std::string name;
    int score;
};

void ReadFile(Student &student, std::vector<Student> &student_list, const std::string &name_file);
void PrintResults(std::vector<Student> &student_list);
int CountScore(const std::string &answer, const std::string &correct_anwer);
double Average(const std::vector<Student> &student_list);

int main() {

    Student student;
    std::vector<Student> students_list;
    std::string file_name = "responses.txt";

    try {
        ReadFile(student, students_list, file_name);
        PrintResults(students_list);
    }
    catch(const PrintException &ex){
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "End of Program - Student Scoring - Good bye" << std::endl << std::endl;
    return 0;
}

void ReadFile(Student &student, std::vector<Student> &student_list, const std::string &name_file){

    std::string correct{};

    std::ifstream in_file;
    in_file.open(name_file);
    if(!in_file){
        std::cerr << "Problem reading the file" << std::endl;
        throw PrintException();
    }

    std::string text{};
    std::string answer{};

    in_file >> correct;
    std::cout << "Correct answer: " <<  correct << std::endl;
    std::cout << "Results by students: " << std::endl << std::endl;


    while (in_file >> text >> answer){
        std::cout << text << " " << answer << std::endl;
        student.score = CountScore(answer, correct);  
        student.name = text;      
        student_list.push_back(Student{student.name, student.score});
    }
    std::cout << std::endl << std::endl;    
}
int CountScore(const std::string &answer, const std::string &correct_answer){
    int points{0};
    for (int i = 0; i < 5; i++){
        if (answer[i] == correct_answer[i]){
            points++;
        }    
    }
    return points;
}
double Average(const std::vector<Student> &student_list){
    double average{0};
    int count{0};
    for (Student student: student_list){
        average += student.score;
        count++;
    }
    return average/count;
}
void PrintResults(std::vector<Student> &student_list){
    std::cout << "Student:" << std::setw(20) << "Score:" << std::endl;
    std::cout << std::setfill(' ');

    for (Student student: student_list){
        std::cout << std::setw(15) << std::left << student.name
         << std::setw(15) << std::right << student.score << std::endl << std::endl;
    }
    std::cout << std::setw(40) <<std::setfill('-') << "" <<std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(30) <<"Average student score: " << Average(student_list)<<std::endl;
}
