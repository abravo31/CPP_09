#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector> //vector to sort
# include <iostream> //cout
# include <list> //list to sort
# include <set> //set container to find duplicates
# include <sys/time.h> //gettimeofday
# include <stdlib.h> //atoi

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
        std::vector<int>    parseVector( char **args, int size );
        std::list<int>      parseList( char **args, int size );
        void                findDouble( void );
        void                printBeforeAndAfter( void );

    //Getter
        //int     getResult( void ) const;
        double  getTime( void ); 

    private:
        int                 _size;
        bool                _sorted;
        std::vector<int>    _vector;
        std::list<int>      _list;
        double              _timeVector;
        double              _timeList;
};

// std::ostream&	operator << (std::ostream& o, const PmergeMe& i);

#endif