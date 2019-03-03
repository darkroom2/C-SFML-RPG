#pragma once
class Game {
private:
    // variables
    sf::RenderWindow* window;
    sf::Event sfEvent;


    // init funcs
    void initWindow();

public:
    Game();
    virtual ~Game();

    // functions
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};

