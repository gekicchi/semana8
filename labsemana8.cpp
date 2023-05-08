#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CrearNodo(int dat) // ejercicio 1
{
	Node* newNode = new Node;
	newNode->data = dat;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

Node* InsertarNodo(Node* root,Node* nuevoNodo) // ejercicio 2
{
	if (root == NULL) // llego a posicion vacia
	{
		root = nuevoNodo;
	}
	else
	{
		if (root->data >= nuevoNodo->data) // moverse a la izquierda
		{
			root->left = InsertarNodo(root->left, nuevoNodo);
		}
		else // moverse a la derecha
		{
			root->right = InsertarNodo(root->right, nuevoNodo);
		}
	}
	return root;
}

void ImprimirArbol(Node* root) // ejercicio 3
{
	if (root == NULL)
		return;
		
	ImprimirArbol(root->left);
	cout << root->data << " ";
	ImprimirArbol(root->right);
}

bool BuscarNodo(Node* root, int dat) // ejercicio 4
{
	if (root == NULL)
		return false;
	else
	{
		if (root->data == dat)
			return true;
		
		if (root->data > dat)
			BuscarNodo(root->left, dat);
		else
			BuscarNodo(root->right, dat);
	}
}

int ValorMinimo(Node* root) // ejercicio 5
{
	if (root->left == NULL)
		return root->data;
	
	ValorMinimo(root->left);
}

int ValorMaximo(Node* root) // ejercicio 6
{
	if (root->right == NULL)
		return root->data;
		
	ValorMaximo(root->right);
}
/*
Node* EliminarNodo(Node* root, Node* leaf,int dat) // ejercicio 7
{
	if (leaf->data == dat) // nodo encontrado
	{
		if (root == leaf) // primer nodo
		{
			if (leaf->left != NULL)
			{
				*root = *leaf->left;
				//root->right = InsertarNodo
			}
			else if (leaf->right != NULL)
				*root = *leaf->right;
				
			return leaf;
		}
		else // cualquier otro
		{
			if (root->data > dat)
				root = InsertarNodo(root, leaf)
			
			leaf->left = NULL;
			leaf->right = NULL;
		}
		
		return leaf;
	}
	
	if (leaf->data > dat)
		return EliminarNodo(root, root->left, dat);
	else
		return EliminarNodo(root, root->right, dat);
}
*/

int main()
{
	int eleccion=0, data=0;
	Node* root = NULL;
	Node* nuevoNodo = new Node;
	Node* nodoEliminado = NULL;
	
	do{
		cout << "Menu de Pruebas" << endl;
		cout << "[1] Crear y Anadir Nodo\t[2] Buscar Nodo" << endl << "[3] Valor Minimo\t[4] Valor Maximo" << endl << "[5] Imprimir Arbol\t[6] Salir" << endl;
		do{
			cout << "Eleccion: ";
			cin >> eleccion;
		} while (eleccion < 1 && eleccion > 6);
		
		switch (eleccion)
		{
			case 1: // crear y añadir nodo
				cout << "Ingrese Data para Nodo: ";
				cin >> data;
				nuevoNodo = CrearNodo(data);
				root = InsertarNodo(root, nuevoNodo);
				break;
				
			case 2: // buscar nodo
				cout << "Data de Nodo a Buscar: ";
				cin >> data;
				if (BuscarNodo(root, data))
					cout << "Nodo se Encuentra en el Arbol" << endl;
				else
					cout << "Nodo no Esta en el Arbol" << endl;
				break;
				
			case 3: // valor minimo
				cout << "Buscando Valor Minimo..." << endl;
				cout << "Valor Minimo: " << ValorMinimo(root) << endl;
				break;
				
			case 4: // valor maximo
				cout << "Buscando Valor Maximo..." << endl;
				cout << "Valor Maximo: " << ValorMaximo(root) << endl;
				break;
				
			case 5: // imprimir arbol
				cout << "Nodos en Arbol: ";
				ImprimirArbol(root);
				cout << endl;
				break;
				
			case 6: // salir
			cout << "ADIOS!";
				break;
		}
		cout << endl;
	} while (eleccion != 6);
	
	return 0;
}
