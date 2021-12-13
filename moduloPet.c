#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloPet.h"
#include "util.h"


typedef struct pet Pet;

void navPet(void)
{
  int opcao;
  do
  {
    opcao = menuPet();
    switch (opcao)
    {
    case 1:
      cadastrarPet();
      break;
    case 2:
      pesquisarPet();
      break;
    case 3:
      editarPet();
      break;
    case 4:
      deletarPet();
      break;
    }

  } while (opcao != 0);
}

int menuPet(void)
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
  printf("///           = = = = = = = = =  Menu Pet   = = = = = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  printf("///            1. Cadastrar Pet                                             ///\n");
  printf("///            2. Pesquisar Pet                                             ///\n");
  printf("///            3. Editar Pet                                                ///\n");
  printf("///            4. Apagar Pet                                                ///\n");
  printf("///            0. Sair                                                      ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

   int escolha;
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        return escolha;
    }while(!validaNav(&escolha));
}



void cadastrarPet(void)
{
  telaCadastrarPet();
}

void pesquisarPet(void)
{
  telaPesquisarPet();
}

void editarPet(void)
{
  telaEditarPet();
}

void deletarPet(void)
{
  telaDeletarPet();
}

Pet* telaCadastrarPet(void)
{
  Pet *pet;
  pet = (Pet*)malloc(sizeof(Pet));
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
  printf("///           = = = = = = = = =  Cadastro Pet = = = = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  do{
    printf("///            Nome do Pet:");
    scanf(" %255[^\n]", pet->nome);
    getchar();
   
   
    
  }while(!validaNome(pet->nome));
  do{
    printf("///            Sexo do Pet (f/m):");
    scanf(" %255[^\n]", pet->sexo);
    getchar();
    if (validaSexo(pet->sexo) == 0)
    {
      printf("Sexo Invalido\n");
    }
  }while(!validaSexo(pet->sexo));
  
  printf("///            Idade do Pet:");
  do{
    printf("///            Especie do Pet:");
    scanf(" %255[^\n]", pet->especie);
    getchar();
  }while(!validaNome(pet->especie));
  do{
    printf("///            Dono:");
    scanf(" %255[^\n]", pet->dono);
    getchar();
  }while(!validaNome(pet->dono));
 
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  

  
  printf("0. Voltar \n: ");
  return pet;
}
/*
void validaDadosPet(void)
{

  int idadeValida = 0;

  int idade;
  char sexo;
  char nome[20];
  char especie[15];

  do
  {
    printf("Idade: ");
    scanf("%d", &idade);

    if (idade > 0)
    {
      idadeValida = 1;
    }
    else
    {
      printf("IDADE INVALIDA\n");
    }
  } while (idadeValida != 1);

  int sexoValido = 0;
  do
  {
    printf("Sexo: ");
    scanf("%c", &sexo);

    if (sexo == 'm' || sexo == 'f')
    {
      sexoValido = 1;
    }
  } while (sexoValido != 1);
  printf("Nome: ");
  scanf("%s", nome);

  printf("Especie: ");
  scanf("%s", especie);

  if (idadeValida == 1 && sexoValido == 1)
  {

    structPet(&idade, nome, especie, &sexo);
    exibirCadastroStructPet();
  }
}*/
/*
void structPet(int *idade, char *nome, char *especie, char *sexo)
{
  strcpy(PET.nome, nome);
  PET.idade = *idade;
  PET.sexo = *sexo;
  strcpy(PET.especie, especie);

  arquivoCadPet();
}

void exibirCadastroStructPet(void)
{

  //printf("Nome Pet: %s\n", PET.nome);
 // printf("Idade Pet: %d\n", PET.idade);
  //printf("Sexo Pet: %c\n", PET.sexo);
  //printf("Especie Pet: %s\n", PET.especie);
}
void arquivoCadPet(void)
{
 // FILE *gravarCadPET;
 // gravarCadPET = fopen("CadastroPET.txt", "w");
 // fprintf(gravarCadPET, "NOME PET: %s\n", PET.nome);
 // fprintf(gravarCadPET, "IDADE PET: %d\n", PET.idade);
 // fprintf(gravarCadPET, "SEXO PET: %c\n", PET.sexo);
 // fprintf(gravarCadPET, "ESPECIE PET: %s\n", PET.especie);
 // fclose(gravarCadPET);
}
*/
int telaDeletarPet(void)
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
  printf("///           = = = = = = = = =  Exluir Pet   = = = = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  printf("///            Nome do Pet:                                                 ///\n");
  printf("///            Idade do Pet:                                                ///\n");
  printf("///            Sexo do Pet:                                                 ///\n");
  printf("///            Especie do Pet:                                              ///\n");
  printf("///            Dono:                                                        ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");

  
  printf("0. Voltar \nEscolha: ");
   int escolha;
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        validaNav(&escolha);
        return escolha;
    }while(!validaNav(&escolha));
}

int telaEditarPet(void)
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
  printf("///           = = = = = = = = =   Editar Pet  = = = = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  printf("///            Nome do Pet:                                                 ///\n");
  printf("///            Idade do Pet:                                                ///\n");
  printf("///            Sexo do Pet:                                                 ///\n");
  printf("///            Especie do Pet:                                              ///\n");
  printf("///            Dono:                                                        ///\n");
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

int telaPesquisarPet(void)
{
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
  printf("///           = = = = = = = = =  Pesquisar Pet  = = = = = = =               ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
  printf("///                                                                         ///\n");
  printf("///           Pesquisar:                                                    ///\n");

  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");

  
  printf("0. Voltar \n ");
   int escolha;
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        validaNav(&escolha);
        return escolha;
    }while(!validaNav(&escolha));
}