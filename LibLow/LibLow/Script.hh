#ifndef LIBLOW_HEADER_SCRIPT_HH
#define LIBLOW_HEADER_SCRIPT_HH

#include "Command.hh"

#include <memory>
#include <vector>

namespace LibLow
{
	class Script final
	{
		friend class Interpreter;

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

	public:
		void Reset();

	private:
		std::vector<Command> Commands_;
	};
}

#endif