#ifndef LIBLOW_HEADER_INTERPRETER_HH
#define LIBLOW_HEADER_INTERPRETER_HH

#include "Object.hh"
#include "Variable.hh"

#include <map>
#include <stack>
#include <string>
#include <vector>

namespace LibLow
{
	class Interpreter final
	{
	public:
		Interpreter();
		Interpreter(const Interpreter& interpreter) = delete;
		Interpreter(Interpreter&& interpreter) noexcept = delete;
		~Interpreter() = default;

	public:
		Interpreter& operator=(const Interpreter& interpreter) = delete;
		Interpreter& operator=(Interpreter&& interpreter) noexcept = delete;
		bool operator==(const Interpreter& interpreter) const noexcept = delete;
		bool operator!=(const Interpreter& interpreter) const noexcept = delete;

	private:
		std::map<std::string, Object::Ptr> Registers_;
		std::stack<Object::Ptr> Stack_;
		std::vector<Variable::Ptr> NonMember_Variables_;
	};
}

#endif