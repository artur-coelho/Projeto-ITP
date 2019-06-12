#include "main.h"

int main() {

	Imagem *img1 = NULL;
	img1 = ler_imagem("Images/imagem1.ppm");
	//reduce(img1, 5);
	//img2 = imagem_copia(img1);
	//zoom(img1, 3);
	//rotate(img1, 270, 'h');
	//blurring(img1);
	//sharpening(img1);
	edge_detection(img1);
	imprimir_imagem(img1, "Images/imagem1_edge_detection");
	desalocar_imagem(img1);


	return 0;
}