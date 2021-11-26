#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moduloPet.h"
#include "moduloConsulta.h"
#include "moduloUsuario.h"
#include "moduloTelainfo.h"

int telaMenu(void);

int main(void)
{
  char opcao;
  do
  {
    opcao = telaMenu();
    switch (opcao)
    {
    case 1:
      navPet();
      break;
    case 2:
      navConsulta();
      break;
    case 3:
      navUsuario();
      break;
    case 4:
      navInfo();
    }
  } while (opcao != 0);
  return 0;
}

int telaMenu(void)
{

  printf("\n");
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
  printf("///            1. Modulo Pet                                                ///\n");
  printf("///            2. Modulo Consulta                                           ///\n");
  printf("///            3. Modulo Usuário                                            ///\n");
  printf("///            4. Informacoes                                               ///\n");
  printf("///            0. Sair                                                      ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  int escolha;
  printf("Escolha: ");
  scanf("%d", &escolha);

  return escolha;
}
