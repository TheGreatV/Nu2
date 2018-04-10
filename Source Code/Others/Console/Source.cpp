#include <../Common/Common.hpp>
#include <../Nu/Lexer/Lexer.hpp>


class Identifier :
	public Nu::Lexer::Token::Identifier
{
public:
	inline virtual Offset GetOffset() const override
	{
		throw 0;
	}
	inline virtual Length GetLength() const override
	{
		throw 0;
	}
	inline virtual Text GetText() const override
	{
		throw 0;
	}
};
class Visitor:
	public Nu::Lexer::Token::Visitor
{
public:
	virtual void Visit(const Nu::Lexer::Token::Identifier& token_) override
	{
	}
};


void main()
{
	auto t = new Identifier();
	auto b = (Nu::Lexer::Token*)t;
	auto v = new Visitor();

	v->Nu::Lexer::Token::Visitor::Visit(*b);
}