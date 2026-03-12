#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --- DETECCIÓN DE SISTEMA OPERATIVO ---
#ifdef _WIN32
    #include <windows.h>
    #define LIMPIAR_PANTALLA() system("cls")
    #define PAUSA_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define LIMPIAR_PANTALLA() system("clear")
    #define PAUSA_MS(ms) usleep(ms * 1000)
#endif

// --- FUNCIÓN PARA ESPERAR AL USUARIO (PORTABLE) ---
void esperar_tecla() {
    printf("\nPresiona Enter para continuar...");
    fflush(stdout);
    getchar();
}

// --- CONFIGURACIÓN PARA VISUAL STUDIO ---
#ifndef _CRT_SECURE_NO_WARNINGS
    #define _CRT_SECURE_NO_WARNINGS
#endif

#endif