#ifndef TOPERAND_HPP
# define TOPERAND_HPP

# include "IOperand.hpp"
# include "OperandFactory.hpp"
# include <sstream>
# include <iomanip>

template<typename T>
class TOperand: public IOperand
{
public:
	TOperand (TOperand const &copy)
	{
		*this = copy;
	}

	TOperand (eOperandType const &type, T const &value): _type(type), _value(value)
	{
		if (type < Float)
			_precision = 0;
		else if (type == Float)
			_precision = 16;
		else
			_precision = 32;
	}

	TOperand (void): _value(0) {};

	virtual ~TOperand () {};
	TOperand			&operator=(TOperand const &copy)
	{
		_value = copy._value;
		return (*this);
	}

	int					getPrecision( void ) const
	{
		return (_type);
	}

	eOperandType		getType( void ) const
	{
		return (_type);
	}

	IOperand const				*operator+( IOperand const & rhs ) const
	{
		OperandFactory		o;
		eOperandType		type = std::max(_type, rhs.getType());

		if (type < Float)
		{
			auto					val = std::stoll(toString()) + std::stoll(rhs.toString());
			std::stringstream		s;

			s << std::setprecision(0) << val;
			return (o.createOperand(type, s.str()));
		}
		auto					val = std::stod(toString()) + std::stod(rhs.toString());
		std::stringstream		s;

		s << std::setprecision(std::max(getPrecision(), rhs.getPrecision())) << val;
		return (o.createOperand(type, s.str()));
	}

	IOperand const				*operator-( IOperand const & rhs ) const
	{
		OperandFactory		o;
		eOperandType		type = std::max(_type, rhs.getType());

		if (type < Float)
		{
			auto					val = std::stoll(toString()) - std::stoll(rhs.toString());
			std::stringstream		s;

			s << std::setprecision(0) << val;
			return (o.createOperand(type, s.str()));
		}
		auto					val = std::stod(toString()) - std::stod(rhs.toString());
		std::stringstream		s;

		s << std::setprecision(std::max(getPrecision(), rhs.getPrecision())) << val;
		return (o.createOperand(type, s.str()));
	}

	IOperand const				*operator*( IOperand const & rhs ) const
	{
		OperandFactory		o;
		eOperandType		type = std::max(_type, rhs.getType());

		if (type < Float)
		{
			auto					val = std::stoll(toString()) * std::stoll(rhs.toString());
			std::stringstream		s;

			s << std::setprecision(0) << val;
			return (o.createOperand(type, s.str()));
		}
		auto					val = std::stod(toString()) * std::stod(rhs.toString());
		std::stringstream		s;

		s << std::setprecision(std::max(getPrecision(), rhs.getPrecision())) << val;
		return (o.createOperand(type, s.str()));
	}

	IOperand const				*operator/( IOperand const & rhs ) const
	{
		OperandFactory		o;
		eOperandType		type = std::max(_type, rhs.getType());

		if (type < Float)
		{
			auto					val = std::stoll(toString()) / std::stoll(rhs.toString());
			std::stringstream		s;

			s << std::setprecision(0) << val;
			return (o.createOperand(type, s.str()));
		}
		auto					val = std::stod(toString()) / std::stod(rhs.toString());
		std::stringstream		s;

		s << std::setprecision(std::max(getPrecision(), rhs.getPrecision())) << val;
		return (o.createOperand(type, s.str()));
	}

	IOperand const				*operator%( IOperand const & rhs ) const
	{
		OperandFactory		o;
		eOperandType		type = std::max(_type, rhs.getType());

		if (type < Float)
		{
			auto					val = std::stoll(toString()) % std::stoll(rhs.toString());
			std::stringstream		s;

			s << std::setprecision(0) << val;
			return (o.createOperand(type, s.str()));
		}
		throw std::invalid_argument("Can't mod doubles!");
		return (NULL);
	}

	std::string const	&toString( void ) const
	{
		std::stringstream		s;
		std::string				*tmp;

		s << std::setprecision(_precision) << +_value;
		tmp = new std::string(s.str());
		return (*tmp);
	}

private:
	eOperandType		_type;
	int					_precision;
	T					_value;
	std::string			*_str;
};

#endif
