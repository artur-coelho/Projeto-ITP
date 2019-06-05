#include "main.h"

int main() {

	Imagem *img1 = NULL;
	img1 = ler_imagem("Images/imagem2.ppm");
	//img2 = imagem_copia(img1);
	zoom(img1, 2);
	imprimir_imagem(img1, "Images/imagem_ampliada.ppm");
	desalocar_imagem(img1);


	return 0;
}