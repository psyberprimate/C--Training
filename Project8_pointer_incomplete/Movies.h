#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.h"
#include <iostream>
#include <vector>

class Movies{
    private:
        std::vector <Movie> *collection;
    public:
        Movies();
        Movies(Movies &&source)noexcept;
        ~Movies();
        bool increment_watch(std::string name);
        bool add_movie(std::string name, std::string rating, int watch_count);
        void display() const;
        void welcome() const;
};


#endif //_MOVIES_H_