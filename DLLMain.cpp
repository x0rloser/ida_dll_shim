// 
// ida.dll compatibility shim for IDA
// Check the readme.md for more info
// 
// xorloser - November 2022
// 

#include <Windows.h>

// uncomment one of the following to produce a shim for that version of ida
//#define IDA_700			1
//#define IDA_710			1
//#define IDA_710SP1	1
//#define IDA_720			1
//#define IDA_730			1
//#define IDA_740			1
//#define IDA_750			1
//#define IDA_760			1
//#define IDA_770			1
//#define IDA_800			1
#define IDA_810			1

#include "ida_dll_exports.h"


DWORD WINAPI ProcessAttach(
	_In_ LPVOID Parameter
)
{
	if ( Parameter == NULL )
		return FALSE;

	return TRUE;
}

DWORD WINAPI ProcessDetach(
	_In_ LPVOID Parameter
)
{
	if ( Parameter == NULL )
		return FALSE;

	return TRUE;
}

BOOL APIENTRY DllMain( 
	_In_ HINSTANCE Instance,
	_In_ DWORD     Reason,
	_In_ LPVOID    Reserved 
)
{
	switch ( Reason )
	{
		case DLL_PROCESS_ATTACH:
			// Disable DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications
			DisableThreadLibraryCalls( Instance );
			return ProcessAttach( Instance );
		case DLL_PROCESS_DETACH:
			return ProcessDetach( Instance );
	}

	return TRUE;
}
