typedef struct pet Pet;

struct pet
{
    char nome[30];
    char data[10];
    char sexo[1];
    char especie[40];
    char dono[50];
};

void navPet(void);

void cadastrarPet(void);
Pet* telaCadastrarPet(void);
void deletarPet(void);
int telaDeletarPet(void);
void pesquisarPet(void);
int telaPesquisarPet(void);
void editarPet(void);
int telaEditarPet(void);
int telaListarPet(void);

int menuPet(void);

void validaDadosPet(void);
void structPet(int *, char *, char *, char *);
void exibirCadastroStructPet(void);

void arquivoCadPet(void);
void gravarPet(Pet* );
