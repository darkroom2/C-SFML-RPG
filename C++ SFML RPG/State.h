#pragma once
class State {
private:

protected:
    sf::RenderWindow* window;
    std::map<char, int>* supportedKeys;
    std::map<std::string, int> keyBinds;

    bool quit;

    // resources
    std::vector<sf::Texture> textures;

    // functions
    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<char, int>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;

    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

