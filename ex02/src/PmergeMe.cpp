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
        this->_vector = src._vector;
        this->_deque = src._deque;
        this->_sorted = src._sorted;
        this->_timeDeque = src._timeDeque;
        this->_timeVector = src._timeVector;
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

std::deque<int>    PmergeMe::parseDeque( char **args, int size ){
    std::deque<int> copy;

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
        std::cout << std::endl << "Before : ";
    else
        std::cout << "After : ";
    std::vector<int>::iterator itBegin = _vector.begin();
    std::vector<int>::iterator itEnd = _vector.end();
    while (itBegin != itEnd){
        std::cout << " " << *itBegin;
        itBegin++;
    }
    std::cout << std::endl << std::endl;
}

double	PmergeMe::getTime( void ){
	
    struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double	PmergeMe::deltaTime( long long time ) {
	if (time > 0)
		return (getTime() - time);
	return (0);
}

template<typename Container>
void    PmergeMe::insertSort(Container& toSort ){
    
    for (typename Container::iterator i = toSort.begin(); i != toSort.end(); ++i) {
        typename Container::iterator j = i;

        while (j != toSort.begin() && *(j - 1) > *j) {
            std::swap(*j, *(j - 1));
            --j;
        }
    }
}

template<typename Container>
void    PmergeMe::merge( Container& toSort, Container& left, Container& right ){

    typename Container::iterator i = left.begin();
	typename Container::iterator j = right.begin();
	typename Container::iterator k = toSort.begin();

    while (i != left.end() && j != right.end()){
        if (*i < *j) {
            *k = *i;
            ++i;
        } else {
            *k = *j;
            ++j;
        }
        ++k;
        //std::cout << "Hello" << std::endl;
    }
    while (i != left.end()){
        *k = *i;
        ++i;
        ++k;
    }
    while (j != right.end()){
        *k = *j;
        ++j;
        ++k;
    }
}

template<typename Container>
void    PmergeMe::mergeInsertSort( Container& toSort ){

    const int threshold = 16;
    const int size = toSort.size();

    if ( size < threshold)
        insertSort(toSort);
    else {
        typename Container::iterator mid = toSort.begin() + (size / 2);
        //std::cout <<"mid: " << mid << std::endl << std::endl;
        Container left(toSort.begin(), mid);
	    Container right(mid, toSort.end());
        mergeInsertSort(left);
        mergeInsertSort(right);
        merge(toSort, left, right);
    }
}

void	PmergeMe::printTime(std::string result) const {
	double time;
	if (result == "Vector")
		time = this->_timeVector;
	else if (result == "Deque")
		time = this->_timeDeque;
	std::cout 
		<< "Time to process a range of " << this->_vector.size() 
		<< " elements with std::" << result << ": "
		<< std::fixed << std::setprecision(5) << time << " ms" << std::endl;
}

//Member Functions
void    PmergeMe::runInput( char** av, int ac ){
    
    this->_vector = parseVector(av, ac);
    findDouble();
    this->_deque = parseDeque(av, ac);

    printBeforeAndAfter();

    double start = getTime();
    mergeInsertSort(this->_vector);
    _timeVector = deltaTime(start);

    start = getTime();
	mergeInsertSort(this->_deque);
	_timeDeque = deltaTime(start);


    _sorted = true;
    printBeforeAndAfter();

    printTime("Vector");
    printTime("Deque");
}

//Getters
double	PmergeMe::getVectorTime(void) const {
	return (this->_timeVector);
}

double	PmergeMe::getDequeTime(void) const {
	return (this->_timeDeque);
}

std::ostream&	operator << (std::ostream& o, const PmergeMe& i){
    	o 
		<< "Vector delta time: " << i.getVectorTime() << std::endl
		<< "Deque delta time: " << i.getDequeTime();
	return o;
}