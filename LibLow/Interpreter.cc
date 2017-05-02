#include "LibLow/Interpreter.hh"

#include <utility>

namespace LibLow
{
	Interpreter::Interpreter()
	{
#define R(name) Registers_.insert(std::make_pair<std::string, Object::Ptr>(name, nullptr))
		
		R("rax");
		R("rbx");
		R("rcx");
		R("rdx");

		R("eax");
		R("ebx");
		R("ecx");
		R("edx");
	}

	void Interpreter::Run(const Command& command)
	{
		
	}
}