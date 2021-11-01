#include "raylib.h"
#include "window.h"
#include "game.h"

Vector2 Window::Dimension = {1280, 720};

int main() 
{
    // Initialization --------------------------
    Game Game{Window::Dimension, "Template", 144};

    while (!Game.GameShouldClose())
    {
        Game.Tick();
    }
}