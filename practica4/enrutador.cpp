#include "enrutador.h"

enrutador::enrutador(){
}

void enrutador::modificacion(int *_costo, string *_nombre, int _numeroEnrutadores)
{
    costo=_costo;
    nombre=_nombre;
    numeroEnrutadores=_numeroEnrutadores;
}



void enrutador::calcularRutas(){
    if(!rutas.empty()){
        rutas.clear();
    }
    for(int i=0;i<numeroEnrutadores;i++){
        for(int j=0;j<numeroEnrutadores;j++){
            if(i==j) rutas.push_back(0);
            else{
                int saltos=0;
                int temp=i;
                while(true){
                    if(temp==numeroEnrutadores-1){
                        temp=0;
                        saltos+=1;
                    }
                    else{
                        temp+=1;
                        saltos+=1;
                    }
                    if(temp==j){
                        break;
                    }
                }
                /*While que calcula la cantidad de saltos que debe dar la información que circula
                para ir de un enrutador a otro*/


                temp=i;
                int temp1=0,temp2=0;
                for(int k=0;k<saltos;k++){
                    if(temp==numeroEnrutadores-1){
                        temp1+=*(costo+temp);
                        temp=0;
                    }
                    else{
                        temp1+=*(costo+temp);
                        temp+=1;
                    }
                }
                /*Calcula el costo que tiene ir a un enrutador destino en el sentido de las
                manecillas del reloj*/

                temp=i;
                for(int k=0;k<numeroEnrutadores-saltos;k++){
                    if(temp==0){
                        temp2+=*(costo+numeroEnrutadores-1);
                        temp=numeroEnrutadores-1;
                    }
                    else{
                        temp2+=*(costo+temp-1);
                        temp-=1;
                    }
                }
                /*Calcula el costo que tiene ir a un enrutador destino en el sentido contrario
                a las manecillas del reloj*/

                if(temp1<temp2) rutas.push_back(temp1+0.1);
                else rutas.push_back(temp2);
                //Verifica la ruta con menor costo
                //+0.1 sentido las manecillas del reloj, +0 sentido contrario a las manecillas
            }
        }
    }
}
