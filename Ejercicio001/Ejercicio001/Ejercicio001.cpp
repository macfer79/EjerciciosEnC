#define _CRT_SECURE_NO_WARNINGS		//elimina las advertencias propias de Microsoft por utilizar funciones estandar que pueden causar (buffer overflows).

// Si estamos en Windows, incluimos la librería necesaria.
#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>					//librería estandar para que el programa se comunique con el usuario.
#include <stdlib.h>					//libreria estandar que contiene funciones para control de memoria, procesos del sistema y conversiones de datos.
#include <locale.h>

int main()
{
	// 1. Configuración para macOS / Linux
	setlocale(LC_ALL, "en_US.UTF-8");

    // 2. Configuración específica para la consola de Windows
    #ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8); // Fuerza a Windows a dejar de usar la tabla de Códigos 437 y que utilice Unicode UTF-8.
	SetConsoleCP(CP_UTF8); // Fallback si el anterior falla.
    #endif

	//Declaración de variables
	int n = 0;						//Contador de cantidad de productos en la lista.
	int producto;					//Número de producto.

	float precio;					//Número que indica el precio del producto.
	float total = 0.0;				//Suma del total de los precios de los productos de la lista.

	do {
		//Introducción del código de producto por el usuario.
		do {
			printf("Introduce el código del producto: ");
			scanf("%d", &producto);
		} while (producto < 0);

		//En el caso de que el producto no tenga el valor 0, se podrá indicar el precio de dicho producto.
		if (producto != 0) {
			do {
				printf("Indica su precio: ");
				scanf("%f", &precio);
			} while (precio <= 0.0);

			n++;					//se sumará 1 al contador de productos de la lista.
			total += precio;		//se sumará el precio de los productos de la lista.
		}
		//En el caso de que el producto tenga el valor 0, se lo indicará al usuario mediante los siguientes mensajes por pantalla.
		if (n == 0) {
			printf("No hay productos en la lista\n");
			printf("La cantidad de productos de la lista es: %d\n", n);
		}
	} while (producto != 0);

	//Cuando el producto tenga como valor 0 y el valor de n sea mayor que 0, se lo indicará al usuario mediante los siguientes mensajes por pantalla.
	if (n > 0) {
		printf("El precio total de la lista es %.2f\n", total);
		printf("La cantidad de productos de la lista es: %d\n", n);
	}

	printf("El programa ha terminado.\n");

	printf("Presiona Enter para salir...");

	// Limpia el búfer: lee caracteres hasta encontrar un \n o el fin del archivo.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Ahora sí, este se detendrá de verdad
	getchar();

	return 0;
}
