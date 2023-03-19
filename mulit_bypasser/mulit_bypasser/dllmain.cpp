// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "api.h"
m_api::api* ch = new m_api::api();

DWORD WINAPI Main(LPVOID prm)
{
    ch->get_base_address(L"FiveM.exe");
    unsigned char patch[3]{ 0x48, 0x01, 0xD8 };
    ch->change_bytes(0x1D4F79, patch, L"discord.dll");
    FreeLibraryAndExitThread((HMODULE)Main, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Main, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

