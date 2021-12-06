#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehLetra(char c)
{
  if (c >= 'A' && c <= 'Z')
  {
    return 1;
  }
  else if (c >= 'a' && c <= 'z')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int ehDigito(char num)
{
  if (num >= '0' && num <= '9')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int validaNome(char *nome)
{
  int i;
  for (i = 0; nome[i] != '\0'; i++)
  {
    if (ehLetra(nome[i]) || nome[i] == ' ')
    {
      return 1;
    }
  }
  return 0;
}

int validaCpf(char *cpf)
{
  // 000.000.000-00\0
  int i;
  int tam = strlen(cpf);
  if (tam != 11)
  {
    return 0;
  }
  for (i = 0; cpf[i] != '\0'; i++)
  {
    if (!ehDigito(cpf[i]))
    {
      return 0;
    }
  }
  return 1;
}

int validaEmail(char* email){
  int i;
  int ponto = 0;
  int arroba = 0;
  int dpsArroba = 0;
  for(i= 0; email[i]!='\0'; i++){
    if(email[i] == '.' && dpsArroba == 1){
       ponto = 1;
    }
    if(email[i] == '@'){
      arroba = 1;
      dpsArroba =1;
    } 
  }
  if(ponto == 1 && arroba == 1){
    return 1;

  }else{
    return 0;
  }
}

int validaCep(char *cep)
{
  // 00000-000\0
  int i;
  int tam = strlen(cep);

  if (tam != 8)
  {
    return 0;
  }
  for (i = 0; cep[i] != '\0'; i++)
  {
    if (!ehDigito(cep[i]))
    {
      return 0;
    }
  }
  return 1;
}

int ehBissexto(int aa)
{
  // Identificar se o ano é bissexto.
  if ((aa % 4 == 0) && (aa % 100 != 0))
  {
    return 1;
  }
  else if (aa % 400 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int ehData(int dd, int mm, int aa)
{
  // verificação da data.
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2)
  {
    if (ehBissexto(aa))
      maiorDia = 29;
    else
      maiorDia = 28;
  }
  else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
  {
    maiorDia = 30;
  }
  else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}

int validarData(char *data)
{
  // Validação da data
  int tam, dia, mes, ano;
  tam = strlen(data);
  if (tam != 8)
  {
    return 0;
  }
  int i;
  for (i = 0; i < tam; i++)
  {
    if (!ehDigito(data[i]))
    {
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[2] - '0') * 10 + (data[3] - '0');
  ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 +
        (data[6] - '0') * 10 + (data[7] - '0');
  if (!ehData(dia, mes, ano))
  {
    return 0;
  }
  return 1;
}


void maskCpf(char *cpf)
{
  int i;
  int j = 0;
  int cont = 0;
  char mask[4] = {'.', '.', '-', '\0'};
  char newCpf[20];

  for (i = 0; i <= 14; i++)
  {
    if (i == 3 || i == 7 || i == 11)
    {
      newCpf[i] = mask[cont];
      j = i - cont;
      cont += 1;
    }
    else
    {
      newCpf[i] = cpf[j];
      j++;
    }
  }
  printf("%s\n", newCpf);
}

void maskCep(char *cep)
{
  int i;
  int j = 0;
  char newCep[20];

  for (i = 0; i <= 9; i++)
  {
    if (i == 5)
    {
      newCep[i] = '-';
      j = i;
    }
    else
    {
      newCep[i] = cep[j];
      j++;
    }
  }
  printf("%s\n", newCep);
}

int validaPhone(char *telefone)
{
  // 00000-0000\0
  int i;
  int tam = strlen(telefone);
  if (tam != 9)
  {
    return 0;
  }
  for (i = 0; telefone[i] != '\0'; i++)
  {
    if (!ehDigito(telefone[i]))
    {
      return 0;
    }
  }
  return 1;
}

void maskPhone(char *telefone)
{
  int i;
  int j = 0;
  char newPhone[20];

  for (i = 0; i <= 10; i++)
  {
    if (i == 5)
    {
      newPhone[i] = '-';
      j = i;
    }
    else
    {
      newPhone[i] = telefone[j];
      j++;
    }
  }
  printf("%s\n", newPhone);
}

int validaRg(char *rg)
{
  // 00.000.000-0\0
  int i;
  int tam = strlen(rg);
  if (tam != 9)
  {
    return 0;
  }
  for (i = 0; rg[i] != '\0'; i++)
  {
    if (!ehDigito(rg[i]))
    {
      return 0;
    }
  }
  return 1;
}

void maskRg(char *rg)
{
  int i;
  int j = 0;
  int cont = 0;
  char mask[4] = {'.', '.', '-', '\0'};
  char newRg[20];

  for (i = 0; i <= 12; i++)
  {
    if (i == 2 || i == 6 || i == 10)
    {
      newRg[i] = mask[cont];
      j = i - cont;
      cont += 1;

    }
    else
    {
      newRg[i] = rg[j];
      j++;
    }
  }
  printf("%s\n", newRg);
}
int ehSexo(char s){
  if(s == 'f' || s == 'm'){
    return 1;
  }else if(s == 'F' || s == 'M'){
    return 1;
  }
  else{
    return 0;
  }
}

int validaSexo(char *sexo)
{
  // f ou m
  int i;
  int tam = strlen(sexo);
  if (tam != 1)
  {
    return 0;
  }
  for (i = 0; sexo[i] != '\0'; i++)
  {
    if (!ehSexo(sexo[i]))
    {
      return 0;
    }
  }
  return 1;
}

