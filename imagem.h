#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definição do tipo Pixel
typedef struct {
	unsigned char red, green, blue;
} Pixel;
//Definição do tipo Imagem
typedef struct {
	char *identificador;
	int altura, largura, color_range;
	Pixel **img;
} Imagem;

//Assinatura da função de alocar espaço para imagem:
void alocar_imagem(Imagem *imagem);
//Assinatura da função para desalocar o espaço da imagem:
void desalocar_imagem(Imagem *imagem);
//Assinatura da função para ler a imagem de um arquivo:
Imagem* ler_imagem(void);
//Assinatura da função que imprime a imagem em formato ppm
void imprimir_imagem(Imagem *imagem);
//Assinatura da função para deixar a foto em escala cinza:
void gray_scale(Imagem *imagem);

#endif