#include "OperandFactory.hpp"

OperandFactory::OperandFactory(void)
{
	_operands[0] = &OperandFactory::createInt8;
	_operands[1] = &OperandFactory::createInt16;
	_operands[2] = &OperandFactory::createInt32;
	_operands[3] = &OperandFactory::createFloat;
	_operands[4] = &OperandFactory::createDouble;
}

OperandFactory::~OperandFactory(void)
{
}

OperandFactory::OperandFactory (OperandFactory const &copy)
{
	*this = copy;
}

OperandFactory			&OperandFactory::operator=(OperandFactory const &copy)
{
	static_cast<void>(copy);
	return (*this);
}

void					OperandFactory::checkOverflow(eOperandType type,
							std::string const &value)
{

}

IOperand const			*OperandFactory::createOperand(eOperandType type,
							std::string const & value) const
{
	return ((this->*(_operands[type]))(value));
}

IOperand const			*OperandFactory::createInt8(std::string const &value) const
{

}
