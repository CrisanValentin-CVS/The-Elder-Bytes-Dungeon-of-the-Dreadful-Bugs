#include "GameAudio.h"
#include <windows.h>
#include <mmsystem.h> // Include for multimedia functions

#pragma comment(lib, "Winmm.lib") // Link against Winmm.lib

// Convert a narrow character string to a wide character string
std::wstring GameAudio::stringToWString(const std::string& s) {
    int len;
    int slength = static_cast<int>(s.length()) + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    std::wstring r(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
    return r;
}

// Function to play sound
void GameAudio::playSound(const std::string& filename) {
    std::wstring wFilename = stringToWString(filename);
    PlaySound(wFilename.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Function to stop sound
void GameAudio::stopSound() {
    PlaySound(NULL, NULL, SND_ASYNC);
}
