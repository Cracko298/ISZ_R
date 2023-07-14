import ctypes
from time import sleep
from os import path

def execute_dll():
    # Load the DLL
    dll_path = "ISZ_Jx64w.dll"

    if path.exists(dll_path) != True:
        dll_path = "ISZ_Rx64w.dll"


    my_dll = ctypes.CDLL(dll_path)

    try:
        # Define the MainApp function signature
        main_app_func = my_dll.MainApp
        main_app_func.restype = None  # Set the return type of the function

        # Call the MainApp function
        main_app_func()
        
    except AttributeError:
        print("ISZF Dialogue: Could not find the MainApp function in the Shared Library DLL.")
        sleep(5)

execute_dll()