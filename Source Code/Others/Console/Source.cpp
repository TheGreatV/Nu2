#include <../Common/Common.hpp>
#include <../Nu/Lexer/Lexer.hpp>
#include <../Parser/Parser.hpp>


void main()
{
	Nu::Lexer::Parser lexer;

	auto lexerOutput = lexer.Parse(L"a:");

	Nu::Parsing::Parser parser;

	// parser.Parse(lexerOutput);
}