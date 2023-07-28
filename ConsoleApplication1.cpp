#include <iostream>
#include <Windows.h>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


// Função para fazer o mouse clicar
void clickMouse() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = 0;
    input.mi.dy = 0;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    input.mi.mouseData = 0;
    input.mi.dwExtraInfo = 0;
    input.mi.time = 0;

    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    int durationInSeconds = 10;
    int millisecondsPerClick = 50; // Intervalo entre cada clique

    int totalClicks = (durationInSeconds * 1000) / millisecondsPerClick;

    std::cout << "O mouse clicara sem parar por 10 segundos. Pressione Ctrl + C para interromper.\n";

    for (int i = 0; i < totalClicks; ++i) {
        clickMouse();
        Sleep(millisecondsPerClick);
    }

    return 0;
}
