// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void PrintFunct(const Tours &tours, double withd);

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // Unformatted display so you can see how to access the vector elements
    // std::cout << std::setfill('-') <<std::setw(60)  << tours.title;
    // std::cout << std::left << std::setw(29)  << "-" <<std::endl;
    // std::cout << std::setfill(' ');
    // std::cout << std::right;

    // std::cout << std::setw(20) << "-Country-" << std::setw(20) << "-City-" << std::setw(20) << "-Population-" << std::setw(15) << "-Trip cost-" << std::endl << std::endl;
    // for(auto country : tours.countries) {   // loop through the countries
    //     std::cout << std::setw(12) << '-' <<country.name << '-'  << std::endl;
    //     for(auto city : country.cities) {       // loop through the cities for each country
    //         std::cout << std::setw(40) << std::right << city.name << ":" 
    //                       << std::setw(15) << city.population 
    //                       << std::setw(15) << city.cost 
    //                       << std::endl;
    //         std::cout << std::setfill(' ') << std::right << std::setw(50);
    //     }  
    //     std::cout << std::endl;
    // }
    PrintFunct(tours, 25);
    PrintFunct(tours, 35);
    std::cout << std::endl << std::endl;
    return 0;
}

void PrintFunct(const Tours &tours, double withd){
    std::cout << std::setfill('-') <<std::setw(((withd*4) - tours.title.length())/ 2)  << tours.title;
    std::cout << std::left << std::setw((((withd*4) - tours.title.length())/ 2)-tours.title.length())  << "" <<std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::right;

    std::cout << std::setw(withd*2/3) << "-Country-" << std::setw((withd*2/3)-8) << "-City-" << std::setw((withd*2/3)-7) << "-Population-" << std::setw((withd*2/3)-10) << "-Trip cost-" << std::endl << std::endl;
    for(auto country : tours.countries) {   // loop through the countries
        std::cout  << std::setw((withd*2/3)-8) <<"-" <<country.name << '-' << std::endl;
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(withd*2/3 + withd/2) << std::right << city.name << ":" 
                          << std::setw(withd*1/3) << city.population 
                          << std::setw(withd*1/3) << city.cost 
                          << std::endl;
            std::cout << std::setfill(' ') << std::right << std::setw(50);
            std::cout << std::right;
        }  
        std::cout << std::endl;
    }
}