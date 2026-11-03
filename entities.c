#include "raylib.h"
#include <stdio.h>

typedef struct{
    Vector2 posicao;
    int vida;
    int vida_maxima;
    bool quebrado;
    float tempo_renascimento;
    float cooldown_renascimento;
}Recursos;

typedef struct {
    Vector2 posicao;
    float velocidade;
    int nivel; //isso aqui é pra usar na progressão do jogo depois
    //eu gosto muito do jeito que risk of rain faz spawn de monstro, se vcs quiserem me perguntar sobre dps eu explico

    float vida;
    float vida_maxima;
    float ataque;
    float defesa;

    bool morto;
} Monstro;
/*
a ideia é:
<A ataca B> 
B.vida -= max(0, A.ataque - B.defesa);
if B.vida <= 0;
    B.morto = true;
*/

void quebrar_recurso(Recursos *recurso, int dano) {
    if (recurso->quebrado) return; // Não dá para quebrar o que já está quebrado

    recurso->vida -= dano;

    if (recurso->vida <= 0) {
        recurso->quebrado = true;
        recurso->tempo_renascimento = recurso->cooldown_renascimento; // Inicia a contagem regressiva
    }
}


void atualiza_recurso(Recursos *recurso, int quant) {
    float deltaTime = GetFrameTime(); // Tempo do frame atual em segundos

    for (int i = 0; i < quant; i++) {
        if (recurso[i].quebrado) {
            // Conta o tempo para renascer
            recurso[i].tempo_renascimento -= deltaTime;

            if (recurso[i].tempo_renascimento <= 0.0f) {
                // Renasce a árvore!
                recurso[i].quebrado = false;
                recurso[i].vida = recurso[i].vida_maxima;
            }
        }
    }
}

