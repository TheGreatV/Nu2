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
					TEST_METHOD(OperatorWithSingleArgument_Instance)
					{
						const auto the_none				= Parser::Make<Parser::None>();
						
						const auto the_interface		= Parser::Make<Parser::Interface>();
						const auto the_instance			= Parser::Make<Parser::Instance>(the_interface);

						const auto operator_result		= the_none;
						const auto operator_arguments	= Parser::Operator::Arguments({ the_instance });
						const auto the_operator			= Parser::Make<Parser::Operator>(operator_result, operator_arguments);

						// check result
						const auto result				= the_operator->GetResult();

						Assert::IsTrue(result == the_none);

						const auto result2				= the_operator->GetResult2();

						Assert::IsTrue(result2 == the_none);

						// check arguments
						const auto arguments			= the_operator->GetArguments();

						Assert::IsTrue(arguments.size() == 1);
						Assert::IsTrue(arguments[0] == the_instance);

						const auto arguments2			= the_operator->GetArguments2();
						
						Assert::IsTrue(arguments2.size() == 1);
						Assert::IsTrue(arguments2[0] == the_instance);
					}
				};
				TEST_CLASS(OperatorOrder)
				{
					TEST_METHOD(EmptyOperatorOrder_LeftOperator)
					{
						const auto the_none				= Parser::Make<Parser::None>();
						
						const auto operator_result		= the_none;
						const auto operator_arguments	= Parser::Operator::Arguments({});
						const auto the_operator			= Parser::Make<Parser::Operator>(operator_result, operator_arguments);

						const auto order_argument_left	= Parser::Make<Parser::Operator::Order::Argument::Left>(the_operator);

						const auto the_order			= Parser::Make<Parser::Operator::Order>(order_argument_left);

						// check operator
						const auto order_argument		= the_order->GetArgument();

						Assert::IsTrue(order_argument == order_argument_left);
						
						const auto order_argument2		= the_order->GetArgument2();

						Assert::IsTrue(order_argument2 == order_argument_left);
						
						// check order
						const auto order_order			= the_order->GetOrder();

						Assert::IsTrue(order_order == nullptr);
						
						const auto order_order2			= the_order->GetOrder2();

						Assert::IsTrue(order_order2 == nullptr);
					}
					TEST_METHOD(EmptyOperatorOrder_RightOperator)
					{
						const auto the_none				= Parser::Make<Parser::None>();
						
						const auto operator_result		= the_none;
						const auto operator_arguments	= Parser::Operator::Arguments({});
						const auto the_operator			= Parser::Make<Parser::Operator>(operator_result, operator_arguments);

						const auto order_argument_right	= Parser::Make<Parser::Operator::Order::Argument::Right>(the_operator);

						const auto the_order			= Parser::Make<Parser::Operator::Order>(order_argument_right);

						// check operator
						const auto order_argument		= the_order->GetArgument();

						Assert::IsTrue(order_argument == order_argument_right);
						
						const auto order_argument2		= the_order->GetArgument2();

						Assert::IsTrue(order_argument2 == order_argument_right);
						
						// check order
						const auto order_order			= the_order->GetOrder();

						Assert::IsTrue(order_order == nullptr);
						
						const auto order_order2			= the_order->GetOrder2();

						Assert::IsTrue(order_order2 == nullptr);
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
				TEST_CLASS(Interface)
				{
					TEST_METHOD(CommonInterface)
					{
						const auto the_interface = Parser::Make<Parser::Interface>();

						// interface
						const auto interface_instanceable_interface		= the_interface->GetInterface();

						Assert::IsTrue(interface_instanceable_interface == the_interface);
						
						const auto interface_instanceable_interface2	= the_interface->GetInterface2();

						Assert::IsTrue(interface_instanceable_interface2 == the_interface);
					}
				};
				TEST_CLASS(Instance)
				{
					TEST_METHOD(InterfaceInstance)
					{
						const auto the_interface	= Parser::Make<Parser::Interface>();
						const auto the_instance		= Parser::Make<Parser::Instance>(the_interface);
						
						// const auto sequence_elements	= Parser::Sequence::Elements();
						// const auto the_sequence			= Parser::Make<Parser::Sequence>(sequence_elements);
						// 
						// const auto elements				= the_sequence->GetElements();
						// 
						// Assert::IsTrue(elements.empty());
						// 
						// const auto elements2			= the_sequence->GetElements2();
						// 
						// Assert::IsTrue(elements2.empty());
					}
				};
			}
		}
	}
}



