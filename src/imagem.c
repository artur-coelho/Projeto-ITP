#include "imagem.h"

//Implementação da função de alocar espaço para a matriz imagem
Imagem* alocar_imagem(int altura, int largura) {
	Imagem* imagem_alocada = (Imagem *)malloc(sizeof(Imagem));
	imagem_alocada->identificador = "P3";
	imagem_alocada->altura = altura;
	imagem_alocada->largura = largura;
	imagem_alocada->color_range = 255;
	imagem_alocada->img = (Pixel **)malloc(altura*sizeof(Pixel*));
	for(int i = 0; i < altura; i++) {
		imagem_alocada->img[i] = (Pixel *)malloc(largura*sizeof(Pixel));
	}
	return imagem_alocada;
}
//Implementação da função para desalocar o espaço da imagem
void desalocar_imagem(Imagem *imagem) {
	for(int i = 0; i < imagem->altura; i++) {
		free(imagem->img[i]);
	}
	free(imagem->img);
	free(imagem);
}
//Implementação da função para ler a imagem de um arquivo, retorna um tipo imagem alocado dinamicamente:
Imagem* ler_imagem(char* arquivo) {
	FILE *arquivo_lido;
	Imagem *imagem_lida;
	arquivo_lido = fopen(arquivo, "r");
	if (arquivo_lido==NULL) {//Verificar se o arquivo a ser lido existe
		printf("Erro na abertura do arquivo.\n");
		return NULL;
	} else {
		//unsigned long len = 0;//variável para uso da função getline
		//getline(&imagem_lida->identificador, &len, arquivo_lido);
		int altura, largura, color_range;
		fscanf(arquivo_lido, "P3 %i %i\n %i\n", &altura, &largura, &color_range);
		imagem_lida = alocar_imagem(altura, largura);
		for(int i = 0; i < imagem_lida->altura; i++) {
			for(int j = 0; j < imagem_lida->largura; j++) {
				fscanf(arquivo_lido, "%hhu\n %hhu\n %hhu\n", &imagem_lida->img[i][j].red, 
					   &imagem_lida->img[i][j].green, &imagem_lida->img[i][j].blue);
			}
		}
		fclose(arquivo_lido);
		return imagem_lida;
	}
}
//Implementação da função que imprime a imagem em formato ppm
void imprimir_imagem(Imagem *imagem, char* arquivo) {
	FILE *arquivo_escrito;
	arquivo_escrito = fopen(arquivo, "w");
	fprintf(arquivo_escrito, "%s\n", imagem->identificador);
	fprintf(arquivo_escrito, "%i %i\n%i\n", imagem->altura,
			imagem->largura, imagem->color_range);
	for(int i = 0; i < imagem->altura; i++) {
			for(int j = 0; j < imagem->largura; j++) {
				fprintf(arquivo_escrito, "%hhu\n%hhu\n%hhu\n", imagem->img[i][j].red, 
					   imagem->img[i][j].green, imagem->img[i][j].blue);
			}
		}
		fclose(arquivo_escrito);
}

Imagem* imagem_copia(Imagem *modelo) {
	Imagem* copia = alocar_imagem(modelo->altura, modelo->largura);
	copia->identificador = modelo->identificador;
	copia->color_range = modelo->color_range;
	for(int i = 0; i < copia->altura; i++) {
		for(int j = 0; j < copia->largura; j++) {
			copia->img[i][j].red = modelo->img[i][j].red;
			copia->img[i][j].green = modelo->img[i][j].green;
			copia->img[i][j].blue = modelo->img[i][j].blue;
		}
	}
	return copia;
}