#include "Lexer.hpp"
#include <stdio.h>
#include <string>

extern FILE		*yyin;
extern int		yylex(void);
extern char		*yytext;

Lexer::Lexer(void)
{
}

Lexer::~Lexer(void)
{
	while (!_l.empty())
	{
		delete (_l.back()).msg;
		_l.pop_back();
	}
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

sLexeme::sLexeme(eLexeme type, const std::string *s): type(type), msg(s)
{
}

sLexeme::~sLexeme(void)
{
}

std::list<sLexeme>		&Lexer::getTokens(void)
{
	/* std::list<sLexeme>		l; */
	eLexeme					token;
	std::string				*tmp;

	while ((token = static_cast<eLexeme>(yylex())) != END_OF_FILE
			&& token != ERROR)
	{
		if (token == EOL)
			_lineNum++;
		tmp = new std::string(yytext);
		if (token == 0 && *tmp == std::string(""))
		{
			delete tmp;
			break ;
		}
		_l.push_back(sLexeme(token,
			const_cast<const std::string*>(new std::string(tmp->c_str()))));
		delete tmp;
	}
	if (token == ERROR)
		throw std::invalid_argument("Illegal instruction!");
	return (_l);
}
