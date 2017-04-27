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

	void Interpreter::Run()
	{
		for (const Command& cmd : Script_->Commands_)
		{
			switch (cmd.CmdType())
			{
			case Command::Nop:
				break;

			default:
				break; // TODO 
			}
		}
	}

	void Interpreter::Reset()
	{
		Variables_.clear();
	}
}