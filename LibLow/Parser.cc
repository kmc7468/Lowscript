#include "LibLow/Parser.hh"

#include "LibLow/Command.hh"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iterator>
#include <sstream>
#include <utility>

namespace LibLow
{
	Command Parser::ParseLine(std::string line)
	{
		while (line.length() > 0 && (line.front() == ' ' || line.front() == '\t'))
		{
			line = line.substr(1);
		}
		while (line.length() > 0 && (line.back() == ' ' || line.back() == '\t'))
		{
			line = line.substr(0, line.length() - 1);
		}

		if (line.length() == 0)
			throw "The length of the line cannot be zero.";

		std::string line_lower = line;
		std::transform(line_lower.begin(), line_lower.end(), line_lower.begin(), tolower);


		if (line_lower.find("nop") == 0)
		{
			if (line.length() != 3)
				throw "The argument to the command is invalid.";

			return Command(Command::Nop, {});
		}

		Command::Type cmd_type;
		std::uint8_t cmd_len = 0;

		for (std::size_t i = 0; i < sizeof(Command::TypeString) / sizeof(void*); ++i)
		{
			if (line_lower.find(Command::TypeString[i]) == 0)
			{
				cmd_type = static_cast<Command::Type>(i);
				cmd_len = Command::TypeLength[i];
				goto argument;
			}
		}

		throw "Unknown command.";

	argument:
		std::vector<std::string> arguments;

		if (line.length() == cmd_len)
			throw "The argument to the command is invalid.";

		char arg_char_str = '\0';
		std::string temp;

		for (char c : line.substr(cmd_len + 1))
		{
			if (arg_char_str != '\0')
			{
				temp += c;
				if (c == arg_char_str)
				{
					c = '\0';
				}

				break;
			}
			else
			{
				if (c == ' ')
				{
					continue;
				}

				temp += c;
				if (c == '\"' || c == '\'')
				{
					arg_char_str = c;
				}
				else if (c == ',')
				{
					temp = temp.substr(0, temp.length() - 1);
					arguments.push_back(temp);
					temp.clear();
				}
			}
		}

		arguments.push_back(temp);
		temp.clear();

		if (Command::ArgumentSize(cmd_type) != arguments.size())
			throw "The argument to the command is invalid.";

		return Command(cmd_type, arguments);
	}
	std::vector<Command> Parser::ParseLines(const std::string& lines)
	{
		std::vector<Command> commands;

		std::vector<std::string> line_parse
		{
			std::istream_iterator<std::string>(std::istringstream(lines)),
			std::istream_iterator<std::string>()
		};

		for (const std::string& line : line_parse)
		{
			commands.push_back(ParseLine(line));
		}

		return commands;
	}
	bool Parser::InvalidSyntax(const Command& command)
	{
		if (command.CmdType() < 0 ||
			command.CmdType() > sizeof(Command::TypeLength) / sizeof(std::size_t))
		{
			return false;
		}

		// TODO: Argument Length

		return true;
	}

	Command operator""_c(const char* line, std::size_t length)
	{
		return Parser::ParseLine(std::string(line, length));
	}
}