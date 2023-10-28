#include <stdio.h>
#include <string.h>
#include "util.h"






int valida_nome(char* nome) {
  int tam;
  
  tam = strlen(nome);
  for (int i = 0; i < tam-1; i++) {
    if (!so_letra(nome[i])) {
      return 0;
    }
  }
  return 1;  
}

int valida_telefone(char* tel) {
  int tam;
  tam = strlen(tel);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!so_digito(tel[i])) {
      return 0;
    }
  }
  return 1;
}


int valida_logradouro(char* log) {
  int tam;
  
  tam = strlen(log);
  for (int i = 0; i < tam-1; i++) {
    if (!so_letra(log[i])) {
      return 0;
    }
  }
  return 1;  
}

int valida_numero(char* num) {
  int tam;
  tam = strlen(num);
  if (tam >5) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!so_digito(num[i])) {
        return 0;
    }
  }
  return 1;
}
  
 
int valida_bairro(char* bai) {
  int tam;
  
  tam = strlen(bai);
  for (int i = 0; i < tam-1; i++) {
    if (!so_letra(bai[i])) {
      return 0;
    }
  }
  return 1;  
}

 
int valida_aro(char* aro) {
  int tam;
  tam = strlen(aro);
  if (tam >3) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!so_digito(aro[i])) {
        return 0;
    }
  }
  return 1;
}
  

int so_letra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else if (c == ' ' || c == 13) {
    return 1;
  } else {
    return 0;
  }  
}

int so_digito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}



int valida_cpf (char* cpf){
    int icpf[12];  
    int i,somador=0,digito1,result1,result2,digito2,valor;
      
//Efetua a conversao de array de char para um array de int.  
    for(i=0;i<11;i++) {  
    icpf[i]=cpf[i]-48;  
    }  
  
//PRIMEIRO DIGITO.  
  
    for(i=0;i<9;i++)  {  
    somador+=icpf[i]*(10-i);  
    }  
    result1=somador%11;  
  
    if( (result1==0) || (result1==1) ) {  
    digito1=0;  
    }  
  
    else {  
    digito1 = 11-result1;  
    }  
  
//SEGUNDO DIGITO.  
  
    somador=0;  
  
    for(i=0;i<10;i++) {  
    somador+=icpf[i]*(11-i);  
    }  
    valor=(somador/11)*11;  
    result2=somador-valor;  
  
    if( (result2==0) || (result2==1) ) {  
    digito2=0;  
    }  
  
    else {  
    digito2=11-result2;  
    }  
  
//RESULTADOS DA VALIDACAO.  
  
    if((digito1==icpf[9]) && (digito2==icpf[10])) {  
    return 1; 
    }  
    else  {   
    }  
    return 0;  
}  

int valida_email (char* email){
  int tam; 
  tam = strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } 

  if (i == tam && depoisPonto > 1){
    
    return 1;
  }  
  else{
    return 0;
  }
}

