#include "LibLow/Variable.hh"

#include "LibLow/Types/Bool.hh"
#include "LibLow/Types/Double.hh"
#include "LibLow/Types/Int.hh"

namespace LibLow
{
	Variable::Variable(const Type& type)
		: Variable(type, TypeOption::None)
	{}
	Variable::Variable(const Type& type, const LibLow::TypeOption& type_option)
		: TypeOption_(type_option)
	{
		switch (type)
		{
		case Type::Bool:
		{
			Value_ = Types::Bool::Create();
			break;
		}

		case Type::Double:
		{
			Value_ = Types::Double::Create();
			break;
		}

		case Type::Int:
		{
			Value_ = Types::Int::Create();
			break;
		}

		default:
			throw "A type that cannot be instantiated.";
		}
	}

	const Object::Ptr Variable::Value() const
	{
		return Value_;
	}
	Object::Ptr Variable::Value()
	{
		return Value_;
	}
	TypeOption Variable::TypeOption() const noexcept
	{
		return TypeOption_;
	}
}