#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>

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
string *LeerArchivo();

void Instrucciones()
{
	cout << "INSTRUCCIONES" << endl;
}

void EditarPalabras()
{
	cout << "EDITAR PALABRAS" << endl;
}

void IniciarJuego(string palabra)
{

	string palabra_jugar = "";
	int LetrasEscondidas = 0;

	for (std::string::size_type i = 0; i < palabra.size(); ++i)
	{
		int random = 1 + (rand() % 100);

		if (random % 2)
		{
			palabra_jugar.push_back(palabra[i]);
		}
		else
		{
			palabra_jugar.push_back('_');
			LetrasEscondidas++;
		}
	}
	//	cout << "Palabra 1: " << palabra << " Palabra 2: " << palabra_jugar << endl;

	char caracter = ' ';
	bool FinJuego = false;
	int Intentos = LetrasEscondidas;

	cout << "Palabra: " << palabra_jugar << " Intentos " << Intentos << endl;

	while (FinJuego == false)
	{
		cout << "Ingrese una letra: ";
		cin >> caracter;
		cout << endl;
		bool letra_encontrada = false;
		for (std::string::size_type i = 0; i < palabra.size(); ++i)
		{
			if (palabra[i] == caracter)
			{
				palabra_jugar[i] = caracter;
				letra_encontrada = true;
			}
		}

		if (letra_encontrada == false)
		{
			Intentos--;
		}

		if (palabra_jugar == palabra || Intentos <= 0)
		{
			FinJuego = true;
		}
		cout << "Palabra: " << palabra_jugar << " Intentos " << Intentos << endl;
	}

	if (palabra_jugar == palabra)
	{
		cout << "GANADOR!!!!!!" << endl;
	}
	else
	{
		cout << "Perdedor !!!!!!" << endl;
	}
}

void Jugar()
{
	cout << "JUGAR" << endl;
	string *pal = LeerArchivo();
	vector<string> ListaPalabras;
	string PalabraJugar = "";

	// Llenar el vector con las palabras
	for (int i = 0; i < 100; i++)
	{
		string l = pal[i];

		if (l.size() > 0)
		{
			ListaPalabras.push_back(l);
		}
	}

	if (ListaPalabras.size() > 0)
	{
		// Elegir parabra aleatoriamente
		int random = 1 + (rand() % ListaPalabras.size() - 1);
		//	cout << "Random: " << random << endl;
		//		cout << "Palabra: " << ListaPalabras[random] << endl;
		IniciarJuego(ListaPalabras[random]);
	}
	else
	{
		cout << "No hay palabras guardadas. Necesita guardarlas para iniciar el juego." << endl;
		presionarteclacontinuar;
		EditarPalabras();
	}

	presionarteclacontinuar;
}

void Presentacion()
{
	cout << "Presentacion" << endl;
}

// Lee un archivo de texto y lo guarda en una matriz
string *LeerArchivo()
{
	cout << "Leer archivo palabras.txt" << endl;
	int numlinea = 0;
	ifstream archivo("palabras.txt");
	string linea;
	string *matriz = new string[100];
	while (getline(archivo, linea))
	{
		// cout << "**** " + linea + " *****" << endl;
		//  std::istringstream iss(linea);
		matriz[numlinea] = linea;
		numlinea++;
	}

	presionarteclacontinuar;
	return matriz;
}

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
	cout << "********** EL AHORCADO ***********" << endl;
	cout << "*********************************" << endl;
	cout << "Seleccione una opcion:" << endl;
	cout << " [1] Instrucciones" << endl;
	cout << " [2] Editar palabras" << endl;
	cout << " [3] Jugar" << endl;
	cout << " [4] Presentacion" << endl;
	cout << " [0] Salir" << endl;
}

int main()
{
	int op;
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
			Instrucciones();
			break;
		case 2:
			EditarPalabras();
			break;
		case 3:
			Jugar();
			presionarteclacontinuar();
			break;
		case 4:
			Presentacion();
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
