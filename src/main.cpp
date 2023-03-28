#include <sdk/SexySDK.hpp> //for deluxe
#include <sdk/SexyNightsSDK.hpp> //for nights
#include <MinHook.h>

void init()
{
	MH_Initialize();

	//Some useful callbacks
	//Check out callbacks.hpp in the respective game's sdk for more!

	//Deluxe
	Sexy::callbacks::on(Sexy::callbacks::type::begin_turn_2, []()
	{
	});

	Sexy::callbacks::on(Sexy::callbacks::type::do_level_done, []()
	{
	});

	Sexy::callbacks::on(Sexy::callbacks::type::do_to_menu, []()
	{
	});

	Sexy::callbacks::on(Sexy::callbacks::type::main_loop, []()
	{
	});

	//Nights
	SexyNights::callbacks::on(SexyNights::callbacks::type::begin_turn_2, []()
	{
	});

	SexyNights::callbacks::on(SexyNights::callbacks::type::do_level_done, []()
	{
	});

	SexyNights::callbacks::on(SexyNights::callbacks::type::do_to_menu, []()
	{
	});

	SexyNights::callbacks::on(SexyNights::callbacks::type::main_loop, []()
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
