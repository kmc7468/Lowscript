#ifndef LIBLOW_HEADER_TYPES_DOUBLE_HH
#define LIBLOW_HEADER_TYPES_DOUBLE_HH

#include "../Object.hh"

#include <memory>

namespace LibLow
{
	namespace Types
	{
		class Double final : public Object
		{
		public:
			Double() = default;
			Double(const double& value);
			Double(const Double& object);
			Double(Double&& object) noexcept;
			~Double() = default;

		public:
			Double& operator=(const Double& object);
			Double& operator=(Double&& object) noexcept;
			bool operator==(const Double& object) const noexcept;
			bool operator!=(const Double& object) const noexcept;

		public:
			static std::shared_ptr<Double> Create();
			static std::shared_ptr<Double> Create(const double& value);

		public:
			virtual LibLow::Type Type() const noexcept override;
			virtual SignedOption Signed() const noexcept override;

		public:
			double Value() const;
			double& Value();

		private:
			double Value_ = 0.0;
		};
	}
}

#endif