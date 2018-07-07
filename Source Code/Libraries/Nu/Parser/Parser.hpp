#pragma region Include

#pragma once

#include "Interface.hpp"

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Nu
{
	namespace Parsing
	{
		using namespace Common;


		class Parser;


		class Parser
		{
		public:
			using Input = Lexer::Parser::Output;
		public:
			class Entity;
			class Named;
			class Operator;
			class None;
		public:
			template<class Type_, class... Arguments_> inline static StrongPointer<Type_> Make(Arguments_&&... arguments_);
		public:
			inline void Parse(const Input& input_);
		};
#pragma region Parser::Entity
		class Parser::Entity:
			public Parsing::Entity,
			public This<Entity>
		{
		public:
			inline Entity(const StrongPointer<Entity>& this_);
			inline ~Entity() override = default;
		};
#pragma endregion
#pragma region Parser::Named
		class Parser::Named:
			public Parsing::Named,
			public virtual Entity
		{
		public:
			inline Named(const StrongPointer<Named>& this_);
			inline ~Named() override = default;
		};
#pragma endregion
#pragma region Parser::Operator
		class Parser::Operator:
			public Parsing::Operator,
			public Named
		{
		protected:
			using Abstraction = Parsing::Operator;
		public:
			class Result;
		protected:
			const StrongPointer<Result> result;
		public:
			inline Operator(const StrongPointer<Operator>& this_, const StrongPointer<Result>& result_);
			inline ~Operator() override = default;
		public:
			inline StrongPointer<Abstraction::Result>	GetResult() const override;
			inline Abstraction::Arguments				GetArguments() const override;
			inline StrongPointer<Abstraction::Body>		GetBody() const override;
		public:
			inline StrongPointer<Result>				GetResult2() const;
		};
#pragma endregion
#pragma region Parser::Operator::Result
		class Parser::Operator::Result:
			public Parsing::Operator::Result,
			public virtual Parser::Entity
		{
		protected:
			using Abstraction = Parsing::Operator;
		public:
			inline Result(const StrongPointer<Result>& this_);
			inline ~Result() override = default;
		};
#pragma endregion
#pragma region Parser::None
		class Parser::None:
			public Parsing::None,
			public virtual Entity,
			public Operator::Result
		{
		public:
			inline None(const StrongPointer<None>& this_);
			inline ~None() override = default;
		};
#pragma endregion
	}
}


#pragma region Nu

#pragma region Parser

#pragma region Entity

Nu::Parsing::Parser::Entity::Entity(const Common::StrongPointer<Entity>& this_):
	This(this_)
{
}

#pragma endregion

#pragma region Named

Nu::Parsing::Parser::Named::Named(const Common::StrongPointer<Named>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion

#pragma region Operator

#pragma region Operator

Nu::Parsing::Parser::Operator::Result::Result(const Common::StrongPointer<Result>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion


Nu::Parsing::Parser::Operator::Operator(const Common::StrongPointer<Operator>& this_, const Common::StrongPointer<Result>& result_):
	Parser::Entity(this_),
	Parser::Named(this_),
	result(result_)
{
}

Common::StrongPointer<Nu::Parsing::Parser::Operator::Abstraction::Result> Nu::Parsing::Parser::Operator::GetResult() const
{
	return result;
}
Nu::Parsing::Parser::Operator::Abstraction::Arguments Nu::Parsing::Parser::Operator::GetArguments() const
{
	throw NotImplementedException();
}
Common::StrongPointer<Nu::Parsing::Parser::Operator::Abstraction::Body> Nu::Parsing::Parser::Operator::GetBody() const
{
	throw NotImplementedException();
}

Common::StrongPointer<Nu::Parsing::Parser::Operator::Result> Nu::Parsing::Parser::Operator::GetResult2() const
{
	return result;
}

#pragma endregion

#pragma region None

Nu::Parsing::Parser::None::None(const Common::StrongPointer<None>& this_):
	Parser::Entity(this_),
	Operator::Result(this_)
{
}

#pragma endregion


template<class Type_, class... Arguments_>
Common::StrongPointer<Type_> Nu::Parsing::Parser::Make(Arguments_&&... arguments_)
{
	class Holder:
		public Type_
	{
	public:
		Holder(const StrongPointer<Type_>& this_, Arguments_&&... arguments_):
			Parser::Entity(this_), Type_(this_, Forward<Arguments_&&>(arguments_)...)
		{
		}
		void operator delete (Memory<void> rawMemory_)
		{
			auto memory = static_cast<Memory<Holder>>(rawMemory_);

			ReleaseMemory(memory);
		}
	};

	auto memory			= AllocateMemory<Holder>();
	auto pointer		= StrongPointer<Holder>(memory);
	auto castedPointer	= StaticCast<Type_>(pointer);

	::new(memory) Type_(castedPointer, Forward<Arguments_&&>(arguments_)...);

	return Move(castedPointer);
}


/*void Nu::Parser::Parser::Parse()
{
	auto instance = new Instance();
}*/

#pragma endregion

#pragma endregion


#pragma region Region
#pragma endregion



