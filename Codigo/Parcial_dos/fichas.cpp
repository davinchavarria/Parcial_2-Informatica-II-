#include "fichas.h"


fichas::fichas(){
    estado = ' '; // Establece un valor predeterminado para el estado de la ficha

}

char fichas::get_estado(){
    char _estado = estado;
    return _estado;
}

void fichas::set_estado(char _estado){
    estado = _estado;
}

fichas::~fichas(){}
