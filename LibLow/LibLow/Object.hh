#ifndef LIBLOW_HEADER_OBJECT_HH
#define LIBLOW_HEADER_OBJECT_HH

#include <cstddef>
#include <memory>

namespace LibLow
{
	enum class Type
	{
		Void,
		Bool,
		Int,
		Double,
	};

	constexpr std::size_t TypeSize[] =
	{
		0, // Void
		1, // Bool
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
		None = 0,
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
		Object& operator=(const Object& object) = delete;
		Object& operator=(Object&& object) noexcept = delete;
		bool operator==(const Object& object) const noexcept = delete;
		bool operator!=(const Object& object) const noexcept = delete;

	public:
		virtual Type Type() const noexcept = 0;
		virtual SignedOption Signed() const noexcept = 0;

		std::size_t Size() const noexcept;
	};
}

#endif