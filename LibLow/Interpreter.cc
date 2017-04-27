#include "LibLow/Interpreter.hh"

#include <string>

namespace LibLow
{
	Interpreter::Interpreter(const Script::Ptr& script)
		: Script_(new Script(*script.get()))
	{}

	Interpreter::Ptr Interpreter::Create(const Script::Ptr& script)
	{
		return std::make_shared<Interpreter>(script);
	}

	void Interpreter::Reset()
	{
		while (!Stack_.empty())
		{
			Stack_.pop();
		}
		Variables_.clear();
	}
}