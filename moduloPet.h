
struct Pet {
    char nome[20];
    int idade;
    char sexo;
    char especie[15];
};

void navPet(void);

void cadastrarPet(void);
int telaCadastrarPet(void);
void deletarPet(void);
int telaDeletarPet(void);
void pesquisarPet(void);
int telaPesquisarPet(void);
void editarPet(void);
int telaEditarPet(void);

int menuPet(void);


void validaDadosPet(void);
void structPet(int*, char*, char*, char*);
void exibirCadastroStructPet(void);

void arquivoCadPet(void);
