#define _CRT_SECURE_NO_WARNINGS		// Elimina las advertencias propias de Microsoft por utilizar funciones estandar que pueden causar (buffer overflows).

// Declaración de librerias.
#ifdef _WIN32
#include <windows.h>				// Si estamos en Windows, incluimos la librería necesaria.
#endif

#include <stdio.h>					// Libreria estandar para que el programa se comunique con el usuario.
#include <stdlib.h>					// Libreria estandar que contiene funciones para control de memoria, procesos del sistema y conversiones de datos.
#include <locale.h>					// Libreria estandar que define cómo se muestran las fechas, los símbolos de moneda y los caracteres (acentos, eñes, etc.) que debe reconocer el programa.

int main()
{
	// Configuración para macOS o Linux.
	setlocale(LC_ALL, "en_US.UTF-8");

    // Configuración específica para la consola de Windows.
    #ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);	// Fuerza a Windows a dejar de usar la tabla de Códigos 437 y que utilice Unicode UTF-8.
	SetConsoleCP(CP_UTF8);			// Fallback si el anterior falla.
    #endif

	// Declaración de variables
	int n = 0;						// Contador de cantidad de productos en la lista.
	int producto;					// Número de producto.

	float precio;					// Número que indica el precio del producto.
	float total = 0.0;				// Suma del total de los precios de los productos de la lista.

	do {
		// Introducción del código de producto por el usuario.
		do {
			printf("Introduce el código del producto: ");
			scanf("%d", &producto);
		} while (producto < 0);

		// En el caso de que el producto no tenga el valor 0, se podrá indicar el precio de dicho producto.
		if (producto != 0) {
			do {
				printf("Indica su precio: ");
				scanf("%f", &precio);
			} while (precio <= 0.0);

			n++;					// Se sumará uno al contador de productos de la lista.
			total += precio;		// Se sumará el precio de los productos de la lista.
		}
		// En el caso de que el producto tenga el valor 0 y el valor de n sea igual a 0, se lo indicará al usuario mediante los siguientes mensajes por pantalla.
		if (n == 0) {
			printf("No hay productos en la lista\n");
			printf("La cantidad de productos de la lista es: %d\n", n);
		}
	} while (producto != 0);

	// Cuando el producto tenga como valor 0 y el valor de n sea mayor que 0, se lo indicará al usuario mediante los siguientes mensajes por pantalla.
	if (n > 0) {
		printf("El precio total de la lista es %.2f\n", total);
		printf("La cantidad de productos de la lista es: %d\n", n);
	}

	printf("El programa ha terminado.\n");

	printf("Presiona Enter para salir...");

	// Limpia el búfer: lee caracteres hasta encontrar un \n o el fin del archivo.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Ahora este SÍ se detiene y espera a que el usuario pulse una tecla.
	getchar();

	return 0;
}
