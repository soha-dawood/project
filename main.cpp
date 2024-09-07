#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
    SetConsoleCursorPosition(hConsole, coord);
}

void printCenteredText(const string &text, int width) {
    int len = text.length();
    int spaces = (width - len) / 2;
    for (int i = 0; i < spaces; ++i) cout << " ";
    cout << text;
}

void printWelcomeToSSHBank() {
    cout <<"*                 *   * * * * *   *          *********   ***********  ***          ***  * * * * * "<<endl;
    cout <<"*                 *   *           *          *           *         *  *  *        *  *  *         "<<endl;
    cout <<"*       ***       *   *           *          *           *         *  *   *      *   *  *          "<<endl;
    cout <<"*     *     *     *   *********   *          *           *         *  *    *    *    *  *********  "<<endl;
    cout <<"*    *       *    *   *           *          *           *         *  *     *  *     *  *          "<<endl;
    cout <<"*   *         *   *   *           *          *           *         *  *      **      *  *          "<<endl;
    cout <<"*  *           *  *   *           *          *           *         *  *              *  *          "<<endl;
    cout <<"***             ***   * * * * *   *********  **********  ***********  *              *  * * * * *   "<<endl;

}

int main() {
    // Set text color (Light Green for this example)
    setColor(10);

    // Get console dimensions
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int consoleWidth = csbi.dwSize.X;

    // Print centered text
    clearScreen(); // Clear screen before printing
    printWelcomeToSSHBank();

    // Wait for 5 seconds
    Sleep(20000);

    // Clear the screen before exiting
    clearScreen();

    // Reset color to default
    setColor(7); // Default color

    return 0;
}
