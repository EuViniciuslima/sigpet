typedef struct bancodados BancoDados;

struct bancodados{
    char ufBr[2][26];
};


int validaNav(int *);
int validaEmail(char *);
int validaCpf(char *);
int validaCep(char *);
int validaPhone(char *);
int validaRg(char *);
int validaNome(char *);
int validaSexo(char *);
void maskCpf(char *);
void maskData(char *);
void maskCep(char *);
void maskPhone(char *);
void maskRg(char *);
int ehDigito(char);
int ehLetra(char);
int ehSexo(char);
int ehBissexto(int);
int ehData(int, int, int);
int validarData(char *);
int validaUF(char*);