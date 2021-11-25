
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloUsuario.h"

typedef struct {
    char nome[30];
    int idade;
    char email[20];
    char telefone[20];
    char bairro[15];
    int numeroResidencial;

}Usuario;

Usuario USU;

void navUsuario(void){
  int opcao;
  do{
    opcao = menuUsuario();
    switch(opcao){
      case 1: cadastrarUsuario();
      break;
      case 2: pesquisarUsuario();
      break;
      case 3: editarUsuario();
      break;
      case 4: deletarUsuario();
      break;
    }

  }while(opcao!= 0);
 
}

void pesquisarUsuario(void){
  telaPesquisarUsuario();
}
void cadastrarUsuario(void){
  telaCadastrarUsuario();
  validacao();
}
void editarUsuario(void){
  telaEditarUsuario();
}
void deletarUsuario(void){
  telaDeletarUsuario();
}



int validaEmail(char *email, int *emailValido){

    int arroba;
    int ponto;

    int tamanho = strlen(email);
    int contador;

    for(contador = 0; contador < tamanho; contador ++){
      if(email[contador] == '@'){
        arroba = 1;
      }
      if(email[contador] == '.'){
        ponto = 1;
      }
    }
    if(arroba == 1 && ponto == 1){
      *emailValido = 1;
    }
    return *emailValido;
}


void validacao(void){
   int emailValido = 0;

   char email[20];
   

    do{
      printf("Email: ");
      scanf("%s", email);
      
      validaEmail(email, &emailValido);

      if(emailValido == 0){
        printf("EMAIL INVALIDO!\n");
      }
    }while(emailValido != 1);

    insertStructUsu(email);
    exibirCadastroStruct();
}

void insertStructUsu(char *email){
  
    strcpy(USU.email, email);
    criarArquivoCadastro();
}

void criarArquivoCadastro(void){
  FILE *gravarCadADM;
  gravarCadADM = fopen("CadastroADM.txt","w");
  fprintf(gravarCadADM, "EMAIL: %s\n", USU.email);
  fclose(gravarCadADM);
}

void exibirCadastroStruct(void){
  
    printf("Email Registrado: %s\n", USU.email);
   
}

int menuUsuario(void){
    
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
    printf("///            1. Cadastrar Usuario                                         ///\n");
    printf("///            2. Editar Usuario                                            ///\n");
    printf("///            3. Pequisar Usuario                                          ///\n");
    printf("///            4. Apagar Usuario                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    int escolha;
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
   
}

int telaCadastrarUsuario(void){
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
    printf("///            1. Email                                                     ///\n");
    printf("///            2. Senha                                                     ///\n");
    printf("///            3. Confirmação de senha                                      ///\n");
    printf("///            4. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    int escolha;
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}


int telaPesquisarUsuario(void){
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
    printf("///           = = = = = = = = Pesquisar Usuario = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///           Pesquisar:                                                    ///\n");

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    
    int escolha;
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}



int telaEditarUsuario(void){
  
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
    printf("///            1. Alterar email                                             ///\n");
    printf("///            2. Alterar senha                                             ///\n");
    printf("///            3. Alterar número de telefone                                ///\n");
    printf("///            4. Alterar nome                                              ///\n");
    printf("///            5. Endereço                                                  ///\n");
    printf("///            6. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
  
    int escolha;
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;

}


int telaDeletarUsuario(void){
   
    
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
    printf("///        1.Nome  2.Email  3.Telefone  4.Bairro  5.Cidade / Filtrar        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///        6. Sair                                        7. excluir        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    int escolha;
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;


}