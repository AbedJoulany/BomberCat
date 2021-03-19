#pragma once
#include "SettingOptions.h"

template <typename T>//window's type
class Resolution :
	public SettingOptions
{
public:
	Resolution() {};//---------------------c-tor-------------------------------
	~Resolution() {};//---------------------d-tor------------------------------
	template<typename Y>//menu's type
	void set(Y& menu);
};
//------------------ register function ----------------------------------------
template<typename T>//window's type
template<typename Y>//menu's type
inline void Resolution<T>::set(Y& menu)
{
	menu.set(RESOLUTION, [this] {T::instance().resize(); });
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------