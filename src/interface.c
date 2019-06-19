#include "interface.h"

void carregar_imagem(Imagem* imagem) {
	imagem  = ler_imagem("Images/imagem1.ppm");
}

void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window, *image;
	GtkWidget *vbox, *hbox;
	GtkWidget *label1, *label2;
	//Imagem *imagem_carregada = NULL;

	window = gtk_application_window_new (app);
	gtk_window_set_title(GTK_WINDOW(window), "Editor de imagens ppm");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
	gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 20);

	//GtkVBox eh um container vertical para widgets
	//o primeiro argumento significa se os widgets sao igualmente distribuidos
	//o segundo argumento significa o espacamento entre os widgets em pixels
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	//GtkHBox eh um container horizontal para widgets
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3);

	//cria um botao com titulo carregar imagem
	GtkWidget *botaoCarregar = gtk_button_new_with_label("Carregar Imagem");

	//cria um botao com titulo aplicar filtro
	GtkWidget *botaoAplicar = gtk_button_new_with_label("Aplicar Filtro");

	//cria um botao para restaurar imagem
	GtkWidget *botaoRestaurar = gtk_button_new_with_label("Restaurar Imagem");
	
	//cria um botao para salvar imagem
	GtkWidget *botaoSalvar = gtk_button_new_with_label("Salvar Imagem");

	//cria um frame para colocar as opcoes do filtro
	GtkWidget *frameFiltro = gtk_frame_new("Opções do filtro");

	//cria um scrolled window para inserir a imagem
	GtkWidget *scrolledWindow = gtk_scrolled_window_new(gtk_adjustment_new(0, 0, 100, 1, 1, 1), gtk_adjustment_new(0, 0, 100, 1, 1, 1));
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

	// inicializarWidgetsMeuFiltro();

	//altera o tamanho do botao carregar
	gtk_widget_set_size_request(botaoCarregar, 70, 30);
	//altera o tamanho do botao aplicar
	gtk_widget_set_size_request(botaoAplicar, 70, 30);

	//adiciona os botoes no container horizontal (hbox)
	gtk_container_add(GTK_CONTAINER(hbox), botaoCarregar);
	gtk_container_add(GTK_CONTAINER(hbox), botaoAplicar);
	gtk_container_add(GTK_CONTAINER(hbox), botaoRestaurar);
	gtk_container_add(GTK_CONTAINER(hbox), botaoSalvar);

	//cria labels
	label1 = gtk_label_new("Carregue uma imagem");
	label2 = gtk_label_new("Aplicação de Filtros");

	//adiciona um widget imagem vazio 
	image = gtk_image_new();

	//adiciona os demais widgets no container vertical (vbox)
	//a funcao gtk_box_pack_start eh similar a gtk_container_add
	//mas com mais parametros
	gtk_box_pack_start(GTK_BOX(vbox), scrolledWindow, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(scrolledWindow), image);

	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), label1, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), label2, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), frameFiltro, FALSE, FALSE, 0);

	// adicionarWidgetsMeuFiltro(frameFiltro);

	//adiciona o vbox na janela (window)
	gtk_container_add(GTK_CONTAINER(window), vbox);

	//conecta o evento clicked do botaoCarregar a funcao carregarImagem
	g_signal_connect(G_OBJECT(botaoCarregar), "clicked", G_CALLBACK(carregar_imagem), (gpointer)user_data);

	//conecta o evento clicked do botaoAplicar a funcaoTeste (argv[0] eh o argumento)
	// g_signal_connect(G_OBJECT(botaoAplicar), "clicked", G_CALLBACK(funcaoAplicar), NULL);
	
	//conecta o evento clicked do botaoRestaurar a funcaoRestaurar
	// g_signal_connect(G_OBJECT(botaoRestaurar), "clicked", G_CALLBACK(funcaoRestaurar), NULL);

	//conecta o evento clicked do botaoSalvar a funcao salvarImagem
	// g_signal_connect(G_OBJECT(botaoSalvar), "clicked", G_CALLBACK(salvarImagem), NULL);

	//conecta o evento destroy da janela a
	// g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);
}