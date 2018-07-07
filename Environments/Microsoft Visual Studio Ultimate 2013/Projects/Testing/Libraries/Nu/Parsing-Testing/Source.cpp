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

			namespace Sandbox
			{
				TEST_CLASS(Operator)
				{
					TEST_METHOD(EmptyOperator)
					{
						auto the_none			= Parser::Make<Parser::None>();

						auto operator_result	= the_none;
						auto operator_arguments	= Parser::Operator::Arguments({});
						auto operator_body		= the_none;
						auto the_operator		= Parser::Make<Parser::Operator>(operator_result, operator_arguments, operator_body);

						the_operator->GetResult();
						the_operator->GetResult2();

						the_operator->GetArguments();
						the_operator->GetArguments2();

						the_operator->GetBody();
						the_operator->GetBody2();
					}
				};
			}
		}
	}
}



