#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloConsulta.h"
#include "util.h"
void copyConsulta(FILE *, FILE *);
void recolocandoConsulta(FILE *read2, FILE *fp2);

typedef struct consulta Consulta;

void navConsulta(void)
{
  int opcao;
  int opc;
  
    opcao = menuConsulta();
    switch (opcao)
    {
    case 1:
      cadastrarConsulta();
      break;
    case 2:
      pesquisarConsulta();
      break;
    case 3:
      editarConsulta();
      break;
    case 4:
      deletarConsulta();
      break;
    case 5:
      opc = telaListarConsulta();
        // do
        //{
        switch (opc)
        {
          case 1:
              listarConsulta();
              break;
          case 2:
              listarConsultaporCpf();
              break;
          case 3:
              listarConsultaporData();
              break;
          case 4: 
              listarTudoConsulta();
              break;
          case 5:
              listaDinamicaConsultaPaciente();
              break;
          case 6:
              listaDinamicaConsultaDono();
              break;
        }
        break;
      case 6:
        ReposicionandoConsulta();
        break;
      }
}

 


int menuConsulta(void)
{

  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
  printf("///               Departamento de Computação e Tecnologia                   ///\n");
  printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
  printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
  printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
  printf("///                                                                         ///\n");
  printf("///            1. Cadastrar Consulta                                        ///\n");
  printf("///            2. Pesquisar Consulta                                        ///\n");
  printf("///            3. Editar Consulta                                           ///\n");
  printf("///            4. Apagar Consulta                                           ///\n");
  printf("///            5. Relatorio da Consulta                                     ///\n");
  printf("///            6. Limpar Registros                                          ///\n");
  printf("///            0. Sair                                                      ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");



  int escolha;
  do
  {
    printf("Escolha: ");
    scanf("%d", &escolha);
    getchar();
    validaNav(&escolha);
    return escolha;
  } while (!validaNav(&escolha));
}

void cadastrarConsulta(void)
{
  Consulta *cons;
  cons = telaCadastrarConsulta();
  gravarConsulta(cons);
  free(cons);
}
void listaDinamicaConsultaPaciente(void){
    Consulta *cons;
    cons = NULL;
    gerarRelatorioConsulta(&cons);
    exibirListaConsulta(cons);
    free(cons);
}
void listaDinamicaConsultaDono(void){
    Consulta *cons;
    cons = NULL;
    gerarRelatorioConsulta2(&cons);
    exibirListaConsulta(cons);
    free(cons);
}
void pesquisarConsulta(void)
{
    Consulta *cons;
    char *pesquise;
    pesquise = telaPesquisarConsulta();
    cons = buscarConsulta(pesquise);
    exibirConsulta(cons);
    free(cons);
    free(pesquise);
}

void editarConsulta(void)
{
    Consulta *cons;
    char *alterar;
    alterar = telaEditarConsulta();
    cons = buscarConsulta(alterar);
    alterarConsulta(cons);
    free(cons);
    free(alterar);
}
void deletarConsulta(void)
{
    Consulta *cons;
    char *deletar;
    deletar = telaDeletarConsulta();
    cons = buscarConsulta(deletar);
    excluirConsulta(cons);
    free(cons);
}

Consulta *telaCadastrarConsulta(void)
{

  Consulta *cons;
  cons = (Consulta *)malloc(sizeof(Consulta));

  printf("                                                                          - □ x\n");
  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                                                                         ///\n");
  printf("///          ===================================================            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          ===================================================            ///\n");
  printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///           = = = = = = = = =  Cadastro Consulta  = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");

do
  {
    printf("CPF[Apenas Numeros]:");
    scanf(" %14[^\n]", cons->consCPF);
    validaCpf(cons->consCPF);
  
  } while (!validaCpf(cons->consCPF));
  do
  {
    printf("Data da consulta (Apenas Numeros, Sem Espacos):");
    scanf(" %10[^\n]", cons->cadData);
    validarData(cons->cadData);
    maskData(cons->cadData);
  } while (!validarData(cons->cadData));

  do
  {
    printf("Nome do Paciente(Pet): ");
    scanf(" %40[^\n]", cons->cadPaciente);
    getchar();
  } while (!validaNome(cons->cadPaciente));

  do
  {
    printf("Dono/Responsavel: ");
    scanf(" %40[^\n]", cons->cadResponsavel);
    getchar();
  } while (!validaNome(cons->cadResponsavel));

  do
  {
    printf("Descrição: ");
    scanf(" %50[^\n]", cons->cadDescricao);
    getchar();
  } while (!validaNome(cons->cadDescricao));

  cons->status = 'o';
  return cons;
}

char* telaPesquisarConsulta(void)
{
  char *pesquise;
  pesquise = (char *)malloc(14 * sizeof(char));
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                                                                         ///\n");
  printf("///          ===================================================            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          ===================================================            ///\n");
  printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///           = = = = = = = = =  Pesquisar Consulta  = = = = =              ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
 
  printf("Informe o CPF: ");
  scanf("%12[^\n]", pesquise);
  return pesquise;
}

char* telaEditarConsulta(void)
{
  char *alterar;
  alterar = (char *)malloc(14 * sizeof(char)); 
  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                                                                         ///\n");
  printf("///          ===================================================            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          ===================================================            ///\n");
  printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///           = = = = = = = = =   Editar Consulta   = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  printf("///            Informe o CPF:  ");
  scanf(" %[0-9]", alterar);
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  return alterar;


}

char* telaDeletarConsulta(void)
{
  
  char *deletar;
  deletar = (char *)malloc(14 * (sizeof(char)));
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                                                                         ///\n");
  printf("///          ===================================================            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
  printf("///          ===================================================            ///\n");
  printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///           = = = = = = = = =  Excluir Consulta   = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  printf("///            Informe o CPF:  ");
  scanf(" %[0-9]", deletar);
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  return deletar;

  
}
void gravarConsulta(Consulta *cons)
{
    FILE *grv;
    grv = fopen("consultas.dat", "ab");
    if (grv == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }
    fwrite(cons, sizeof(Consulta), 1, grv);
    fclose(grv);
}

Consulta *buscarConsulta(char *pesquise)
{
    FILE *busca;

    Consulta *cons;
    cons = (Consulta *)malloc(sizeof(Consulta));

    busca = fopen("consultas.dat", "rb");
    // rb = leitura de binários
    if (busca == NULL)
    {
        printf("Ocorreu um erro durante a abertura do arquivo");
        exit(1);
    }
    while (!feof(busca))
    {
        fread(cons, sizeof(Consulta), 1, busca); 
        if ((strcmp(cons->consCPF, pesquise)) == 0 && (cons->status != 'x'))
        {
            fclose(busca);
            return cons;
        }
    }
    fclose(busca);
    return NULL;
}

void exibirConsulta(const Consulta *cons)
{

    printf("======================= RESULTADOS ENCONTRADOS =========================");
    printf("\n");
    printf("===    Nome: %s\n", cons->cadResponsavel);
    printf("===    Data: %s\n", cons->cadData);
    printf("===    CPF: %s\n", cons->consCPF);
    printf("===    Descricao: %s\n", cons->cadDescricao);
    printf("===    Paciente: %s\n", cons->cadPaciente);
}
Consulta *excluirConsulta(Consulta *confirm)
{
    FILE *del;
    Consulta *cons;
    // char cpf;
    int achou = 0;

    if (confirm == NULL)
    {
        printf("Consulta nao cadastrado");
    }
    else
    {
        cons = (Consulta *)malloc(sizeof(Consulta));
        del = fopen("consultas.dat", "r+b");
        if (del == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(del))
        {
            fread(cons, sizeof(Consulta), 1, del);
            if ((strcmp(cons->consCPF, confirm->consCPF) == 0) && (cons->status) != 'x')
            {
                achou = 1;
                cons->status = 'x';
                fseek(del, -1 * sizeof(Consulta), SEEK_CUR);
                fwrite(cons, sizeof(Consulta), 1, del);
                fclose(del);
                printf("\n ========================== Consulta excluida com sucesso ==========================\n");
                return cons;
            }
        }
        if (!achou)
        {
            printf("Consulta nao encontrado");
        }
        fclose(del);
    }
    return cons;
}

Consulta *alterarConsulta(Consulta *confirm)
{
    FILE *alt;
    Consulta *cons;
    int achou = 0;
    char paciente[50];
    char responsavel[50];
    char descricao[60];
    char data[10];
   
    if (confirm == NULL)
    {
        printf("Consulta nao cadastrado");
    }
    else
    {
        cons = (Consulta *)malloc(sizeof(Consulta));
        alt = fopen("consultas.dat", "r+b");
        if (alt == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(alt))
        {
            fread(cons, sizeof(Consulta), 1, alt);
            if ((strcmp(cons->cadPaciente, confirm->cadPaciente) == 0) && (cons->status) != 'x')
            {
                achou = 1;
                  
                do
                {
                  printf("Data da consulta (Apenas Numeros, Sem Espacos):");
                  scanf(" %10[^\n]", data);
                  validarData(data);
                  maskData(data);
                } while (!validarData(data));

                do
                {
                  printf("Nome do Paciente(Pet): ");
                  scanf(" %40[^\n]", paciente);
                  getchar();
                } while (!validaNome(paciente));

                do
                {
                  printf("Dono/Responsavel: ");
                  scanf(" %40[^\n]", responsavel);
                  getchar();
                } while (!validaNome(responsavel));

                do
                {
                  printf("Descrição: ");
                  scanf(" %50[^\n]", descricao);
                  getchar();
                } while (!validaNome(descricao));

                strcpy(cons->cadPaciente, paciente);
                strcpy(cons->cadResponsavel, responsavel);
                strcpy(cons->cadDescricao, descricao);
                strcpy(cons->cadData, data);
             

                fseek(alt, -1 * sizeof(Consulta), SEEK_CUR);
                fwrite(cons, sizeof(Consulta), 1, alt);
                fclose(alt);
                printf("\n ========================== Consulta alterada com sucesso ==========================\n");
                return cons;
            }
        }
        if (!achou)
        {
            printf("Consulta nao encontrado");
        }
        fclose(alt);
    }
    return cons;
}

void listarConsulta(void) // fazer os demais códigos baseado neste.
{
    FILE *lst;
    Consulta *cons;
    printf(" ============ Lista de Consultas =============\n");
    cons = (Consulta *)malloc(sizeof(Consulta));
    lst = fopen("consultas.dat", "rb");
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }

    while (fread(cons, sizeof(Consulta), 1, lst))
    {
        if (cons->status != 'x')
        {
            exibirConsulta(cons);
        }
    }
    fclose(lst);
}

int telaListarConsulta(void)
  {
    int opc;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = =  Listar  =  = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///               [1] Listar Consultas                                      ///\n");
    printf("///               [2] Listar Consultas por CPF                              ///\n");
    printf("///               [3] Listar Consultas por Data                             ///\n");
    printf("///               [4] Listar Tudo (Ate os Excluidos Logicamente)            ///\n");
    printf("///               [5] Lista Dinamica (Pacientes Em Ordem Alfabetica)        ///\n");
    printf("///               [6] Lista Dinamica (Dono Em Ordem Alfabetica)             ///\n");
         

    do
    {
        printf("Escolha: ");
        scanf("%d", &opc);
        getchar();
        return opc;
    } while (!validaNav(&opc));
}

void listarTudoConsulta(void)
{
    FILE *lst;
    Consulta *cons;
    printf(" ============ Lista de Consultas =============\n");
    cons = (Consulta *)malloc(sizeof(Consulta));
    lst = fopen("consultas.dat", "rb");
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    while (!feof(lst))
    {
        while (fread(cons, sizeof(Consulta), 1, lst))
        {
            exibirConsulta(cons);
        }
        
        // navUsuario();
    }
    fclose(lst);
}

void listarConsultaporCpf(void)
{
    FILE *lst;
    Consulta *cons;
    char cpf[15];
    cons = (Consulta *)malloc(sizeof(Consulta));
    lst = fopen("consultas.dat", "rb");
    printf(" ============ Lista de Consultas por CPF =============\n");
    printf("Informe o CPF: ");
    scanf("%14[^\n]", cpf);
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");

        exit(1);
    }
    while (!feof(lst))
    {
        while (fread(cons, sizeof(Consulta), 1, lst))
        {
            if ((strcmp(cons->consCPF, cpf) == 0) && (cons->status != 'x'))
            {
                exibirConsulta(cons);
            }
        }
    
        // navUsuario();
    }
    fclose(lst);
}

void listarConsultaporData(void)
{
    FILE *lst;
    Consulta *cons;
    char data[12];
    cons = (Consulta *)malloc(sizeof(Consulta));
    lst = fopen("consultas.dat", "rb");
    printf(" ============ Lista de Consultas por Data =============\n");
    printf("Informe o Data: ");
    scanf("%10[^\n]", data);
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");

        exit(1);
    }
    while (!feof(lst))
    {
        while (fread(cons, sizeof(Consulta), 1, lst))
        {
            if ((strcmp(cons->cadData, data) == 0) && (cons->status != 'x'))
            {
                exibirConsulta(cons);
            }
        }
    }
    fclose(lst);
}

void copyConsulta(FILE *read, FILE *fp)
{
    Consulta *cons;
    cons = (Consulta *)malloc(sizeof(Consulta));

    while (!feof(read))
    {
        while (fread(cons, sizeof(Consulta), 1, read))
        {
            if (cons->status != 'x')
            {
                fwrite(cons, sizeof(Consulta), 1, fp);
            }
        }
    }
}

void recolocandoConsulta(FILE *read2, FILE *fp2)
{
    Consulta *cons;
    cons = (Consulta *)malloc(sizeof(Consulta));

    while (!feof(read2))
    {
        while (fread(cons, sizeof(Consulta), 1, read2))
        {

            fwrite(cons, sizeof(Consulta), 1, fp2);
        }
    }
}

void DelFisicConsulta(void)
{
    FILE *read;
    read = fopen("consultas.dat", "rb");
    if (read == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo");
        exit(1);
    }
    FILE *fp;
    fp = fopen("ConsultasExistentes.dat", "wb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo");
        exit(1);
    }

    copyConsulta(read, fp);

    fclose(read);
    fclose(fp);
}

void ReposicionandoConsulta(void)
{
    DelFisicConsulta();
    FILE *read2;
    read2 = fopen("ConsultasExistentes.dat", "rb");
    if (read2 == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo");
        exit(1);
    }

    FILE *fp2;
    fp2 = fopen("consultas.dat", "wb");
    if (fp2 == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo");
        exit(1);
    }

    recolocandoConsulta(read2, fp2);

    fclose(read2);
    fclose(fp2);
}

void exibirListaConsulta(const Consulta *aux)
{

	
  printf("\n");
	while (aux != NULL)
	{
    	printf("%s\t\t\t",aux->cadPaciente);
    	printf("%s\t\t\t",aux->cadData);
    	printf("%s\n",aux->cadResponsavel);
    	printf("%s\n",aux->consCPF);
    	aux = aux->prox;
	}
	printf("\nFim da Lista! \n\n");
}



void gerarRelatorioConsulta(Consulta **con)
{
    FILE *fp;
    Consulta *al;
    
    //apagarLista(&(*lista));
    *con = NULL;
    fp = fopen("consultas.dat","rb");
    if (fp == NULL)
    {
   	 printf("Erro na abertura do arquivo... \n");
   	 exit(1);
    }
    else
    {
   	 al = (Consulta *) malloc(sizeof(Consulta));
   	 while (fread(al, sizeof(Consulta), 1, fp))
   	 {
        if ((*con == NULL) || (strcmp(al->cadPaciente, (*con)->cadPaciente) < 0)) {
          al->prox = *con;
          *con = al;
        } else  {
          Consulta* ant = *con;
          Consulta* atu = (*con)->prox;
          while ((atu != NULL) && (strcmp(atu->cadPaciente, al->cadPaciente) < 0)) {
            ant = atu;
            atu = atu->prox;
          }
          ant->prox = al;
          al->prox = atu;
        }
        al = (Consulta *) malloc(sizeof(Consulta));
   	 }
   	 free(al);
   	 printf("Arquivo recuperado com sucesso! \n");
   	 
    }  
    fclose(fp);
   
}



void gerarRelatorioConsulta2(Consulta **con)
{
    FILE *fp;
    Consulta *al;
    
    //apagarLista(&(*lista));
    *con = NULL;
    fp = fopen("consultas.dat","rb");
    if (fp == NULL)
    {
   	 printf("Erro na abertura do arquivo... \n");
   	 exit(1);
    }
    else
    {
   	 al = (Consulta *) malloc(sizeof(Consulta));
   	 while (fread(al, sizeof(Consulta), 1, fp))
   	 {
        if ((*con == NULL) || (strcmp(al->cadResponsavel, (*con)->cadResponsavel) < 0)) {
          al->prox = *con;
          *con = al;
        } else  {
          Consulta* ant = *con;
          Consulta* atu = (*con)->prox;
          while ((atu != NULL) && (strcmp(atu->cadResponsavel, al->cadResponsavel) < 0)) {
            ant = atu;
            atu = atu->prox;
          }
          ant->prox = al;
          al->prox = atu;
        }
        al = (Consulta *) malloc(sizeof(Consulta));
   	 }
   	 free(al);
   	 printf("Arquivo recuperado com sucesso! \n");
   	 
    }  
    fclose(fp);
   
}
