#ifndef LIBLOW_HEADER_TYPES_BOOL_HH
#define LIBLOW_HEADER_TYPES_BOOL_HH

#include "../Object.hh"

namespace LibLow
{
	namespace Types
	{
		class Bool final : public Object
		{
		public:
			Bool() = default;
			Bool(const bool& value);
			Bool(const Bool& object);
			Bool(Bool&& object) noexcept;
			~Bool() = default;

		public:
			Bool& operator=(const Bool& object);
			Bool& operator=(Bool&& object) noexcept;
			bool operator==(const Bool& object) const noexcept;
			bool operator!=(const Bool& object) const noexcept;

		public:
			virtual LibLow::Type Type() const noexcept override;
			virtual SignedOption Signed() const noexcept override;

		public:
			bool Value() const;
			bool& Value();

		private:
			bool Value_ = false;
		};
	}
}

#endif