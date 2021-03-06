/*
 * utn_getNumero.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Santino Canepa
 */
#include <stdio.h>
#include <stdlib.h>
#define BTC 4606954.55
#define DESCUENTO 0.9
#define INTERES 1.25
#define KILOMETROS 7090
#define AEROLINEAS 162965
#define LATAM 159339

int utn_getNumero(){
	int numero;

	 printf("\n1) ingrese '1' para cargar los kilometros "
			"\n2) ingrese '2' para elegir el tipo de vuelo"
			"\n3) ingrese '3' para calcular todos los datos"
			"\n4) ingrese '4' para informar los resultados de los datos"
			"\n5) ingrese '5' para la carga forzada de datos"
			"\n6) ingrese '6' para cerrar el programa"
			"\ningrese la opcion: ");
	 fflush(stdin);
	 scanf("%d", &numero);

	 return numero;
}

float ingresoValidoKm(){
	float kilometros;

	printf("\ningrese la cantidad de Kilómetros por recorrer(entre 10 y 50000): \n");
	fflush(stdin);
	scanf("%f", &kilometros);

	while(kilometros<10 || kilometros>50000)
	{
		printf("error. ingrese la cantidad de Kilómetros por recorrer(entre 10 y 50000): \n");
		fflush(stdin);
		scanf("%f", &kilometros);
	}
	return kilometros;
}


float menuVuelos(){
	int opcionVuelo;

	printf("\ningrese el vuelo para darle precio"
			"\n1) ingrese '1' para elegir aerolineas"
			"\n2) ingrese '2' para elegir latam"
			"\ningrese la opcion: ");
	fflush(stdin);
	scanf("%d", &opcionVuelo);

	return opcionVuelo;
}

float multiplicar(float num1, float num2){
	float resultado;

	resultado = num1 * num2;

	return resultado;
}

float dividir(float num1, float num2){
	float resultado;

	resultado = num1 / num2;

	return resultado;
}

float buscarDiferencia(float num1, float num2){
	float resultado;

	if(num1>num2)
	{
		resultado = num1 - num2;
	}
	else
	{
		resultado = num2 - num1;
	}

	return resultado;
}

void cargaForzada(){
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float diferenciaPrecio;

	precioDebitoLatam = multiplicar(LATAM, DESCUENTO);
	precioCreditoLatam = multiplicar(LATAM, INTERES);
	precioBitcoinLatam = dividir(LATAM, BTC);
	precioUnitarioLatam = dividir(LATAM, KILOMETROS);
	precioDebitoAerolineas = multiplicar(AEROLINEAS, DESCUENTO);
	precioCreditoAerolineas = multiplicar(AEROLINEAS, INTERES);
	precioBitcoinAerolineas = dividir(AEROLINEAS, BTC);
	precioUnitarioAerolineas = dividir(AEROLINEAS, KILOMETROS);
	diferenciaPrecio = buscarDiferencia(LATAM, AEROLINEAS);

	printf("kilometros ingresados: %d"
			"\n"
			"\nPrecio Latam: %d"
			"\na) Precio con tarjeta de débito: %.2f"
			"\nb) Precio con tarjeta de crédito: %.2f"
			"\nc) Precio pagando con bitcoin : %f"
			"\nd) Precio unitario: %.2f"
			"\n"
			"\nAerolíneas: %d"
			"\na) Precio con tarjeta de débito: %.2f"
			"\nb) Precio con tarjeta de crédito: %.2f"
			"\nc) Precio pagando con bitcoin : %f"
			"\n d) Precio unitario: %.2f"
			"\nLa diferencia de precio es : %.2f"
			"\n",KILOMETROS, LATAM, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, AEROLINEAS, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecio);
}

