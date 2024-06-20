#include "GameAudio.h"
#include <windows.h>
#include <mmsystem.h> // Include for multimedia functions

#pragma comment(lib, "Winmm.lib") // Link against Winmm.lib

void GameAudio::playSound(const std::string& soundFile) {
    std::wstring wideSoundFile(soundFile.begin(), soundFile.end());
    PlaySound(wideSoundFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

void GameAudio::stopSound() {
    PlaySound(NULL, 0, 0);
}