#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

int *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
	int retorno = 0;
	if(posicao < 1 || posicao > 10){
    	retorno = POSICAO_INVALIDA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1] != NULL){
		retorno = JA_TEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}
	if(tamanho < 1){
		retorno = TAMANHO_INVALIDO;
		return retorno;
	}
    vetorPrincipal[posicao-1] = (int*) malloc((tamanho + 2) * sizeof(int));
    if(vetorPrincipal[posicao-1] == NULL){
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }
    else{
        vetorPrincipal[posicao-1][0] = tamanho; 
        vetorPrincipal[posicao-1][1] = 0;       
        retorno = SUCESSO;
        return retorno;
    }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  int retorno = 0;
    
	if(posicao < 1 || posicao > 10){
		retorno = POSICAO_INVALIDA;
	}      
    else
    {
		if(vetorPrincipal[posicao-1] != NULL){	
        if (vetorPrincipal[posicao-1][1] < vetorPrincipal[posicao-1][0]){
				  int p = vetorPrincipal[posicao-1][1] + 2;			    
				  vetorPrincipal[posicao-1][p] = valor;
				  vetorPrincipal[posicao-1][1]++;  
				  retorno = SUCESSO;
        }
        else
        {
          retorno = SEM_ESPACO;
        }
    	}
    else	
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }   	
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
	int retorno = 0;
	if(posicao < 1 || posicao > 10){
    	retorno = POSICAO_INVALIDA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1] == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1][0] > 0 && vetorPrincipal[posicao-1][1] == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
    	return retorno;
	}
	else{
		vetorPrincipal[posicao-1][1]--;
		retorno = SUCESSO;
    	return retorno;
	}

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
	int retorno = 0;
	if(posicao < 1 || posicao > 10){
    	retorno = POSICAO_INVALIDA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1] == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1][0] > 0 && vetorPrincipal[posicao-1][1] == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1][0] > 0 && vetorPrincipal[posicao-1][1] > 0){
		for(int i = 2; i < vetorPrincipal[posicao-1][1] + 2; i++){
			if(valor == vetorPrincipal[posicao-1][i])
			{
				for(int j = i; j < vetorPrincipal[posicao-1][1] + 1; j++)
				{
					vetorPrincipal[posicao-1][j] = vetorPrincipal[posicao-1][j+1];
				}
				vetorPrincipal[posicao-1][1]--;
				retorno = SUCESSO;
    			return retorno;
			}
		}
		retorno = NUMERO_INEXISTENTE;
    	return retorno;	
	}
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
	if(posicao < 1 || posicao > 10){
    	retorno = POSICAO_INVALIDA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1] == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;
    	return retorno;
	}
	else{
		for (int i = 0; i < vetorPrincipal[posicao-1][1]; i++){
			vetorAux[i] = vetorPrincipal[posicao-1][i+2];
		}
		retorno = SUCESSO;
    	return retorno;		
	}
}

void insertionSort(int arr[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = arr[i]; 
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave; 
    }
}
/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
	int retorno = 0;
	if(posicao < 1 || posicao > 10){
    	retorno = POSICAO_INVALIDA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1] == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;
    	return retorno;
	}
	else{
		for (int i = 0; i < vetorPrincipal[posicao-1][1]; i++){
			vetorAux[i] = vetorPrincipal[posicao-1][i+2];
		}
		int n = vetorPrincipal[posicao-1][1];
		insertionSort(vetorAux, n);
		retorno = SUCESSO;
    	return retorno;		
  }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
	int retorno = 0;
	int k = 0;    
	for(int j = 0; j < 10; j++){
		if(vetorPrincipal[j] != NULL){
			for (int i = 0; i < vetorPrincipal[j][1]; i++){
				vetorAux[k] = vetorPrincipal[j][i+2];
				k++;
			}

		}
	}	
	if(k == 0){
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    	return retorno;	
	}
	retorno = SUCESSO;
    return retorno;	
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
	int retorno = 0;
	int k = 0;    
	for(int j = 0; j < 10; j++){
		if(vetorPrincipal[j] != NULL){
			for (int i = 0; i < vetorPrincipal[j][1]; i++){
				vetorAux[k] = vetorPrincipal[j][i+2];
				k++;
			}

		}
	}	
	if(k == 0){
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    	return retorno;	
	}
	insertionSort(vetorAux, k);
	retorno = SUCESSO;
    return retorno;	
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    if(posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if(vetorPrincipal[posicao-1] == NULL){
          retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    int tamanhonovo = vetorPrincipal[posicao-1][0] + novoTamanho;
    if(tamanhonovo < 1){
          retorno = NOVO_TAMANHO_INVALIDO;
      return retorno;       
    }

    int *novaEstrutura = realloc(vetorPrincipal[posicao-1], (tamanhonovo + 2) * sizeof(int));
    if(novaEstrutura == NULL){
      retorno = SEM_ESPACO_DE_MEMORIA;
      return retorno;
    }
    vetorPrincipal[posicao-1] = novaEstrutura;
    vetorPrincipal[posicao-1][0] = tamanhonovo;
    if(vetorPrincipal[posicao-1][1] > tamanhonovo){
          vetorPrincipal[posicao-1][1] = tamanhonovo;
    }       
    retorno = SUCESSO;
    return retorno; 
}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
	int retorno = 0;
	
	if(posicao < 1 || posicao > 10){
    	retorno = POSICAO_INVALIDA;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1] == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;
    	return retorno;
	}
	else if(vetorPrincipal[posicao-1][0] > 0 && vetorPrincipal[posicao-1][1] == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
    	return retorno;
	}
	int qtdElementos = vetorPrincipal[posicao-1][1];
	return qtdElementos;
}


No* criarLista() {
    No* cabecote = (No*) malloc(sizeof(No));
    
    if (cabecote != NULL) {
        cabecote->prox = NULL;
    }
    return cabecote;
}

void inserirFinal(No* lista, int num) {
    No* aux = lista; 
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->conteudo = num;
        novo->prox = NULL;
        aux->prox = novo;
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
	int cont = 0;
	for(int j = 0; j < TAM; j++){
		if(vetorPrincipal[j] != NULL && vetorPrincipal[j][1] > 0){
				cont = 1;
				break;
		}
	}
	if (!cont) {
      return NULL; 
    }
	
	No *minhaLista = criarLista();
	
	for(int j = 0; j < 10; j++){
        if(vetorPrincipal[j] != NULL){
            for (int i = 0; i < vetorPrincipal[j][1]; i++){
                inserirFinal(minhaLista, vetorPrincipal[j][i+2]);
            }
        }
    }
	
    return minhaLista;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
	if (inicio == NULL) {
        return;
	}
	
    No *atual = inicio->prox;
    int k = 0;

    while(atual != NULL)
    {
        vetorAux[k] = atual->conteudo; 
        atual = atual->prox;
        k++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (inicio == NULL || *inicio == NULL) {
        return;
    }
    No *atual = *inicio; 
    No *aux;
    while (atual != NULL) {
        aux = atual->prox;
        free(atual);      
        atual = aux;      
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  	for(int i = 0; i < TAM; i++){
        vetorPrincipal[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
      for(int i = 0; i < TAM; i++) 
    {
        if(vetorPrincipal[i] != NULL)
        {
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}
