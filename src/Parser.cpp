#include "Parser.hpp"

Parser::Parser(void)
{
}

Parser::~Parser(void)
{
	while (!_stack.empty())
	{
		delete _stack.back();
		_stack.pop_back();
	}
}

Parser::Parser (Parser const &copy)
{
	*this = copy;
}

Parser			&Parser::operator=(Parser const &copy)
{
	(void)copy;
	return (*this);
}

Parser::Parser(std::list<sLexeme> &l): _lexemes(l), _exit(false)
{
	_operations[0] = &Parser::push;
	_operations[1] = &Parser::pop;
	_operations[2] = &Parser::dump;
	_operations[3] = &Parser::assert;
	_operations[4] = &Parser::add;
	_operations[5] = &Parser::sub;
	_operations[6] = &Parser::mul;
	_operations[7] = &Parser::div;
	_operations[8] = &Parser::mod;
	_operations[9] = &Parser::print;
	_operations[10] = &Parser::exit;
}

void			Parser::parse(void)
{
	int		num;
	for (auto it = _lexemes.begin(); it != _lexemes.end(); ++it)
	{
		num = it->type - NUM_OPERANDS;
		if (num < 0)
			throw std::invalid_argument("Wrong Syntax!");
		if (num >= NUM_OPERATIONS)
			continue ;
		(this->*_operations[num])(it);
		if (_exit)
			break ;
	}
	if (!_exit)
		throw std::invalid_argument("No exit instruction!");
}

void			Parser::push(std::list<sLexeme>::iterator &it)
{
	it++;
	if (it->type > NUM_OPERANDS)
		throw std::invalid_argument("Wrong Syntax!");
	_stack.push_back(_operandFactory.createOperand(
				static_cast<eOperandType>(it->type),
				*it->msg));
	it++;
	if (it->type != EOL)
		throw std::invalid_argument("Wrong Syntax!");
}

void			Parser::pop(std::list<sLexeme>::iterator &it)
{
	it++;
	if (it->type != EOL)
		throw std::invalid_argument("Wrong Syntax!");
	if (_stack.empty())
		throw std::invalid_argument("Pop on empty stack!");
	delete _stack.back();
	_stack.pop_back();
}

void			Parser::dump(std::list<sLexeme>::iterator &it)
{
	it++;
	if (it->type != EOL)
		throw std::invalid_argument("Wrong Syntax!");
	for (auto i = _stack.rbegin(); i != _stack.rend(); ++i)
		std::cout << (*i)->toString() << std::endl;
}

void			Parser::assert(std::list<sLexeme>::iterator &it)
{
	it++;
	if (it->type > NUM_OPERANDS)
		throw std::invalid_argument("Wrong Syntax!");
	if (_stack.empty())
		throw std::invalid_argument("Pop on empty stack!");
	auto	value = _stack.back();
	if (*it->msg != (value)->toString())
		throw std::logic_error("Assertion error!");
	it++;
	if (it->type != EOL)
		throw std::invalid_argument("Wrong Syntax!");
}

void			Parser::add(std::list<sLexeme>::iterator &it)
{
	DO_OPERATOR_CHECKS(+, it);
}

void			Parser::sub(std::list<sLexeme>::iterator &it)
{
	DO_OPERATOR_CHECKS(-, it);
}

void			Parser::mul(std::list<sLexeme>::iterator &it)
{
	DO_OPERATOR_CHECKS(*, it);
}

void			Parser::div(std::list<sLexeme>::iterator &it)
{
	DO_OPERATOR_CHECKS(/, it);
}

void			Parser::mod(std::list<sLexeme>::iterator &it)
{
	DO_OPERATOR_CHECKS(%, it);
}

void			Parser::print(std::list<sLexeme>::iterator &it)
{
	it++;
	if (it->type != EOL)
		throw std::invalid_argument("Wrong Syntax!");
	if (_stack.empty())
		throw std::invalid_argument("Pop on empty stack!");
	auto		value = _stack.end();
	value--;
	auto	res = std::stoll((*value)->toString());
	if (res < CHAR_MIN || res > CHAR_MAX)
		throw std::out_of_range("Char overflow or underflow");
	/* _stack.pop_back(); */
	std::cout << static_cast<char>(res) << std::endl;
}

void			Parser::exit(std::list<sLexeme>::iterator &it)
{
	it++;
	if (it->type != EOL)
		throw std::invalid_argument("Wrong Syntax!");
	_exit = true;
}
