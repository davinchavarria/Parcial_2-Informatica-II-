#include "class_board.h"
#include <iostream>
using namespace std;

Class_board::Class_board(){//establecemos las pociciones iniciales del tablero

    board[3][3].set_estado('*'); // Establece el estado de la ficha en la posición (3,3)
    board[3][4].set_estado('-'); // Establece el estado de la ficha en la posición (3,4)
    board[4][3].set_estado('-'); // Establece el estado de la ficha en la posición (4,3)
    board[4][4].set_estado('*'); // Establece el estado de la ficha en la posición (4,4)

}

void Class_board::poner_ficha(int fila, int columna, char color){//cambiamos el estado de una de las pociciones del tablero
    board[fila][columna].set_estado(color);
}

void Class_board::imprimir_tablero(){
    cout<<"----------------TABLERO--------------"<<endl<<endl;
    cout<<"    A   B   C   D   E   F   G   H"<<endl;

    for (int i = 0; i<8; i++ ){
        cout<<"   -------------------------------"<<endl;
        cout<<(i+1)<<" | ";
        for (int j = 0; j<8; j++ ){
            cout<<board[i][j].get_estado()<<" | ";
        }
        cout<<(i+1)<<endl;
    }
    cout<<"   -------------------------------"<<endl;
    cout<<"    A   B   C   D   E   F   G   H"<<endl<<endl;
}

bool Class_board::atrapar_ficha(int fila, int columna, char color){
    //mirar si se puede atrapar hacia arriba
    bool atrapar_ficha_oponente = false;
    for (int i = fila-1; i > -1; --i) {
        if (board[i][columna].get_estado() == 'color'){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;
        }
    }
    //mirar si se puede atrapar hacia abajo
    for (int i = fila+1; i < 8; ++i) {
        if (board[i][columna].get_estado() == 'color'){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;
        }
    }
    //mirar si se puede atrapar hacia la izquierda
    for (int i = columna-1; i > -1; --i) {
        if (board[fila][i].get_estado() == 'color'){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;
        }
    }
    //mirar si se puede atrapar hacia la derecha
    for (int i = columna+1; i < 8; ++i) {
        if (board[fila][i].get_estado() == 'color'){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;
        }
    }

    //mirar diagonalmente superior izquierda si se puede atrapar una ficha del oponente

    for (int i = fila-1; i > -1; --i) {
        for (int j = columna-1; j > -1; --j) {
            if (board[i][j].get_estado() == 'color'){
                board[fila][columna].set_estado('O');
                atrapar_ficha_oponente = true;
            }
        }

    }
    //mirar diagonalmente superior derecha si se puede atrapar una ficha del oponente

    for (int i = fila-1; i > -1; --i) {
        for (int j = columna+1; j < 8; ++j) {
            if (board[i][j].get_estado() == 'color'){
                board[fila][columna].set_estado('O');
                atrapar_ficha_oponente = true;
            }
        }

    }
    //mirar diagonalmente inferior derecha si se puede atrapar una ficha del oponente

    for (int i = fila+1; i < 8; ++i) {
        for (int j = columna+1; j < 8; ++j) {
            if (board[i][j].get_estado() == 'color'){
                board[fila][columna].set_estado('O');
                atrapar_ficha_oponente = true;
            }
        }

    }
    //mirar diagonalmente inferior izquierda si se puede atrapar una ficha del oponente

    for (int i = fila+1; i < 8; ++i) {
        for (int j = columna-1; j > -1; --j) {
            if (board[i][j].get_estado() == 'color'){
                board[fila][columna].set_estado('O');
                atrapar_ficha_oponente = true;
            }
        }

    }

    return atrapar_ficha_oponente;
}



Class_board::~Class_board() {
    // Cuerpo del destructor (vacío en este caso)
}
