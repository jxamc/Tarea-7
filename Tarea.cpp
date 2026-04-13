#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* pila = NULL;

void push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = pila;
    pila = nuevo;
}

void pop() {
    if (pila == NULL) {
        cout << "Pila vacia\n";
        return;
    }

    Nodo* temp = pila;
    pila = pila->siguiente;
    delete temp;
}

void verTopePila() {
    if (pila == NULL)
        cout << "Pila vacia\n";
    else
        cout << "Tope de pila: " << pila->dato << endl;
}

void mostrarPila() {
    Nodo* aux = pila;
    cout << "Pila: ";

    while (aux != NULL) {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }

    cout << "NULL\n";
}

Nodo* frente = NULL;
Nodo* finalCola = NULL;

void enqueue(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        finalCola = nuevo;
    } else {
        finalCola->siguiente = nuevo;
        finalCola = nuevo;
    }
}

void dequeue() {
    if (frente == NULL) {
        cout << "Cola vacia\n";
        return;
    }

    Nodo* temp = frente;
    frente = frente->siguiente;
    delete temp;

    if (frente == NULL)
        finalCola = NULL;
}

void verFrenteCola() {
    if (frente == NULL)
        cout << "Cola vacia\n";
    else
        cout << "Frente de cola: " << frente->dato << endl;
}

void mostrarCola() {
    Nodo* aux = frente;
    cout << "Cola: ";

    while (aux != NULL) {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }

    cout << "NULL\n";
}

Nodo* listaNegativos = NULL;

void insertarNegativo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = listaNegativos;
    listaNegativos = nuevo;
}

void mostrarListaNegativos() {
    Nodo* aux = listaNegativos;
    cout << "Lista negativos: ";

    while (aux != NULL) {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }

    cout << "NULL\n";
}

void liberarMemoria() {

    while (pila != NULL)
        pop();

    while (frente != NULL)
        dequeue();

    while (listaNegativos != NULL) {
        Nodo* temp = listaNegativos;
        listaNegativos = listaNegativos->siguiente;
        delete temp;
    }
}

int main() {

    int opcion, numero;
    int pares = 0, impares = 0;

    do {

        cout << "\nMENU\n";
        cout << "1. Ingresar numero\n";
        cout << "2. Mostrar pila\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Mostrar lista negativos\n";
        cout << "5. Eliminar de pila\n";
        cout << "6. Eliminar de cola\n";
        cout << "7. Ver tope pila\n";
        cout << "8. Ver frente cola\n";
        cout << "9. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "Ingrese numero (-1 para terminar): ";
            cin >> numero;

            if (numero == -1)
                break;

            if (numero < 0)
                insertarNegativo(numero);

            else if (numero % 2 == 0) {
                enqueue(numero);
                pares++;
            }

            else {
                push(numero);
                impares++;
            }

            break;

        case 2:
            mostrarPila();
            break;

        case 3:
            mostrarCola();
            break;

        case 4:
            mostrarListaNegativos();
            break;

        case 5:
            pop();
            break;

        case 6:
            dequeue();
            break;

        case 7:
            verTopePila();
            break;

        case 8:
            verFrenteCola();
            break;

        case 9:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 9);

    cout << "\nEstadisticas:\n";
    cout << "Pares: " << pares << endl;
    cout << "Impares: " << impares << endl;

    liberarMemoria();

    return 0;
}