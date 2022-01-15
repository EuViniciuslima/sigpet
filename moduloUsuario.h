
void navUsuario(void);
int menuUsuario(void);

typedef struct usuario Usuario;




struct usuario
{
    
    char nome[50];
    char cpf[15];
    char email[50];
    char telefone[12];
    char data[10];
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