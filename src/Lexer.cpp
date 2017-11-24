#include "Lexer.hpp"
#include <stdio.h>
#include <string>

extern "C" FILE		*yyin;
extern "C" int		yylex(void);
extern "C" char		*yytext;

Lexer::Lexer(void)
{
}

Lexer::~Lexer(void)
{
}

Lexer::Lexer (Lexer const &copy)
{
	*this = copy;
}

Lexer			&Lexer::operator=(Lexer const &copy)
{
	(void)copy;
	return (*this);
}

Lexer::Lexer(int ac, char **av)
{
	if (ac > 2)
		throw std::invalid_argument("too much argumnets to program!\n");
	else if (ac == 1)
		yyin = stdin;
	else
	{
		yyin = fopen(av[1], "r");
		if (!yyin)
			throw std::invalid_argument("can't open file");
	}
}

sLexeme::sLexeme(std::string &s, eLexeme type): type(type), msg(s)
{
}

std::list<sLexeme>		Lexer::getTokens(void)
{
	std::list<sLexeme>		l;
	eLexeme					token;
	std::string				tmp;

	while ((token = static_cast<eLexeme>(yylex())))
	{
		tmp = std::string(yytext);
		l.push_back(static_cast<sLexeme>(sLexeme(tmp, token)));
	}
	return (l);
}
