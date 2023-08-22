#include "PmergeMe.hpp"

 //Constructors & Destructor
PmergeMe::PmergeMe( const std::string input ) : _input(input){}

PmergeMe::PmergeMe( const PmergeMe& copy ) : _input(copy._input){}

PmergeMe::~PmergeMe( void ){}
    
//Assignement operator
PmergeMe&    PmergeMe::operator = ( const PmergeMe& src ){
    if (this != &src){
        this->_input = src._input;
        this->_vector = src._vector;
        this->_list = src._list;
    }
}

std::vector<int>    PmergeMe::parseVector( char **args, int size ){
    vector<int> copy;

    for (size_t i = 0; i < size; ++i){
        
        std::string arg = args[i];
        int val = atoi(arg.c_str());
        if ( val <= 0 )
            throw std::runtime_error("Invalid argument value.")
        copy.push_back(val);
    }
    return copy;
}

std::vector<int>    PmergeMe::parseList( char **args, int size ){
    list<int> copy;

    for (size_t i = 0; i < size; ++i){
        
        std::string arg = args[i];
        int val = atoi(arg.c_str());
        if ( val <= 0 )
            throw std::runtime_error("Invalid argument value.")
        copy.push_back(val);
    }
    return copy;
}

//Member Functions
void    PmergeMe::checkInput( char** av, int ac ){
    this->_vector = parseVector(ac, av);

    for (std::size_t i = 0; i < _input.length(); i++) {
        
        char c = _input[i];
        if (isdigit(c))
            token += c;
    }
}

//Getter
int     PmergeMe::getResult( void ) const{

} 

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i){

}