void pesquisarUsuario(void);
void editarUsuario(void);
void cadastrarUsuario(void);
void deletarUsuario(void);

void navUsuario(void);
int menuUsuario(void);

typedef struct Usuario USU;

struct Usuario{
    char nome[50];
    char cpf[15];
    char email[50];
    char cep[10];
    char rg[12];
    char telefone[12];
 
};

int telaPesquisarUsuario(void);
int telaDeletarUsuario(void);
int telaCadastrarUsuario(void);
int telaEditarUsuario(void);


void validacao(void);

