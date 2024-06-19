#ifndef GAMEAUDIO_H
#define GAMEAUDIO_H

#include <string>

class GameAudio {
public:
    static void playSound(const std::string& filename);
    static void stopSound();

private:
    static std::wstring stringToWString(const std::string& s);
};

#endif // GAMEAUDIO_H
