#ifndef TPPRUEBASFUNCIONES_H_INCLUDED
#define TPPRUEBASFUNCIONES_H_INCLUDED
#include <windows.h>
#include <vector>
using namespace std;

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void menuEmbaucado ();
void registroJugadores (void menuEmbaucado(), string& nombreJugadorUno, string& nombreJugadorDos);
void eligiendoOpcionesMenu (string nombreJugadorUno, string nombreJugadorDos);
string mezcladorEmbaucada ();
void jugarPartida (string nombreJugUno, string nombreJugDos,string& ganadorRondaUno, string& ganadorRondaDos, string& ganadorRondaTres,int& puntajeRondaUno, int& puntajeRondaDos, int& puntajeTotalJugUno, int& puntajeTotalJugDos, int& ronda, int& puntajeTotalEstadistica, string& nombreJugEstadistica);
void repartiendo ( int vecNaipe [5], string vecFig [5],string vecPalo [5], string jugadorCorrespondiente, string embaucador, int& puntajeRonda, int vecMostrarNaipe[5]);

void estadisticasPartida (string nombreJugUno, string nombreJugDos, string ganadorRondaUno, string ganadorRondaDos,string ganadorRondaTres, int puntajeTotalUno, int puntajeTotalDos, int ronda, int puntajeTotalEstadistica, string nombreJugEstadistica, int partida, vector <int>vecPuntajeTotalEstadistica, vector <string>vecNombreJugEstadistica);
void comparaEmbaucado (string elemento, string embaucador, int elementoNaipe, int& puntajeRonda, int& elementoMostrarNaipe);
void generandoTablero (int puntajeTotalUno,int puntajeTotalDos , string cartaEmbaucadora, string nombreJugUno, string nombreJugDos, int vecJugUnoNaipe[5], int vecJugDosNaipe[5], string vecJugUnoFig[5], string vecJugDosFig[5], string vecJugUnoPalo[5], string vecJugDosPalo[5], int puntajeRondaUno, int puntajeRondaDos, int vecMostrarNaipeUno[5], int vecMostrarNaipeDos[5]);
void remezcladorEmbaucadora (int& puntajeRonda, int& puntajeTotal, string embauca, string VecFig [5], int VecNaipe [5], int vecMostrarNaipe [5]);
void mostrarPuntajeRonda(string nombreJugUno, string nombreJugDos, int puntajeRondaUno, int puntajeRondaDos, int vecJugUnoNaipe [5], int vecJugDosNaipe [5], int vecMostrarNaipeUno[5], int vecMostrarNaipeDos[5]);
void mostrarPuntajeTotal (string nombreJugUno, string nombreJugDos, int& puntajeRondaUno, int& puntajeRondaDos, int& puntajeTotalUno, int& puntajeTotalDos, int ronda);
void comparaVectores(int vecJugUnoNaipe[5],int vecJugDosNaipe[5], string vecJugUnoPalo[5], string vecJugDosPalo[5], string vecJugUnoFig[5],string vecJugDosFig[5],string nombreJugUno, string nombreJugDos, string y, int vecMostrarNaipeUno[5], int vecMostrarNaipeDos[5],int& puntajeRondaUno, int& puntajeRondaDos);
int maxPuntajeTotal (int pjeRondaUno, int pjeRondaDos, int pjeRondaTres);
void creditosDesarrollador();
void confirmacionInicio (char& confirmar, string nombreJugUno, string nombreJugDos);
void respuestaErronea (string& respuesta);


void menuEmbaucado ()
{

    system("cls");
    cout << "      EMBAUCADO      " << endl;
    cout << "------------------------------" << endl;
    cout << "1 - JUGAR " << endl;
    cout << "2 - ESTADISTICAS " << endl;
    cout << "3 - CREDITOS  " << endl;
    cout << "------------------------------" << endl;
    cout << "0 - SALIR  " << endl << endl;


}

void respuestaErronea (string& respuesta)
{
    while (respuesta != "S" && respuesta != "s" && respuesta != "N" && respuesta != "n")
    {
        cout << "Por favor introduzca una respuesta valida " << endl;
        cout << "Desea cambiar carta embaucadora?" << endl;
        cin >> respuesta;

    }
}

void registroJugadores (void menuEmbaucado(), string& nombreJugadorUno, string& nombreJugadorDos)
{

    char confirmar;


    cout << "Antes de comenzar, por favor, registren sus nombres " << endl << endl;
    cout << "Nombre del jugador 1? " << endl;
    cin >> nombreJugadorUno;
    cout << "Nombre del jugador 2?" << endl;
    cin >> nombreJugadorDos;
    cout << " Confirmar nombres? (S/N)" << endl;
    cin >> confirmar;
    confirmacionInicio (confirmar, nombreJugadorUno, nombreJugadorDos);

}
void confirmacionInicio (char& confirmar, string nombreJugUno, string nombreJugDos)

{
    while (confirmar !='S' && confirmar != 's')
    {

    if (confirmar == 'N' || confirmar == 'n')
    {
    while(confirmar == 'N' || confirmar == 'n' ){

    //system("cls");
    menuEmbaucado();
    cout << "Corrija nombre " << endl;
    cout << "Nombre del jugador 1?" << endl;
    cin >> nombreJugUno;
    cout << "Nombre del jugador 2?" << endl;
    cin >> nombreJugDos;
    cout << " Confirmar nombres? (S/N)" << endl;
    cin >> confirmar;
    }
    }
    else
    {
    system("cls");
    //menuEmbaucado();
    cout << " Respuesta invalida, vuelva a intentarlo" << endl;
    cout << " Confirmar nombres? (S/N)" << endl;
    cin >> confirmar;
    }
    }

}


void eligiendoOpcionesMenu (string nombreJugadorUno, string nombreJugadorDos)
    {
        int ronda = 0;
        int repetirOpciones = 1;
        int puntajeRondaUno = 0, puntajeRondaDos = 0;
        int puntajeTotalJugUno = 0, puntajeTotalJugDos = 0;
        string ganadorUno, ganadorDos = "", ganadorTres ;
        int partida = 0;
        int puntajeTotalEstadistica;
        string nombreJugEstadistica;

        vector <int>vecPuntajeTotalEstadistica;
        vector <string>vecNombreJugEstadistica;




        while(repetirOpciones != 0){

        int opcion;

        cout << " Elija opcion del menu" << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("cls");
            registroJugadores(menuEmbaucado, nombreJugadorUno, nombreJugadorDos);
            system("cls");
            ronda = 0;
            partida ++;
            jugarPartida(nombreJugadorUno, nombreJugadorDos, ganadorUno, ganadorDos, ganadorTres, puntajeRondaUno, puntajeRondaDos, puntajeTotalJugUno, puntajeTotalJugDos, ronda, puntajeTotalEstadistica,  nombreJugEstadistica);
            for(int k =partida - 1 ; k < partida; k++)
                {
                vecPuntajeTotalEstadistica.push_back(puntajeTotalEstadistica);
                vecNombreJugEstadistica.push_back (nombreJugEstadistica);
                }
            system("pause");
            system("cls");
            menuEmbaucado();
            break;
        case 2:
            system("cls");
            estadisticasPartida (nombreJugadorUno, nombreJugadorDos,ganadorUno, ganadorDos, ganadorTres, puntajeRondaUno, puntajeRondaDos, ronda, puntajeTotalEstadistica,  nombreJugEstadistica, partida, vecPuntajeTotalEstadistica,vecNombreJugEstadistica);

            system("pause");
            menuEmbaucado();

            break;
        case 3:
            system("cls");
            creditosDesarrollador();
            system("pause");
            system("cls");
            menuEmbaucado();
            break;
        case 0:
            repetirOpciones = 0;
            break;
        default :
            system("cls");
            menuEmbaucado();
            cout << " Opcion erronea " << endl;

            repetirOpciones = 1;
            break;
        }
        }
    }


string mezcladorEmbaucada (){
     //system("cls");
    string embaucador;
    int mezclar, limite_inferior = 1, limite_superior = 4;

    mezclar = limite_inferior + rand () % (limite_superior + 1 - limite_inferior);
    switch (mezclar)
    {

        case 1 : embaucador = "de corazon ";
        break;
        case 2 : embaucador = "de diamante";
        break;
        case 3 : embaucador = "de pica    ";;
        break;
        case 4 : embaucador = "de trebol  ";
        break;


    }

    return embaucador;

}



void jugarPartida (string nombreJugUno, string nombreJugDos,string& ganadorRondaUno, string& ganadorRondaDos, string& ganadorRondaTres, int& puntajeRondaUno, int& puntajeRondaDos, int& puntajeTotalUno, int& puntajeTotalDos, int& ronda, int& puntajeTotalEstadistica, string& nombreJugEstadistica)
{
    int comodinJugadorUno = 0, comodinJugadorDos = 0;
    //int u;
    string y;

    int i = 0;
    string j;
    int vecJugUnoNaipe [5], vecJugDosNaipe [5], vecMostrarNaipeUno [5], vecMostrarNaipeDos [5];
    string vecJugUnoFig [5], vecJugDosFig [5];
    string vecJugUnoPalo [5], vecJugDosPalo [5];
    string respuesta;

    int puntajeRondaUnoJugUno, puntajeRondaUnoJugDos, puntajeRondaDosJugUno, puntajeRondaDosJugDos, puntajeRondaTresJugUno, puntajeRondaTresJugDos;

     puntajeTotalUno = 0;
     puntajeTotalDos = 0;
    while(ronda <3)
    {


        system("cls");
        ronda++;
        cout <<"   Ronda # "<< ronda << endl;
        cout << "   " << nombreJugUno << " vs " << nombreJugDos << endl << endl;
        y = mezcladorEmbaucada();

        comparaVectores(vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoPalo, vecJugDosPalo, vecJugUnoFig, vecJugDosFig, nombreJugUno, nombreJugDos, y, vecMostrarNaipeUno, vecMostrarNaipeDos, puntajeRondaUno, puntajeRondaDos);

        generandoTablero ( puntajeTotalUno, puntajeTotalDos, y, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig,vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);
        mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);
        cout << endl;


        switch(ronda)
        {


        case 1:

            puntajeTotalUno += puntajeRondaUno;
            puntajeTotalDos += puntajeRondaDos;
            mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
           //system("pause");
            //generandoTablero (y, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig,vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);
            //cout << " De aca sale otra vez al comienzo del while, no comprendo porque no va al otro switch" << endl;
            //system("pause");
            puntajeRondaUnoJugUno = puntajeRondaUno;
            puntajeRondaUnoJugDos = puntajeRondaDos;


            break;


        case 2:


            cout << "Jugador " << nombreJugUno << " desea cambiar carta embaucadora?" << endl;
            cout << "Le costara 20 puntos (S/N)" << endl;
            cin >> respuesta;
                if((respuesta == "S" || respuesta == "s" )&& puntajeTotalUno >= 20)
                {
                    system("cls");///  nuevo
                comodinJugadorUno++;
                puntajeTotalUno = puntajeTotalUno - 20;

                cout << "Puntaje jugador " << nombreJugUno << " restandole 20 puntos es: " << puntajeTotalUno << endl;
                cout << "Puntaje jugador " << nombreJugDos << "  : " << puntajeTotalDos << endl;
                j = mezcladorEmbaucada();
                cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | El embaucador nuevo es : "  << j << "                                                                |"  << endl;
                cout << " +-----------------------------------------------------------------------------------------------------+" << endl;

                cout << "//////////////////////////"<< endl;
                remezcladorEmbaucadora (puntajeRondaUno, puntajeTotalUno, j, vecJugUnoFig, vecJugUnoNaipe, vecMostrarNaipeUno);
                remezcladorEmbaucadora (puntajeRondaDos, puntajeTotalDos, j, vecJugDosFig, vecJugDosNaipe, vecMostrarNaipeDos);
                //system("cls");
                generandoTablero (puntajeTotalUno, puntajeTotalDos, j, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig, vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);
                mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);

                cout << "El nuevo puntaje para los jugadores es : " << endl;
                mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);


                puntajeRondaDosJugUno = puntajeRondaUno;
                puntajeRondaDosJugDos = puntajeRondaDos;

                }
                else if (respuesta == "N" || respuesta == "n")
                {
                cout << "Jugador " << nombreJugDos << " desea cambiar carta embaucadora?" << endl;
                cout << "Le costara 20 puntos (S/N)" << endl;
                cin >> respuesta;

                    if ((respuesta == "S" || respuesta == "s") && puntajeTotalDos >= 20)
                    {
                    system("cls");
                    comodinJugadorDos++;
                    puntajeTotalDos = puntajeTotalDos - 20;
                    cout << "Puntaje jugador " << nombreJugDos << " restandole 20 puntos es: " << puntajeTotalDos << endl;
                    cout << "Puntaje jugador " << nombreJugUno << " : " << puntajeTotalUno << endl;
                    j = mezcladorEmbaucada();
                    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                    cout << " | El embaucador nuevo es : "  << j << "                                                                |"  << endl;
                    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                    //cout << "//////////////////////////"<< endl;
                    remezcladorEmbaucadora (puntajeRondaUno, puntajeTotalUno, j, vecJugUnoFig, vecJugUnoNaipe, vecMostrarNaipeUno);
                    remezcladorEmbaucadora (puntajeRondaDos, puntajeTotalDos, j, vecJugDosFig, vecJugDosNaipe, vecMostrarNaipeDos);
                    generandoTablero (puntajeTotalUno, puntajeTotalDos, j, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig, vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);

                    mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);
                    cout << "El nuevo puntaje para los jugadores es : " << endl;
                    mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
                    //system("pause");
                    puntajeRondaDosJugUno = puntajeRondaUno;
                    puntajeRondaDosJugDos = puntajeRondaDos;
                    }else if (respuesta == "N" || respuesta == "n")
                    {
                    puntajeTotalUno += puntajeRondaUno;
                    puntajeTotalDos += puntajeRondaDos;
                    mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
                    //system("pause");
                    puntajeRondaDosJugUno = puntajeRondaUno;
                    puntajeRondaDosJugDos = puntajeRondaDos;

                    }
 /*                   else {
                     respuestaErronea (respuesta);
                    }
*//// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                }else {
                     respuestaErronea (respuesta); /// en caso de no querer la validacion debo sacar todo lo que copie debajo de respuestaErronea.
                     if((respuesta == "S" || respuesta == "s" )&& puntajeTotalUno >= 20)
                {
                    system("cls");
                comodinJugadorUno++;
                puntajeTotalUno = puntajeTotalUno - 20;

                cout << "Puntaje jugador " << nombreJugUno << " restandole 20 puntos es: " << puntajeTotalUno << endl;
                cout << "Puntaje jugador " << nombreJugDos << " : " << puntajeTotalDos << endl;
                j = mezcladorEmbaucada();
                cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | El embaucador nuevo es : "  << j << "                                                                |"  << endl;
                cout << " +-----------------------------------------------------------------------------------------------------+" << endl;

                cout << "//////////////////////////"<< endl;
                remezcladorEmbaucadora (puntajeRondaUno, puntajeTotalUno, j, vecJugUnoFig, vecJugUnoNaipe, vecMostrarNaipeUno);
                remezcladorEmbaucadora (puntajeRondaDos, puntajeTotalDos, j, vecJugDosFig, vecJugDosNaipe, vecMostrarNaipeDos);
                //system("cls");
                generandoTablero (puntajeTotalUno, puntajeTotalDos, j, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig, vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);
                mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);

                cout << "El nuevo puntaje para los jugadores es : " << endl;
                mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);


                puntajeRondaDosJugUno = puntajeRondaUno;
                puntajeRondaDosJugDos = puntajeRondaDos;

                }
                else if (respuesta == "N" || respuesta == "n")
                {
                cout << "Jugador " << nombreJugDos << " desea cambiar carta embaucadora?" << endl;
                cout << "Le costara 20 puntos (S/N)" << endl;
                cin >> respuesta;

                    if ((respuesta == "S" || respuesta == "s") && puntajeTotalDos >= 20)
                    {
                    system("cls");
                    comodinJugadorDos++;
                    puntajeTotalDos = puntajeTotalDos - 20;
                    cout << "Puntaje jugador " << nombreJugDos << " restandole 20 puntos es: " << puntajeTotalDos << endl;
                    cout << "Puntaje jugador " << nombreJugUno << " : " << puntajeTotalUno << endl;
                    j = mezcladorEmbaucada();
                    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                    cout << " | El embaucador nuevo es : "  << j << "                                                                |"  << endl;
                    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                    //cout << "//////////////////////////"<< endl;
                    remezcladorEmbaucadora (puntajeRondaUno, puntajeTotalUno, j, vecJugUnoFig, vecJugUnoNaipe, vecMostrarNaipeUno);
                    remezcladorEmbaucadora (puntajeRondaDos, puntajeTotalDos, j, vecJugDosFig, vecJugDosNaipe, vecMostrarNaipeDos);
                    generandoTablero (puntajeTotalUno, puntajeTotalDos, j, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig, vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);

                    mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);
                    cout << "El nuevo puntaje para los jugadores es : " << endl;
                    mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
                    //system("pause");
                    puntajeRondaDosJugUno = puntajeRondaUno;
                    puntajeRondaDosJugDos = puntajeRondaDos;
                    }else if (respuesta == "N" || respuesta == "n")
                    {
                    puntajeTotalUno += puntajeRondaUno;
                    puntajeTotalDos += puntajeRondaDos;
                    mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
                    //system("pause");
                    puntajeRondaDosJugUno = puntajeRondaUno;
                    puntajeRondaDosJugDos = puntajeRondaDos;

                    }else {
                    respuestaErronea (respuesta);
                    }

                }else {
                     respuestaErronea (respuesta);


                    }
                    }

            break;
        case 3:

            cout << "Jugador " << nombreJugDos << " desea cambiar carta embaucadora?" << endl;
            cout << "Le costara 20 puntos (S/N)" << endl;
            cin >> respuesta;
            if(respuesta == "S" || respuesta == "s")
            {
                system("cls");
                comodinJugadorDos++;
                puntajeTotalDos = puntajeTotalDos - 20;
                cout << "Puntaje jugador " << nombreJugDos << " restandole 20 puntos es: " << puntajeTotalDos << endl;
                cout << "Puntaje jugador " << nombreJugUno << " : " << puntajeTotalUno << endl;
                j = mezcladorEmbaucada();
                cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | El embaucador nuevo es : "  << j << "                                                                |"  << endl;
                cout << " +-----------------------------------------------------------------------------------------------------+" << endl;

                //cout << "//////////////////////////"<< endl;
                remezcladorEmbaucadora (puntajeRondaUno, puntajeTotalUno, j, vecJugUnoFig, vecJugUnoNaipe, vecMostrarNaipeUno);
                remezcladorEmbaucadora (puntajeRondaDos, puntajeTotalDos, j, vecJugDosFig, vecJugDosNaipe, vecMostrarNaipeDos);

                generandoTablero (puntajeTotalUno, puntajeTotalDos, j, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig, vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);

                mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);

                puntajeRondaTresJugUno =  puntajeRondaUno;
                puntajeRondaTresJugDos =  puntajeRondaDos;

                //cout << "El nuevo puntaje para los jugadores es : " << endl;
                mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
                //system("pause");
            }
            else if (respuesta == "N" || respuesta == "n")
            {
                cout << "Jugador " << nombreJugUno << " desea cambiar carta embaucadora?" << endl;
                cout << "Le costara 20 puntos (S/N)" << endl;
                cin >> respuesta;
                if (respuesta == "S" || respuesta == "s")
                {
                    system("cls");
                    comodinJugadorUno++;
                    puntajeTotalUno = puntajeTotalUno - 20;
                    cout << "Puntaje jugador " << nombreJugUno << " restandole 20 puntos es: " << puntajeTotalUno << endl;
                    cout << "Puntaje jugador " << nombreJugDos << " : " << puntajeTotalDos << endl;
                    j = mezcladorEmbaucada();
                    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                    cout << " | El embaucador nuevo es : "  << j << "                                                                |"  << endl;
                    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
                    //cout << "//////////////////////////"<< endl;
                    remezcladorEmbaucadora (puntajeRondaDos, puntajeTotalDos, j, vecJugDosFig, vecJugDosNaipe, vecMostrarNaipeDos);
                    remezcladorEmbaucadora (puntajeRondaUno, puntajeTotalUno, j, vecJugUnoFig, vecJugUnoNaipe, vecMostrarNaipeUno);
                    generandoTablero (puntajeTotalUno, puntajeTotalDos, j, nombreJugUno, nombreJugDos, vecJugUnoNaipe, vecJugDosNaipe, vecJugUnoFig, vecJugDosFig, vecJugUnoPalo, vecJugDosPalo, puntajeRondaUno, puntajeRondaDos, vecMostrarNaipeUno, vecMostrarNaipeDos);

                    mostrarPuntajeRonda (nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, vecJugUnoNaipe, vecJugDosNaipe, vecMostrarNaipeUno, vecMostrarNaipeDos);

                    puntajeRondaTresJugUno =  puntajeRondaUno;
                    puntajeRondaTresJugDos =  puntajeRondaDos;
                    cout << "El nuevo puntaje para los jugadores es : " << endl;
                    mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);



                }
                else
                {
                    puntajeTotalUno += puntajeRondaUno;
                    puntajeTotalDos += puntajeRondaDos;
                    mostrarPuntajeTotal(nombreJugUno, nombreJugDos, puntajeRondaUno, puntajeRondaDos, puntajeTotalUno, puntajeTotalDos, ronda);
                    puntajeRondaTresJugUno =  puntajeRondaUno;
                    puntajeRondaTresJugDos =  puntajeRondaDos;

                }


            }
            break;

            system("pause");

        }


        switch(ronda)
        {
        case 1:
                if (puntajeRondaUno > puntajeRondaDos)
                {
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El ganador de la ronda es : " << nombreJugUno << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El nuevo puntaje para los jugadores es : " << endl;

                    system("pause");
                }
                else
                {
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El ganador de la ronda es : " << nombreJugDos << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    ganadorRondaUno = nombreJugDos;
                    system("pause");
                    }
            break;

        case 2:
                if (puntajeRondaUno > puntajeRondaDos)
                {
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El ganador de la ronda es : " << nombreJugUno << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    ganadorRondaDos = nombreJugUno;
                    system("pause");
                }
                else
                {
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El ganador de la ronda es : " << nombreJugDos << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    ganadorRondaDos = nombreJugDos;
                    system("pause");
                }
            break;
        case 3:
                if (puntajeRondaUno > puntajeRondaDos)
                {
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El ganador de la ronda es : " << nombreJugUno << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    ganadorRondaTres = nombreJugUno;
                    system("pause");
                }
                else
                {
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "El ganador de la ronda es : " << nombreJugDos << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                    ganadorRondaTres = nombreJugDos;
                    system("pause");
                }
            break;
        }


    }
    system("cls");

        cout << "+-------------------------------------------------+" << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "RONDA              " << nombreJugUno << "          " << nombreJugDos << endl;
        cout << "  1                " << puntajeRondaUnoJugUno << "           " << puntajeRondaUnoJugDos << endl;
        cout << "  2                " << puntajeRondaDosJugUno << "           " << puntajeRondaDosJugDos << endl;
        cout << "  3                " << puntajeRondaTresJugUno << "           " << puntajeRondaTresJugDos << endl;
        cout << "Sacrificio(-20)    " << comodinJugadorUno << "            " << comodinJugadorDos << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "TOTAL              " << puntajeTotalUno << "          " << puntajeTotalDos << endl;
        cout << "+-------------------------------------------------+" << endl <<endl;
        if(puntajeTotalUno > puntajeTotalDos)
        {
            cout << "+-------------------------------------------------+" << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << " El ganador de la partida es: " << nombreJugUno << endl;
            cout << "+-------------------------------------------------+" << endl << endl;

            puntajeTotalEstadistica = puntajeTotalUno;
            nombreJugEstadistica = nombreJugUno;
        }
        else if (puntajeTotalDos > puntajeTotalUno)
        {
            cout << "+-------------------------------------------------+" << endl;
            cout << " El ganador de la partida es: " << nombreJugDos << endl;
            cout << "+-------------------------------------------------+" << endl << endl;

            puntajeTotalEstadistica = puntajeTotalDos;
            nombreJugEstadistica = nombreJugDos;
        }else {

        if (maxPuntajeTotal(puntajeRondaUnoJugUno,puntajeRondaDosJugUno, puntajeRondaTresJugUno)> maxPuntajeTotal(puntajeRondaUnoJugDos,puntajeRondaDosJugDos, puntajeRondaTresJugDos))
           {
               cout << "Jugador " << nombreJugUno << " es el ganador por contar con mayor puntuacion en una ronda" << endl;

           }else if (maxPuntajeTotal(puntajeRondaUnoJugDos,puntajeRondaDosJugDos, puntajeRondaTresJugDos)> maxPuntajeTotal(puntajeRondaUnoJugUno,puntajeRondaDosJugUno, puntajeRondaTresJugUno))
            {
                cout << "Jugador " << nombreJugDos << " es el ganador por contar con mayor puntuacion en una ronda" << endl;
            }else{
            cout << " La partida se empato. " << endl;
            }
        }


    }


   int maxPuntajeTotal (int pjeRondaUno, int pjeRondaDos, int pjeRondaTres)
    {

        int maxPuntaje;
        maxPuntaje = pjeRondaUno;
       for (int i = 0; i < 3; i++)
       {
        if(pjeRondaDos > maxPuntaje){

            maxPuntaje = pjeRondaDos;
        }else if(pjeRondaTres > maxPuntaje)
        {
            maxPuntaje = pjeRondaTres;

        }

       }

        return maxPuntaje;
}


    void comparaVectores(int vecJugUnoNaipe[5],int vecJugDosNaipe[5], string vecJugUnoPalo[5], string vecJugDosPalo[5], string vecJugUnoFig[5],string vecJugDosFig[5],string nombreJugUno, string nombreJugDos, string y, int vecMostrarNaipeUno[5], int vecMostrarNaipeDos[5],int& puntajeRondaUno, int& puntajeRondaDos)

    {
        int i, j;
        string paloUno, paloDos,figuraUno, figuraDos;
        int contUno = 0, contDos = 0, contTres = 0;

        while(contUno != 5 || contDos != 5 || contTres !=0)
        {
        repartiendo (vecJugUnoNaipe, vecJugUnoFig, vecJugUnoPalo,nombreJugUno, y, puntajeRondaUno, vecMostrarNaipeUno);
        repartiendo (vecJugDosNaipe, vecJugDosFig, vecJugDosPalo, nombreJugDos, y, puntajeRondaDos, vecMostrarNaipeDos);

         contUno = 0;
         contDos = 0;
         contTres = 0;
         for(i=0; i<5; i++)
         {
             paloUno = vecJugUnoPalo[i];
             figuraUno = vecJugUnoFig[i];
             paloDos = vecJugDosPalo[i];
             figuraDos = vecJugDosFig[i];
             for(j=0; j<5; j++)
             {
                 if(vecJugUnoPalo[j]== paloUno && vecJugUnoFig[j]== figuraUno) /// Aca lo normal es contUno = 5
                 {
                     contUno++;
                 }
                 if(vecJugDosPalo[j]== paloDos && vecJugDosFig[j] == figuraDos )/// Aca lo normal es contDos = 5
                 {
                     contDos++;
                 }
                 if(vecJugUnoPalo[j]== paloDos && vecJugUnoFig[j]== figuraDos)/// Aca lo normal es contTres = 0
                 {
                     contTres++;
                 }


             }
         }

        }

    }

    void mostrarPuntajeTotal (string nombreJugUno, string nombreJugDos,  int& puntajeRondaUno, int& puntajeRondaDos, int& puntajeTotalUno, int& puntajeTotalDos, int ronda)
        {

        cout << "+-------------------------------------------------+" << endl;
        cout << "|El puntaje total de " << nombreJugUno << " hasta ronda " << ronda << " es :" << puntajeTotalUno << "|" << endl;
        cout << "|El puntaje total de " << nombreJugDos <<" hasta ronda " << ronda << " es :"  << puntajeTotalDos << "|" <<endl;
        cout << "+-------------------------------------------------+" << endl;

        }




    void generandoTablero (int puntajeTotalUno, int puntajeTotalDos, string cartaEmbaucadora, string nombreJugUno, string nombreJugDos, int vecJugUnoNaipe[5], int vecJugDosNaipe[5], string vecJugUnoFig[5], string vecJugDosFig[5], string vecJugUnoPalo[5], string vecJugDosPalo[5], int puntajeRondaUno, int puntajeRondaDos, int vecMostrarNaipeUno[5], int vecMostrarNaipeDos[5])
    {

        int i = 0;
        cout << "   Jugador "  << nombreJugUno << ": " <<puntajeTotalUno   <<"           |valor carta                      " << "   Jugador "  << nombreJugDos << ": " <<puntajeTotalDos <<"           |valor carta " << endl;
    cout << " +---------------------------------------+             " << "        +---------------------------------------+" << endl;
    for (i=0; i<5; i++)
    {
        if (vecMostrarNaipeUno[i] == 0 )
        {
          cout << " |" << vecJugUnoPalo[i] <<"   "   << vecJugUnoFig [i] << "          |    "   << vecMostrarNaipeUno[i] << "       |                    "    << " |" << vecJugDosPalo[i] <<"   "   << vecJugDosFig [i] << "          |    "   << vecMostrarNaipeDos [i] << "      |" << endl;
        }else if (vecMostrarNaipeDos[i] == 0)
        {
        cout << " |" << vecJugUnoPalo[i] <<"   "   << vecJugUnoFig [i] << "          |    "   << vecMostrarNaipeUno[i] << "      |                    "    << " |" << vecJugDosPalo[i] <<"   "   << vecJugDosFig [i] << "          |    "   << vecMostrarNaipeDos [i] << "       |" << endl;

        }else if(vecMostrarNaipeUno[i] == 0 && vecMostrarNaipeDos[i] == 0)
        {
            cout << " |" << vecJugUnoPalo[i] <<"   "   << vecJugUnoFig [i] << "          |    "   << vecMostrarNaipeUno[i] << "       |                    "    << " |" << vecJugDosPalo[i] <<"   "   << vecJugDosFig [i] << "           ||    "   << vecMostrarNaipeDos [i] << "          |" << endl;
        }else{
        cout << " |" << vecJugUnoPalo[i] <<"   "   << vecJugUnoFig [i] << "          |    "   << vecMostrarNaipeUno[i] << "      |                    "    << " |" << vecJugDosPalo[i] <<"   "   << vecJugDosFig [i] << "          |    "   << vecMostrarNaipeDos [i] << "      |" << endl;
        }
    }

    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;
    cout << " | El embaucador es : "  << cartaEmbaucadora << "                                                                      |"  << endl;
    cout << " +-----------------------------------------------------------------------------------------------------+" << endl;



    cout << endl;




    }


    void mostrarPuntajeRonda(string nombreJugUno, string nombreJugDos, int puntajeRondaUno, int puntajeRondaDos, int vecJugUnoNaipe [5], int vecJugDosNaipe [5], int vecMostrarNaipeUno [5], int vecMostrarNaipeDos [5])
    {

    int i;

    cout << "El puntaje de la ronda para jugador " << nombreJugUno   <<  " es: " << puntajeRondaUno << "                " << " El puntaje de la ronda para jugador " << nombreJugDos   <<  " es: " << puntajeRondaDos << endl << endl;
    for(i=0; i<5; i++)
    {

        if(i<4)
        {

        cout << vecMostrarNaipeUno[i] << " + ";
        }else {
            cout << vecMostrarNaipeUno [i] << " = " << puntajeRondaUno << "                                      ";
        }

    }
        for(i=0; i<5; i++)
        {

        if(i<4)
        {

        cout << vecMostrarNaipeDos[i] << " + ";
        }else {
            cout << vecMostrarNaipeDos [i] << " = " << puntajeRondaDos << endl;
        }

        }
    }



void remezcladorEmbaucadora (int& puntajeRonda, int& puntajeTotal, string embauca, string VecFig [5], int VecNaipe [5], int vecMostrarNaipe [5])
    {
        int i;
        puntajeRonda = 0;
        for (int j=0; j < 5; j++)
        {
            vecMostrarNaipe[j]= VecNaipe[j];
        }

        for(i = 0; i<5; i++)
        {
        comparaEmbaucado(VecFig[i], embauca, VecNaipe [i], puntajeRonda, vecMostrarNaipe[i]);
        }
        puntajeTotal += puntajeRonda;

        }




void repartiendo ( int vecNaipe [5], string vecFig [5],string vecPalo [5], string jugadorCorrespondiente, string embaucador, int& puntajeRonda, int vecMostrarNaipe [5])
{
    int azar, mezclar, i = 0;
    int limite_inferior = 10,  limite_superior = 20;

    puntajeRonda = 0;
    while (i < 5)
    {
    azar = limite_inferior + rand () % (limite_superior + 1 - limite_inferior);
    mezclar = 1 + rand () % (4 );

    if(660 % azar == 0)
    {
        vecNaipe[i] = azar;
        vecMostrarNaipe[i] = vecNaipe[i];

    switch (mezclar){
        case 1:
            vecFig [i] = "de corazon ";
            break;
        case 2 :
            vecFig [i] = "de diamante";
            break;
        case 3 :
            vecFig [i] = "de pica    ";
            break;
        case 4 :
            vecFig [i] = "de trebol  ";
        }
        switch(azar){
            // se crea vector para nombrar a cada naipe y hacerlo coincidir con vector de puntajes, vecJugUnoNaipe [i]
        case 10:
            vecPalo[i] ="10";
            break;
        case 11:
            vecPalo[i] ="J ";
            break;
        case 12:
            vecPalo[i] ="Q ";
            break;
        case 15:
            vecPalo[i] ="K ";
            break;
        case 20:
            vecPalo[i] ="A ";
            break;

        }
        comparaEmbaucado(vecFig[i], embaucador, vecNaipe[i], puntajeRonda, vecMostrarNaipe[i]);

        i++;
    }
    }

}


void comparaEmbaucado (string elementoFig, string embaucador,int elementoNaipe, int& puntajeRonda, int& elementoMostrarNaipe )
{

     if (elementoFig != embaucador )
        {
            // suma solo las cartas que no coinciden ocn embaucador
        puntajeRonda+= elementoNaipe;

        }
        else {
                elementoMostrarNaipe = 0;
        }
}



void estadisticasPartida (string nombreJugUno, string nombreJugDos, string ganadorRondaUno, string ganadorRondaDos,string ganadorRondaTres, int puntajeTotalUno, int puntajeTotalDos, int ronda, int puntajeTotalEstadistica, string nombreJugEstadistica, int partida,vector <int>vecPuntajeTotalEstadistica, vector <string>vecNombreJugEstadistica)
{
    cout << "Estadisticas de partidas jugadas entre " << nombreJugUno << " y " << nombreJugDos << endl << endl;
    cout << "Partida      Ganador          Puntaje total" << endl;
        int acumuladoJugadorUno = 0,acumuladoJugadorDos = 0 ;
        int cont = 0;
        int j;
        for(j =0; j < partida; j++)
        {
            cont++;

            cout << cont <<"             " << vecNombreJugEstadistica [j] << "              "  << vecPuntajeTotalEstadistica [j]<< endl;

            if (vecNombreJugEstadistica[j]== nombreJugUno)
        {
            acumuladoJugadorUno += vecPuntajeTotalEstadistica[j];
        }else if (vecNombreJugEstadistica[j]== nombreJugDos)
        {
            acumuladoJugadorDos += vecPuntajeTotalEstadistica[j];
        }

        }


        cout << endl;
        cout <<"+-------------------------------------+" << endl;
        cout << "Acumulado global para jugador " << nombreJugUno << " :" << acumuladoJugadorUno << endl;
        cout <<"+-------------------------------------+" << endl;
        cout << "Acumulado global para jugador " << nombreJugDos << " :" << acumuladoJugadorDos << endl;
        cout <<"+-------------------------------------+" << endl;



      //cout << "EL jugador " << nombreJugEstadistica << " gana con " << puntajeTotalEstadistica << " puntos." << endl;


    /// OJO EL PROBLEMA POR EL QUE SE ME CIERRA LUEGO DE COMPILAR ES MUY PROBABLE QUE VENGA DE QUE CADA VEZ QUE DEFINO EL NEW ESPACIO
    /// DEL VECTOR, SE PIERDE LO GUARDADO EN LAS POSICIONES YA QUE AL DEFINIR NEW INT O NEW STRING CREA UN NUEVO ESPACIO.
    /// VOY A INTENTAR CON LA OTRA OPCION QUE VI EN INTERNET DE VEC.INT O ALGO ASIS
}

void creditosDesarrollador()
{
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ " << endl << endl;
    cout << "                   UNIVERSIDAD TECNOLOGICA NACIONAL (UTN)  " << endl << endl;;
    cout << "                   Tecnicatura Universitaria en Programacion" << endl << endl;
    cout << "                   CURSO: N2C - C1 PACHECO NOCHE" << endl << endl << endl << endl;
    cout << "                   -GRUPO             : 34" << endl << endl;
    cout << "                   -NOMBRE Y APELLIDO : FERNANDO CESAR LOPEZ" << endl << endl;
    cout << "                   -LEGAJO            : 31023" << endl << endl;
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ "  << endl;
}




#endif // TPPRUEBASFUNCIONES_H_INCLUDED


































