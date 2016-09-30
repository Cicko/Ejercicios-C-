#include <iostream>
#include <vector>

// GUIA 
// unsigned --> es como el entero pero no puede ser negativo. Se usar� para contar as� que nunca puede ser negativo.
// const --> constante
// & --> referencia
// vector<int> --> vector de enteros
// int --> entero



// Esta es la funci�n que recibe como primer par�metro una referencia constante a un vector de enteros y 
// como segundo par�metros un pivote (entero tambi�n (int)).
unsigned getNumNumMayoresQuePivote (const std::vector<int>& enteros, int pivote) {
  unsigned numEnterosMayoresQueElPivote = 0;
  
  // it = iterador.
  for (int it = 0;it <  enteros.size(); it++) 
	  if (enteros.at(it) > pivote) 
		  numEnterosMayoresQueElPivote++;
  
  return numEnterosMayoresQueElPivote;
}


int main () {
	int elPivote = 8; 
	int numDeEnteros = 20;  // adem�s ser� el mayor n�mero almacenado en el vector
	std::vector<int> losEnteros;
	
	// Metemos 20 numeros en el vector = {1, 2,..., 20}
	for (int i = 1;i <= numDeEnteros; i++)  
		losEnteros.push_back(i);
	
	std::cout << "En el vector hay " << getNumNumMayoresQuePivote(losEnteros, elPivote) <<  " numeros mayores que el pivote." << std::endl;
	
	return 0;

}
