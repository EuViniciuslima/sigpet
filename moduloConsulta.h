void navConsulta(void);
int menuConsulta(void);

typedef struct consulta Consulta;

struct consulta
{
    char cadPaciente[15];
    char cadResponsavel[15];
    char cadDescricao[60];
    char cadData[10];
    char cadHorario[10];
};

void pesquisarConsulta(void);
void deletarConsulta(void);
void cadastrarConsulta(void);
void editarConsulta(void);

int telaPesquisarConsulta(void);
int telaDeletarConsulta(void);
Consulta* telaCadastrarConsulta(void);
int telaEditarConsulta(void);

void gravarConsulta(Consulta*);