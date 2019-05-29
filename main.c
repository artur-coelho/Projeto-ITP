#include <stdio.h>
#include "imagem.h"

int main() {

	Imagem *img1;
	img1 = ler_imagem();
	gray_scale(img1);
	imprimir_imagem(img1);
	desalocar_imagem(img1);

	return 0;
}