#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> vec1 {};
    vector <int> vec2 {};

    vec1.push_back(10);
    vec1.push_back(20);

    cout << "Vector 1 elements are: " << vec1.at(0) << " and " << vec1.at(1) << endl;
    cout << "Vector 1 size is: " << vec1.size() << endl;

    vec2.push_back(100);
    vec2.push_back(200);

    cout << "Vector 2 elements are: " << vec2.at(0) << " and " << vec2.at(1) << endl;
    cout << "Vector 2 size is: " << vec2.size() << endl;

    vector <vector <int>> vector_2d {};

    vector_2d.push_back(vec1);
    vector_2d.push_back(vec2);

    cout << "2d Vector elements of vector 1 are " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << " " << endl;
    cout << "2d Vector elements of vector 2 are " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << " " << endl;

    vec1.at(0) = 1000;

    cout << "\n2d Vector elements of vector 1 are " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << " " << endl;
    cout << "2d Vector elements of vector 2 are " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << " " << endl;

    cout << "Elements of vector 1 are " << vec1.at(0) << " " << vec1.at(1) << endl;

    return 0;
}
