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
			class Sequence;
			class _SequenceElement;
			class Instanceable;
			class Interface;
			class Instance;
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
#pragma region Parser::_SequenceElement
		class Parser::_SequenceElement:
			public virtual Parsing::_SequenceElement,
			public virtual Entity
		{
		public:
			inline _SequenceElement(const StrongPointer<_SequenceElement>& this_);
			inline ~_SequenceElement() override = default;
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
			class Argument;
			class Order;
			class Body;
		public:
			using Arguments = Vector<StrongPointer<Argument>>;
		protected:
			const StrongPointer<Result>	result;
			const Arguments				arguments;
		public:
			inline Operator(const StrongPointer<Operator>& this_, const StrongPointer<Result>& result_, const Arguments& arguments_);
			inline ~Operator() override = default;
		public:
			inline StrongPointer<Abstraction::Result>	GetResult() const override;
			inline Abstraction::Arguments				GetArguments() const override;
		public:
			inline StrongPointer<Result>				GetResult2() const;
			inline Arguments							GetArguments2() const;
		};
#pragma endregion
#pragma region Parser::Operator::Result
		class Parser::Operator::Result:
			public Parsing::Operator::Result,
			public virtual Parser::Entity
		{
		protected:
			using Abstraction = Parsing::Operator::Result;
		public:
			inline Result(const StrongPointer<Result>& this_);
			inline ~Result() override = default;
		};
#pragma endregion
#pragma region Parser::Operator::Argument
		class Parser::Operator::Argument:
			public virtual Parsing::Operator::Argument,
			public virtual Parser::Entity
		{
		protected:
			using Abstraction = Parsing::Operator::Argument;
		public:
			inline Argument(const StrongPointer<Argument>& this_);
			inline ~Argument() override = default;
		};
#pragma endregion
#pragma region Parser::Operator::Order
		class Parser::Operator::Order:
			public virtual Parsing::Operator::Order,
			public virtual Parser::Entity
		{
		public:
			class Argument;
		protected:
			using Abstraction = Parsing::Operator;
		protected:
			const StrongPointer<Argument> argument;
			const StrongPointer<Order> order;
		public:
			inline Order(const StrongPointer<Order>& this_, const StrongPointer<Argument>& argument_);
			inline Order(const StrongPointer<Order>& this_, const StrongPointer<Argument>& argument_, const StrongPointer<Order>& order_);
			inline ~Order() override = default;
		public:
			inline StrongPointer<Abstraction::Order::Argument>	GetArgument() const override;
			inline StrongPointer<Abstraction::Order>			GetOrder() const override;
		public:
			inline StrongPointer<Argument>	GetArgument2() const;
			inline StrongPointer<Order>		GetOrder2() const;
		};
#pragma endregion
#pragma region Parser::Operator::Order::Argument
		class Parser::Operator::Order::Argument:
			public virtual Parsing::Operator::Order::Argument,
			public virtual Parser::Entity
		{
		public:
			class Left;
			class Right;
		public:
			inline Argument(const StrongPointer<Argument>& this_);
			inline ~Argument() override = default;
		};
#pragma endregion
#pragma region Parser::Operator::Order::Argument::Left
		class Parser::Operator::Order::Argument::Left:
			public virtual Parsing::Operator::Order::Argument::Left,
			public Argument
		{
		protected:
			const StrongPointer<Operator> the_operator;
		public:
			inline Left(const StrongPointer<Left>& this_, const StrongPointer<Operator>& the_operator_);
			inline ~Left() override = default;
		public:
			inline StrongPointer<Parsing::Operator> GetOperator() const override;
		public:
			inline StrongPointer<Operator> GetOperator2() const;
		};
#pragma endregion
#pragma region Parser::Operator::Order::Argument::Right
		class Parser::Operator::Order::Argument::Right:
			public virtual Parsing::Operator::Order::Argument::Right,
			public Argument
		{
		protected:
			const StrongPointer<Operator> the_operator;
		public:
			inline Right(const StrongPointer<Right>& this_, const StrongPointer<Operator>& the_operator_);
			inline ~Right() override = default;
		public:
			inline StrongPointer<Parsing::Operator> GetOperator() const override;
		public:
			inline StrongPointer<Operator> GetOperator2() const;
		};
#pragma endregion
#pragma region Parser::Operator::Body
		class Parser::Operator::Body:
			public Parsing::Operator::Body,
			public virtual Parser::Entity
		{
		protected:
			using Abstraction = Parsing::Operator::Body;
		public:
			inline Body(const StrongPointer<Body>& this_);
			inline ~Body() override = default;
		};
#pragma endregion
#pragma region Parser::Sequence
		class Parser::Sequence:
			public virtual Parsing::Sequence,
			public virtual Entity,
			public _SequenceElement,
			public Operator::Argument
		{
		protected:
			using Abstraction = Parsing::Sequence;
			using Implementation = Parser;
		public:
			using Element = Implementation::_SequenceElement;
			using Elements = Vector<StrongPointer<Element>>;
		protected:
			const Elements elements;
		public:
			inline Sequence(const StrongPointer<Sequence>& this_, const Elements& elements_);
			inline ~Sequence() override = default;
		public:
			inline Abstraction::Elements	GetElements() const override;
			inline Elements					GetElements2() const;
		};
#pragma endregion
#pragma region Parser::Instanceable
		class Parser::Instanceable:
			public virtual Parsing::Instanceable,
			public virtual Entity
		{
		protected:
			const StrongPointer<Interface> interface;
		public:
			inline Instanceable(const StrongPointer<Instanceable>& this_);
			inline Instanceable(const StrongPointer<Instanceable>& this_, const StrongPointer<Interface>& interface_);
			inline ~Instanceable() override = default;
		public:
			inline StrongPointer<Parsing::Interface> GetInterface() const override;
			inline StrongPointer<Interface> GetInterface2() const;
		};
#pragma endregion
#pragma region Parser::Interface
		class Parser::Interface:
			public virtual Parsing::Interface,
			public virtual Entity,
			public Instanceable
		{
		public:
			inline Interface(const StrongPointer<Interface>& this_);
			inline ~Interface() override = default;
		public:
			inline StrongPointer<Parsing::Interface> GetInterface() const override;
		};
#pragma endregion
#pragma region Parser::Instance
		class Parser::Instance:
			public virtual Parsing::Instance,
			public virtual Entity,
			public Operator::Argument
		{
		protected:
			const StrongPointer<Instanceable> instanceable;
		public:
			inline Instance(const StrongPointer<Instance>& this_, const StrongPointer<Instanceable>& instanceable_);
			inline ~Instance() override = default;
		public:
			inline StrongPointer<Parsing::Instanceable> GetInstanceable() const override;
			inline StrongPointer<Instanceable> GetInstanceable2() const;
		};
#pragma endregion
#pragma region Parser::None
		class Parser::None:
			public Parsing::None,
			public virtual Entity,
			public Operator::Result,
			public Operator::Argument,
			public Operator::Body,
			public Sequence::Element
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

#pragma region Result

Nu::Parsing::Parser::Operator::Result::Result(const Common::StrongPointer<Result>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion

#pragma region Argument

Nu::Parsing::Parser::Operator::Argument::Argument(const Common::StrongPointer<Argument>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion

#pragma region Order

#pragma region Argument

#pragma region Left

Nu::Parsing::Parser::Operator::Order::Argument::Left::Left(const Common::StrongPointer<Left>& this_, const Common::StrongPointer<Operator>& the_operator_):
	Parser::Entity(this_),
	Argument(this_),
	the_operator(the_operator_)
{
}

Common::StrongPointer<Nu::Parsing::Operator> Nu::Parsing::Parser::Operator::Order::Argument::Left::GetOperator() const
{
	return the_operator;
}
Common::StrongPointer<Nu::Parsing::Parser::Operator> Nu::Parsing::Parser::Operator::Order::Argument::Left::GetOperator2() const
{
	return the_operator;
}

#pragma endregion

#pragma region Right

Nu::Parsing::Parser::Operator::Order::Argument::Right::Right(const Common::StrongPointer<Right>& this_, const Common::StrongPointer<Operator>& the_operator_):
	Parser::Entity(this_),
	Argument(this_),
	the_operator(the_operator_)
{
}

Common::StrongPointer<Nu::Parsing::Operator> Nu::Parsing::Parser::Operator::Order::Argument::Right::GetOperator() const
{
	return the_operator;
}
Common::StrongPointer<Nu::Parsing::Parser::Operator> Nu::Parsing::Parser::Operator::Order::Argument::Right::GetOperator2() const
{
	return the_operator;
}

#pragma endregion


Nu::Parsing::Parser::Operator::Order::Argument::Argument(const Common::StrongPointer<Argument>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion


Nu::Parsing::Parser::Operator::Order::Order(const Common::StrongPointer<Order>& this_, const Common::StrongPointer<Argument>& argument_):
	Order(this_, argument_, StrongPointer<Order>(nullptr))
{
}
Nu::Parsing::Parser::Operator::Order::Order(const Common::StrongPointer<Order>& this_, const Common::StrongPointer<Argument>& argument_, const Common::StrongPointer<Order>& order_) :
	Parser::Entity(this_),
	argument(argument_),
	order(order_)
{
}

Common::StrongPointer<Nu::Parsing::Operator::Order::Argument> Nu::Parsing::Parser::Operator::Order::GetArgument() const
{
	return argument;
}
Common::StrongPointer<Nu::Parsing::Parser::Operator::Order::Abstraction::Order> Nu::Parsing::Parser::Operator::Order::GetOrder() const
{
	return order;
}
Common::StrongPointer<Nu::Parsing::Parser::Operator::Order::Argument> Nu::Parsing::Parser::Operator::Order::GetArgument2() const
{
	return argument;
}
Common::StrongPointer<Nu::Parsing::Parser::Operator::Order> Nu::Parsing::Parser::Operator::Order::GetOrder2() const
{
	return order;
}

#pragma endregion

#pragma region Body

Nu::Parsing::Parser::Operator::Body::Body(const Common::StrongPointer<Body>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion


Nu::Parsing::Parser::Operator::Operator(const Common::StrongPointer<Operator>& this_, const Common::StrongPointer<Result>& result_, const Arguments& arguments_):
	Parser::Entity(this_),
	Parser::Named(this_),
	result(result_),
	arguments(arguments_)
{
}

Common::StrongPointer<Nu::Parsing::Parser::Operator::Abstraction::Result> Nu::Parsing::Parser::Operator::GetResult() const
{
	return result;
}
Nu::Parsing::Parser::Operator::Abstraction::Arguments Nu::Parsing::Parser::Operator::GetArguments() const
{
	Abstraction::Arguments argumentsToReturn;

	argumentsToReturn.reserve(arguments.size());

	for (auto &argument : arguments)
	{
		argumentsToReturn.push_back(argument);
	}
	
	return Move(argumentsToReturn);
}

Common::StrongPointer<Nu::Parsing::Parser::Operator::Result> Nu::Parsing::Parser::Operator::GetResult2() const
{
	return result;
}
Nu::Parsing::Parser::Operator::Arguments Nu::Parsing::Parser::Operator::GetArguments2() const
{
	return arguments;
}

#pragma endregion

#pragma region Sequence

#pragma region Element

Nu::Parsing::Parser::_SequenceElement::_SequenceElement(const Common::StrongPointer<_SequenceElement>& this_):
	Parser::Entity(this_)
{
}

#pragma endregion


Nu::Parsing::Parser::Sequence::Sequence(const Common::StrongPointer<Sequence>& this_, const Elements& elements_):
	Parser::Entity(this_),
	Implementation::_SequenceElement(this_),
	Operator::Argument(this_),
	elements(elements_)
{
}

Nu::Parsing::Parser::Sequence::Abstraction::Elements Nu::Parsing::Parser::Sequence::GetElements() const
{
	Abstraction::Elements elementsToReturn;

	elementsToReturn.reserve(elements.size());

	for (auto &element : elements)
	{
		elementsToReturn.push_back(element);
	}

	return Move(elementsToReturn);
}
Nu::Parsing::Parser::Sequence::Elements Nu::Parsing::Parser::Sequence::GetElements2() const
{
	return elements;
}

#pragma endregion

#pragma region Instanceable

Nu::Parsing::Parser::Instanceable::Instanceable(const Common::StrongPointer<Instanceable>& this_):
	Instanceable(this_, StrongPointer<Interface>(nullptr))
{
}
Nu::Parsing::Parser::Instanceable::Instanceable(const Common::StrongPointer<Instanceable>& this_, const Common::StrongPointer<Interface>& interface_):
	Parser::Entity(this_),
	interface(interface_)
{
}

Common::StrongPointer<Nu::Parsing::Interface> Nu::Parsing::Parser::Instanceable::GetInterface() const
{
	return interface;
}
Common::StrongPointer<Nu::Parsing::Parser::Interface> Nu::Parsing::Parser::Instanceable::GetInterface2() const
{
	return interface;
}

#pragma endregion

#pragma region Interface

Nu::Parsing::Parser::Interface::Interface(const Common::StrongPointer<Interface>& this_):
	Parser::Entity(this_),
	Instanceable(this_, this_)
{
}

Common::StrongPointer<Nu::Parsing::Interface> Nu::Parsing::Parser::Interface::GetInterface() const
{
	return Instanceable::GetInterface();
}

#pragma endregion

#pragma region Instance

Nu::Parsing::Parser::Instance::Instance(const Common::StrongPointer<Instance>& this_, const Common::StrongPointer<Instanceable>& instanceable_):
	Parser::Entity(this_),
	Operator::Argument(this_),
	instanceable(instanceable_)
{
}

Common::StrongPointer<Nu::Parsing::Instanceable> Nu::Parsing::Parser::Instance::GetInstanceable() const
{
	return instanceable;
}
Common::StrongPointer<Nu::Parsing::Parser::Instanceable> Nu::Parsing::Parser::Instance::GetInstanceable2() const
{
	return instanceable;
}

#pragma endregion


#pragma region None

Nu::Parsing::Parser::None::None(const Common::StrongPointer<None>& this_):
	Parser::Entity(this_),
	Operator::Result(this_),
	Operator::Argument(this_),
	Operator::Body(this_),
	Sequence::Element(this_)
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



