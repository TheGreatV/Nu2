#pragma region Include

#pragma once

#include <../Common/Common.hpp>

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Nu
{
	namespace Lexer
	{
		using namespace Common;

		class Entity
		{
		public:
			virtual ~Entity() = default;
		};
		class Alphabet:
			public virtual Entity
		{
		public:
			using Character = WideString::value_type;
		public:
			class Quotation;
			class Brace;
		};
		class Token:
			public virtual Entity
		{
		public:
			using Offset = Size;
			using Length = Size;
			using Text = WideString;
		public:
			class Visitor;
			friend Visitor;
		public:
			class Whitespace;
			class Comment;
			class Special;
			class Identifier;
			class Literal;
			class Group;
		private:
			virtual void Accept(Visitor& visitor_) const = 0;
		public:
			virtual Offset GetOffset() const = 0;
			virtual Length GetLength() const = 0;
			virtual Text GetText() const = 0;
		};
#pragma region Token::Whitespace
		class Token::Whitespace:
			public virtual Token
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Comment
		class Token::Comment:
			public virtual Token
		{
		public:
			class Line;
			class Block;
			class Top;
			class Bottom;
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Comment::Line
		class Token::Comment::Line:
			public virtual Comment
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Comment::Block
		class Token::Comment::Block:
			public virtual Comment
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Comment::Top
		class Token::Comment::Top:
			public virtual Comment
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Comment::Bottom
		class Token::Comment::Bottom:
			public virtual Comment
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Special
		class Token::Special:
			public virtual Token
		{
		public:
			class Dot;
			class Comma;
			class Semicolon;
			class Colon;
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Special::Dot
		class Token::Special::Dot:
			public virtual Special
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Special::Comma
		class Token::Special::Comma:
			public virtual Special
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Special::Semicolon
		class Token::Special::Semicolon:
			public virtual Special
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Special::Colon
		class Token::Special::Colon:
			public virtual Special
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Identifier
		class Token::Identifier:
			public virtual Token
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion
#pragma region Token::Literal
		class Token::Literal:
			public virtual Token
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		public:
			virtual StrongPointer<Alphabet::Quotation> GetOpening() const = 0;
			virtual StrongPointer<Alphabet::Quotation> GetClosing() const = 0;
			virtual Text GetValue() const = 0;
		};
#pragma endregion
#pragma region Token::Group
		class Token::Group:
			public virtual Token
		{
		public:
			using Content = List<StrongPointer<Token>>;
		private:
			virtual void Accept(Visitor& visitor_) const override;
		public:
			virtual Content GetContent() const = 0;
			virtual StrongPointer<Alphabet::Brace> GetOpening() const = 0;
			virtual StrongPointer<Alphabet::Brace> GetClosing() const = 0;
			virtual Text GetValue() const = 0;
		};
#pragma endregion
#pragma region Token::Visitor
		class Token::Visitor:
			public virtual Entity
		{
		public:
			virtual void Visit(const Token& token_);
		public:
			virtual void Visit(const Token::Whitespace& token_);
			virtual void Visit(const Token::Comment& token_);
			virtual void Visit(const Token::Comment::Line& token_);
			virtual void Visit(const Token::Comment::Block& token_);
			virtual void Visit(const Token::Comment::Top& token_);
			virtual void Visit(const Token::Comment::Bottom& token_);
			virtual void Visit(const Token::Special& token_);
			virtual void Visit(const Token::Special::Dot& token_);
			virtual void Visit(const Token::Special::Comma& token_);
			virtual void Visit(const Token::Special::Semicolon& token_);
			virtual void Visit(const Token::Special::Colon& token_);
			virtual void Visit(const Token::Identifier& token_);
			virtual void Visit(const Token::Literal& token_);
			virtual void Visit(const Token::Group& token_);
		};
#pragma endregion
	}
}


#pragma region Nu

#pragma region Lexer
#pragma endregion

#pragma endregion


#pragma region Region
#pragma endregion



