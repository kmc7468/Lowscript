#include <LibLow.hh>

int main()
{
	auto c = LibLow::Parser::ParseLine("mov a,b");
	auto c_str = c.ToString();

	return 0;
}