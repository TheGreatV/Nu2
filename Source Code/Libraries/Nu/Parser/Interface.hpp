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


		class Entity;

		class Intermediate;

		class Name;
		class Named;

		class Scope;
		class Unit;

		class Factory;
		class Body;

		class Interface;
		class Instance;
		class Algorithm;

		class None;


		class Entity
		{
		public:
			virtual ~Entity() = default;
		};
		
		/**
		 * Object, used only as intermediate and do not take place in final assembly.
		 */
		class Intermediate:
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
		};
		class Named:
			public virtual Entity
		{
		};

		class Scope:
			public virtual Entity
		{
		public:
			using Names = List<Name>;
		public:
			virtual Names GetNames() const = 0;
		};

		class Factory:
			public virtual Entity
		{
		public:
			/**
			 * Interface, which created object will have
			 */
			virtual StrongPointer<Interface> GetInterface() const = 0;
		};
		class Body:
			public virtual Scope
		{
		public:
			class Command;
		public:
			class CommandsList;
		};
#pragma region Body::CommandsList
		class Body::CommandsList:
			public virtual Body
		{
		};
#pragma endregion
#pragma region Body::Command
		class Body::Command:
			public virtual Entity
		{
		};
#pragma endregion

		class Interface:
			public virtual Scope,
			public virtual Named
		{
		public:
			/**
			 * If not nullptr, factory to generate instances
			 */
			virtual StrongPointer<Factory> GetFactory() const = 0;
		};
		class Instance:
			public virtual Scope,
			public virtual Named
		{
		public:
			/**
			 * Factory, based on which instance was created
			 */
			virtual StrongPointer<Factory> GetFactory() const = 0;
		};
		class Algorithm:
			public virtual Scope,
			public virtual Named
		{
		};
		
		/**
		 * Object, used to describe empty states (e.g. empty body, result, etc.).
		 */
		class None:
			public virtual Entity,
			public virtual Body
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



