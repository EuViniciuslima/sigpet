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
 
  
  tamanhoCpf = strlen(cpf);

  if(tamanhoCpf == tamanhoMaximo){
    tamanhoAdequado = 1;
  }
  if(cpf[3] == '.' && cpf[7] == '.'){
    ponto = 1;
  }
    
  if(cpf[11] == '-'){
    traco = 1;
  }
    
  int cont = 0;
  while(cont < tamanhoMaximo){
    if(isdigit(cpf[cont])){
      isNumber =1;
    }
    else{
      cont = tamanhoMaximo;
    }
    cont ++;
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
    int cont = 0;
    while(cont < tamanhoMaximo){
      if(isdigit(cep[cont])){
        isNumber =1;
      }
      else{
        cont = tamanhoMaximo;
      }
      cont ++;
    }
    if(isNumber ==1 && tamanhoAdequado ==1 && traco ==1){
      *cepValido = 1;
    }
    return *cepValido;
}

int validaPhone(char *telefone, int *telValido){
    int tamanho;
    int isNumber;
    int tamanhoAdequado = 0;
    int tamanhoMaximo = 10;
    int traco = 0;
    //99999-9999
    tamanho = strlen(telefone);

    if(tamanho == tamanhoMaximo){
      tamanhoAdequado = 1;
    }
    if(telefone[5] == '-'){
      traco = 1;
    }
    int cont = 0;
    while(cont < tamanhoMaximo){
      if(isdigit(telefone[cont])){
        isNumber =1;
      }
      else{
        cont = tamanhoMaximo;
      }
      cont ++;
    }

    if(isNumber == 1 && tamanhoAdequado ==1 && traco == 1){
      *telValido =1;
    }
    return *telValido;
}
