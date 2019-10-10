#include <iostream>
using namespace std;


bool notDone = true;
int i, a, nIterations, temp, gap, *aux, *aux2;

class BinarySearch {
    public:
    int pos = 0, tempB, posAux;

    bool searchTerm (int array[], int size, int term){
        gap = size/2;
        
        if (*(array + gap) == term){
            pos = pos + gap;
            if (posAux < 0 && pos > 1) pos = pos -gap;
            return true;    
        }else if (size == 0)
            return false;
 
        if (*(array + gap) > term){              //Obvia la parte "derecha" del array.
            posAux--;
            if (posAux < 0){
               pos = size - 1;
            }
            searchTerm(array, gap, term);
        }else{                                   //Obvia la parte "izquierda" del array.
            posAux++;
            pos = pos + gap + 1;
            searchTerm(array+gap+1, gap-1, term);
        }
        
    }

    int getPos() {
        tempB = pos;
        pos = 0;
        return tempB;
    }
};

void InsertionSort(int array[], int size) {
    cout << "Your list: ";
    for (i = 0; i < size; i++)
        cout << *(array + i) << "  ";
    cout << endl << "Sorting..." << endl;

    nIterations = 0;
    aux = array + 1;
    do {
        notDone = false;
        for (i = 0; i < size; i++) {
            if (*(array + i)>*(aux + i)) { //Si el valor de la derecha es menor que el de la izquierda:
                a = i;
                do {
                    temp = *(aux + a); //Guardamos el valor de la derecha en temp.
                    *(aux + a) = *(array + a); //Le asignamos al valor de la derecha el valor de la izquierda.
                    *(array + a) = temp; //Le asignamos al valor de la izquierda el valor de temp.
                    a--;
                } while (*(array - a)>*(aux - a)); //Sigue siendo este valor menor?
                notDone = true;
            }
        }
        if (notDone) {
            nIterations++;
            cout << "Iteration " << nIterations << ": ";
            for (i = 0; i < size; i++)
                cout << *(array + i) << "  ";
            cout << endl;
        }
    } while (notDone);
    cout << endl << "Sorted in " << nIterations << " Iterations.";
}

void ShellSort(int array[], int size) {
    cout << "Shell Sort using N/2 gap:" << endl << endl;
    cout << "Your list: ";
    for (i = 0; i < size; i++)
        cout << *(array + i) << "  ";
    cout << endl << "Sorting..." << endl;

    nIterations = 0;
    gap = size;
    do {
        gap = gap / 2;
        aux = array + gap;
        for (i = 0; i < size; i++) {
            if (*(array + i)>*(aux + i)) {
                if (gap + i <= gap * 2) { //Ahorra tiempo. Si se sale no comprueba hacía atrás.
                    temp = *(aux + i);
                    *(aux + i) = *(array + i);
                    *(array + i) = temp;
                } else {
                    temp = *(aux + i);
                    *(aux + i) = *(array + i);
                    *(array + i) = temp;
                    aux = array + i;
                    aux2 = array + i - gap;
                    while (aux2 > array && *aux < *aux2) { //Comprueba si no se sale y si es necesario.
                        temp = *aux;
                        *aux = *aux2;
                        *aux2 = temp;

                        aux = aux - gap;
                        aux2 = aux2 - gap;
                    }
                    aux = array + gap; //Reubica aux.
                }
            }
            if (gap + i >= size) break; //Comprueba si aux ha acabado de recorrer el array.
        }

        nIterations++;
        cout << "Iteration " << nIterations << ": ";
        for (i = 0; i < size; i++)
            cout << *(array + i) << "  ";
        cout << endl;

    } while (gap / 2 > 0);
    cout << endl << "Sorted in " << nIterations << " Iterations.";
}

int main() {
    int size, toSearch, opt;
    BinarySearch bSearch;

    cout << "Simple C++ Insertion, Shell and Binary Search Demo." << endl << endl;
    cout << "Number of elements your list will contain: ", cin>>size;
    cout << endl << "Introduce all elements now:" << endl;

    int array[size];
    for (i = 0; i < size; i++)
        cin >> array[i];

    cout << "Choose sorting method:" << endl << "1) Insertion   2) Shell " << endl, cin>>opt, cout << endl << endl;

    if (opt == 1)
        InsertionSort(array, size);
    else
        ShellSort(array, size);  

    cout << endl << endl << "Any to continue, 1 to exit. ", cin>>opt, cout << endl;  
    
    while (opt!=1) {
        cout << "Choose sorting method:" << endl << "1) Insertion   2) Shell" << endl
        << "Or search an item on last sorted array:"<< endl <<"3) Binary Search" << endl, cin>>opt, cout << endl;

        if (opt == 3) {
            cout << "Term you would like to look for: ", cin>>toSearch, cout << endl;
            if (bSearch.searchTerm(array, size, toSearch))
                cout<<toSearch<<" is stored on array's position: "<<bSearch.getPos();
            else          
                cout<<toSearch<<" is not stored in the array.";
        } else {
            cout << "Number of elements your list will contain: ", cin>>size;
            cout << endl << "Introduce all elements now:" << endl;

            int loopArray[size];
            for (i = 0; i < size; i++)
                cin >> loopArray[i];

            if (opt == 1)
                InsertionSort(loopArray, size);
            else if (opt == 2)
                ShellSort(loopArray, size);
        }
        cout << endl << endl << "Any to continue, 1 to exit. ", cin>>opt, cout << endl;
    }
}
