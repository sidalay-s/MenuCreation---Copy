#include "Game.h"
#include <assert.h>

Game::Game(Vector2 &window, std::string title, int FPS)
    : Window{window}, FramesPerSecond{FPS}
{
    assert(!GetWindowHandle()); // if assertion triggers : Window is already opened
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    SetExitKey(0);
    InitWindow(window.x, window.y, title.c_str());
    SetTargetFPS(FPS);
}

Game::~Game()
{
    assert(GetWindowHandle()); // if assertion triggers : Window is already closed
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    // set window.x / window.y to resized dimensions
    if (IsWindowResized())
    {
        Window.x = GetScreenWidth();
        Window.y = GetScreenHeight();
    }
    // check for alt + enter
    if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
    {
        SetFullScreen();
    }

    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Update()
{

}

void Game::Draw()
{
    ClearBackground(BLACK);
}

void Game::SetFullScreen()
{
    // see what display we are on right now
    int display = GetCurrentMonitor();

    if (IsWindowFullscreen()) 
    {
        // if we are full screen, then go back to the windowed size
        ToggleFullscreen();                  
        SetWindowSize(Window.x, Window.y); 
    }
    else
    {                                        
        // if we are not full screen, set the window size to match the monitor we are on
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        ToggleFullscreen();
    }
}