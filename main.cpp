#include <iostream>
using namespace std;


bool notDone = true;
int i, a, nIterations, temp, gap, *aux, *aux2;

void InsertionSort (int array[], int size){

	cout<<"Your list: ";
	for (i = 0; i < size; i++)
		cout<<*(array+i)<<"  ";
	cout<<endl<<"Sorting..."<<endl;

	nIterations = 0;
	aux = array+1;
	do{
		notDone = false;
		for (i = 0; i < size; i++){
			if (*(array+i)>*(aux+i)){   		//Si el valor de la derecha es menor que el de la izquierda:
				a = i;
				do{
				temp = *(aux+a);				//Guardamos el valor de la derecha en temp.
				*(aux+a) = *(array+a);			//Le asignamos al valor de la derecha el valor de la izquierda.
				*(array+a) = temp;				//Le asignamos al valor de la izquierda el valor de temp.
				a--;
				}while(*(array-a)>*(aux-a));	//Sigue siendo este valor menor?
				notDone = true;
			}
		}
		if(notDone){
		nIterations++;
		cout<<"Iteration "<<nIterations<<": ";
		for (i = 0; i < size; i++)
			cout<<*(array+i)<<"  ";
		cout<<endl;
		}
	}while(notDone);
	cout<<endl<<"Sorted in "<<nIterations<<" Iterations.";
}

void ShellSort (int array[], int size){
int i, a, nIterations, temp, gap, *aux, *aux2;
	cout<<"Shell Sort using N/2 gap:"<<endl<<endl;
	cout<<"Your list: ";
	for (i = 0; i < size; i++)
		cout<<*(array+i)<<"  ";
	cout<<endl<<"Sorting..."<<endl;

	nIterations = 0;
	gap=size;
	do{
		gap = gap/2;
		aux = array+gap;

		for (i = 0; i < size; i++){
			if (*(array+i)>*(aux+i)){		
				if (gap+i <= gap*2){						//Ahorra tiempo. Si se sale no comprueba hacía atrás.
					temp = *(aux+i);				
					*(aux+i) = *(array+i);
					*(array+i) = temp;
				}else{
					temp = *(aux+i);				
					*(aux+i) = *(array+i);
					*(array+i) = temp;
					aux = array+i;
					aux2 = array+i-gap;
					while(aux2 > array && *aux < *aux2){	//Comprueba si no se sale y si es necesario.
						temp = *aux;
						*aux = *aux2;
						*aux2 = temp;

						aux = aux-gap;
						aux2 = aux2-gap;
					}
					aux = array+gap;						//Reubica aux.
				}
			}
			if(gap+i >= size) break;  						//Comprueba si aux ha acabado de recorrer el array.
		}

		nIterations++;
		cout<<"Iteration "<<nIterations<<": ";
		for (i = 0; i < size; i++)
			cout<<*(array+i)<<"  ";
		cout<<endl;
		
	}while(gap/2>0);
	cout<<endl<<"Sorted in "<<nIterations<<" Iterations.";
}
	
int main() {
	bool redo = true;
	int size, i, opt;
	while(redo){
	cout<<"Simple C++ Binary/Insertion and Shell Sorting Demo."<<endl<<endl;
	cout<<"Number of elements your list will contain: ",cin>>size;
	cout<<endl<<"Introduce all elements now:"<<endl;

	int array[size];
	for (i = 0; i < size; i++)
		cin>>array[i];

	cout<<"Choose sorting method."<<endl<<"1) Binary/Insertion   2) Shell"<<endl,cin>>opt,cout<<endl<<endl;

	if (opt==1)
		InsertionSort(array,size);
	else if(opt==2)
		ShellSort(array, size);
	

	cout<<endl<<endl<<"Any to continue, 1 to exit.",cin>>opt,cout<<endl;
	if (opt == 1)redo = false;
	}
}
