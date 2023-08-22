#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <iostream>
# include <list>

class PmergeMe {
    public:
    //Constructor & Destructor
        PmergeMe( void );
        PmergeMe( const PmergeMe& copy );
        ~PmergeMe( void );
    
    //Assignement operator
        PmergeMe&    operator = ( const PmergeMe& src );

    //Member Functions
        void                checkInput( char **av, int ac );
        std::vector<int>    parseVector( char **args, int size )

    //Getter
        int     getResult( void ) const;  

    private:
        int                 _size;
        //int             _result;
        std::vector<int>    _vector;
        std::list<int>      _list;
};

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i);

#endif