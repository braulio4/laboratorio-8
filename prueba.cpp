//ejercicios desarrollados 1 a la 7 

#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Forma{
	private:
		string color;
		float ob_punto;
		float ob_punto2;
		string nombre;
	public:
		Forma(string,float,float,string);
		virtual void imprimir();
		void obtener_cambiar_color();
		void mover_forma();
};

Forma::Forma(string _color,float _ob_punto,float _ob_punto2,string _nombre){
	color=_color;
	ob_punto=_ob_punto;
	nombre=_nombre;
	ob_punto2=_ob_punto2;
}

void Forma::imprimir(){
	cout<<"nombre: "<<nombre<<endl;
	cout<<"color: "<<color<<endl;
	cout<<"objeto punto x: "<<ob_punto<<" y: "<<ob_punto2<<endl;
}

void Forma::obtener_cambiar_color(){
	cout<<"ingrese nuevo color: "; cin>>color;
	cout<<"cambio de color: "<<color<<endl;
}

void Forma::mover_forma(){
	cout<<"x se movio a: "; cin>>ob_punto;
	cout<<"y se movio a: "; cin>>ob_punto2;
	cout<<"la forma se movio"<<"x: "<<ob_punto<<" y: "<<ob_punto2<<endl;
}
class Rectangulo:public Forma{
	private:
		int lmenor;
		int lmayor;
	public:
		Rectangulo(string,float,float,string,int,int);
		void imprimir();
		void area();
		void perimetro();
		void cambiar_rectangulo(float);
};

Rectangulo::Rectangulo(string _color,float _ob_punto,float _ob_punto2,string _nombre,int _lmenor,int _lmayor):Forma(_color,_ob_punto,_ob_punto2,_nombre){
	lmenor=_lmenor;
	lmayor=_lmayor;
}

void Rectangulo::imprimir(){
	Forma::imprimir();
	cout<<"lado mayor: "<<lmayor<<endl;
	cout<<"lado menor: "<<lmenor<<endl;
}

void Rectangulo::area(){
	int ar;
	ar=lmayor*lmenor;
	cout<<"el area es: "<<ar<<endl;
}

void Rectangulo::perimetro(){
	int peri;
	peri=(2*lmenor)+(2*lmayor);
	cout<<"el perimetro es: "<<peri<<endl;
}

void Rectangulo::cambiar_rectangulo(float fact){
	if(fact==2){
		cout<<"su tamaño se duplico"<<endl;
	}
	else if(fact==0.5){
		cout<<"su tamaño se reducira a la mitad"<<endl;
	}
	else{
		cout<<"ingreso un numero invalido"<<endl;
	}
}

class Elipse:public Forma{
	private:
		int rmayor;
		int rmenor;
	public:
		Elipse(string,float,float,string,int,int);
		void area();
		void imprimir();
};

Elipse::Elipse(string _color,float _ob_punto,float _ob_punto2,string _nombre,int _rmenor,int _rmayor):Forma(_color,_ob_punto,_ob_punto2,_nombre){
	rmenor=_rmenor;
	rmayor=_rmayor;
}

void Elipse::imprimir(){
	Forma::imprimir();
	cout<<"el radio menor es: "<<rmenor<<endl;
	cout<<"el radio mayor es: "<<rmayor<<endl;
}

void Elipse::area(){
	float ar;
	ar=3.14*(rmayor*rmenor);
	cout<<"el area del elipse es: "<<ar<<endl;
}

class Cuadrado:public Rectangulo{
	public:
		Cuadrado(string _color,float _ob_punto,float _ob_punto2,string _nombre,int _lmenor,int _lmayor):Rectangulo(_color,_ob_punto,_ob_punto2,_nombre,_lmenor,_lmayor){cout<<endl<<"cuadrado heredado de rectangulo"<<endl;
		}
		
};



class Circulo:public Elipse{
	public:
		Circulo(string _color,float _ob_punto,float _ob_punto2,string _nombre,int _rmenor,int _rmayor):Elipse(_color,_ob_punto,_ob_punto2,_nombre,_rmenor,_rmayor){cout<<endl<<"circulo heredado de elipse"<<endl;
		}
};

int main(){
	Rectangulo p1=Rectangulo("verde",10,5,"rectangulo",5,10);
	p1.imprimir();
	cout<<endl;
	p1.perimetro();
	cout<<endl;
	p1.area();
	cout<<endl;
	p1.cambiar_rectangulo(2);
	Elipse p2=Elipse("rojo",20,15,"elipse",2,3);
	p2.imprimir();
	cout<<endl;
	p2.area();
	cout<<endl;
	Cuadrado cuadro=Cuadrado("azul",16,-15,"cuadrado",5,10);
	cuadro.imprimir();
	cout<<endl;
	Elipse circle=Elipse("gris",-25,30,"circulo",4,5);
	circle.imprimir();
	string nombres[4]={"Rectangulo base","Cuadrado base","Elipse base","Circulo base"};
	Forma *Formas[4];
	char*ptrNombre1=&(nombres[0])[0];
	Formas[0]=new Rectangulo("Rojo",10,2,ptrNombre1,15,18); 
	char*ptrNombre2=&(nombres[1])[0];
	Formas[1]=new Cuadrado("Amarillo",13,42,ptrNombre2,20,10);
	char*ptrNombre3=&(nombres[2])[0];
	Formas[2]=new Elipse("Azul",3,0,ptrNombre3,32,14);
	char*ptrNombre4=&(nombres[3])[0];
	Formas[3]=new Circulo("Verde",13,9,ptrNombre4,10,2);	
	getch();
	return 0;
}