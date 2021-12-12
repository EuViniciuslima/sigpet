void navConsulta(void);
int menuConsulta(void);

typedef struct Cadastro CONS;

struct Cadastro
{
    char cadConsult[13];
    char nomePaciente[15];
    char nomeRespon[15];
    char cadDescri[60];
};

void pesquisarConsulta(void);
void deletarConsulta(void);
void cadastrarConsulta(void);
void editarConsulta(void);

int telaPesquisarConsulta(void);
int telaDeletarConsulta(void);
int telaCadastrarConsulta(void);
int telaEditarConsulta(void);