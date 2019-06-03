#include "main.h"

int main() {

	Imagem *img1;
	img1 = ler_imagem("Images/imagem1.ppm");
	rotate(img1);
	imprimir_imagem(img1, "Images/imagem_rotacionada.ppm");
	desalocar_imagem(img1);

	return 0;
}