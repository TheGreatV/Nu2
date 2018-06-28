#pragma region Include

#pragma once

#include "Header.hpp"
#include "String.hpp"

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Common
{
	class Exception
	{
	public:
		using Text = String;
	protected:
		const Text text;
	public:
		inline Exception();
		inline Exception(const Text& text_);
	public:
		inline Text GetText() const;
	};
	class NotImplementedException:
		public Exception
	{
	public:
		inline NotImplementedException();
	};

}


#pragma region Common

#pragma region Exception

Common::Exception::Exception():
	Exception("Unknown exception.")
{
}
Common::Exception::Exception(const Text& text_):
	text(text_)
{
}
Common::Exception::Text Common::Exception::GetText() const
{
	return text;
}

#pragma endregion

#pragma region Exception

Common::NotImplementedException::NotImplementedException():
	Exception("Not implemented.")
{
}

#pragma endregion

#pragma endregion


#pragma region
#pragma endregion


