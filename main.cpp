#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "tpPruebasFunciones.h"
#include <windows.h>

using namespace std;

/// NO DECLARAR NINGUNA VARIABLE GLOBAL SOLO HACER PASAJE POR REFERENCIA.


int main()
{


    srand(time(NULL));
    string nombreJugadorUno = "", nombreJugadorDos = "";


    menuEmbaucado();

    eligiendoOpcionesMenu(nombreJugadorUno, nombreJugadorDos);

    return 0;
}














/*
void repartiendo ( int vecJugUnoNaipe [5], string vecJugUnoFig [5],string vecJugUnoNaipeFig [5], int JUGADOR_CORRESPONDIENTE  )
    {

    string cartaEmbaucadora;
    int azar, azar2, azar1, puntaje = 0, mezclar, mezclar1, mezclar2, i = 0;
    int limite_inferior = 10,  limite_superior = 20;

    //int cont = 0;
    cartaEmbaucadora = repartidor();



    while (i < 5)
    {


        azar1 = limite_inferior + rand () % (limite_superior + 1 - limite_inferior);
        //azar2 = limite_inferior + rand () % (limite_superior + 1 - limite_inferior);

        mezclar1 = 1 + rand () % (4 );
        //mezclar2 = 1 + rand () % (4 );



        if(660 % azar1 == 0 ){
            // con este algoritmo se logra seleccionar solo los numeros que spon multiplos de 660 que es el MCM de 10, 11,12, 15 y 20.
          //cont++;
          if (JUGADOR_CORRESPONDIENTE ==1){
          vecJugUnoNaipe [i] = azar1;
          mezclar = mezclar1;
          azar = azar1;
          cout << "azar1 " << azar1 <<endl;

          }else {
          vecJugUnoNaipe [i] = azar1;
          mezclar = mezclar1;
          azar = azar1;
          cout << "azar1 " << azar1 <<endl;
          }
          switch (mezclar){
        case 1:
            vecJugUnoFig [i] = "de corazon ";
            break;
        case 2 :
            vecJugUnoFig [i] = "de diamante";
            break;
        case 3 :
            vecJugUnoFig [i] = "de pica    ";
            break;
        case 4 :
            vecJugUnoFig [i] = "de trebol  ";
        }
        switch(azar){
            // se crea vector para nombrar a cada naipe y hacerlo coincidir con vector de puntajes, vecJugUnoNaipe [i]
        case 10:
            vecJugUnoNaipeFig[i] ="10";
            break;
        case 11:
            vecJugUnoNaipeFig[i] ="J ";
            break;
        case 12:
            vecJugUnoNaipeFig[i] ="Q ";
            break;
        case 15:
            vecJugUnoNaipeFig[i] ="K ";
            break;
        case 20:
            vecJugUnoNaipeFig[i] ="A ";
            break;



        }
        if (vecJugUnoFig [i] != cartaEmbaucadora )
        {
            // suma solo las cartas que no coinciden ocn embaucador
        puntaje+= vecJugUnoNaipe[i];

        }else {
            // se asigna 0 cuando coincide con embaucadora para que el jugador entienda que se le estan descontando puntos
        vecJugUnoNaipe [i]= 0;
        }

          i++;
        }


    }

    cout << " Cartas jugador "  << JUGADOR_CORRESPONDIENTE << ":"    <<"        valor carta" << endl;
    for (i=0; i<5; i++)
    {
        cout << vecJugUnoNaipeFig[i] <<"   "   << vecJugUnoFig [i] << "          |    "   << vecJugUnoNaipe [i] << "     " << endl;
    }
    cout << endl;
    cout << "El puntaje total de la ronda para jugador " << JUGADOR_CORRESPONDIENTE   <<  " es:  "   << puntaje << endl;
    cout << azar1 << endl;
    cout << azar2 << endl;

    }


*/










    /*void cargarVector (int vector [10])
    {
        int i;
        for (i=0; i<10; i++)
        {
            vector [i] = i;
        }
        cout << " el vector  cargado es " << vector [i] << endl;
    }
    void mostrarVector (int vec [10])
    {
        int i;
        for (i=0; i<10; i++)
            cout << vec [i] << endl;
    }
*/
