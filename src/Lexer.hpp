#ifndef LEXER_HPP
# define LEXER_HPP

# include "Types.hpp"
# include <list>
# include <stdexcept>
# include <string>

class Lexer
{
	public:
		Lexer (int ac, char **av);
		virtual ~Lexer ();
		Lexer					&operator=(Lexer const &copy);

		std::list<sLexeme>		&getTokens(void);
	private:
		Lexer (void);
		Lexer (Lexer const &copy);
		std::list<sLexeme>		_l;
		int						_lineNum;
};

#endif
