
#include <iostream>
#include <vector>
#include <enrutador.h>
#include <string.h>
#include<fstream>
#include <cstdlib>

using namespace std;

#define DOC "doc.txt"



void lectura();

int main()
{
    vector<string> nombres;
    vector<int> costos;
    int n=0;//numero de enrutadores

    ifstream leer;

    try {
        leer.open(DOC);
        if(!leer.is_open())
            throw '1';
    }
    catch (char c) {
        if(c=='1')
            cout<<"Problema con la lectura del archivo de la red"<<endl;
    }

    string linea;

    while(getline(leer,linea)){
        string nombre;
        string costo;
        int separador=0;
        separador=linea.find(";");
        nombre=linea.substr(0,separador);
        costo=linea.substr(separador+1);
        nombres.push_back(nombre);
        costos.push_back(atoi(costo.c_str()));
        n+=1;
        cout<<"Se está leyendo"<<endl;
    }
    //While que saca los nombres y costos de los enrutadores para meterlos en los vectores.
    leer.close();


    enrutador red;
    red.modificacion(&costos[0],&nombres[0],n);
    red.calcularRutas();

    cout<<"probando.."<<endl;
    return 0;
}

