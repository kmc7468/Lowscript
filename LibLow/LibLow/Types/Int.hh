#ifndef LIBLOW_HEADER_TYPES_INT_HH
#define LIBLOW_HEADER_TYPES_INT_HH

#include "../Object.hh"

#include <cstdint>

namespace LibLow
{
	namespace Types
	{
		class Int final : public Object
		{
		public:
			Int() = default;
			Int(const std::int32_t& value);
			Int(const Int& object);
			Int(Int&& object) noexcept;
			~Int() = default;

		public:
			Int& operator=(const Int& object);
			Int& operator=(Int&& object) noexcept;
			bool operator==(const Int& object) const noexcept;
			bool operator!=(const Int& object) const noexcept;
			
		public:
			virtual LibLow::Type Type() const noexcept override;
			virtual SignedOption Signed() const noexcept override;

		public:
			std::int32_t Value() const;
			std::int32_t& Value();

		private:
			std::int32_t Value_ = 0;
		};
	}
}

#endif