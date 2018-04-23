#pragma region Include

#pragma once

#include "Header.hpp"

#pragma endregion


#pragma region Macros
#pragma endregion


namespace Nu
{
	namespace Parser
	{
		using namespace Common;


		class Instance;
		class Interface;


		class Entity
		{
		public:
			virtual ~Entity() = default;
		};

		class Named:
			public virtual Entity
		{
		};
		class Name:
			public virtual Entity
		{
		public:
			using Value = WideString;
		public:
			virtual Value GetValue() const = 0;
			virtual StrongPointer<Named> GetNamed() const = 0;
		};

		class Scope:
			public virtual Entity
		{
		public:
			using Names = List<StrongPointer<Name>>;
		public:
			class Free;
			class Direct;
		public:
			virtual StrongPointer<Scope> GetParent() const = 0;
		};
#pragma region Scope::Free
		class Scope::Free:
			public virtual Scope
		{
		public:
			virtual Names GetNames() const = 0;
		};
#pragma endregion
#pragma region Scope::Direct
		class Scope::Direct:
			public virtual Scope
		{
		};
#pragma endregion

		class Operator:
			public virtual Scope::Direct
		{
		public:
			class Result;
			class Argument;
			class Body;
		public:
			virtual StrongPointer<Result> GetResult() const = 0;
			virtual StrongPointer<Argument> GetLeft() const = 0;
			virtual StrongPointer<Argument> GetRight() const = 0;
			virtual StrongPointer<Body> GetBody() const = 0;
		};
#pragma region Operator::Result
		class Operator::Result:
			public virtual Scope::Direct
		{
		};
#pragma endregion
#pragma region Operator::Argument
		class Operator::Argument:
			public virtual Scope::Direct
		{
		};
#pragma endregion
#pragma region Operator::Body
		class Operator::Body:
			public virtual Scope::Direct
		{
		public:
			class CommandsList;
		};
#pragma endregion
#pragma region Operator::Body::CommandsList
		class Operator::Body::CommandsList:
			public virtual Body
		{
		public:
			class Command;
		};
#pragma endregion
#pragma region Operator::Body::CommandsList::Command
		class Operator::Body::CommandsList::Command:
			public virtual Entity
		{
		public:
			class Create;
			class Delete;
			class Call;
		};
#pragma endregion
#pragma region Operator::Body::CommandsList::Command::Create
		class Operator::Body::CommandsList::Command::Create:
			public virtual Command
		{
		public:
			virtual StrongPointer<Instance> GetInstance() const = 0;
		};
#pragma endregion
#pragma region Operator::Body::CommandsList::Command::Delete
		class Operator::Body::CommandsList::Command::Delete:
			public virtual Command
		{
		public:
			virtual StrongPointer<Instance> GetInstance() const = 0;
		};
#pragma endregion
#pragma region Operator::Body::CommandsList::Command::Call
		class Operator::Body::CommandsList::Command::Call:
			public virtual Command
		{
		public:
			class Result;
			class Argument;
		public:
			virtual StrongPointer<Operator> GetOperator() const = 0;
			virtual StrongPointer<Result> GetResult() const = 0;
			virtual StrongPointer<Argument> GetLeft() const = 0;
			virtual StrongPointer<Argument> GetRight() const = 0;
		};
#pragma endregion
#pragma region Operator::Body::CommandsList::Command::Call::Result
		class Operator::Body::CommandsList::Command::Call::Result:
			public virtual Entity
		{
		};
#pragma endregion
#pragma region Operator::Body::CommandsList::Command::Call::Argument
		class Operator::Body::CommandsList::Command::Call::Argument:
			public virtual Entity

		{
		};
#pragma endregion

		class Unit:
			public virtual Entity,
			public virtual Operator::Result,
			public virtual Operator::Argument,
			public virtual Operator::Body::CommandsList::Command::Call::Result,
			public virtual Operator::Body::CommandsList::Command::Call::Argument
		{
		};

		class Sequence:
			public virtual Unit
		{
		public:
			virtual List<StrongPointer<Unit>> GetUnits() const = 0;
		};
		class Group:
			public virtual Unit
		{
		public:
			class Brace;
		public:
			virtual StrongPointer<Brace> GetOpening() const = 0;
			virtual StrongPointer<Brace> GetClosing() const = 0;
			virtual StrongPointer<Unit> GetContent() const = 0;
		};
#pragma region Group::Brace
		class Group::Brace:
			public virtual Entity
		{
		};
#pragma endregion

		class Instanceable:
			public virtual Entity
		{
		public:
			virtual StrongPointer<Interface> GetInterface() const = 0;
		};
		class Interface:
			public virtual Unit,
			public virtual Scope::Free,
			public virtual Instanceable
		{
		};
		class Instance:
			public virtual Unit,
			public virtual Scope::Free
		{
		public:
			virtual StrongPointer<Instanceable> GetInstanceable() const = 0;
			inline virtual Names GetNames() const override
			{
				return GetInstanceable()->GetInterface()->GetNames();
			}
		};
		class Factory:
			public virtual Instance,
			public virtual Instanceable
		{
		};

		class None:
			public virtual Unit,
			public virtual Operator::Body
		{
		};
	}
}


#pragma region Nu

#pragma region Parser
#pragma endregion

#pragma endregion


#pragma region Region
#pragma endregion



