#include "main.h"

int main(int argc, char** argv) {

	Imagem *img1 = NULL;
	//char* imagem1 = "Images/imagem1.ppm";
	//img1 = ler_imagem("Images/imagem1.ppm");
	//reduce(img1, 2);
	//img2 = imagem_copia(img1);
	//zoom(img1, 3);
	//rotate(img1, 270, 'h');
	//blurring(img1);
	//sharpening(img1);
	//edge_detection(img1);
	//imprimir_imagem(img1, "Images/imagem1_edge_detection");
	

	GtkApplication *app;
 	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK(activate), img1);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	desalocar_imagem(img1);

	
	return status;
}