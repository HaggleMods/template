#include <sdk/SexySDK.hpp>
#include <callbacks/callbacks.hpp>
#include <MinHook.h>

void init()
{
	MH_Initialize();


	//Some useful callbacks
	//Check out callbacks.hpp for more!


	callbacks::on(callbacks::type::begin_turn_2, []()
	{
	});

	callbacks::on(callbacks::type::do_level_done, []()
	{
	});

	callbacks::on(callbacks::type::do_to_menu, []()
	{
	});

	callbacks::on(callbacks::type::main_loop, []()
	{
	});

	MH_EnableHook(MH_ALL_HOOKS);
}

DWORD WINAPI OnAttachImpl(LPVOID lpParameter)
{
	init();
	return 0;
}

DWORD WINAPI OnAttach(LPVOID lpParameter)
{
	__try
	{
		return OnAttachImpl(lpParameter);
	}
	__except (0)
	{
		FreeLibraryAndExitThread((HMODULE)lpParameter, 0xDECEA5ED);
	}

	return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, 0, OnAttach, hModule, 0, nullptr);
		return true;
	}

	return false;
}
