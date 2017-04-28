#ifndef LIBLOW_HEADER_PARSER_HH
#define LIBLOW_HEADER_PARSER_HH

#include <cstddef>
#include <string>
#include <vector>

namespace LibLow
{
	class Command;

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
		static Command ParseLine(std::string line);
		static std::vector<Command> ParseLines(const std::string& lines);
	};

	Command operator""_c(const char* line, std::size_t length);
}

#endif