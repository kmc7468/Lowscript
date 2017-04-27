#ifndef LIBLOW_HEADER_PARSER_HH
#define LIBLOW_HEADER_PARSER_HH

namespace LibLow
{
	class Parser final
	{
	public:
		Parser() = delete;
		Parser(const Parser& parser) = delete;
		Parser(Parser&& parser) noexcept = delete;
		~Parser() = delete;

	public:
		Parser& operator=(const Parser& parser) = delete;
		Parser& operator=(Parser&& parser) noexcept = delete;
		bool operator==(const Parser& parser) const noexcept = delete;
		bool operator!=(const Parser& parser) const noexcept = delete;

	public:

	};
}

#endif