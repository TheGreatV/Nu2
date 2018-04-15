#pragma region Include

#pragma once

#include <utility>

#include "Header.hpp"

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Common
{
	template<class Type_> using Unreferenced = typename std::remove_reference<Type_>::type;

	template<class Type_> inline typename Unreferenced<Type_>&&		Move(Type_&& type_);
	template<class Type_> inline Type_&&							Forward(typename Unreferenced<Type_>& type_);
}


#pragma region Common	

template<class Type_>
inline typename Common::Unreferenced<Type_>&& Common::Move<Type_>(Type_&& type_)
{
	return std::move(type_);
}

template<class Type_>
inline Type_&& Common::Forward<Type_>(typename Unreferenced<Type_>& type_)
{
	return std::forward<Type_>(type_);
}

#pragma endregion


#pragma region
#pragma endregion


