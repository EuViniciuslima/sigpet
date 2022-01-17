#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloConsulta.h"
#include "util.h"

typedef struct consulta Consulta;

void navConsulta(void)
{
  int opcao;
  do
  {
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
    }

  } while (opcao != 0);
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

void editarConsulta(void)
{
  telaEditarConsulta();
}

void pesquisarConsulta(void)
{
  telaPesquisarConsulta();
}

void deletarConsulta(void)
{
  telaDeletarConsulta();
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
  printf("///            Data da Consulta:                                            ///\n");
  printf("///            Nome do Paciente(Pet):                                       ///\n");
  printf("///            Dono/Responsavel:                                            ///\n");
  printf("///            Descricao:                                                   ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  do
  {
    printf("Data da consulta (Apenas Numeros, Sem Espacos):");
    scanf(" %255[^\n]", cons->cadData);
    validarData(cons->cadData);
    maskData(cons->cadData);
  } while (!validarData(cons->cadData));

  do
  {
    printf("Nome do Paciente(Pet): ");
    scanf(" %255[^\n]", cons->cadPaciente);
    getchar();
  } while (!validaNome(cons->cadPaciente));

  do
  {
    printf("Dono/Responsavel: ");
    scanf(" %255[^\n]", cons->cadResponsavel);
    getchar();
  } while (!validaNome(cons->cadResponsavel));

  do
  {
    printf("Descrição: ");
    scanf(" %255[^\n]", cons->cadDescricao);
    getchar();
  } while (!validaNome(cons->cadDescricao));

  return cons;
}

int telaPesquisarConsulta(void)
{
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
  printf("///            1. Pesquisa por Data da Consulta:                            ///\n");
  printf("///            2. Pesquisa pelo Nome do Paciente(Pet):                      ///\n");
  printf("///            3. Pesquisa pelo Dono/Responsavel:                           ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");

  printf("0. Voltar \nEscolha: ");
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

int telaEditarConsulta(void)
{
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
  printf("///            Data da Consulta:                                            ///\n");
  printf("///            Nome do Paciente(Pet):                                       ///\n");
  printf("///            Dono/Responsavel:                                            ///\n");
  printf("///            Descricao:                                                   ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  printf("0. Voltar \nEscolha: ");
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

int telaDeletarConsulta(void)
{

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
  printf("///            Data da Consulta:                                            ///\n");
  printf("///            Nome do Paciente(Pet):                                       ///\n");
  printf("///            Dono/Responsavel:                                            ///\n");
  printf("///            Descricao:                                                   ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  printf("0. Voltar \nEscolha: ");
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

void gravarConsulta(Consulta *cons)
{
  FILE *grv;
  grv = fopen("consulta_cadastradosTexto.txt", "a+");
  if (grv == NULL)
  {
    printf("Ocorreu um erro na abertura do arquivo");
    exit(1);
  }
  fprintf(grv, "%s\n", cons->cadPaciente); // gravação de arquivo texto
  fprintf(grv, "%s\n", cons->cadResponsavel);
  fprintf(grv, "%s\n", cons->cadData);
  fprintf(grv, "%s\n", cons->cadDescricao);
  fclose(grv);
}