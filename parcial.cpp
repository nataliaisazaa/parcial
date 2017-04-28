#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int dato;
    nodo* siguiente;

}nodo;
struct nodo2{
    int dato2;
    nodo2* siguiente;
};

struct nodo3{
    int dato3;
    nodo3* siguiente;
};
    nodo* primero = NULL;
    nodo* ultimo = NULL;



void insertarNodo();
void insertarNodo2();
void desplegarCola();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void vaciarCola();
void banco();
void menu();
int main(){
    system("color f1");
    menu();
    return 0;
}
void menu(){
    int opcion;
    do{
        printf("|******************************************|\n");
        printf("|----------------- * COLAS *---------------|\n");
        printf("|******************************************|\n");
        printf("| 1.Insertar cliente                       |\n");
        printf("| 2.Insertar cliente tramie                |\n");
        printf("| 3.Buscar cliente                         |\n");
        printf("| 4.Modificar cliente                      |\n");
        printf("| 5.Eliminar cliente                       |\n");
        printf("| 6.Mostrar cliente                        |\n");
        printf("| 7.Vaciar cliente                         |\n");
        printf("| 8.personas atendidas en el banco         |\n");
        printf("| 0.Salir                                  |\n");
        printf("|******************************************|\n");
        printf("Ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("-INSERTAR CLIENTE \n");
                insertarNodo();
                break;
            case 2:
                //insertarNodo2();
                break;
            case 3:printf("-BUSCAR CLIENTE \n");
                buscarNodo();

                break;
            case 4:printf("-MODIFICAR INFORMACION DEL CLIENTE \n");
                modificarNodo();

                break;
            case 5:printf("-ELIMINAR CLIENTE \n");
                eliminarNodo();

                break;
            case 6: printf("-MOSTRAR CLIENTES \n\n");
                desplegarCola();

                break;
            case 7:system("cls");
                vaciarCola();
                break;
            case 8:banco();
                break;
            case 0: exit(0);
                break;
            default: printf("\nNO VALIDA LA OPCION\n");
                break;
        }
    }while(opcion != 0);
}
void insertarNodo(){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    printf("\n id del cliente: ");
    scanf("%d", &nuevo->dato);
    if(primero == NULL){
        primero = nuevo;
        primero -> siguiente = NULL;
        ultimo = nuevo;
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = NULL;
        ultimo = nuevo;
    }
    printf("\nNODO INGRESADO CON EXITO\n");
    system("cls");
}
/*void insertarNodo2(){
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));
    printf("\n tramite y fecha: ");
    scanf("%d", &nuevo->dato2);
    if(primero == NULL){
        primero = nuevo;
        primero -> siguiente = NULL;
        ultimo = nuevo;
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = NULL;
        ultimo = nuevo;
    }
    printf("\nNODO INGRESADO CON EXITO\n");
    system("cls");
}*/
void desplegarCola(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    if(primero != NULL){
        while(actual != NULL){
            printf("\n     %d", actual -> dato);
            actual = actual -> siguiente;
        }
    }else{
        printf("\n\nLA COLA SE ENCUENTRA VACIA");
    }
}
void buscarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL DATO DEL CLIENTE A BUSCAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL){
            if(actual->dato == nodoBuscado){
                printf("\n EL CLIENTE ( %d ) - ENCONTRADO\n", nodoBuscado);
                encontrado = 1;
            }
            actual = actual -> siguiente;
        }
        if(encontrado == 0){
            printf("\nEL CLIENTE NO HA SIDO ENCONTRADO\n");
        }
    }else{
        printf("\nLA COLA SE ENCUENTRA VACIA\n");
    }
}
void modificarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE EL CLIENTE A BUSCAR PARA MODIFICAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL){
            if(actual->dato == nodoBuscado){
                printf("\nEL CLIENTE ( %d ) - ENCONTRADO", nodoBuscado);
                printf("\nINGRESE EL NUEVO DATO PARA EL NODO: ");
                scanf("%d", &actual->dato);
                printf("\nNODO MODIFICADO\n");
                encontrado = 1;
            }
            actual = actual -> siguiente;
        }
        if(encontrado == 0){
            printf("\nCLIENTE NO HA SIDO ENCONTRADO\n");
        }
    }else{
        printf("\nLA COLA SE ENCUENTRA VACIA\n");
    }
}
void eliminarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    nodo* anterior = (nodo*) malloc(sizeof(nodo));
    anterior = NULL;
    int nodoBuscado = 0, encontrado = 0;
    printf("\nINGRESE CLIENTE A BUSCAR PARA ELIMINAR: ");
    scanf("%d", &nodoBuscado);
    if(primero != NULL){
        while(actual != NULL && encontrado != 1){
            if(actual->dato == nodoBuscado){
                if(actual == primero){
                    primero = primero -> siguiente;
                }else{
                    anterior -> siguiente = actual -> siguiente;
                }
                printf("\nEL NODO HA SIDO BORRADO CON EXITO\n");
                encontrado = 1;
            }
            anterior = actual;
            actual = actual -> siguiente;
        }
        if(encontrado == 0){
            printf("\nEL NODO NO HA SIDO ENCONTRADO\n");
        }else{
            free(anterior);
        }
    }else{
        printf("\nLA COLA SE ENCUENTRA VACIA\n");
    }
}
void banco(){

}
void vaciarCola(){
}
