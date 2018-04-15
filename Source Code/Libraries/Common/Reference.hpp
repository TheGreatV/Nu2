#pragma region Include

#pragma once

#include <cstdlib>

#include "Header.hpp"
#include "Size.hpp"
#include "Memory.hpp"
#include "Move.hpp"

#pragma endregion


#pragma region Macros

#if _DEBUG
#define __COMMON_REFERENCE_ERROR_CHECK__ 1
#else
#define __COMMON_REFERENCE_ERROR_CHECK__ 0
#endif

#pragma endregion


namespace Common
{
	template<class Type_> class Pointer;			// base class
	template<class Type_> class ConstantPointer;	// can't be changed (without overhead)
	template<class Type_> class UniquePointer;		// can't have more than one owner
	template<class Type_> class StrongPointer;		// can have many owners
	template<class Type_> class WeakPointer;		// can be casted to strong
	template<class Type_> class UserPointer;		// can't be deleted


	template<class DestinationType_, class SourceType_> StrongPointer<DestinationType_>	StaticCast(const StrongPointer<SourceType_>& source_);
	template<class DestinationType_, class SourceType_> StrongPointer<DestinationType_>	DynamicCast(const StrongPointer<SourceType_>& source_);
	template<class DestinationType_, class SourceType_> WeakPointer<DestinationType_>	StaticCast(const WeakPointer<SourceType_>& source_);
	template<class DestinationType_, class SourceType_> WeakPointer<DestinationType_>	DynamicCast(const WeakPointer<SourceType_>& source_);
}


// ConstantPointer
template<class Type_>	inline bool operator == (const Common::ConstantPointer<Type_>& pointer_, const typename Common::ConstantPointer<Type_>::Value& value_);
template<class Type_>	inline bool operator != (const Common::ConstantPointer<Type_>& pointer_, const typename Common::ConstantPointer<Type_>::Value& value_);
template<class Type_>	inline bool operator == (const typename Common::ConstantPointer<Type_>::Value& value_, const Common::ConstantPointer<Type_>& pointer_);
template<class Type_>	inline bool operator != (const typename Common::ConstantPointer<Type_>::Value& value_, const Common::ConstantPointer<Type_>& pointer_);

template<class Type_>	inline bool operator == (const Common::ConstantPointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator != (const Common::ConstantPointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator == (const Common::Null&, const Common::ConstantPointer<Type_>& pointer_);
template<class Type_>	inline bool operator != (const Common::Null&, const Common::ConstantPointer<Type_>& pointer_);

// UniquePointer
template<class Type_>	inline bool operator == (const Common::UniquePointer<Type_>& pointer_, const typename Common::UniquePointer<Type_>::Value& value_);
template<class Type_>	inline bool operator != (const Common::UniquePointer<Type_>& pointer_, const typename Common::UniquePointer<Type_>::Value& value_);
template<class Type_>	inline bool operator == (const typename Common::UniquePointer<Type_>::Value& value_, const Common::UniquePointer<Type_>& pointer_);
template<class Type_>	inline bool operator != (const typename Common::UniquePointer<Type_>::Value& value_, const Common::UniquePointer<Type_>& pointer_);

template<class Type_>	inline bool operator == (const Common::UniquePointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator != (const Common::UniquePointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator == (const Common::Null&, const Common::UniquePointer<Type_>& pointer_);
template<class Type_>	inline bool operator != (const Common::Null&, const Common::UniquePointer<Type_>& pointer_);

// StrongPointer
template<class Type_>	inline bool operator == (const Common::StrongPointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator != (const Common::StrongPointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator == (const Common::Null&, const Common::StrongPointer<Type_>& pointer_);
template<class Type_>	inline bool operator != (const Common::Null&, const Common::StrongPointer<Type_>& pointer_);

// WeakPointer
template<class Type_>	inline bool operator == (const Common::WeakPointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator != (const Common::WeakPointer<Type_>& pointer_, const Common::Null&);
template<class Type_>	inline bool operator == (const Common::Null&, const Common::WeakPointer<Type_>& pointer_);
template<class Type_>	inline bool operator != (const Common::Null&, const Common::WeakPointer<Type_>& pointer_);


namespace Common
{
	template<class Type_> class Pointer
	{
	public:
		using Value = Memory<Type_>;
	};
	template<class Type_> class ConstantPointer:
		public Pointer<Type_>
	{
	protected:
		Value						value = nullptr;
	public:
		inline						ConstantPointer() = default;
		inline explicit				ConstantPointer(const Null&);
		inline explicit				ConstantPointer(const Value& value_);
		inline						ConstantPointer(const ConstantPointer&) = delete;
		inline						ConstantPointer(ConstantPointer&& source_);
		inline						~ConstantPointer();
	public:
		inline ConstantPointer&		operator = (const Null&) = delete;
		inline ConstantPointer&		operator = (const ConstantPointer&) = delete;
		inline ConstantPointer&		operator = (ConstantPointer&&) = delete;
	public:
		inline const Value			operator -> () const;
		inline Value				operator -> ();
		inline const Type_&			operator * () const;
		inline Type_&				operator * ();
	public:
		inline bool					operator == (const ConstantPointer& source_) const;
		inline bool					operator != (const ConstantPointer& source_) const;
	public:
		inline operator				bool () const;
		inline explicit operator	Value () const;
	public:
		inline Value				GetValue() const;
	};
	template<class Type_> class UniquePointer:
		public Pointer<Type_>
	{
	public:
		using Value = Memory<Type_>;
	protected:
		Value						value = nullptr;
	public:
		inline						UniquePointer() = default;
		inline explicit				UniquePointer(const Null&);
		inline explicit				UniquePointer(const Value& value_);
		inline						UniquePointer(const UniquePointer&) = delete;
		inline						UniquePointer(UniquePointer&& source_);
		inline						~UniquePointer();
	public:
		inline UniquePointer&		operator = (const Null&);
		inline UniquePointer&		operator = (const UniquePointer&) = delete;
		inline UniquePointer&		operator = (UniquePointer&& source_);
	public:
		inline const Value			operator -> () const;
		inline Value				operator -> ();
		inline const Type_&			operator * () const;
		inline Type_&				operator * ();
	public:
		inline bool					operator == (const UniquePointer& source_) const;
		inline bool					operator != (const UniquePointer& source_) const;
	public:
		inline operator				bool () const;
		inline explicit operator	Value () const;
	public:
		inline Value				GetValue() const;
		inline void					Release();
	};
	class _ReferenceCounter
	{
	public:
		using Counter = Size;
	public:
		class Exception;
		class ExpiredException;
	protected:
		Counter										strongCounter = 1;
		Counter										weakCounter = 0;
	public:
		inline										_ReferenceCounter() = default;
		inline										_ReferenceCounter(const _ReferenceCounter&) = delete;
		inline										_ReferenceCounter(_ReferenceCounter&&) = delete;
		inline virtual								~_ReferenceCounter() = default;
	protected:
		inline _ReferenceCounter&					operator = (const _ReferenceCounter&) = delete;
		inline _ReferenceCounter&					operator = (_ReferenceCounter&&) = delete;
	private:
		inline virtual void							Clear() = 0;
	public:
		inline void									IncreaseStrongCounter();
		inline void									DecreaseStrongCounter();
		inline void									IncreaseWeakCounter();
		inline void									DecreaseWeakCounter();
	public:
		inline Counter								GetStrongCounter() const;
		inline Counter								GetWeakCounter() const;
	};
	template<class Type_> class _ReferenceHolder:
		public _ReferenceCounter
	{
	public:
		using Value = Memory<Type_>;
	protected:
		const Value value;
	public:
		inline _ReferenceHolder(const Value& value_);
	private:
		inline virtual void Clear() override;
	};
	template<class Type_> class SharedPointer: // basic for strong & weak pointers
		public Pointer<Type_>
	{
	public:
		using Value								= typename _ReferenceHolder<Type_>::Value;
		using Counter							= typename _ReferenceHolder<Type_>::Counter;
		using Holder							= Memory<_ReferenceCounter>; 
	public:
		class Exception;
	protected:
		class InitializedTag {};
	protected:
		mutable Holder							holder;
	protected:
		inline									SharedPointer() = delete;
		inline explicit							SharedPointer(const Holder& holder_);
		inline									SharedPointer(const SharedPointer&) = delete;
		inline									SharedPointer(SharedPointer&&) = delete;
		inline									~SharedPointer() = default;
	protected:
		inline SharedPointer&					operator = (const SharedPointer&) = delete;
		inline SharedPointer&					operator = (SharedPointer&&) = delete;
	protected:
		inline void								IncreaseStrongCounter();
		inline void								DecreaseStrongCounter();
		inline void								IncreaseWeakCounter();
		inline void								DecreaseWeakCounter();
	public:
		inline bool								IsEmpty() const;
		inline Counter							GetStrongCounter() const;
		inline Counter							GetWeakCounter() const;
	};
	template<class Type_> class StrongPointer:
		public SharedPointer<Type_>
	{
	public:
		friend WeakPointer<Type_>;
		template<class DestinationType_, class SourceType_> friend StrongPointer<DestinationType_> StaticCast(const StrongPointer<SourceType_>& source_);
		template<class DestinationType_, class SourceType_> friend StrongPointer<DestinationType_> DynamicCast(const StrongPointer<SourceType_>& source_);
	protected:
		Value											value;
	protected:
		inline											StrongPointer(const Value& value_, const Holder& holder_);
		inline											StrongPointer(const Value& value_, const Holder& holder_, const InitializedTag&);
	public:
		inline											StrongPointer();
		inline explicit									StrongPointer(const Null&);
		inline explicit									StrongPointer(const Value& value_);
		inline explicit									StrongPointer(const WeakPointer<Type_>& source_);
		inline											StrongPointer(const StrongPointer& source_);
		inline											StrongPointer(StrongPointer&& source_);
		inline											~StrongPointer();
	public:
		inline StrongPointer&							operator = (const Null&);
		inline StrongPointer&							operator = (const StrongPointer& source_);
		inline StrongPointer&							operator = (const WeakPointer<Type_>& source_);
		inline StrongPointer&							operator = (StrongPointer&& source_);
	public:
		inline bool										operator == (const StrongPointer& source_) const;
		inline bool										operator != (const StrongPointer& source_) const;
		inline bool										operator < (const StrongPointer& source_) const;
		inline bool										operator > (const StrongPointer& source_) const;
		inline bool										operator <= (const StrongPointer& source_) const;
		inline bool										operator >= (const StrongPointer& source_) const;
	public:
		inline const Value								operator -> () const;
		inline Value									operator -> ();
		inline const Type_&								operator * () const;
		inline Type_&									operator * ();
	public:
		inline operator									bool () const;
		inline explicit operator						Value () const;
		template<class OtherType_> inline operator		StrongPointer<OtherType_> () const;
	public:
		inline Value									GetValue() const;
	};
	template<class Type_> class WeakPointer:
		public SharedPointer<Type_>
	{
	public:
		friend StrongPointer<Type_>;
		template<class DestinationType_, class SourceType_> friend WeakPointer<DestinationType_> StaticCast(const WeakPointer<SourceType_>& source_);
		template<class DestinationType_, class SourceType_> friend WeakPointer<DestinationType_> DynamicCast(const WeakPointer<SourceType_>& source_);
	protected:
		Value					value;
	protected:
		inline					WeakPointer(const Value& value_, const Holder& holder_);
		inline					WeakPointer(const Value& value_, const Holder& holder_, const InitializedTag&);
	public:
		inline					WeakPointer();
		inline explicit			WeakPointer(const Null&);
		inline explicit			WeakPointer(const StrongPointer<Type_>& source_);
		inline					WeakPointer(const WeakPointer& source_);
		inline					WeakPointer(WeakPointer&& source_);
		inline					~WeakPointer() = default;
	public:
		inline WeakPointer&		operator = (const Null&);
		inline WeakPointer&		operator = (const StrongPointer<Type_>& source_);
		inline WeakPointer&		operator = (const WeakPointer& source_);
		inline WeakPointer&		operator = (WeakPointer&& source_);
	public:
		inline bool				operator == (const WeakPointer& source_) const;
		inline bool				operator != (const WeakPointer& source_) const;
		inline bool				operator < (const WeakPointer& source_) const;
		inline bool				operator > (const WeakPointer& source_) const;
		inline bool				operator <= (const WeakPointer& source_) const;
		inline bool				operator >= (const WeakPointer& source_) const;
	public:
		inline const Value		operator -> () const;
		inline Value			operator -> ();
		inline const Type_&		operator * () const;
		inline Type_&			operator * ();
	public:
		template<class OtherType_> inline operator WeakPointer<OtherType_>() const;
	public:
		inline bool				IsExpired() const;
		inline Value			GetValue() const;
	};

	template<class Type_> class SharedPointer<Type_>::Exception
	{
		// TODO
	};
	class _ReferenceCounter::Exception
	{
		// TODO
	};
	class _ReferenceCounter::ExpiredException:
		public Exception
	{
		// TODO
	};

	template<class Type_> class This
	{
	protected:
		const WeakPointer<Type_> self;
	public:
		inline This(const StrongPointer<Type_>& this_):
			self(this_)
		{
		}
		inline This(const This&) = delete;
		inline ~This() = default;
	public:
		inline This& operator = (const This&) = delete;
	public:
		template<class Derived_> inline StrongPointer<Derived_> GetThis() const
		{
			return Move(StaticCast<Derived_>(MakeStrong(self)));
		}
		template<class Derived_> inline WeakPointer<Derived_> GetWeak() const
		{
			return Move(StaticCast<Derived_>(self));
		}
	};


	template<class Type_, class... Arguments> inline ConstantPointer<Type_>						MakeConstant(Arguments&&... arguments_);
	template<class Type_> inline ConstantPointer<Type_>											MakeConstant();
	template<class Type_, class... Arguments> inline UniquePointer<Type_>						MakeUnique(Arguments&&... arguments_);
	template<class Type_> inline UniquePointer<Type_>											MakeUnique();
	template<class Type_, class... Arguments> inline StrongPointer<Type_>						MakeStrong(Arguments&&... arguments_);
	template<class Type_> inline StrongPointer<Type_>											MakeStrong();
	template<class Type_> inline StrongPointer<Type_>											MakeStrong(const Memory<Type_>& memory_);
	template<class Type_> inline StrongPointer<Type_>											MakeStrong(const WeakPointer<Type_>& source_);
	template<class Type_> inline WeakPointer<Type_>												MakeWeak(const StrongPointer<Type_>& source_);

	template<class Type_, class... Arguments_> inline StrongPointer<Type_>						Make(Arguments_&&... arguments_);
}


#pragma region Common

#pragma region ConstantPointer

template<class Type_>
Common::ConstantPointer<Type_>::ConstantPointer(const Null&):
	ConstantPointer()
{
}
template<class Type_>
Common::ConstantPointer<Type_>::ConstantPointer(const Value& value_):
	Pointer(),
	value(value_)
{
}
template<class Type_>
Common::ConstantPointer<Type_>::ConstantPointer(ConstantPointer&& source_):
	ConstantPointer(source_.value)
{
	source_.value = nullptr;
}
template<class Type_>
Common::ConstantPointer<Type_>::~ConstantPointer()
{
	delete value; // it is OK to delete nullptr
}

template<class Type_>
typename const Common::ConstantPointer<Type_>::Value Common::ConstantPointer<Type_>::operator -> () const
{
	return value;
}
template<class Type_>
typename Common::ConstantPointer<Type_>::Value Common::ConstantPointer<Type_>::operator -> ()
{
	return value;
}
template<class Type_>
const Type_& Common::ConstantPointer<Type_>::operator * () const
{
	return *value;
}
template<class Type_>
Type_& Common::ConstantPointer<Type_>::operator * ()
{
	return *value;
}

template<class Type_>
bool Common::ConstantPointer<Type_>::operator == (const ConstantPointer& source_) const
{
	return value == source_.value;
}
template<class Type_>
bool Common::ConstantPointer<Type_>::operator != (const ConstantPointer& source_) const
{
	return value != source_.value;
}

template<class Type_>
Common::ConstantPointer<Type_>::operator bool() const
{
	return value != nullptr;
}
template<class Type_>
Common::ConstantPointer<Type_>::operator Value() const
{
	return value;
}

template<class Type_>
typename Common::ConstantPointer<Type_>::Value Common::ConstantPointer<Type_>::GetValue() const
{
	return value;
}

#pragma endregion

#pragma region UniquePointer

template<class Type_>
Common::UniquePointer<Type_>::UniquePointer(const Null&):
	UniquePointer(static_cast<Value>(nullptr))
{
}
template<class Type_>
Common::UniquePointer<Type_>::UniquePointer(const Value& value_):
	Pointer(),
	value(value_)
{
}
template<class Type_>
Common::UniquePointer<Type_>::UniquePointer(UniquePointer&& source_):
	UniquePointer(source_.value)
{
	source_.value = nullptr;
}
template<class Type_>
Common::UniquePointer<Type_>::~UniquePointer()
{
	delete value; // delete nullptr is okay
}

template<class Type_>
typename Common::UniquePointer<Type_>& Common::UniquePointer<Type_>::operator = (const Null&)
{
	delete value; // it is okay to delete nullptr

	value = nullptr;

	return *this;
}
template<class Type_>
typename Common::UniquePointer<Type_>& Common::UniquePointer<Type_>::operator = (UniquePointer&& source_)
{
	delete value; // it is okay to delete nullptr

	value = source_.value;
	source_.value = nullptr;

	return *this;
}

template<class Type_>
typename const Common::UniquePointer<Type_>::Value Common::UniquePointer<Type_>::operator -> () const
{
	return value;
}
template<class Type_>
typename Common::UniquePointer<Type_>::Value Common::UniquePointer<Type_>::operator -> ()
{
	return value;
}
template<class Type_>
const Type_& Common::UniquePointer<Type_>::operator * () const
{
	return *value;
}
template<class Type_>
Type_& Common::UniquePointer<Type_>::operator * ()
{
	return *value;
}

template<class Type_>
bool Common::UniquePointer<Type_>::operator == (const UniquePointer& source_) const
{
	return value == source_.value;
}
template<class Type_>
bool Common::UniquePointer<Type_>::operator != (const UniquePointer& source_) const
{
	return value != source_.value;
}

template<class Type_>
Common::UniquePointer<Type_>::operator bool() const
{
	return value != nullptr;
}
template<class Type_>
Common::UniquePointer<Type_>::operator Value() const
{
	return value;
}

template<class Type_>
typename Common::UniquePointer<Type_>::Value Common::UniquePointer<Type_>::GetValue() const
{
	return value;
}
template<class Type_>
void Common::UniquePointer<Type_>::Release()
{
	value = nullptr;
}

#pragma endregion

#pragma region _ReferenceCounter

void Common::_ReferenceCounter::IncreaseStrongCounter()
{
#if __COMMON_REFERENCE_ERROR_CHECK__
	if (strongCounter == 0)
	{
		throw ExpiredException();
	}
#endif

	++strongCounter;
}
void Common::_ReferenceCounter::DecreaseStrongCounter()
{
#if __COMMON_REFERENCE_ERROR_CHECK__
	if (strongCounter == 0)
	{
		throw ExpiredException();
	}
#endif

	--strongCounter;

	if (strongCounter == 0)
	{
		Clear();

		if (weakCounter == 0)
		{
			delete this; // suicide
		}
	}
}
void Common::_ReferenceCounter::IncreaseWeakCounter()
{
	++weakCounter;
}
void Common::_ReferenceCounter::DecreaseWeakCounter()
{
	--weakCounter;

	if (weakCounter == 0 && strongCounter == 0)
	{
		delete this; // suicide
	}
}

Common::_ReferenceCounter::Counter Common::_ReferenceCounter::GetStrongCounter() const
{
	return strongCounter;
}
Common::_ReferenceCounter::Counter Common::_ReferenceCounter::GetWeakCounter() const
{
	return weakCounter;
}

#pragma endregion

#pragma region _ReferenceCounter

template<class Type_> Common::_ReferenceHolder<Type_>::_ReferenceHolder(const Value& value_):
	_ReferenceCounter(),
	value(value_)
{
}
template<class Type_> void Common::_ReferenceHolder<Type_>::Clear()
{
	delete value; // okay to delete nullptr
}

#pragma endregion

#pragma region SharedPointer

template<class Type_> Common::SharedPointer<Type_>::SharedPointer(const Holder& holder_):
	holder(holder_)
{
}

template<class Type_> void Common::SharedPointer<Type_>::IncreaseStrongCounter()
{
	if (holder)
	{
		holder->IncreaseStrongCounter();
	}
}
template<class Type_> void Common::SharedPointer<Type_>::DecreaseStrongCounter()
{
	if (holder)
	{
		holder->DecreaseStrongCounter();
	}
}
template<class Type_> void Common::SharedPointer<Type_>::IncreaseWeakCounter()
{
	if (holder)
	{
		holder->IncreaseWeakCounter();
	}
}
template<class Type_> void Common::SharedPointer<Type_>::DecreaseWeakCounter()
{
	if (holder)
	{
		holder->DecreaseWeakCounter();
	}
}
template<class Type_> bool Common::SharedPointer<Type_>::IsEmpty() const
{
	return holder == nullptr;
}
template<class Type_> typename Common::SharedPointer<Type_>::Counter Common::SharedPointer<Type_>::GetStrongCounter() const
{
	return holder
		? holder->GetStrongCounter()
		: 0;
}
template<class Type_> typename Common::SharedPointer<Type_>::Counter Common::SharedPointer<Type_>::GetWeakCounter() const
{
	return holder
		? holder->GetWeakCounter()
		: 0;
}

#pragma endregion

#pragma region StrongPointer

template<class Type_> Common::StrongPointer<Type_>::StrongPointer(const Value& value_, const Holder& holder_):
	StrongPointer(value_, holder_, InitializedTag())
{
	IncreaseStrongCounter();
}
template<class Type_> Common::StrongPointer<Type_>::StrongPointer(const Value& value_, const Holder& holder_, const InitializedTag&):
	SharedPointer(holder_),
	value(value_)
{
}

template<class Type_> Common::StrongPointer<Type_>::StrongPointer():
	StrongPointer(nullptr)
{
}
template<class Type_> Common::StrongPointer<Type_>::StrongPointer(const Null&):
	StrongPointer(nullptr, nullptr)
{
}
template<class Type_> Common::StrongPointer<Type_>::StrongPointer(const Value& value_):
	StrongPointer(value_, new _ReferenceHolder<Type_>(value_), InitializedTag())
{
}
template<class Type_> Common::StrongPointer<Type_>::StrongPointer(const WeakPointer<Type_>& source_):
	StrongPointer(source_.value, source_.holder)
{
}
template<class Type_> Common::StrongPointer<Type_>::StrongPointer(const StrongPointer& source_):
	StrongPointer(source_.value, source_.holder)
{
}
template<class Type_> Common::StrongPointer<Type_>::StrongPointer(StrongPointer&& source_):
	StrongPointer(source_.value, source_.holder, InitializedTag())
{
	source_.holder = nullptr;
	source_.value = nullptr;
}
template<class Type_> Common::StrongPointer<Type_>::~StrongPointer()
{
	DecreaseStrongCounter();
}

template<class Type_> Common::StrongPointer<Type_>& Common::StrongPointer<Type_>::operator = (const Null&)
{
	DecreaseStrongCounter();

	value = nullptr;
	holder = nullptr;

	return *this;
}
template<class Type_> Common::StrongPointer<Type_>& Common::StrongPointer<Type_>::operator = (const WeakPointer<Type_>& source_)
{
	DecreaseCounter();
	
	value = source_.value;
	holder = source_.holder;

	IncreaseCounter();

	return *this;
}
template<class Type_> Common::StrongPointer<Type_>& Common::StrongPointer<Type_>::operator = (const StrongPointer& source_)
{
	DecreaseStrongCounter();

	value = source_.value;
	holder = source_.holder;

	IncreaseStrongCounter();

	return *this;
}
template<class Type_> Common::StrongPointer<Type_>& Common::StrongPointer<Type_>::operator = (StrongPointer&& source_)
{
	DecreaseStrongCounter();

	value = source_.value;
	holder = source_.holder;

	source_.value = nullptr;
	source_.holder = nullptr;

	return *this;
}

template<class Type_> bool Common::StrongPointer<Type_>::operator == (const StrongPointer& source_) const
{
	return value == source_.value;
}
template<class Type_> bool Common::StrongPointer<Type_>::operator != (const StrongPointer& source_) const
{
	return value != source_.value;
}
template<class Type_> bool Common::StrongPointer<Type_>::operator < (const StrongPointer& source_) const
{
	return value < source_.value;
}
template<class Type_> bool Common::StrongPointer<Type_>::operator > (const StrongPointer& source_) const
{
	return value > source_.value;
}
template<class Type_> bool Common::StrongPointer<Type_>::operator <= (const StrongPointer& source_) const
{
	return value <= source_.value;
}
template<class Type_> bool Common::StrongPointer<Type_>::operator >= (const StrongPointer& source_) const
{
	return value >= source_.value;
}

template<class Type_> typename const Common::StrongPointer<Type_>::Value Common::StrongPointer<Type_>::operator -> () const
{
#if __COMMON_REFERENCE_ERROR_CHECK__
	if (IsEmpty() || value == nullptr)
	{
		throw Exception(); // TODO
	}
#endif

	return value;
}
template<class Type_> typename Common::StrongPointer<Type_>::Value Common::StrongPointer<Type_>::operator -> ()
{
#if __COMMON_REFERENCE_ERROR_CHECK__
	if (IsEmpty() || value == nullptr)
	{
		throw Exception(); // TODO
	}
#endif

	return value;
}
template<class Type_> const Type_& Common::StrongPointer<Type_>::operator * () const
{
#if __COMMON_REFERENCE_ERROR_CHECK__
	if (IsEmpty() || value == nullptr)
	{
		throw Exception(); // TODO
	}
#endif

	return *value;
}
template<class Type_> Type_& Common::StrongPointer<Type_>::operator * ()
{
#if __COMMON_REFERENCE_ERROR_CHECK__
	if (IsEmpty() || value == nullptr)
	{
		throw Exception(); // TODO
	}
#endif

	return *value;
}

template<class Type_> Common::StrongPointer<Type_>::operator bool() const
{
	return value != nullptr;
}
template<class Type_> Common::StrongPointer<Type_>::operator Value() const
{
	return value;
}
template<class Type_> template<class OtherType_> Common::StrongPointer<Type_>::operator Common::StrongPointer<OtherType_>() const
{
	return StaticCast<OtherType_>(*this);
}

template<class Type_> typename Common::StrongPointer<Type_>::Value Common::StrongPointer<Type_>::GetValue() const
{
	return value;
}

#pragma endregion

#pragma region WeakPointer

template<class Type_> Common::WeakPointer<Type_>::WeakPointer(const Value& value_, const Holder& holder_):
	WeakPointer(value_, holder_, InitializedTag())
{
	IncreaseWeakCounter();
}
template<class Type_> Common::WeakPointer<Type_>::WeakPointer(const Value& value_, const Holder& holder_, const InitializedTag&):
	SharedPointer(holder_),
	value(value_)
{
}
template<class Type_> Common::WeakPointer<Type_>::WeakPointer():
	WeakPointer(nullptr)
{
}
template<class Type_> Common::WeakPointer<Type_>::WeakPointer(const Null&):
	WeakPointer(nullptr, nullptr)
{
}
template<class Type_> Common::WeakPointer<Type_>::WeakPointer(const StrongPointer<Type_>& source_):
	WeakPointer(source_.value, source_.holder, InitializedTag())
{
}
template<class Type_> Common::WeakPointer<Type_>::WeakPointer(const WeakPointer& source_):
	WeakPointer(source_.value, source_.holder)
{
}
template<class Type_> Common::WeakPointer<Type_>::WeakPointer(WeakPointer&& source_):
	WeakPointer(source_.value, source_.holder, InitializedTag())
{
	source_.value = nullptr;
	source_.holder = nullptr;
}

template<class Type_> Common::WeakPointer<Type_>& Common::WeakPointer<Type_>::operator = (const Null&)
{
	DecreaseWeakCounter();

	value = nullptr;
	holder = nullptr;

	return *this;
}
template<class Type_> Common::WeakPointer<Type_>& Common::WeakPointer<Type_>::operator = (const StrongPointer<Type_>& source_)
{
	DecreaseWeakCounter();
	
	value = source_.value;
	holder = source_.holder;

	IncreaseWeakCounter();

	return *this;
}
template<class Type_> Common::WeakPointer<Type_>& Common::WeakPointer<Type_>::operator = (const WeakPointer& source_)
{
	DecreaseWeakCounter();
	
	value = source_.value;
	holder = source_.holder;

	IncreaseWeakCounter();
	
	return *this;
}
template<class Type_> Common::WeakPointer<Type_>& Common::WeakPointer<Type_>::operator = (WeakPointer&& source_)
{
	DecreaseWeakCounter();

	value = source_.value;
	holder = source_.holder;

	source_.value = nullptr;
	source_.holder = nullptr;

	return *this;
}

template<class Type_> bool Common::WeakPointer<Type_>::operator == (const WeakPointer& source_) const
{
	return value == source_.value;
}
template<class Type_> bool Common::WeakPointer<Type_>::operator != (const WeakPointer& source_) const
{
	return value != source_.value;
}
template<class Type_> bool Common::WeakPointer<Type_>::operator < (const WeakPointer& source_) const
{
	return value < source_.value;
}
template<class Type_> bool Common::WeakPointer<Type_>::operator >(const WeakPointer& source_) const
{
	return value > source_.value;
}
template<class Type_> bool Common::WeakPointer<Type_>::operator <= (const WeakPointer& source_) const
{
	return value <= source_.value;
}
template<class Type_> bool Common::WeakPointer<Type_>::operator >= (const WeakPointer& source_) const
{
	return value >= source_.value;
}

template<class Type_> typename const Common::WeakPointer<Type_>::Value Common::WeakPointer<Type_>::operator -> () const
{
	return value; // TODO: check if expired
}
template<class Type_> typename Common::WeakPointer<Type_>::Value Common::WeakPointer<Type_>::operator -> ()
{
	return value; // TODO: check if expired
}
template<class Type_> const Type_& Common::WeakPointer<Type_>::operator * () const
{
	return *value; // TODO: check != nullptr
}
template<class Type_> Type_& Common::WeakPointer<Type_>::operator * ()
{
	return *value; // TODO: check != nullptr
}

template<class Type_> template<class OtherType_> Common::WeakPointer<Type_>::operator Common::WeakPointer<OtherType_>() const
{
	return StaticCast<OtherType_>(*this);
}

template<class Type_> bool Common::WeakPointer<Type_>::IsExpired() const
{
	return holder->GetStrongCounter() == 0;
}
template<class Type_> typename Common::WeakPointer<Type_>::Value Common::WeakPointer<Type_>::GetValue() const
{
	return value;
}

#pragma endregion


template<class Type_, class... Arguments> typename Common::ConstantPointer<Type_> Common::MakeConstant<Type_>(Arguments&&... arguments)
{
	return ConstantPointer<Type_>(new Type_(Forward<Arguments>(arguments)...));
}
template<class Type_> typename Common::ConstantPointer<Type_> Common::MakeConstant<Type_>()
{
	return ConstantPointer<Type_>(new Type_());
}

template<class Type_, class... Arguments> typename Common::UniquePointer<Type_> Common::MakeUnique<Type_>(Arguments&&... arguments)
{
	return UniquePointer<Type_>(new Type_(Forward<Arguments>(arguments)...));
}
template<class Type_> typename Common::UniquePointer<Type_> Common::MakeUnique<Type_>()
{
	return UniquePointer<Type_>(new Type_());
}

template<class Type_, class... Arguments> typename Common::StrongPointer<Type_> Common::MakeStrong<Type_>(Arguments&&... arguments)
{
	return StrongPointer<Type_>(new Type_(Forward<Arguments>(arguments)...));
}
template<class Type_> typename Common::StrongPointer<Type_> Common::MakeStrong<Type_>()
{
	return StrongPointer<Type_>(new Type_());
}
template<class Type_> typename Common::StrongPointer<Type_> Common::MakeStrong<Type_>(const WeakPointer<Type_>& source_)
{
	return Move(StrongPointer<Type_>(source_));
}
template<class Type_> typename Common::StrongPointer<Type_> Common::MakeStrong(const Memory<Type_>& memory_)
{
	return StrongPointer<Type_>(memory_);
}

template<class Type_> typename Common::WeakPointer<Type_> Common::MakeWeak<Type_>(const StrongPointer<Type_>& source_)
{
	return Move(WeakPointer<Type_>(source_));
}

template<class Type_, class... Arguments_>
Common::StrongPointer<Type_> Common::Make(Arguments_&&... arguments_)
{
	class Holder:
		public Type_
	{
	public:
		Holder(const StrongPointer<Type_>& this_, Arguments_&&... arguments_):
			Type_(this_, Forward<Arguments_&&>(arguments_)...)
		{
		}
		void operator delete (Memory<void> rawMemory_)
		{
			auto memory = static_cast<Memory<Holder>>(rawMemory_);
			
			ReleaseMemory(memory);
		}
	};

	auto memory = AllocateMemory<Holder>();
	auto pointer = StrongPointer<Holder>(memory);
	auto castedPointer = StaticCast<Type_>(pointer);

	::new(memory)Type_(castedPointer, Forward<Arguments_&&>(arguments_)...);

	return Move(castedPointer);
}

template<class DestinationType_, class SourceType_> typename Common::StrongPointer<DestinationType_> Common::StaticCast<DestinationType_, SourceType_>(const StrongPointer<SourceType_>& source_)
{
	auto castedValue = static_cast<StrongPointer<DestinationType_>::Value>(source_.value);
	
	return Move(StrongPointer<DestinationType_>(castedValue, source_.holder));
}
template<class DestinationType_, class SourceType_> typename Common::StrongPointer<DestinationType_> Common::DynamicCast<DestinationType_, SourceType_>(const StrongPointer<SourceType_>& source_)
{
	auto castedValue = dynamic_cast<typename StrongPointer<DestinationType_>::Value>(source_.value);

	return Move(castedValue
		? StrongPointer<DestinationType_>(castedValue, source_.holder)
		: StrongPointer<DestinationType_>(nullptr)
	);
}
template<class DestinationType_, class SourceType_> typename Common::WeakPointer<DestinationType_> Common::StaticCast<DestinationType_, SourceType_>(const WeakPointer<SourceType_>& source_)
{
	auto castedValue = static_cast<WeakPointer<DestinationType_>::Value>(source_.value);

	return Move(WeakPointer<DestinationType_>(castedValue, source_.holder));
}
template<class DestinationType_, class SourceType_> typename Common::WeakPointer<DestinationType_> Common::DynamicCast<DestinationType_, SourceType_>(const WeakPointer<SourceType_>& source_)
{
	auto castedValue = dynamic_cast<typename WeakPointer<DestinationType_>::Value>(source_.value);

	return Move(castedValue
		? WeakPointer<DestinationType_>(castedValue, source_.holder)
		: WeakPointer<DestinationType_>(nullptr)
	);
}

#pragma endregion


// ConstantPointer
template<class Type_>
bool operator == (const Common::ConstantPointer<Type_>& pointer_, const typename Common::ConstantPointer<Type_>::Value& value_)
{
	return pointer_.GetValue() == value_;
}
template<class Type_>
bool operator != (const Common::ConstantPointer<Type_>& pointer_, const typename Common::ConstantPointer<Type_>::Value& value_)
{
	return pointer_.GetValue() != value_;
}
template<class Type_>
bool operator == (const typename Common::ConstantPointer<Type_>::Value& value_, const Common::ConstantPointer<Type_>& pointer_)
{
	return pointer_ == value_;
}
template<class Type_>
bool operator != (const typename Common::ConstantPointer<Type_>::Value& value_, const Common::ConstantPointer<Type_>& pointer_)
{
	return pointer_ != value_;
}

template<class Type_>
bool operator == (const Common::ConstantPointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() == nullptr;
}
template<class Type_>
bool operator != (const Common::ConstantPointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() != nullptr;
}
template<class Type_>
bool operator == (const Common::Null&, const Common::ConstantPointer<Type_>& pointer_)
{
	return nullptr == pointer_.GetValue();
}
template<class Type_>
bool operator != (const Common::Null&, const Common::ConstantPointer<Type_>& pointer_)
{
	return nullptr != pointer_.GetValue();
}


// UniquePointer
template<class Type_>
bool operator == (const Common::UniquePointer<Type_>& pointer_, const typename Common::UniquePointer<Type_>::Value& value_)
{
	return pointer_.GetValue() == value_;
}
template<class Type_>
bool operator != (const Common::UniquePointer<Type_>& pointer_, const typename Common::UniquePointer<Type_>::Value& value_)
{
	return pointer_.GetValue() != value_;
}
template<class Type_>
bool operator == (const typename Common::UniquePointer<Type_>::Value& value_, const Common::UniquePointer<Type_>& pointer_)
{
	return pointer_ == value_;
}
template<class Type_>
bool operator != (const typename Common::UniquePointer<Type_>::Value& value_, const Common::UniquePointer<Type_>& pointer_)
{
	return pointer_ != value_;
}

template<class Type_>
bool operator == (const Common::UniquePointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() == nullptr;
}
template<class Type_>
bool operator != (const Common::UniquePointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() != nullptr;
}
template<class Type_>
bool operator == (const Common::Null&, const Common::UniquePointer<Type_>& pointer_)
{
	return nullptr == pointer_.GetValue();
}
template<class Type_>
bool operator != (const Common::Null&, const Common::UniquePointer<Type_>& pointer_)
{
	return nullptr != pointer_.GetValue();
}

// StrongPointer
template<class Type_> bool operator == (const Common::StrongPointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() == nullptr;
}
template<class Type_> bool operator != (const Common::StrongPointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() != nullptr;
}
template<class Type_> bool operator == (const Common::Null&, const Common::StrongPointer<Type_>& pointer_)
{
	return pointer_ == nullptr;
}
template<class Type_> bool operator != (const Common::Null&, const Common::StrongPointer<Type_>& pointer_)
{
	return pointer_ != nullptr;
}

// WeakPointer
template<class Type_> bool operator == (const Common::WeakPointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() == nullptr;
}
template<class Type_> bool operator != (const Common::WeakPointer<Type_>& pointer_, const Common::Null&)
{
	return pointer_.GetValue() != nullptr;
}
template<class Type_> bool operator == (const Common::Null&, const Common::WeakPointer<Type_>& pointer_)
{
	return pointer_ == nullptr;
}
template<class Type_> bool operator != (const Common::Null&, const Common::WeakPointer<Type_>& pointer_)
{
	return pointer_ != nullptr;
}


#pragma region
#pragma endregion


