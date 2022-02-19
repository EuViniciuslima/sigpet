typedef struct pet Pet;

struct pet
{
    char nome[30];
    char data[10];
    char sexo[3];
    char especie[40];
    char dono[50];
    char cpf[15];
    char status;
    struct pet *prox;
};

void navPet(void);

void cadastrarPet(void);
Pet *telaCadastrarPet(void);
void deletarPet(void);
char *telaDeletarPet(void);
void pesquisarPet(void);
char *telaPesquisarPet(void);
void editarPet(void);
char *telaEditarPet(void);
int telaListarPet(void);
void exibirPet(const Pet *);
Pet *alterarPet(Pet *);
void listarTudoPet(void);

int menuPet(void);

void validaDadosPet(void);
void structPet(int *, char *, char *, char *);
void exibirCadastroStructPet(void);
void editarPet(void);

void arquivoCadPet(void);
void gravarPet(Pet *);
void listarPet(void);
void deletarPet(void);
Pet *excluirPet(Pet *);
Pet *buscarPet(char *);
void DelFisicPet(void);
void ReposicionandoPet(void);
void listarPorSexoPet(void);
void listarPorEspeciePet(void);

void exibirListaPet(const Pet*);
void gerarRelatorioPet(Pet **);
void listaDinamicaPet(void);