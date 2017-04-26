#include "LibLow/Command.hh"

#include <cstddef>
#include <utility>

namespace LibLow
{
	Command::Command(const Type& type, const std::vector<std::string>& arguments)
		: Type_(type), Arguments_(arguments)
	{}
	Command::Command(const Command& command)
		: Type_(command.Type_), Arguments_(command.Arguments_)
	{}
	Command::Command(Command&& command) noexcept
		: Type_(std::move(command.Type_)), Arguments_(std::move(command.Arguments_))
	{}

	Command& Command::operator=(const Command& command)
	{
		Type_ = command.Type_;
		Arguments_ = command.Arguments_;
		return *this;
	}
	Command& Command::operator=(Command&& command) noexcept
	{
		Type_ = std::move(command.Type_);
		Arguments_ = std::move(command.Arguments_);
		return *this;
	}
	bool Command::operator==(const Command& command) const
	{
		if (Type_ != command.Type_)
		{
			return false;
		}
		else if (Arguments_.size() != command.Arguments_.size())
		{
			return false;
		}
		else
		{
			for (std::size_t i = 0; i < Arguments_.size(); ++i)
			{
				if (Arguments_[i] != command.Arguments_[i])
				{
					return false;
				}
			}

			return true;
		}
	}
	bool Command::operator!=(const Command& command) const
	{
		return !(*this == command);
	}

	Command::Type Command::CmdType() const
	{
		return Type_;
	}
	const std::vector<std::string>& Command::Arguments() const
	{
		return Arguments_;
	}
}