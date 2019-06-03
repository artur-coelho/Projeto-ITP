#include "imagem.h"

//Implementação da função de alocar espaço para a matriz imagem
void alocar_imagem(Imagem *imagem_alocada) {
	imagem_alocada->img = malloc(imagem_alocada->altura*sizeof(Pixel*));
	for(int i = 0; i < imagem_alocada->altura; i++) {
		imagem_alocada->img[i] = malloc(imagem_alocada->largura*sizeof(Pixel));
	}
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
	Imagem *imagem_lida = (Imagem *)malloc(sizeof(Imagem));
	arquivo_lido = fopen(arquivo, "r");
	if (arquivo_lido==NULL) {//Verificar se o arquivo a ser lido existe
		printf("Erro na abertura do arquivo.\n");
		return imagem_lida;
	} else {
		unsigned long len = 0;//variável para uso da função getline
		getline(&imagem_lida->identificador, &len, arquivo_lido);
		fscanf(arquivo_lido, "%i %i\n %i\n", &imagem_lida->altura, &imagem_lida->largura, &imagem_lida->color_range);
		alocar_imagem(imagem_lida);
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
	Imagem* copia = (Imagem *)malloc(sizeof(Imagem));
	copia->identificador = modelo->identificador;
	copia->altura = modelo->altura;
	copia->largura = copia->largura;
	copia->color_range = modelo->color_range;
	alocar_imagem(copia);
	for(int i = 0; i < copia->altura; i++) {
		for(int j = 0; j < copia->largura; j++) {
			copia->img[i][j].red = modelo->img[i][j].red;
			copia->img[i][j].green = modelo->img[i][j].green;
			copia->img[i][j].blue = modelo->img[i][j].blue;
		}
	}
	return copia;
}