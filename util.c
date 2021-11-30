#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int validaCpf(char *cpf, int *cpfValido){
  int ponto = 0;
  int traco = 0;
  int tamanhoAdequado = 0;
  int tamanhoMaximo = 14;
  int isNumber = 0;
  int tamanhoCpf;
  int contador;

  
  tamanhoCpf = strlen(cpf);

  if(tamanhoCpf == tamanhoMaximo){
    tamanhoAdequado = 1;
    for(contador = 0; contador< tamanhoCpf; contador ++){
      if(cpf[3] == '.' && cpf[7] == '.'){
        ponto = 1;
      }
    
      if(cpf[11] == '-'){
        traco = 1;
      }

      if(isdigit(cpf[0]) && isdigit(cpf[1]) && isdigit(cpf[2]) && isdigit(cpf[4]) && isdigit(cpf[5]) && isdigit(cpf[6]) && isdigit(cpf[8]) && isdigit(cpf[9]) && isdigit(cpf[10]) && isdigit(cpf[12]) && isdigit(cpf[13])){
        isNumber = 1;
      }
    }
  }
  if(traco == 1 && ponto == 1 && tamanhoAdequado == 1 && isNumber ==1){
    *cpfValido = 1; 
  }
  return *cpfValido;
}


int validaEmail(char *email, int *emailValido){

    int arroba;
    int ponto;
    int tamanho = strlen(email);
    int contador;

    for(contador = 0; contador < tamanho; contador ++){
      if(email[contador] == '@'){
        arroba = 1;
      }
      if(email[contador] == '.'){
        ponto = 1;
      }
    }
    if(arroba == 1 && ponto == 1){
      *emailValido = 1;
    }
    return *emailValido;
}

int validaCep(char *cep, int *cepValido){
    int tamanhoCep;
    int isNumber = 0;
    int tamanhoAdequado = 0;
    int tamanhoMaximo = 9 ;
    int traco = 0;
    
    
    tamanhoCep = strlen(cep);

    if(tamanhoCep == tamanhoMaximo){
        tamanhoAdequado = 1;
    }
    if(cep[5] == '-'){
        traco = 1;
    }
    if(isdigit(cep[0]) && isdigit(cep[1]) && isdigit(cep[2]) && isdigit(cep[3]) && isdigit(cep[4]) && isdigit(cep[6]) && isdigit(cep[7]) && isdigit(cep[8])){
        isNumber = 1;
    } 
    if(isNumber ==1 && tamanhoAdequado ==1 && traco ==1){
        *cepValido = 1;
    }
    return *cepValido;
}
