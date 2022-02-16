void navConsulta(void);
int menuConsulta(void);

typedef struct consulta Consulta;

struct consulta
{
    char cadPaciente[50];
    char cadResponsavel[50];
    char cadDescricao[60];
    char cadData[10];
    char cadHorario[10];
    char consCPF[14];
    char status;
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
void preencher(Consulta *);
void preencherNovamente(Consulta *);

