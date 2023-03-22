//#define FORWARDED_EXPORT(procname, DLL_NAME) \
//	__pragma(comment(linker, "/export:" #procname "=" #dllname "." #procname))

#ifdef IDA64
// 64bit
//#define DLL_NAME	"ida64-orig"
#define FORWARDED_EXPORT(procname, DLL_NAME) \
	__pragma(comment(linker, "/export:" #procname "=" "ida64-orig" "." #procname))
#else
// 32bit
//#define DLL_NAME	"ida-orig"
#define FORWARDED_EXPORT(procname, DLL_NAME) \
	__pragma(comment(linker, "/export:" #procname "=" "ida-orig" "." #procname))
#endif

#if   defined(IDA_700)
#include "ida_dll_700_exports.h"
#elif defined(IDA_710)
#include "ida_dll_710_exports.h"
#elif defined(IDA_710SP1)
#include "ida_dll_710sp1_exports.h"
#elif defined(IDA_720)
#include "ida_dll_720_exports.h"
#elif defined(IDA_730)
#include "ida_dll_730_exports.h"
#elif defined(IDA_740)
#include "ida_dll_740_exports.h"
#elif defined(IDA_750)
#include "ida_dll_750_exports.h"
#elif defined(IDA_760)
#include "ida_dll_760_exports.h"
#elif defined(IDA_770)
#include "ida_dll_770_exports.h"
#elif defined(IDA_800)
#include "ida_dll_800_exports.h"
#define IDA_MISSING_FUNCS	1
#elif defined(IDA_810)
#include "ida_dll_810_exports.h"
#define IDA_MISSING_FUNCS	1
#elif defined(IDA_820)
#include "ida_dll_820_exports.h"
#define IDA_MISSING_FUNCS	1
#else
#error "You need to define an IDA_XXX version specifier"
#endif


// Missing functions in ida.dll v8.x
// These are needed for v7.6 and v7.7 HexRays decompilers to work with IDA v8.x
#if defined(IDA_MISSING_FUNCS)
#define EXTERNC         extern "C"
#define idaapi            __stdcall
#define ida_export        idaapi
#define idaman EXTERNC __declspec(dllexport)


// retn 0
idaman int ida_export merge_handler_ctr() { return 0; }
idaman int ida_export merge_handler_dtr() { return 0; }
idaman int ida_export merge_handler_init() { return 0; }
idaman int ida_export merge_handler_perform_diff() { return 0; }
idaman int ida_export merge_handler_dump_merge_results() { return 0; }
idaman int ida_export get_ea_diffpos_name() { return 0; }
idaman int ida_export destroy_moddata_merge_handlers() { return 0; }

// xor     eax, eax; retn
idaman int ida_export create_moddata_diff_source() { return 0; }
idaman int ida_export merge_handler_perform_merging() { return 0; }
idaman int ida_export create_byfunc_merge_handler() { return 0; }

// this was implemented with the code shown below
// but we will just use a dummy function for simplicity.
idaman int ida_export create_nodeval_merge_handler() { return 0; }

/*
typedef unsigned long long u64;
idaman int ida_export create_nodeval_merge_handler(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
	u64* p_obj1 = (u64*)a7;
	u64* p_obj2 = (u64*)p_obj1[7];
	if (p_obj2)
	{
		u64* p_obj2_vtable = (u64*)p_obj2[0];
		void (*p_func)(void* _this, void* a2, void* a3, void* a4, void* a5, void* a6) = (void (*)(void* _this, void* a2, void* a3, void* a4, void* a5, void* a6))p_obj2_vtable[4];

		p_func(p_obj2, a2, a3, a4, a5, a6);
		p_obj1[7] = NULL;
	}
	return 0;
}
*/

#endif // defined(IDA_MISSING_FUNCS)
