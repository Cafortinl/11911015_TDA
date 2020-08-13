#include <iostream>
#include <string>
#include "Object.hpp"
#include "Alumno.hpp"
#include "Simbolo.hpp"
#include "TDAList.hpp"
#include "TDAStack.hpp"
#include "TDAQueue.hpp"
#include "ArrayList.hpp"
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"
#include "LinkedStack.hpp"
#include "LinkedQueue.hpp"

using namespace std;

//Método que valida que la entrada es del tipo de dato correcto (entero)
int validInput(){
    int input;
    cin >> input;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Este campo requiere un número entero. Ingréselo nuevamente: ";
        cin >> input;
    }
    return input;
}

//Método que muestra las operaciones posibles
void showOperations(int x){
    switch(x){
        case 1:{
            cout << "Operaciones de Listas\n 1. Insertar Elemento\n 2. Imprimir Elementos\n 3. Buscar Elemento\n 4. Borrar Elemento\n 5. Ver si está vacía\n 6. Obtener Elemento por Posición\n 7. Obtener Siguiente\n 8. Obtener Anterior\n 9. Borrar todos los Elementos (Anula)\n 10. Regresar al Menú Principal " << endl;
            break;
        }

        case 2:{
            cout << "Operaciones de Pilas\n 1. “Empujar” (push)\n 2. “Sacar” (pop)\n 3. Ver Tope (top)\n 4. Verificar si está vacía\n 5. Imprimir elementos\n 6. Regresar al Menú Principal" << endl;
            break;
        }

        case 3:{
            cout << "Operaciones de Colas\n 1. “Encolar” (queue)\n 2. “Desencolar” (dequeue)\n 3. Ver Tope (peek)\n 4. Verificar si está vacía\n 5. Imprimir elementos\n 6. Regresar al Menú Principal" << endl;
            break;
        }
    }
}

//Método que muestra los menús
void showMenu(int x){
    switch(x){
        case 1:{
            cout << "Menú Principal\n 1. Trabajar con Listas\n 2. Trabajar con Pilas\n 3. Trabajar con Colas\n 4. Salir " << endl;
            break;
        }

        case 2:{
            cout << "Menú Tipo de Lista\n 1. Trabajar con ArrayList\n 2. Trabajar con Linked List\n 3. Regresar al Menú Principal" << endl;
            break;
        }

        case 3:{
            cout << "Menú Tipo de Pila\n 1. Trabajar con ArrayStack\n 2. Trabajar con LinkedStack\n 3. Regresar al Menú Principal" << endl;
            break;
        }

        case 4:{
            cout << "Menú Tipo de Cola\n 1. Trabajar con ArrayQueue\n 2. Trabajar con LinkedQueue\n 3. Regresar al Menú Principal" << endl;
            break;
        }
    }
}


//Método que ejecuta las operaciones del TDA lista
int listOptions(int x){
    TDAList* lista;
    bool opcionValida = false;
    int opcion = 0;
    switch(x){//Validando el tipo de lista con el que el usuario desea trabajar
        case 1:{
            lista = new ArrayList;
            opcionValida = true;
            break;
        }

        case 2:{
            lista = new LinkedList;
            opcionValida = true;
            break;
        }

        case 3:{
            break;
        }

        default:{
            cout << "La opción ingresada no es válida" << endl;
            break;
        }
    }
    if(opcionValida){
        do{
            showOperations(1);
            opcion = validInput();
            cout << endl;
            switch(opcion){
                case 1:{
                    int posicion;
                    char respuesta;
                    string nombre, cuenta;
                    do{
                        cin.ignore();
                        cout << "Ingrese el nombre del alumno: ";
                        getline(cin, nombre);
                        cout << "Ingrese la cuenta del alumno: ";
                        cin >> cuenta;
                        cout << "Ingrese la posición en la que desea insertar el alumno: ";
                        posicion = validInput();
                        Object* ptr = new Alumno(nombre, cuenta);
                        if(lista->insert(posicion, ptr))
                            cout << "El alumno se ingresó correctamente" << endl;
                        else
                            cout << "No se pudo ingresar el alumno" << endl;
                        cout << "¿Desea ingresar otro alumno? [s/n]: ";
                        cin >> respuesta;
                    }while(respuesta != 'n' && respuesta != 'N');
                    break;
                }

                case 2:{
                    lista->print();
                    break;
                }

                case 3:{
                    string cuenta;
                    cout << "Ingrese el numero de cuenta del alumno que desea buscar: ";
                    cin >> cuenta;
                    Object* ptr = new Alumno("", cuenta);
                    if(lista->find(ptr) > 0)
                        cout << to_string(lista->find(ptr)) + '[' + lista->get(lista->find(ptr))->toString() + ']' << endl;
                    else
                        cout << "El alumno que busca no está en la lista" << endl;
                    break;
                }

                case 4:{
                    int posicion;
                    cout << "Ingrese la posición del alumno que desea eliminar: ";
                    posicion = validInput();
                    Object* ptr = lista->remove(posicion);
                    if(ptr)
                        cout << "El alumno [" + ptr->toString() + "] fue borrado exitosamente" << endl;
                    else
                        cout << "No se pudo eliminar el elemento seleccionado" << endl;
                    delete ptr;
                    break;
                }

                case 5:{
                    if(lista->isEmpty())
                        cout << "La lista está vacía" << endl;
                    else
                        cout << "La lista no está vacía, tiene " + to_string(lista->size()) + " elementos" << endl;
                    break;
                }

                case 6:{
                    int posicion;
                    cout << "Ingrese la posición de la que desea recuperar el elemento: ";
                    posicion = validInput();
                    if(lista->get(posicion) != nullptr)
                        cout << "El elemento en la posición " + to_string(posicion) + " es: " + lista->get(posicion)->toString() << endl;
                    else
                        cout << "No existe el elemento que busca" << endl;
                    break;
                }

                case 7:{
                    int posicion;
                    cout << "Ingrese la posición de la que desea recuperar el elemento siguiente: ";
                    posicion = validInput();
                    if(lista->getNext(posicion) != nullptr)
                        cout << "El elemento que le sigue a la posición " + to_string(posicion) + " es: " + lista->getNext(posicion)->toString() << endl;
                    else
                        cout << "No existe el elemento que busca" << endl;
                    break;
                }

                case 8:{
                    int posicion;
                    cout << "Ingrese la posición de la que desea recuperar el elemento anterior: ";
                    posicion = validInput();
                    if(lista->getPrevious(posicion) != nullptr)
                        cout << "El elemento antes de la posición " + to_string(posicion) + " es: " + lista->getPrevious(posicion)->toString() << endl;
                    else
                        cout << "No existe el elemento que busca" << endl;
                    break;
                }

                case 9:{
                    lista->clear();
                    break;
                }

                case 10:{
                    break;
                }

                default:{
                    cout << "La opción ingresada no es válida" << endl;
                }
            }
            cout << endl;
        }while(opcion != 10);
        delete lista;
    }
    return 3;
}

//Método que ejecuta las operaciones del TDA pila
int stackOptions(int x){
    TDAStack* pila;
    bool opcionValida = false;
    int opcion = 0;
    switch(x){//Validando el tipo de pila con el que el usuario desea trabajar
        case 1:{
            pila = new ArrayStack;
            opcionValida = true;
            break;
        }

        case 2:{
            pila = new LinkedStack;
            opcionValida = true;
            break;
        }

        case 3:{
            break;
        }

        default:{
            cout << "La opción ingresada no es válida" << endl;
            break;
        }
    }
    if(opcionValida){
        do{
            showOperations(2);
            opcion = validInput();
            cout << endl;
            switch(opcion){
                case 1:{
                    cin.ignore();
                    string nombre;
                    cout << "Ingrese el nombre del simbolo que desea agregar a la pila: ";
                    getline(cin, nombre);
                    Object* ptr = new Simbolo(nombre);
                    pila->push(ptr);
                    cout << "Simbolo agregado" << endl;
                    break;
                }

                case 2:{
                    Object* ptr = pila->pop();
                    if(ptr)
                        cout << "El elemento sacado es: " + ptr->toString() << endl;
                    else
                        cout << "La pila está vacía" << endl;
                    delete ptr;
                    break;
                }

                case 3:{
                    Object* ptr = pila->top();
                    if(ptr)
                        cout << "El elemento en el tope de la pila es: " + ptr->toString() << endl;
                    else
                        cout << "La pila está vacía" << endl;
                    break;
                }

                case 4:{
                    if(pila->isEmpty())
                        cout << "Está Vacía" << endl;
                    else
                        cout << "No Está Vacía" << endl;
                    break;
                }

                case 5:{
                    pila->print();
                    break;
                }

                case 6:{
                    break;
                }

                default:{
                    cout << "La opción ingresada no es válida" << endl;
                }
            }
            cout << endl;
        }while(opcion != 6);
        delete pila;
    }
    return 3;
}

//Método que ejecuta las operaciones del TDA cola
int queueOptions(int x){
    TDAQueue* cola;
    bool opcionValida = false;
    int opcion = 0;
    switch(x){//Validando el tipo de cola con el que el usuario desea trabajar
        case 1:{
            cola = new ArrayQueue;
            opcionValida = true;
            break;
        }

        case 2:{
            cola = new LinkedQueue;
            opcionValida = true;
            break;
        }

        case 3:{
            break;
        }

        default:{
            cout << "La opción ingresada no es válida" << endl;
            break;
        }
    }
    if(opcionValida){
        do{
            showOperations(3);
            opcion = validInput();
            cout << endl;
            switch(opcion){
                case 1:{
                    string nombre, cuenta;
                    cin.ignore();
                    cout << "Ingrese el nombre del alumno: ";
                    getline(cin, nombre);
                    cout << "Ingrese la cuenta del alumno: ";
                    cin >> cuenta;
                    Object* ptr = new Alumno(nombre, cuenta);
                    cola->queue(ptr);
                    break;
                }

                case 2:{
                    Object* ptr = cola->dequeue();
                    if(ptr)
                        cout << "El elemento que se sacó de la cola es: " + ptr->toString() << endl;
                    else
                        cout << "La cola está vacía" << endl;
                    delete ptr;
                    break;
                }

                case 3:{
                    Object* ptr = cola->peek();
                    if(ptr)
                        cout << "El elemento está al frente de la cola es: " + ptr->toString() << endl;
                    else
                        cout << "La cola está vacía" << endl;
                    break;
                }

                case 4:{
                    if(cola->isEmpty())
                        cout << "Está Vacía" << endl;
                    else
                        cout << "No Está Vacía" << endl;
                    break;
                }

                case 5:{
                    cola->print();
                    break;
                }

                case 6:{
                    break;
                }

                default:{
                    cout << "La opción ingresada no es válida" << endl;
                }
            }
            cout << endl;
        }while(opcion != 6);
        delete cola;
    }
    return 3;
}

//Método que ejecuta las operaciones del menu principal
void menuOptions(int x){
    int opcion = 0;

    switch(x){
        case 1:{
            do{
                showMenu(2);
                opcion = validInput();
                cout << endl;
                opcion = listOptions(opcion);
            }while(opcion != 3);
            break;
        }

        case 2:{
            do{
                showMenu(3);
                opcion = validInput();
                cout << endl;
                opcion = stackOptions(opcion);
            }while(opcion != 3);
            break;
        }

        case 3:{
            do{
                showMenu(4);
                opcion = validInput();
                cout << endl;
                opcion = queueOptions(opcion);
            }while(opcion != 3);
            break;
        }

        case 4:{
            break;
        }

        default:{
            cout << "La opción ingresada no es válida" << endl;
            break;
        }
    }
}

int main(){
    int opcion = 0;
    do{
        showMenu(1);
        opcion = validInput();
        cout << endl;
        menuOptions(opcion);
    }while(opcion != 4);
    cout << "Fin del programa" << endl;
    return 0;
}