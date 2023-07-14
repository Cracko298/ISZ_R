#include <Windows.h>
#include <TlHelp32.h>

bool g_Running = false;

extern "C"
{
int printf(const char *format, ...);
}

bool isAppRunning(const wchar_t* appName)
{
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        // Error handling
        return false;
    }

    PROCESSENTRY32W processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(snapshot, &processEntry))
    {
        do
        {
            if (_wcsicmp(processEntry.szExeFile, appName) == 0)
            {
                CloseHandle(snapshot);
                return true;
            }
        } while (Process32NextW(snapshot, &processEntry));
    }

    CloseHandle(snapshot);
    return false;
}

void PressKey(WORD key)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void TypeString(const char* str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        WORD keyCode = LOBYTE(VkKeyScanA(str[i])); // Extract low byte correctly

        PressKey(keyCode);
    }
}

void StartTyping()
{
    const char* textToType1 = "set Engine.CharacterMovementComponent MaxWalkSpeed 900";
    const char* textToType2 = "set Engine.CharacterMovementComponent MaxWalkSpeed 600";
    const WORD backtickKeyCode = VK_OEM_3; // Backtick code

    g_Running = true;
    while (g_Running)
    {
        if (GetAsyncKeyState(VK_OEM_PERIOD) & 0x8000)
        {
            Sleep(50);

            PressKey(backtickKeyCode);
            TypeString(textToType1);
            PressKey(VK_RETURN);
            printf("Player State: Running.\n");

            if (GetAsyncKeyState(0x57) & 0x8000)
            {
                PressKey(0x57);
                Sleep(5);
                PressKey(0x57);
                Sleep(5);
                PressKey(0x57);
                Sleep(5);
                PressKey(0x57);
            }

            if (GetAsyncKeyState(0x53) & 0x8000)
            {
                PressKey(0x53);
                Sleep(5);
                PressKey(0x53);
                Sleep(5);
                PressKey(0x53);
                Sleep(5);
                PressKey(0x53);
            }

            Sleep(7500);

            PressKey(backtickKeyCode);
            TypeString(textToType2);
            PressKey(VK_RETURN);
            printf("Player State: Not Running.\n");

            if (GetAsyncKeyState(0x57) & 0x8000)
            {
                PressKey(0x57);
                Sleep(5);
                PressKey(0x57);
                Sleep(5);
                PressKey(0x57);
                Sleep(5);
                PressKey(0x57);
            }

            if (GetAsyncKeyState(0x53) & 0x8000)
            {
                PressKey(0x53);
                Sleep(5);
                PressKey(0x53);
                Sleep(5);
                PressKey(0x53);
                Sleep(5);
                PressKey(0x53);
            }

            Sleep(8000);
        }
    }
}

void AppRunning()
{
    const wchar_t* appName = L"ISZ-Win64-Shipping.exe";
    if (isAppRunning(appName))
    {
        printf("ISZF Dialogue: ISZ_R Has Been Loaded.\n");
        printf("\n");
        printf("DLL Version: v1.0\n");
        printf("ISZ_R is Under Apache-2.0 License.\n");
        StartTyping();
    }
    else
    {
        printf("Ice Station Z is Not Running. Cannot hook MainApp Function.");
        Sleep(5000);
        exit(0);
    }

}

extern "C" __declspec(dllexport) void MainApp() // Entry Point
{
    AppRunning();
}

extern "C" __declspec(dllexport) void StopTyping() // Failsafe
{
    g_Running = false;
}