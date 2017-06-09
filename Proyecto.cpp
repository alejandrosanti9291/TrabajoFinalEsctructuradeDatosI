/*
Programa:
Autor: Alejandro Santibañez y Jose Alejandro Palacios
Fecha: 4/6/2017
Resumen:
*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define l 500000

void menu();
void generar_arreglo(int []);
void generacion_numero_aleatorios(int [], int);
void cargar_datos();
void crear_archivo();
void leer_archivo();
void generacion_numero_aleatorios_txt(int []);
void ordenar_datos(int []);
int burbuja(int []);
int insercion(int []);
int seleccion(int []);
int quicksort(int [], int, int);
void imprimir_datos(int []);
void ascendente(int []);
void ascedente_burbuja(int []);
void ascedente_insercion(int []);
void ascedente_seleccion(int []);
void descendente(int []);
void descendente_burbuja(int []);
void descendente_insercion(int []);
void descendente_seleccion(int []);
void buscar_datos(int []);
int secuencial(int []);
int binaria(int []);
void guardar_datos();

int main(){
    system("color f2");
    menu();
    return 0;
}
void menu(){
    int opcion, numeros[l];
    crear_archivo();
    leer_archivo();
    do{
        printf("                  ------MENU------... PROYECTO....------\n");
        printf("\n1.Generar Arreglo");
        printf("\n2.Cargar Datos");
        printf("\n3.Ordenar Datos");
        printf("\n4.Imprimir");
        printf("\n5.Buscar Datos");
        printf("\n6.Guardar");
        printf("\n0.Salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: generar_arreglo(numeros);
                break;
            case 2: cargar_datos();
                break;
            case 3: ordenar_datos(numeros);
                break;
            case 4: imprimir_datos(numeros);
                break;
            case 5: buscar_datos(numeros);
                break;
            case 6: guardar_datos();
                break;
            case 0: exit(0);
                break;
            default: printf("No es una opcion valida\n\n");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
void generar_arreglo(int numeros[l]){
    int opcion, cantDatos;
    do{
        printf("\n1. Cien Mil");
        printf("\n2. Doscientos Mil");
        printf("\n3. Trescientos Mil");
        printf("\n4. Cuatrocientos Mil");
        printf("\n5. Quinientos Mil");
        printf("\n6. Menu Principal\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                cantDatos = 100000;
                generacion_numero_aleatorios(numeros, cantDatos);
                break;
            case 2: cantDatos = 200000;
                generacion_numero_aleatorios(numeros, cantDatos);
                break;
            case 3: cantDatos = 300000;
                generacion_numero_aleatorios(numeros, cantDatos);
                break;
            case 4: cantDatos = 400000;
                generacion_numero_aleatorios(numeros, cantDatos);
                break;
            case 5: cantDatos = 500000;
                generacion_numero_aleatorios(numeros, cantDatos);
                break;
           case 6: menu();
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
void generacion_numero_aleatorios(int numeros[l], int cantDatos){
    int i = 0;
    srand(time(NULL));
    while(i < cantDatos){
         printf("%d\n", (rand() % (1999998 + 1)) - 999999);
         i += 1;
    }
    printf("\nDatos Generados %d\n", i);
}
void cargar_datos(){
    int opcion;
    FILE *archivo;
    do{
        printf("\n1. Cien Mil.txt");
        printf("\n2. Doscientos Mil.txt");
        printf("\n3. Trescientos Mil.txt");
        printf("\n4. Cuatrocientos Mil.txt");
        printf("\n5. Quinientos Mil.txt");
        printf("\n0. Salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                archivo = fopen("cien_mil.txt", "r");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0: exit(0);
                break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
void crear_archivo(){
    int cantDatos = 10000;
    int i = 0, n;
    FILE *archivo;
    archivo = fopen("cien_mil.txt", "w");
    srand(time(NULL));
    while(i < cantDatos){
         n = (rand() % (1999998 + 1)) - 999999;
         fprintf(archivo, "%d\n", n);
         i += 1;
    }
    printf("\nDatos Generados %d\n", i);
}

void leer_archivo(){
    int dato, i = 0;
    int numeros[10000];
    FILE *archivo;
    archivo = fopen("cien_mil.txt", "r");
    printf("aqui");
    while((dato = fgetc(archivo)) != EOF){
        printf("%d \n", dato);
    }
}
void generacion_numero_aleatorios_txt(int numeros[l]){
    /*int i = 0;
    srand(time(NULL));
    while(i < cantDatos){
         printf("%d\n", (rand() % (1999998 + 1)) - 999999);
         i += 1;
    }
    printf("\nDatos Generados %d\n", i);*/
}
void ordenar_datos(int numeros[l]){
    int opcion;
    do{
        printf("\n1. Burbuja");
        printf("\n2. Insercion");
        printf("\n3. Seleccion");
        printf("\n4. Quicksort");
        printf("\n0. Salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: burbuja(numeros);
                break;
            case 2: insercion(numeros);
                break;
            case 3: seleccion(numeros);
                break;
            case 4: quicksort(numeros, 0, -1);
                break;
            case 0: exit(0);
                break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
int burbuja(int numeros[l]){
    int i,j,aux;

    for(i = 0;i < l;i++){
        for(j=0;j<l;j++){
            if( numeros[i] > numeros[j+1]){
                aux =  numeros[j];
                 numeros[j] =  numeros[j+1];
                  numeros[j+1] = aux;
            }
        }
    }
}
int insercion(int numeros[l]){
    int i,pos,aux;

    for(i=0;i<l;i++){
        pos = i;
        aux = numeros[i];
        while((pos > 0) && numeros[pos-1] > aux){
            numeros[pos] = numeros[pos-1];
            pos--;
        }
        numeros[pos] = aux;
    }
}
int seleccion(int numeros[l]){
    int i,j,aux,minimo;

    for(i=0;i<l;i++){
        minimo = i;
        for(j=i;j<l;j++){
           if(numeros[j] < numeros[minimo]){
                minimo = j;
           }
        }
        aux = numeros[i];
        numeros[i] = numeros[minimo];
        numeros[minimo] = aux;
    }
}
int quicksort(int numeros[l],int primero,int ultimo){
      int central,i,j,pivote;

      central=(primero+ultimo)/2;
      pivote=numeros[central];
      i=primero;
      j=ultimo;

      do{
        while(numeros[i]<pivote) i++;
        while(numeros[j]>pivote) j--;
        if(i<=j){
            int temp;
            temp=numeros[i];
            numeros[i]=numeros[j]; /*intercambia A[i] con A[j] */
            numeros[j]=temp;
            i++;
            j--;
        }
   }while(i<=j);
   if(primero<j)
   quicksort(numeros,primero,j); /*mismo proceso con sublista izquierda*/
   if(i<ultimo)
   quicksort(numeros,i,ultimo); /*mismo proceso con sublista derecha*/
   printf("Numeros ordenados: ");
   for(i= 0; i < l; i++){
        printf("%d\n", numeros[i]);
   }
}
void imprimir_datos(int numeros[l]){
    int opcion;
    do{
        printf("\n1. Ascendente");
        printf("\n2. Descendente");
        printf("\n0. Salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: ascendente(numeros);
                break;
            case 2:
                break;
            case 0: exit(0);
                break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
void ascendente(int numeros[l]){
    int opcion;
    do{
        printf("\n1. Burbuja");
        printf("\n2. Insercion");
        printf("\n3. Seleccion");
        printf("\n4. Quicksort");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: ascedente_burbuja(numeros);
                break;
            case 2: ascedente_insercion(numeros);
                break;
            case 3: ascedente_seleccion(numeros);
                break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
void ascedente_burbuja(int numeros[l]){
    printf("Numeros ordenados: ");
    for(int i=0;i<l;i++){
        printf("%d", numeros[i]);
    }
}
void ascedente_insercion(int numeros[l]){
    printf("Numeros ordenados: ");
    for(int i=0;i<l;i++){
       printf("%d", numeros[i]);
    }
}
void ascedente_seleccion(int numeros[l]){
     printf("Numero ordenados: ");
    for(int i=0;i<l;i++){
        printf("%d ", numeros[i]);
    }
}
void descendente(int numeros[l]){
    int opcion;
    do{
        printf("\n1. Burbuja");
        printf("\n2. Insercion");
        printf("\n3. Seleccion");
        printf("\n4. Quicksort");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: descendente_burbuja(numeros);
                break;
            case 2: descendente_insercion(numeros);
                break;
            case 3: descendente_seleccion(numeros);
                break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
void descendente_burbuja(int numeros[l]){
    printf("Numeros ordenados: ");
    for(int i=l;i>=0;i--){
        printf("%d", numeros[i]);
    }
}
void descendente_insercion(int numeros[l]){
    printf("Numeros ordenados: ");
    for(int i=l;i>=0;i--){
       printf("%d", numeros[i]);
    }
}
void descendente_seleccion(int numeros[l]){
    printf("Numero ordenados: ");
    for(int i=l;i>=0;i--){
        printf("%d ", numeros[i]);
    }
}
void buscar_datos(int numeros[l]){
    int opcion;
    do{
        printf("\n1. Secuencial");
        printf("\n2. Binario\n");
        //printf("\n0. Salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: secuencial(numeros);
                break;
            case 2: binaria(numeros);
                break;
            //case 0: exit(0);
                //break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
int secuencial(int numeros[l]){
    int dato;
    bool estado=false;

    printf("Ingrese dato a buscar:\n");
	scanf("%d", &dato);
	for(int i=0;i<l;i++){
		if(numeros[i]==dato){
			estado=true;
			break;
		}
	}
	if(estado==true){
		printf("Dato encontrado\n");
	}else{
		printf("Dato no encontrado\n");
	}
}
int binaria(int numeros[l]){
    int sup, inf, mitad, dato,i=0;
    bool estado=false;

    while(inf <= sup && i < 10){
		mitad = (inf+sup)/2;
		if(numeros[mitad]==dato){
			estado=true;
			break;
		}
		if(numeros[mitad]>dato){
			sup=mitad;
		}
		if(numeros[mitad]<dato){
			inf=mitad;
		}
		i++;
	}
	if(estado==true){
		printf("Dato encontrado\n");
	}else{
		printf("Dato no encontrado\n");
	}
}
void guardar_datos(){
    int opcion;
    do{
        printf("\n1. Ordenado");
        printf("\n2. Desordenado\n");
        //printf("\n0. Salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                break;
            case 2:
                break;
            //case 0: exit(0);
                //break;
            default: printf("No es una opcion valida");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
