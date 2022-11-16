/******************************************************************************
    Authors:
        Guilherme Henrique Luiz E. Pereira
        Karen P.S. Moreira
    FUMEC University - Computer Science - Discrete Mathematics 2022/2
    Instructor: Emerson Eustaquio

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **matrizIncidencia(int nV, int nA, int *pArray);
int **matrizAdjacencia(int nV, int *pArray);
int **grauVertice(int **pMatriz, int vtc, int n, int nA, int *pArray);
void vertArestAdj(int **pMtrAdj, int nV);
void imprimirMatriz(int **pMatriz, int n, int m, int *pArray);

int main()
{
    int nV, nA, i, aux;
    int **pMatrizInc;
    int **pMatrizAdj;
    int op;
    int *pArray;

    do
    {
        fflush(stdin);
        int array[nV];

        printf("\n\n\t============================================\n\n");
        printf("\t\t  MENU - GRAFOS SIMPLES\n\n");
        printf("\t============================================\n\n");
        printf("\t ESCOLHA A OPCAO DESEJADA:  \n\n");
        printf("\t  1  %c   Novos Elementos \n\n\t  2  %c   Matriz de Incidencia\n\n\t  3  %c   Matriz de Adjacencia\n\n\t  4  %c   Grau do Vertice\n\n\t  5  %c   Conjuntos do Grafo\n\n\n\t  6   %c  Sair\n", 16, 16, 16, 16, 16, 16);
        printf("\t____________________________________________   \n\n\t  %c     ", 26);
        scanf("\n%d", &op);

        fflush(stdin);
        switch (op)
        {
        case 1: // Letra A) --> definir a quantidade de elementos (vertices) e preencher array
            nA = 0;
            fflush(stdin);
            printf("\n\tInforme o numero de elementos: ");
            scanf("%i", &nV);

            for (i = 0; i < nV; i++)
            {
                printf("\n\t\t - Elemento %d: ", (i + 1));
                scanf("%d", &array[i]);
            }

            pArray = &array[0];
            break;

        case 2: // Letra B
            if (nV == 0)
            { // confere se o usuario iniciou o array
                printf("\n\tAtencao! Elementos nao informados. (Opcao 1 do menu)\n ");
                break;
            }
            do
            {
                printf("\n\tInforme o numero de arestas: ");
                scanf("%d", &nA);
                if (nA > ((((nV * nV) - nV) / 2)))
                {
                    printf("\n	Invalido! Informe um valor entre 1 e %d\n", (((nV * nV) - nV) / 2));
                }
            } while (nA > ((((nV * nV) - nV) / 2)) || nA < 1); // limite de arestas de um grafo simples

            pMatrizInc = matrizIncidencia(nV, nA, pArray); // funcao para criar a matriz de incidencia

            printf("\n\n\t\tMATRIZ DE INICIDENCIA\n\n\t\t"); // imprimir matriz
            for (i = 0; i < nA; i++)
            {
                printf("|a%d\t", i + 1);
            }
            imprimirMatriz(pMatrizInc, nV, nA, pArray);
            break;

        case 3: // Letra C
            if (nV == 0)
            { // confere se o usuario iniciou o array
                printf("\n\tAtencao! Elementos nao informados. (Opcao 1 do menu)\n ");
                break;
            }
            
            pMatrizAdj = matrizAdjacencia(nV, pArray);
			
            break;

        case 4: // Letra D
            if (nA == 0)
            { // confere se o usuario iniciou a matriz de incidencia
                printf("\n\tAtencao! Matriz de Incidencia nao inicializada. (Opcao 2 do menu)\n ");
                break;
            }
                
            printf("\n\tDigite o vertice: ");
            scanf("%d", &aux);

            for (i = 0; i < nV; i++)
            { // busca o vertice informado no array. Se for encontrado chama a funçao
                if (aux == pArray[i])
                {
                    grauVertice(pMatrizInc, aux, i, nA, pArray);
                }
            }
            break;

        case 5:
            if (nV == 0) {
                printf("\n\tAtencao! Elementos nao informados. (Opcao 1 do menu)\n ");
                break;
            }
            
            vertArestAdj(pMatrizAdj, nV);
            break;
                
        case 6:
            printf("\t____________________________________________\n\n");
            printf("\tDesenvolvido por:\n\n");
            printf("\tGuilherme Henrique   \n");
            printf("\tKaren Moreira   \n");
            printf("\n\n\tCIENCIA DA COMPUTACAO - 02/2022");

            break;

        default:
            printf("\n\t\t  Insira uma opcao valida!");
            break;
        }

    } while (op != 6);
}

int **matrizIncidencia(int nV, int nA, int *pArray)
{  // Letra B                                   
    int vrt1, vrt2, n, m, valido = 1; // sendo n = Linha e M = Coluna

    int **pMtrInc = malloc(nV * sizeof(*pMtrInc)); // alocando memoria
    for (n = 0; n < nV; n++)
    {
        pMtrInc[n] = malloc(nA * sizeof(*pMtrInc[n]));
        for (m = 0; m < nA; m++)
        {
            pMtrInc[n][m] = 0;
        }
    }

    printf("\n\tElementos: "); // imprime os elementos
    for (n = 0; n < nV; n++)
    {
        printf("%d ", pArray[n]);
    }

    printf("\n\n\tDefina as extremidades das arestas aX: {v1,v2}\n");

    for (m = 0; m < nA; m++)
    { // definindo a matriz com base na aresta (coluna)
        printf("\n\t%c a%d : {\n", 26, m + 1);
        do
        { // valida se o v1 existe dentro do array
            fflush(stdin);
            fprintf(stdout, "\t\tv1 = ");
            scanf("%d", &vrt1);
            for (n = 0; n < nV; n++)
            {
                if (vrt1 == pArray[n])
                {
                    valido = 1;
                    pMtrInc[n][m] = pMtrInc[n][m] + 1;
                    break;
                }
                else
                {
                    valido = 0;
                }
            }
            if (valido == 0)
            {
                printf("\n\tVertice invalido. Tente novamente\n\n");
            }
        } while (valido == 0);

        do
        { // valida se o v2 existe dentro do array
            fflush(stdin);
            printf("\t\tv2 = ");
            scanf("%d", &vrt2);
            for (n = 0; n < nV; n++)
            {
                if (vrt2 == vrt1)
                {
                    valido = 0;
                    break;
                }
                else if (vrt2 == pArray[n])
                {
                    valido = 1;
                    pMtrInc[n][m] = pMtrInc[n][m] + 1;
                    printf("\t\t}\n");
                    break;
                }
                else
                {
                    valido = 0;
                }
            }
            if (valido == 0)
            {
                printf("\n\tVertice invalido. Tente novamente\n\n");
            }
        } while (valido == 0);
    }

    return pMtrInc;
}

int **matrizAdjacencia(int nV, int *pArray) {
	// Declara��es:
		// Definindo n:
			int n = nV + 1; 
			
		// Variaveis para o loop For:
			int i, j;
		
		// Variaveis para os vertices conectados:
			int par1, par2;
		
	// Alocando o ponteiro e preenchendo com zero a matriz:
		int **pMtrAdj = malloc (n * sizeof(*pMtrAdj));
		
		for (i=0; i<n; i++) {
	        pMtrAdj[i] = malloc(n * sizeof(*pMtrAdj[i]));
	        for (j=0; j<n; j++) {
	            pMtrAdj[i][j] = 0;
	        }
	    }
	
	// Preenchendo Cabecalho:
		for(i=0; i<1; i++) {
            for(j=1; j<=n; j++) { 
                pMtrAdj[i][j] = *(pArray+(j-1));
            }
        }
        
    // Preenchendo Periodo
    	for(i=1; i<n; i++) {
            for(j=0; j<1; j++) {
                pMtrAdj[i][j] = *(pArray+(i-1));
            }
        }

    // Preenchendo a Matriz de Adjacencia:
    	// Perguntando os pares conectados:
    		int arestas = ((n*n) - n)/2;
			int x = 0;
			char answer;
			
			do{
				fflush(stdin);
				
				printf("\n\tInsira os pares de vertice que possuem arestas entre eles, separando-os por espaco: ");
				scanf("%i %i", &par1, &par2);
				
				x++;	
				
				for(i=0; i<n; i++) {
		            for(j=0; j<n; j++) {
		                if( ((par1 == j) && (par2 == i))|| ((par1 == i) && (par2 == j))) {
		                	pMtrAdj[i][j] = 1;
						}
		            }
		        }
		        
		        fflush(stdin);
		        
				printf("\n\tDesejas inserir as coordenadas de uma arestas? ('s' ou 'n'): ");
				scanf("%c", &answer);
				
				if(answer == 'n') {
					break;
				}
			} while ((answer == 's') || (x == arestas));
	
	// Imprimindo a matriz:		
		printf("\n\n\t========== Matriz de Adjacencia Bidirecional ==========\n\n\t");
		//imprimirMatriz(pMtrAdj, n, n, pArray); M�todo de Impressao diferente!
		
		for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
            	if(i==0 && j==0) {
            		printf("\t %c", ' ');
				}else {
					printf("\t %i ", pMtrAdj[i][j]);
				}
            }
            printf("\n\t");
        }
		
	// Retornando a matriz:
		return pMtrAdj;
}

int **grauVertice(int **pMatriz, int vtc, int n, int nA, int *pArray)
{ // Letra E
    int cont = 0, m;

    for (m = 0; m < nA; m++)
    {
        cont = cont + pMatriz[n][m]; // soma os valores de cada aresta em rela
    }
    printf("\n\t\tGrau do vertice %d = %d", vtc, cont);
}

void vertArestAdj(int **pMtrAdj, int nV){
	// Declaracoes:
		int n = nV + 1;
		int i, j;
	
	// Imprimindo os vertices:
		printf("\n\tOs vertices do grafos sao: v(");
		
		for (i=1; i<n; i++){
			if(i != (n-1)){
				printf("%i, ", i);
			} else {
				printf("%i", i);
			}
		}
		
		printf(")\n\n");
	
	// Imprimindo as ligacoes/extreminadades das arestas:
		printf("\tAs arestas do grafos sao: \n");
		
		for(i=1; i<n; i++) {
            for(j=1; j<n; j++) {
                if( pMtrAdj[i][j] == 1) {
                	printf("\te(%i,%i)\n", i, j);
				}
            }
        }
}

void imprimirMatriz(int **pMatriz, int n, int m, int *pArray)
{
    int x, y;
    for (x = 0; x < n; x++)
    {
        printf("\n\t%d\t", pArray[x]);
        for (y = 0; y < m; y++)
        {
            printf("|%d\t", pMatriz[x][y]);
        }
    }
}
