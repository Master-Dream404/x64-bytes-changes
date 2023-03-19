#include "pch.h"
#include "memory.h"
#include <iostream>


void mem::memory::change_bytes(uintptr_t offset, unsigned char* patch, LPCWSTR module_name)
{
    std::uint64_t base_address = (std::uint64_t)GetModuleHandle(module_name);
    void* addr = (void*)(base_address + offset);

    DWORD old;
    VirtualProtect(addr, sizeof(patch), PAGE_EXECUTE_READWRITE, &old);
    memcpy(addr, patch, sizeof(patch));
    VirtualProtect(addr, sizeof(patch), old, &old);
}

std::uint64_t mem::memory::get_base_address(LPCWSTR module_a)
{
    return (std::uint64_t)GetModuleHandleW(module_a);
}

void mem::memory::m_console(std::string titel, bool read_write) {
    AllocConsole();
    SetConsoleTitleA(titel.c_str());
    if (read_write)
    {
        FILE* f = new FILE;
        freopen_s(&f, "CONOUT$", "w", stdout);
    }
}

uintptr_t mem::memory::find_address(uintptr_t ptr, std::vector<unsigned int> offset)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offset.size(); i++)
    {
        addr = *(uintptr_t*)addr;
        addr += offset[i];
    }
    return addr;
}

void mem::memory::change_value(DWORD* player_base, DWORD* game_base, DWORD* game_base_pointer, DWORD value)
{
    DWORD* a1, * a2, * a3, * v1;
    a1 = (DWORD*)player_base;//First, we will get the player's base address by reading the value at 0x017EED18:
    a2 = (DWORD*)(*player_base + game_base);//This will declare player_base as a pointer to a DWORD value. The location it will point at is our player's base address at 0x017EED18. We can then dereference this pointer to "read" or retrieve this value. Using this, we can get our game base address by adding an offset:
    a3 = (DWORD*)(*game_base + game_base_pointer);//Finally, we can dereference the game_base address and add an offset to retrieve our gold value. We can then dereference this gold value and set its value directly:
    v1 = a3;
    *v1 = value;
}

std::uint64_t mem::memory::beta_hook_qword(int qword_offset/*qword offset like 0x19E6108*/, std::uint64_t addr/* the game base address */, int override_of/* the offset for change dword like 0x10 or 0xC1 */)
{
    std::uint64_t m_qword = *(std::uint64_t*)(addr + qword_offset);

    std::uint64_t hook = *(std::uint64_t*)(m_qword + override_of);
    return *(std::uint64_t*)(hook + override_of);

    /*
    std::uint64_t hook = *(std::uint64_t*)(m_qword + override_of);
    return hook;
    */
}

void mem::memory::console_getline(std::string& a, std::string text)
{
    if (text.empty())
    {
        //printf("%s\n", text);
        std::getline(std::cin, a);
    }
    else
    {
        printf("%s\n", text);
        std::getline(std::cin, a);
    }
}



