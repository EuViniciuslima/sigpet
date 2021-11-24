///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///           Projeto Sistema de Agendamento de Consultas para Pets         ///
///                Developed by  @OliveiraAnna99 - Out, 2021                ///
///                Developed by  @EuViniciuslima - Out, 2021                ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Primeira Tela
void telaInicial(void);

//Derivação da primeira tela
void telaLogin(void);
void telaCadastro(void);

//Derivação da tela Login
void telaMenu(void);

//Bifurcações da tela Menu
void moduloPet(void); 
void moduloConsulta(void);
void moduloUsuario(void);
void infoMenu();


// Tela CRUD Modulo PET
void telaCadadastrarPet(void);
void telaEditarPet(void);
void telaPesquisarPet(void);
void telaDeletarPet(void);

// Tela CRUD Modulo Consulta
void telaCadadastrarConsulta(void);
void telaEditarConsulta(void);
void telaPesquisarConsulta(void);
void telaDeletarConsulta(void);

// Tela CRUD Modulo Usuario
void telaCadadastrarUsuario(void);
void telaEditarUsuario(void);
void telaPesquisarUsuario(void);
void telaDeletarUsuario(void);

//funções CRUD modulo PET
void insertPet(char*, int*, char*, char*);
void updatePet(void);
void selectPet(void);
void deletePet(void);


//funções CRUD modulo Consulta
void insertConsulta(void);
void updateConsulta(void);
void selectConsulta(void);
void deleteConsulta(void);


//funções CRUD modulo Usuario
void insertUsuario(void);
void updateUsuario(void);
void selectUsuario(void);
void deleteUsuario(void);

void telaEquipe(void);
void telaSobre(void);


void cadastroUsuario(char*);


//validação das credencias para realizar o login
void efetuarLogin(void);
void validEmail(int*, char*) ;

//Sistema de decisões para navegabilidade do sistema
void fluxoTela();
void escolhaPet();
void escolhaConsulta();
void escolhaUsuario();
void escolhaInfo();


#define MAX_USUARIOS 25
#define MAX_PETS 50



int main(void){

    int op;
    
    telaInicial();

    printf("Digite a opção: \n1. Login\n2. Cadastrar-se\nEscolha: ");
    scanf("%d", &op); // Capturando as informações do teclado e armazenando na variavel escolha;
  
    switch(op){

      case 1: 
        telaLogin();
        break;

      case 2:
        telaCadastro();
        break;

      default:
        printf("Selecione uma das opções acima! ");
        telaInicial();
    }

    return 0;
}


//Primeira Tela da Aplicação
void telaInicial(void)
{
    system("clear"); //Limpar Prompt 
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1.LOGIN                                                      ///\n");
    printf("///            2.CADASTRE-SE                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}



void efetuarLogin(){

    int Stop = 1;
    do{
        
      FILE *validLogin;
      validLogin = fopen("validacao.txt", "w");

      printf("Digite o seu email: ");
      char email_log[30]; //Criação da váriavel
      scanf("%s", email_log); //Leitura dos valores do teclado e armazenamento na variavel email_log (0.3)
      fprintf(validLogin, "%s \n", email_log);


      printf("Digite o sua senha: ");
      char senha_log[10];
      scanf("%s", senha_log);
      fprintf(validLogin, "%s \n", senha_log);
      fclose(validLogin);
      //Criando variaveis para armazenar os valores já cadastrados e compara-los
      char email[30];
      char senha[10];

      

      FILE *pontLeitura; //Criando ponteiro
      pontLeitura = fopen("cadastro_usuario.txt" , "r" ); //Leitura
      fgets (email, 30 , pontLeitura); //Capturando os valores do arquivo txt
      fgets (senha, 10 , pontLeitura);
      fclose(pontLeitura);

      FILE *pontValid;
      pontValid = fopen("validacao.txt","r");
      fgets (email_log, 30, pontValid);
      fgets (senha_log, 10, pontValid);
      fclose(pontValid);
      // utilizado em testes
      //int tamanhoEmail; 
      //int tamanhoSenha;
      //int tEmailLog;

      //tamanhoEmail = strlen(email);
      //tamanhoSenha = strlen(senha);
      //tEmailLog = strlen(email_log);
      //printf("Tamanho senha: %d\n", tamanhoSenha);
      //printf("tamanho email: %d\n", tamanhoEmail);
      //printf("tamanho email_log: %d\n", tEmailLog);

      int compararEmail;
      compararEmail = strcmp(email, email_log);
      //A Função strcmp retorna 0 quando as strings são iguais

      int compararSenha;
      compararSenha = strcmp(senha, senha_log);
      //printf("%d", compararSenha);

    
      if(compararEmail == 0 && compararSenha == 0){

        Stop = 0;
        telaMenu();
      }
      else{
        printf("Email ou senha incorretos\n");
        
      }

    }while (Stop!=0);
    
    

}

//Bifurcação da primeira tela (telaInicial), Login 
void telaLogin(void)
{
    system("clear"); //Limpar Prompt 
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            Email:                                                       ///\n");
    printf("///            Senha:                                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    efetuarLogin();
    
}


void insertUsuario(void){
  int emailValidado = 0;
  FILE *pontGravar;
  pontGravar = fopen("cadastro_usuario.txt", "w"); //criando arquivo para gravação dos dados do usuário
  char email[30];


  do{
  
    printf("Digite o seu email: ");
    scanf("%s", email); 

    int arroba = 0;
    int ponto = 0;
    int cont;

  
    int tamanho = strlen(email);
    for(cont = 0; cont < tamanho; cont ++){      
      if(email[cont] == '@'){
        arroba = 1; 
      }

      if(email[cont] == '.'){
        ponto = 1;
      } 
    }

    if(ponto == 1 && arroba == 1){
      emailValidado  = 1;
    }
    else{
      printf("\nEmail Invalido\n");
    }
  }while(emailValidado !=1);
      
      char senha[10];
      printf("Digite a sua senha: ");
      scanf("%s", senha); // Fazendo a leitura do numero digitado acima 0.3

      fprintf(pontGravar, "%s \n", email);
      fprintf(pontGravar, "%s \n", senha);
      fclose(pontGravar);
      
  
      printf("1. Login\n2. Sair\nEscolha:  ");
      int escolha;
      scanf("%d", &escolha); // Fazendo a leitura do numero digitado acima 0.3
      if (escolha == 1){
        telaLogin();
      }
      if (escolha == 2){
        moduloPet();
      }
      else{
          printf("Selecione uma das opções acima\n");
      }
    // }
}
    


//void validEmail(int *emailValidado){
  //int ponto = 0;
  //int arroba = 0;
 // int caracterEspecial = 0;

 // char analisarEmail[20];
 // strcpy(analisarEmail, &email);
        //destino      //origem
 // int tamanho;
  //tamanho = strlen(analisarEmail);
  //int contador;     
 // for (contador = 0; contador < tamanho; contador++){
   // if(strcmp(analisarEmail[contador], ".") == 0){
     // ponto = 1;
    //}

    //if(strcmp(analisarEmail[contador], "@") == 0){
      //arroba = 1;
    //}


    //if(ponto == 1 && arroba == 1){
      //*emailValidado = 1;
     
    //}
  //}
//}

void telaCadastro(void)
{
    system("clear");
    printf("\n");
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1.Email:                                                     ///\n");
    printf("///            2.Senha:                                                     ///\n");
    printf("///            3.Confirme a senha:                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    insertUsuario();
}



//Tela que sucede a telaLogin
void telaMenu(void){
    system("clear");
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

    fluxoTela();
}

void telaEquipe(void)
{
    system("clear");
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

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        infoMenu();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }
}

// Tela de "cadastrar pet" está pronta. (disponível para alterações no código "linha 301")
void moduloPet(void){
    //system("clear");
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

    escolhaPet();
}

// telaCad_Pet sendo elaborada, mas até o momnento funcionando. Após o cadastro do animal ele irá voltar pra telaPet.

void telaCadastrarPet(void){

    //system("clear");
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

    
    int cadastrandoPet =1;
    
    
    while(cadastrandoPet == 1){
      printf("Deseja Cadastrar Seu Pet? \n1. Cadastrar \n0. Voltar \nSua Escolha: ");
      scanf("%d", &cadastrandoPet);

      if(cadastrandoPet == 0){
        moduloPet();
      }

      else{
        char nomePet[20];
        printf("Digite o nome do animal: ");
        scanf("%s", nomePet);
      
        int idadePet;
        printf("Digite a idade do animal: ");
        scanf("%d", &idadePet);

        char sexoPet[1];
        printf("Digite o sexo do animal:\t");
        scanf("%s", sexoPet);

        char especiePet[15];
        printf("Digite a especie do animal:\t");
        scanf("%s", especiePet);

        
        insertPet(nomePet, &idadePet, sexoPet, especiePet);
      }

      
    }
      

     
}

void telaSobre(void)
{
    system("clear");
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

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        infoMenu();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }

    
}

void telaPesquisarPet(void){
    system("clear");

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

    int executar = 0;
    while (executar != 1){
      printf("Pesquisar por:");
      char pesquisa[20];
      scanf("%s", pesquisa);

      //FILE *pontPesquisa;
      //pontPesquisa = fopen("cadastro_pet.txt", "r");

      int escolha;

      printf("1. Continuar Pesquisa \n0. Voltar \nEscolha: ");
      scanf("%d", &escolha);


      if(escolha == 0){
        executar = 1;
        moduloPet();
      }

      if(escolha != 1 && escolha != 0){
        printf("Opção selecionada é invalida, escolha uma das ações acima");
        telaPesquisarPet();
      }
      
    }
    getchar();

}

void telaEditarPet(void){
    system("clear");
    
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
    printf("\n");

    //updatePet();
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloPet();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
       
    }
}

void telaDeletarPet(void){
    system("clear");
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
    printf("\n");

    
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloPet();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }
}

void moduloConsulta(void){
    system("clear");
    printf("                                                                          - □ x\n");
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
    printf("///            1. Cadastrar Consulta                                        ///\n");
    printf("///            2. Pesquisar Consulta                                        ///\n");
    printf("///            3. Editar Consulta                                           ///\n");
    printf("///            4. Apagar Consulta                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    escolhaConsulta();
}

void moduloUsuario(void){
    system("clear");
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
    printf("///            1. Cadastrar Novo Usuário                                    ///\n");
    printf("///            2. Editar Usuário                                            ///\n");
    printf("///            3. Pequisar Usuário                                          ///\n");
    printf("///            4. Apagar Usuário                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    escolhaUsuario();

   
}

void telaCadastrarUsuario(void){
    system("clear");
    
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
    

   

    char nomeUsuarioMod[20];
    printf("Preencha o Formulario\n");
    printf("Nome Usuario: ");
    scanf("%s", nomeUsuarioMod);

    cadastroUsuario(nomeUsuarioMod);
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloUsuario();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }
}

void cadastroUsuario(char *nomeUsuarioMod){
 //utilizando o ponteiro * : estamos referenciando a variavel da função anterior
 //desse

    FILE *modUsuarioCad;
    modUsuarioCad = fopen("ModCadastroUsuario.txt", "w");
    fprintf(modUsuarioCad, "NOME USUARIO: %s", nomeUsuarioMod);
    fclose(modUsuarioCad);
    
}


void telaEditarUsuario(void){
    system("clear");
    printf("                                                                          - □ x\n");
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

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloUsuario();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
       
    }
}

void telaDeletarUsuario(void){
    system("clear");
    printf("                                                                          - □ x\n");
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
    printf("///        1.Nome  2.Email  3.Telefone  4.Bairro  5.Cidade / Filtrar        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///        6. Sair                                        7. excluir        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloUsuario();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }
}

void telaCadastrarConsulta(void){
    system("clear");
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

    int escolha;
    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloConsulta();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
       
    }
}

void telaPesquisarConsulta(void){

    system("clear");
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
    printf("\n");
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloConsulta();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }
}

void telaEditarConsulta(void){

    system("clear");
    
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
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloConsulta();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
        
    }
}

void telaDeletarConsulta(void){

    system("clear");
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
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloConsulta();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
       
    }
}

void telaPesquisarUsuario(void){
    system("clear");
    char pesquisa[50];
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
    printf("///           = = = = = = = = Pesquisar Usuario = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///           Pesquisar:                                                    ///\n");

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Pesquisa: ");
    scanf("%s", pesquisa); // Fazendo a leitura do numero digitado acima direcionando ao if 0.3
    int escolha;

    printf("0. Voltar \nEscolha: ");
    scanf("%d", &escolha);


    if(escolha == 0){
        moduloUsuario();
    }
    else{
        printf("Opcao Invalida! Selecione uma das opcoes acima\n");
      
    }
}

void insertPet(char *nomePet, int* idadePet, char *sexoPet, char* especiePet){

  

    FILE *pontGravar; //criando ponteiro
    pontGravar = fopen("INSERT_PET.txt", "a"); //criando arquivo
    char organizador[60] = "=======================================\n";
    fprintf(pontGravar, "%s\n", organizador);
    fprintf(pontGravar, "NOME: %s\n", nomePet);
    fprintf(pontGravar, "IDADE: %d\n", *idadePet);
    fprintf(pontGravar, "SEXO: %s\n", sexoPet);
    fprintf(pontGravar, "ESPECIE: %s\n", especiePet);

    fclose(pontGravar);
  
}


// AINDA NÃO ESTÁ FUNCIONANDO CORRETAMENTE

void updatePet(void){

    FILE *pont_editar;
    pont_editar = fopen("cadastro_pet.txt", "r+");

    long qbitpulados = 40;
    int origem = 1;

    fseek(pont_editar, qbitpulados, origem);

    char nome_pet[60];
    printf("Digite o nome do seu animal: ");
    scanf("%s", nome_pet);
    fprintf(pont_editar, "EMAIL: %s\n", nome_pet);
}

void infoMenu(void){
    system("clear");
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");


    escolhaInfo();
}

void fluxoTela(){

  int escolhaMenu;
  printf("Escolha: ");
  scanf("%d", &escolhaMenu);

  switch(escolhaMenu){
    case 1:
      moduloPet();
      break;

    case 2:
      moduloConsulta();
      break;

    case 3:
      moduloUsuario();
      break;
    
    case 4: 
      infoMenu();
      break;
  }

}

void escolhaPet(){
  
  int escolhaPet;
  printf("Escolha: ");
  scanf("%d", &escolhaPet);

  switch(escolhaPet){
    case 1:
      telaCadastrarPet();
      break;

    case 2:
      telaPesquisarPet();
      break;

    case 3:
      telaEditarPet();
      break;
    
    case 4: 
      telaDeletarPet();
      break;
    
    case 0:
      telaMenu();
      break;
    
    default:
      printf("Selecione uma das opcoes acima");
  }
}



void escolhaConsulta(){
  
  int escolhaConsulta;
  printf("Escolha: ");
  scanf("%d", &escolhaConsulta);

  switch(escolhaConsulta){
    case 1:
      telaCadastrarConsulta();
      break;

    case 2:
      telaPesquisarConsulta();
      break;

    case 3:
      telaEditarConsulta();
      break;
    
    case 4: 
      telaDeletarConsulta();
      break;
    
    case 0:
      telaMenu();
      break;
    
    default:
      printf("Selecione uma das opções acima");
  }
}



void escolhaUsuario(){
  
  int escolhaUsuario;
  printf("Escolha: ");
  scanf("%d", &escolhaUsuario);

  switch(escolhaUsuario){
    case 1:
      telaCadastrarUsuario();
      break;

    case 2:
      telaPesquisarUsuario();
      break;

    case 3:
      telaEditarUsuario();
      break;
    
    case 4: 
      telaDeletarUsuario();
      break;
    
    case 0:
      telaMenu();
      break;
    
    default:
      printf("Selecione uma das opções acima");
  }
}



void escolhaInfo(){
  
  int escolhaInfo;
  printf("Escolha: ");
  scanf("%d", &escolhaInfo);

  switch(escolhaInfo){
    case 1:
      telaSobre();
      break;

    case 2:
      telaEquipe();
      break;

    case 0:
      telaMenu();
      break;

    default:
      printf("Selecione uma das opções acima");
  }
}