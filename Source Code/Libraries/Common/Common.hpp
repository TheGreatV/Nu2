#pragma region Include

#pragma once

#include <string>
#include <list>
#include <memory>

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Common
{
	using Size									= std::size_t;

	using String								= std::string;
	using WideString							= std::wstring;

	template<class Type_> using List			= std::list<Type_>;
	template<class Type_> using StrongPointer	= std::shared_ptr<Type_>;

	template<class Type_, class... Arguments_> StrongPointer<Type_> MakeStrong(Arguments_&&... arguments)
	{
		return std::make_shared<Type_>(std::forward<Arguments_>(arguments)...);
	}
	template<class DestinationType_, class SourceType_> StrongPointer<DestinationType_> StaticCast(const StrongPointer<SourceType_>& source_)
	{
		return std::static_pointer_cast<DestinationType_>(source_);
	}
	template<class DestinationType_, class SourceType_> StrongPointer<DestinationType_> DynamicCast(const StrongPointer<SourceType_>& source_)
	{
		return std::dynamic_pointer_cast<DestinationType_>(source_);
	}

	class Exception
	{
	};
	class NotImplementedException:
		public Exception
	{
	};
}


#pragma region Common
#pragma endregion


#pragma region Region
#pragma endregion



