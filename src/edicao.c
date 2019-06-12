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
//Implementação da função pra rotacionar a imagem, dado seu ângulo e o sentido (horarío ou anti-horario)
void rotate(Imagem *imagem, int angulo, char sentido) {
	Imagem *temporaria = NULL;
	if((angulo != 90 && angulo != 180 && angulo != 270)
		|| (sentido != 'h' && sentido != 'a')) {
		printf("%s\n","Ângulo ou sentido de rotação ou inválido(s), digite novamente" );
		return;		
	} else {
		int altura = imagem->altura;
		int largura = imagem->largura;
		if(angulo == 180) {
			temporaria = alocar_imagem(altura, largura);

			for(int i = 0; i < altura; i++) {
				for(int j = 0; j < largura; j++) {
					temporaria->img[altura - i - 1][largura - j - 1] = imagem->img[i][j];
				}
			}
		} else if((sentido == 'h' && angulo == 90) || (sentido == 'a' && angulo == 270)) {
			temporaria = alocar_imagem(largura, altura);

			for(int i = 0; i < altura; i++) {
				for(int j = 0; j < largura; j++) {
					temporaria->img[j][altura - i - 1] = imagem->img[i][j];
				}
			}
		} else if((sentido == 'h' && angulo == 270) || (sentido == 'a' && angulo == 90)) {
			temporaria = alocar_imagem(largura, altura);

			for(int i = 0; i < altura; i++) {
				for(int j = 0; j < largura; j++) {
					temporaria->img[largura - j - 1][i] = imagem->img[i][j];
				}
			}			
		}

	}

	desalocar_imagem(imagem);
	imagem = imagem_copia(temporaria);
	desalocar_imagem(temporaria);
}
//Implementação da função para ampliar a imagem em um número "n" de vezes
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
//Implementação da função para reduzir a imagem em um número "n" de vezes
void reduce(Imagem *imagem, int n){
	int altura = imagem->altura;
	int largura = imagem->largura;
	float alt = altura/n, larg = largura/n;
	Imagem *imagem_reduzida = alocar_imagem(ceil(alt), ceil(larg));


	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++) {
			imagem_reduzida->img[i/n][j/n].red = imagem_reduzida->img[i/n][j/n].red + imagem->img[i][j].red/(n*n);
			imagem_reduzida->img[i/n][j/n].green = imagem_reduzida->img[i/n][j/n].green + imagem->img[i][j].green/(n*n);
			imagem_reduzida->img[i/n][j/n].blue = imagem_reduzida->img[i/n][j/n].blue + imagem->img[i][j].blue/(n*n);
		}
	}

	desalocar_imagem(imagem);
	imagem = imagem_copia(imagem_reduzida);
	desalocar_imagem(imagem_reduzida);

}

void blurring(Imagem *imagem) {
	int altura = imagem->altura;
	int largura = imagem->largura;
	int contador_red, contador_green, contador_blue;
	Imagem *imagem_borrada = alocar_imagem(altura, largura);

	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++) {
			contador_red = 0;
			contador_green = 0;
			contador_blue = 0;
			if(i == 0 && j == 0) {
				for(int x = i; x < i+2; x++) {
					for(int y = j; y < j+2; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/4;
				imagem_borrada->img[i][j].green = contador_green/4;
				imagem_borrada->img[i][j].blue = contador_blue/4;
			} else if(i == 0 && j == largura-1) {
				for(int x = i; x < i+2; x++) {
					for(int y = j-1; y < j+1; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/4;
				imagem_borrada->img[i][j].green = contador_green/4;
				imagem_borrada->img[i][j].blue = contador_blue/4;
			} else if(i == altura-1 && j == 0) {
				for(int x = i-1; x < i+1; x++) {
					for(int y = j; y < j+2; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/4;
				imagem_borrada->img[i][j].green = contador_green/4;
				imagem_borrada->img[i][j].blue = contador_blue/4;
			} else if(i == altura-1 && j == largura-1) {
				for(int x = i-1; x < i+1; x++) {
					for(int y = j-1; y < j+1; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/4;
				imagem_borrada->img[i][j].green = contador_green/4;
				imagem_borrada->img[i][j].blue = contador_blue/4;
			} else if(i == 0) {
				for(int x = i; x < i+2; x++) {
					for(int y = j-1; y < j+2; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/6;
				imagem_borrada->img[i][j].green = contador_green/6;
				imagem_borrada->img[i][j].blue = contador_blue/6;
			} else if(j == 0) {
				for(int x = i-1; x < i+2; x++) {
					for(int y = j; y < j+2; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/6;
				imagem_borrada->img[i][j].green = contador_green/6;
				imagem_borrada->img[i][j].blue = contador_blue/6;
			} else if(i == altura-1) {
				for(int x = i-1; x < i+1; x++) {
					for(int y = j-1; y < j+2; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/6;
				imagem_borrada->img[i][j].green = contador_green/6;
				imagem_borrada->img[i][j].blue = contador_blue/6;
			} else if(j == largura-1) {
				for(int x = i-1; x < i+2; x++) {
					for(int y = j-1; y < j+1; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/6;
				imagem_borrada->img[i][j].green = contador_green/6;
				imagem_borrada->img[i][j].blue = contador_blue/6;
			} else {
				for(int x = i-1; x < i+2; x++) {
					for(int y = j-1; y < j+2; y++) {
						contador_red += imagem->img[x][y].red;
						contador_green += imagem->img[x][y].green;
						contador_blue += imagem->img[x][y].blue;
					}
				}
				imagem_borrada->img[i][j].red = contador_red/9;
				imagem_borrada->img[i][j].green = contador_green/9;
				imagem_borrada->img[i][j].blue = contador_blue/9;
			}

		}
	}
	desalocar_imagem(imagem);
	imagem = imagem_copia(imagem_borrada);
	desalocar_imagem(imagem_borrada);
}