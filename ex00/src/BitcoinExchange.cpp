#include "BitcoinExchange.hpp"

//Contructor & Destructor
BitcoinExchange::BitcoinExchange( void ){}
BitcoinExchange::~BitcoinExchange( void ){}

// Members function
void    BitcoinExchange::checkInput( const std::string& filename )
{
    // Try to find the last point in the file
    size_t dot = filename.find_last_of(".");
    if (dot == std::string::npos)
        throw std::runtime_error("No point found in the file name.");
    // Try to find extension "txt"
    std::string extension = filename.substr(dot + 1);
    if (extension != "txt")
        throw std::runtime_error("The extension is not <txt> format.");
    // See if file is openable 
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Impossible to open input file.");
    file.close();
}