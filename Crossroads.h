#ifndef CROSSROADS_H
#define CROSSROADS_H

#include <iostream>
#include <cstdlib> // For rand()
#include <ctime> // For time()

class Crossroads {
public:
    void explore();
    bool continueJourney() const;

private:
    void choosePath() const;
};

#endif // CROSSROADS_H
