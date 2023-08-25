#include "PmergeMe.hpp"

int main ( int ac, char** av ){
    try
    {
        if (ac > 2){
            PmergeMe toSort;
            toSort.runInput(av, ac);
        } else 
            std::cout << "Ivalid Args : try with <./PmergeMe> & < 6 5 4 3 2 1 >" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << '\n';
    }
    return 0;
}