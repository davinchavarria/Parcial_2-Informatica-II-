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
    bool atrapar_ficha(int fila, int columna, char color);



    ~Class_board();


};

#endif // CLASS_BOARD_H
