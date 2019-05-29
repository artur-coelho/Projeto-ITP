#include <stdio.h>
#include <stdlib.h>

int main() {

    /*
    Matriz = matriz de entrada
    Matrizn = matriz anti-horario
    Matriznn = matriz Horario
    */

	int matriz[3][3], matrizn[3][3], matriznn[3][3], n = 3-1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriz[i][j] = k++;
        }
    }

    //girando anti horario
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
                matrizn[i][j] = matriz[j][n-i];
        }
    }

    //girando horario
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
                matriznn[i][j] = matriz[n-j][i];
        }
    }

    //imprimindo matriz normal
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    //imprimindo matriz anti horario
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrizn[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    //imprimindo matriz horario
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriznn[i][j]);
        }
        printf("\n");
    }


	return 0;
}