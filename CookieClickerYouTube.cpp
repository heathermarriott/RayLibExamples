#include "raylib.h"
#include <stdlib.h> //rand, srand
#include <stdio.h> //debugging statements
#include <time.h> //for seeding random number gen with time


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(){
    //initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World Raylib");

    Texture2D cookie=LoadTexture("./Cookie.png");
    srand(time(NULL));

    int cookieX = rand() % (SCREEN_WIDTH - cookie.width);
    int cookieY = rand() % (SCREEN_HEIGHT - cookie.height);
    Color cookieColor = RAYWHITE; 

    srand(time(NULL)); 

    float lastMoveTime = GetTime();

    int score = 0; 

    while (! WindowShouldClose()) {  //keep running till Esc or window close

        BeginDrawing();
        ClearBackground(BLUE);

        if (GetTime() - lastMoveTime >=2.0f){
            //move cookie to random part of screen
            cookieX = rand() % (SCREEN_WIDTH - cookie.width);
            cookieY = rand() % (SCREEN_HEIGHT - cookie.height);
            lastMoveTime = GetTime();
            cookieColor.a = 255;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mousePos = GetMousePosition();
            Rectangle cookieBounds = { (float)cookieX, (float)cookieY, (float)cookie.width, (float)cookie.height};
            if (CheckCollisionPointRec(mousePos, cookieBounds)){
                cookieColor.a = 0;
                score++;
            }
        }

        char scoreText[50];
        snprintf(scoreText, 50, "Click on the Cookie. Score: %d", score);
        DrawText(scoreText, 10, 300, 30, RED);
        DrawTexture(cookie, cookieX, cookieY, cookieColor);
        EndDrawing();
    }

    UnloadTexture(cookie);
    CloseWindow();
    return 0;
}