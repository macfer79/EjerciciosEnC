#define _CRT_SECURE_NO_WARNINGS		    //elimina las advertencias propias de Microsoft por utilizar funciones estandar que pueden causar (buffer overflows).

#include <stdio.h>                      //librería estandar para que el programa se comunique con el usuario.
#include <stdlib.h>                     //libreria estandar que contiene funciones para control de memoria, procesos del sistema y conversiones de datos.
#include <time.h>                       //Devuelve el tiempo actual del sistema en segundos transcurridos desde el 1 de enero de 1970 (el Tiempo Unix).
#include <stdbool.h>                    //librería estandar para usar booleanos.
#include <windows.h>                

// --- SECCIÓN DE PORTABILIDAD ---
#ifdef _WIN32
    #include <windows.h>                //librería que te permite interactuar con el hardware, las ventanas y el sistema de archivos profundo.
    #define PAUSA(ms) Sleep(ms)
#else
    #include <unistd.h>                 //Esta librería es el equivalente a <windows.h>, pero para sistemas basados en estándares POSIX (como macOS, Linux, y FreeBSD).
    #define PAUSA(ms) usleep(ms * 1000) //usleep usa microsegundos.
#endif
// -------------------------------

// --- MACRO PARA LIMPIAR PANTALLA ---
#ifdef _WIN32
    #define LIMPIAR_PANTALLA() system("cls")    //Limpia la información en pantalla en sistemas Windows.
#else
    #define LIMPIAR_PANTALLA() system("clear")  //Limpia la información en pantalla en sistemas macOS, Linux y FreeBSD.
#endif
// -----------------------------------

int main()
{
    //Declaración de variables. Tipo entero
    int aleatorio, num = 1, usuario, uno = 0, dos = 0, tres = 0, cuatro = 0, mayor, numeroMayor;

    //Generamos número aleatorio entre 1 y 4
    srand(time(NULL));              //Sirve para establecer el punto de inicio (la semilla) de la secuencia de rand() y devuelve el tiempo actual.
    aleatorio = rand() % 4 + 1;     //Con esta fórmula, lo obligas a quedarse en un rango específico (1,2,3 o 4).

    while (num < 20)                //Saldrá del bucle cuando no se cumpla la condición.
    {
        printf("%d\n", aleatorio);  //imprimimos el valor aleatorio.
        PAUSA(100);                 //Pausa de medio segundo (500ms) dependiendo del S.O. utilizado.

        num++;                      //Suma 1 al contador para saber la cantidad de números aleatorios generados.
        LIMPIAR_PANTALLA();         //Limpia la pantalla dependiendo del S.O. utilizado.

        // --- Comparación de la variable con cada uno de los números de la secuencia y suma si se cumple la condición. ---
        if (aleatorio == 1) uno++;
        if (aleatorio == 2) dos++;
        if (aleatorio == 3) tres++;
        if (aleatorio == 4) cuatro++;
        // ----------------------------------------------------------------------------------------------------------------

        //Generamos nuevo número aleatorio
        aleatorio = rand() % 4 + 1;
    }

    //Determinamos cual ha salido en mas ocasiones
    if (uno >= dos)
    {
        mayor = uno; //Toma el valor de la variable.
        numeroMayor = 1; //Toma el valor del número que se evalúa.
    }
    else
    {
        mayor = dos; //Toma el valor de la variable.
        numeroMayor = 2; //Toma el valor del número que se evalúa.
    }
    if (mayor < tres)
    {
        mayor = tres; //Toma el valor de la variable.
        numeroMayor = 3; //Toma el valor del número que se evalúa.
    }
    if (mayor < cuatro)
    {
        mayor = cuatro; //Toma el valor de la variable.
        numeroMayor = 4; //Toma el valor del número que se evalúa.
    }
    //Preguntamos al usuario que número ha salido mas veces
    printf("Que n%cmero ha salido m%cs veces?\n", 163, 160);
    scanf_s("%d", &usuario);

    if (usuario == numeroMayor)
    {
        printf("Has acertado. Los n%cmeros han salido en estas cantidades: \n", 163);
    }
    else
    {
        printf("No has acertado. Los n%cmeros han salido en estas cantidades: \n", 163);
    }
    //Mostramos las frecuencias de aparición
    printf("1: %d, 2: %d,3:  %d, 4: %d, Mayor frecuencia: %d\n", uno, dos, tres, cuatro, numeroMayor);

    return 0;
}
