#ifndef CROSSROADS_H
#define CROSSROADS_H

#include <iostream>
#include <cstdlib> // For rand()
#include <ctime> // For time()

class Crossroads {
public:
    enum class Scene { Forest, Village, Cave };

    Crossroads();
    void explore();
    bool continueJourney();
    Scene getCurrentScene() const;

private:
    void choosePath() const;
    Scene currentScene;
};

#endif // CROSSROADS_H
