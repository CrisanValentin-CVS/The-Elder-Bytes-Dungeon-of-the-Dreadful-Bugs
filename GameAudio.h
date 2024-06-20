#ifndef GAMEAUDIO_H
#define GAMEAUDIO_H

#include <string>
#include <windows.h>

class GameAudio {
public:
    static void playSound(const std::string& soundFile);
    static void stopSound();
};

#endif
