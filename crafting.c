#include "raylib.h"
#include <stdio.h>


typedef struct{
    int id_item;
    int qtd;
}res;

typedef struct{
    int id_result;
    int qtd_result;
    res resource[2];
    int total_resources;
}recipe;

int crafting(recipe Product ,int inventory[]){
    for(int i=0;i<Product.total_resources;i++){
        int id=Product.resource[i].id_item;
        int quantity_required = Product.resource[i].qtd;

        if (inventory[id]<quantity_required){
            printf("Materiais insuficientes! Falta o item ID %d.\n", id);
            return 0;
        }
    }
    for (int i = 0; i < Product.total_resources; i++) {
        int id = Product.resource[i].id_item;
        int quantity_required = Product.resource[i].qtd;
        
        inventory[id] -= quantity_required;
    }
    inventory[Product.id_result] += Product.qtd_result;
    printf("Produto fabricado com sucesso!");
    return 1;
}
