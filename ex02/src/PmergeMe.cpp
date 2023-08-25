#include "PmergeMe.hpp"

 //Constructors & Destructor
PmergeMe::PmergeMe( void ) : _sorted(false) {}

PmergeMe::PmergeMe( const PmergeMe& copy ) {
    *this = copy;
}

PmergeMe::~PmergeMe( void ){}
    
//Assignement operator
PmergeMe&    PmergeMe::operator = ( const PmergeMe& src ){
    if (this != &src){
        //this->_input = src._input;
        this->_vector = src._vector;
        this->_list = src._list;
    }
    return *this;
}

std::vector<int>    PmergeMe::parseVector( char **args, int size ){
    std::vector<int> copy;

    for (int i = 1; i < size; ++i){
        
        std::string arg = args[i];
        int val = atoi(arg.c_str());
        if ( val <= 0 )
            throw std::runtime_error("Invalid argument value.");
        copy.push_back(val);
    }
    return copy;
}

std::list<int>    PmergeMe::parseList( char **args, int size ){
    std::list<int> copy;

    for (int i = 1; i < size - 1; ++i){
        
        std::string arg = args[i];
        int val = atoi(arg.c_str());
        if ( val <= 0 )
            throw std::runtime_error("Invalid argument value.");
        copy.push_back(val);
    }
    return copy;
}

void            PmergeMe::findDouble( void ){

    std::set<int> toSet;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it){
        int num = *it;
        if (toSet.find(num) != toSet.end())
            throw std::runtime_error("Number duplicated.");
        toSet.insert(num);
    }
}

void            PmergeMe::printBeforeAndAfter( void ){

    if (_sorted == false)
        std::cout << "Before : ";
    else
        std::cout << "After : ";
    std::vector<int>::iterator itBegin = _vector.begin();
    std::vector<int>::iterator itEnd = _vector.end();
    while (itBegin != itEnd){
        std::cout << " " << *itBegin;
        itBegin++;
    }
    std::cout << std::endl;
}

double	PmergeMe::getTime( void ){
	
    struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

template<typename Container>
void    PmergeMe::insertSort(Container& toSort, int low, int high){
    
    //const int threshold = 16;
    for (int i = low + 1; i <= high; ++i) {
        typename Container::value_type key = toSort[i];
        int j = i - 1;

        while (j >= low && toSort[j] > key) {
            toSort[j + 1] = toSort[j];
            --j;
        }
        // std::cout << "Pair: " << toSort[j] << " " << toSort[j + 1] << std::endl;
        // std::cout << "j = " << j << " & " << "(j + 1) = " << j+1 << std::endl << std::endl;
        toSort[j + 1] = key;
    }
}

template<typename Container>
void    PmergeMe::mergeIsertSort( Container& toSort, int low, int high ){

    const int threshold = 16;

    if (high - low < threshold)
        insertSort(toSort, low, high);
    else {
        int mid = (low + high) / 2;
        std::cout <<"mid: " << mid << std::endl << std::endl;
        mergeIsertSort(toSort, low, mid);
        mergeIsertSort(toSort, mid + 1, high);
    }
}

//Member Functions
void    PmergeMe::checkInput( char** av, int ac ){
    
    this->_vector = parseVector(av, ac);
    findDouble();
    this->_list = parseList(av, ac);

    printBeforeAndAfter();
    mergeIsertSort(_vector, 0, _vector.size() - 1);

    _sorted = true;
    printBeforeAndAfter();

    // for (std::size_t i = 0; i < _input.length(); i++) {
        
    //     char c = _input[i];
    //     if (isdigit(c))
    //         token += c;
    // }
}

//Getter
// int     PmergeMe::getResult( void ) const{

// } 

// std::ostream&	operator << (std::ostream& o, const PmergeMe& i){

// }