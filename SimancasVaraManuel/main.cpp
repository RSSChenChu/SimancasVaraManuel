#include <stdio.h>
#include <iostream>
#include "Gestor.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Gestor gestor = *new Gestor();
    char opcion;
    int dato;
    do {
        cout << "\n\t--------------------------------------------------------------"
                "--------\n";
        cout << "\tA. Generar 20 numeros de forma aleatoria y almacenarlos en las "
                "Pilas.\n";
        cout << "\tB. Mostrar el contenido de ambas pilas.\n";
        cout << "\tC. Borrar el contenido de las pilas.\n";
        cout << "\tD. Generar 20 aficionados a partir de las dos pilas y almacenarlas en un ABB.\n";
        cout << "\tX. Dibuja el ABB generado.\n";
        cout << "\tE. Almacenar los aficionados del ABB en las listas "
                "(Se borrara el contenido de las listas).\n";
        cout << "\tF. Mostrar los aficionados de las dos listas.\n";
        cout << "\tG. Borrar el contenido de las dos listas.\n";
        cout << "\tH. Insertar los aficionados en la cola "
                "(se borrara los datos de la cola).\n";
        cout << "\tI. Mostrar los aficionados que hay en la cola.\n";
        cout << "\tJ. Borrar el contenido de la cola.\n";
        cout << "\tK. Mostrar los datos de los aficionados almacenados en el ABB, "
                "ordenados por sus IDs de menor a mayor.\n";
        cout << "\tL. Mostrar los datos de los socios almacenados en el ABB, "
                "ordenados por sus IDs de menor a mayor.\n";
        cout << "\tM. Mostrar los datos de los simpatizantes almacenados en el ABB, "
                "ordenados por sus IDs de menor a mayor.\n";
        cout << "\tN. Mostrar el primero y el ultimo socio y simpatizante en entrar (En ABB).\n";
        cout << "\tO. Eliminar un aficionado, almacenado en el ABB, por su ID.\n";
        cout << "\tP. Mostrar el primero y el ultimo socio y simpatizante en entrar (En cola).\n";
        cout << "\tR. Reiniciar el programa.\n";
        cout << "\tS. Salir.\n\n";
        cout << "\tIndique la opcion deseada: ";
        cin >> opcion;
        opcion = toupper(opcion);
        // system("clear");
        system("cls");
        switch(opcion) {
        case 'A':
            gestor.llenarPilas();
            break;
        case 'B':
            gestor.mostrarPilas();
            break;
        case 'C':
            gestor.borrarPilas();
            break;
        case 'D':
            gestor.generarAficionados();
            break;
        case 'X':
            gestor.dibujarAbb();
            break;
        case 'E':
            gestor.insertarEnListas();
            break;
        case 'F':
            gestor.mostrarListas();
            break;
        case 'G':
            gestor.borrarListas();
            break;
        case 'H':
            gestor.insertarEnColas();
            break;
        case 'I':
            gestor.mostrarColas();
            break;
        case 'J':
            gestor.borrarColas();
            break;
        case 'K':
            gestor.mostrarAficionadosEnAbb();
            break;
        case 'L':
            gestor.mostrarSociosEnAbb();
            break;
        case 'M':
            gestor.mostrarSimpEnAbb();
            break;
        case 'N':
            gestor.mostrar4Abb();
            break;
        case 'O':
            cout << "Indique el ID del aficionado que desea eliminar: ";
            cin >> dato;
            
            gestor.eliminarAficionadoEnAbb(dato);
            
            gestor.dibujarAbb();
            break;
        case 'P':
            gestor.mostrar4Cola();
            break;
        case 'R':
            gestor.reiniciar();
            break;
        case 'S':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion incorrecta!\n\n";
            break;
        }
    } while(opcion != 'S');
    return 0;
}
