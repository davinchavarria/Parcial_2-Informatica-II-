#ifndef CLASS_BOARD_H
#define CLASS_BOARD_H
#include "fichas.h"

class Class_board
{
private:
    fichas board[8][8];
public:
    Class_board();
    void poner_ficha(int fila, int columna, char color);
    void imprimir_tablero();
    bool tablero_lleno();
    bool atrapar_ficha(int fila, int columna, char color);
    void atrapar_ficha_cambio(int fila, int columna, char color);
    void eliminar_O();
    char get_estado_casilla(int fila, int columna);
    int contador_fichas(char color);
    void poner_todo_ficha();

    ~Class_board();
};

#endif // CLASS_BOARD_H
