#include "button.h"

Button::Button(Vector2 ScreenPos = {20.f, 20.f}, 
               Rectangle Outline = {0.f,0.f,200.f,100.f}, 
               Texture2D Idle = {}, 
               Texture2D Active = {})
    : ScreenPos{ScreenPos}, Outline{Outline}, Idle{Idle}, Active{Active}
{

}

Button::~Button()
{
    UnloadTexture(Idle);
    UnloadTexture(Active);
}

void Button::Tick(float DeltaTime)
{

}

void Button::Draw()
{
    
}