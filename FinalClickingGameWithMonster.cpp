#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {
    //initialize window - Width, Height, Title
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Title");
 
    Texture2D images[6];
    images[0]=LoadTexture("./Cookie.png");
    images[1]=LoadTexture("./cupcake.png");
    images[2]=LoadTexture("./icecream.png");
    images[3]=LoadTexture("./blueMonster.png");
    images[4]=LoadTexture("./pizza.png");
    images[5]=LoadTexture("./popcorn.png");
    srand(time(NULL));

    Texture2D* ptr = &images[1];

    // Initial cookie position
    int cookieX = rand() % SCREEN_WIDTH;
    int cookieY = rand() % SCREEN_HEIGHT;

    int score = 0;
    float lastMoveTime = GetTime(); // Time tracking
    int imageNum = 0;
    Color cookieColor = RAYWHITE; // Includes alpha

    bool isGameOver = false;

    //run the application
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);

        if (isGameOver){
            DrawText("Game Over!", 300, 250, 60, RED);
        }
        else {
            // Move cookie every 1 second
            if (GetTime() - lastMoveTime >= 1.0f) {
                cookieX = rand() % (SCREEN_WIDTH - images[0].width);
                cookieY = rand() % (SCREEN_HEIGHT - images[0].height);

                imageNum = rand()%4;
                ptr = &images[imageNum];
                
                cookieColor.a = 255; // Reset alpha to fully visible
                lastMoveTime = GetTime();
            }

            // Detect mouse click on cookie
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                Rectangle cookieBounds = { (float)cookieX, (float)cookieY, (float)(*ptr).width, (float)(*ptr).height };
                if (CheckCollisionPointRec(mousePos, cookieBounds)) {
                    if (imageNum == 3){
                        printf("game over");
                        isGameOver = true;
                    }
                    score++;
                    cookieColor.a = 0; // Make cookie invisible
                }
            }

            DrawTexture((*ptr), cookieX, cookieY, cookieColor);

            //Text you want, x-position, y-position, font size, Color
            //0,0 is upper left corner
            char scoreText[50];
            snprintf(scoreText, 50, "Click on Food. Score: %d", score);
            DrawText(scoreText, 100, 300, 50, YELLOW);
        }
        EndDrawing();
    }

    UnloadTexture(images[0]);
    UnloadTexture(images[1]);
    UnloadTexture(images[2]);
    UnloadTexture(images[3]);
    UnloadTexture(images[4]);
    UnloadTexture(images[5]);
    //close the application
    CloseWindow();
    return 0;
}