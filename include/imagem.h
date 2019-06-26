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
	char* identificador;
	int altura, largura, color_range;
	Pixel **img;
} Imagem;

/*Função que aloca um espaço para o tipo imagem. Recebe como parâmetros
a altura e largura da matriz de pixels, respectivamente.
Retorna um ponteiro para a imagem alocada*/
Imagem* alocar_imagem(int altura, int largura);

/*Função que desaloca o espaço em memória reservado para uma imagem
que foi passada como parâmero */
void desalocar_imagem(Imagem *imagem);

/*Função que lê um arquivo ppm passado como parâmetro e salva o que foi lido
de modo compatível com o tipo imagem, alocado dinamicamente.
Retorna um ponteiro para a imagem alocada */
Imagem* ler_imagem(char* arquivo);

/*Função que recebe um ponteiro pra imagem passado como primeiro parâmetro
e escreve ela em um arquivo cujo nome foi passado como segundo parâmetro*/
void imprimir_imagem(Imagem *imagem, char* arquivo);

//Assinatura da função que retorna uma imagem cópia da que foi passada como parâmetro
Imagem* imagem_copia(Imagem *modelo);

#endif