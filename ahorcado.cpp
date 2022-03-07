#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

string convertiratexto(float f);

void presionarteclacontinuar();
void borrarpantalla();
void dibujarasteriscos(float longitud_texto);
void CrearTitulo(string texto);
void MostrarAhorcado(string palabra_jugar, int TotalIntentos,  int IntentosRestantes);
void menuprincipal();
string *LeerArchivo();

void Instrucciones()
{
	cout << "INSTRUCCIONES - Por implementar texto informativo" << endl;
	presionarteclacontinuar();
}

void EditarPalabras()
{
	cout << "EDITAR PALABRAS - Por implementar recibir información del usuario y almacenarlo en el archivo local" << endl;
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

	MostrarAhorcado(palabra_jugar, LetrasEscondidas, Intentos);

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

		MostrarAhorcado(palabra_jugar, LetrasEscondidas, Intentos);
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

void MostrarAhorcado(string palabra_jugar, int TotalIntentos, int IntentosRestantes)
{
	borrarpantalla();
	CrearTitulo("Ahorcado");
	cout << "	" << palabra_jugar << endl
		 << endl
		 << "Intentos " << IntentosRestantes << endl
		 << endl;

	cout << "	" << palabra_jugar << endl
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

	if (TotalIntentos == IntentosRestantes)
	{
		cout << "   [-]                      O" << endl;
		cout << "   [-]                    _/|\\_" << endl;
		cout << "   [-]                      |" << endl;
		cout << "[-][-][-]                 _/ \\_" << endl;
	}
	else
	{
		cout << "   [-]              x        O" << endl;
		cout << "   [-]              x      _/|\\_" << endl;
		cout << "   [-]              x        |" << endl;
		cout << "[-][-][-]           x      _/ \\_" << endl;
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
