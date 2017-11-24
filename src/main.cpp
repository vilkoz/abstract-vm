/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaliirybalko <vrybalko@student.uni       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:05:31 by vitaliir          #+#    #+#             */
/*   Updated: 2017/11/24 16:08:20 by vitaliir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include <list>

int			main(int argc, char *argv[])
{
	try {
		Lexer				lexer(argc, argv);
		std::list<sLexeme>	l;

		l = lexer.getTokens();
	} catch(std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}