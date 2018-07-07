#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <../Nu/Parser/Parser.hpp>

namespace Testing
{
	namespace Nu
	{
		namespace Lexer
		{
			using namespace Common;
			using namespace ::Nu::Parsing;

			TEST_CLASS(SandboxTest)
			{
				TEST_METHOD(Test1)
				{
					auto operator_result	= Parser::Make<Parser::None>();
					auto the_operator		= Parser::Make<Parser::Operator>(operator_result);

					the_operator->GetResult();
					the_operator->GetResult2();
				}
			};
		}
	}
}



