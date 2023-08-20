# include "RPN.hpp"

int main ( int ac, char** av ){
    try
    {
        if (ac == 2){
            RPN cal(av[1]);
            cal.evaluateRPN();
        } else 
            std::cout << "Ivalid Args : try with <./RPN> & <7 7 * 7 ->" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << '\n';
    }
    return 0;
}

