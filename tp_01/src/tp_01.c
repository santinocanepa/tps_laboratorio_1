/*
 ============================================================================
 Santino Canepa
 Div j
 Tarde
 TP-1
Ejercicio: Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define BTC 4606954.55
#define DESCUENTO 0.9
#define INTERES 1.25


int main(void){
	setbuf(stdout,NULL);
	int opcion;
	float kilometros=0;
	int opcionVuelos;
	float aerolineas=0;
	float latam=0;
	float precioDebitoLatam=0;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float diferenciaPrecio;
	int flag=0;

	do{
		opcion = utn_getNumero();//retorno guardado en opcion
			switch(opcion)
			{
			case 1://ingreso de kilometros
				kilometros = ingresoValidoKm();
				printf("\nlos kilometros ingresados son %.2f km", kilometros);
				break;
			case 2://ingreso de vuelos y precios
				if(kilometros!=0){
					opcionVuelos = menuVuelos();
					if(opcionVuelos==1){
						printf("\ningrese el precio para aerolineas: ");
						fflush(stdin);
						scanf("%f", &aerolineas);
					}
					else if(opcionVuelos==2)
					{
						printf("\ningrese el precio para latam: ");
						fflush(stdin);
						scanf("%f", &latam);
					}
					else{
						printf("no existe esa opcion");
					}
				}
				else
				{
					printf("\nno se ingresaron kilometros\n");
				}

				break;
			case 3://calculos de precios
				if(latam!=0 && aerolineas!=0)
				{
					precioDebitoLatam = multiplicar(latam, DESCUENTO);
					precioCreditoLatam = multiplicar(latam, INTERES);
					precioBitcoinLatam = dividir(latam, BTC);
					precioUnitarioLatam = dividir(latam, kilometros);
					precioDebitoAerolineas = multiplicar(aerolineas, DESCUENTO);
					precioCreditoAerolineas = multiplicar(aerolineas, INTERES);
					precioBitcoinAerolineas = dividir(aerolineas, BTC);
					precioUnitarioAerolineas = dividir(aerolineas, kilometros);
					diferenciaPrecio = buscarDiferencia(latam, aerolineas);
					flag=1;
				}
				else
				{
					printf("\n no se ingresaron kilometros o precios necesarios\n");
				}
				break;
			case 4://muestra de precios
				if(latam!=0 && aerolineas!=0 && flag==1){
					printf("\nPrecio vuelo Latam:%.2f\n a) Precio con tarjeta de débito: %.2f\n b) Precio con tarjeta de crédito: %.2f\n c) Precio pagando con bitcoin : %f\n d) Precio unitario: %.2f\nPrecio vuelo Aerolíneas: %.2f\n a) Precio con tarjeta de débito: %.2f\n b) Precio con tarjeta de crédito: %.2f\n c) Precio pagando con bitcoin : %f\n d) Precio unitario: %.2f\nLa diferencia de precio es : %.2f\n",latam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, aerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecio);
				}
				else
				{
					printf("\n no se ingresaron kilometros o precio en los vuelos\n");
				}
				break;
			case 5://carga forzada de datos
				cargaForzada();
				break;
			case 6://salida del programa
				printf("\nusted salio del programa\n");
				break;
			default:
				printf("\nopcion no valida\n");
			}
	}while(opcion!=6);

	return 0;
}
