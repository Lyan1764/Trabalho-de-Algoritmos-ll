#include <stdio.h>
float calcularmedia(int n, int *p){
    int i,soma=0;
    for(i=0;i<n;i++){
        soma = soma + *p;
        p++;
    }
    return (float)soma/n;

}
float meuabs(float A){

    if(A<0){
        return -A;
    }else{
    return A;
    }
}
int devetrocar(float distA, float distB, int valA, int valB){
    if(distA > distB){
        return 1;
    } 
    
    else if (distA == distB && valA > valB) {
        return 1;
    }
    
    return 0;
}

void pegardistancia(int *vet,int n,float media){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0; j<n-i-1;j++){
            float diferencaA = media - *(vet+j); 
            float diferencaB = media - *(vet+j+1);
            diferencaA = meuabs(diferencaA);
            diferencaB = meuabs(diferencaB);
            if(devetrocar(diferencaA,diferencaB,*(vet+j),*(vet+j+1))){
                temp = *(vet+j);
                *(vet+j)= *(vet+j+1);
                *(vet+j+1)= temp;
                
            }
        }
    }
   

}

int main (){
    int n,i;
    printf("digite o tamanho do vetor \n");
    scanf("%d",&n);
    int vet[n],*p=vet;

    printf("digite os elementos do vetor \n");
    
    for(i=0;i<n;i++){

        scanf("%d",p);
        p++;
    }
    float media = calcularmedia(n,vet);

    pegardistancia(vet,n,media);
    p=vet;
    printf("a media: %.2f \n",media);
    for(i=0;i<n;i++){
        printf(" %d ",*p);
        p++;
    }
    
    return 0;
}