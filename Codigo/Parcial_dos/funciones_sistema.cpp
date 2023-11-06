#include "funciones_sistema.h"
#include <iostream>
using namespace std;

int validar_opcion(int a, int b){
    int opcion;
    cout<<"\nPor favor digite una opcion: ";
    cin>>opcion;
    cout<<endl;
    while((opcion < a) or (opcion > b)){
        cout<<"\nEl numero ingresado no es valido"<<endl;
        cout<<"\nPor favor digite una nueva opcion: ";
        cin>>opcion;
        cout<<endl;
    }
    return opcion;
}
void visualizar_menu_principal(){
    cout<<"      OTHELLO(UN JUEGO DE ESTRATEGIA)      \n";
    cout<<"\n";
    cout<<"--------------------MENU-------------------\n";
    cout<<"1. INICIAR NUEVA PARTIDA.\n";
    cout<<"2. VER PARTIDAS ANTERIORES.\n";
    cout<<"3. FINALIZAR PROGRAMA.\n";
    cout<<"-------------------------------------------\n";

}

void seleccion_fichas(char* jugador1,char* jugador2){
    int opcion;

    cout<<"\n----------------------------------\n";
    cout<<"JUGADOR UNO POR FAVOR ELIJA EL COLOR DE SUS FICHAS \n";
    cout<<"1. Blanco(*) \n";
    cout<<"2. Negro(-) \n";
    cout<<"----------------------------------\n";

    opcion = validar_opcion(1,2);

    if(opcion == 1) {
        *jugador1 = '*';
        *jugador2 = '-';
    }
    else {
        *jugador1 = '-';
        *jugador2 = '*';
    }

}
bool verificar_colocar_fichas(Class_board *tablerito, char color){
    bool colocar_ficha = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (tablerito->atrapar_ficha(i, j, color)){
                colocar_ficha = true;
            }

        }
    }
    return colocar_ficha;

}

void seleccion_casilla(int* filas, char* columnas, char jugador, Class_board *tablerito){
    int fila;
    char columna;
    cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
    cout<<"MUEBEN LAS FICHAS '"<<jugador<<"'\n"<<endl;
    cout<<"Las casillas marcadas con 'O' son posiciones donde el jugador puede colocar una ficha. "<<endl;
    cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
    cout<<"Ingrese la fila en donde quiere poner la ficha";
    cin>>fila;
    cout<<"\nE ingrese la columna en donde quiere poner la ficha";
    cin>>columna;
    cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;

    while ((tablerito->get_estado_casilla(fila - 1, columna - 'A')) != 'O'){

        cout<<"En la posicion ingresada no se puede poner una ficha\n"<<endl;
        cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
        cout<<"MUEBEN LAS FICHAS '"<<jugador<<"'."<<endl;
        cout<<"Las casillas marcadas con 'O' son posiciones donde el jugador puede colocar una ficha. "<<endl;
        cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
        cout<<"Ingrese la fila en donde quiere poner la ficha";
        cin>>fila;
        cout<<"\nE ingrese la columna en donde quiere poner la ficha";
        cin>>columna;
        cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
    }

    *filas = fila - 1;
    *columnas = columna - 65;
}

void menu_principal(){
    Class_board Tablero;
    int opcion;
    char jugador1 = ' ', jugador2 = ' ';
    visualizar_menu_principal();
    opcion = validar_opcion(1,3);

    if (opcion == 1){
        cout<<"\n----------------------------------\n";
        cout<<"SE INICIO UNA NUEVA PARTIDA  \n";
        cout<<"----------------------------------\n";

        Tablero.imprimir_tablero();

        seleccion_fichas(&jugador1, &jugador2);
        char jugador = jugador1;
        while((verificar_colocar_fichas(&Tablero, jugador1) or verificar_colocar_fichas(&Tablero, jugador2)) or !Tablero.tablero_lleno()){
            int fila;
            char columna;
            Tablero.eliminar_O();
            cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
            cout<<"MUEBEN LAS FICHAS '"<<jugador<<"'\n"<<endl;
            cout<<"Las casillas marcadas con 'O' son posiciones donde el jugador puede colocar una ficha. "<<endl;
            cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;

            if (verificar_colocar_fichas(&Tablero, jugador)){
                Tablero.imprimir_tablero();
                seleccion_casilla(&fila, &columna, jugador,&Tablero);
                Tablero.atrapar_ficha_cambio(fila, columna, jugador);
                Tablero.eliminar_O();

            }
            else{
                cout<<"\n--------------------------------------------------------------------------------------\n";
                cout<<"El jugador no puede poner ninguna ficha, se le sedera el turno al siguiente jugador\n";
                cout<<"--------------------------------------------------------------------------------------\n";
            }

            Tablero.eliminar_O();

            if (jugador == jugador1){
                jugador = jugador2;
            }
            else{
                jugador = jugador1;
            }
        }

        menu_principal();

    }
    else if(opcion == 2){
        cout<<"ahorita no se puede usar\n";
        menu_principal();

    }
    else {
        cout<<"-------------------------------\n";
        cout<<"   HAZ FINALIZADO EL PROGRA    \n";
        cout<<"      TE ESPERAMOS PRONTO      \n";
        cout<<"-------------------------------\n";

    }
}

