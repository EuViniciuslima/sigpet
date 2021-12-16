
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
    char data[10];
    endereco Endereco;
    char status;
};



char* telaPesquisarUsuario(void);
char* telaDeletarUsuario(void);
Usuario* telaCadastrarUsuario();
char* telaEditarUsuario(void);

void exibirUsuario(const Usuario *);
void gravarUsuario(Usuario* );

Usuario* buscarUsuario(char *);

void pesquisarUsuario(void);
void editarUsuario(void);
void cadastrarUsuario(void);
void deletarUsuario(void);
Usuario* excluirUsuario(Usuario *);
Usuario* alterarUsuario(Usuario *);