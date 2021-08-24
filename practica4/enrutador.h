
#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

class enrutador
{
private:
    int * costo;
    string * nombre;
    int numeroEnrutadores;
    vector<float> rutas;
public:
    enrutador();
    void modificacion(int * _costo, string * _nombre, int _numeroEnrutadores);
    void calcularRutas();
};

#endif // ENRUTADOR_H
