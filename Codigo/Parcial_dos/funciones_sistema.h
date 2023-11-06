#ifndef FUNCIONES_SISTEMA_H
#define FUNCIONES_SISTEMA_H
#include "class_board.h"

int validar_opcion(int a, int b);
void visualizar_menu_principal();
void seleccion_fichas(char* jugador1,char* jugador2);
bool verificar_colocar_fichas(Class_board *tablerito, char color);
void seleccion_casilla(int* filas, int* columnas, char jugador, Class_board *tablerito);
void menu_principal();
char ganador(Class_board *tablerito, char jugador1, char jugador2);
void guardar_data(char jugador1, char ganador, int cantidad_fichas);
void Imprimir_data();

#endif // FUNCIONES_SISTEMA_H
