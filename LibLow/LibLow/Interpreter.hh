#ifndef LIBLOW_HEADER_INTERPRETER_HH
#define LIBLOW_HEADER_INTERPRETER_HH

#include "Variable.hh"

#include <memory>
#include <vector>

namespace LibLow
{
	class Interpreter final
	{
	public:
		using Ptr = std::shared_ptr<Interpreter>;

	public:
		Interpreter() = default;
		Interpreter(const Interpreter& interpreter) = delete;
		Interpreter(Interpreter&& interpreter) noexcept = delete;
		~Interpreter() = default;

	public:
		Interpreter& operator=(const Interpreter& interpreter) = delete;
		Interpreter& operator=(Interpreter&& interpreter) noexcept = delete;
		bool operator==(const Interpreter& interpreter) const noexcept = delete;
		bool operator!=(const Interpreter& interpreter) const noexcept = delete;

	public:
		void Reset();
	
	private:
		std::vector<Variable::Ptr> Variables_;
	};
}

#endif