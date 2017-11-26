#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

# include <climits>
# include <cfloat>
# include <cstdint>
# include <cstdlib>
# include "Types.hpp"
# include "IOperand.hpp"

class OperandFactory
{
	public:
		OperandFactory (void);
		OperandFactory (OperandFactory const &copy);
		virtual ~OperandFactory ();
		OperandFactory			&operator=(OperandFactory const &copy);

		IOperand const			*createOperand(eOperandType type,
									std::string const & value) const;
		IOperand const			*createInt8(std::string const &value) const;
		IOperand const			*createInt16(std::string const &value) const;
		IOperand const			*createInt32(std::string const &value) const;
		IOperand const			*createFloat(std::string const &value) const;
		IOperand const			*createDouble(std::string const &value) const;

	private:
		void					checkOverflow(eOperandType type,
									std::string const &value);
		IOperand const			*(OperandFactory::*_operands[5])(
									std::string const &value) const;
};

#endif
