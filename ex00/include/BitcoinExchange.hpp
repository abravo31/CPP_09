#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <cstdlib>

class BitcoinExchange{
    public :
    //Contructor & Destructor
        BitcoinExchange( const std::string& filename );
        ~BitcoinExchange( void );

    // Members function
        void    checkInput( void );
        void    processFile( void );

    private:
        const std::string   _fileName;  

};

#endif