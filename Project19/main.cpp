// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
 #include <stdlib.h>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Currently playing: " << song << std::endl;
    //std::cout << "You implement this function"<< std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
   for (const Song &play : playlist){
        std::cout << play << std::endl;
   }
   std::cout << "Currently playing: " << current_song << std::endl;
    
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3},
            {"Ayayayayayayayaya", "Pillar Men",                5}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    std::string input{};
    std::string input2{};
    int input3{};
    char input_ctrl {};

    std::cout << "Welcome to the Radio SURF" << std::endl;
    
    do{
        display_menu();
        //std::getchar(std::toupper(input_ctrl));
        std::cin>>input_ctrl; 
        input_ctrl = std::toupper(input_ctrl);
        switch(input_ctrl){
            case 'F':
                current_song = playlist.begin();
                play_current_song(*current_song);
            break;
            case 'N':
                if(*current_song == playlist.back()){
                    current_song = playlist.begin();
                }
                // ++current_song;
                // if(current_song == playlist.end()){
                //     current_song = playlist.begin();
                // }
                else{
                    ++current_song;
                }
                play_current_song(*current_song);

            break;
            case 'P':
                if(*current_song == playlist.front()){
                    current_song = playlist.end();
                    --current_song;
                }
                // if(current_song == playlist.begin()){
                //     current_song = playlist.end();
                //     current_song--;
                // }
                else{
                    --current_song;
                }
                
                play_current_song(*current_song);
            break;
            case 'A':
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Adding and playing a new song" << std::endl;
                std::cout << "Enter song name: ";
                //std::cin >> input;
                std::getline(std::cin, input);
                std::cout << "Enter song artist: ";
                //std::cin >> input2;
                std::getline(std::cin, input2);
                std::cout << "Enter your rating (1-5): ";
                std::cin >> input3;
                playlist.emplace_front(input, input2, input3);
                play_current_song(*current_song);
            break;
            case 'L':
                display_playlist(playlist, *current_song);
            break;
            case 'Q':   
                std::cout << "Good bye" << std::endl;
                std::cout << "Thank you listening" << std::endl;
            default:
                std::cout << "Unknown command" << std::endl;
        }
    //input_ctrl = {};
    //system("CLS");
    }while(input_ctrl != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}