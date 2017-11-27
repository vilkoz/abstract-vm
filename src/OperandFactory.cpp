#include "OperandFactory.hpp"
#include "TOperand.hpp"

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
							std::string const &value) const
{
	if (type == Int8)
	{
		auto	res = std::stoll(value.c_str());
		if (res < CHAR_MIN || res > CHAR_MAX)
			throw std::out_of_range("Int8 overflow or underflow");
		static_cast<void>(res);
	}
	else if (type == Int16)
	{
		auto	res = std::stoll(value.c_str());
		if (res < SHRT_MIN || res > SHRT_MAX)
			throw std::out_of_range("Int16 overflow or underflow");
		static_cast<void>(res);
	}
	else if (type == Int32)
	{
		auto	res = std::stoi(value.c_str());
		static_cast<void>(res);
	}
	else if (type == Float)
	{
		auto	res = std::stof(value.c_str());
		static_cast<void>(res);
	}
	else if (type == Double)
	{
		auto	res = std::stod(value.c_str());
		static_cast<void>(res);
	}
}

IOperand const			*OperandFactory::createOperand(eOperandType type,
							std::string const & value) const
{
	return ((this->*(_operands[type]))(value));
}

IOperand const			*OperandFactory::createInt8(std::string const &value) const
{
	checkOverflow(Int8, value);
	auto	res = std::stoi(value);
	return (new TOperand<char>(Int8, static_cast<char>(res)));
}

IOperand const			*OperandFactory::createInt16(std::string const &value) const
{
	checkOverflow(Int16, value);
	auto	res = std::stoi(value);
	return (new TOperand<short>(Int16, static_cast<short>(res)));
}

IOperand const			*OperandFactory::createInt32(std::string const &value) const
{
	checkOverflow(Int32, value);
	auto	res = std::stoi(value);
	return (new TOperand<int>(Int32, static_cast<int>(res)));
}

IOperand const			*OperandFactory::createFloat(std::string const &value) const
{
	checkOverflow(Float, value);
	auto	res = std::stof(value);
	return (new TOperand<float>(Float, static_cast<float>(res)));
}

IOperand const			*OperandFactory::createDouble(std::string const &value) const
{
	checkOverflow(Float, value);
	auto	res = std::stod(value);
	return (new TOperand<double>(Double, static_cast<double>(res)));
}
