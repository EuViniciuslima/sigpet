
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
            editarUsuario();
            break;
        case 3:
            pesquisarUsuario();
            break;
        case 4:
            deletarUsuario();
            break;
        }
    } while (opcao != 0);
}

void pesquisarUsuario(void)
{
    Usuario *usu;
    char *pesquise;
    pesquise = telaPesquisarUsuario();
    usu = buscarUsuario(pesquise);
    exibirUsuario(usu);
    free(usu);
    free(pesquise);
}
void cadastrarUsuario(void)
{
    Usuario *usu;
    usu = telaCadastrarUsuario();
    gravarUsuario(usu);
    free(usu);
}
void editarUsuario(void)
{
    Usuario *usu;
    char *alterar;
    alterar = telaEditarUsuario();
    usu = buscarUsuario(alterar);
    alterarUsuario(usu);
    free(usu);
    free(alterar);
}
void deletarUsuario(void)
{
    Usuario *usu;
    char *deletar;
    deletar = telaDeletarUsuario();
    usu = buscarUsuario(deletar);
    excluirUsuario(usu);
    free(usu);
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
    do
    {
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        return escolha;
    } while (!validaNav(&escolha));
}

Usuario *telaCadastrarUsuario()
{
    Usuario *usu;
    usu = (Usuario *)malloc(sizeof(Usuario));
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
        if (validaNome(usu->nome) == 0)
        {
            printf("Nome Inválido\n");
        }
    } while (!validaNome(usu->nome));
    do
    {
        printf("///           Email:");
        scanf(" %255[^\n]", usu->email);
        if (validaEmail(usu->email) == 0)
        {
            printf("Email Invalido\n");
        }
    } while (!validaEmail(usu->email));
    do
    {
        printf("///           Data de Nascimento:");
        scanf(" %255[^\n]", usu->data);
        if (validarData(usu->data) == 0)
        {
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
        if (validaCpf(usu->cpf) == 0)
        {
            printf("CPF Invalido\n");
        }
    } while (!validaCpf(usu->cpf)); /*
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
    // int escolha;
    // printf("Escolha: ");
    // scanf("%d", &escolha);
    usu->status = 'o';
    return usu;
}

char *telaPesquisarUsuario(void)
{
    char *pesquise;
    pesquise = (char *)malloc(14 * sizeof(char));

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
    printf("///           Pesquisar por cpf:   ");
    scanf(" %[0-9]", pesquise);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return pesquise;
}

char *telaEditarUsuario(void)
{

    char *alterar;
    alterar = (char *)malloc(14 * sizeof(char));

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
    printf("///            Cpf:  ");
    scanf(" %[0-9]", alterar);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return alterar;
}

char *telaDeletarUsuario(void)
{
    char *deletar;
    deletar = (char *)malloc(14 * (sizeof(char)));

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
    printf("///       Deletar Usuario:  ");
    scanf(" %[0-9]", deletar);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    return deletar;
}
// const é utilizado para que não se altere os dados do usuario enquanto
// estamos tentando exibir os dados
/*
Usuario* alterarUsuario(void){

}*/

void gravarUsuario(Usuario *usu)
{
    FILE *grv;
    grv = fopen("usuarios_cadastrados.dat", "ab");
    // arquivos .dat são aqueles que contém dados
    // ab = Acrescenta dados binários no fim do arquivo
    //  verificamos se o arquivo nao está vazio
    if (grv == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }
    fwrite(usu, sizeof(Usuario), 1, grv); // gravação de binários
    fclose(grv);
}

Usuario *buscarUsuario(char *pesquise)
{
    FILE *busca;

    Usuario *usu;
    usu = (Usuario *)malloc(sizeof(Usuario));

    busca = fopen("usuarios_cadastrados.dat", "rb");
    // rb = leitura de binários
    if (busca == NULL)
    {
        printf("Ocorreu um erro durante a abertura do arquivo");
        exit(1);
    }
    // feof verifica se o apontador chegou no final do arquivo já que
    // essa leitura é feita em camadas
    while (!feof(busca))
    {
        fread(usu, sizeof(Usuario), 1, busca); // ler os bites que foram gravados
                                               /* if ((strcmp(usu->nome, pesquise_nome)) == 0 && (usu->status != 'x'))
                                                {
                                                    fclose(busca);
                                                    return usu;
                                                }
                                                */
        if ((strcmp(usu->cpf, pesquise)) == 0 && (usu->status != 'x'))
        {
            fclose(busca);
            return usu;
        }
    }
    fclose(busca);
    return NULL;
}

void exibirUsuario(const Usuario *usu)
{
    if (usu->status == 'x' || usu == NULL)
    {
        printf("Usuario Inexistente");
    }
    else
    {
        printf("======================= RESULTADOS ENCONTRADOS =========================");
        printf("\n");
        printf("===    Nome: %s\n", usu->nome);
        printf("===    Email: %s\n", usu->email);
        printf("===    CPF: %s\n", usu->cpf);
        printf("===    Data de Nascimento: %s\n", usu->data);
    }
}

Usuario *excluirUsuario(Usuario *confirmLeitura)
{
    FILE *del;
    Usuario *usu;
    // char cpf;
    int achou = 0;

    if (confirmLeitura == NULL)
    {
        printf("Usuario nao cadastrado");
    }
    else
    {
        usu = (Usuario *)malloc(sizeof(Usuario));
        del = fopen("usuarios_cadastrados.dat", "r+b");
        if (del == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(del))
        {
            fread(usu, sizeof(Usuario), 1, del);
            if ((strcmp(usu->cpf, confirmLeitura->cpf) == 0) && (usu->status) != 'x')
            {
                achou = 1;
                usu->status = 'x';
                fseek(del, -1 * sizeof(Usuario), SEEK_CUR);
                fwrite(usu, sizeof(Usuario), 1, del);
                fclose(del);
                printf("\n ========================== Usuario excluido com sucesso ==========================\n");
                return usu;
            }
        }
        if (!achou)
        {
            printf("Usuario nao encontrado");
        }
        fclose(del);
    }
    return usu;
}

Usuario *alterarUsuario(Usuario *confirmLeitura)
{
    FILE *alt;
    Usuario *usu;
    // char cpf;
    int achou = 0;
    char nome[50];
    char email[50];
    char data[10];

    if (confirmLeitura == NULL)
    {
        printf("Usuario nao cadastrado");
    }
    else
    {
        usu = (Usuario *)malloc(sizeof(Usuario));
        alt = fopen("usuarios_cadastrados.dat", "r+b");
        if (alt == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(alt))
        {
            fread(usu, sizeof(Usuario), 1, alt);
            if ((strcmp(usu->nome, confirmLeitura->nome) == 0) && (usu->status) != 'x')
            {
                achou = 1;
                do{

                    printf("\n =============================== ALTERANDO DADOS ==================================\n");
                    printf("////        Nome: ");
                    scanf(" %256[^\n]", nome);
                    if(validaNome(nome) == 0){
                        printf("Nome invalido\n");
                    }
                  
                }while(!validaNome(nome));
                do{
                    printf("////        Email: ");
                    scanf(" %256[^\n]", email);
                    if(validaEmail(email) == 0){
                        printf("Email invalido\n");
                    }

                }while(!validaEmail(email));
                do{
                    printf("////        Data de Nascimento: ");
                    scanf(" %256[^\n]", data);
                    if(validarData(data) == 0){
                        printf("Data invalida\n");
                    }
                }while(!validarData(data));
               

                strcpy(usu->nome, nome);
                strcpy(usu->email, email);
                strcpy(usu->data, data);

                fseek(alt, -1 * sizeof(Usuario), SEEK_CUR);
                fwrite(usu, sizeof(Usuario), 1, alt);
                fclose(alt);
                printf("\n ========================== Usuario alterado com sucesso ==========================\n");
                return usu;
            }
        }
        if (!achou)
        {
            printf("Usuario nao encontrado");
        }
        fclose(alt);
    }
    return usu;
}