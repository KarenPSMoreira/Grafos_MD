/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** matrizIncidencia(int nV, int nA, int array[]);
int ** grauVertice(int **pMatriz, int vtc,int nV, int nA,int array[]);

void imprimirMatriz(int **pMatriz, int l, int c, int array[] );


int main()
{
    
    int nV=0, nA, i, aux;
    int **pMatrizInc;
    int op;
    int array[nV];
    
    
    do{
    	fflush(stdin);
    	
    	printf("\n\n\t============================================\n\n");
    	printf("\t\tMENU - GRAFOS SIMPLES\n\n");
    	printf("\t============================================\n\n");
    	printf("\t ESCOLHA A OPCAO DESEJADA:  \n\n");
		printf("\t  1  %c   Novo Grafo\n\n\t  2  %c   Matriz de Incidencia\n\n\t  3  %c   Matriz de Adjacencia\n\n\t  4  %c   Grau do Vertice\n\n\t  5  %c   Conjuntos do Grafo\n\n\n\t  6   %c  Sair\n",16,16,16,16,16,16);
		printf("\t____________________________________________   \n\n\t  %c     ",26);
		scanf("\n%d",&op);
		
		fflush(stdin);
		switch(op){
			case 1:
				nA=0;
				fflush(stdin);
				printf("\n\tInforme o numero de elementos: ");
    			scanf("%i",&nV);
    			
    			printf("\n\t%i\t", nV);
			    for(i=0; i<nV; i++){ // Letra A)
			    	
			        printf("\t\t - Elemento %d: ",(i+1));
			        scanf("%d", &array[i]);
			    }
			    for(i=0; i<nV; i++){
			    	printf("\n\t%d\t|", array[i]);
				}
			    break;
			    
			case 2:
				if(nV==0){
					printf("\n\tAtencao! Grafo nao inicializado. (Opcao 1 do menu)\n ");
					break;
				}
				do{ 
					printf("\n\tInforme o numero de arestas: \n");
        			scanf("%d", &nA);
        
        			if(nA>((((nV*nV)-nV)/2))){
            			printf("\n	Invalido! Informe um valor entre 1 e %d\n",(((nV*nV)-nV)/2));
        			}
    			}while(nA > ((((nV*nV)-nV)/2)) || nA < 1); //limite de arestas de um grafo simples
    			
    			pMatrizInc = matrizIncidencia(nV, nA, array); // funcao para cirar a matriz de incidencia
    
    			printf("\n\n\t\tMATRIZ DE INICIDENCIA\n\n\t\t"); //imprimir matriz
    			for(i=0; i<nA; i++){
        			printf("|a%d\t",i+1);
    			}
    			imprimirMatriz(pMatrizInc, nV, nA, array);
				break;
				
			case 3:
				if(nV==0){
					printf("\n\tAtencao! Grafo nao inicializado. (Opcao 1 do menu)\n ");
					break;
				}
				break;
				
			case 4:
				if(nA==0){
					printf("\n\tAtencao! Matriz de Incidencia não inicializada. (Opcao 2 do menu)\n ");
					break;
				}
				
				printf("\n\n\tDigite o vertice: ");
        		scanf("%d", &aux);
        		grauVertice(pMatrizInc, aux,nV, nA, array);
				
				break;
				
			case 5:
				if(nV==0){
					printf("\n\tAtencao! Grafo nao inicializado. (Opcao 1 do menu)\n ");
					break;
				}
				break;
			case 6:
				printf("\t____________________________________________\n\n");
						printf("\tDesenvolvido por:\n\n");
						printf("\tGuilherme Henrique   \n");
						printf("\tKaren Moreira   \n");
						printf("\n\n\tCIENCIA DA COMPUTACAO - 03/2022");
						
						break;
			
			default:
				printf("\n\t\t  Insira uma opcao valida!");
				break;
			
		}
				
    	
	}while(op!=6);
    
   
}

int ** matrizIncidencia(int nV, int nA, int array[]){
    
    int vrt1,vrt2, i, n, m, valido = 1; //sendo n = Linha e M = Coluna
    for(i=0; i<nV; i++){
			    	printf("\n\t%d\t|", array[i]);
				}
    
    int **pMtrInc = malloc(nV * sizeof(*pMtrInc));
    for(n = 0; n<nV; n++){//alocando memoria
        pMtrInc[n] = malloc(nA * sizeof(*pMtrInc[n]));
        for(m = 0; m<nA; m++){
            pMtrInc[n][m] = 0;
        }
    }
    
    printf("\n\tDefina as extremidades das arestas aX: {v1,v2}\n");
    
    for(m=0; m<nA; m++){ //definindo a matriz com base na aresta (coluna)
        printf("\n\t%c a%d : {\n",26,m+1);
        do{//validando se o v1 existe dentro do array
        	fflush(stdin);
            fprintf(stdout,"\t\tv1 = ");
            scanf("%d",&vrt1);
            for(n=0; n<nV; n++){
                if(vrt1==array[n]){
                    valido = 1;
                    pMtrInc[n][m] = pMtrInc[n][m]+1;
                    break;
                }else{
                    valido = 0;
                }
            }
            if(valido==0){
                printf("\n\tVertice invalido. Tente novamente\n");
            }
        }while(valido==0);
        
        do{//validando se o v2 existe dentro do array
        	fflush(stdin);
            printf("\t\tv2 = ");
            scanf("%d",&vrt2);
            for(n=0; n<nV; n++){
            	if(vrt2==vrt1){
            		valido = 0;
            		break;
				}else if(vrt2==array[n]){
                    valido = 1;
                    pMtrInc[n][m] = pMtrInc[n][m]+1;
                    printf("\t\t}\n");
                    break;
                }else{
                    valido = 0;
                }
            }
            if(valido==0){
                printf("\nVertice invalido. Tente novamente\n");
            }
        }while(valido==0);
        
    }
    
    return pMtrInc;
}

int ** grauVertice(int **pMatriz, int vtc, int nV, int nA, int array[]){
    int cont = 0, x, y;
    for(x=0;x<nV;x++){
    	if(vtc==array[x]){
    		for(y=0; y<nA; y++){
    			cont = cont + pMatriz[x][y];
    			
			}
		}
	}
    printf("\n\t\tGrau do vertice %d = %d", vtc, cont);
}

void imprimirMatriz(int **pMatriz, int l, int c, int array[] ){
	int n, m;
    for(n = 0; n<l; n++){
        printf("\n\t%d\t|", array[n]);
      
        for( m = 0; m<c; m++){
            printf("%d\t|", pMatriz[n][m]);
        }
    }
    
}


