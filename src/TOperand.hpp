#ifndef TOPERAND_HPP
# define TOPERAND_HPP

# include "IOperand.hpp"

template<typename T>
class TOperand: public IOperand
{
public:
	TOperand (TOperand const &copy)
	{
		*this = copy;
	}

	TOperand (T const &value)
	{
		_value = value;
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

	};
	eOperandType		getType( void ) const;
	char const			*operator+( char const & rhs ) const;
	char const			*operator-( char const & rhs ) const;
	char const			*operator*( char const & rhs ) const;
	char const			*operator/( char const & rhs ) const;
	char const			*operator%( char const & rhs ) const;
	std::string const	&toString( void ) const;

private:
	T					_value;
};

#endif
