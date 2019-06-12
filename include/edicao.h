#ifndef EDICAO_H
#define EDICAO_H

#include "imagem.h"
#include <math.h>

//Assinatura da função para deixar a foto em escala cinza:
void gray_scale(Imagem *imagem);
//Assinatura da função que rotaciona a imagem 
void rotate(Imagem *imagem, int angulo, char sentido);
//Assinatura da função pra dar zoom a imagem
void zoom(Imagem* imagem, int n);
//Assinatura da função para reduzir a imagem
void reduce(Imagem* imagem, int n);

void blurring(Imagem *imagem);

#endif