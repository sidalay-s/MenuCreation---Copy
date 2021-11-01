#ifndef GAME_H
#define GAME_H

#include <string>
#include "raylib.h"
#include "window.h"

class Game
{
private:
    Vector2 Window{};
    int FramesPerSecond{};
    void Update();
    void Draw();
    void SetFullScreen();
public:
    Game(Vector2 &window, std::string title, int FPS);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;
    bool GameShouldClose() const;

    void Tick();
};

#endif