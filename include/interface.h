#ifndef INTERFACE_H
#define INTERFACE_H

#include <gtk/gtk.h>

#include "imagem.h"
#include "edicao.h"


void carregar_imagem(Imagem* imagem);

void activate(GtkApplication *app, gpointer user_data);


#endif