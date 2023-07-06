#include <iostream>
#include "Movies.h"

//Function prototype
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watch_times);

int main(){
    Movies movies_obj;

    movies_obj.welcome();
    movies_obj.display();

    add_movie(movies_obj, "Big", "PG-13", 2);
    add_movie(movies_obj, "Star Wars", "PG", 5);
    add_movie(movies_obj, "Cinderella", "PG", 7);

    movies_obj.display();

    add_movie(movies_obj, "Cinderella", "PG", 7);
    add_movie(movies_obj, "Ice Age", "PG", 12);

    movies_obj.display();

    increment_watched(movies_obj, "Big");
    increment_watched(movies_obj, "Ice Age");

    movies_obj.display();

    increment_watched(movies_obj, "XXX");

    return 0;
}

void increment_watched(Movies &movies, std::string name){
    if (movies.increment_watch(name)){
        std::cout << name << " watch incremented" << std::endl;
    }
    else {
        std::cout << name << " not found" << std::endl;
    }

}

void add_movie(Movies &movies, std::string name, std::string rating, int watch_times){
    if (movies.add_movie(name, rating, watch_times)) {
        std::cout << name << " was added to the list" << std::endl;
    }
    else{
        std::cout << name << " already exists" << std::endl;
    }
}