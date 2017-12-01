#ifndef PARSER_HPP
# define PARSER_HPP

# include "Types.hpp"
# include "IOperand.hpp"
# include "OperandFactory.hpp"
# include <list>

class Parser
{
	public:
		Parser (Parser const &copy);
		Parser (std::list<sLexeme> &l);
		virtual ~Parser ();
		Parser			&operator=(Parser const &copy);

		void			parse(void);

		void			push(std::list<sLexeme>::iterator &it);
		void			pop(std::list<sLexeme>::iterator &it);
		void			dump(std::list<sLexeme>::iterator &it);
		void			assert(std::list<sLexeme>::iterator &it);
		void			add(std::list<sLexeme>::iterator &it);
		void			sub(std::list<sLexeme>::iterator &it);
		void			mul(std::list<sLexeme>::iterator &it);
		void			div(std::list<sLexeme>::iterator &it);
		void			mod(std::list<sLexeme>::iterator &it);
		void			print(std::list<sLexeme>::iterator &it);
		void			exit(std::list<sLexeme>::iterator &it);

	private:
		Parser (void);
		std::list<sLexeme>			_lexemes;
		std::list<IOperand const*>	_stack;
		void						(Parser::*_operations[11])(
										std::list<sLexeme>::iterator &it);
		OperandFactory				_operandFactory;
		bool						_exit;
};

# define	DO_OPERATOR_CHECKS(op, it)	\
{																				\
	it++;																		\
	if (it->type != EOL)														\
		throw std::invalid_argument("Wrong Syntax!");							\
	if (_stack.empty())															\
		throw std::invalid_argument("Pop on empty stack!");						\
	auto	v1 = _stack.back();													\
	_stack.pop_back();															\
	if (_stack.empty())															\
		throw std::invalid_argument("Pop on empty stack!");						\
	auto	v2 = _stack.back();													\
	_stack.pop_back();															\
	IOperand const		*res = (*v1) op (*v2);									\
	delete v1;																	\
	delete v2;																	\
	_stack.push_back(res);														\
}																				\

#endif
