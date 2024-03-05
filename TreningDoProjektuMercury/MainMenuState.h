#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "State.h"
#include "Button.h"
#include "GameState.h"
class MainMenuState :
    public State
{
private:
    //Variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    
    std::map<std::string, Button*> buttons;

    //Functions
    void initVariables();
    void initFonts();
    void initKeybinds();
    void initButtons();
    void initBackground();
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack <State*>* states);
    virtual ~MainMenuState();

    //Functions

    void updateInput(const float& dt);
    void updateButtons(const float& dt);
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // !MAINMENUSTATE_H
