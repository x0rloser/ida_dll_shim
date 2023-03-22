// 
// ida.dll compatibility shim for IDA
// Check the readme.md for more info
// 
// xorloser - November 2022
// 

#include <Windows.h>

// Uncomment one of the following to produce a shim for that version of ida.
// 
// SP1 etc versions are only provided if the SP version dll has different
// exports to the base version dll. This is not usually the case.
// If there is no SP version then use the base version. Eg v8.2sp1 is the
// same as v8.2, so to build a dll for v8.2sp1 just use IDA_820.
// 
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
//#define IDA_810			1
#define IDA_820			1

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
