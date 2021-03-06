/*Se dau de la tastatură un număr necunoscut de mare de perchi de două, trei sau patru numere fracționare reprezentabile cu dublă precizie (până la EOF). Aceste perechi reprezintă numere imaginare de forma a + bi, a+bi+cj sau a+bi+cj+dk. Părțile imaginare din numere au propritetățile i2=-1, j2=-1, k2=-1, i*j=j*i=0, j*k=k*j=0, i*k=k*i=0. Astfel, se pot înmulții numere imaginare, chiar dacă ele sunt de tipuri diferite. Însă, aeastă înmulțire nu este comutativă. Astfel, dacă înmulțim un număr imaginar cu 2 componente cu un număr imaginar cu 3 componente rezultatul va fi un număr imaginar cu 2 componente (a treia componentă nu se ia în calcul), însă dacă înmulțim un număr imaginar cu 3 componente cu un număr imaginar cu 2 componente rezultatul va fi un număr imaginar cu 3 componente. Analog pentru toate celelalte tipuri de înmulțiri.


Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Point cu următoarele specificații:
- clasa trebuie să conțină 2 atribute protected numite mCoordinates și mDistance, primul fiind un std::vector de numere fracționare pe dublă precizie, iar al doilea număr fracționar pe dublă precizie. Observație: Dacă vom folosi clasa Point ca și parametru al unei metode în altă clasă nu vom putea accesa atributul mCoordinates deoarece el este protected. Astfel, va trebui să declarăm cele 3 clase se mai jos ca fiind "prietene" clasei noastre, adică friend class Point2D; și așa mai departe în spațiul protected al clasei Point.
- clasa trebuie să fie abstractă. Abstractizarea se va face prin crearea a 3 metode publice pur virtual numite print, calculateDistance și multiply. Metodele print și calculateDistance nu vor returna nimic și nu primesc niciun parametru. În schimb, metoda multiply va întoarce un pointer la clasa Point și va primi ca parametru un alt pointer la clasa Point.
- clasa trebuie să conțină o metodă publică fără niciun parametru numită getDistance. Aceasta trebuie să întoarcă valoarea atributului mDistance. Tipul de dată returnat al metodei trebuie să îl deduceți voi.

Să se creeze o clasă cu numele Point2D cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Point;
- clasa trebuie să conțină un constructor public cu 2 parametrii care să introducă în vectorul mCoordinates valoarile specificate.
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, metoda calculateDistance va calcula metrica impusă în cerință și rezultatul se va stoca în atributul mDistance, iar metoda multiply va întoarce produsul dintre punctul 2D curent și un punct dat ca parametru, rezultatul pe care îl va întoarce funcția fiind un punct 2D. Dacă după înmulțire se obține un punct cu o dimensiune mai mare, restul dimensiunilor se ignoră.

Să se creeze o clasă cu numele Point3D cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Point;
- clasa trebuie să conțină un constructor public cu 3 parametrii care să introducă în vectorul mCoordinates valoarile specificate.
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, metoda calculateDistance va calcula metrica impusă în cerință și rezultatul se va stoca în atributul mDistance, iar metoda multiply va întoarce produsul dintre punctul 3D curent și un punct dat ca parametru, rezultatul pe care îl va întoarce funcția fiind un punct 3D. Dacă după înmulțire se obține un punct cu o dimensiune mai mare, restul dimensiunilor se ignoră.

Să se creeze o clasă cu numele Point4D cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Point;
- clasa trebuie să conțină un constructor public cu 4 parametrii care să introducă în vectorul mCoordinates valoarile specificate.
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, metoda calculateDistance va calcula metrica impusă în cerință și rezultatul se va stoca în atributul mDistance, iar metoda multiply va întoarce produsul dintre punctul 4D curent și un punct dat ca parametru, rezultatul pe care îl va întoarce funcția fiind un punct 4D. Chiar dacă se înmulțește un punct 4D cu unul 2D, 3D sau 4D, rezultatul va fi tot în 4D.

ATENȚIE! Ultimele 3 clase trebuie să aibă definite și un constructor cu 0 parametrii care să introducă în vectorul mCoordinates coordonatele inițializate cu valoarea 0, iar distanța să aibă și ea de asemenea valoarea 0.

Cerință
Să se calculeze produsul numerelor imaginare luate 2 câte 2 și să se găsească produsul cu distanța maximă. Aveți grijă că înmulțirea nu este comutativă, deci va trebui să faceți toate înmulțirile posibile. Distanța se calculează după următoarele formule:
- 2D: dist = a2+b2−−−−−−√
- 3D: dist = a3+b3+c3−−−−−−−−−−√3
- 4D: dist = a4+b4+c4+d4−−−−−−−−−−−−−−√4
Date de intrare 
Un număr necunoscut de perechi de două, trei sau patru numere fracționare reprezentabile în dublă precizie, numerele dintr-o pereche separate prin punct-și-virgulă, perechile separate prin unul sau mai multe spații.

Date de ieșire 
Se va afișa numărul imaginar obținut prin inmulțirea numerelor imaginare de la intrare luate 2 câte 2 cu distanța maximă. Se vor afișa componentele numărului împreună cu părțile lor imaginare, de forma a±bi, a±bi±cj sau a±bi±cj±dk, în funcție de câte componente are numărul. Pe lângă aceasta, se va afișa și distanța, separată de număr printr-o săgeată de forma " -> ".

Exemplu
Intrare

3;1  -2;-1;1
1;1;3;2
Ieșire

2.000+4.000i+9.000j+6.000k -> 9.495
Explicație

Avem 2 numere imaginare, unul cu 2, unul cu 3 și unul cu 4 componente. Le vom lua 2 câte 2 și vom face înmulțirile.

(-2-i+j)*(3+i) = -5.000-5.000i+3.000j,                    dist = -6.064
(3+i)*(-2-i+j) = -5.000-5.000i,                           dist = 7.071
(1+i+3j+2k)*(3+i) = 2.000+4.000i+9.000j+6.000k,           dist = 9.495
(3+i)*(1+i+3k+2k) = 2.000+4.000i,                         dist = 4.472
(1+i+3j+2k)*(-2-i+j) = -4.000-3.000i-5.000j-4.000k,       dist = 5.908
(-2-i+j)*(1+i+3j+2k) = -4.000-3.000i-5.000j,              dist = -6.000

Așadar, numărul cu distanța maximă este cel de-al treilea, iar la ieșire se va afișa numărul împreună cu distanța.
2.000+4.000i+9.000j+6.000k -> 9.495
-----------------------------
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
//using std::showpos;
class Point {
protected:
    double mDistance;
    std::vector<double> mCoordinates;
    friend class Point2D;
    friend class Point3D;
    friend class Point4D;
public:
    virtual void print()=0;
    virtual void calculateDistance()=0;
    virtual Point* multiply(Point *p)=0;

    double getDistance(){
        return mDistance;
    }
};
class Point2D:public Point{
public:
    Point2D(){
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point2D(double a,double b){
        mCoordinates.push_back(a);
        mCoordinates.push_back(b);
    }
    void print() override {
        //std::cout << showpos;
        std::cout<<std::showpos<<std::fixed<<std::setprecision(3)<<mCoordinates[0]<<mCoordinates[1]<<"i -> "<<mDistance<<std::endl;
    }
    void calculateDistance() override {
        mDistance=sqrt(mCoordinates[0]*mCoordinates[0]+mCoordinates[1]*mCoordinates[1]);
    }

    Point* multiply(Point *p)override{
         
    Point2D *pp=    new Point2D(mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1],mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0]);
    
        return pp;
    }
};
class Point3D:public Point{
public:
    Point3D(){
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point3D(double a,double b,double c){
        mCoordinates.push_back(a);
        mCoordinates.push_back(b);
        mCoordinates.push_back(c);
        mDistance=0;
    }
    void print() override {
        //std::cout << showpos;
        std::cout<<std::showpos<<std::fixed<<std::setprecision(3)<<mCoordinates[0]<<mCoordinates[1]<<"i"<<mCoordinates[2]<<"j -> "<<mDistance<<std::endl;
    }
    void calculateDistance() override {
        mDistance=pow(double(mCoordinates[0]*mCoordinates[0]*mCoordinates[0]+mCoordinates[1]*mCoordinates[1]*mCoordinates[1]+mCoordinates[2]*mCoordinates[2]*mCoordinates[2]),(double)1/3);
    }

    Point* multiply(Point *p)override{
        Point3D * pp= new Point3D(mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1]-mCoordinates[2]*p->mCoordinates[2],mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],mCoordinates[0]*p->mCoordinates[2]+mCoordinates[2]*p->mCoordinates[0]);
    
        return pp;
    }
};
class Point4D:public Point{
public:
    Point4D(){
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point4D(double a,double b,double c,double d){
        mCoordinates.push_back(a);
        mCoordinates.push_back(b);
        mCoordinates.push_back(c);
        mCoordinates.push_back(d);
        mDistance=0;
    }
    void print() override {
        //std::cout << showpos;
        std::cout<<std::showpos<<std::fixed<<std::setprecision(3)<<mCoordinates[0]<<mCoordinates[1]<<"i"<<mCoordinates[2]<<"j"<<mCoordinates[3]<<"k -> "<<mDistance<<std::endl;
    }
    void calculateDistance() override {
        mDistance=pow(abs(mCoordinates[0]*mCoordinates[0]*mCoordinates[0]*mCoordinates[0]+mCoordinates[1]*mCoordinates[1]*mCoordinates[1]*mCoordinates[1]+mCoordinates[2]*mCoordinates[2]*mCoordinates[2]*mCoordinates[2]+mCoordinates[3]*mCoordinates[3]*mCoordinates[3]*mCoordinates[3]),(double)1/4);
    }

    Point* multiply(Point *p)override{
        Point4D *pp;
        if (p->mCoordinates.size()==2){
            pp=  new Point4D(mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1],mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],mCoordinates[2]*p->mCoordinates[0],mCoordinates[3]*p->mCoordinates[0]);
            
        }else
        if(p->mCoordinates.size()==3){
            pp=  new Point4D(mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1]-mCoordinates[2]*p->mCoordinates[2],mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],mCoordinates[0]*p->mCoordinates[2]+mCoordinates[2]*p->mCoordinates[0],mCoordinates[3]*p->mCoordinates[0]);
            
        }else
     pp=  new Point4D(mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1]-mCoordinates[2]*p->mCoordinates[2]-mCoordinates[3]*p->mCoordinates[3],mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],mCoordinates[0]*p->mCoordinates[2]+mCoordinates[2]*p->mCoordinates[0],mCoordinates[0]*p->mCoordinates[3]+mCoordinates[3]*p->mCoordinates[0]);
    
         return pp;
    }
};

int main() {

    std::vector<Point*> p,x;
    char s;
    double a,b,c,d;
    while (std::cin>>a){
        s=getchar();
        std::cin>>b;
        s=getchar();
        if (s==';'){
            std::cin>>c;
            s=getchar();
            if(s==';'){
                std::cin>>d;
                p.push_back(new Point4D(a,b,c,d));
            }else
                p.push_back(new Point3D(a,b,c));
        }else p.push_back(new Point2D(a,b));

    }

    for (auto i:p){
       for (auto j:p){
           if (j!=i){
            x.push_back(i->multiply(j));


           }
       }
    }
    for (auto i:x){
        i->calculateDistance();
    }
    double m=0;
    for (auto i:x){
       if(i->getDistance()>m) m=i->getDistance();
//i->print();
    }
     for (auto i:x){
       if(i->getDistance()==m) i->print();
//i->print();
    }
//std::cout<<m;
    return 0;
}
