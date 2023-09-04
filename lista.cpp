#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
} *pri, *ult;
typedef struct nodo * Tlista;

void insertarInicio(Tlista &lista,int valor){
	Tlista q;
	q= new(struct nodo);
	q->nro = valor;
	q->sgte = lista;
	lista = q;
}
void inserFinal(Tlista &lista,int valor){
	Tlista q,x;
	q= new(struct nodo);
	q->nro = valor;
	q->sgte=NULL;

	if(lista==NULL){
		lista=q;
	}else{
		x=lista;
		while(x->sgte!=NULL){
			x=x->sgte;
		}
		x->sgte=q;
	}
}
void mosLista(Tlista &lista){
	Tlista q;
	q=new(struct nodo);
	q= lista;
	
	while(q != NULL){
		cout<<q->nro<<"-";
		q = q->sgte;
	}
}
void buscarElemento(Tlista lista,int valor){
	Tlista q = lista;
	int i = 0,band=0;
	while(q!=NULL)
	{
		if(q->nro==valor){
			cout<<endl<<"Encontrado en pocision "<<i <<endl;
			band=1;
		}
		q = q->sgte;
		i++;
	}
	 if(band==0){
	 	cout<<"\n\n Numero no encontrado!"<<endl;
	 }
}
void inserPosicion(Tlista &lista,int valor){
	Tlista q = lista;
	int i = 0,band=0;
	while(q!=NULL)
	{
		if(q->nro==valor){
			cout<<"Ingrese el nuevo dato: ";
			cin>>q->nro;
			band=1;
		}
		q = q->sgte;
		i++;
	}
	 if(band==0){
	 	cout<<"\n\n Numero no encontrado!"<<endl;
	 }
}
void eliminarLista(Tlista &lista,int valor){
	Tlista q = lista;
	int i = 0,band=0;
	nodo *an = new nodo();
	an=NULL;
	cout<<"Ingrese el numero a borrar: ";
	cin>>i;
	if(q!=NULL){
	while(q!=NULL && band !=0)
	{
		if(q->nro==i){
			if(q == lista){
				q=q->sgte;
			}
			else if(q == ult){
				an->sgte = NULL;
				ult=an;
			}
			else{
				an->sgte = q->sgte;
			}
			cout<<"\n Dato eliminado";
			band=1;
		}
		an = q;
		q = q->sgte;
		i++;
	}
	 if(band==0){
	 	cout<<"\n\n Numero no encontrado!"<<endl;
	 }
}
int main(){
	Tlista lista=NULL;
	int _dato;
	int op;
	do{
		cout<<"\t.MENU\n";
		cout<<"1. Insertar Elementos lista al inicio\n";
		cout<<"2. Insertar al final de la lista\n";
		cout<<"3. Insertar en cualquier posicion\n";
		cout<<"4. Inserte el numero a borrar\n";
		cout<<"5. Modificar la lista\n";
		count<<"6. Buscar numero\n";
		cout<<"7. Mostrar elementos\n";
		cout<<"8. Salir\n";
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Numero a insertar: "; cin>>_dato;
				insertarInicio(lista,_dato);
				cout<<endl<<endl;
			break;
			case 2: 
				cout<<"\n Numero a insertar: "; 
				cin>>_dato;
				inserFinal(lista,_dato);
				cout<<endl<<endl;
			break;
			case 3:
				cout<<"\n Numero a insertar: "
				cin>>_dato;
				inserPosicion(lista,_dato);
			break;
			case 4;
				cout<<"Inserte numero a borrar: ";
				cin>>_dato;
				eliminarLista(lista,_dato);
			break;
			case 5:
				cout<<"Inserte numero a modificar: ";
				cin>>_dato;
				inserPosicion(lista,_dato);
			break;
			case 6:
				cout<<"Insertar numero a buscar";
				cin>>_dato;
				buscarElemento(lista,_dato);
			break;
			case 7:
				mosLista(lista);
			break;
		}
		sytem("pause");
	}while(op !=8);	
	return 0;
}
