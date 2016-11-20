#ifndef VMACHINE_HPP
# define VMACHINE_HPP

# include <vector>
# include "OperandFactory.hpp"
# include "Grammar.hpp"

class						VMachine
{
	public:
		typedef void  (VMachine::*FN)(Grammar::t_ins const &);

								VMachine();
								VMachine(const VMachine & rhs);
								~VMachine();
		VMachine&				operator=(const VMachine & rhs);

		int						execute(std::vector<Grammar::t_ins> program);

	private:
		void					_executeIns(Grammar::t_ins const & ins);

		void					_push(Grammar::t_ins const & ins);
		void					_pop(Grammar::t_ins const & ins);
		void					_dump(Grammar::t_ins const & ins);
		void					_assert(Grammar::t_ins const & ins);
		void					_add(Grammar::t_ins const & ins);
		void					_sub(Grammar::t_ins const & ins);
		void					_mul(Grammar::t_ins const & ins);
		void					_div(Grammar::t_ins const & ins);
		void					_mod(Grammar::t_ins const & ins);
		void					_print(Grammar::t_ins const & ins);
		void					_exit(Grammar::t_ins const & ins);

		static FN				_fnArray[11];
		OperandFactory	_factory;
		std::vector<IOperand const *>	_stack;
};


#endif
