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
						const auto the_none				= Parser::Make<Parser::None>();
						
						const auto operator_result		= the_none;
						const auto operator_arguments	= Parser::Operator::Arguments({});
						const auto the_operator			= Parser::Make<Parser::Operator>(operator_result, operator_arguments);

						// check result
						const auto result				= the_operator->GetResult();

						Assert::IsTrue(result == the_none);

						const auto result2				= the_operator->GetResult2();

						Assert::IsTrue(result2 == the_none);

						// check arguments
						const auto arguments			= the_operator->GetArguments();

						Assert::IsTrue(arguments.empty());

						const auto arguments2			= the_operator->GetArguments2();
						
						Assert::IsTrue(arguments2.empty());
					}
					TEST_METHOD(OperatorWithSingleArgument_None)
					{
						const auto the_none				= Parser::Make<Parser::None>();
						
						const auto operator_result		= the_none;
						const auto operator_arguments	= Parser::Operator::Arguments({ the_none });
						const auto the_operator			= Parser::Make<Parser::Operator>(operator_result, operator_arguments);

						// check result
						const auto result				= the_operator->GetResult();

						Assert::IsTrue(result == the_none);

						const auto result2				= the_operator->GetResult2();

						Assert::IsTrue(result2 == the_none);

						// check arguments
						const auto arguments			= the_operator->GetArguments();

						Assert::IsTrue(arguments.size() == 1);
						Assert::IsTrue(arguments[0] == the_none);

						const auto arguments2			= the_operator->GetArguments2();
						
						Assert::IsTrue(arguments2.size() == 1);
						Assert::IsTrue(arguments2[0] == the_none);
					}
					TEST_METHOD(OperatorWithSingleArgument_Sequence)
					{
						const auto sequence_elements	= Parser::Sequence::Elements();
						const auto the_sequence			= Parser::Make<Parser::Sequence>(sequence_elements);

						const auto the_none				= Parser::Make<Parser::None>();
						
						const auto operator_result		= the_none;
						const auto operator_arguments	= Parser::Operator::Arguments({ the_sequence });
						const auto the_operator			= Parser::Make<Parser::Operator>(operator_result, operator_arguments);

						// check result
						const auto result				= the_operator->GetResult();

						Assert::IsTrue(result == the_none);

						const auto result2				= the_operator->GetResult2();

						Assert::IsTrue(result2 == the_none);

						// check arguments
						const auto arguments			= the_operator->GetArguments();

						Assert::IsTrue(arguments.size() == 1);
						Assert::IsTrue(arguments[0] == the_sequence);

						const auto arguments2			= the_operator->GetArguments2();
						
						Assert::IsTrue(arguments2.size() == 1);
						Assert::IsTrue(arguments2[0] == the_sequence);
					}
				};
				TEST_CLASS(Sequence)
				{
					TEST_METHOD(EmptySequence)
					{
						const auto sequence_elements	= Parser::Sequence::Elements();
						const auto the_sequence			= Parser::Make<Parser::Sequence>(sequence_elements);

						const auto elements				= the_sequence->GetElements();
						
						Assert::IsTrue(elements.empty());
						
						const auto elements2			= the_sequence->GetElements2();
						
						Assert::IsTrue(elements2.empty());
					}
					TEST_METHOD(SequenceWithSingleElement_None)
					{
						const auto the_none				= Parser::Make<Parser::None>();

						const auto sequence_elements	= Parser::Sequence::Elements({ the_none });
						const auto the_sequence			= Parser::Make<Parser::Sequence>(sequence_elements);

						const auto elements				= the_sequence->GetElements();
						
						Assert::IsTrue(elements.size() == 1);
						Assert::IsTrue(elements[0] == the_none);

						const auto elements2			= the_sequence->GetElements2();
						
						Assert::IsTrue(elements2.size() == 1);
						Assert::IsTrue(elements2[0] == the_none);
					}
					TEST_METHOD(SequenceWithSingleElement_Sequence)
					{
						const auto the_argument_sequence	= Parser::Make<Parser::Sequence>(Parser::Sequence::Elements());

						const auto sequence_elements		= Parser::Sequence::Elements({ the_argument_sequence });
						const auto the_sequence				= Parser::Make<Parser::Sequence>(sequence_elements);

						const auto elements					= the_sequence->GetElements();
						
						Assert::IsTrue(elements.size() == 1);
						Assert::IsTrue(elements[0] == the_argument_sequence);

						const auto elements2				= the_sequence->GetElements2();
						
						Assert::IsTrue(elements2.size() == 1);
						Assert::IsTrue(elements2[0] == the_argument_sequence);
					}
				};
			}
		}
	}
}



