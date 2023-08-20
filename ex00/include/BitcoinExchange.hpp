#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <cstdlib>
# include <map>
# include <sstream>

class BitcoinExchange{
    public :
    //Contructors
        BitcoinExchange( const std::string& filename );
        BitcoinExchange( const BitcoinExchange& copy );
        ~BitcoinExchange( void );
    
    // Assignement operator
        BitcoinExchange&    operator = ( const BitcoinExchange& src );

    // Members function
        void    checkInput( void );
        void    processFile( void );

    private:

        void    parseExchangeFile( void );
        float   walletValue( const std::string targetDate );

        const std::string               _fileName;
        const std::string               _databaseFile;
        std::map<std::string, double>   _exchangeRates;
};

#endif