#pragma once
#include "State.h"
#include "Entity.h"
class GameState :
    public State {
private:
    Entity player;

    // functions
    void initKeybinds();

public:
    GameState(sf::RenderWindow* window, std::map<char, int>* supportedKeys);
    virtual ~GameState();


    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
