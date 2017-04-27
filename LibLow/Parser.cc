#include "LibLow/Parser.hh"

#include "LibLow/Command.hh"

#include <algorithm>
#include <cctype>

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
		std::transform(line.begin(), line.end(), line.begin(), tolower);

		if (line_lower.find("nop") == 0)
		{
			if (line.length() != 3)
				throw "The argument to the command is invalid.";

			return Command(Command::Nop, {});
		}
		else if (line_lower.find("var") == 0)
		{
			// TODO
		}
		else if (line_lower.find("con") == 0)
		{
			// TODO
		}
		else if (line_lower.find("push") == 0)
		{
			// TODO
		}
		else if (line_lower.find("pop") == 0)
		{
			// TODO
		}
		else
			throw "Unknown command.";
	}
}