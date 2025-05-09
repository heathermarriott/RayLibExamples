#include "raylib.h"

int main() {
    //initialize window - Width, Height, Title
    InitWindow(800, 600, "Raylib Title");
 
    //run the application
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);

        //Text you want, x-position, y-position, font size, Color
        //0,0 is upper left corner
        DrawText("Hello World in raylib!", 100, 300, 50, RED);

        EndDrawing();
    }

    //close the application
    CloseWindow();
    return 0;
}

