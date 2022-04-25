#include <iostream>
#include <string>

using namespace std;

struct Datos {
    char titulo[30];
    char desc[256];
};

struct Save {
    Datos info;
    Save* sig;
};

void Agregar(Save*& lista);
void Mostrar(Save* lista);

int main() {
    
    int opc;
    Save* lista = NULL;

    cout << "Bienvenido." << endl;
    cout << "Acontinuacion tenermos las siguientes funciones: " << endl;
    cout << "1° Agregar tarea. " << endl;
    cout << "2° Ver tareas. " << endl;
    cout << "¿Que opcion desea? " << endl;
    cin >> opc;

    if (opc == 1) {
        std::cout << "Opcion 1°" << std::endl;
        Agregar(lista);
    }
    if (opc == 2) {
        std::cout << "Opcion 2°" << std::endl;
        Mostrar(lista);
    }

    return 0;
}

void Agregar(Save*& lista) {
    
    Save* nuevo = new Save();
    
    std::cout << "Ingrese el Titulo de su nueva tarea. " << std::endl;
    cin.getline(nuevo->info.titulo, 30);
    std::cout << "Ingrese la descripcion de la tarea. " << std::endl;
    cin.getline(nuevo->info.desc, 256);

    nuevo->sig = NULL;

    if (lista == NULL)
        lista = nuevo;
    else {
        Save* aux = lista;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    } 
}

void Mostrar(Save* lista) {
    if (lista == NULL) {
        std::cout << "La lista se encuentra vacia. " << std::endl;
    }
    Save* aux = lista;
    while (aux != NULL)
        std::cout << "Titulo de tarea: " << aux->info.titulo << std::endl;
        std::cout << "Descrpcion: " << std::endl << aux->info.desc << std::endl;
        aux = aux->sig;
}