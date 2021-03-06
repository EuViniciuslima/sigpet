#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "moduloPet.h"
#include "util.h"
void copyPet(FILE *, FILE *);
void recolocandoPet(FILE *, FILE *);

typedef struct pet Pet;

void navPet(void)
{
    int opcao;
    int opc;
    // do
    //{
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
    case 5:
        opc = telaListarPet();
        // do
        //{
        switch (opc)
        {
            case 1:
                listarPet();
                break;
            case 2:
                listarPorSexoPet();
                break;
            case 3:
                listarPorEspeciePet();
                break;
            case 4:
                listarTudoPet();
                break;
            case 5:
                listaDinamicaPet();
                break;
        }

        //} while (opc != 0);
        break;
    case 6:
        ReposicionandoPet();
        break;
    }

    //} while (opcao != 0);
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
    printf("///            5. Listar Pet                                                ///\n");
    printf("///            6. Apagar Permanentemente Pet                                ///\n");
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

void cadastrarPet(void)
{
    Pet *pet;
    pet = telaCadastrarPet();
    gravarPet(pet);
    free(pet);
}

void pesquisarPet(void)
{
    Pet *pet;
    char *pesquise;
    pesquise = telaPesquisarPet();
    pet = buscarPet(pesquise);
    exibirPet(pet);
    free(pet);
    free(pesquise);
}
void editarPet(void)
{
    Pet *pet;
    char *alterar;
    alterar = telaEditarPet();
    pet = buscarPet(alterar);
    alterarPet(pet);
    free(pet);
    free(alterar);
}
void listaDinamicaPet(void){
    Pet *pet;
    pet = NULL;
    gerarRelatorioPet(&pet);
    exibirListaPet(pet);
    free(pet);
}
void deletarPet(void)
{
    Pet *pet;
    char *deletar;
    deletar = telaDeletarPet();
    pet = buscarPet(deletar);
    excluirPet(pet);
    free(pet);
}

Pet *telaCadastrarPet(void)
{
    Pet *pet;
    pet = (Pet *)malloc(sizeof(Pet));
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
    do
    {
        printf("///            Nome do Pet:");
        scanf(" %29[^\n]", pet->nome);
        getchar();
    } while (!validaNome(pet->nome));
    do
    {
        printf("///            Sexo do Pet (f/m):");
        scanf(" %2[^\n]", pet->sexo);
        getchar();
        if (validaSexo(pet->sexo) == 0)
        {
            printf("Sexo Invalido\n");
        }
    } while (!validaSexo(pet->sexo));
    do
    {
        printf("///            Data de Nascimento - Pet:");
        scanf(" %9[^\n]", pet->data);
        getchar();
        if (validarData(pet->data) == 0)
        {
            printf("Data Invalida\n");
        }
    } while (!validarData(pet->data));
    do
    {
        printf("///            Especie do Pet:");
        scanf(" %39[^\n]", pet->especie);
        getchar();
    } while (!validaNome(pet->especie));
    do
    {
        printf("///            Dono:");
        scanf(" %49[^\n]", pet->dono);
        getchar();
    } while (!validaNome(pet->dono));

    do
    {
        printf("///            cpf dono do Pet:");
        scanf(" %14[^\n]", pet->cpf);
        getchar();
    } while (!validaCpf(pet->cpf));
    pet->status = 'o';

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
char *telaDeletarPet(void)
{
    char *deletePet;
    deletePet = (char *)malloc(15 * (sizeof(char)));
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
    printf("///            CPF dono do Pet:  ");
    scanf(" %14[^\n]", deletePet);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    return deletePet;
    /*printf("0. Voltar \nEscolha: ");
    int escolha;
    do
    {
      printf("Escolha: ");
      scanf("%d", &escolha);
      getchar();
      validaNav(&escolha);
      return escolha;
    } while (!validaNav(&escolha));*/
}

char *telaEditarPet(void)
{
    char *alterar;
    alterar = (char *)malloc(15 * sizeof(char));
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
    printf("///           Digite o CPF do usu??rio j?? cadastrado:  ");
    scanf(" %[0-9]", alterar);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    return alterar;
}

char *telaPesquisarPet(void)
{
    char *pesquise;
    pesquise = (char *)malloc(15 * sizeof(char));

    printf("                                                                          - ??? x\n");
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
    printf("///           Pesquisar CPF:   \n");
    scanf(" %[0-9]", pesquise);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return pesquise;
}

void gravarPet(Pet *pet)
{
    FILE *grvpet;
    grvpet = fopen("pets_cadastrados.dat", "ab");
    if (grvpet == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }

    fwrite(pet, sizeof(Pet), 1, grvpet);
    fclose(grvpet);
}

int telaListarPet(void)
{
    int opcpet;
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
    printf("///           = = = = = = = = = = Listar = = = = = = = = = =                ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///               [1] Listar Pets                                           ///\n");
    printf("///               [2] Listar Pets por sexo                                  ///\n");
    printf("///               [3] Listar Pets por especie                               ///\n");
    printf("///               [4] Listar Tudo (Excluidos e Registrados)                 ///\n");
    printf("///               [5] Lista Dinamica (Ordem Alfabetica)                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    do
    {
        printf("Escolha: ");
        scanf("%d", &opcpet);
        getchar();
        return opcpet;
    } while (!validaNav(&opcpet));
}

void exibirPet(const Pet *pet)
{

    printf("======================= RESULTADOS ENCONTRADOS =========================");
    printf("\n");
    printf("===    Nome: %s\n", pet->nome);
    printf("===    Data: %s\n", pet->data);
    printf("===    Sexo: %s\n", pet->sexo);
    printf("===    Esp??cie: %s\n", pet->especie);
    printf("===    Dono: %s\n", pet->dono);
    printf("===    CPF: %s\n", pet->cpf);
}

void listarPet(void)
{
    FILE *lst;
    Pet *pet;
    printf(" ============ Lista de Pet =============\n");
    pet = (Pet *)malloc(sizeof(Pet));
    lst = fopen("pets_cadastrados.dat", "rb");
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    //while (!feof(lst))
    //{

        while (fread(pet, sizeof(Pet), 1, lst))
        {
            if (pet->status != 'x')
            {
                exibirPet(pet);
            }
        }
        fclose(lst);
         // navPet();
    //}
}

void listarPorSexoPet(void)
{
    FILE *lst;
    Pet *pet;
    char sexoinfo[3];
    pet = (Pet *)malloc(sizeof(Pet));
    lst = fopen("pets_cadastrados.dat", "rb");
    printf(" ============ Lista de Pets por sexo =============\n");
    printf("Informe a Especie: ");
    scanf("%2[^\n]", sexoinfo);
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");

        exit(1);
    }
    while (!feof(lst))
    {
        while (fread(pet, sizeof(Pet), 1, lst))
        {
            if ((strcmp(pet->sexo, sexoinfo) == 0) && (pet->status != 'x'))
            {
                exibirPet(pet);
            }
        }
    }
    fclose(lst);
}

void listarPorEspeciePet(void)
{
    FILE *lst;
    Pet *pet;
    char especieinfo[40];
    pet = (Pet *)malloc(sizeof(Pet));
    lst = fopen("pets_cadastrados.dat", "rb");
    printf(" ============ Lista de Pets por especie =============\n");
    printf("Informe a Especie: ");
    scanf("%39[^\n]", especieinfo);
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");

        exit(1);
    }
    while (!feof(lst))
    {
        while (fread(pet, sizeof(Pet), 1, lst))
        {
            if ((strcmp(pet->especie, especieinfo) == 0) && (pet->status != 'x'))
            {
                exibirPet(pet);
            }
        }
    }
    fclose(lst);
}

void listarTudoPet(void)
{
    FILE *lst;
    Pet *pet;
    printf(" ============ Lista de Pets =============\n");
    pet = (Pet *)malloc(sizeof(Pet));
    lst = fopen("pets_cadastrados.dat", "rb");
    if (lst == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    while (!feof(lst))
    {
        while (fread(pet, sizeof(Pet), 1, lst))
        {
            exibirPet(pet);
        }
    }
    fclose(lst);
}

Pet *buscarPet(char *pesquise)
{
    FILE *busca;

    Pet *pet;
    pet = (Pet *)malloc(sizeof(Pet));

    busca = fopen("pets_cadastrados.dat", "rb");
    // rb = leitura de bin??rios
    if (busca == NULL)
    {
        printf("Ocorreu um erro durante a abertura do arquivo");
        exit(1);
    }
    // feof verifica se o apontador chegou no final do arquivo j?? que
    // essa leitura ?? feita em camadas
    while (!feof(busca))
    {
        fread(pet, sizeof(Pet), 1, busca);
        if ((strcmp(pet->cpf, pesquise)) == 0 && (pet->status != 'x'))
        {
            fclose(busca);
            return pet;
        }
    }
    fclose(busca);
    return NULL;
}

Pet *excluirPet(Pet *confirmLeitura)
{
    FILE *deletarPet;
    Pet *pet;
    // char nome;
    int achou = 0;

    if (confirmLeitura == NULL)
    {
        printf("Pet nao cadastrado");
    }
    else
    {
        pet = (Pet *)malloc(sizeof(Pet));
        deletarPet = fopen("pets_cadastrados.dat", "r+b");
        if (deletarPet == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(deletarPet))
        {
            fread(pet, sizeof(Pet), 1, deletarPet);
            if ((strcmp(pet->nome, confirmLeitura->nome) == 0) && (pet->status) != 'x')
            {
                achou = 1;
                pet->status = 'x';
                fseek(deletarPet, -1 * sizeof(Pet), SEEK_CUR);
                fwrite(pet, sizeof(Pet), 1, deletarPet);
                fclose(deletarPet);
                printf("\n ========================== Pet excluido com sucesso ==========================\n");
                return pet;
            }
        }
        if (!achou)
        {
            printf("Pet nao encontrado");
        }
        fclose(deletarPet);
    }
    return pet;
}

Pet *alterarPet(Pet *confirmLeitura)
{
    FILE *alt;
    Pet *pet;

    int achou = 0;
    char nome[30];
    char data[10];
    char sexo[3];
    char especie[40];
    char dono[50];

    if (confirmLeitura == NULL)
    {
        printf("Pet nao cadastrado");
    }
    else
    {
        pet = (Pet *)malloc(sizeof(Pet));
        alt = fopen("pets_cadastrados.dat", "r+b");
        if (alt == NULL)
        {
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(alt))
        {
            fread(pet, sizeof(Pet), 1, alt);
            if ((strcmp(pet->cpf, confirmLeitura->cpf) == 0) && (pet->status) != 'x')
            {
                achou = 1;
                do
                {
                    printf("\n =============================== ALTERANDO DADOS ==================================\n");

                    printf("///            Nome do Pet:");
                    scanf(" %29[^\n]", nome);
                    getchar();
                } while (!validaNome(nome));
                do
                {
                    printf("///            Sexo do Pet (f/m):");
                    scanf(" %2[^\n]", sexo);
                    getchar();
                    if (validaSexo(pet->sexo) == 0)
                    {
                        printf("Sexo Invalido\n");
                    }
                } while (!validaSexo(sexo));
                do
                {
                    printf("///            Data de Nascimento - Pet:");
                    scanf(" %9[^\n]", data);
                    getchar();
                    if (validarData(data) == 0)
                    {
                        printf("Data Invalida\n");
                    }
                } while (!validarData(data));
                do
                {
                    printf("///            Especie do Pet:");
                    scanf(" %39[^\n]", especie);
                    getchar();
                } while (!validaNome(especie));
                do
                {
                    printf("///            Dono:");
                    scanf(" %49[^\n]", dono);
                    getchar();
                } while (!validaNome(dono));

                strcpy(pet->nome, nome);
                strcpy(pet->sexo, sexo);
                strcpy(pet->data, data);
                strcpy(pet->especie, especie);
                strcpy(pet->dono, dono);

                fseek(alt, -1 * sizeof(Pet), SEEK_CUR);
                fwrite(pet, sizeof(Pet), 1, alt);
                fclose(alt);
                printf("\n ========================== Pet alterado com sucesso ==========================\n");
                return pet;
            }
        }
        if (!achou)
        {
            printf("Pet nao encontrado");
        }
        fclose(alt);
    }
    return pet;
}

void copyPet(FILE *read, FILE *fp)
{
    Pet *pet;
    pet = (Pet *)malloc(sizeof(Pet));

    while (!feof(read))
    {
        while (fread(pet, sizeof(Pet), 1, read))
        {
            if (pet->status != 'x')
            {
                fwrite(pet, sizeof(Pet), 1, fp);
            }
        }
    }
}

void recolocandoPet(FILE *read2, FILE *fp2)
{
    Pet *pet;
    pet = (Pet *)malloc(sizeof(Pet));

    while (!feof(read2))
    {
        while (fread(pet, sizeof(Pet), 1, read2))
        {

            fwrite(pet, sizeof(Pet), 1, fp2);
        }
    }
}

void DelFisicPet(void)
{
    FILE *read;
    read = fopen("pets_cadastrados.dat", "rb");
    if (read == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo ");
        exit(1);
    }
    FILE *fp;
    fp = fopen("PetsExistenes.dat", "wb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo 4");
        exit(1);
    }

    copyPet(read, fp);

    fclose(read);
    fclose(fp);
}

void ReposicionandoPet(void)
{
    DelFisicPet();
    FILE *read2;
    read2 = fopen("PetsExistenes.dat", "rb");
    if (read2 == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo 1");
        exit(1);
    }

    FILE *fp2;
    fp2 = fopen("pets_cadastrados.dat", "wb");
    if (fp2 == NULL)
    {
        printf("Ocorreu um erro! Nao foi possivel abrir o arquivo 2");
        exit(1);
    }

    recolocandoPet(read2, fp2);

    fclose(read2);
    fclose(fp2);
}

void exibirListaPet(const Pet *aux)
{

	
  printf("\n");
	while (aux != NULL)
	{
    	printf("%s\t\t\t",aux->nome);
    	printf("%s\t\t\t",aux->data);
    	printf("%s\n",aux->sexo);
    	printf("%s\n",aux->dono);
    	aux = aux->prox;
	}
	printf("\nFim da Lista! \n\n");
}



void gerarRelatorioPet(Pet **con)
{
    FILE *fp;
    Pet *al;
    
    //apagarLista(&(*lista));
    *con = NULL;
    fp = fopen("pets_cadastrados.dat","rb");
    if (fp == NULL)
    {
   	 printf("Erro na abertura do arquivo... \n");
   	 exit(1);
    }
    else
    {
   	 al = (Pet *) malloc(sizeof(Pet));
   	 while (fread(al, sizeof(Pet), 1, fp))
   	 {
        if ((*con == NULL) || (strcmp(al->nome, (*con)->nome) < 0)) {
          al->prox = *con;
          *con = al;
        } else  {
          Pet* ant = *con;
          Pet* atu = (*con)->prox;
          while ((atu != NULL) && (strcmp(atu->nome, al->nome) < 0)) {
            ant = atu;
            atu = atu->prox;
          }
          ant->prox = al;
          al->prox = atu;
        }
        al = (Pet *) malloc(sizeof(Pet));
   	 }
   	 free(al);
   	 printf("Arquivo recuperado com sucesso! \n");
   	 
    }  
    fclose(fp);
   
}
