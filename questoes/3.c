#include <stdio.h>
#include <string.h>

struct filosofo{
    char nome[50];
    int pratos_comidos;
};
typedef struct filosofo filosofo;

void jantar(filosofo *p, int max_rodadas){
    int garfos[5]; 
    int i, rodada = 0, todos_comeram;
    
    while(rodada < max_rodadas){
        for(i=0; i<5; i++){
            garfos[i] = 0;
        }

        todos_comeram = 1; 

        for(i=0; i<5; i++){
            int garfo_esq = i;
            int garfo_dir = (i+1) % 5;

            if(garfos[garfo_esq] == 0 && garfos[garfo_dir] == 0){
                garfos[garfo_esq] = 1;
                garfos[garfo_dir] = 1;

                (p+i)->pratos_comidos++;
                strcat((p+i)->nome, "COME");
            }

            if((p+i)->pratos_comidos == 0){
                todos_comeram = 0;
            }
        }

        if(todos_comeram == 1){
            break; 
        }
        rodada++;
    }
}

int main (){
    filosofo f[5] = {
        {"Aristoteles", 0},
        {"Platao", 0},
        {"Socrates", 0},
        {"Kant", 0},
        {"Nietzsche", 0}
    };
    
    int rodadas, i, total=0;
    filosofo *p = f; 

    printf("digite o numero maximo de rodadas \n");
    scanf("%d", &rodadas);

    jantar(p, rodadas);

    printf("Nomes: ");
    for(i=0; i<5; i++){
        printf("%s, ", (p+i)->nome);
        total = total + (p+i)->pratos_comidos;
    }
    printf("\nTotal de pratos comidos: %d \n", total);

    return 0;
}