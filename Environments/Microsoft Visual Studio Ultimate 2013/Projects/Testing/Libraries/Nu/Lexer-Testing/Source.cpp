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
			using namespace Common;
			using namespace ::Nu::Lexer;

			TEST_CLASS(SmokeTest)
			{
			protected:
				inline Vector<StrongPointer<Token>> Parse(const Parser::Input& input_) // TODO: add output
				{
					auto const parser = Parser();
					auto const output = Move(parser.Parse(input_));

					return Move(ToVector(output));
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
					Parse(L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*-=_+<>?|\\/");
				}
				TEST_METHOD(Literals)
				{
					Parse(L"'abc\\'xyz\\\"ikj\\\\nml\"");
				}
				TEST_METHOD(Groups)
				{
					Parse(L"()(}(]{){}{][)[}[]((()))");
				}
			public:
				TEST_METHOD(Comment_Combined)
				{
					auto tokens = Move(Parse(Common::WideString() +
						L"abc"							+ L"\n" +
						L"`\\ def \\`"					+ L"\n" +
						L"`/ ghi \\`"					+ L"\n" +
						L"`\\ `\\ `/ jkl \\`"			+ L"\n" +
						L"\\` \\`"						+ L"\n" +
						L"\\`"							+ L"\n" +
						L"mno"							+ L"\n" +
						L"`\\"							+ L"\n" +
						L"`\\ `\\ `/ pqr \\`"			+ L"\n" +
						L"\\` \\`"						+ L"\n" +
						L"`\\ stu \\`"					+ L"\n" +
						L"vwx"							+ L"\n" +
					L""));

					Assert::IsTrue(tokens.size() == 5);

					Assert::IsTrue(DynamicCast<Token::Comment::Top>(tokens[0]) != nullptr);
					Assert::IsTrue(DynamicCast<Token::Comment::Whitespace>(tokens[1]) != nullptr);
					Assert::IsTrue(DynamicCast<Token::Comment::Identifier>(tokens[2]) != nullptr);
					Assert::IsTrue(DynamicCast<Token::Comment::Whitespace>(tokens[3]) != nullptr);
					Assert::IsTrue(DynamicCast<Token::Comment::Bottom>(tokens[4]) != nullptr);
				}
				TEST_METHOD(Comment_Line)
				{
					auto &tokens = Move(Parse(Common::WideString() +
						L"abc`/def" + L"\n" +
					L""));
				}
				TEST_METHOD(Comment_Top)
				{
					Parse(L"abc\\`def");
				}
				TEST_METHOD(Comment_TopNested)
				{
					Parse(L"abc`\\def\\`ghi\\`jkl");
				}
				TEST_METHOD(Comment_DoubleTop)
				{
					Parse(L"abc\\`def\\`ghi");
				}
				TEST_METHOD(Comment_DoubleTopNested)
				{
					Parse(L"abc`\\def\\`ghi\\`jkl\\`mno");
				}
				TEST_METHOD(Comment_Bottom)
				{
					Parse(L"uvw`\\xyz");
				}
				TEST_METHOD(Comment_BottomNested)
				{
					Parse(L"opq`\\rst`\\uvw\\`xyz");
				}
				TEST_METHOD(Comment_DoubleBottom)
				{
					Parse(L"rst`\\uvw`\\xyz");
				}
				TEST_METHOD(Comment_DoubleBottomNested)
				{
					Parse(L"lnm`\\opq`\\rst`\\uvw\\`xyz");
				}
			};
		}
	}
}