/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:04:37 by vrybalko          #+#    #+#             */
/*   Updated: 2017/11/23 23:32:31 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <string>
# include "Types.hpp"

class IOperand {
public:
	virtual int					getPrecision( void ) const = 0;
	virtual eOperandType		getType( void ) const = 0;
	virtual IOperand const		*operator+( IOperand const & rhs ) const = 0;
	virtual IOperand const		*operator-( IOperand const & rhs ) const = 0;
	virtual IOperand const		*operator*( IOperand const & rhs ) const = 0;
	virtual IOperand const		*operator/( IOperand const & rhs ) const = 0;
	virtual IOperand const		*operator%( IOperand const & rhs ) const = 0;
	virtual std::string const	&toString( void ) const = 0;
	virtual ~IOperand( void ) {}
};

#endif