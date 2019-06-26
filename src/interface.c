#include "interface.h"

Imagem *imagem_alterada;
char *arquivo_alterado = NULL;
GtkWidget *window, *g_image;

void carregar_imagem(void) {
	
	GtkWidget *dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
	gint res;
	char *filename = NULL;

	dialog = gtk_file_chooser_dialog_new ("Selecionar arquivo", GTK_WINDOW(window), action,
                                          ("_Cancelar"), GTK_RESPONSE_CANCEL,("_Abrir"),
                                          GTK_RESPONSE_ACCEPT, NULL);

	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		
		if(imagem_alterada != NULL) {
		desalocar_imagem(imagem_alterada);
		}

	    GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
	    arquivo_alterado = gtk_file_chooser_get_filename (chooser);
	    filename = gtk_file_chooser_get_filename (chooser);
	    gtk_image_set_from_file(GTK_IMAGE(g_image), filename);
	    imagem_alterada = ler_imagem(filename);
	    g_free(filename);
	}

	gtk_widget_destroy (dialog);
}

void salvar_imagem(void) {
	if(imagem_alterada != NULL) {
		GtkWidget *dialog;
		GtkFileChooser *chooser;
		GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
		gint res;

		dialog = gtk_file_chooser_dialog_new ("Salvar Arquivo", (GtkWindow *)window, action,
		                                      ("_Cancelar"), GTK_RESPONSE_CANCEL,
		                                      ("_Salvar"), GTK_RESPONSE_ACCEPT, NULL);
		chooser = GTK_FILE_CHOOSER(dialog);

		gtk_file_chooser_set_do_overwrite_confirmation(chooser, TRUE);

	    gtk_file_chooser_set_current_name (chooser, ("Untitled document.ppm"));

		res = gtk_dialog_run (GTK_DIALOG(dialog));
		if (res == GTK_RESPONSE_ACCEPT)
		  {
		    char *filename;

		    filename = gtk_file_chooser_get_filename(chooser);
		    imprimir_imagem(imagem_alterada , filename);
		    g_free(filename);
		  }

		gtk_widget_destroy(dialog);
	}
}

void aplicar_filtro(void) {

}

void restaurar_imagem(void) {
	desalocar_imagem(imagem_alterada);
	imagem_alterada = ler_imagem(arquivo_alterado);
}

void limpar_imagem(void) {
	if(imagem_alterada != NULL) {
		desalocar_imagem(imagem_alterada);
		imagem_alterada = NULL;
		gtk_image_clear(GTK_IMAGE(g_image));
	} else {
		return;
	}
}

void i_gray_scale(void) {
	if(imagem_alterada != NULL) {
		gray_scale(imagem_alterada);
	}
}

void i_rotate_90_h(void) {
	if(imagem_alterada != NULL) {
		rotate(imagem_alterada, 90, 'h');
	}
}

void i_rotate_90_a(void) {
	if(imagem_alterada != NULL) {
		rotate(imagem_alterada, 90, 'a');
	}
}

void i_rotate_180(void) {
	if(imagem_alterada != NULL) {
		rotate(imagem_alterada, 180, 'a');
	}
}

void i_zoom(void) {
	if(imagem_alterada != NULL) {
		zoom(imagem_alterada, 2);
	}
}

void i_reduce(void) {
	if(imagem_alterada != NULL) {
		reduce(imagem_alterada, 2);
	}
}

void i_blurring(void) {
	if(imagem_alterada != NULL) {
		blurring(imagem_alterada);
	}
}

void i_sharpening(void) {
	if(imagem_alterada != NULL) {
		sharpening(imagem_alterada);
	}
}

void i_edge_detection(void) {
	if(imagem_alterada != NULL) {
		edge_detection(imagem_alterada);
	}
}

void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *vbbox, *hbbox, *vlbox, *hlbox;
	GtkWidget *frame;
	frame = gtk_frame_new("Opções de filtros:");
	g_image = gtk_image_new();

	//Propriedades da janela que foi criada:
	window = gtk_application_window_new (app);
	gtk_window_set_title(GTK_WINDOW(window), "Editor de imagens ppm");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
	gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	//Criação dos containers horizontair e verticais que irão acoplar outros widgets
	vbbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	vlbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);
	
	hbbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	hlbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3);

	//criação do botão para carregar a imagem, associando ele a uma função e posicionando ele
    GtkWidget *botaoCarregar = gtk_button_new_with_label ("Carregar Imagem");
    g_signal_connect (botaoCarregar, "clicked", G_CALLBACK (carregar_imagem), NULL);
	gtk_container_add(GTK_CONTAINER(hlbox), botaoCarregar);

    //cria um botão para salvar a imagem, associando ele a uma função e posicionando ele
    GtkWidget *botaoSalvar = gtk_button_new_with_label ("Salvar Imagem");
    g_signal_connect (botaoSalvar, "clicked", G_CALLBACK (salvar_imagem), NULL);
	gtk_container_add(GTK_CONTAINER(hlbox), botaoSalvar);

    //cria um botão para aplicar o filtro a imagem, associando ele a uma função e posicionando ele
    GtkWidget *botaoAplicar = gtk_button_new_with_label("Aplicar Filtro");
    g_signal_connect (botaoAplicar, "clicked", G_CALLBACK (aplicar_filtro), NULL);
	gtk_container_add(GTK_CONTAINER(hlbox), botaoAplicar);

    //cria um botao para restaurar imagem, associando ele a uma função e posicionando ele
	GtkWidget *botaoRestaurar = gtk_button_new_with_label("Restaurar Imagem");
	g_signal_connect (botaoRestaurar, "clicked", G_CALLBACK (restaurar_imagem), NULL);
	gtk_container_add(GTK_CONTAINER(hlbox), botaoRestaurar);

	//cria um botão para salvar a imagem, associando ele a uma função e posicionando ele
    GtkWidget *botaoLimpar = gtk_button_new_with_label ("Limpar Imagem");
    g_signal_connect (botaoLimpar, "clicked", G_CALLBACK (limpar_imagem), NULL);
	gtk_container_add(GTK_CONTAINER(hlbox), botaoLimpar);

	//altera o tamanho dos botões passados como parametro
	gtk_widget_set_size_request(botaoCarregar, 100, 30);
	gtk_widget_set_size_request(botaoSalvar, 100, 30);
	gtk_widget_set_size_request(botaoRestaurar, 100, 30);
	gtk_widget_set_size_request(botaoLimpar, 100, 30);
	

	GtkWidget *botaoGrayScale = gtk_button_new_with_label("Gray Scale");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoGrayScale);
	g_signal_connect(botaoGrayScale, "clicked", G_CALLBACK(i_gray_scale), NULL);

	GtkWidget *botaoRotate90h = gtk_button_new_with_label("Rotacionar\n 90° Horário");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoRotate90h);
	g_signal_connect(botaoRotate90h, "clicked", G_CALLBACK(i_rotate_90_h), NULL);

	GtkWidget *botaoRotate90a = gtk_button_new_with_label("Rotacionar\n 90° Anti-Horário");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoRotate90a);
	g_signal_connect(botaoRotate90a, "clicked", G_CALLBACK(i_rotate_90_a), NULL);

	GtkWidget *botaoRotate180 = gtk_button_new_with_label("Rotacionar\n 180°");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoRotate180);
	g_signal_connect(botaoRotate180, "clicked", G_CALLBACK(i_rotate_180), NULL);

	GtkWidget *botaoZoom = gtk_button_new_with_label("Ampliar");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoZoom);
	g_signal_connect(botaoZoom, "clicked", G_CALLBACK(i_zoom), NULL);

	GtkWidget *botaoReduce = gtk_button_new_with_label("Reduzir");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoReduce);
	g_signal_connect(botaoReduce, "clicked", G_CALLBACK(i_reduce), NULL);

	GtkWidget *botaoBlurring = gtk_button_new_with_label("Blurring");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoBlurring);
	g_signal_connect(botaoBlurring, "clicked", G_CALLBACK(i_blurring), NULL);

	GtkWidget *botaoSharpening = gtk_button_new_with_label("Sharpening");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoSharpening);
	g_signal_connect(botaoSharpening, "clicked", G_CALLBACK(i_sharpening), NULL);

	GtkWidget *botaoEdge = gtk_button_new_with_label("Edge Detection");
	gtk_container_add(GTK_CONTAINER(vlbox), botaoEdge);
	g_signal_connect(botaoEdge, "clicked", G_CALLBACK(i_edge_detection), NULL);


	GtkWidget *scrolledWindow = gtk_scrolled_window_new(gtk_adjustment_new(0, 0, 100, 1, 1, 1), gtk_adjustment_new(0, 0, 100, 1, 1, 1));
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_container_add(GTK_CONTAINER(scrolledWindow), g_image);

	gtk_container_add(GTK_CONTAINER(frame), vlbox);
	gtk_box_pack_start(GTK_BOX(hbbox), frame, FALSE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbbox), scrolledWindow, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbbox), hlbox, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbbox), hbbox, TRUE, TRUE, 5);

	//adiciona o vwindowbox na janela (window)
	gtk_container_add(GTK_CONTAINER(window), vbbox);


	gtk_widget_show_all(window);
}