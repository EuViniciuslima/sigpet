
void navUsuario(void);
int menuUsuario(void);

typedef struct usuario Usuario;


typedef struct{
    char cep[10];
    char  rg[12];
    char uf[2];
}endereco;

struct usuario
{
    char nome[50];
    char cpf[15];
    char email[50];
    char telefone[12];
    endereco Endereco;
};



int telaPesquisarUsuario(void);
int telaDeletarUsuario(void);
Usuario* telaCadastrarUsuario();
int telaEditarUsuario(void);

void exibirUsuario(const Usuario *);
void validacao(void);

void pesquisarUsuario(void);
void editarUsuario(void);
void cadastrarUsuario(void);
void deletarUsuario(void);
