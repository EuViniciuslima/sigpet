#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloPet.h"

void navPet(void){
  int opcao;
  do{
    opcao = moduloPet();
    switch(opcao){
      case 1: cadastrarPet();
      break;
      case 2: pesquisarPet();
      break;
      case 3: editarPet();
      break;
      case 4: deletarPet();
      break;
    }

  }while(opcao!= 0);

}



int moduloPet(void){
   
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
    printf("Escolha: ");
    scanf("%d", &escolha);

    return escolha;
    
}



typedef struct {
    char nome[20];
    int idade;
    char sexo;
    char especie[15];
}Pet;

Pet PET;

void cadastrarPet(void){
  telaCadastrarPet();
}

void pesquisarPet(void){
  telaPesquisarPet();
}

void editarPet(void){
  telaEditarPet();
}

void deletarPet(void){
  telaDeletarPet();
}



int telaCadastrarPet(void){

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
    printf("///            Nome do Pet:                                                 ///\n");
    printf("///            Idade do Pet:                                                ///\n");
    printf("///            Sexo do Pet:                                                 ///\n");
    printf("///            Especie do Pet:                                              ///\n");
    printf("///            Dono:                                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    validaDadosPet();
    
    int escolha;
    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

void validaDadosPet(void){
  
  int idadeValida = 0;
  

  int idade;
  char sexo;
  char nome[20];
  char especie[15];

  do{
    printf("Idade: ");
    scanf("%d", &idade);  

    if(idade > 0){
      idadeValida = 1;
    }
    else{
      printf("IDADE INVALIDA\n");
    }
  }while(idadeValida !=1);
  
  int sexoValido = 0;
  do{
    printf("Sexo: ");
    scanf("%c", &sexo);

    if(sexo == 'm' || sexo == 'f'){
      sexoValido = 1;
    } 
  }while(sexoValido != 1);
  printf("Nome: ");
  scanf("%s", nome);

  printf("Especie: ");
  scanf("%s", especie);

  if(idadeValida ==1 && sexoValido ==1){
   
    structPet(&idade, nome, especie, &sexo);
    exibirCadastroStructPet();
  } 
}

void structPet(int *idade, char *nome, char *especie, char *sexo){
    strcpy(PET.nome, nome);
    PET.idade = *idade;
    PET.sexo = *sexo;
    strcpy(PET.especie, especie);
    
    arquivoCadPet();
}

void exibirCadastroStructPet(void){
  
    printf("Nome Pet: %s\n", PET.nome);
    printf("Idade Pet: %d\n", PET.idade);
    printf("Sexo Pet: %c\n", PET.sexo);
    printf("Especie Pet: %s\n", PET.especie);

}
void arquivoCadPet(void){
  FILE *gravarCadPET;
  gravarCadPET = fopen("CadastroPET.txt","w");
  fprintf(gravarCadPET, "NOME PET: %s\n", PET.nome);
  fprintf(gravarCadPET, "IDADE PET: %d\n", PET.idade);
  fprintf(gravarCadPET, "SEXO PET: %c\n", PET.sexo);
  fprintf(gravarCadPET, "ESPECIE PET: %s\n", PET.especie);
  fclose(gravarCadPET);
}


int telaDeletarPet(void){
    
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

    int escolha;
    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int telaEditarPet(void){

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
    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int telaPesquisarPet(void){
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

    int escolha;
    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);
    return escolha;

}