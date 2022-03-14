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
//#include <wchar.h>
//#include <locale.h> // Sirve para poder mostrar tildes en la consola

using namespace std;

void gotoxy(short x, short y); // here we declare the gotoxy function//
HANDLE Consola = GetStdHandle(STD_OUTPUT_HANDLE);

string convertiratexto(float f);

void presionarteclacontinuar();
void borrarpantalla();
void DibujarMarcoSuperior(float longitud_texto);
void CrearTitulo(string titulo, string subtitulo);
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
	borrarpantalla();
	CrearTitulo("JUEGO EL AHORCADO", "Instrucciones");
	SetConsoleTextAttribute(Consola, 7);
	string Texto = "Antes de iniciar el juego debera ingresar las palabras para el juego en la opcion 2 del menu principal.\nUna vez tenga guardadas las palabras, en el menu principal debe seleccionar la opcion 3.\nAhora iniciado el juego se le mostrara una palabra seleccionada aleatoriamente con letras en estaran ocultas reemplazadas por el caracter _\nLa cantidad de letras ocultas es la cantidad maxima de intentos que tiene antes de perder la jugada.";
	cout << Texto << endl
		 << endl;
	presionarteclacontinuar();
}

void SetearPalabras()
{
	borrarpantalla();
	CrearTitulo("JUEGO EL AHORCADO", "Registro de palabras para jugar");
	SetConsoleTextAttribute(Consola, 7);

	string Palabra = "";
	cout << endl
		 << "Ingrese las palabras para el juego (no incluya tildes) y presione enter.\nCuando termine presione 0 para guardar y salir:" << endl;

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

			if (Palabra.size() > 0)
			{
				archivo << Palabra << endl;
			}
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
		SetConsoleTextAttribute(Consola, 15);
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
			Beep(1500, 500);
			Intentos--;
		}
		else
		{
			Beep(3000, 250);
		}

		if (palabra_jugar == palabra || Intentos <= 0)
		{
			FinJuego = true;
		}

		MostrarAhorca(palabra_jugar, LetrasEscondidas, Intentos);
	}

	if (palabra_jugar == palabra)
	{
		SetConsoleTextAttribute(Consola, 2);
		cout << "  ¡¡¡¡¡¡¡  Ha ganado el juego !!!!!!" << endl
			 << endl;
	}
	else
	{
		SetConsoleTextAttribute(Consola, 12);
		cout << "  Ha perdido el juego,"
			 << " la palabra oculta era: " << palabra << endl
			 << endl;
	}
	cout << '\a';
}

void MostrarAhorca(string palabra_jugar, int TotalIntentos, int IntentosRestantes)
{
	string Titulo = "JUEGO EL AHORCADO";

	// string SubTitulo = "";
	borrarpantalla();
	CrearTitulo("JUEGO EL AHORCADO", "Palabra: " + palabra_jugar);
	SetConsoleTextAttribute(Consola, 7);

	cout << endl
		 << "Intentos restantes: " << IntentosRestantes << endl
		 << endl;

	SetConsoleTextAttribute(Consola, 2);

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

	SetConsoleTextAttribute(Consola, 7);
}

void MoverHumano(int TotalIntentos, int IntentosRestantes)
{

	switch (IntentosRestantes)
	{

	case 0:
		SetConsoleTextAttribute(Consola, 8);
		break;
	case 1:
		SetConsoleTextAttribute(Consola, 5);
		break;
	case 2:
		SetConsoleTextAttribute(Consola, 14);
		break;
	case 3:
		SetConsoleTextAttribute(Consola, 6);
		break;
	default:
		SetConsoleTextAttribute(Consola, 2);
		break;
	}

	int x = 26;
	int y = 10 + IntentosRestantes;
	gotoxy(x, y + 1);
	cout << "  O" << endl;
	gotoxy(x, y + 2);
	cout << "_/|\\_" << endl;
	gotoxy(x, y + 3);
	cout << "  |" << endl;
	gotoxy(x, y + 4);
	cout << "_/ \\_" << endl;
	gotoxy(0, 29);
}

void Jugar()
{
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
		borrarpantalla();
		CrearTitulo("JUEGO EL AHORCADO", "Jugar");
		SetConsoleTextAttribute(Consola, 7);
		cout << "No hay palabras guardadas. Necesita setearlas para iniciar el juego. Vuelva al menu principal." << endl;
		presionarteclacontinuar;
		SetearPalabras();
	}

	presionarteclacontinuar;
}

void Presentacion()
{
	borrarpantalla();
	SetConsoleTextAttribute(Consola, 1);
	gotoxy(0, 0);
	cout << endl
		 << "                    INSTITUTO TECNOLOGICO \"ISMAC\"" << endl;
	SetConsoleTextAttribute(Consola, 9);
	gotoxy(56, 1);
	printf(",                      ");
	gotoxy(54, 2);
	printf(",****.                   ");
	gotoxy(50, 3);
	printf("..********,                  ");
	gotoxy(40, 4);
	printf("..,*,,*************//,                 ");
	gotoxy(12, 5);
	printf("*/*.   ,,,,,.     ..   . ,/((/****,..,,*,,****///*                 ");
	gotoxy(6, 6);
	printf("((#######/,      /(###/,,*//./(/(////*,****,***********,                 ");
	gotoxy(5, 7);
	printf("#####(/*  %.   %@@@&#&@&((/**(/*/****(@@@@@@@@@%******//.                 ");
	gotoxy(3, 8);
	printf("*.(##      .#  *@@@@...,((******/*//*(@@@@@(..*&@@&,***//,                  ");
	gotoxy(1, 9);
	printf("####(/#/     /(  /@@@@@%#(*********//*,@@@@@%,..,#@@%,,***/*****,             ");
	gotoxy(1, 10);
	printf("(((##(/#(,   *(    .**(#/,*********/(**%@@@@@@@@@@@&*,/*//(#*   ,.            ");
	gotoxy(1, 11);
	printf("#(/##/(((//(#((#(*,./#(************/(****(%&@@@@@#,,*(//(##/                  ");
	gotoxy(2, 12);
	printf("/####((####(/%%######((/**************************((((#####*                 ");
	gotoxy(4, 13);
	printf("###(((/. ,%%###############((((((((((((((################(.                ");
	gotoxy(4, 14);
	printf("(((((,  (%%#############################################/(.                ");
	gotoxy(4, 15);
	printf("((((/. /%%#########(/###############################(###(*                 ");
	gotoxy(4, 16);
	printf("((((/. #%####(####(.(###############################/(##/.                 ");
	gotoxy(4, 17);
	printf("/////   #%#(#####(/,##############(###########/(###(//(*                   ");
	gotoxy(4, 18);
	printf("/////.   ./(######*,(#############(#(####(###(//###/,                      ");
	gotoxy(4, 19);
	printf("/////.        ..,,.,,/(#################(/(((*,..                          ");
	gotoxy(4, 20);
	printf("/**///*,/**                  .......                                       ");
	gotoxy(5, 21);
	printf("*******//*/(((((((////((/. //*....*/, *.                                  ");
	gotoxy(9, 22);
	printf("*////*((((((((((((((, **/..,****,/(((((/.                             ");
	gotoxy(26, 23);
	printf("((%%%(((,*(((/.*(((/((((/                            ");
	gotoxy(26, 24);
	printf("((*.((((*/**####((/,*(((((,                          ");
	gotoxy(26, 25);
	printf("((.,(((/,/%/(*,/((.  .((((/**                        ");
	gotoxy(26, 26);
	printf("(( *((,/&/,/*,/(,.   .****///,           ...         ");
	gotoxy(26, 27);
	printf("(( *,/%/*/((/,,,,((,. .******.       /#(//*//*/*,    ");
	gotoxy(26, 28);
	printf("**.(%*,,*//,,,,,,,,,**//////,      *///.      *//*,  ");
	gotoxy(26, 29);
	printf(",.&/,,,/##(*,***,,,/((////,       .(*,   .,.    **** ");
	gotoxy(28, 30);
	printf(",,,,,,,((#####(((((((/,.        ,(*   .  .*   ,//*,");
	gotoxy(26, 31);
	printf("//*,.,,,,,,/######(((/..           ,/*,    ,*   ,/**.");
	gotoxy(26, 32);
	printf("///,  (//(##(####(##(,,,.              .,,.    ,//** ");
	gotoxy(26, 33);
	printf("///.  ,(#((//((###(/***//*,...               ,/****, ");
	gotoxy(26, 34);
	printf("///.       .(###/ *(##(/***//*,,..  .  ..,***//**(.  ");
	gotoxy(25, 35);
	printf("////,       .////*,   *(###((***//**///**///***//.    ");
	gotoxy(25, 36);
	printf("////*        *////*       ,/(####(((/////((((/.       ");
	gotoxy(25, 37);
	printf("////*        ,////*.               ,,,,               ");
	gotoxy(25, 38);
	printf("////*,       .////*,                                  ");
	gotoxy(25, 39);
	printf(",****,,      .*****,.                                 ");
	gotoxy(14, 40);
	printf("%&&%%%#*,,,,,,,,,,,.   *&*,,,,,,,,,(#%%%##(,                     ");
	gotoxy(14, 41);
	printf(",,,,,,,,,,,,,,,,,,..   ,/,,,,,,,,,,,,,,,,,,,                     ");
	gotoxy(15, 42);
	printf(".........   ....        ...... ......,....                      ");
	gotoxy(0, 43);

	SetConsoleTextAttribute(Consola, 10);
	cout << endl
		 << "  Creado por: Edwin De La Cruz" << endl;
	cout << endl
		 << "  DESARROLLO DE SOFTWARE - Primero Online" << endl;
	gotoxy(0, 0);
	cout << '\a';
	presionarteclacontinuar();
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

void DibujarMarcoSuperior(float longitud_texto, bool superior)
{
	string linea;
	int posicion;
	linea = " ";
	longitud_texto = longitud_texto + 21;
	// Esta linea es para que en la consola se puedan visualizar los caracteres extendidos de ASCII
	SetConsoleCP(437);

	if (superior)
	{
		linea += char(201);
	}
	else
	{
		linea += char(200);
	}

	while (posicion <= longitud_texto)
	{
		linea += char(205);
		posicion = posicion + 1;
	}

	if (superior)
	{
		linea += char(187);
	}
	else
	{
		linea += char(188);
	}
	cout << linea << endl;
}

void DibujarMarcoSubtitulo(float longitud_texto)
{
	string linea;
	int posicion;
	linea = " ";
	longitud_texto = longitud_texto + 21;
	// Esta linea es para que en la consola se puedan visualizar los caracteres extendidos de ASCII
	SetConsoleCP(437);

	linea += char(192);

	while (posicion <= longitud_texto)
	{
		// linea += "*";
		linea += char(196);

		posicion = posicion + 1;
	}

	linea += char(217);

	cout << linea << endl;
}

void CrearTitulo(string texto, string subtitulo)
{
	SetConsoleTextAttribute(Consola, 1);
	cout << "              " << endl;
	DibujarMarcoSuperior(texto.size(), true);
	cout << " " << char(186) << "           " + texto + "           " << char(186) << endl;
	DibujarMarcoSuperior(texto.size(), false);
	SetConsoleTextAttribute(Consola, 9);
	cout << " " << char(179);

	// Igualamos la cantidad de caracteres del subtitulo a la cantidad de caracteres del titulo, para que se ajuste el marco del titulo con el subtitulo
	if ((texto.size() + 21) > subtitulo.size())
	{

		cout << subtitulo;
		int i = 0;
		while (i < (texto.size() + 21 - subtitulo.size()))
		{
			cout << " ";
			i++;
		}

		//		cout << subtitulo;
	}
	else
	{
		cout << subtitulo.substr(texto.size() + 21) << endl;
	}
	cout << " " << char(179) << endl;
	DibujarMarcoSubtitulo(texto.size());
}

void menuprincipal()
{
	borrarpantalla();
	CrearTitulo("JUEGO EL AHORCADO", "Menu Principal");
	SetConsoleTextAttribute(Consola, 7);

	cout << "  Seleccione una opcion:" << endl;
	cout << "   [1] Instrucciones" << endl;
	cout << "   [2] Setear palabras" << endl;
	cout << "   [3] Jugar" << endl;
	cout << "   [4] Presentacion" << endl;
	cout << "   [0] Salir" << endl;
}

int main()
{

	Presentacion();

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
			SetearPalabras();
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
