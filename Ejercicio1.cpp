#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

// GUIA 
// unsigned --> es como el entero pero no puede ser negativo. Se usar� para contar as� que nunca puede ser negativo.
// const --> constante
// & --> referencia
// vector<int> --> vector de enteros
// int --> entero



// Esta es la funci�n que recibe como primer par�metro una referencia constante a un vector de enteros y 
// como segundo par�metros un pivote (entero tambi�n (int)).
unsigned getNumNumMayoresQuePivote (std::vector<int> const & enteros, int pivote) {
  unsigned numEnterosMayoresQueElPivote = 0;
  
  // it = iterador.
  for (int it = 0;it <  enteros.size(); it++) 
	  if (enteros.at(it) > pivote) 
		  numEnterosMayoresQueElPivote++;
  
  return numEnterosMayoresQueElPivote;
}


// argc es un entero que nos indica el n�mero de par�metros que le hemos pasado al programa
// argv es un puntero que apunta al vector de cadenas que contiene todos los par�metros del programa
int main (int argc, char * argv[]) {
	int elPivote; 
	std::vector<int> losEnteros;
	std::ifstream fich;
	

	if (argc == 0) {  // no se le ha pasado ning�n par�metro
		std::cerr << "Por lo menos debe indicar el nombre del fichero que contiene los numeros...saliendo del programa." << std::endl;
		return -1;
	}
	else if (argc == 1)  // Solo se le ha pasado como par�metro el nombre del fichero de entrada. No se le ha pasado el pivote
		elPivote = 10;
	else                // si se le pasan 2 o m�s. argv[2] es el segundo par�metros, que ser�a el pivote
		elPivote = atoi (argv[2]);  // la funci�n atoi convierte una cadena que contiene un numero en el equivalente tipo de dato entero.
	
	fich.open (argv[1]);  // Abrimos el fichero con el nombre del archivo (contenido en argv[1])
	
	while (!fich.eof()) {   // mientras no lleguemos al final del fichero. eof = End Of File
		std::string numero;
		getline(fich, numero);  // cuando leamos una linea enseguida fich apuntar� a la siguiente.
		losEnteros.push_back(atoi(numero.c_str()));  // metemos el numero le�do convertido en un entero pero antes hay que convertir el string en una cadena con la funci�n c_str()
	}
	
	std::cout << "El vector es: [";
	for (int i = 0; i < losEnteros.size(); i++) {
		std::cout << losEnteros[i];
		if (i < losEnteros.size() - 1)
			std::cout << ", ";
		else
			std::cout << "]" << std::endl;
	}
	
	

	
	
	
	
	std::cout << "En el vector hay " << getNumNumMayoresQuePivote(losEnteros, elPivote) <<  " numeros mayores que el pivote." << std::endl;
	
	return 0;

}
