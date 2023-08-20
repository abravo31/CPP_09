#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <stack>
# include <sstream>
# include <cmath>
# include <stdlib.h>

class RPN {
    public:
    //Constructor & Destructor
        RPN( const std::string input );
        RPN( const RPN& copy );
        ~RPN( void );
    
    //Assignement operator
        RPN&    operator = ( const RPN& src );

    //Member Functions
        void    evaluateRPN( void );

    //Getter
        int     getResult( void ) const;  

    private:
        std::string     _input;
        int             _result;
        std::stack<int> _operands;
};

std::ostream&	operator<<(std::ostream& o, const RPN& i);

#endif