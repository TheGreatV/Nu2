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
			using namespace ::Nu::Parser;

			TEST_CLASS(SmokeTest)
			{
			public:
				TEST_METHOD(Whitespaces)
				{
					Parser::NamesSolver solver;

					solver.Solve(L"");
				}
			};
		}
	}
}