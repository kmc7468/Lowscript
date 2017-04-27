#ifndef LIBLOW_HEADER_COMMAND_HH
#define LIBLOW_HEADER_COMMAND_HH

#include <string>
#include <vector>

namespace LibLow
{
	class Command final
	{
	public:
		enum Type
		{
			Nop,

			Var,
			Con,
			Push,
			Pop,
		};

	public:
		Command(const Type& type, const std::vector<std::string>& arguments);
		Command(const Command& command);
		Command(Command&& command) noexcept;
		~Command() = default;

	public:
		Command& operator=(const Command& command);
		Command& operator=(Command&& command) noexcept;
		bool operator==(const Command& command) const;
		bool operator!=(const Command& command) const;

	public:
		Type CmdType() const;
		const std::vector<std::string>& Arguments() const;

	private:
		Type Type_;
		std::vector<std::string> Arguments_;
	};
}

#endif