#pragma region Include

#pragma once

#include "Interface.hpp"

#include <../Common/Common.hpp>

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Nu
{
	namespace Lexer
	{
		using namespace Common;

		class Parser
		{
		public:
			using Input = WideString;
		protected:
			using Offset = Size;
		protected:
			class Alphabet:
				public virtual Lexer::Alphabet
			{
			public:
				class Quotation:
					public virtual Lexer::Alphabet::Quotation
				{
				public:
					class Single;
					class Double;
				};
#pragma region Single
				class Quotation::Single:
					public Quotation
				{
				};
#pragma endregion
#pragma region Duoble
				class Quotation::Double:
					public Quotation
				{
				};
#pragma endregion
			public:
				inline virtual bool IsWhitespace(const Character& character_) const override;
				inline virtual bool IsLetter(const Character& character_) const override;
				inline virtual bool IsQuotation(const Character& character_) const override;
			public:
				inline StrongPointer<Quotation> GetQuotation(const Character& character_) const
				{
					if (character_ == L'\'')
					{
						return MakeStrong<Quotation::Single>();
					}
					else if (character_ == L'"')
					{
						return MakeStrong<Quotation::Double>();
					}
					else
					{
						throw Exception();
					}
				}
			};
			class Token:
				public virtual Lexer::Token
			{
			protected:
				const Offset offset;
				const Text text;
			public:
				class Whitespace;
				class Comment;
				class Special;
				class Identifier;
				class Literal;
				class Group;
			public:
				inline Token(const Offset& offset_, const Text& text_) : offset(offset_), text(text_)
				{
				}
			public:
				inline virtual Offset GetOffset() const override
				{
					return offset;
				}
				inline virtual Length GetLength() const override
				{
					return text.length();
				}
				inline virtual Text GetText() const override
				{
					return text;
				}
			};
#pragma region Token::Whitespace
		class Token::Whitespace:
			public virtual Lexer::Token::Whitespace,
			public Token
		{
		public:
			inline Whitespace(const Offset& offset_, const Text& text_) : Token(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Whitespace::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Comment
		class Token::Comment:
			public virtual Lexer::Token::Comment,
			public Token
		{
		public:
			class Line;
			class Block;
			class Top;
			class Bottom;
		public:
			inline Comment(const Offset& offset_, const Text& text_): Token(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Comment::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Comment::Line
		class Token::Comment::Line:
			public virtual Lexer::Token::Comment::Line,
			public Comment
		{
		public:
			inline Line(const Offset& offset_, const Text& text_): Comment(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Comment::Line::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
/*#pragma region Token::Comment::Block
		class Token::Comment::Block:
			public virtual Comment
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion*/
#pragma region Token::Comment::Top
		class Token::Comment::Top:
			public virtual Lexer::Token::Comment::Top,
			public Comment
		{
		public:
			inline Top(const Offset& offset_, const Text& text_): Comment(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Comment::Top::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
/*#pragma region Token::Comment::Bottom
		class Token::Comment::Bottom:
			public virtual Comment
		{
		private:
			virtual void Accept(Visitor& visitor_) const override;
		};
#pragma endregion*/
#pragma region Token::Special
		class Token::Special:
			public virtual Lexer::Token::Special,
			public Token
		{
		public:
			class Dot;
			class Comma;
			class Semicolon;
			class Colon;
		public:
			inline Special(const Offset& offset_, const Text& text_) : Token(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Special::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Special::Dot
		class Token::Special::Dot:
			public virtual Lexer::Token::Special::Dot,
			public Special
		{
		public:
			inline Dot(const Offset& offset_, const Text& text_) : Special(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Special::Dot::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Special::Comma
		class Token::Special::Comma:
			public virtual Lexer::Token::Special::Comma,
			public Special
		{
		public:
			inline Comma(const Offset& offset_, const Text& text_) : Special(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Special::Comma::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Special::Semicolon
		class Token::Special::Semicolon:
			public virtual Lexer::Token::Special::Semicolon,
			public Special
		{
		public:
			inline Semicolon(const Offset& offset_, const Text& text_) : Special(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Special::Semicolon::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Special::Colon
		class Token::Special::Colon:
			public virtual Lexer::Token::Special::Colon,
			public Special
		{
		public:
			inline Colon(const Offset& offset_, const Text& text_) : Special(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Special::Colon::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Identifier
		class Token::Identifier:
			public virtual Lexer::Token::Identifier,
			public Token
		{
		public:
			inline Identifier(const Offset& offset_, const Text& text_) : Token(offset_, text_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Identifier::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		};
#pragma endregion
#pragma region Token::Literal
		class Token::Literal:
			public virtual Lexer::Token::Literal,
			public Token
		{
		protected:
			const StrongPointer<Alphabet::Quotation> opening;
			const StrongPointer<Alphabet::Quotation> closing;
		public:
			inline Literal(const StrongPointer<Alphabet::Quotation>& opening_, const StrongPointer<Alphabet::Quotation>& closing_, const Offset& offset_, const Text& text_) : Token(offset_, text_), opening(opening_), closing(closing_)
			{
			}
		protected:
			inline virtual void Accept(Visitor& visitor_) const override
			{
				Lexer::Token::Literal::Accept(visitor_);
			}
		public:
			inline virtual Offset GetOffset() const override
			{
				return Token::GetOffset();
			}
			inline virtual Length GetLength() const override
			{
				return Token::GetLength();
			}
			inline virtual Text GetText() const override
			{
				return Token::GetText();
			}
		public:
			inline virtual StrongPointer<Lexer::Alphabet::Quotation> GetOpening() const override
			{
				return opening;
			}
			inline virtual StrongPointer<Lexer::Alphabet::Quotation> GetClosing() const override
			{
				return closing;
			}
			inline virtual Text GetValue() const override
			{
				auto &text = GetText();

				return text.substr(1, text.length() - 2);
			}
		};
#pragma endregion
		protected:
			inline static Offset End()
			{
				return std::numeric_limits<Offset>::max();
			}
		public:
			inline void Parse(const Input& input_) const;
		};
	}
}


#pragma region Nu

#pragma region Lexer

#pragma region Parser

#pragma region Parser

bool Nu::Lexer::Parser::Alphabet::IsWhitespace(const Character& character_) const
{
	return
		character_ == L' ' ||
		character_ == L'\t' ||
		character_ == L'\n' ||
		character_ == L'\r';
}
bool Nu::Lexer::Parser::Alphabet::IsLetter(const Character& character_) const
{
	return
		character_ == L'a' || character_ == L'A' ||
		character_ == L'b' || character_ == L'B' ||
		character_ == L'c' || character_ == L'C' ||
		character_ == L'd' || character_ == L'D' ||
		character_ == L'e' || character_ == L'E' ||
		character_ == L'f' || character_ == L'F' ||
		character_ == L'g' || character_ == L'G' ||
		character_ == L'h' || character_ == L'H' ||
		character_ == L'i' || character_ == L'I' ||
		character_ == L'j' || character_ == L'J' ||
		character_ == L'k' || character_ == L'K' ||
		character_ == L'l' || character_ == L'L' ||
		character_ == L'm' || character_ == L'M' ||
		character_ == L'n' || character_ == L'N' ||
		character_ == L'o' || character_ == L'O' ||
		character_ == L'p' || character_ == L'P' ||
		character_ == L'q' || character_ == L'Q' ||
		character_ == L'r' || character_ == L'R' ||
		character_ == L's' || character_ == L'S' ||
		character_ == L't' || character_ == L'T' ||
		character_ == L'u' || character_ == L'U' ||
		character_ == L'v' || character_ == L'V' ||
		character_ == L'w' || character_ == L'W' ||
		character_ == L'x' || character_ == L'X' ||
		character_ == L'y' || character_ == L'Y' ||
		character_ == L'z' || character_ == L'Z' ||

		character_ == L'0' ||
		character_ == L'1' ||
		character_ == L'2' ||
		character_ == L'3' ||
		character_ == L'4' ||
		character_ == L'5' ||
		character_ == L'6' ||
		character_ == L'7' ||
		character_ == L'8' ||
		character_ == L'9' ||

		character_ == L'~' ||
		character_ == L'!' ||
		character_ == L'@' ||
		character_ == L'#' ||
		character_ == L'$' ||
		character_ == L'%' ||
		character_ == L'^' ||
		character_ == L'&' ||
		character_ == L'*' ||
		character_ == L'_' ||
		character_ == L'-' ||
		character_ == L'+' ||
		character_ == L'=' ||
		character_ == L'<' ||
		character_ == L'>' ||
		character_ == L'?' ||
		character_ == L'/' ||
		character_ == L'\\' ||
		character_ == L'|';
}
bool Nu::Lexer::Parser::Alphabet::IsQuotation(const Character& character_) const
{
	return
		character_ == L'\'' ||
		character_ == L'"';
}

#pragma endregion


void Nu::Lexer::Parser::Parse(const Input& input_) const
{
	auto const length		= input_.size();
	auto const alphabet		= Alphabet();

	Offset position = 0;

	while (position < length)
	{
		auto const character	= input_[position];
		auto const tokenOffset	= position++;

		if (alphabet.IsWhitespace(character))
		{
			while (position < length && alphabet.IsWhitespace(input_[position]))
			{
				++position;
			}

			auto const tokenLength	= position - tokenOffset;
			auto const tokenText	= input_.substr(tokenOffset, tokenLength);
			auto const token		= MakeStrong<Token::Whitespace>(tokenOffset, tokenText);
		}
		else if (alphabet.IsLetter(character))
		{
			while (position < length && alphabet.IsLetter(input_[position]))
			{
				++position;
			}

			auto const tokenLength	= position - tokenOffset;
			auto const tokenText	= input_.substr(tokenOffset, tokenLength);
			auto const token		= MakeStrong<Token::Identifier>(tokenOffset, tokenText);
		}
		else if (alphabet.IsQuotation(character))
		{
			auto const opening = alphabet.GetQuotation(character); // TODO: check != null
			
			while (true)
			{
				if (position >= length)
				{
					throw Exception();
				}

				auto const character = input_[position++];

				if (alphabet.IsQuotation(character)) // closing quotation
				{
					auto const closing		= alphabet.GetQuotation(character); // TODO: check != null
					auto const tokenLength	= position - tokenOffset;
					auto const tokenText	= input_.substr(tokenOffset, tokenLength);
					auto const token = MakeStrong<Token::Literal>(opening, closing, tokenOffset, tokenText);
				}
				else if (character == L'\\') // screening
				{
					if (position >= length)
					{
						throw Exception();
					}
					
					auto const character = input_[position++];

					if (!alphabet.IsQuotation(character) && character != L'\\')
					{
						throw Exception(); // unsupported screened character
					}
				}
			}

			auto const tokenLength = position - tokenOffset;
			auto const tokenText = input_.substr(tokenOffset, tokenLength);
			auto const token = MakeStrong<Token::Identifier>(tokenOffset, tokenText);
		}
		else if (character == L'.')
		{
			auto const tokenLength	= position - tokenOffset;
			auto const tokenText	= input_.substr(tokenOffset, tokenLength);
			auto const token		= MakeStrong<Token::Special::Dot>(tokenOffset, tokenText);
		}
		else if (character == L',')
		{
			auto const tokenLength	= position - tokenOffset;
			auto const tokenText	= input_.substr(tokenOffset, tokenLength);
			auto const token		= MakeStrong<Token::Special::Comma>(tokenOffset, tokenText);
		}
		else if (character == L':')
		{
			auto const tokenLength	= position - tokenOffset;
			auto const tokenText	= input_.substr(tokenOffset, tokenLength);
			auto const token		= MakeStrong<Token::Special::Colon>(tokenOffset, tokenText);
		}
		else if (character == L';')
		{
			auto const tokenLength	= position - tokenOffset;
			auto const tokenText	= input_.substr(tokenOffset, tokenLength);
			auto const token		= MakeStrong<Token::Special::Semicolon>(tokenOffset, tokenText);
		}
		else
		{
			throw Exception();
		}
	}


	/*// scan for top comment
	auto blockCommentOpeningOffset = FindBlockCommentOpeningOffset(input_, offset);
	auto blockCommentEndingOffset = FindBlockCommentClosingOffset(input_, offset);
	auto quotationOffset = FindQuotationOffset(input_, offset, alphabet);

	if (blockCommentEndingOffset < blockCommentOpeningOffset && blockCommentEndingOffset < quotationOffset)
	{
		auto length = blockCommentEndingOffset - offset;
		auto text = input_.substr(offset, length - offset);
		auto topComment = MakeStrong<Token::Comment::Top>(offset, text);
	}*/
}

#pragma endregion

#pragma endregion

#pragma endregion


#pragma region Region
#pragma endregion



