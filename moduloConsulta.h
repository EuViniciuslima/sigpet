void navConsulta(void);
int menuConsulta(void);

typedef struct consulta Consulta;

struct consulta
{
    char cadPaciente[50];
    char cadResponsavel[50];
    char cadDescricao[60];
    char cadData[12];
    //char cadHorario[12];
    char consCPF[15];
    char status;
    struct consulta *prox;
};

void pesquisarConsulta(void);
void deletarConsulta(void);
void cadastrarConsulta(void);
void editarConsulta(void);


char* telaPesquisarConsulta(void);
char* telaDeletarConsulta(void);
Consulta *telaCadastrarConsulta(void);
char* telaEditarConsulta(void);
int telaListarConsulta(void);

void gravarConsulta(Consulta *);
Consulta *excluirConsulta(Consulta *);
Consulta *alterarConsulta(Consulta *);
void listarConsulta(void);
void exibirConsulta(const Consulta *);
Consulta* buscarConsulta(char *);

