

#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int times_watched) : name(name), rating(rating), times_watched(times_watched) {
}
//Copy constructor
Movie::Movie(const Movie &source) : Movie{source.name, source.rating, source.times_watched}{
}
Movie::~Movie(){
    //std::cout << " destructor called" << std::endl;
}
void Movie::display() const{
    std::cout << name << ", " << rating << ", " << times_watched << std::endl;
}