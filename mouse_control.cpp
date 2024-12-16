#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>

/**
 * Generates a random integer within the specified range.
 *
 * @param min The minimum value (inclusive) of the desired random number.
 * @param max The maximum value (inclusive) of the desired random number.
 * @return A random integer between min and max, inclusive.
 */
int getRandomNumber(int min, int max)
{
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main()
{
    POINT mousePointer;
    // screen height and width
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    std::cout << "Hold the escape key to exit." << std::endl;
    // random mouse movement
    boolean isRunning = true;
    while (isRunning)
    {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            std::cout << "Program exited" << std::endl;
            isRunning = false;
            break;
        }
        mousePointer.x = getRandomNumber(0, screenWidth);
        mousePointer.y = getRandomNumber(0, screenHeight);
        SetCursorPos(mousePointer.x, mousePointer.y);
        Sleep(3000);
    }
    return 0;
}