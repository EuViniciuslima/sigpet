
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloUsuario.h"
#include "util.h"

typedef struct usuario Usuario;

void navUsuario(void)
{
    
    int opcao;
    do
    {
        opcao = menuUsuario();
        switch (opcao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            pesquisarUsuario();
            break;
        case 3:
            editarUsuario();
            break;
        case 4:
            deletarUsuario();
            break;
        }
        
    } while (opcao != 0);
    
}

void pesquisarUsuario(void)
{
    telaPesquisarUsuario();
}
void cadastrarUsuario(void)
{
    Usuario* usu;
    usu = telaCadastrarUsuario();
    gravarUsuario(usu);
    free(usu);
}
void editarUsuario(void)
{
    telaEditarUsuario();
}
void deletarUsuario(void)
{
    telaDeletarUsuario();
}

int menuUsuario(void)
{

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
    do{ 
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        return escolha;
    }while(!validaNav(&escolha));
  
}

Usuario* telaCadastrarUsuario()
{   
    Usuario *usu;
    usu = (Usuario*)malloc(sizeof(Usuario));
    
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
    do
    {
        printf("///           Nome:");
        scanf(" %255[^\n]", usu->nome);
        if(validaNome(usu->nome) == 0){
            printf("Nome Inválido\n");
        }
    }while(!validaNome(usu->nome));
    do
    {
        printf("///           Email:");
        scanf(" %255[^\n]", usu->email);
        if(validaEmail(usu->email) == 0){
            printf("Email Invalido\n");
        }
    } while (!validaEmail(usu->email));
    do
    {
        printf("///           Data de Nascimento:");
        scanf(" %255[^\n]", usu->data);
        if(validarData(usu->data) == 0){
            printf("Data Invalido\n");
        }
    } while (!validarData(usu->data));
   /* do
    {
        printf("///           CEP (Apenas Numeros):");
        scanf(" %[0-9]", usu->cep);
        validaCep(usu->cep);
        maskCep(usu->cep);
        if(validaCep(usu->cep) == 0){
            printf("CEP Invalido\n");
        }
    } while (!validaCep(usu->cep));
    do
    {
        printf("///            Phone (Apenas Numeros):");
        scanf(" %[0-9]", telefone);
        getchar();
        validaPhone(telefone);
        maskPhone(telefone);
        if(validaPhone(telefone) == 0){
            printf("Telefone Invalido\n");
        }
    } while (!validaPhone(telefone));*/
    do
    {
        printf("///            CPF (Apenas Numeros):");
        scanf(" %255[^\n]", usu->cpf);
        maskCpf(usu->cpf);
        if(validaCpf(usu->cpf) == 0){
            printf("CPF Invalido\n");
        }
    } while (!validaCpf(usu->cpf));/*
    do
    {
        printf("///            RG (Apenas Numeros):");
        scanf(" %[0-9]", rg);
        getchar();
        validaRg(rg);
        maskRg(rg);
        if(validaRg(rg) == 0){
            printf("RG Invalido\n");
        }

    } while (!validaRg(rg));
   */
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    //int escolha;
    //printf("Escolha: ");
    //scanf("%d", &escolha);
    exibirUsuario(usu);
    return usu;
    
}

int telaPesquisarUsuario(void)
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

int telaEditarUsuario(void)
{

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

int telaDeletarUsuario(void)
{

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

void exibirUsuario(const Usuario* usu){
    printf("Nome: %s\n", usu->nome);
    printf("Email: %s\n", usu->email);
    printf("CPF: %s\n", usu->cpf);
}

void gravarUsuario(Usuario* usu){
    FILE *grv;
    grv = fopen("USUARIO_CADASTRADOS.dat", "ab");
    //arquivos .dat são aqueles que contém dados
    //ab = Acrescenta dados binários no fim do arquivo
    fwrite(usu, sizeof(Usuario), 1, grv); //gravação de binários
    fclose(grv);
} 