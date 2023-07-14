# ISZ_R
- A simple Dynamic Link Library *.dll *.so Shared Library for ISZ-2021 which permits Running in ISZ.
- Requires the UE4 Console, and needs to be called from another Application or Script.
- Ice Station Z needs to be opened to load the Plugin.

# Download Compiled:
- Download [Windows x64]().
- Download [Linux/Unix]().
- Download [ISZF(H)](https://github.com/ISZ-Hacker-Organization/ISZF/raw/main/py_compiled/iszf.exe) (Ice Station Z Function Hook).

# Loading/Injecting:
```
> C++       LoadLibrary (Call the function MainApp).
> Python    Ctypes.CDLL (Call the function MainApp).
```

# Building:
### Windows x64:
```
> g++ -shared -o ISZ_Rx64w.dll ISZ_Rx64w.cpp
```
### Linux/Unix:
```
> g++ -shared -o ISZ_Rx64l.so -fPIC ISZ_Rx64w.cpp -luser32
```
## Requirements:
> Standard Linkage Library.
> 
> C++ 14 (or Newer).
> 
> GCC or MinGW-w64
>
> Ice Station Z Function Hook (ISZFH) Executable (Or another app to load ISZ Functions via MainApp).


# Name Scheme:
```
ISZ_R     x64/X32        w/l          *.dll/*.so
^ Name    ^ CPU Arch     ^ OS Type    ^ Extension
```

# Notes:

## Features:
- Enables Running in ISZ-2021.
- 

## Update Note(s):
### Version v1.0 Released
- Running is Still Jank. But works well enough to warrent a Release.
