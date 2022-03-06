#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

string convertiratexto(float f);

string rellenartexto(string texto_inicial, int longitud_final);
void imprimirlibros(string matriz[3][4]);
void imprimirtrabajadores(string matriz[3][5]);
void presionarteclacontinuar();
void borrarpantalla();
void dibujarasteriscos(float longitud_texto);
void creartitulo(string texto);
void reglibros();
void regtrabajadores();
void menuprincipal();

string rellenartexto(string texto_inicial, int longitud_final)
{
	string salida = texto_inicial;
	while (salida.size() < longitud_final)
	{
		salida = salida + " ";
	}
	salida = (salida.substr(0, longitud_final)) + " ";
	return salida;
}

void imprimirlibros(string matriz[3][4])
{
	int i;
	i = 1;
	// t�tulo, autor, a�o y color del libro
	cout << endl;
	cout << rellenartexto("#", 2) << rellenartexto("TITULO", 20) << rellenartexto("AUTOR", 20) << rellenartexto("ANIO", 10) << rellenartexto("COLOR", 15) << endl;
	for (i = 1; i <= 3; i++)
	{
		cout << rellenartexto(convertiratexto(i), 2) << rellenartexto(matriz[i - 1][0], 20) << rellenartexto(matriz[i - 1][1], 20) << rellenartexto(matriz[i - 1][2], 10) << rellenartexto(matriz[i - 1][3], 15) << endl;
	}
	cout << endl;
}

void imprimirtrabajadores(string matriz[3][5])
{
	int i;
	i = 1;
	// Nombre y apellido, edad, ciudad, cargo, salario
	cout << endl;
	cout << rellenartexto("#", 2) << rellenartexto("NOMBRE", 20) << rellenartexto("EDAD", 10) << rellenartexto("CIUDAD", 10) << rellenartexto("CARGO", 15) << rellenartexto("SALARIO", 10) << endl;
	for (i = 1; i <= 3; i++)
	{
		cout << rellenartexto(convertiratexto(i), 2) << rellenartexto(matriz[i - 1][0], 20) << rellenartexto(matriz[i - 1][1], 10) << rellenartexto(matriz[i - 1][2], 10) << rellenartexto(matriz[i - 1][3], 15) << rellenartexto(matriz[i - 1][4], 10) << endl;
	}
	cout << endl;
}

void presionarteclacontinuar()
{
	// cout << "Presione una tecla para continuar..." << endl;
	system("PAUSE");
}

void borrarpantalla()
{
	system("CLS");
}

void dibujarasteriscos(float longitud_texto)
{
	string linea;
	int posicion;
	linea = "";
	longitud_texto = longitud_texto + 10;
	while (posicion <= longitud_texto)
	{
		linea = "*" + linea;
		posicion = posicion + 1;
	}
	cout << linea << endl;
}

void creartitulo(string texto)
{
	int cantidadcaracteres;
	cantidadcaracteres = texto.size();
	dibujarasteriscos(cantidadcaracteres);
	cout << "**** " + texto + " *****" << endl;
	dibujarasteriscos(cantidadcaracteres);
}

void reglibros()
{
	int c;
	int f;
	int i;
	string libros[3][4];
	string titulo;
	titulo = "REGISTRO DE LIBROS";
	f = 3;
	c = 4;
	cout << endl;
	borrarpantalla();

	for (i = 1; i <= f; i++)
	{
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese TITULO del libro " << i << endl;
		imprimirlibros(libros);
		cin >> libros[i - 1][0];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese AUTOR del libro " << i << endl;
		imprimirlibros(libros);
		cin >> libros[i - 1][1];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese ANIO del libro " << i << endl;
		imprimirlibros(libros);
		cin >> libros[i - 1][2];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese COLOR del libro " << i << endl;
		imprimirlibros(libros);
		cin >> libros[i - 1][3];
	}
	borrarpantalla();
	creartitulo(titulo);
	imprimirlibros(libros);
	presionarteclacontinuar();
}

void regtrabajadores()
{
	int c;
	int f;
	int i;
	string titulo;
	string trabajadores[3][5];
	titulo = "REGISTRO DE TRABAJADORES";
	f = 3;
	c = 5;
	borrarpantalla();
	for (i = 1; i <= f; i++)
	{
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese NOMBRE del trabajador " << i << endl;
		imprimirtrabajadores(trabajadores);
		cin >> trabajadores[i - 1][0];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese EDAD del trabajador " << i << endl;
		imprimirtrabajadores(trabajadores);
		cin >> trabajadores[i - 1][1];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese CIUDAD del trabajador " << i << endl;
		imprimirtrabajadores(trabajadores);
		cin >> trabajadores[i - 1][2];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese CARGO del trabajador " << i << endl;
		imprimirtrabajadores(trabajadores);
		cin >> trabajadores[i - 1][3];
		borrarpantalla();
		creartitulo(titulo);
		cout << "Ingrese SALARIO del trabajador " << i << endl;
		imprimirtrabajadores(trabajadores);
		cin >> trabajadores[i - 1][4];
	}
	borrarpantalla();
	creartitulo(titulo);
	imprimirtrabajadores(trabajadores);
	presionarteclacontinuar();
}

void menuprincipal()
{
	borrarpantalla();
	cout << "**********************************" << endl;
	cout << "**** Tarea 3_2: Estructura 2 ****" << endl;
	cout << "*********************************" << endl;
	cout << "Seleccione una opci�n:" << endl;
	cout << " [1] Registrar libros" << endl;
	cout << " [2] Registrar trabajadores" << endl;
	cout << " [0] Salir" << endl;
}

int main()
{
	int op;
	// Hacer un men� que realice lo siguiente:
	// Hacer una estructura para registrar los datos de tres libros como: t�tulo, autor, a�o y color del libro.
	// Hacer una estructura para el registro de trabajadores, los datos a ingresar queda a su decisi�n.
	// Ejecutar el programa hasta que el usuario desee salir
	op = 100;
	while (op != 0)
	{
		menuprincipal();
		cin >> op;
		switch (op)
		{
		case 0:
			cout << "Escrito por: Edwin De La Cruz " << endl;
			return 0;
			break;
		case 1:
			reglibros();
			break;
		case 2:
			regtrabajadores();
			break;
		default:
			cout << "La opcion seleccionada no es valida." << endl;
		}
	}
	cout << "Escrito por: Edwin De La Cruz " << endl;
	return 0;
}

string convertiratexto(float f)
{
	stringstream ss;
	ss << f;
	return ss.str();
}
