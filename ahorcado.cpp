#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(short x, short y); // here we declare the gotoxy function//
HANDLE Consola = GetStdHandle(STD_OUTPUT_HANDLE);

string convertiratexto(float f);

void presionarteclacontinuar();
void borrarpantalla();
void dibujarasteriscos(float longitud_texto);
void CrearTitulo(string texto);
void MostrarAhorca(string palabra_jugar, int TotalIntentos, int IntentosRestantes);
void menuprincipal();
string *LeerArchivo();
void MoverHumano(int TotalIntentos, int IntentosRestantes);

void gotoxy(short x, short y) // definition of gotoxy function//
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Instrucciones()
{
	cout << "INSTRUCCIONES - Por implementar texto informativo" << endl;
	presionarteclacontinuar();
}

void EditarPalabras()
{
	string Palabra = "";
	cout << "EDITAR PALABRAS - Por implementar recibir información del usuario y almacenarlo en el archivo local" << endl;
	cout << "ingrese las palabras y presione enter, cuando termine presione 0 para guardar y salir:" << endl;

	ofstream archivo("palabras.txt");
	if (archivo.is_open())
	{
		while (true)
		{
			cin >> Palabra;

			if (Palabra == "0")
			{
				break;
			}

			archivo << Palabra << endl;
		}
		archivo.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo" << endl;
	};

	presionarteclacontinuar();
}



void IniciarJuego(string palabra)
{

	string palabra_jugar = "";
	int LetrasEscondidas = 0;

	for (std::string::size_type i = 0; i < palabra.size(); ++i)
	{
		int random = 1 + (rand() % 1000);
		palabra[i] = toupper(palabra[i]);

		if (random % 2)
		{
			palabra_jugar.push_back(toupper(palabra[i]));
		}
		else
		{
			palabra_jugar.push_back('_');
			LetrasEscondidas++;
		}
	}

	char caracter = ' ';
	bool FinJuego = false;
	int Intentos = LetrasEscondidas;

	MostrarAhorca(palabra_jugar, LetrasEscondidas, Intentos);

	while (FinJuego == false)
	{

		cout << "Ingrese una letra: ";
		cin >> caracter;
		cout << endl;
		bool letra_encontrada = false;
		for (std::string::size_type i = 0; i < palabra.size(); ++i)
		{
			if (palabra[i] == toupper(caracter))
			{
				palabra_jugar[i] = toupper(caracter);
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

		MostrarAhorca(palabra_jugar, LetrasEscondidas, Intentos);
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

void MostrarAhorca(string palabra_jugar, int TotalIntentos, int IntentosRestantes)
{
	string Titulo = "AHORCADO";
	borrarpantalla();
	CrearTitulo(Titulo);
	cout << "	" << palabra_jugar << endl
		 << endl
		 << "Intentos " << IntentosRestantes << endl
		 << endl;

	cout << "   [-][-][-][-][-][-][-][-][-]" << endl;
	cout << "   [-]                      |" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "   [-]" << endl;
	cout << "[-][-][-]" << endl;

	MoverHumano(TotalIntentos, IntentosRestantes);
}

void MoverHumano(int TotalIntentos, int IntentosRestantes)
{
	int x = 26;
	int y = 8 + IntentosRestantes;
	gotoxy(x, y + 1);
	cout << "  O" << endl;
	gotoxy(x, y + 2);
	cout << "_/|\\_" << endl;
	gotoxy(x, y + 3);
	cout << "  |" << endl;
	gotoxy(x, y + 4);
	cout << "_/ \\_" << endl;
	gotoxy(0, 26);
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
	cout << "Presentacion - Por implementar pantalla animada o en colores de bienvenida al juego" << endl;
	presionarteclacontinuar;
}

// Lee un archivo de texto y lo guarda en una matriz
string *LeerArchivo()
{
	// cout << "Leer archivo palabras.txt" << endl;
	int numlinea = 0;
	ifstream archivo("palabras.txt");
	string linea;
	string *matriz = new string[100];
	while (getline(archivo, linea))
	{
		matriz[numlinea] = linea;
		numlinea++;
	}

	presionarteclacontinuar;
	return matriz;
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

void CrearTitulo(string texto)
{
	int cantidadcaracteres;
	cantidadcaracteres = texto.size();
	dibujarasteriscos(cantidadcaracteres);
	cout << "**** " + texto + " *****" << endl;
	dibujarasteriscos(cantidadcaracteres);
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
