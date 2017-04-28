#include "LibLow/Script.hh"

#include <utility>

namespace LibLow
{
	Script::Script(const Script& script)
		: Commands_(script.Commands_)
	{}
	Script::Script(Script&& script) noexcept
		: Commands_(std::move(script.Commands_))
	{}

	Script& Script::operator+=(const Command& command) noexcept
	{
		AddCommand(command);
		return *this;
	}
	Script& Script::operator+=(const std::vector<Command>& commands)
	{
		AddCommands(commands);
		return *this;
	}

	Script::Ptr Script::Create()
	{
		return std::make_shared<Script>();
	}

	void Script::Reset()
	{
		Commands_.clear();

		ResetVariables();
	}
	void Script::ResetVariables()
	{
		while (!Stack_.empty())
		{
			Stack_.pop();
		}
		Variables_.clear();
	}

	void Script::AddCommand(const Command& command)
	{
		Commands_.push_back(command);
	}
	void Script::AddCommand(Command&& command) noexcept
	{
		Commands_.push_back(std::move(command));
	}
	void Script::AddCommands(const std::vector<Command>& commands)
	{
		for (const Command& command : commands)
		{
			AddCommand(command);
		}
	}
}