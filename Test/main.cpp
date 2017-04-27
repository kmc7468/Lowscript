#include <LibLow.hh>

int main()
{
	auto script = LibLow::Script::Create();

	auto interpreter = LibLow::Interpreter::Create(script);

	return 0;
}