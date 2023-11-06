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
    char color2;

    if (color == '*'){
        color2 = '-';
    }
    else if(color == '-'){
        color2 = '*';
    }


    for (int i = fila-1; i > -1; --i) {
        if ((board[i][columna].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila-1][columna].get_estado() == color2) and (board[i+1][columna].get_estado() == color2)){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;

        }
    }

    //mirar si se puede atrapar hacia abajo
    for (int i = fila+1; i < 8; ++i) {
        if ((board[i][columna].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila+1][columna].get_estado() == color2) and (board[i-1][columna].get_estado() == color2)){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;

        }
    }

    //mirar si se puede atrapar hacia la izquierda
    for (int i = columna-1; i > -1; --i) {
        if ((board[fila][i].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila][columna-1].get_estado() == color2) and (board[fila][i+1].get_estado() == color2)){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;

        }
    }
    //mirar si se puede atrapar hacia la derecha
    for (int i = columna+1; i < 8; ++i) {
        if ((board[fila][i].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila][columna+1].get_estado() == color2) and (board[fila][i-1].get_estado() == color2)){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;

        }
    }

    //mirar diagonalmente superior izquierda si se puede atrapar una ficha del oponente

    for (int i = fila-1, j = columna-1; i > -1; --i, --j) {
            if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila-1][columna-1].get_estado() == color2) and (board[i+1][j+1].get_estado() == color2)){
                board[fila][columna].set_estado('O');
                atrapar_ficha_oponente = true;

            }
    }
    //mirar diagonalmente superior derecha si se puede atrapar una ficha del oponente

    for (int i = fila-1, j = columna+1; i > -1; --i, ++j) {

            if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila-1][columna+1].get_estado() == color2) and (board[i+1][j-1].get_estado() == color2)){
                board[fila][columna].set_estado('O');
                atrapar_ficha_oponente = true;

            }


    }
    //mirar diagonalmente inferior derecha si se puede atrapar una ficha del oponente

    for (int i = fila+1, j = columna+1; i < 8; ++i, ++j) {

        if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila+1][columna+1].get_estado() == color2) and (board[i-1][j-1].get_estado() == color2)){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;

        }


    }
    //mirar diagonalmente inferior izquierda si se puede atrapar una ficha del oponente

    for (int i = fila+1, j = columna-1; j > -1; ++i, --j) {
        if ((board[i][j].get_estado() == color) and (board[i][j].get_estado() != ' ') and (board[fila][columna].get_estado() != color2) and (board[fila+1][columna-1].get_estado() == color2) and (board[i-1][j+1].get_estado() == color2)){
            board[fila][columna].set_estado('O');
            atrapar_ficha_oponente = true;
        }



    }

    return atrapar_ficha_oponente;
}

bool Class_board::tablero_lleno(){
    bool lleno = true;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j].get_estado() == ' '){
                lleno = false;
            }

        }
    }

    return lleno;
}

void Class_board::eliminar_O(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j].get_estado() == 'O'){
                board[i][j].set_estado(' ');
            }

        }
    }

}

void Class_board::atrapar_ficha_cambio(int fila, int columna, char color){
    char color2;

    if (color == '*'){
        color2 = '-';
    }
    else{
        color2 = '*';
    }

    for (int i = fila-1; i > -1; --i) {
        if ((board[i][columna].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila-1][columna].get_estado() == color2) and (board[i+1][columna].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int j = fila-1; j > i; --j) {
                board[j][columna].set_estado(color);
            }

        }
    }

    //mirar si se puede atrapar hacia abajo
    for (int i = fila+1; i < 8; ++i) {
        if ((board[i][columna].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila+1][columna].get_estado() == color2) and (board[i-1][columna].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int j = fila+1; j < i; ++j) {
                board[j][columna].set_estado(color);
            }

        }
    }

    //mirar si se puede atrapar hacia la izquierda
    for (int i = columna-1; i > -1; --i) {
        if ((board[fila][i].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila][columna-1].get_estado() == color2) and (board[fila][i+1].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int j = columna-1; j > i; --j) {
                board[fila][j].set_estado(color);
            }

        }
    }
    //mirar si se puede atrapar hacia la derecha
    for (int i = columna+1; i < 8; ++i) {
        if ((board[fila][i].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila][columna+1].get_estado() == color2) and (board[fila][i-1].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int j = columna+1; j < i; ++j) {
                board[fila][j].set_estado(color);
            }

        }
    }

    //mirar diagonalmente superior izquierda si se puede atrapar una ficha del oponente
    for (int i = fila-1, j = columna-1; i > -1; --i, --j) {
        if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila-1][columna-1].get_estado() == color2) and (board[i+1][j+1].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int k = fila-1, l = columna-1; k > i; --k, --l) {
                board[k][l].set_estado(color);
            }
        }
    }

    //mirar diagonalmente superior derecha si se puede atrapar una ficha del oponente
    for (int i = fila-1, j = columna+1; i > -1; --i, ++j) {
        if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila-1][columna+1].get_estado() == color2) and (board[i+1][j-1].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int k = fila-1, l = columna+1; k > i; --k, ++l) {
                board[k][l].set_estado(color);
            }
        }


    }

    //mirar diagonalmente inferior derecha si se puede atrapar una ficha del oponente
    for (int i = fila+1, j = columna+1; i < 8; ++i, ++j) {
        if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila+1][columna+1].get_estado() == color2) and (board[i-1][j-1].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int k = fila+1, l = columna+1; k < i; ++k, ++l) {
                board[k][l].set_estado(color);
            }
        }
    }

    //mirar diagonalmente inferior izquierda si se puede atrapar una ficha del oponente
    for (int i = fila+1, j = columna-1; j > -1; ++i, --j) {
        if ((board[i][j].get_estado() == color) and (board[fila][columna].get_estado() != color2) and (board[fila+1][columna-1].get_estado() == color2) and (board[i-1][j+1].get_estado() == color2)){
            board[fila][columna].set_estado(color);
            for (int k = fila+1, l = columna-1; k < i; ++k, --l) {
                board[k][l].set_estado(color);
            }
        }
    }

}
char Class_board::get_estado_casilla(int fila, int columna){
    return board[fila][columna].get_estado();
}
int Class_board::contador_fichas(char color){
    int fichas;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (board[i][j].get_estado() = color){
                fichas += 1;
            }
        }
    }
    return fichas;
}


Class_board::~Class_board() {
    // Cuerpo del destructor (vacío en este caso)
}
