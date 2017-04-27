#include "../LibLow/Types/Double.hh"

#include <utility>

namespace LibLow
{
	namespace Types
	{
		Double::Double(const double& value)
			: Value_(value)
		{}
		Double::Double(const Double& object)
			: Value_(object.Value_)
		{}
		Double::Double(Double&& object) noexcept
			: Value_(std::move(object.Value_))
		{}

		Double& Double::operator=(const Double& object)
		{
			Value_ = object.Value_;
			return *this;
		}
		Double& Double::operator=(Double&& object) noexcept
		{
			Value_ = std::move(object.Value_);
			return *this;
		}
		bool Double::operator==(const Double& object) const noexcept
		{
			return Value_ == object.Value_;
		}
		bool Double::operator!=(const Double& object) const noexcept
		{
			return Value_ != object.Value_;
		}

		std::shared_ptr<Double> Double::Create()
		{
			return std::make_shared<Double>();
		}
		std::shared_ptr<Double> Double::Create(const double& value)
		{
			return std::make_shared<Double>(value);
		}

		Type Double::Type() const noexcept
		{
			return Type::Double;
		}
		SignedOption Double::Signed() const noexcept
		{
			return SignedOption::Signed;
		}

		double Double::Value() const
		{
			return Value_;
		}
		double& Double::Value()
		{
			return Value_;
		}
	}
}