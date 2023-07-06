#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


void print(const int* const array, const size_t &size);
int* apply_all(const int* array1, const size_t array1_size, const int* array2, const size_t array2_size);

int main(){

    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    std::cout << "Array1: " ;
    print(array1, array1_size);

    std::cout << "Array2: ";
    print(array2, array2_size);

    int* results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{array1_size * array2_size};

    std::cout << "Result: ";
    print(results, results_size);


    std::cout << std::endl;

    //delete [] results;
    return 0;
}

void print(const int* const array, const size_t &size){
    for (size_t i{0}; i < size; ++i){
        std::cout << *(array+i) << " ";  
    }
    std::cout << std::endl;
}
///*
int* apply_all(const int* array1, const size_t array1_size, const int* array2, const size_t array2_size){
    size_t new_size = array1_size * array2_size;
    int* new_array{nullptr};
    // std::cout << "new_size is: " << new_size;
    new_array = new int [new_size];

    for (size_t j {0}; j < array2_size; ++j){
        for (size_t i {0}; i < array1_size; ++i){
            // *(new_array + i + j*5) = *(array1+i) * *(array2+j); // pointer offset notation
            // new_array[i+j*5] = array1[i] * array2[j]; //pointer subscript
            /*if (j == 1){
                *(new_array + i + 5) = *(array1+i) * *(array2+j);
            }
            if (j == 2){
                *(new_array + i+ 10) = *(array1+i) * *(array2+j);
            }
            else{
                *(new_array + i) = *(array1+i) * *(array2);
            }*/
        }
        
    }
    return new_array;
}//*/