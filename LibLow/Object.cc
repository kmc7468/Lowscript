#include "LibLow/Object.hh"

namespace LibLow
{
	std::size_t Object::Size() const noexcept
	{
		return TypeSize[static_cast<int>(Type())];
	}
}