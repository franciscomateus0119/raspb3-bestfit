#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * @(#)Bestfit.c   1.00 01/10/2018
 * Author: Francisco Mateus Rocha Filho
 * Federal University of Cear�
 * ---------------------------------------------------
 */


//..........................................................................
//..........................................................................


void main()
{
	//--------------------------------------------------------------------------------
	//--Se��o das Vari�veis
	//--------------------------------------------------------------------------------

	//
	//Vari�veis para definir o tamanho m�nimo e m�ximo dos blocos a serem encaixados
    int tamanhoblocomin; /** Tamanho m�nimo dos blocos*/
    int tamanhoblocomax; /** Tamanho m�ximo dos blocos*/

	//Vari�veis para definir o tamanho m�nimo e m�ximo dos processos
    int tamanhoprocessomin; /** Tamanho m�nimo dos processos */
    int tamanhoprocessomax; /** Tamanho m�ximo dos processos*/

	//Vari�veis para uso em la�os como for e while
    int i, j, a, b, z=1500;

	//Vari�veis para conta o n�mero de processos encaixados e n�o encaixados e
	//de blocos n�o totalmente preenchidos
	int contador=0; /** n�mero de processos encaixados */
	int naoalocadop=0; /** n�mero de processos n�o encaixados*/
	int naoalocadob=0; /** n�mero de blocos n�o totalmente preenchidos*/

	//Vari�veis auxiliares para armazenamento de valores tempor�rios
	int y=0, aux=0, c=0, temp;
	int bloco;
	int processo;

	//Vari�veis para armazenamento dos valores de tamanho dos blocos e dos processos
    int vetorbloco[1500];
    int vetorprocesso[1500];

	//Vari�vel para verifica��o de condi��o da fun��o while
    int x=1;

	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Atribui��o dos valores rand�micos
	//--------------------------------------------------------------------------------

	printf("\t\t\tEsquema de Gerenciamento de Memoria - Best Fit\n\n\n");

	//--------------------------------------------------------------------------------

    //Determina��o, a partir de user input, do tamanho m�nimo dos blocos
	printf("\nTamanho Minimo dos Blocos: ");
	scanf("%d",&tamanhoblocomin); /** Leitura do user input para o tamanho m�nimo */

	//Determina��o, a partir de user input, do tamanho m�nimo dos processos
	printf("\nTamanho Maximo dos Blocos: ");
	scanf("%d",&tamanhoblocomax); /** Leitura do user input para o tamanho m�ximo */


    //Atribui��o de Tamanhos Rand�micos aos Blocos
	srand((unsigned)time(NULL)); /** Fun��o para ativar a gera��o de valores aleat�rios */

	printf("\n");

	for(i=0;i<=1500;i++){ /** La�o for para percorrer os 1500 espa�os livres do vetor vetorbloco[1500] */
	    if(i>0){ /** A partir da segunda repeti��o do la�o ou repeti��es posteriores */
            if(bloco>=tamanhoblocomin){/** Se o valor rand�micamente gerado for igual ou maior que o m�nimo exigido para blocos*/
                y=i-1;
                vetorbloco[y] = bloco; /** Colocar, na posi��o anterior(i-1), o valor rand�mico*/
            }else{
                i--; /**Se o valor rand�micante gerado foi menor que o m�nimo estipulado, permanecer em vetorbloco[i] at� que
					    um valor que satisfa�a os requisitos seja gerado e armazenado */
            }//else

	    }//if

	    bloco = rand()%(tamanhoblocomax) +1; /** O valor gerado rand�micamente ir� variar de 1 at� o valor m�ximo exigido para blocos */

	}//for


    // Mostrando os tamanhos (para blocos) gerados no terminal
	printf("\nTamanhos dos Blocos:\n");
    for(i=0;i<1500;i++)//
        printf("%d ",vetorbloco[i]); /** Percorre todo o vetor e mostra cada um dos 1500 valores randomicamente gerados */


    // Determina��o, a partir de user input, do tamanho m�nimo dos processos
	printf("\n\nTamanho Minimo dos Processos: ");
	scanf("%d",&tamanhoprocessomin); /** Leitura do user input para o tamanho m�nimo */

	// Determina��o, a partir de user input, do tamanho m�ximo dos processos
	printf("\nTamanho Maximo dos Processos: ");
	scanf("%d",&tamanhoprocessomax); /** Leitura do user input para o tamanho m�ximo */


    //Atribui��o de Tamanhos Rand�micos entre os Processos
	for(i=0;i<=1500;i++){ /** La�o for para percorrer os 1500 espa�os livres do vetor vetorprocesso[1500] */
	    if(i>0){ /** A partir da segunda repeti��o do la�o ou repeti��es posteriores */
            if(processo>=tamanhoprocessomin){ /** Se o valor rand�micamente gerado for igual ou maior que o m�nimo exigido para processos */
                y=i-1;
                vetorprocesso[y] = processo; /** Colocar, na posi��o anterior(i-1), o valor rand�mico */
            }else{
                i--; /** Se o valor rand�micante gerado foi menor que o m�nimo estipulado, permanecer em vetorprocesso[i] at� que
					     um valor que satisfa�a os requisitos seja gerado e armazenado */
            }//else

	    }//if

	    processo = rand()%(tamanhoprocessomax) +1; /** O valor gerado rand�micamente ir� variar de 1 at� o valor m�ximo exigido para processos */

	}//for

	//Mostrando os tamanhos (para processos) gerados no terminal
	printf("\n\nTamanhos dos Processos:\n");
    for(i=0;i<1500;i++)
        printf("%d ",vetorprocesso[i]); /** Percorre todo o vetor e mostra cada um dos 1500 valores randomicamente gerados */

	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Organiza��o por BubbleSort
	//--------------------------------------------------------------------------------

	/**
	 *O m�todo de organiza��o BubbleSort consiste em organizar algo (neste caso, um vetor) em ordem crescente ou crescente.
	 *Para tal, ele faz compara��es do espa�o atual do vetor (Ex: vetor[x]) e compara com o pr�ximo espa�o do vetor (vetor[x+1].
	 *Se ele for maior ou menor (depende se quer organiza crecente ou decrescentemente), ele realizar� a troca do valor presente
	 *nesses espa�os.
	 */

    //BubbleSort dos Blocos

    //Organiza��o dos valores do vetor vetorbloco[1500] em decrescente.
    for(i=0;i<1500;i++){
        for(j=i+1;j<1500;j++){
            if(vetorbloco[j]>vetorbloco[i]){ /** se o valor do espa�o atual for menor que o do pr�ximo espa�o*/
                aux = vetorbloco[j]; /** Armazena o valor presente no pr�ximo espa�o*/
                vetorbloco[j] = vetorbloco[i]; /** O pr�ximo espa�o recebe o valor presente no espa�o atual*/
                vetorbloco[i] = aux; /** O espa�o atual recebe o valor armazenado*/
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
	//--Aplica��o do BestFit
	//--------------------------------------------------------------------------------

	/**
	 *O algoritmo bestfit se resume a encaixar processos (ou qualquer outra coisa que voc� queira encaixar)
	 *em blocos, no qual o tamanho do bloco deve ser igual ou o mais pr�ximo poss�vel ao do processo que se
	 *deseja encaixar, visando o menor espa�o restante poss�vel.
	 */


    for(j=0;j<1500;j++){ /** "j" se refere a ordem que os processos v�o sendo armazenados. Assim, j=0 � o primeiro
						 processo a ser armazenado, enquanto 1500 � o ultimo. */

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

        x=1; /** "x" � utilizado para verificar se o processo realmente procurou por um bloco cujo tamanho seja igual
			ou similar ao seu, tenha tal processo sido encaixado ou n�o.*/

		//Compara��o do tamanho do processo atual com o dos blocos
        while(x!=0){
            for(i=1499;i>=0;i--){ /** Percorre todos os blocos */
                if(vetorprocesso[j]<=vetorbloco[i] && vetorprocesso[j]!=0){ /** Se o tamanho do processo for menor que o do bloco atual
																			    e n�o tenha sido encaixado ainda */
                    bloco = vetorbloco[i];
                    processo = vetorprocesso[j];
                    temp = vetorbloco[i] - vetorprocesso[j]; /** Cria um fragmento a partir da diferen�a entre o tamanho do bloco e o do processo. */
                    contador++; /** Numero do encaixe realizado */
                    printf("\n%d - T_Processo = %d\tT_Bloco = %d\t Fragmento = %d",contador,vetorprocesso[j],vetorbloco[i],temp);
                    vetorbloco[i] = temp; /** Atualiza o tamanho do bloco com o fragmento gerado */
                    vetorprocesso[j]=0; /** O processo foi totalmente encaixado no bloco, sendo atualizado com 0 para considera-lo encaixado. */
                }//if

            }//for

            i++;

            //Verifica��o do tamanho do processo
            if(vetorprocesso[j]>vetorbloco[i]){ /** Se o tamanho do processo for maior que tamanho m�ximo dos blocos */
                naoalocadop++; /** Aumenta-se o n�mero de processos n�o alocados */
                printf("\n%d.N - T_Processo = %d nao alocado - maior espaco = %d",naoalocadop, vetorprocesso[j],vetorbloco[i]);

            }//if

            x=0; /** Processo terminou de procurar por um espa�o para ser encaixado. Ir para pr�ximo processo. */

		}//while

    }//for


	//--------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------



	//--------------------------------------------------------------------------------
	//--Demonstra��o dos Resultados
	//--------------------------------------------------------------------------------

    //Mostra todos os processos n�o encaixados
    printf("\n\nTamanho dos Processos Nao Alocados:\n");
    for(i=0;i<1500;i++){
        if(vetorprocesso[i]!=0){ /** Se o processo n�o foi encaixado, ent�o seu possui um valor diferente de 0. */
            printf("%d ",vetorprocesso[i]);

        }//if

    }//for

    //Mostra todos os Blocos que n�o foram totalmente preenchidos
    printf("\n\nTamanho dos Blocos Restantes:\n");
    for(i=0;i<1500;i++){
        if(vetorbloco[i]!=0){ /** Blocos com fragmentos s�o blocos que n�o foram totalmente preenchidos por processos. */
            printf("%d ",vetorbloco[i]);
            naoalocadob++;
        }//if

    }//for


    //Mostra o numero de processos encaixados, de n�o encaixados e de blocos n�o totalmente preenchidos
    printf("\n\nNumero de Processos Alocados = %d",contador);
    printf("\nNumero de Processos Nao Alocados = %d",naoalocadop);
    printf("\nNumero de Blocos Nao Totalmente Preenchidos = %d",naoalocadob);


}// main
