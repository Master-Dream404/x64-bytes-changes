#pragma once
#include <cstdint>
#include <string>
#include <vector>
namespace mem
{
	class memory
	{
	public:
		void change_bytes(uintptr_t offset, unsigned char* patch, LPCWSTR module_name);
		std::uint64_t get_base_address(LPCWSTR module_a);
		void m_console(std::string titel, bool read_write);
		uintptr_t find_address(uintptr_t ptr, std::vector<unsigned int> offset);
		void change_value(DWORD* player_base, DWORD* game_base, DWORD* game_base_pointer, DWORD value);
		std::uint64_t beta_hook_qword(int qword_offset, std::uint64_t addr, int override_of);

		void console_getline(std::string& a, std::string text/*text is for text to the getline*/);

	private:

	protected:
	};
}
