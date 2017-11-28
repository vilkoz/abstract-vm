/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaliirybalko <vrybalko@student.uni       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:05:31 by vitaliir          #+#    #+#             */
/*   Updated: 2017/11/29 01:46:28 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"
#include <list>

int			main(int argc, char *argv[])
{
	try {
		Lexer				lexer(argc, argv);
		std::list<sLexeme>	lexemes = lexer.getTokens();
		Parser				parser(lexemes);
		parser.parse();

	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
