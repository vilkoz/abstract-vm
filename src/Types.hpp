#ifndef TYPES_HPP
# define TYPES_HPP

# include <iostream>

# define NUM_OPERANDS	5
# define NUM_OPERATIONS	11

enum	eOperandType
{
		Int8,
		Int16,
		Int32,
		Float,
		Double
};

enum	eLexeme
{
		INT8,
		INT16,
		INT32,
		FLOAT,
		DOUBLE,
		PUSH,
		POP,
		DUMP,
		ASSERT,
		ADD,
		SUB,
		MUL,
		DIV,
		MOD,
		PRINT,
		EXIT,
		ERROR,
		END_OF_FILE,
		EOL
};

struct sLexeme
{
	sLexeme(eLexeme, const std::string *);
	~sLexeme();
	eLexeme					type;
	const std::string		*msg;
};

#endif
