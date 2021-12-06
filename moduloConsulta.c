#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloConsulta.h"
#include "util.h"

typedef struct Cadastro CONS;

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
  printf("Escolha: ");
  scanf("%d", &escolha);
  return escolha;
}

void cadastrarConsulta(void)
{
  telaCadastrarConsulta();
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

int telaCadastrarConsulta(void)
{

  char cadConsult[13];
  char nomePaciente[15];
  char nomeRespon[15];
  char cadDescri[60];

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
    printf("Data da consulta:");
    scanf(" %[0-9]", cadConsult);
    validarData(cadConsult);
  } while (!validarData(cadConsult));

  do
  {
    printf("Nome do Paciente(Pet): ");
    scanf(" %[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomePaciente);
    getchar();
  } while (!validaNome(nomePaciente));

  do
  {
    printf("Dono/Responsavel: ");
    scanf(" %[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeRespon);
    getchar();
  } while (!validaNome(nomeRespon));

  do
  {
    printf("Descrição: ");
    scanf(" %[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cadDescri);
    getchar();
  } while (!validaNome(cadDescri));

  printf("0. Voltar \nEscolha: ");
  int escolha;
  scanf("%d", &escolha);
  return escolha;
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
  scanf("%d", &escolha);
  return escolha;
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
  scanf("%d", &escolha);
  return escolha;
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
  scanf("%d", &escolha);
  return escolha;
}
