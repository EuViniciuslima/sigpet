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
void listaDinamicaConsultaPaciente(void);
void listaDinamicaConsultaDono(void);


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

void listarTudoConsulta(void);
void listarConsultaporCpf(void);
void listarConsultaporData(void);

void ReposicionandoConsulta(void);
void DelFisicConsulta(void);

void exibirListaConsulta(const Consulta *);
void gerarRelatorioConsulta(Consulta **);
void gerarRelatorioConsulta2(Consulta **);