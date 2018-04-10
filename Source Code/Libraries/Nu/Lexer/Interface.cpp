#include "Interface.hpp"


#pragma region Nu

#pragma region Lexer

#pragma region Token

#pragma region Visitor

void Nu::Lexer::Token::Visitor::Visit(const Token& token_)
{
	token_.Accept(*this);
}

void Nu::Lexer::Token::Visitor::Visit(const Token::Whitespace& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Comment& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Comment::Line& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Comment::Block& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Comment::Top& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Comment::Bottom& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Special& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Special::Dot& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Special::Comma& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Special::Semicolon& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Special::Colon& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Identifier& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Literal& token_)
{
}
void Nu::Lexer::Token::Visitor::Visit(const Token::Group& token_)
{
}

#pragma endregion

#pragma endregion

#pragma region Token::Comment

void Nu::Lexer::Token::Comment::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Comment::Line

void Nu::Lexer::Token::Comment::Line::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Comment::Block

void Nu::Lexer::Token::Comment::Block::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Comment::Top

void Nu::Lexer::Token::Comment::Top::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Comment::Bottom

void Nu::Lexer::Token::Comment::Bottom::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Special

void Nu::Lexer::Token::Special::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Special::Dot

void Nu::Lexer::Token::Special::Dot::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Special::Comma

void Nu::Lexer::Token::Special::Comma::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Special::Semicolon

void Nu::Lexer::Token::Special::Semicolon::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Special::Colon

void Nu::Lexer::Token::Special::Colon::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Identifier

void Nu::Lexer::Token::Identifier::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Literal

void Nu::Lexer::Token::Literal::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion
#pragma region Token::Group

void Nu::Lexer::Token::Group::Accept(Visitor& visitor_) const
{
	visitor_.Visit(*this);
}

#pragma endregion

#pragma endregion

#pragma endregion

#pragma endregion



