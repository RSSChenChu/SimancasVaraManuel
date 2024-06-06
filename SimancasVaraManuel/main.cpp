#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    // Gestor gestor;
    char opcion;
    do {
        cout << "\n\t--------------------------------------------------------------"
                "--------\n";
        cout << "\tPedidos en la pila -> " << 0 /*gestor.PedidosEnPila()*/
             << "\n\tPedidos en las colas:\n \t\tSala A-> " << 0 /*gestor.PedidosEnSalaA() */ << "\tSala B-> "
             << 0 /*gestor.PedidosEnSalaB() */ << "\tSala C-> " << 0 /*gestor.PedidosEnSalaC() */ << "\tSala D-> "
             << 0 /*gestor.PedidosEnSalaD()*/
             << " \n\tPedidos en las listas:\n \t\tEstandar-> "
             << 0 /*gestor.PedidosEnListaEstandar()*/ << "\tUrgentes-> " << 0 /*gestor.PedidosEnListaUrgentes()*/
             << "\n\tPedidos en el arbol -> " << 0                            /*gestor.PedidosEnArbol()*/
             << "\n";
        cout << "\t----------------------------------------------------------------"
                "------\n\n";
        cout << "\tA. Generar 12 Pedidos de forma aleatoria y almacenarlos en la "
                "Pila.\n";
        cout << "\tB. Consultar todos los Pedidos generados en la Pila (pendientes "
                "de entrar en las salas).\n";
        cout << "\tC. Borrar los Pedidos generados en la pila.\n";
        cout << "\tD. Simular llegada de los Pedidos en las colas.\n";
        cout << "\tE. Consultar los Pedidos de las salas A y B.\n";
        cout << "\tF. Consultar los Pedidos de las salas C y D.\n";
        cout << "\tG. Borrar los todos los Pedidos de las salas.\n";
        cout << "\tH. Simular la entrada de los Pedidos a las listas.\n";
        cout << "\tI. Mostrar los Pedidos que hay en la lista Estandar.\n";
        cout << "\tJ. Mostrar los Pedidos que hay en la lista Urgentes.\n";
        cout << "\tK. Buscar en las listas el Pedido Estandar de mayor prioridad y "
                "el pedido Urgente con menor prioridad "
                "prioridad.\n";
        cout << "\tL. Reiniciar el programa.\n";
        cout << "\tM. Crear y dibujar el ABB en consola.\n";
        cout << "\tN. Mostrar los datos de todos los Pedidos Estandar ordenados "
                "por numero de seguimiento en orden ascendente.\n";
        cout << "\tO. Mostrar los datos de todos los Pedidos Urgentes ordenados "
                "por numero de seguimiento en orden ascendente.\n";
        cout << "\tP. Mostrar los datos de todos los Pedidos recorriendo el arbol "
                "en inorden.\n";
        cout << "\tQ. Buscar en el ABB el Pedido Estándar con el numero de "
                "seguimiento mas alto y mas bajo, asi como los Pedidos Urgentes "
                "con el numero de ID mas alto y mas bajo.\n";
        cout << "\tR. Contar el numero de Pedidos almacenados en el ABB cuyos "
                "numeros de seguimiento son impares.\n";
        cout << "\tT. Mostrar los Pedidos que se encuentran almacenados en un nodo "
                "hoja.\n";
        cout << "\tU. Eliminar un Pedido indicado por su numero de seguimiento "
                "(que se pide desde consola) y mostrar el arbol "
                "resultante tras la eliminacion de dicho Pedido.\n";
        cout << "\tS. Salir.\n\n";
        cout << "\tIndique la opcion deseada: ";
        cin >> opcion;
        opcion = toupper(opcion);
        // system("clear");
        system("cls");
        switch(opcion) {
        case 'A':
            // gestor.llenaPilas();
            break;
        case 'B':
            // gestor.muestraPilas();
            break;
        case 'C':
            // gestor.eliminaPilas();
            break;
        case 'D':
            // gestor.generaArbol();
            break;
        case 'X':
            // gestor.muestraArbol();
            break;
        case 'E':
            // gestor.enlistarAficionados();
            break;
        case 'F':
            // gestor.muestraListas();
            break;
        case 'G':
            // gestor.borraListas();
            break;
        case 'H':
            // gestor.encolarAficionados();
            break;
        case 'I':
            // gestor.muestraCola();
            break;
        case 'J':
            // gestor.borraCola();
            break;
        case 'K':
            // gestor.muestraAfiOrd();
            break;
        case 'L':
            // gestor.muestraSociOrd();
            break;
        case 'M':
            // gestor.muestraSimpOrd();
            break;
        case 'N':
            // gestor.muestraArbol4();
            break;
        case 'O':
            // gestor.eliminaAficionado();
            break;
        case 'P':
            // gestor.muetraCola4();
            break;
        case 'R':
            // gestor.reiniciar();
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
