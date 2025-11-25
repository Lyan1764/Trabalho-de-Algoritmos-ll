#include <stdio.h>
#include <string.h>

//funcao para separar e armazenar 
void separar(char (*palavras1)[200], char *frase1){
    
    char primeira[200];
    strcpy(primeira,frase1);
    char *token;
    
    token = strtok(primeira," ");

    while(token != NULL){
        strcpy(*palavras1,token);
        token = strtok(NULL," ");
        palavras1++;

    }

}
float jaccard(char (*palavras1)[200], char (*palavras2)[200],char (*rpt)[200]){
    int tam1=0,tam2=0,i,j,c=0;

    char (*inicio1)[200] = palavras1;
    char (*inicio2)[200] = palavras2;


    while(**palavras1!='\0'){
        tam1++;
        palavras1++;
    }

    while(**palavras2!= '\0'){
        tam2++;
        palavras2++;
    }

    palavras1 = inicio1;
    palavras2 = inicio2;


    for(i=0;i<tam1;i++){
        for(j=0;j<tam2;j++){
            if(strcmp(*palavras1,*palavras2)== 0){
                c++;
                strcpy(*rpt,*palavras1);
                rpt++;
                break;
            }
            palavras2++;
        }
        palavras2 = inicio2;
        palavras1++;
    }
    int uniao = (tam1+tam2) - c;
    //forçar o resultado de divisao de inteiros resultando em um float
    return (float)c/uniao;

}

int main (){
    //incializando com 0 para remover o lixo de memoria e saber o fim do vetor;
    char palavras1[10][200]={0},palavras2[10][200]={0};
    char repetidas[10][200]={0},f1[200],f2[200];
    char (*rpt)[200] = repetidas;

    printf("digite a primeira frase \n");
    scanf(" %199[^\n]", f1);

    printf("digite a segunda frase \n");
    scanf(" %199[^\n]", f2);

    separar(palavras1,f1);
    separar(palavras2,f2);

    float indice = jaccard(palavras1,palavras2,repetidas);
    printf("a intersecao:");

    //acontece ate não encontrar palavras dentro do vetor
    while(**rpt != '\0'){
        printf(" %s ,",*rpt);
        rpt++;
    }
    printf("\n"); 
    printf("o indice do jaccard e de : : %.2f\n",indice);  
    
    return 0;
}