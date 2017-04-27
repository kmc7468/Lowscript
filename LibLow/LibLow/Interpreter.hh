#ifndef LIBLOW_HEADER_INTERPRETER_HH
#define LIBLOW_HEADER_INTERPRETER_HH

#include "Script.hh"
#include "Variable.hh"

#include <memory>
#include <stack>
#include <vector>

namespace LibLow
{
	class Interpreter final
	{
	public:
		using Ptr = std::shared_ptr<Interpreter>;

	public:
		Interpreter(const Script::Ptr& script);
		Interpreter(const Interpreter& interpreter) = delete;
		Interpreter(Interpreter&& interpreter) noexcept = delete;
		~Interpreter() = default;

	public:
		Interpreter& operator=(const Interpreter& interpreter) = delete;
		Interpreter& operator=(Interpreter&& interpreter) noexcept = delete;
		bool operator==(const Interpreter& interpreter) const noexcept = delete;
		bool operator!=(const Interpreter& interpreter) const noexcept = delete;

	public:
		static Ptr Create(const Script::Ptr& script);

	public:
		void Reset();

	private:
		Script::Ptr Script_;
		std::stack<Variable::Ptr> Stack_;
		std::vector<Variable::Ptr> Variables_;
	};
}

#endif