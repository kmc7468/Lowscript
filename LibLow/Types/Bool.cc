#include "../LibLow/Types/Bool.hh"

#include <utility>

namespace LibLow
{
	namespace Types
	{
		Bool::Bool(const bool& value)
			: Value_(value)
		{}
		Bool::Bool(const Bool& object)
			: Value_(object.Value_)
		{}
		Bool::Bool(Bool&& object) noexcept
			: Value_(std::move(object.Value_))
		{}

		Bool& Bool::operator=(const Bool& object)
		{
			Value_ = object.Value_;
			return *this;
		}
		Bool& Bool::operator=(Bool&& object) noexcept
		{
			Value_ = std::move(object.Value_);
			return *this;
		}
		bool Bool::operator==(const Bool& object) const noexcept
		{
			return Value_ == object.Value_;
		}
		bool Bool::operator!=(const Bool& object) const noexcept
		{
			return Value_ != object.Value_;
		}

		std::shared_ptr<Bool> Bool::Create()
		{
			return std::make_shared<Bool>();
		}
		std::shared_ptr<Bool> Bool::Create(const bool& value)
		{
			return std::make_shared<Bool>(value);
		}

		Type Bool::Type() const noexcept
		{
			return Type::Bool;
		}
		SignedOption Bool::Signed() const noexcept
		{
			return SignedOption::Signed;
		}

		bool Bool::Value() const
		{
			return Value_;
		}
		bool& Bool::Value()
		{
			return Value_;
		}
	}
}