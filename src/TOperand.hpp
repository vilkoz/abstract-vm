#ifndef TOPERAND_HPP
# define TOPERAND_HPP

# include "IOperand.hpp"
# include "OperandFactory.hpp"
# include <sstream>
# include <iomanip>

# define OPERATOR_FOR_FLOAT(op, rhs, type, s) \
{																				\
		s << std::setprecision(													\
				std::max(getPrecision(), rhs.getPrecision()))					\
			<< std::stod(toString()) op std::stod(rhs.toString());				\
}																				\

# define OPERATOR_NOT_FOR_FLOAT(op, rhs, type, s) \
{																				\
throw std::invalid_argument("Can't perform this operator for float or double");	\
}																				\

# define RUN_OPERATOR(op, rhs, type, s, float_macro) \
	{																			\
		type = std::max(_type, rhs.getType());									\
																				\
		if (type < Float)														\
		{																		\
			s << std::setprecision(0)											\
				<< std::stoll(toString()) op std::stoll(rhs.toString());		\
			return (_o.createOperand(type, s.str()));							\
		}																		\
		else																	\
		{																		\
			float_macro(op, rhs, type, s);										\
		}																		\
	}

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
		eOperandType		type;
		std::stringstream	s;
		RUN_OPERATOR(+, rhs, type, s, OPERATOR_FOR_FLOAT);
		return (_o.createOperand(type, s.str()));
	}

	IOperand const				*operator-( IOperand const & rhs ) const
	{
		eOperandType		type;
		std::stringstream	s;
		RUN_OPERATOR(-, rhs, type, s, OPERATOR_FOR_FLOAT);
		return (_o.createOperand(type, s.str()));
	}

	IOperand const				*operator*( IOperand const & rhs ) const
	{
		eOperandType		type;
		std::stringstream	s;
		RUN_OPERATOR(*, rhs, type, s, OPERATOR_FOR_FLOAT);
		return (_o.createOperand(type, s.str()));
	}

	IOperand const				*operator/( IOperand const & rhs ) const
	{
		eOperandType		type;
		std::stringstream	s;
		RUN_OPERATOR(/, rhs, type, s, OPERATOR_FOR_FLOAT);
		return (_o.createOperand(type, s.str()));
	}

	IOperand const				*operator%( IOperand const & rhs ) const
	{
		eOperandType		type;
		std::stringstream	s;
		RUN_OPERATOR(%, rhs, type, s, OPERATOR_NOT_FOR_FLOAT);
		return (_o.createOperand(type, s.str()));
	}

	std::string const				&toString( void ) const
	{
		std::stringstream		s;
		std::string				*tmp;

		s << std::setprecision(_precision) << +_value;
		tmp = new std::string(s.str());
		return (*tmp);
	}

private:
	OperandFactory		_o;
	eOperandType		_type;
	int					_precision;
	T					_value;
	std::string			*_str;
};

#endif
