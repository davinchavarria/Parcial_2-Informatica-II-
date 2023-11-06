#include <iostream>
#include "class_board.h"

using namespace std;

int main()
{
    Class_board uno, dos;
    uno.poner_ficha(1,2,'-');
    uno.imprimir_tablero();
    dos.imprimir_tablero();
    return 0;
}
