#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloConsulta.h"
#include "util.h"

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
              //listarUsuarioporUF();
              break;
          case 3:
              //listarUsuarioporCidade();
              break;
          case 4:
              // listarNovoArquivo();
             // listarTudo();
              break;
          case 5:
            //  listaDinamica();
              break;
        }

        //} while (opc != 0);
        break;
      case 6:
       // ReposicionandoUsuario();
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
  printf("///            5. Relatorio da Consulta                                           ///\n");
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
/*
void listaDinamica(void){
    Consulta *cons;
    cons = NULL;
    gerarRelatorio(&cons);
    exibirLista(cons);
    free(cons);
}
*/
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
    scanf(" %12[^\n]", cons->consCPF);
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
    scanf(" %20[^\n]", cons->cadPaciente);
    getchar();
  } while (!validaNome(cons->cadPaciente));

  do
  {
    printf("Dono/Responsavel: ");
    scanf(" %30[^\n]", cons->cadResponsavel);
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
    printf("===    Horario %s\n", cons->cadHorario);
    printf("===    Paciente: %s\n", cons->cadPaciente);
}

Consulta *excluirConsulta(Consulta *confirmLeitura)
{
    FILE *del;
    Consulta *cons;
    int achou = 0;
    if (confirmLeitura == NULL)
    {
        printf("Usuario nao cadastrado");
    }
    else
    {
        cons = (Consulta *)malloc(sizeof(Consulta));
        del = fopen("consultas.dat", "rb");
        if (del == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(del))
        {
            fread(cons, sizeof(Consulta), 1, del);
            if ((strcmp(cons->consCPF, confirmLeitura->consCPF) == 0) && (cons->status) != 'x')
            {
                achou = 1;
                cons->status = 'x';
                fseek(del, -1 * sizeof(Consulta), SEEK_CUR);
                fwrite(cons, sizeof(Consulta), 1, del);
                fclose(del);
                printf("\n ========================== Usuario excluido com sucesso ==========================\n");
                return cons;
            }
        }
        if (!achou)
        {
            printf("Usuario nao encontrado");
        }
        fclose(del);
    }
    return cons;
}

Consulta *alterarConsulta(Consulta *confirmLeitura)
{
    FILE *alt;
    Consulta *cons;
   
    int achou = 0;
    char cadPaciente[50];
    char cadResponsavel[50];
    char cadDescricao[60];
    char cadData[10];
 
    
   

    if (confirmLeitura == NULL)
    {
        printf("Usuario nao cadastrado");
    }
    else
    {
        cons = (Consulta *)malloc(sizeof(Consulta));
        alt = fopen("consultas.dat", "rb");
        if (alt == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(alt))
        {
            fread(cons, sizeof(Consulta), 1, alt);
            if ((strcmp(cons->consCPF, confirmLeitura->consCPF) == 0) && (cons->status) != 'x')
            {
                achou = 1;
                                
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
                    scanf(" %20[^\n]", cons->cadPaciente);
                    getchar();
                  } while (!validaNome(cons->cadPaciente));

                  do
                  {
                    printf("Dono/Responsavel: ");
                    scanf(" %30[^\n]", cons->cadResponsavel);
                    getchar();
                  } while (!validaNome(cons->cadResponsavel));

                  do
                  {
                    printf("Descrição: ");
                    scanf(" %50[^\n]", cons->cadDescricao);
                    getchar();
                  } while (!validaNome(cons->cadDescricao));

                strcpy(cons->cadPaciente, cadPaciente);
                strcpy(cons->cadResponsavel, cadResponsavel);
                strcpy(cons->cadData, cadData);
                strcpy(cons->cadDescricao, cadDescricao);
               

                fseek(alt, -1 * sizeof(Consulta), SEEK_CUR);
                fwrite(cons, sizeof(Consulta), 1, alt);
                fclose(alt);
                printf("\n ========================== Usuario alterado com sucesso ==========================\n");
                return cons;
            }
        }
        if (!achou)
        {
            printf("Usuario nao encontrado");
        }
        fclose(alt);
    }
    return cons;
}

void listarConsulta(void) // fazer os demais códigos baseado neste.
{
    FILE *lst;
    Consulta *cons;
    printf(" ============ Lista de Usuarios =============\n");
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
    printf("///               [1] Listar Consultas                                       ///\n");
         

    do
    {
        printf("Escolha: ");
        scanf("%d", &opc);
        getchar();
        return opc;
    } while (!validaNav(&opc));
}