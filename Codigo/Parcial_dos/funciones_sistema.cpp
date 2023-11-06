#include "funciones_sistema.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <limits>
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
            if ((tablerito->get_estado_casilla(i,j) != '*') and (tablerito->get_estado_casilla(i,j) != '-')){
                if (tablerito->atrapar_ficha(i, j, color)){
                    colocar_ficha = true;
                }
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
    cout<<"Ingrese la fila en donde quiere poner la ficha: ";
    cin>>fila;
    cout<<"\nE ingrese la columna en donde quiere poner la ficha: ";
    cin>>columna;
    cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;

    while ((tablerito->get_estado_casilla(fila - 1, columna - 'A')) != 'O'){

        cout<<"En la posicion ingresada no se puede poner una ficha\n"<<endl;
        cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
        cout<<"MUEBEN LAS FICHAS '"<<jugador<<"'."<<endl;
        cout<<"Las casillas marcadas con 'O' son posiciones donde el jugador puede colocar una ficha. "<<endl;
        cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
        cout<<"Ingrese la fila en donde quiere poner la ficha: ";
        cin>>fila;
        cout<<"\nE ingrese la columna en donde quiere poner la ficha: ";
        cin>>columna;
        cout<<"\n----------------------------------------------------------------------------------------\n"<<endl;
    }

    *filas = fila - 1;
    *columnas = columna - 65;
}
char ganador(Class_board *tablerito, char jugador1, char jugador2){
    int ganador;
    if (tablerito->contador_fichas(jugador1) > tablerito->contador_fichas(jugador2)){
        ganador = jugador1;
    }
    else if(tablerito->contador_fichas(jugador1) < tablerito->contador_fichas(jugador2)) {
        ganador = jugador2;
    }
    else{
        ganador = 'O';
    }
    return ganador;
}

void guardar_data(char jugador1, char ganador, int cantidad_fichas){
    ofstream archivo;
    char nombre1[100];
    char nombre2[100];
    char jugador2;
    time_t tiempoActual;
    struct tm* tiempoInfo;
    char buffer[80];

    time(&tiempoActual); // Obtiene el tiempo actual
    tiempoInfo = localtime(&tiempoActual); // Convierte a estructura tm

    // Formatea y muestra la fecha y hora
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempoInfo);


    cout<<"\nIngresar nombre del jugador 1: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(nombre1, 100);
    cout<<"Ingresar nombre del jugador 2: ";
    cin.getline(nombre2, 100);
    cout<<endl;

    if ('*' == jugador1){
        jugador2 = '-';
    }
    else{
        jugador2 = '*';
    }

    archivo.open("C:\\Users\\DAVIN CHAVARRIA\\Downloads\\data.txt",ios::app);

    if(archivo.fail()){
        cout<<"No se pudo guardar la informacion";
        exit(1);
    }

    if (ganador == jugador1){
        archivo<<"El "<<buffer<<" el ganador fue "<<nombre1<<" con un total de fichas de "<<cantidad_fichas<<" en contra del jugador "<<nombre2<<"\n";
    }
    else if (ganador == jugador2){
        archivo<<"El "<<buffer<<" el ganador fue "<<nombre2<<" con un total de fichas de "<<cantidad_fichas<<" en contra del jugador "<<nombre1<<"\n";
    }
    else{
        archivo<<"El "<<buffer<<" se dio un empate entre "<<nombre1<<" y "<<nombre2<<"\n";
    }

    archivo.close();
}

void Imprimir_data(){
    ifstream archivo;
    char linea[292];

    archivo.open("C:\\Users\\DAVIN CHAVARRIA\\Downloads\\data.txt",ios::in);//Abrimos el archivo en modo de lectura

    if (archivo.fail()){//si ocurre algun error al tratar de abrir el archivo
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);//salimos de la funcion
    }


    while(!archivo.eof()){//mientras que  no sea el final del archivo
        archivo.getline(linea,292);//obtenemos el contenido de las lineas del archivo
        cout<< linea<<"\n";//almacenamos las lineas para no perder informacion
    }
    cout<<endl;
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
        if (ganador(&Tablero, jugador1, jugador2) == jugador1){
            cout<<"\n----------------------------------------------------------------------------------------------\n";
            cout<<"Felicidades el ganador es el jugador 1 con "<<Tablero.contador_fichas(jugador1)<<" fichas"<<endl;
            cout<<"----------------------------------------------------------------------------------------------\n";
        }
        else if(ganador(&Tablero, jugador1, jugador2) == jugador2){
            cout<<"\n----------------------------------------------------------------------------------------------\n";
            cout<<"Felicidades el ganador es el jugador 2 con "<<Tablero.contador_fichas(jugador2)<<" fichas"<<endl;
            cout<<"----------------------------------------------------------------------------------------------\n";
        }
        else{
            cout<<"\n----------------------------------------------------------------------------------------------\n";
            cout<<"Se dio un empate con una cantidad de"<<Tablero.contador_fichas(jugador2)<<" fichas"<<endl;
            cout<<"----------------------------------------------------------------------------------------------\n";
        }

        guardar_data(jugador1, ganador(&Tablero, jugador1, jugador2), Tablero.contador_fichas(ganador(&Tablero, jugador1, jugador2)));

        menu_principal();

    }
    else if(opcion == 2){
        cout<<"\n---------------------------------------\n";
        cout<<"            PARTIDAS ANTERIORES\n";
        cout<<"---------------------------------------\n";
        Imprimir_data();
        menu_principal();

    }
    else {
        cout<<"------------------------------------------\n";
        cout<<"HAZ FINALIZADO EL PROGRA    \n";
        cout<<"------------------------------------------\n";

    }
}

