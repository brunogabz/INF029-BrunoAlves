#include <stdio.h>
#define MAX 100


typedef struct
{
	char cor[MAX];
    int chassi;
    int ano;
}Carro;

void menu();
void limpar_buffer();

int main()
{	
	int cont = 0; 
	int sair = 0;
   	Carro carro[MAX];
	while(sair == 0)
	{
		menu();
		int opcao = -1;
		scanf("%d", &opcao);
		limpar_buffer();	
		switch(opcao)
		{
			case 0:
			{	
				printf("\nSaindo...\n");
				sair = 1;
				break;
			}
			case 1:
			{
				if(cont < MAX)
				{
					printf("\nCadastrando...\n");
					printf("Qual o chassi do carro? ");
					scanf("%d", &carro[cont].chassi);
					printf("Qual o ano do carro? ");
					scanf("%d", &carro[cont].ano);
				 	limpar_buffer();
                	printf("Qual a cor do carro? ");
                	fgets(carro[cont].cor, MAX, stdin);
                	int i = 0;
                	while (carro[cont].cor[i] != '\0') 
					{
                    	if (carro[cont].cor[i] == '\n') 
						{
                        	carro[cont].cor[i] = '\0';
                        break;
                    	}
                    i++;
                	}
					printf("\n");
					cont++;
					break;
				}
				else 
				{
                    printf("Limite de carros atingido!\n");
                }
                break;
			}	
			case 2: 
			{
                printf("\nListando...\n");
                for (int i = 0; i < cont; i++)
				{
                	printf("Carro %d - Chassi: %d - Ano: %d - Cor: %s \n", i+1, carro[i].chassi, carro[i].ano, carro[i].cor);
                }
                printf("\n");
                break;
            }
            case 3: 
			{
            	printf("Atualizando...\n");
            	for (int i = 0; i < cont; i++)
				{
                	printf("Carro %d - Chassi: %d - Ano: %d - Cor: %s \n", i+1, carro[i].chassi, carro[i].ano, carro[i].cor);
                }
                printf("\n");
                printf("Digite o número do carro que vc quer atualizar: \n");
                int num;
                scanf("%d", &num);
				if (num >= 1 && num <= cont)
				{
                	printf("Digite o chassi: ");
                	scanf("%d", &carro[num - 1].chassi);
                	printf("Digite o ano: ");
                	scanf("%d", &carro[num - 1].ano);
                	limpar_buffer();
                	printf("Digite a cor: ");
                	fgets(carro[num - 1].cor, MAX, stdin);
                	int i = 0;
                	while (carro[num-1].cor[i] != '\0') 
					{
                    	if (carro[num-1].cor[i] == '\n') 
						{
                        	carro[num-1].cor[i] = '\0';
                        break;
                    	}
                    i++;
                	}
            	}
				else 
				{
                    printf("Número inválido\n");
                }
                break;
            }
            case 4: 
			{
				printf("Excluindo...\n");
            	for (int i = 0; i < cont; i++)
				{
                	printf("Carro %d - Chassi: %d - Ano: %d - Cor: %s \n", i+1, carro[i].chassi, carro[i].ano, carro[i].cor);
                }
                printf("\n");
                printf("Qual carro deseja excluir?\n");
                int excluido;
                scanf("%d", &excluido);
                if (excluido >= 1 && excluido <= cont)
				{
                	for (int e = excluido-1;e<cont-1;e++)
               		{
                		carro[e] = carro[e+1];
					}
					cont--;
					printf("Excluido!\n");
				}
				else 
				{
                    printf("Número inválido\n");
                }
				break;
            }
		}
		
	}
}

void menu()
{
	printf("O que deseja fazer:\n");
	printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
    printf("\n");
}

void limpar_buffer()
{
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}




