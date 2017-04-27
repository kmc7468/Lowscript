#include "../LibLow/Types/Int.hh"

#include <utility>

namespace LibLow
{
	namespace Types
	{
		Int::Int(const std::int32_t& value)
			: Value_(value)
		{}
		Int::Int(const Int& object)
			: Value_(object.Value_)
		{}
		Int::Int(Int&& object) noexcept
			: Value_(std::move(object.Value_))
		{}

		Int& Int::operator=(const Int& object)
		{
			Value_ = object.Value_;
			return *this;
		}
		Int& Int::operator=(Int&& object) noexcept
		{
			Value_ = std::move(object.Value_);
			return *this;
		}
		bool Int::operator==(const Int& object) const noexcept
		{
			return Value_ == object.Value_;
		}
		bool Int::operator!=(const Int& object) const noexcept
		{
			return Value_ != object.Value_;
		}

		Type Int::Type() const noexcept
		{
			return Type::Int;
		}
		SignedOption Int::Signed() const noexcept
		{
			return SignedOption::Signed;
		}

		std::int32_t Int::Value() const
		{
			return Value_;
		}
		std::int32_t& Int::Value()
		{
			return Value_;
		}
	}
}