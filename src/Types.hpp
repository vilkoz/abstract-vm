#ifndef TYPES_HPP
# define TYPES_HPP

# include <iostream>

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
		END_OF_FILE,
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
