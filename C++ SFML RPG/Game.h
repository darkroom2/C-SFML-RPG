#pragma once
#include "GameState.h"

class Game {
private:
    // variables
    sf::RenderWindow* window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    std::map<char, int> supportedKeys;

    // init funcs
    void initWindow();
    void initStates();
    void initKeys();

public:
    Game();
    virtual ~Game();

    // functions
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};

