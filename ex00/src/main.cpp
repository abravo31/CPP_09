#include "BitcoinExchange.hpp"

int main ( int ac, char** av ){
    try
    {
        if (ac == 2){
            BitcoinExchange test;
            test.checkInput(av[1]);
        } else 
            std::cout << "Ivalid Args : try with <./btc> & <filename>" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << '\n';
    }
    return 0;
}