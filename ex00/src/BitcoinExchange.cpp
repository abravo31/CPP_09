#include "BitcoinExchange.hpp"

//Contructor & Destructor
BitcoinExchange::BitcoinExchange( const std::string& filename ) : _fileName(filename) {}
BitcoinExchange::~BitcoinExchange( void ){}

// Members function
void    BitcoinExchange::checkInput( void )
{
    // Try to find the last point in the file
    size_t dot = this->_fileName.find_last_of(".");
    if (dot == std::string::npos)
        throw std::runtime_error("No point found in the file name.");
    // Try to find extension "txt"
    std::string extension = this->_fileName.substr(dot + 1);
    if (extension != "txt")
        throw std::runtime_error("The extension is not <txt> format.");
    // See if file is openable 
    std::ifstream file(this->_fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("Impossible to open input file.");
    file.close();
}

bool isValidValue(const std::string& valueStr) {
    char* endPtr;
    double value = strtod(valueStr.c_str(), &endPtr);
    if (endPtr == valueStr.c_str() || *endPtr != '\0') {
        return false;
    }
    if (value < 0)
        throw std::runtime_error("not a positive number.");
    if (value > 1000)
        throw std::runtime_error("too large a number.");
    return (value >= 0 && value <= 1000);
}

bool isValidDate(const std::string& dateStr) {
    //std::cout << dateStr.length() << std::endl;
    if (dateStr.length() != 11) 
        return false;
    
    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    // Vérification des valeurs numériques
    for (int i = 0; i < 10; ++i) {
        if (i != 4 && i != 7 && !isdigit(dateStr[i])) 
            return false;
    }

    int year = atoi(dateStr.substr(0, 4).c_str());
    int month = atoi(dateStr.substr(5, 2).c_str());
    int day = atoi(dateStr.substr(8, 2).c_str());
    
    if (year < 2009 && year > 2023)
        throw std::runtime_error("Invalid year.");
    if (month == 0 || month > 12)
        throw std::runtime_error("Invalid month.");
    if (day == 0 || day > 31 || (month == 2 && day > 28))
        throw std::runtime_error("Invalid date.");
    return (true);
}


void BitcoinExchange::processFile( void ){

    std::string firstLine;
    std::ifstream file(this->_fileName.c_str());
    if (std::getline(file, firstLine)){
        if (firstLine != "date | value")
            throw std::runtime_error("The first line format is whrong please put <date | value> as the first line");
    }

    std::string line;
    while (std::getline(file, line)) {
        try{
            // Check line format
            size_t separatorPos = line.find("|");
            if (separatorPos == line.npos) {
                throw std::runtime_error("bad input => " + line);
            }

            std::string dateString = line.substr(0, separatorPos);
            std::string valueString = line.substr(separatorPos + 1);

            if (!isValidDate(dateString) || !isValidValue(valueString)) {
                throw std::runtime_error("Format de ligne incorrect : " + line);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
        }       
}