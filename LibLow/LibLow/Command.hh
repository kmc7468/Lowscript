#ifndef LIBLOW_HEADER_COMMAND_HH
#define LIBLOW_HEADER_COMMAND_HH

#include <cstddef>
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
			Push,
			Pop,

			Mov,
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
		static constexpr std::size_t ArgumentSize(const Type& command) noexcept
		{
			switch (command)
			{
			case Nop:
				return 0;

			case Push:
			case Pop:
				return 1;

			case Var:
			case Mov:
				return 2;

			default:
				return -1;
			}
		}

	public:
		std::string ToString() const;

	public:
		Type CmdType() const;
		const std::vector<std::string>& Arguments() const;

	public:
		static constexpr const char* const TypeString[] =
		{
			"nop",
			"var",
			"push",
			"pop",
			"mov",
		};
		static constexpr const std::size_t TypeLength[] =
		{
			3, // nop
			3, // var
			4, // push
			3, // pop
			3, // mov
		};

	private:
		Type Type_;
		std::vector<std::string> Arguments_;
	};
}

#endif