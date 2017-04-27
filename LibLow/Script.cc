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

	void Script::Reset()
	{
		Commands_.clear();
	}
}