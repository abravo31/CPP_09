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

//Member Functions
void    PmergeMe::checkInput( void ){
    std::string token;

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