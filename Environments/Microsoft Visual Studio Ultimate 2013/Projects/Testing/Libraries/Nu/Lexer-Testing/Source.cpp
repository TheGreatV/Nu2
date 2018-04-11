#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <../Nu/Lexer/Lexer.hpp>

namespace Testing
{
	namespace Nu
	{
		namespace Lexer
		{
			using namespace ::Nu::Lexer;

			TEST_CLASS(SmokeTest)
			{
			protected:
				inline void Parse(const Parser::Input& input_) // TODO: add output
				{
					auto parser = Parser();

					parser.Parse(input_);
				}
			public:
				TEST_METHOD(Whitespaces)
				{
					Parse(L" \t\n\r");
				}
				TEST_METHOD(Specials)
				{
					Parse(L".,;:");
				}
				TEST_METHOD(Identifiers)
				{
					Parse(L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*-=_+<>?|\/");
				}
				TEST_METHOD(Literals)
				{
					Parse(L"'abc\\'xyz\\\"ikj\\\\nml\"");
				}
			};
		}
	}
}