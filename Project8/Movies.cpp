#include "Movies.h"
#include <iostream>
#include <algorithm>


Movies::Movies(){

}
Movies::~Movies(){

}
bool Movies::increment_watch(std::string name){
    for(Movie &Movie: collection){
        if(Movie.get_name() == name){
            //Movie *increment_watched;
            //this->increment_watch();
            Movie.increment_watched();
            return true;
        }
    }
    return false;
}
bool Movies::add_movie(std::string name, std::string rating, int watch_count){


    for(const Movie &Movie: collection){
        if (Movie.get_name() == name){
            return false;
        }

    }   
        Movie tmp {name, rating, watch_count};
        collection.push_back(tmp);
        return true;
}
void Movies::display() const{
//    int i = 0;
    std::cout << "----------------------------------------------" << std::endl;

    if(collection.size() == 0){
        std::cout << "Apology, nothing to display" << std::endl;
    }

    for (const Movie &Movie: collection){
//        if (Movie.get_name() != ""){
//            Movie.display();
//            i++;
            Movie.display();
    }  
    //if (i < 1)
    //std::cout << "Apology, nothing to display" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;    
}
void Movies::welcome() const{
    std::cout << "Welcome to the My top movie list!" << std::endl;
}