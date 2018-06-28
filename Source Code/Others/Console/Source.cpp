#include <../Common/Common.hpp>
#include <../Nu/Lexer/Lexer.hpp>
#include <../Nu/Parser/Parser.hpp>


void main()
{
	auto input = Common::WideString(L"'abc\\'\\\"xyz\"");
	auto lexer = Nu::Lexer::Parser();

	auto tokens = lexer.Parse(input);
}