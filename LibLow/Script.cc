#include "LibLow/Script.hh"

#include <utility>

namespace LibLow
{
	Script::Script(const Script& script)
	{}
	Script::Script(Script&& script) noexcept
	{}

	Script::Ptr Script::Create()
	{
		return std::make_shared<Script>();
	}
}