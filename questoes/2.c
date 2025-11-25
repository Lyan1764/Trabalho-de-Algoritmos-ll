#include <stdio.h>
#include <string.h>

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
float jaccard(char (*palavras1)[200], char (*palavras2)[200]){
    int tam1=0,tam2=0,i,j,c=0;
    char repetida[10][200],*rpt=*repetida;

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
                strcpy(rpt,*palavras1);
                break;
            }
            palavras2++;
        }
        palavras2 = inicio2;
        palavras1++;
    }
    int repetidas = (tam1+tam2) - c;
    return (float)c/repetidas;

}

int main (){

    char f1[200],f2[200],palavras1[10][200]={0},palavras2[10][200]={0};
    printf("digite a primeira frase \n");
    scanf(" %199[^\n]", f1);
    printf("digite a segunda frase \n");
    scanf(" %199[^\n]", f2);

    separar(palavras1,f1);
    separar(palavras2,f2);
    float indice = jaccard(palavras1,palavras2);
    printf("o indice do jaccard eh : %.2f\n",indice);

    return 0;
}