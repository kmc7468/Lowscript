#include "LibLow/Parser.hh"

#include "LibLow/Command.hh"

#include <algorithm>
#include <cctype>
#include <cstdint>

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

		if (line_lower.find("var") == 0)
		{
			cmd_type = Command::Var;
			cmd_len = 3;
		}
		else if (line_lower.find("con") == 0)
		{
			cmd_type = Command::Con;
			cmd_len = 3;
		}
		else if (line_lower.find("push") == 0)
		{
			cmd_type = Command::Push;
			cmd_len = 4;
		}
		else if (line_lower.find("pop") == 0)
		{
			cmd_type = Command::Pop;
			cmd_len = 3;
		}
		else
			throw "Unknown command.";
	
		std::vector<std::string> arguments;

		if (line.length() == cmd_len)
			throw "The argument to the command is invalid.";

		bool is_char = false, is_str = false;
		std::string temp;

		for (char c : line.substr(cmd_len + 1))
		{
			if (is_char)
			{
				temp += c;
				if (c == '\'')
				{
					is_char = false;
				}
			}
			else if (is_str)
			{
				temp += c;
				if (c == '\'')
				{
					is_str = false;
				}
			}
			else
			{
				if (c == ' ')
				{
					continue;
				}

				temp += c;
				if (c == '\"')
				{
					is_str = true;
				}
				else if (c == '\'')
				{
					is_char = true;
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

		switch (cmd_type)
		{
		case Command::Var:
		{
			if (arguments.size() != 2)
				throw "The argument to the command is invalid.";
			break;
		}

		case Command::Con:
		{
			if (arguments.size() != 2)
				throw "The argument to the command is invalid.";
			break;
		}

		case Command::Push:
		{
			if (arguments.size() != 1)
				throw "The argument to the command is invalid.";
			break;
		}

		case Command::Pop:
		{
			if (arguments.size() != 1)
				throw "The argument to the command is invalid.";
			break;
		}
		}

		return Command(cmd_type, arguments);
	}
}