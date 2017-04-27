#ifndef LIBLOW_HEADER_VARIABLE_HH
#define LIBLOW_HEADER_VARIABLE_HH

#include "Object.hh"

#include <memory>
#include <string>

namespace LibLow
{
	class Variable final
	{
	public:
		using Ptr = std::shared_ptr<Variable>;

	public:
		Variable(const std::string& name, const Type& type);
		Variable(const std::string& name, const Type& type, const TypeOption& type_option);
		Variable(const Variable& variable) = delete;
		Variable(Variable&& variable) noexcept = delete;
		~Variable() = default;

	public:
		const Object::Ptr Value() const;
		Object::Ptr Value();
		TypeOption TypeOption() const noexcept;
		std::string Name() const;

	private:
		Object::Ptr Value_ = nullptr;
		LibLow::TypeOption TypeOption_ = TypeOption::None;
		std::string Name_;
	};
}

#endif