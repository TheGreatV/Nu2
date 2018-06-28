#pragma region Include

#pragma once

#include "Interface.hpp"

#pragma endregion


#pragma region Macros
#pragma endregion


// Predeclarations
namespace Nu
{
	namespace Parser
	{
		using namespace Common;


		class Parser;
	}
}


// Declarations
namespace Nu
{
	namespace Parser
	{
		class Parser
		{
		public:
			class ScopeLocation;
			class NamesSolver;
		};
#pragma region Parser::ScopeLocation
		class Parser::ScopeLocation
		{
		public:
		};
#pragma endregion
#pragma region Parser::NamesSolver
		class Parser::NamesSolver
		{
		public:
			using Text = WideString;
			using Name = WideString;
		public:
			class Solution;
		public:
			inline StrongPointer<Solution> Solve(const Text& text_) const;
		};
#pragma endregion
#pragma region Parser::NamesSolver::Solution
		class Parser::NamesSolver::Solution
		{
		public:
			class NamesNotFound;
		public:
			inline virtual ~Solution() = default;
		};
#pragma endregion
#pragma region Parser::NamesSolver::Solution::NamesNotFound
		class Parser::NamesSolver::Solution::NamesNotFound:
			public Solution
		{
		public:
			inline ~NamesNotFound() override = default;
		};
#pragma endregion
	}
}


// Definitions
namespace Nu
{
	namespace Parser
	{
		StrongPointer<Parser::NamesSolver::Solution> Parser::NamesSolver::Solve(const Text& text_) const
		{
			return MakeStrong<Solution::NamesNotFound>();
		}
	}	
}


#pragma region Region
#pragma endregion



