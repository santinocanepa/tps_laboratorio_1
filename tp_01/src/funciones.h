/*
 * utn_getNumero.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Santino Canepa
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/**
 *
 * @return retorna el numero ingresado
 */
int utn_getNumero();

/**
 *
 * @return retorna la opcion elegida
 */
float menuVuelos();

/**
 *
 * @return retorna los kilometros para guardarlo en el main
 */

float ingresoValidoKm();

/***
 *
 * @param num1 copia el primer numero
 * @param num2 copia el segundo numero
 * @return retorna la multiplicacion
 */

float multiplicar(float num1, float num2);

/**
 *
 * @param num1 copia el primer numero
 * @param num2 copia el segundo numero
 * @return retorna la division
 */
float dividir(float num1, float num2);

/**
 *
 * @param num1 copia el primer numero
 * @param num2 copia el segundo numero
 * @return retorna la resta necesaria
 */
float buscarDiferencia(float num1, float num2);

void cargaForzada();

#endif /* FUNCIONES_H_ */
