/*Este săptămâna formelor geometrice la grădiniţă. Astăzi copiii au învăţat să deseneze pătrate, dreptunghiuri şi cercuri. Bineînţeles că apare competiţia: cine poate desena cea mai mare formă geometrică? Doamna educatoare este arbitrul şi trebuie să stabilească cine este câştigătorul. O puteţi ajuta?

Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Shape cu următoarele specificații:
- clasa trebuie să conțină 2 atribute protected numite mShape și mArea, primul de tip string, iar al doilea număr fracționar pe simplă precizie;
- clasa trebuie să fie abstractă. Abstractizarea se va face prin crearea a 2 metode publice pur virtual numite print și calculateArea. Aceste metode nu vor returna nimic și nu primesc niciun parametru;
- clasa trebuie să conțină o metodă publică fără niciun parametru numite getArea. Aceasta trebuie să întoarcă valoarea atributului mArea. Tipul de dată returnat al metodei trebuie să îl deduceți voi.

Să se creeze o clasă cu numele Square cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină un atribut private numit mLength, de tip fracționar pe simplă precizie;
- clasa trebuie să conțină un constructor public cu un singur parametru care să inițializeze atributul mLength cu valoarea specificată. De asemena, se va seta valoarea atributul mShape cu textul "patrat";
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, iar metoda calculateArea va calcula aria figurii, iar rezultatul se va stoca în atributul mArea.

Să se creeze o clasă cu numele Rectangle cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină 2 atribute private numite mLength și mWidth, ambele de tip fracționar pe simplă precizie;
- clasa trebuie să conțină un constructor public cu 2 parametrii care să inițializeze atributele mLength și mWidth cu valoarea specificată. De asemena, se va seta valoarea atributul mShape cu textul "dreptunghi";
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, iar metoda calculateArea va calcula aria figurii, iar rezultatul se va stoca în atributul mArea.

Să se creeze o clasă cu numele Circle cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină un atribut private numit mRadius, de tip fracționar pe simplă precizie;
- clasa trebuie să conțină un constructor public cu un singur parametru care să inițializeze atributul mRadius cu valoarea specificată. De asemena, se va seta valoarea atributul mShape cu textul "cerc";
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, iar metoda calculateArea va calcula aria figurii, iar rezultatul se va stoca în atributul mArea.

ATENȚIE! Cele 3 clase trebuie să aibă definite și un constructor cu 0 parametrii care să inițializeze toate atributele cu  valoarea 0, iar atributul mShape cu textul "nedefinit".


Cerinţă
Stabiliţi ierarhia formelor geometrice, ordonându-le după suprafață, de la cea mai mare la cea mai mică.

Date de intrare
Se vor citi de la tastatură (fluxul stdin) următoarele date:
o valoare întreagă N reprezentând numărul de forme geometrice intrate în competiţie, urmată de caracterul newline (tasta Enter); 
N linii, fiecare linie conţinând numele formei geometrice („patrat”, „dreptunghi”, „cerc”) şi informaţiile despre aceasta (lungimea laturii pentru pătrate, lungimile laturilor pentru dreptunghiuri, raza cercului pentru cercuri), în următorul format: 
    patrat <L>
    cerc <R>
    dreptunghi <L1> <L2>
Entităţile componente ale liniilor sunt separate printr-un spaţiu, ca în exemplul dat în final. Fiecare dintre cele N linii reprezentând rezultate este urmată de caracterul newline (tasta Enter).

Date de ieşire
Programul va afişa pe ecran (stream-ul standard de ieşire) informaţiile despre forme,  în acelaşi format în care au fost introduse şi datele de intrare ordonate după arie, de la cea mai mare la cea mai mică.

Restricţii şi precizări
Numărul de forme geometrice, N, este un număr întreg între 1 şi 100. 
Denumirea formelor geometrice va fi („patrat”, „dreptunghi” sau „cerc”). 
Lungimile laturilor şi razele sunt numere reale, între 0 şi 1000, cu exact 2 zecimale. 
Suprafaţa formelor geometrice este: Sp atrat =L2,S dreptu nghi =L1⋅L2, Scerc =πR2 Spatrat=L2,Sdreptunghi=L1⋅L2,Scerc=πR2
Exemplu
Intrare 

6
patrat 2.10
dreptunghi 1.20 7.90
cerc 3.11
patrat 4.40
dreptunghi 9.10 0.40
patrat 1.50
Ieșire

cerc 3.11
patrat 4.40
dreptunghi 1.20 7.90
patrat 2.10
dreptunghi 9.10 0.40
patrat 1.50

--------------------------
 */
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iomanip>
class Shape {
protected:
    std::string mShape;
    float mArea;
public:
    virtual void print()=0;
    virtual void calculateArea()=0;

    Shape():mShape("nedefinit"),mArea(0){
    }
    const std::string &getShape() const {
        return mShape;
    }

    void setShape(const std::string &mShape) {
        Shape::mShape = mShape;
    }

    float getArea() {
        return mArea;
    }

    void setArea(float mArea) {
        Shape::mArea = mArea;
    }


};
class Square:public Shape {
    float mLength;
public:
    Square(){
        mShape="nedefinit";
        mArea=0;
        mLength=0;
    }
    Square(float length):mLength(length){
        mShape="patrat";
    }

    void print() override{
        std::cout<<std::fixed<<std::setprecision(2)<<mShape<<" "<<mLength<<std::endl;
    }
    void calculateArea()override{
        mArea=mLength*mLength;
    }

    friend class Shape;
};
class Rectangle:public Shape{
    float mLength,mWidth;
public:
    Rectangle(){
        mShape="nedefinit";
        mArea=0;
        mLength=0;
        mWidth=0;
    }
    Rectangle(float length,float width){
        mLength=length;
        mWidth=width;
        mShape="dreptunghi";
    }
    void print() override{
        std::cout<<std::fixed<<std::setprecision(2)<<mShape<<" "<<mLength<<" "<<mWidth<<std::endl;
    }
    void calculateArea()override{
        mArea=mLength*mWidth;
    }

    friend class Shape;
};
class Circle:public Shape{
    float mRadius;
public:
    Circle(){
        mShape="nedefinit";
        mArea=0;
        mRadius=0;
    }
    Circle(float radius):mRadius(radius){
        mShape="cerc";
    }

    void print() override{
        std::cout<<std::fixed<<std::setprecision(2)<<mShape<<" "<<mRadius<<std::endl;
    }
    void calculateArea()override{
        mArea=M_PI*mRadius*mRadius;
    }

    friend class Shape;
};
bool compp( Shape* S,Shape* SS){
    return S->getArea()>SS->getArea();
}
int main() {
    std::vector<Shape*> o;
    int n;
    float l,w;
    std::string s;
    std::cin>>n;
    for (int i=0;i<n;i++){
        std::cin>>s;
        if (s=="patrat"){
            std::cin>>l;
            o.push_back(new Square(l));
        }
        if(s=="cerc"){
            std::cin>>l;
            o.push_back(new Circle(l));
        }
        if(s=="dreptunghi"){
            std::cin>>w>>l;
            o.push_back(new Rectangle(w,l));
        }
    }

    for (auto i:o) {
        i->calculateArea();
    }
    std::sort(o.begin(),o.end(),compp);
        for (auto i:o){
    i->print();
    }

    return 0;
}
