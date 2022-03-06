Funcion Jugar(  )
	
	Definir Palabras Como Caracter;
	Definir UsuarioEditarPalabras Como Caracter;
	
	Si Longitud(Palabras) > 0 Entonces
		Escribir "El archivo tiene palabras";
	SiNo
		Escribir  "No hay palabras guardadas, desea guardarlas ahora?";
		
		Leer UsuarioEditarPalabras;
		
		Si UsuarioEditarPalabras = "S" Entonces
			Escribir "Editar palabras";
			GuardarPalabras(  );
		SiNo
			Escribir "Regresa al menú principal";
			MenuPrincipal();
		Fin Si
		
	Fin Si
	
	
Fin Funcion


Funcion GuardarPalabras(  )
	// Para que el usuario guarda las palabras
	
Fin Funcion

Funcion RetornoGuardado <- GuardarArchivo ( Argumentos )
	
Fin Funcion

Funcion RetornoLeer  <- LeerArchivo (  )
	
Fin Funcion



Funcion Instrucciones(  )
	
Fin Funcion

Funcion Historia(  )
	
Fin Funcion

Funcion Presentacion (  )
	
Fin Funcion




Funcion salida <- RellenarTexto ( texto_inicial, longitud_final )
	Definir  salida Como Caracter;
	salida = texto_inicial;
	Mientras longitud(salida) < longitud_final Hacer
		salida = Concatenar(salida, " ");
	Fin Mientras	
	salida = Concatenar(subcadena(salida, 0, longitud_final), " ");
Fin Funcion


Funcion ImprimirLibros ( matriz)
	Definir i Como Entero;
	i = 1;
	//t?tulo, autor, a?o y color del libro
	Escribir , RellenarTexto("#", 2), RellenarTexto("TITULO", 20), RellenarTexto("AUTOR", 20), RellenarTexto("ANIO", 10), RellenarTexto("COLOR", 15);
	Para i<-1 Hasta 3 Con Paso 1 Hacer	
		Escribir , RellenarTexto(ConvertirATexto(i), 2), RellenarTexto(matriz[i, 1], 20), RellenarTexto(matriz[i, 2], 20), RellenarTexto(matriz[i, 3], 10), RellenarTexto(matriz[i, 4], 15);		
	Fin Para
	
Fin Funcion

Funcion ImprimirTrabajadores ( matriz)
	Definir i Como Entero;
	i = 1;
	// Nombre y apellido, edad, ciudad, cargo, salario 
	Escribir RellenarTexto("#", 2), RellenarTexto("NOMBRE", 20), RellenarTexto("EDAD", 10), RellenarTexto("CIUDAD", 10), RellenarTexto("CARGO", 15), RellenarTexto("SALARIO", 10);
	Para i<-1 Hasta 3 Con Paso 1 Hacer	
		Escribir RellenarTexto(ConvertirATexto(i), 2), RellenarTexto(matriz[i, 1], 20), RellenarTexto(matriz[i, 2], 10), RellenarTexto(matriz[i, 3], 10), RellenarTexto(matriz[i, 4], 15), RellenarTexto(matriz[i, 5], 10);		
	Fin Para
	
Fin Funcion

Funcion PresionarTeclaContinuar ()
	Definir enter Como Caracter;
	Escribir "";
	Escribir "Presione enter para volver al men? principal...";
	Leer enter;	
Fin Funcion


Funcion BorrarPantalla  (  )
	Limpiar Pantalla;
Fin Funcion


Funcion DibujarAsteriscos  ( longitud_texto)
	Definir posicion Como Entero;
	Definir  linea Como Caracter;
	linea = "";
	longitud_texto = longitud_texto+10;
	Mientras posicion <= longitud_texto Hacer
		linea = "*"+ linea;
		posicion = posicion+1;
	Fin Mientras
	Escribir linea;
Fin Funcion


Funcion CrearTitulo  ( texto )
	Definir cantidadCaracteres Como Entero;
	cantidadCaracteres = Longitud(texto);
	DibujarAsteriscos(cantidadCaracteres);
	Escribir "**** "+texto+" *****";
	DibujarAsteriscos(cantidadCaracteres);
Fin Funcion








Funcion MenuPrincipal (  )
	BorrarPantalla;
	Escribir "*************************+++++++*";
	Escribir "*** EL AHORCADO *****";
	Escribir "*************************+++++++*";
	Escribir "Seleccione una opci?n:";
	Escribir  "	[1] Instrucciones";
	Escribir  "	[2] Editar Palabras";
	Escribir  "	[3] Jugar";
	Escribir  "	[0] Salir";
	
	
Fin Funcion

Algoritmo Ahorcado
	
	//Hacer un men? que realice lo siguiente:	
	//	Hacer una estructura para registrar los datos de tres libros como: t?tulo, autor, a?o y color del libro. 
	//	Hacer una estructura para el registro de trabajadores, los datos a ingresar queda a su decisi?n.
	//	Ejecutar el programa hasta que el usuario desee salir	
	
	Definir op Como Entero;
	
	op = 100;
	
	Mientras op <> 0 Hacer
		
		MenuPrincipal();
		Leer op;
		Segun op Hacer
			1:
				Instrucciones();
			2:
				GuardarPalabras();
			3:
				Jugar();				
			De Otro Modo:
				Escribir "La opcion seleccionada no es valida.";
		Fin Segun
		
		
	Fin Mientras
	
FinAlgoritmo
