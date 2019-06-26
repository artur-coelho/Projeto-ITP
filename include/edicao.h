#ifndef EDICAO_H
#define EDICAO_H

#include "imagem.h"
#include <math.h>

//Função que recebe uma imagem como parâmetro e aplica o filtro de preto e branco
void gray_scale(Imagem *imagem);

/*Assinatura da função que rotaciona a imagem
angulos de 90, 180 ou 270. sentido "h"(horário) ou "a"(anti-horário) */
void rotate(Imagem *imagem, int angulo, char sentido);

/*Função que amplia a imagem passada como primeiro parametro em um número "n" de 
vezes passado como segundo parâmetro*/
void zoom(Imagem* imagem, int n);

/*Função que reduz a imagem passada como primeiro parametro em um número "n" de 
vezes passado como segundo parâmetro*/
void reduce(Imagem* imagem, int n);

//Função que recebe uma imagem como parâmetro e aplica o filtro de blurring
void blurring(Imagem *imagem);

//Função que recebe uma imagem como parâmetro e aplica o filtro de sharpening
void sharpening(Imagem *imagem);

//Função que recebe uma imagem como parâmetro e aplica o filtro de detecção de bordas
void edge_detection(Imagem *imagem);

#endif