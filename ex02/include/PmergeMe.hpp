#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <iostream>
# include <list>

class PmergeMe {
    public:
    //Constructor & Destructor
        PmergeMe( const std::string input );
        PmergeMe( const PmergeMe& copy );
        ~PmergeMe( void );
    
    //Assignement operator
        PmergeMe&    operator = ( const PmergeMe& src );

    //Member Functions
        void    checkInput( void );

    //Getter
        int     getResult( void ) const;  

    private:
        std::string         _input;
        //int             _result;
        std::vector<int>    _vector;
        std::list<int>      _list;
};

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i);

#endif