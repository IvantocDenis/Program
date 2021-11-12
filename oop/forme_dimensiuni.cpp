/*~80%) În aplicații de grafică computerizată, este necesară recunoașterea de forme și aproximarea dimensiunii lor.

Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Point cu următoarele specificații:
- clasa trebuie să conțină 2 atribute private numite x și y, ambele numere fractionare in dublă precizie;
- clasa trebuie sa contina un constructor cu 0 parametri. Acesta va initializa pe x si pe y cu 0;
- clasa trebuie sa contina un constructor cu 2 parametri, ce va initializa pe x si pe y cu cei 2 parametri dati;
- clasa trebuie sa contina metodele getX si getY, declarate const qualified, ce vor returna cele 2 coordonate ale punctului;
- clasa trebuie sa contina metodele setX si setY ce vor seta cele 2 coordonate;
- clasa trebuie sa supraincarce operatorul -, declarat const qualified, ce va lua ca parametru un const Point&, si sa returneze un Point ce are drept coordonate valoarea absoluta obtinuta prin scaderea din punctul curent, punctul dat ca parametru


Să se creeze o clasă cu numele Shape cu următoarele specificații:
- clasa trebuie să conțină 3 atribute protected, mFirst, mSecond, mName, unde mFirst si mSecond sunt 2 campuri de tip Point, iar mName este un std::string;
- clasa trebuie sa contina un constructor cu 0 parametri. Acesta va initializa pe mFirst si pe mSecond cu valorile (0,0);
- clasa trebuie sa contina un constructor cu 2 parametri, de tip Point. Acesta va initializa pe mFirst cu primul punct, iar pe mSecond cu cel de-al doilea punct;
- clasa trebuie sa contina metodele getFirst si getSecond, declarate const qualified, ce vor returna cele 2 puncte;
- clasa trebuie sa contina metodele setFirst si setSecond, ce vor seta cele 2 puncte;
- clasa trebuie să conțină metoda getName, declarată const qualified, ce va returna numele formei.
- clasa trebuie sa contina metoda setName, care seteaza numele formei;
- clasa trebuie sa fie abstracta si sa contina metodele pur virtuale getPerimeter si getArea, declarate const qualified, ce vor intoarce aria și perimetrul ca numere fractionare in dubla precizie;


Să se creeze o clasă cu numele Quadrilateral cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină un constructor cu 0 parametri, ce initializeaza punctele din clasa de bază cu valorile (0,0), iar mName va fi initializat cu valoarea "Unknown";
- clasa trebuie sa contina un constructor cu 3 parametri, ce initializeaza cele 2 puncte din clasa de bază cu cele 2 puncte date ca parametri și numele formei cu numele dat ca parametru;
- metoda getLength, declatată const qualified, ce calculeaza lungimea pe axa Ox dintre cele 2 puncte;
- metoda getWidth, declarată const qulaified, ce calculeaza lungimea pe axa Oy dintre cele 2 puncte;
Indicatie: pentru scrierea metodelor getLength si getWidth este recomandata folosirea operatorului supraincarcat din clasa Point;
- implementarea metodelor virtuale din clasa de bază;

Să se creeze o clasă cu numele Circle cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină un atribut private numit mRadius, de tip fracționar in dubla precizie;
- clasa trebuie să conțină un constructor public cu 0 parametri, care să inițializeze punctele din clasa mama cu valorile (0,0), campul mRadius cu 0, iar mName va fi initializat cu valoarea "Unknown";
- clasa trebuie sa contina un constructor cu 2 parametri, unul dintre ele sa fie un Point, centrul cercului, iar cel de-al doilea parametru sa fie de tip double, reprezentand raza cercului. Acest constructor va inițializa atributul mFirst cu centrul cercului, iar atributul mSecond cu un punct gol, care nu va fi folosit pentru un cerc. De asemenea, atributul mName va fi inițializat cu valoarea "cerc".
- clasa trebuie sa implementeze cele doua metode virtuale din clasa de bază;
- clasa trebuie sa contina metoda setRadius() care seteaza valoarea razei cercului;
- clasa trebuie sa contina metoda getRadius, declarată const qualified, care seteaza valoarea razei cercului;

Dându-se o listă de forme de tip cerc, pătrat sau dreptunghi împreună cu mărimile de definiție (pentru cerc, coordonata centrului și raza iar pentru pătrat și dreptunghi coordonatele punctelor din stânga sus și dreapta jos), să se ordoneze acestea crescător în funcție de arie. 

Datele de intrare sunt date astfel: pe prima linie se află numărul de forme n, urmat de două valori min, max, fracționare, toate separate prin spațiu Pe următoarele n linii se află definițiile fomelor în următorul format: numele formei (cerc, patrat sau dreptunghi), urmat de mărimile caracteristice (pentru cerc, coordonata centrului și raza iar pentru pătrat și dreptunghi coordonatele punctelor din stânga sus și dreapta jos). n este în intervalul [1, 500], coordonatele sunt în intevalul [-1000, 1000] și razele în (0; 1000]. min și max sunt valori de tip floating point pozitive. cu observația că min <= max.

NB: Efectuati calculele in dubla precizie si afisati cu 6 zecimale exacte.

Exemplu de date de intrare:

5 120.7 150.4
cerc 4.7 3.5 12
cerc 20 21 15
patrat 0 0 10 10
dreptunghi 40 23 45 30.5
cerc 10 21 17


La ieșire se cer formele ordonate crescător în funcție de arie. Pentru fiecare formă se cere tipul ei, urmată de arie, urmată de perimetru.

Exemplu de ieșire (pentru intrarea de mai sus):

dreptunghi 37.500000 25.000000
patrat 100.000000 40.000000
cerc 452.389342 75.398224
cerc 706.858347 94.247780
cerc 907.920277 106.814150

Explicație: dreptunghiul din listă are coordonatele (40, 23) pentru vârful din stânga sus și (45, 30.5) pentru cel din dreapta jos (x crește la dreapta și y crește în jos). Astfel, laturile sunt de dimensiunea 45 - 40 = 5 și 30.5 - 23 = 7.5, deci aria
    este de 5 * 7.5 = 37.5, perimetrul este de 2 * (5 + 7.5) = 25. ș.a.m.d


(~10%) Dacă n este în afara intervalului de definiție, sau oricare din coordonate sau raze sunt în afara domeniului de  definiție, sau min > max, se va afișa “Valoare de intrare invalida” (fără ghilimele) și programul se va încheia. 

(~10%) Dacă există forme care au aceeași arie, atunci ele se vor ordona în funcție de perimetru.

Observații:
Toate liniile de ieșire se termină obligatoriu cu un caracter newline (\n).
Două numere floating point f1 și f2 se consideră egale, dacă |1 - f1/f2| < 0.0001


--------------------------------
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
class Point {
    double x,y;
public:
    Point (){
        x=0;
        y=0;
    }
    Point (double mx,double my){
        x=mx;
        y=my;
    }

    double getX() const  {
        return x;
    }

    void setX(double x) {
        Point::x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        Point::y = y;
    }
    Point  operator-(const Point & A)const{
        return  Point(A.x-x,A.y-y);
    }

};
class Shape {
protected:
    Point mFirst,mSecond;
    std::string mName;
    friend class Circle;
    friend class Quadrilateral;
public:
    Shape(){
        mFirst=Point(0,0);
        mSecond=Point(0,0);
    }
    Shape(Point A,Point B){
        mFirst=A;
        mSecond=B;
    }

    Point getFirst() const {
        return mFirst;
    }

    void setFirst(Point mFirst) {
        Shape::mFirst = mFirst;
    }

    Point getSecond() const {
        return mSecond;
    }

    void setSecond(Point mSecond) {
        Shape::mSecond = mSecond;
    }

    std::string getName() const {
        return mName;
    }

    void setName( std::string mName) {
        Shape::mName = mName;
    }
    virtual  double getPerimeter ()const=0;
    virtual    double getArea()const=0;
};
class Quadrilateral : public Shape{
public:
    Quadrilateral(){
        mFirst=Point(0,0);
        mSecond=Point(0,0);
        mName="Unknown";
    }
    Quadrilateral(Point A,Point B,std::string S){
        mFirst=A;
        mSecond=B;
        mName=S;
    }
     double getLength() const{
        return abs(mSecond.getX() - mFirst.getX());
    }
     double getWidth()const{
        return abs(mSecond.getY()-mFirst.getY()) ;
    }
     double getPerimeter ()const{
        return 2*double(fabs(mFirst.getY()-mSecond.getY())+fabs(mSecond.getX()-mFirst.getX()));
    }
     double getArea()const{
        return fabs(mFirst.getY()-mSecond.getY())*fabs(mSecond.getX()-mFirst.getX());
    }

};
class Circle : public Shape{
    double mRadius;
public:
    Circle(){
        mFirst=Point(0,0);
        mSecond=Point(0,0);
        mName="Unknown";
        mRadius=0;
    }
    Circle(Point A,double r){
        mFirst=A;
        mSecond=Point();
        mRadius=r;
        mName="cerc";
    }


    double getRadius() const {
        return mRadius;
    }

    void setRadius(double mRadius) {
        Circle::mRadius = mRadius;
    }
     double getPerimeter  ()const{
        return 2*M_PI*mRadius;
    }
     double getArea()const{
        return M_PI*mRadius*mRadius;
    }
};
bool compp( const Shape *a, const Shape *b){

    if (a->getArea()==b->getArea()) return a->getPerimeter()<b->getPerimeter(); else
        return a->getArea()<b->getArea();

}

int main() {
    std::vector <Shape*> x;
    float min ,max;
    int n ;

    double a,b,c,d;
    std::string s;
    std::cin >>n>>min>>max;
    if (min>max) {
        std::cout<<"Valoare de intrare invalida"<<std::endl;
    return 0;
    }
    if ((n<0)||(n>501)) {
    std::cout<<"Valoare de intrare invalida"<<std::endl;
    return 0;
        
    }
    for (int i=0;i<n;i++){
        std::cin>>s;
        if (s=="cerc") {
            std::cin >>a>>b>>c;
            
            Point A(a,b);
        x.push_back(new Circle(A,c));
        }
        if (s=="patrat"||s=="dreptunghi"){
            std::cin >>a>>b>>c>>d;
            if ((a<-1000)||(a>1000)){
                std::cout<<"Valoare de intrare invalida"<<std::endl;
                return 0;
            }
            Point A(a,b);
            Point B(c,d);
            x.push_back(new Quadrilateral(A,B,s));
        }
    }
   std::sort(x.begin(),x.end(),compp);
    for(int i=0;i<n;i++){
        std::cout<<std::fixed<<std::setprecision(6)<<x[i]->getName()<<" "<<x[i]->getArea()<<" "<<x[i]->getPerimeter()<<std::endl;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}