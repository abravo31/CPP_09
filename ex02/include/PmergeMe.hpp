#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector> //vector to sort
# include <iostream> //cout
# include <deque> //list to sort
# include <set> //set container to find duplicates
# include <sys/time.h> //gettimeofday
# include <stdlib.h> //atoi
# include <iomanip> //setprecision

class PmergeMe {
    public:
    //Constructor & Destructor
        PmergeMe( void );
        PmergeMe( const PmergeMe& copy );
        ~PmergeMe( void );
    
    //Assignement operator
        PmergeMe&    operator = ( const PmergeMe& src );

    //Member Functions
        void                runInput( char **av, int ac );
    
    //Publics Getters
        double	getVectorTime(void) const;
        double	getDequeTime(void) const;

    private:

        bool                _sorted;
        std::vector<int>    _vector;
        std::deque<int>     _deque;
        double              _timeVector;
        double              _timeDeque;

        std::vector<int>    parseVector( char **args, int size );
        std::deque<int>     parseDeque( char **args, int size );
        void                findDouble( void );
        void                printBeforeAndAfter( void );
        void                printTime(std::string result) const;
        double              deltaTime( long long time );

    // Pivate Getters

        double  getTime( void );
        
        template<typename Container> 
        void    insertSort( Container& toSort );
        template<typename Container> 
        void    mergeInsertSort( Container& toSort );
        template<typename Container> 
        void    merge( Container& toSort, Container& left, Container& right );
};

std::ostream&	operator << (std::ostream& o, const PmergeMe& i);

#endif