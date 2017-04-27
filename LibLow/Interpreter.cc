#include "LibLow/Interpreter.hh"

namespace LibLow
{
	Interpreter::Interpreter(const Script::Ptr& script)
		: Script_(script)
	{}

	void Interpreter::Reset()
	{
		Variables_.clear();
	}
}