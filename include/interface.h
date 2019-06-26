#ifndef INTERFACE_H
#define INTERFACE_H

#include <gtk/gtk.h>

#include "imagem.h"
#include "edicao.h"

//Função que vai carregar alguma imagem para uso do editor
void carregar_imagem(void);
//Função que irá salvar a imagem
void salvar_imagem(void);
//Função que aplica o filtro selecionado sobre a imagem vista pelo usuário
void aplicar_filtro(void);
//Função para restaurar a imagem ao ponto inicial
void restaurar_imagem(void);
//Função que limpa a imagem
void limpar_imagem(void);
//Função que aplica escala cinza a imagem
void i_gray_scale(void);
//Função que rotaciona a imagem em 90 graus sentido horário
void i_rotate_90_h(void);
//Função que rotaciona a imagem em 90 graus sentido anti-horário
void i_rotate_90_a(void);
//Função que rotaciona a imagem em 180 graus
void i_rotate_180(void);
//Função para ampliar a imagem
void i_zoom(void);
//Função para reduzir a imagem
void i_reduce(void);
//Função para ativar o filtro blurring
void i_blurring(void);
//Função para ativar o filtro de sharpening
void i_sharpening(void);
//Função para ativar o filtro de detecção de bordas
void i_edge_detection(void);

//Função que irá ativar a aplicação da interface
void activate(GtkApplication *app, gpointer user_data);


#endif