#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moduloTelainfo.h"
#include "util.h"

void navInfo(void)
{

  int opcaoInfo;
  do
  {
    opcaoInfo = info();
    switch (opcaoInfo)
    {
    case 1:
      telasobre();
      break;

    case 2:
      develop();
      break;
    }
  } while (opcaoInfo != 0);
}

int info(void)
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
  printf("///            1. Sobre                                                     ///\n");
  printf("///            2. Equipe                                                    ///\n");
  printf("///            0. Voltar                                                    ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  int escolha;
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        validaNav(&escolha);
        return escolha;
    }while(!validaNav(&escolha));
  
}

int telasobre(void)
{

  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
  printf("///               Departamento de Computação e Tecnologia                   ///\n");
  printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
  printf("///          Projeto Sistema de Agendamento de Consultas para Pets          ///\n");
  printf("///                Developed by  @AnnaOliveira99 - Out, 2021                ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
  printf("///                                                                         ///\n");
  printf("///  O Programa SIG-Pet é ums sistema de agendamento de consultas para pets ///\n");
  printf("///  desenvolvido para fins acadêmicos, de modo que o usuário seja capaz de ///\n");
  printf("///  agendar uma consulta para seu animal de estimação do conforto da sua   ///\n");
  printf("///  casa, além de acompanhar por meio do quadro de avisos, a data de vaci- ///\n");
  printf("///  nação do seu bichinho, bem como as pendências do animal                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");


  int escolha;
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        validaNav(&escolha);
        return escolha;
    }while(!validaNav(&escolha));
  
}

int develop(void)
{

  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
  printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
  printf("///               Departamento de Computação e Tecnologia                   ///\n");
  printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
  printf("///          Projeto Sistema de Agendamento de Consultas para Pets          ///\n");
  printf("///                Developed by  @AnnaOliveira99 - Out, 2021                ///\n");
  printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
  printf("///                                                                         ///\n");
  printf("///    Esse projeto está sendo desenvolvido por:                            ///\n");
  printf("///                                                                         ///\n");
  printf("///    Developed by  @OliveiraAnna99 - Out, 2021                            ///\n");
  printf("///    Developed by  @EuViniciuslima - Out, 2021                            ///\n");
  printf("///    Email: anna.oliveira.700@ufrn.edu.br                                 ///\n");
  printf("///    Email: vinicius.lima.114@ufrn.edu.br                                 ///\n");
  printf("///    GitHub repositorio: https://github.com/EuViniciuslima/sigpet.git     ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");

  int escolha;
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        validaNav(&escolha);
        return escolha;
    }while(!validaNav(&escolha));
  
}