#include "raylib.h"

<<<<<<< HEAD
// Ao modificar o codigo, o projeto deve ser recompilado para que as alterações tenham efeito.
// comando pra fazer isso: gcc main.c -o jogo.exe -I C:\raylib\include -L C:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm
// certifiqque-se de que o jogo previamente aberto foi fechado antes de recompilar.
// para executar o jogo, abra o terminal na pasta do projeto e digite: ./jogo.exe

=======
>>>>>>> cf505f92a625d724bfb1bf2749283a75404b3b23
int main(void) {
    // Inicializa a janela (Largura, Altura, Titulo)
    InitWindow(800, 450, "raylib - Meu Primeiro Jogo no Windows");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
<<<<<<< HEAD
            DrawText("mds funciona", 190, 200, 20, LIGHTGRAY);
=======
            DrawText("Parabens! Raylib instalada com sucesso!", 190, 200, 20, LIGHTGRAY);
>>>>>>> cf505f92a625d724bfb1bf2749283a75404b3b23
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
