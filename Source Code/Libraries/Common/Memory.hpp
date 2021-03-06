#pragma region Include

#pragma once

#include <cstdlib>

#include "Header.hpp"
#include "Size.hpp"

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Common
{
	using										Null = std::nullptr_t;
	template<class Type_> using					Memory = Type_*;


	template<class Type_> inline Memory<Type_>	AllocateMemory(const Size& size_ = 1);
	template<class Type_> inline void			ReleaseMemory(const Memory<Type_>& memory_);
	template<class Type_> inline void			FillMemory(const Memory<Type_>& destination_, const Type_& value_, const Size& amount_ = 1);
	template<class Type_> inline void			CopyMemory(const Memory<Type_>& destination_, const Memory<const Type_>& source_, const Size& amount_ = 1);
	template<class Type_> inline bool			CompareMemory(const Memory<const Type_>& memory1_, const Memory<const Type_>& memory2_, const Size& amount_ = 1);
}


#pragma region Common

template<class Type_> Common::Memory<Type_> Common::AllocateMemory(const Size& size_)
{
	auto memoryAmount = sizeof(Type_) * size_;
	auto rawMemory = std::malloc(memoryAmount);
	auto memory = static_cast<Memory<Type_>>(rawMemory);

	return memory;
}
template<class Type_> void Common::ReleaseMemory(const Memory<Type_>& memory_)
{
	std::free(memory_);
}
template<class Type_> void Common::FillMemory(const Memory<Type_>& destination_, const Type_& value_, const Size& amount_)
{
	std::memset(destination_, value_, sizeof(Type_)* amount_);
}
template<class Type_> void Common::CopyMemory(const Memory<Type_>& destination_, const Memory<const Type_>& source_, const Size& amount_)
{
	std::memcpy(destination_, source_, sizeof(Type_) * amount_);
}
template<class Type_> bool Common::CompareMemory(const Memory<const Type_>& memory1_, const Memory<const Type_>& memory2_, const Size& amount_)
{
	auto rawCompareResult = std::memcmp(memory1_, memory2_, sizeof(Type_) * amount_);

	return rawCompareResult == 0;
}

#pragma endregion


#pragma region
#pragma endregion


