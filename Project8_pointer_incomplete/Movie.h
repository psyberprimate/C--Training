#ifndef _MOVIE_H_
#define _MOVIE_H_


#include <string>

class Movie{
    private:
        std::string name;
        std::string rating;
        int times_watched;
    public:
        Movie(std::string name, std::string rating, int times_watched);
        //copy constructor
        Movie(const Movie &source);
        //destructor
        ~Movie();

        //setters and getters
        void set_name(std::string name) {this->name = name;}
        std::string get_name() const {return name;}

        void set_rating(std::string rating) {this->rating = rating;}
        std::string get_rating() const {return rating;}

        void set_times_watched(int times_watched) {this->times_watched = times_watched;}
        int get_times_watched() const {return times_watched;};

        void increment_watched(){++times_watched;}

        void display() const;

};


#endif //_MOVIE_H_