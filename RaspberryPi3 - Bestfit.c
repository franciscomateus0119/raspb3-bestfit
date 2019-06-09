#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * @(#)Bestfit.c   1.00 01/10/2018
 * Author: Francisco Mateus Rocha Filho
 * Federal University of Ceará
 * ---------------------------------------------------
 */


//..........................................................................
//..........................................................................


void main()
{
	//--------------------------------------------------------------------------------
	//--Seção das Variáveis
	//--------------------------------------------------------------------------------

	//
	//Variáveis para definir o tamanho mínimo e máximo dos blocos a serem encaixados
    int tamanhoblocomin; /** Tamanho mínimo dos blocos*/
    int tamanhoblocomax; /** Tamanho máximo dos blocos*/

	//Variáveis para definir o tamanho mínimo e máximo dos processos
    int tamanhoprocessomin; /** Tamanho mínimo dos processos */
    int tamanhoprocessomax; /** Tamanho máximo dos processos*/

	//Variáveis para uso em laços como for e while
    int i, j, a, b, z=1500;

	//Variáveis para conta o número de processos encaixados e não encaixados e
	//de blocos não totalmente preenchidos
	int contador=0; /** número de processos encaixados */
	int naoalocadop=0; /** número de processos não encaixados*/
	int naoalocadob=0; /** número de blocos não totalmente preenchidos*/

	//Variáveis auxiliares para armazenamento de valores temporários
	int y=0, aux=0, c=0, temp;
	int bloco;
	int processo;

	//Variáveis para armazenamento dos valores de tamanho dos blocos e dos processos
    int vetorbloco[1500];
    int vetorprocesso[1500];

	//Variável para verificação de condição da função while
    int x=1;

	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Atribuição dos valores randômicos
	//--------------------------------------------------------------------------------

	printf("\t\t\tEsquema de Gerenciamento de Memoria - Best Fit\n\n\n");

	//--------------------------------------------------------------------------------

    //Determinação, a partir de user input, do tamanho mínimo dos blocos
	printf("\nTamanho Minimo dos Blocos: ");
	scanf("%d",&tamanhoblocomin); /** Leitura do user input para o tamanho mínimo */

	//Determinação, a partir de user input, do tamanho mínimo dos processos
	printf("\nTamanho Maximo dos Blocos: ");
	scanf("%d",&tamanhoblocomax); /** Leitura do user input para o tamanho máximo */


    //Atribuição de Tamanhos Randômicos aos Blocos
	srand((unsigned)time(NULL)); /** Função para ativar a geração de valores aleatórios */

	printf("\n");

	for(i=0;i<=1500;i++){ /** Laço for para percorrer os 1500 espaços livres do vetor vetorbloco[1500] */
	    if(i>0){ /** A partir da segunda repetição do laço ou repetições posteriores */
            if(bloco>=tamanhoblocomin){/** Se o valor randômicamente gerado for igual ou maior que o mínimo exigido para blocos*/
                y=i-1;
                vetorbloco[y] = bloco; /** Colocar, na posição anterior(i-1), o valor randômico*/
            }else{
                i--; /**Se o valor randômicante gerado foi menor que o mínimo estipulado, permanecer em vetorbloco[i] até que
					    um valor que satisfaça os requisitos seja gerado e armazenado */
            }//else

	    }//if

	    bloco = rand()%(tamanhoblocomax) +1; /** O valor gerado randômicamente irá variar de 1 até o valor máximo exigido para blocos */

	}//for


    // Mostrando os tamanhos (para blocos) gerados no terminal
	printf("\nTamanhos dos Blocos:\n");
    for(i=0;i<1500;i++)//
        printf("%d ",vetorbloco[i]); /** Percorre todo o vetor e mostra cada um dos 1500 valores randomicamente gerados */


    // Determinação, a partir de user input, do tamanho mínimo dos processos
	printf("\n\nTamanho Minimo dos Processos: ");
	scanf("%d",&tamanhoprocessomin); /** Leitura do user input para o tamanho mínimo */

	// Determinação, a partir de user input, do tamanho máximo dos processos
	printf("\nTamanho Maximo dos Processos: ");
	scanf("%d",&tamanhoprocessomax); /** Leitura do user input para o tamanho máximo */


    //Atribuição de Tamanhos Randômicos entre os Processos
	for(i=0;i<=1500;i++){ /** Laço for para percorrer os 1500 espaços livres do vetor vetorprocesso[1500] */
	    if(i>0){ /** A partir da segunda repetição do laço ou repetições posteriores */
            if(processo>=tamanhoprocessomin){ /** Se o valor randômicamente gerado for igual ou maior que o mínimo exigido para processos */
                y=i-1;
                vetorprocesso[y] = processo; /** Colocar, na posição anterior(i-1), o valor randômico */
            }else{
                i--; /** Se o valor randômicante gerado foi menor que o mínimo estipulado, permanecer em vetorprocesso[i] até que
					     um valor que satisfaça os requisitos seja gerado e armazenado */
            }//else

	    }//if

	    processo = rand()%(tamanhoprocessomax) +1; /** O valor gerado randômicamente irá variar de 1 até o valor máximo exigido para processos */

	}//for

	//Mostrando os tamanhos (para processos) gerados no terminal
	printf("\n\nTamanhos dos Processos:\n");
    for(i=0;i<1500;i++)
        printf("%d ",vetorprocesso[i]); /** Percorre todo o vetor e mostra cada um dos 1500 valores randomicamente gerados */

	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Organização por BubbleSort
	//--------------------------------------------------------------------------------

	/**
	 *O método de organização BubbleSort consiste em organizar algo (neste caso, um vetor) em ordem crescente ou crescente.
	 *Para tal, ele faz comparações do espaço atual do vetor (Ex: vetor[x]) e compara com o próximo espaço do vetor (vetor[x+1].
	 *Se ele for maior ou menor (depende se quer organiza crecente ou decrescentemente), ele realizará a troca do valor presente
	 *nesses espaços.
	 */

    //BubbleSort dos Blocos

    //Organização dos valores do vetor vetorbloco[1500] em decrescente.
    for(i=0;i<1500;i++){
        for(j=i+1;j<1500;j++){
            if(vetorbloco[j]>vetorbloco[i]){ /** se o valor do espaço atual for menor que o do próximo espaço*/
                aux = vetorbloco[j]; /** Armazena o valor presente no próximo espaço*/
                vetorbloco[j] = vetorbloco[i]; /** O próximo espaço recebe o valor presente no espaço atual*/
                vetorbloco[i] = aux; /** O espaço atual recebe o valor armazenado*/
            }//if

        }//for

    }//for

    //Mostrando os valores do vetor re-organizados
    printf("\n\nTamanhos dos Blocos em Decrescente:\n");
    for(i=0;i<1500;i++)
        printf("%d ",vetorbloco[i]);


	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Aplicação do BestFit
	//--------------------------------------------------------------------------------

	/**
	 *O algoritmo bestfit se resume a encaixar processos (ou qualquer outra coisa que você queira encaixar)
	 *em blocos, no qual o tamanho do bloco deve ser igual ou o mais próximo possível ao do processo que se
	 *deseja encaixar, visando o menor espaço restante possível.
	 */


    for(j=0;j<1500;j++){ /** "j" se refere a ordem que os processos vão sendo armazenados. Assim, j=0 é o primeiro
						 processo a ser armazenado, enquanto 1500 é o ultimo. */

        //BubbleSort - Realizado toda vez que um processo for encaixado em um bloco
        for(a=0;a<1500;a++){
            for(b=a+1;b<1500;b++){
                if(vetorbloco[b]>vetorbloco[a]){
                    aux = vetorbloco[b];
                    vetorbloco[b] = vetorbloco[a];
                    vetorbloco[a] = aux;
                }//if
            }//for
        }//for

        x=1; /** "x" é utilizado para verificar se o processo realmente procurou por um bloco cujo tamanho seja igual
			ou similar ao seu, tenha tal processo sido encaixado ou não.*/

		//Comparação do tamanho do processo atual com o dos blocos
        while(x!=0){
            for(i=1499;i>=0;i--){ /** Percorre todos os blocos */
                if(vetorprocesso[j]<=vetorbloco[i] && vetorprocesso[j]!=0){ /** Se o tamanho do processo for menor que o do bloco atual
																			    e não tenha sido encaixado ainda */
                    bloco = vetorbloco[i];
                    processo = vetorprocesso[j];
                    temp = vetorbloco[i] - vetorprocesso[j]; /** Cria um fragmento a partir da diferença entre o tamanho do bloco e o do processo. */
                    contador++; /** Numero do encaixe realizado */
                    printf("\n%d - T_Processo = %d\tT_Bloco = %d\t Fragmento = %d",contador,vetorprocesso[j],vetorbloco[i],temp);
                    vetorbloco[i] = temp; /** Atualiza o tamanho do bloco com o fragmento gerado */
                    vetorprocesso[j]=0; /** O processo foi totalmente encaixado no bloco, sendo atualizado com 0 para considera-lo encaixado. */
                }//if

            }//for

            i++;

            //Verificação do tamanho do processo
            if(vetorprocesso[j]>vetorbloco[i]){ /** Se o tamanho do processo for maior que tamanho máximo dos blocos */
                naoalocadop++; /** Aumenta-se o número de processos não alocados */
                printf("\n%d.N - T_Processo = %d nao alocado - maior espaco = %d",naoalocadop, vetorprocesso[j],vetorbloco[i]);

            }//if

            x=0; /** Processo terminou de procurar por um espaço para ser encaixado. Ir para próximo processo. */

		}//while

    }//for


	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Demonstração dos Resultados
	//--------------------------------------------------------------------------------

    //Mostra todos os processos não encaixados
    printf("\n\nTamanho dos Processos Nao Alocados:\n");
    for(i=0;i<1500;i++){
        if(vetorprocesso[i]!=0){ /** Se o processo não foi encaixado, então seu possui um valor diferente de 0. */
            printf("%d ",vetorprocesso[i]);

        }//if

    }//for

    //Mostra todos os Blocos que não foram totalmente preenchidos
    printf("\n\nTamanho dos Blocos Restantes:\n");
    for(i=0;i<1500;i++){
        if(vetorbloco[i]!=0){ /** Blocos com fragmentos são blocos que não foram totalmente preenchidos por processos. */
            printf("%d ",vetorbloco[i]);
            naoalocadob++;
        }//if

    }//for


    //Mostra o numero de processos encaixados, de não encaixados e de blocos não totalmente preenchidos
    printf("\n\nNumero de Processos Alocados = %d",contador);
    printf("\nNumero de Processos Nao Alocados = %d",naoalocadop);
    printf("\nNumero de Blocos Nao Totalmente Preenchidos = %d",naoalocadob);


}// main
