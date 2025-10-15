#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define MAX_DISC 10

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char matricula[MAX];
    char nome[MAX];
    char sexo;
    Data data;
    char cpf[MAX];
} Pessoa;

typedef struct
{
	char nome[MAX];
	char codigo[MAX];
	int semestre;
	Pessoa professor;
	Pessoa aluno[MAX];	
	int qtdAlunosMatriculados;
} Disciplina;

void main_menu();
void menu();
void limpar_buffer();
void validacao_cpf(Pessoa pessoa[], int contador);
void validacao_matricula(Pessoa pessoa[], int contador);
void validacao_nome(Pessoa pessoa[], int contador);
void validacao_sexo(Pessoa pessoa[], int contador);
void validacao_data(Pessoa pessoa[], int contador);
void cadastro_pessoa(Pessoa pessoa[], int contador);
void listar_alunos(Pessoa aluno[], int qtdAlunos);
void listar_professores(Pessoa professor[], int qtdProfessores);
int excluir_professor(Pessoa professor[], int qtdProfessores);
int excluir_aluno(Pessoa aluno[], int qtdAlunos);
void menu_listas();
int atualizar_aluno(Pessoa aluno[], int qtdAlunos);
int atualizar_professor(Pessoa professor[], int qtdProfessores);
void lista_alunos_alfabetica(Pessoa aluno[], int qtdAlunos);
void lista_professores_alfabetica(Pessoa professor[], int qtdProfessores);
void lista_professores_sexo(Pessoa professor[], int qtdProfessores);
void lista_alunos_sexo(Pessoa aluno[], int qtdAlunos);
void lista_por_busca(Pessoa aluno[], int qtdAlunos, Pessoa professor[], int qtdProfessores);
void aniversariantes_mes(Pessoa aluno[], int qtdAlunos, Pessoa professor[], int qtdProfessores);
void lista_professores_nascimento(Pessoa professor[], int qtdProfessores);
void lista_alunos_nascimento(Pessoa aluno[], int qtdAlunos);
void cadastro_disciplina(Disciplina disciplina[], int qtdDisciplinas, Pessoa professor[], int qtdProfessores, Pessoa aluno[], int qtdAlunos);
void validacao_nome_disciplina(Disciplina disciplina[], int qtdDisciplinas);
void validacao_codigo_disciplina(Disciplina disciplina[], int qtdDisciplinas);
void validacao_semestre(Disciplina disciplina[], int qtdDisciplinas);
void validacao_professor(Disciplina disciplina[], Pessoa professor[], int qtdDisciplinas, int qtdProfessores);
void matricular_aluno(Disciplina disciplina[], Pessoa aluno[], int qtdDisciplinas, int qtdAlunos);
void listar_disciplinas(Disciplina disciplina[], int qtdDisciplinas);
void listar_disciplina_com_alunos(Disciplina disciplina[], int qtdDisciplinas);
int atualizar_disciplina(Disciplina disciplina[], int qtdDisciplinas, Pessoa professor[], int qtdProfessores, Pessoa aluno[], int qtdAlunos);
int excluir_disciplina(Disciplina disciplina[], int qtdDisciplinas);
void excluir_aluno_disciplina(Disciplina disciplina[], int qtdDisciplinas);
void disciplina_40_vagas(Disciplina disciplina[], int qtdDisciplinas);
void alunos_menos_de_3_disciplinas(Disciplina disciplina[], Pessoa aluno[], int qtdDisciplinas, int qtdAlunos);

int main()
{	
	Disciplina disciplina[MAX_DISC];
	Pessoa aluno[MAX];
	Pessoa professor[MAX];
	int qtdAlunos = 0;
	int qtdProfessores = 0;
	int qtdDisciplinas = 0;
	int sair = 0;
	while(sair == 0)
	{
		main_menu();	
		int opcao_main = -1;
		scanf("%d", &opcao_main);
		limpar_buffer();
		switch(opcao_main)
		{
			case 0:
			{	
				printf("\nSaindo...\n");
				sair = 1;
				break;
			}
			case 1:
			{
				menu();
				int opcao_menu = -1;
				scanf("%d", &opcao_menu);
				limpar_buffer();
				switch(opcao_menu)
				{
					case 0:
					{	
						printf("\nSaindo...\n");
						break;
					}
					case 1:
					{
						printf("\nCadastrando...\n");
						cadastro_pessoa(aluno,qtdAlunos);
						qtdAlunos++;
						break;
					}
					case 2:
					{
						printf("\nAtualizando...\n");
						atualizar_aluno(aluno, qtdAlunos);
						break;
					}
					case 3:
					{
						if(excluir_aluno(aluno, qtdAlunos) == 1)
						{
							qtdAlunos--;
						}
						break;
					}	
					default:
					{
						printf("OPCAO INVALIDA!");
						break;
					}
				}
				break;
			}
			case 2:
			{
				menu();
				int opcao_menu = -1;
				scanf("%d", &opcao_menu);
				limpar_buffer();
				switch(opcao_menu)
				{
					case 0:
					{	
						printf("\nSaindo...\n");
						break;
					}
					case 1:
					{
						printf("\nCadastrando...\n");
						cadastro_pessoa(professor, qtdProfessores);
						qtdProfessores++;
						break;
					}
					case 2:
					{
						printf("\nAtualizando...\n");
						atualizar_professor(professor, qtdProfessores);
						break;
					}
					case 3:
					{
						if(excluir_professor(professor, qtdProfessores) == 1)
						{						
							qtdProfessores--;
						}
						break;
					}	
					default:
					{
						printf("OPCAO INVALIDA!");
						break;
					}	
				}
				break;	
			}
			case 3:
			{
				menu();
				int opcao_menu = -1;
				scanf("%d", &opcao_menu);
				limpar_buffer();
				switch(opcao_menu)
				{
					case 0:
					{	
						printf("\nSaindo...\n");
						break;
					}
					case 1:
					{
						printf("\nCadastrando...\n");
						cadastro_disciplina(disciplina, qtdDisciplinas, professor, qtdProfessores, aluno, qtdAlunos);
						qtdDisciplinas++;
						break;
					}
					case 2:
					{
						printf("\nAtualizando...\n");
						atualizar_disciplina(disciplina, qtdDisciplinas, professor, qtdProfessores, aluno, qtdAlunos);
						break;
					}
					case 3:
					{
						int excluir;
						printf("O que dejesa excluir?\n");
						printf("1 - Disciplina\n");
						printf("2 - Aluno de uma disciplina\n");
						scanf("%d", &excluir);
						switch(excluir)
						{
							case 1:
							{
								if(excluir_disciplina(disciplina, qtdDisciplinas) == 1)
								{						
									qtdDisciplinas--;
								}	
								break;						
							}
							case 2:
							{
								excluir_aluno_disciplina(disciplina, qtdDisciplinas);
								break;
							}								
						}
						break;
					}
					default:
					{
						printf("OPCAO INVALIDA!");
						break;
					}		
				}
				break;	
			}
			case 4:
			{
				menu_listas();
				int opcao_lista = -1;
				scanf("%d", &opcao_lista);
				limpar_buffer();
				switch(opcao_lista)
				{
					case 0:
					{	
						printf("\nSaindo...\n");
						break;
					}
					case 1:
					{
						printf("\nListando...\n");
						listar_alunos(aluno, qtdAlunos);
						break;
					}
					case 2:
					{
						printf("\nListando...\n");
						lista_alunos_alfabetica(aluno, qtdAlunos);
						break;
					}
					case 3:
					{
						printf("\nListando...\n");
						lista_alunos_sexo(aluno, qtdAlunos);
						break;
					}
					case 4:
					{
						printf("\nListando...\n");
						lista_alunos_nascimento(aluno, qtdAlunos);	
						break;
					}
					case 5:
					{
						alunos_menos_de_3_disciplinas(disciplina, aluno, qtdDisciplinas, qtdAlunos);
						break;
					}	
					case 6:
					{	
						printf("\nListando...\n");
						listar_professores(professor, qtdProfessores);
						break;
					}
					case 7:
					{
						printf("\nListando...\n");
						lista_professores_alfabetica(professor, qtdProfessores);
						break;
					}
					case 8:
					{
						printf("\nListando...\n");
						lista_professores_sexo(professor, qtdProfessores);
						break;
					}
					case 9:
					{
						printf("\nListando...\n");
						lista_professores_nascimento(professor, qtdProfessores);	
						break;						
					}
					case 10:
					{
						printf("\nListando...\n");
						listar_disciplinas(disciplina, qtdDisciplinas);
						break;						
					}
					case 11:
					{
						listar_disciplina_com_alunos(disciplina, qtdDisciplinas);
						break;
					}	
					case 12:
					{
						printf("\nListando...\n");
						disciplina_40_vagas(disciplina, qtdDisciplinas);
						break;						
					}	
					case 13:
					{
						lista_por_busca(aluno, qtdAlunos, professor, qtdProfessores);
						break;
					}
					case 14:
					{
						aniversariantes_mes(aluno, qtdAlunos, professor, qtdProfessores);	
						break;
					}
					default:
					{
						printf("OPCAO INVALIDA!");
						break;
					}
				}
				break;
			}
			default:
				{
				printf("OPCAO INVALIDA!");
				break;
				}	
			break;	
		}	

	}

	return 0;
}


void main_menu()
{
	printf("\n");
	printf("Qual aba deseja visualizar:\n");
	printf("0 - Sair\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Disciplinas\n");
    printf("4 - Relatorios/Listas\n");
    printf("\n");
}

void menu()
{
	printf("O que deseja fazer:\n");
	printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Atualizar\n");
    printf("3 - Excluir\n");
    printf("\n");
}

void menu_listas()
{
	printf("\n");
	printf("Qual relatorio/lista deseja vizualizar:\n");
	printf("0 - Sair\n");
	printf("1 - Listar todos os alunos por ordem de matricula\n");
	printf("2 - Listar todos os alunos por ordem alfabetica\n");
	printf("3 - Listar os alunos por sexo\n");
	printf("4 - Listar todos os alunos por ordem de nascimento\n");
	printf("5 - Listar alunos matriculados em menos de 3 disciplinas\n");
	printf("6 - Listar todos os professores por ordem de matricula\n");
	printf("7 - Listar todos os professores por ordem alfabetica\n");
	printf("8 - Listar os professores por sexo\n");
	printf("9 - Listar todos os professores por ordem de nascimento\n");
	printf("10 - Listar todas as disciplinas\n");
	printf("11 - Listar uma disciplina com suas informações completas\n");
	printf("12 - Listar disciplinas que extrapolam 40 vagas\n");
	printf("13 - Listar pessoas (professor/aluno) a partir de uma busca\n");
	printf("14 - Listar aniversariantes do mes\n");
	printf("\n");	
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void validacao_cpf(Pessoa pessoa[], int contador)
{
	
	int cpf_valido;
	do 
	{
		cpf_valido = 1;
    	printf("Informe o CPF (Apenas numeros): ");
    	fgets(pessoa[contador].cpf, MAX, stdin);
    	pessoa[contador].cpf[strcspn(pessoa[contador].cpf, "\r\n")] = 0;
    	if (strlen(pessoa[contador].cpf) != 11) 
		{
        	printf("CPF INVALIDO! O CPF deve conter exatamente 11 numeros.\n\n");
        	cpf_valido = 0;
    	} 
		else 
		{
        	for (int i = 0; i < 11; i++) 
			{
            	if (!isdigit(pessoa[contador].cpf[i])) 
				{
                	printf("CPF INVALIDO! Utilize apenas numeros.\n\n");
                	cpf_valido = 0; 
                	break;
            	}
        	}
    	}
	} 
	while (cpf_valido == 0); 
}

void validacao_matricula(Pessoa pessoa[], int contador)
{
	int matricula_valida;
	do
	{
		matricula_valida = 1;
    	printf("Informe a matricula: ");
    	fgets(pessoa[contador].matricula, MAX, stdin);
    	pessoa[contador].matricula[strcspn(pessoa[contador].matricula, "\r\n")] = 0;
    	if (strlen(pessoa[contador].matricula) != 11) 
		{
        	printf("MATRICULA INVALIDO! A matricula deve conter exatamente 11 numeros.\n\n");
        	matricula_valida = 0;
    	} 
    	else
    	{
    		for (int i = 0; i < 11; i++) 
			{
            	if (!isdigit(pessoa[contador].matricula[i])) 
				{	
                	printf("MATRICULA INVALIDA! Utilize apenas numeros.\n\n");
                	matricula_valida = 0;
                	break;
            	}	
        	}	
    	}
	}
	while(matricula_valida == 0);	
}

void validacao_nome(Pessoa pessoa[], int contador)
{
	int nome_valido;
	do
	{
		nome_valido = 1;			
		printf("Informe o nome: ");
    	fgets(pessoa[contador].nome, MAX, stdin); 
    	pessoa[contador].nome[strcspn(pessoa[contador].nome, "\n")] = 0;
        if (strlen(pessoa[contador].nome) == 0) 
		{
            printf("NOME INVALIDO! O nome nao pode ser vazio.\n\n");
            nome_valido = 0;
        } 
		else 
		{
	    	for (int i = 0; i < strlen(pessoa[contador].nome); i++) 
			{
	            if (!isalpha(pessoa[contador].nome[i]) && !isspace(pessoa[contador].nome[i])) 
				{	
	                printf("NOME INVALIDO! Utilize apenas letras e espacos.\n\n");
	                nome_valido = 0;
	                break;
	            }	
	    	}	
		}
	}
	while(nome_valido == 0);
}

void validacao_sexo(Pessoa pessoa[], int contador)
{
	do
	{
    	printf("Informe o sexo (M/F): ");
    	scanf(" %c", &pessoa[contador].sexo);
    	limpar_buffer();
    	pessoa[contador].sexo = toupper(pessoa[contador].sexo);
   		if(pessoa[contador].sexo != 'F' && pessoa[contador].sexo != 'M')
  			printf("INVALIDO! Use apenas M ou F.\n\n");
	}
	while(pessoa[contador].sexo != 'F' && pessoa[contador].sexo != 'M');
}

void validacao_data(Pessoa pessoa[], int contador)
{
	int data_valida;
	do
	{
		data_valida = 1;
    	printf("Informe a data de nascimento (DD MM AAAA): ");
    	scanf("%d %d %d", &pessoa[contador].data.dia, &pessoa[contador].data.mes, &pessoa[contador].data.ano);
    	limpar_buffer();
    	if(pessoa[contador].data.dia <= 0 || pessoa[contador].data.dia > 31)
    	{
    		printf("DIA INVALIDO! Tente Novamente.\n\n");
    		data_valida = 0;
    	}
    	else if(pessoa[contador].data.mes <= 0 || pessoa[contador].data.mes > 12)
    	{
    		printf("MES INVALIDO! Tente Novamente.\n\n");
    		data_valida = 0;
    	}
    	else if(pessoa[contador].data.ano <= 1925 || pessoa[contador].data.ano > 2025)
    	{
    		printf("ANO INVALIDO! Tente Novamente.\n\n");
			data_valida = 0;			
		}
	}
    while(data_valida == 0); 
}

void cadastro_pessoa(Pessoa pessoa[], int contador)
{
	validacao_nome(pessoa, contador);
	validacao_sexo(pessoa, contador);
	validacao_data(pessoa, contador);
	validacao_cpf(pessoa, contador);
	validacao_matricula(pessoa, contador);
}

void cadastro_disciplina(Disciplina disciplina[], int qtdDisciplinas, Pessoa professor[], int qtdProfessores, Pessoa aluno[], int qtdAlunos)
{
	validacao_nome_disciplina(disciplina, qtdDisciplinas);
	validacao_codigo_disciplina(disciplina, qtdDisciplinas);
	validacao_semestre(disciplina, qtdDisciplinas);
	validacao_professor(disciplina, professor, qtdDisciplinas, qtdProfessores);
	matricular_aluno(disciplina, aluno, qtdDisciplinas, qtdAlunos);
}

void listar_alunos(Pessoa aluno[], int qtdAlunos)
{
	for (int i = 0; i < qtdAlunos; i++)
	{
        printf("Aluno %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, aluno[i].nome, aluno[i].sexo, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano, aluno[i].cpf, aluno[i].matricula);
    }
    printf("\n");
}

void listar_professores(Pessoa professor[], int qtdProfessores)
{
	for (int i = 0; i < qtdProfessores; i++)
	{
        printf("Professor %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, professor[i].nome, professor[i].sexo, professor[i].data.dia, professor[i].data.mes, professor[i].data.ano, professor[i].cpf, professor[i].matricula);
    }
    printf("\n");
}

int excluir_aluno(Pessoa aluno[], int qtdAlunos)
{
	printf("Excluindo...\n");
    listar_alunos(aluno, qtdAlunos);
    printf("Qual aluno deseja excluir?\n");
    int excluido;
	scanf("%d", &excluido);
    limpar_buffer();
    if (excluido >= 1 && excluido <= qtdAlunos)
	{
        for (int e = excluido-1; e<qtdAlunos-1; e++)
    	{
   			aluno[e] = aluno[e+1];
		}
		printf("Excluido!\n");
		return 1;
		}
	else 
	{
    	printf("Número inválido\n");
    	return 0;
    }
}

int excluir_professor(Pessoa professor[], int qtdProfessores)
{
	printf("Excluindo...\n");
    listar_professores(professor, qtdProfessores);
    printf("Qual professor deseja excluir?\n");
    int excluido;
	scanf("%d", &excluido);
    limpar_buffer();
    if (excluido >= 1 && excluido <= qtdProfessores)
	{
        for (int e = excluido-1; e<qtdProfessores-1; e++)
    	{
   			professor[e] = professor[e+1];
		}
		printf("Excluido!\n");
		return 1;
		}
	else 
	{
    	printf("Número inválido\n");
    	return 0;
    }
}

int atualizar_aluno(Pessoa aluno[], int qtdAlunos)
{
	listar_alunos(aluno, qtdAlunos);
	printf("Qual aluno deseja atualizar?\n");
	int atualizado;
	scanf("%d", &atualizado);
    limpar_buffer();
    if (atualizado >= 1 && atualizado <= qtdAlunos)
	{
   		cadastro_pessoa(aluno, atualizado - 1);
		printf("Atualizado!\n");
		return 1;
		}
	else 
	{
    	printf("Número inválido\n");
    	return 0;
    }
	
}

int atualizar_professor(Pessoa professor[], int qtdProfessores)
{
	listar_professores(professor, qtdProfessores);
	printf("Qual professor deseja atualizar?\n");
	int atualizado;
	scanf("%d", &atualizado);
    limpar_buffer();
    if (atualizado >= 1 && atualizado <= qtdProfessores)
	{
   		cadastro_pessoa(professor, atualizado - 1);
		printf("Atualizado!\n");
		return 1;
		}
	else 
	{
    	printf("Número inválido\n");
    	return 0;
    }
	
}

void lista_alunos_alfabetica(Pessoa aluno[], int qtdAlunos)
{
    Pessoa alunos_ordenados[qtdAlunos];
    memcpy(alunos_ordenados, aluno, qtdAlunos * sizeof(Pessoa));
    for (int i = 0; i < qtdAlunos - 1; i++)
    {
        for (int j = 0; j < qtdAlunos - i - 1; j++)
        {
            if (strcmp(alunos_ordenados[j].nome, alunos_ordenados[j + 1].nome) > 0)
            {
                Pessoa temp = alunos_ordenados[j];
                alunos_ordenados[j] = alunos_ordenados[j + 1];
                alunos_ordenados[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("Aluno %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, alunos_ordenados[i].nome, alunos_ordenados[i].sexo, alunos_ordenados[i].data.dia, alunos_ordenados[i].data.mes, alunos_ordenados[i].data.ano, alunos_ordenados[i].cpf, alunos_ordenados[i].matricula);
    }
    printf("\n"); 
}

void lista_professores_alfabetica(Pessoa professor[], int qtdProfessores)
{
    Pessoa professores_ordenados[qtdProfessores];
    memcpy(professores_ordenados, professor, qtdProfessores * sizeof(Pessoa));
    for (int i = 0; i < qtdProfessores - 1; i++)
    {
        for (int j = 0; j < qtdProfessores - i - 1; j++)
        {
            if (strcmp(professores_ordenados[j].nome, professores_ordenados[j + 1].nome) > 0)
            {
                Pessoa temp = professores_ordenados[j];
                professores_ordenados[j] = professores_ordenados[j + 1];
                professores_ordenados[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < qtdProfessores; i++)
    {
        printf("Professor %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, professores_ordenados[i].nome, professores_ordenados[i].sexo, professores_ordenados[i].data.dia, professores_ordenados[i].data.mes, professores_ordenados[i].data.ano, professores_ordenados[i].cpf, professores_ordenados[i].matricula);
    }
    printf("\n"); 
}

void lista_alunos_sexo(Pessoa aluno[], int qtdAlunos)
{
	printf("Deseja ver os alunos de qual sexo? ");
	char sexo;
	scanf(" %c", &sexo);
    limpar_buffer();
    sexo = toupper(sexo);
    if(sexo != 'F' && sexo != 'M')
  	printf("INVALIDO! Use apenas M ou F.\n\n");
    if(sexo == 'M')
    {
    	for(int i = 0; i < qtdAlunos; i++)
    	{
    		if(sexo == aluno[i].sexo)
    		{
    			printf("Aluno %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, aluno[i].nome, aluno[i].sexo, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano, aluno[i].cpf, aluno[i].matricula);
			}
		}
	}
	else if(sexo == 'F')
	{
		for(int i = 0; i < qtdAlunos; i++)
    	{
    		if(sexo == aluno[i].sexo)
    		{
    			printf("Aluna %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, aluno[i].nome, aluno[i].sexo, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano, aluno[i].cpf, aluno[i].matricula);
			}
		}	
	}
}

void lista_professores_sexo(Pessoa professor[], int qtdProfessores)
{
	printf("Deseja ver os professores de qual sexo? ");
	char sexo;
	scanf(" %c", &sexo);
    limpar_buffer();
    sexo = toupper(sexo);
    if(sexo != 'F' && sexo != 'M')
  	printf("INVALIDO! Use apenas M ou F.\n\n");
    if(sexo == 'M')
    {
    	for(int i = 0; i < qtdProfessores; i++)
    	{
    		if(sexo == professor[i].sexo)
    		{
    			printf("Professor %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, professor[i].nome, professor[i].sexo, professor[i].data.dia, professor[i].data.mes, professor[i].data.ano, professor[i].cpf, professor[i].matricula);
			}
		}
	}
	else if(sexo == 'F')
	{
		for(int i = 0; i < qtdProfessores; i++)
    	{
    		if(sexo == professor[i].sexo)
    		{
    			printf("Professora %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, professor[i].nome, professor[i].sexo, professor[i].data.dia, professor[i].data.mes, professor[i].data.ano, professor[i].cpf, professor[i].matricula);
			}
		}	
	}
}

void lista_por_busca(Pessoa aluno[], int qtdAlunos, Pessoa professor[], int qtdProfessores) 
{
	int busca_valida;
    char letras[5]; 
    do
    {
    	busca_valida = 1;
    	printf("Digite as 3 primeiras letras para buscar as pessoas: ");
    	fgets(letras, 5, stdin);
    	letras[strcspn(letras, "\r\n")] = 0;
    	if (strlen(letras) != 3) 
		{
        	printf("INVALIDO! Deve buscar por 3 letras.\n\n");
        	busca_valida = 0; 
    	}
	}
	while(busca_valida == 0);
	int pessoas_encontradas = 0;
    for (int i = 0; i < qtdAlunos; i++)
	{
        if (strncmp(letras, aluno[i].nome, 3) == 0) 
		{
            printf("Aluno - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", aluno[i].nome, aluno[i].sexo, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano, aluno[i].cpf, aluno[i].matricula);
            pessoas_encontradas++;
        }
    }
    for (int i = 0; i < qtdProfessores; i++) 
	{
        if (strncmp(letras, professor[i].nome, 3) == 0) 
		{
            printf("Professor - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", professor[i].nome, professor[i].sexo, professor[i].data.dia, professor[i].data.mes, professor[i].data.ano, professor[i].cpf, professor[i].matricula);
        	pessoas_encontradas++;
		}
    }
    if(pessoas_encontradas == 0)
    {
    	printf("Nenhuma pessoa com as iniciais '%s' encontrada\n", letras);
	}
}

void aniversariantes_mes(Pessoa aluno[], int qtdAlunos, Pessoa professor[], int qtdProfessores) 
{
	int mes_valido;
    int mes; 
    do
    {
    	mes_valido = 1;
    	printf("Deseja ver os aniversariantes de qual mes? ");
		scanf("%d", &mes);
		limpar_buffer();
    	if (mes < 1 || mes > 12) 
		{
        	printf("INVALIDO! Digite um numero de 1 a 12.\n\n");
        	mes_valido = 0; 
    	}
	}
	while(mes_valido == 0);
	int pessoas_encontradas = 0;
    for (int i = 0; i < qtdAlunos; i++)
	{
        if (mes == aluno[i].data.mes) 
		{
            printf("Aluno - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", aluno[i].nome, aluno[i].sexo, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano, aluno[i].cpf, aluno[i].matricula);
            pessoas_encontradas++;
        }
    }
    for (int i = 0; i < qtdProfessores; i++) 
	{
        if (mes == professor[i].data.mes) 
		{
            printf("Professor - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", professor[i].nome, professor[i].sexo, professor[i].data.dia, professor[i].data.mes, professor[i].data.ano, professor[i].cpf, professor[i].matricula);
        	pessoas_encontradas++;
		}
    }
    if(pessoas_encontradas == 0)
    {
    	printf("O mes %d nao possui nenhum aniversariante\n", mes);
	}
}


void lista_alunos_nascimento(Pessoa aluno[], int qtdAlunos)
{
    Pessoa alunos_ordenados[qtdAlunos];
    memcpy(alunos_ordenados, aluno, qtdAlunos * sizeof(Pessoa));
    for (int i = 0; i < qtdAlunos - 1; i++)
    {
        for (int j = 0; j < qtdAlunos - i - 1; j++)
        {
            if (alunos_ordenados[j].data.ano > alunos_ordenados[j + 1].data.ano)
            {
                Pessoa temp = alunos_ordenados[j];
                alunos_ordenados[j] = alunos_ordenados[j + 1];
                alunos_ordenados[j + 1] = temp;
            }
            else if (alunos_ordenados[j].data.ano == alunos_ordenados[j + 1].data.ano && alunos_ordenados[j].data.mes > alunos_ordenados[j + 1].data.mes)
            {
                Pessoa temp = alunos_ordenados[j];
                alunos_ordenados[j] = alunos_ordenados[j + 1];
                alunos_ordenados[j + 1] = temp;
            }
            else if (alunos_ordenados[j].data.ano == alunos_ordenados[j + 1].data.ano && alunos_ordenados[j].data.mes == alunos_ordenados[j + 1].data.mes && alunos_ordenados[j].data.dia > alunos_ordenados[j + 1].data.dia)
            {
                Pessoa temp = alunos_ordenados[j];
                alunos_ordenados[j] = alunos_ordenados[j + 1];
                alunos_ordenados[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("Aluno %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, alunos_ordenados[i].nome, alunos_ordenados[i].sexo, alunos_ordenados[i].data.dia, alunos_ordenados[i].data.mes, alunos_ordenados[i].data.ano, alunos_ordenados[i].cpf, alunos_ordenados[i].matricula);
    }
    printf("\n"); 
}

void lista_professores_nascimento(Pessoa professor[], int qtdProfessores)
{
    Pessoa professores_ordenados[qtdProfessores];
    memcpy(professores_ordenados, professor, qtdProfessores * sizeof(Pessoa));
    for (int i = 0; i < qtdProfessores - 1; i++)
    {
        for (int j = 0; j < qtdProfessores - i - 1; j++)
        {
            if (professores_ordenados[j].data.ano > professores_ordenados[j+1].data.ano)
            {
                Pessoa temp = professores_ordenados[j];
                professores_ordenados[j] = professores_ordenados[j + 1];
                professores_ordenados[j + 1] = temp; 
            }
        	else if (professores_ordenados[j].data.ano == professores_ordenados[j+1].data.ano && professores_ordenados[j].data.mes > professores_ordenados[j+1].data.mes)
           	{
                Pessoa temp = professores_ordenados[j];
                professores_ordenados[j] = professores_ordenados[j + 1];
                professores_ordenados[j + 1] = temp;
            }
    	    else if (professores_ordenados[j].data.ano == professores_ordenados[j+1].data.ano && professores_ordenados[j].data.mes == professores_ordenados[j+1].data.mes && professores_ordenados[j].data.dia > professores_ordenados[j+1].data.dia)
            {
            	Pessoa temp = professores_ordenados[j];
            	professores_ordenados[j] = professores_ordenados[j + 1];
            	professores_ordenados[j + 1] = temp;
            }
    	}
    }
    for (int i = 0; i < qtdProfessores; i++)
    {
        printf("Aluno %d - Nome: %s - Sexo: %c - Data de Nascimento:  %02d/%02d/%d - CPF: %s - Matricula: %s\n", i+1, professores_ordenados[i].nome, professores_ordenados[i].sexo, professores_ordenados[i].data.dia, professores_ordenados[i].data.mes, professores_ordenados[i].data.ano, professores_ordenados[i].cpf, professores_ordenados[i].matricula);
    }
    printf("\n"); 
}

void validacao_nome_disciplina(Disciplina disciplina[], int qtdDisciplinas)
{
	int nome_valido;
	do
	{
		nome_valido = 1;			
		printf("Informe o nome da disciplina: ");
    	fgets(disciplina[qtdDisciplinas].nome, MAX, stdin); 
    	disciplina[qtdDisciplinas].nome[strcspn(disciplina[qtdDisciplinas].nome, "\n")] = 0;
        if (strlen(disciplina[qtdDisciplinas].nome) == 0) 
		{
            printf("NOME INVALIDO! O nome nao pode ser vazio.\n\n");
            nome_valido = 0;
        } 
		else 
		{
	    	for (int i = 0; i < strlen(disciplina[qtdDisciplinas].nome); i++) 
			{
	            if (!isalpha(disciplina[qtdDisciplinas].nome[i]) && !isspace(disciplina[qtdDisciplinas].nome[i])) 
				{	
	                printf("NOME INVALIDO! Utilize apenas letras e espacos.\n\n");
	                nome_valido = 0;
	                break;
	            }	
	    	}	
		}
	}
	while(nome_valido == 0);
}

void validacao_codigo_disciplina(Disciplina disciplina[], int qtdDisciplinas)
{
	int codigo_valido;
	do
	{
		codigo_valido = 1;			
		printf("Informe o codigo da disciplina: ");
    	fgets(disciplina[qtdDisciplinas].codigo, MAX, stdin); 
    	disciplina[qtdDisciplinas].codigo[strcspn(disciplina[qtdDisciplinas].codigo, "\n")] = 0;
        if (strlen(disciplina[qtdDisciplinas].codigo) != 6) 
		{
            printf("CODIGO INVALIDO! O codigo deve conter exatamente 6 caracteres, sendo tres letras e tres numeros.\n\n");
            codigo_valido = 0;
        } 
		else 
		{
	    	for (int i = 0; i < 3; i++) 
			{
	            if (!isalpha(disciplina[qtdDisciplinas].codigo[i])) 
				{	
	                printf("CODIGO INVALIDO! Os tres primeiros caracteres precisam ser letras.\n\n");
	                codigo_valido = 0;
	                break;
	            }	
	    	}
	    	for (int i = 3; i < 6; i++) 
			{
	            if (isalpha(disciplina[qtdDisciplinas].codigo[i])) 
				{	
	                printf("CODIGO INVALIDO! Os tres ultimos caracteres precisam ser numeros.\n\n");
	                codigo_valido = 0;
	                break;
	            }	
	    	}	
		}
	}
	while(codigo_valido == 0);
}

void validacao_semestre(Disciplina disciplina[], int qtdDisciplinas)
{
    int semestre_valido;
    do
    {
        semestre_valido = 1;
        printf("Digite o semestre da disciplina (sendo: 20251 para 2025.1): ");
        if (scanf("%d", &disciplina[qtdDisciplinas].semestre) != 1)
        {
            printf("SEMESTRE INVALIDO! Apenas numeros sao permitidos.\n\n");
            semestre_valido = 0;
        }
        limpar_buffer(); 
    } 
	while (semestre_valido == 0);
}

void validacao_professor(Disciplina disciplina[], Pessoa professor[], int qtdDisciplinas, int qtdProfessores)
{
	int prof_escolhido;
	int professor_valido;
	do
	{	
		professor_valido = 1;
		listar_professores(professor, qtdProfessores);
		printf("Deseja designar qual professor para esta disciplina? ");
		scanf("%d", &prof_escolhido);
		limpar_buffer();
		if(prof_escolhido < 1 || prof_escolhido > qtdProfessores)
		{
			printf("NUMERO INVALIDO!");
			professor_valido = 0;
		}
		else
		{
			disciplina[qtdDisciplinas].professor = professor[prof_escolhido - 1];
		}		
	}
	while(professor_valido == 0);
}

void matricular_aluno(Disciplina disciplina[], Pessoa aluno[], int qtdDisciplinas, int qtdAlunos)
{
    int aluno_escolhido;
    disciplina[qtdDisciplinas].qtdAlunosMatriculados = 0;
    while (1)
    {
        listar_alunos(aluno, qtdAlunos);
        printf("Qual aluno deseja matricular nesta disciplina?\n");
        printf("(Digite '0' para parar)");
        scanf("%d", &aluno_escolhido);
        limpar_buffer();
        if (aluno_escolhido == 0) 
		{
            printf("Parando...\n");
            break; 
        }
        if (aluno_escolhido < 1 || aluno_escolhido > qtdAlunos) 
		{
            printf("NUMERO INVALIDO!\n\n");
        }
        else 
		{
            int vaga_aluno = disciplina[qtdDisciplinas].qtdAlunosMatriculados;
            disciplina[qtdDisciplinas].aluno[vaga_aluno] = aluno[aluno_escolhido - 1];
            disciplina[qtdDisciplinas].qtdAlunosMatriculados++;
            printf("Aluno '%s' matriculado!\n\n", aluno[aluno_escolhido - 1].nome);
        }
    }
}

void listar_disciplinas(Disciplina disciplina[], int qtdDisciplinas)
{
	for (int i = 0; i < qtdDisciplinas; i++)
	{
        printf("Disciplina %d - Nome: %s - Codigo: %s - Semestre: %d - Professor: %s\n", i+1, disciplina[i].nome, disciplina[i].codigo, disciplina[i].semestre, disciplina[i].professor.nome);
    }
    printf("\n");
}

void listar_disciplina_com_alunos(Disciplina disciplina[], int qtdDisciplinas)
{
	int disciplina_valida;
	do
	{
		disciplina_valida = 1;
		int disciplina_escolhida;
		listar_disciplinas(disciplina, qtdDisciplinas);
		printf("Deseja ver os alunos de qual discilpina? ");
		scanf("%d", &disciplina_escolhida);
		limpar_buffer();
		if(disciplina_escolhida < 1 || disciplina_escolhida > qtdDisciplinas)
		{
			printf("NUMERO INVALIDO!");
			disciplina_valida = 0;
		}
		else
		{
			printf("Disciplina %d - Nome: %s - Codigo: %s - Semestre: %d - Professor: %s\n", disciplina_escolhida, disciplina[disciplina_escolhida-1].nome, disciplina[disciplina_escolhida-1].codigo, disciplina[disciplina_escolhida-1].semestre, disciplina[disciplina_escolhida-1].professor.nome);
			printf("Alunos Matriculados:\n");
			for (int i = 0; i < disciplina[disciplina_escolhida-1].qtdAlunosMatriculados; i++)	
			{
				printf("- %s\n", disciplina[disciplina_escolhida-1].aluno[i].nome);
			}
		}
	}	
	while (disciplina_valida == 0);
}

int atualizar_disciplina(Disciplina disciplina[], int qtdDisciplinas, Pessoa professor[], int qtdProfessores, Pessoa aluno[], int qtdAlunos)
{
	listar_disciplinas(disciplina, qtdDisciplinas);
	printf("Qual disciplina deseja atualizar?\n");
	int atualizado;
	scanf("%d", &atualizado);
    limpar_buffer();
    if (atualizado >= 1 && atualizado <= qtdDisciplinas)
	{
   		validacao_nome_disciplina(disciplina, atualizado-1);
		validacao_codigo_disciplina(disciplina, atualizado-1);
		validacao_semestre(disciplina, atualizado-1);
		validacao_professor(disciplina, professor, atualizado-1, qtdProfessores);
		printf("Atualizado!\n");
		return 1;
		}
	else 
	{
    	printf("Número inválido\n");
    	return 0;
    }
	
}

int excluir_disciplina(Disciplina disciplina[], int qtdDisciplinas)
{
	listar_disciplinas(disciplina, qtdDisciplinas);
	printf("Qual disciplina deseja excluir?\n");
	int excluido;
	scanf("%d", &excluido);
    limpar_buffer();
    if (excluido >= 1 && excluido <= qtdDisciplinas)
	{
        for (int e = excluido - 1; e < qtdDisciplinas - 1; e++)
    	{
   			disciplina[e] = disciplina[e+1];
		}
		printf("Excluido!\n");
		return 1;
		}
	else 
	{
    	printf("NUMERO INVALIDO!\n");
    	return 0;
    }
}

void excluir_aluno_disciplina(Disciplina disciplina[], int qtdDisciplinas)
{
	int disciplina_escolhida;
	listar_disciplinas(disciplina, qtdDisciplinas);
	printf("Deseja ver os alunos de qual disciplina? ");
	scanf("%d", &disciplina_escolhida);
	limpar_buffer();
	if(disciplina_escolhida < 1 || disciplina_escolhida > qtdDisciplinas)
	{
		printf("NUMERO INVALIDO!");
	}
	else
	{
		printf("Disciplina %d - Nome: %s - Codigo: %s - Semestre: %d - Professor: %s\n", disciplina_escolhida, disciplina[disciplina_escolhida-1].nome, disciplina[disciplina_escolhida-1].codigo, disciplina[disciplina_escolhida-1].semestre, disciplina[disciplina_escolhida-1].professor.nome);
		printf("Alunos Matriculados:\n");
		for (int i = 0; i < disciplina[disciplina_escolhida-1].qtdAlunosMatriculados; i++)	
		{
			printf("%d - %s\n", i+1, disciplina[disciplina_escolhida-1].aluno[i].nome);
		}
		int excluido;
		printf("Qual aluno deseja excluir?\n");
		scanf("%d", &excluido);
    	limpar_buffer();
    	if (excluido >= 1 && excluido <= disciplina[disciplina_escolhida-1].qtdAlunosMatriculados)
		{
        	for (int e = excluido - 1; e < disciplina[disciplina_escolhida-1].qtdAlunosMatriculados - 1; e++)
    		{
   				disciplina[disciplina_escolhida-1].aluno[e] = disciplina[disciplina_escolhida-1].aluno[e + 1];
			}
		disciplina[disciplina_escolhida-1].qtdAlunosMatriculados--;
		printf("Excluido!\n");
		}
		else 
		{
    	printf("NUMERO INVALIDO!\n");
    	}
	}
}

void disciplina_40_vagas(Disciplina disciplina[], int qtdDisciplinas)
{
	for(int i = 0; i < qtdDisciplinas; i++)
	if(disciplina[i].qtdAlunosMatriculados > 40)
	{
		printf("Disciplina %d - Nome: %s - Codigo: %s - Semestre: %d - Professor: %s\n", i+1, disciplina[i].nome, disciplina[i].codigo, disciplina[i].semestre, disciplina[i].professor.nome);
	}
}

void alunos_menos_de_3_disciplinas(Disciplina disciplina[], Pessoa aluno[], int qtdDisciplinas, int qtdAlunos)
{
    int alunos_encontrados = 0;
    for (int i = 0; i < qtdAlunos; i++)
    {
        int disciplinas_matriculadas = 0;   
        for (int j = 0; j < qtdDisciplinas; j++)
        {            
            for (int k = 0; k < disciplina[j].qtdAlunosMatriculados; k++)
            {
                if (strcmp(aluno[i].matricula, disciplina[j].aluno[k].matricula) == 0)
                {
                    disciplinas_matriculadas++; 
                    break; 
                }
            }
        }
        if (disciplinas_matriculadas < 3)
        {   
    	    printf("Aluno %d - Nome: %s - Sexo: %c - Data de Nascimento: %02d/%02d/%d - CPF: %s - Matricula: %s\n", i + 1, aluno[i].nome, aluno[i].sexo, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano, aluno[i].cpf, aluno[i].matricula);
            alunos_encontrados++;
        }
    }
    if (alunos_encontrados == 0)
    {
        printf("Nenhum aluno encontrado com menos de 3 matriculas.\n");
    }
}