#include "pch.h"
#include "api.h"

mem::memory& m_api::api::change_memory()
{
	static memory instance;
	return instance;
}

void m_api::api::execute(m_api::api& a)
{
	a;
}