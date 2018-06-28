#include <../Common/Common.hpp>
#include <../Nu/Lexer/Lexer.hpp>


void main()
{
	auto input = Common::WideString(L"'abc\\'\\\"xyz\"");
	auto parser = Nu::Lexer::Parser();

	parser.Parse(input);
}