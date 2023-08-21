#include "RPN.hpp"

//Constructor & Destructor
RPN::RPN( const std::string input ) : _input(input), _result(0) {}

RPN::RPN( const RPN& copy ) : _input(copy._input), _result(copy._result){}

RPN::~RPN( void ){}
    
//Assignement operator
RPN&    RPN::operator = ( const RPN& src ){

    if (this != &src){
        this->_input = src._input;
        this->_operands = src._operands;
        this->_result = src._result;
    }
    return *this;
}

static std::string removeWhitespace(const std::string& input) {
    std::string res;

    for (std::size_t i = 0; i < input.size(); i++) {
        if (!std::isspace(input[i])) {
            res += input[i];
        }
    }
    return res;
}

void RPN::evaluateRPN( void ) {

    std::string toEvaluate = removeWhitespace(this->_input);
    std::string token;

    for (std::size_t i = 0; i < toEvaluate.length(); i++) {
        
        char c = toEvaluate[i];
        if (isdigit(c)) {
            token += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/'){
            if (this->_operands.size() < 2)
				throw std::runtime_error("Insufficient operands.");
            // If the token is an operator, pop operands, apply the operator, and push the result
            int operand2 = this->_operands.top();
            this->_operands.pop();
            int operand1 = this->_operands.top();
            this->_operands.pop();

            if (c == '+') this->_operands.push(operand1 + operand2);
            else if (c == '-') this->_operands.push(operand1 - operand2);
            else if (c == '*') this->_operands.push(operand1 * operand2);
            else if (c == '/'){
                if (operand2 == 0)
                    throw std::runtime_error("Division by zero is impossible.");
                this->_operands.push(operand1 / operand2);
            }
        } else
            throw std::runtime_error("Invalid Token.");
        if (!token.empty())
		{
			this->_operands.push(atoi(token.c_str()));
			token.clear();
		}
    }
    if (this->_operands.size() != 1)
        throw std::runtime_error("To many operands.");
    this->_result = _operands.top();
    this->_operands.pop();
}

int	RPN::getResult(void) const {
    
	return (this->_result);
}

std::ostream&	operator<<(std::ostream& o, const RPN& i)
{
	o << i.getResult();
	return o;
}