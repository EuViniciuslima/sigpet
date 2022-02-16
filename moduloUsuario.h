
void navUsuario(void);
int menuUsuario(void);
void relatorioUsuario(void);
int telaListarUsuario(void);

typedef struct usuario Usuario;

struct usuario
{

    char nome[81];
    char cpf[16];
    char email[41];
    char telefone[13];
    char data[11];
    char uf[4];
    char cidade[45];
    char status;
    struct usuario *prox;
};

void listaDinamica(void);
void exibirLista(const Usuario*);
char *telaPesquisarUsuario(void);
char *telaDeletarUsuario(void);
Usuario *telaCadastrarUsuario();
char *telaEditarUsuario(void);

void exibirUsuario(const Usuario *);
void gravarUsuario(Usuario *);

Usuario *buscarUsuario(char *);

void pesquisarUsuario(void);
void editarUsuario(void);
void cadastrarUsuario(void);
void deletarUsuario(void);
void listarUsuario(void);
void listarUsuarioporUF(void);
void listarUsuarioporCidade(void);

Usuario *excluirUsuario(Usuario *);
Usuario *alterarUsuario(Usuario *);
void DelFisicUsuario(void);

void listarNovoArquivo(void);
void listarTudo(void);
void ReposicionandoUsuario(void);
void gerarRelatorio(Usuario **);