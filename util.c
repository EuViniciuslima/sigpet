#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehDigito(char num){
  if(num >= '0' && num <= '9'){
    return 1;
  }else{
    return 0;
  }
}


int validaCpf(char *cpf){
  //000.000.000-00\0
  int i;
  int tam = strlen(cpf);
  if(tam != 11){
    return 0;
  }
  for(i = 0; cpf[i]!='\0'; i++){
    if(!ehDigito(cpf[i])){
      return 0;
    }
  }
  return 1;
}


int validaEmail(char* email){
  int i;
  int ponto = 0;
  int arroba = 0;
  for(i= 0; email[i]!='\0'; i++){
    if(email[i] == '.'){
       ponto = 1;
    }
    if(email[i] == '@'){
      arroba = 1;
    } 
  }
  if(ponto == 1 && arroba == 1){
    return 1;
  }else{
    return 0;
  }
}

int validaCep(char *cep){
  //00000-000\0
  int i;
  int tam = strlen(cep);

  if(tam != 8){
    return 0;
  }
  for(i = 0; cep[i]!='\0'; i++){
    if(!ehDigito(cep[i])){
      return 0;
    }
  }
  return 1;
}
int validaPhone(char *telefone){
  //00000-0000\0
  int i;
  int tam = strlen(telefone);
  if(tam != 9){
    return 0;
  }
  for(i = 0; telefone[i]!='\0'; i++){
    if(!ehDigito(telefone[i])){
      return 0;
    }
  }
  return 1;
}

int validaRg(char *rg){
  //00.000.000-0\0
  int i;
  int tam = strlen(rg);
  if(tam != 9){
    return 0;
  }
  for(i = 0; rg[i]!='\0'; i++){
    if(!ehDigito(rg[i])){
      return 0;
    }
  }
  return 1;
}


