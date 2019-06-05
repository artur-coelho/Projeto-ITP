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
void rotate(Imagem *imagem) {
	int altura = imagem->altura;
	int largura = imagem->largura;
	Imagem *temporaria = alocar_imagem(largura, altura);

	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++) {
			temporaria->img[j][altura - i - 1] = imagem->img[i][j];
		}
	}

	desalocar_imagem(imagem);
	imagem = imagem_copia(temporaria);
	desalocar_imagem(temporaria);
}
//Implementação da função pra dar zoom a imagem
void zoom(Imagem* imagem, int n) {
	int altura = imagem->altura;
	int largura = imagem->largura;
	Imagem *imagem_ampliada = alocar_imagem(n*altura, n*largura);
	for(int i = 0; i < imagem_ampliada->altura; i++) {
		for(int j = 0; j < imagem_ampliada->largura; j++) {
			imagem_ampliada->img[i][j] = imagem->img[i/n][j/n];
		}
	}
	desalocar_imagem(imagem);
	imagem = imagem_copia(imagem_ampliada);
	desalocar_imagem(imagem_ampliada);

}

/*void reduce(Imagem *imagem, int n){
	int altura = imagem->altura;
	int largura = imagem->largura;
	Imagem *imagem_reduzida = alocar_imagem(altura/n, largura/n);
	unsigned char r_acumulado, g_acumulado, b_acumulado;
	unsigned char r_media, g_media, b_media;

	for(int i = 0; i < imagem_reduzida->altura; i = i + n) {
		for(int j = 0; j < imagem_reduzida->largura; j = j + n) {
			for(int z = 0; z < n; z++) {
				r_acumulado = r_acumulado + imagem->img.red[i*z][j*z];
				g_acumulado = g_acumulado + imagem->img.green[i*z][j*z];
				b_acumulado = b_acumulado + imagem->img.blue[i*z][j*z];
			}
			r_media = r_acumulado/n;
			g_media = g_acumulado/n;
			b_media = b_acumulado/n;

		}
	}
}*/