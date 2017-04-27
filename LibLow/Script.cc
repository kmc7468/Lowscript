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

	Script::Ptr Script::Create()
	{
		return std::make_shared<Script>();
	}

	void Script::Reset()
	{
		Commands_.clear();
	}
}