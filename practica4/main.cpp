
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
    }
    //While que saca los nombres y costos de los enrutadores para meterlos en los vectores.
    leer.close();

    enrutador red;
    red.modificacion(&costos[0],&nombres[0],n);
    red.calcularRutas();//Se calculan todas las mejores rutas de cada enrutador.

    while(true){
        int opcion=0;
        cout<<"Menu"<<endl<<"Ingrese un numero para acceder a las opciones:"<<endl
        <<"1.Agregar un nuevo enrutador."<<endl
        <<"2.Eliminar un enrutador"<<endl
        <<"3.Modificar costo de un enrutador a otro"<<endl
        <<"4.Conocer el costo de un enrutador a otro"<<endl;
        system("CLS");
        switch (opcion) {
        case 1:{
            string nombre;
            int costo=0;
            cout<<"Ingrese el nombre del enrutador: ";cin>>nombre;
            system("CLS");
            cout<<endl<<"El enrutador "<<nombre<<" se conectara a "<<nombres[n-1]<<" y a "
            <<nombres[0]<<endl;
            cout<<"Ingrese el costo que habra de  "<<nombre<<" a "<<nombres[n-1];cin>>costo;

            nombres.push_back(nombre);
            costos.push_back(costo);
            n+=1;
            red.modificacion(&costos[0],&nombres[0],n);
            red.calcularRutas();

            break;
        }
        }
    }



    cout<<"probando.."<<endl;

    nombres.erase(nombres.begin()+1);
    costos.erase(costos.begin()+1);
    n-=1;
    red.modificacion(&costos[0],&nombres[0],n);
    red.calcularRutas();

    cout<<"probando.."<<endl;

    return 0;
}

