#include "edicao.h"

//Implementação da função para deixar a foto em escala cinza
void gray_scale(Imagem *imagem) {
	int media;
	for(int i = 0; i < imagem->altura; i++) {
		for(int j = 0; j < imagem->largura; j++) {
			media = (imagem->img[i][j].red + imagem->img[i][j].green + imagem->img[i][j].blue) / 3;
			imagem->img[i][j].red = media;
			imagem->img[i][j].green = media;
			imagem->img[i][j].blue = media;
		}
	}
}
//Implementação da função pra rotacionar a imagem
/*void rotate(Imagem *imagem) {
	Imagem *temporaria = imagem_copia(imagem);
	int altura = temporaria->altura - 1;
	int largura = temporaria->largura - 1;
	for(int i = 0; i < imagem->altura; i++) {
		for(int j = 0; j < imagem->largura; j++) {
			imagem->img[i][j] = temporaria->img[altura-j][i];
		}
	}
	desalocar_imagem(temporaria);
}*/