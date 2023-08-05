#include <iostream>
#include <windows.h>


int main() {
    LPCWSTR mutexName = TEXT("MutexName");
    HANDLE mutex = CreateMutex(NULL, true, mutexName);

    if (GetLastError() == ERROR_ALREADY_EXISTS) { // check if the mutex already exists
        std::cerr << "Program already is running..." << std::endl;
        CloseHandle(mutex);
        system("pause");
        return 0;
    }

    std::cout << "No instance found, running program" << std::endl;

    for (int i = 0; i <= 15; i++) { // program simulation
        Sleep(1000);
        std::cout << i << "/15" << std::endl;
    }

    CloseHandle(mutex);

    return 0;
}
