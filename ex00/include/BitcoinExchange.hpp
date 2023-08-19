#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <fstream>

class BitcoinExchange{
    public :
    //Contructor & Destructor
        BitcoinExchange( void );
        ~BitcoinExchange( void );

    // Members function
        void    checkInput( const std::string& filename );

};

#endif