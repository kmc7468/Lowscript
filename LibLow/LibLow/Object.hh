#ifndef LIBLOW_HEADER_OBJECT_HH
#define LIBLOW_HEADER_OBJECT_HH

#include <cstddef>
#include <memory>

namespace LibLow
{
	enum class Type
	{
		Void,
		Int,
		Double,
	};

	constexpr std::size_t TypeSize[] =
	{
		0, // Void
		4, // Int
		8, // Double
	};

	enum class SignedOption
	{
		Unsigned,
		Signed,
	};

	enum class TypeOption
	{
		Const = 1,
	};

	class Object
	{
	public:
		using Ptr = std::shared_ptr<Object>;

	public:
		virtual ~Object() = default;
		
	protected:
		Object() = default;
		Object(const Object& object) = delete;
		Object(Object&& object) noexcept = delete;

	public:
		virtual Type Type() const noexcept = 0;
		virtual SignedOption Signed() const noexcept = 0;

		std::size_t Size() const noexcept;
	};
}

#endif