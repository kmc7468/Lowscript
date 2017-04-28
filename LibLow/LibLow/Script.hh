#ifndef LIBLOW_HEADER_SCRIPT_HH
#define LIBLOW_HEADER_SCRIPT_HH

#include "Command.hh"
#include "Object.hh"
#include "Variable.hh"

#include <memory>
#include <stack>
#include <vector>

namespace LibLow
{
	class Script final
	{
	public:
		using Ptr = std::shared_ptr<Script>;

	public:
		Script() = default;
		Script(const Script& script);
		Script(Script&& script) noexcept;
		~Script() = default;

	public:
		Script& operator=(const Script& script) = delete;
		Script& operator=(Script&& script) noexcept = delete;
		bool operator==(const Script& script) const noexcept = delete;
		bool operator!=(const Script& script) const noexcept = delete;

	public:
		static Ptr Create();
	};
}

#endif