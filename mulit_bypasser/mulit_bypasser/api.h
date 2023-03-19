#pragma once
#include "memory.h"
namespace m_api
{
	class api : public mem::memory
	{
	public:
		static mem::memory& change_memory();
		void execute(api& a);
	private:

	protected:
	};
}

