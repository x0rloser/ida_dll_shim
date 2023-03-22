# ida.dll compatibility shim
v0.1.1
xorloser
November 2022 - March 2023

This is targeted for usage with IDA Pro since that is the version I use.
If you use another version such as IDA Teams and this does work with it,
then get in contact with me or raise an issue on github.


## What is this for?
This enables customising how ida.dll/ida64.dll works by potentially adding,
removing, replacing or intercepting its dll exports.

The main reason I made this was for forward compatibility support of older
HexRays Decompiler versions with newer IDA versions. Specifically HexRays
decompilers v7.6 and v7.7 do not work with IDA v8.x due to some exports that
were removed from ida.dll in IDA v8.x. When the decompilers are loaded
they attempt to import a list of functions/data from ida.dll and if any are
not found they throw an error and close IDA.

By using this compatibility shim you can use your older v7.6 and v7.7
decompilers with IDA v8.x without having to patch any files.

The decompilers have backward compatibility support by checking the IDA
version and only importing functions/data that it knows exists in older
versions of IDA. However they assume that exports will not be removed in
newer versions of IDA and so fail if this is the case.

The HexRays developers could fix this by adding dummy versions of the
removed exports into future ida.dll releases.
The exports that are missing are documented in 'ida_dll_exports.h'.


## How to build
Open the Visual Studio solution in VS2022.
Edit DllMain.cpp to uncomment only the IDA version you want to use this with.
eg uncomment the line ```#define IDA_810    1``` for use with IDA v8.1
(You will need to build separate files for each version of IDA you want to use
this with.)
Now build the solution for Release configuration to get ida.dll.
Then build the solution for Release64 configuration to get ida64.dll.
(Or batch build both at the same time)


## How to install
Navigate to your IDA install directory.
Rename ida.dll to ida-orig.dll
Rename ida64.dll to ida64-orig.dll
Build the ida_dll_shim project configurations Release and Release64.
Copy in the result ida_dll_shim files ida.dll and ida64.dll into your
IDA install directory.


## How to uninstall
Navigate to your IDA install directory.
Delete the ida_dll_shim ida.dll and ida64.dll files from your
IDA install directory.
Rename ida-orig.dll to ida.dll
Rename ida64-orig.dll to ida64.dll


## History

v0.1.1 - fixed an issue that made IDA throw an error when trying to use the
         previous version of this. (sorry about that)
       - added support for ida v8.2sp1 

v0.1.0 - initial version
