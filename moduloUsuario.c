
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moduloUsuario.h"
#include "util.h"

typedef struct {
   char bairro[15];
   char cidade[10];
   char uf[2];
   char cep[9];
   int numeroResidencial;

}Endereco;


typedef struct {
    int idUsuario;
    char nome[30];
    int idade;
    char email[20];
    char cpf[14];
    char telefone[20];
    
    Endereco endereco;
}Usuario;



Usuario USU;
Endereco END;

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





void validacao(void){
   int emailValido = 0;
   int cpfValido = 0;
   int cepValido = 0;
   int telValido = 0;

   char email[20];
   char cpf[14];
   char cep[9];
   char telefone[10];
    
   //

   do{
    printf("Email: ");
    scanf("%s", email);
    validaEmail(email, &emailValido);
    if(emailValido == 0){
      printf("EMAIL INVALIDO!\n");
    }
   }while(emailValido != 1);
   do{
     printf("CPF: ");
     scanf("%s", cpf);
     validaCpf(cpf, &cpfValido);
     if(cpfValido == 0){
       printf("CPF INVALIDO\n");
     }
   }while(cpfValido != 1);
   do{
     printf("CEP: ");
     scanf("%s", cep);
     validaCep(cep, &cepValido);
     if(cepValido == 0){
       printf("CEP INVALIDO\n");
     }
   }while(cepValido != 1);
   do{
     printf("TEL: ");
     scanf("%s", telefone);
     validaPhone(telefone, &telValido);
     if(telValido == 0){
       printf("TELEFONE INVALIDO\n");
     }
   }while(telValido != 1);


    insertStructUsu(email, cpf, cep, telefone);
    exibirCadastroStruct();
}

void insertStructUsu(char *email, char *cpf, char *cep, char *telefone){

    strcpy(USU.email, email);
    strcpy(USU.cpf, cpf);
    strcpy(END.cep, cep);
    strcpy(USU.telefone, telefone);
    criarArquivoCadastro();
}

void criarArquivoCadastro(void){
  FILE *gravarCadUsu;
  gravarCadUsu = fopen("USUARIOS_CADASTRADOS.txt","w");
  fprintf(gravarCadUsu, "EMAIL: %s\n", USU.email);
  fprintf(gravarCadUsu, "CPF: %s\n", USU.cpf);
  fclose(gravarCadUsu);
}

void exibirCadastroStruct(void){
  
    printf("Email Registrado: %s\n", USU.email);
    printf("CPF Registrado: %s\n", USU.cpf);
   
}

int menuUsuario(void){
    
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
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
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///            Email:                                                     ///\n");
    printf("///            2. Senha                                                     ///\n");
    printf("///            3. Confirmacao de senha                                      ///\n");
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
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
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
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
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