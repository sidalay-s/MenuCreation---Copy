#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

class Button 
{
private:
    Vector2 ScreenPos{};
    Rectangle Outline{};
    Texture2D Idle{};
    Texture2D Active{};
    bool isActive{false};

public:
    Button(Vector2 ScreenPos, Rectangle Outline, Texture2D Idle, Texture2D Active);
    ~Button();
    void Tick(float DeltaTime);
    bool isActivated() {return isActive;}
    void Draw();
    void LoadIdleTexture(Texture2D Idle) {this->Idle = Idle;}
    void LoadActiveTexture(Texture2D Active) {this->Active = Active;}
};

#endif