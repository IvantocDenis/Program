/*Ați fost puși să administrați baza de date a clădirilor care se află pe o anumită așezare. Va trebui să adăugați clădiri în acea bază de date și să adăugați locuitori, angajați și șefi în acele clădiri, iar la sfârșit o statistică acestor date.


Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Person cu următoarele specificații:
- clasa trebuie să conțină 3 atribute publice numite mName, mAge și mSalary, primul fiind un std::string, reprezentând numele persoanei, al doilea fiind un număr întreg fără semn pe 16 biți, reprezentând vârsta persoanei, iar al treilea este un număr fracționar pe dublă precizie, reprezentând salariul persoanei.
- clasa trebuie să conțină un constructor public cu 0 parametri, care să inițializeze vârsta și salariul cu 0, iar numele cu un string gol.
- clasa trebuie să conțină un constructor public cu 3 parametri, care să inițializeze cele 3 atribute cu valorile specificate.
- clasa trebuie să conțină operatorul == public. Acesta va primește un parametru de tip Person, ca referință constantă. De asemenea, operatorul trebuie să fie declarat const qualified. Tipul de dată returnat este bool, acest operator întorcând true dacă cele 2 persoane au numele, vârsta și salariul egale.
- clasa trebuie să conțină operatorul < public. Acesta va primește un parametru de tip Person, ca referință constantă. De asemenea, operatorul trebuie să fie declarat const qualified. Tipul de dată returnat este bool, acest operator întorcând true dacă numele persoanei curente este mai mic din punct de vedere lexicografic decât numele persoanei date ca parametru.

Să se creeze o clasă cu numele Building cu următoarele specificații:
- clasa trebuie să conțină 5 atribute protected numite mBuildingName, mType, mCoordinator, mEmployees și mCitizens. Primul atribut este un std::string, care reprezintă numele clădirii. Al doilea atribut este un std::string, care reprezintă tipul clădirii. Al treilea atribut este o persoană de tip Person, care este un coordonator (o persoană importantă) a unei clădiri. Al patrulea atribut este un std::vector de obiecte de tip Person, care reprezintă persoanele angajate într-o anumită clădire. Al cincelea atribut este un std::vector de obiecte de tip Person, care reprezintă persoanele dintr-o casă, bloc sau primărie.
- clasa trebuie să conțină un constructor public cu 2 parametri, care să inițializeze numele clădirii și tipul clădirii cu valorile specificate.
- clasa trebuie să conțină 2 metode publice pur virtuale numite add și remove. Acestea nu trebuie să întoarcă nimic, iar ca parametru vor primi un obiect de tip Person, ca referință constantă.
- clasa trebuie să conțină operatorul pur virtual +. Acesta trebuie să întoarcă un pointer la un obiect de tip Building, iar ca parametru va primi un obiect de tip Person, ca referință constantă.
- clasa trebuie să conțină cei 2 operatorii virtuali -, adică operatorul binar și cel unar. Ambii operatori trebuie să întoarcă un pointer la un obiect de tip Building. Operatorul unar - nu trebuie să ia niciun parametru, iar operatorul binar - trebuie să ia ca parametru un obiect de tip Person, ca referință constantă. Ambele metode trebuie să returneze în această clasă nullptr.
- clasa trebuie să conțină 2 metode publice fără niciun parametru numite getBuildingName și getType, care trebuie să întoarcă valorile celor 2 atribute. Ambele metode trebuie să fie declarate const qualified.
- clasa trebuie să conțină 2 metode publice fără niciun parametru numite getEmployeesSize și getCitizensSize, care trebuie să întoarcă dimensiunile celor 2 vectori, tipul de dată returnat fiind număr întreg fără semn pe 16 biți. Ambele metode trebuie să fie declarate const qualified.
- clasa trebuie să conțină 2 metode publice numite getEmployee și getCitizen, care trebuie să întoarcă o persoană de la un anumit index din cei 2 vectori. Aceste metode trebuie să returneze un obiect de tip Person, iar ca parametru vor primi indexul persoanei, de tip număr întreg pe 16 biți. Ambele metode trebuie să fie declarate const qualified.
- clasa trebuie să conțină o metodă publică fără niciun parametru numită getCoordinator, care trebuie să întoarcă coordonatorul. Metoda trebuie să fie declarată const qualified.

Să se creeze o clasă cu numele CityHall cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Building. Această clasă reprezintă clădirea primăriei. Aceasta are un primar și persoane care muncesc în acea primărie.
- clasa trebuie să conțină un constructor public cu 1 parametru, acesta fiind numele primăriei. Acest constructor va folosi constructorul clasei Building pentru a inițializa numele clădirii cu parametrul dat constructorului, iar tipul clădirii va fi inițializat cu string-ul "CityHall". Pe lângă aceasta, constructorul va trebui să dea clear la vectorul mCitizens (angajații primăriei) și să inițializeze atributul mCoordinator (primarul) cu un obiect gol de tip Person.
- clasa trebuie să implementeze operatorii virtuali + și unarul - din clasa de bază. Operatorul + va inițializa primarul cu persoana dată ca parametru, doar dacă nu există un primar (mCoordinator este un obiect gol de tip Person). În caz contrar, primarul va rămâne cel vechi, iar operatorul + nu va schimba primarul. Operatorul unar - va șterge primarul, adică va inițializa atribitul mCoordinator cu un obiect gol de tip Person. Ambii operatori vor returna un pointer la obiectul curent modificat.
- clasa trebuie să implementeze metodele virtuale add și remove din clasa de bază. Acestea vor adăuga persoana dată ca parametru în vectorul mCitizens, respectiv va șterge persoana dată ca parametru din vectorul mCitizens. Se va considera că la ștergere există acea persoană în vector.

Să se creeze o clasă cu numele Hospital cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Building. Această clasă reprezintă clădirea spitalului. Aceasta are doctori și pacienți.
- clasa trebuie să conțină un constructor public cu 1 parametru, acesta fiind numele spitalului. Acest constructor va folosi constructorul clasei Building pentru a inițializa numele clădirii cu parametrul dat constructorului, iar tipul clădirii va fi inițializat cu string-ul "Hospital". Pe lângă aceasta, constructorul va trebui să dea clear la vectorii mCitizens (pacienții spitalului) și mEmployees (doctorii din spital).
- clasa trebuie să implementeze operatorii virtuali + și binarul - din clasa de bază. Operatorul + va adăuga doctorul în vectorul mEmployees. Operatorul binar - va șterge doctorul dat ca parametru. Ambii operatori vor returna un pointer la obiectul curent modificat. Se consideră că doctorul care se va șterge există în spital.
- clasa trebuie să implementeze metodele virtuale add și remove din clasa de bază. Acestea vor adăuga pacientul în vectorul mCitizens, respectiv va șterge pacientul dat ca parametru din vectorul mCitizens. Se va considera că la ștergere există acel pacient în vector.

Să se creeze o clasă cu numele PoliceStation cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Building. Această clasă reprezintă clădirea poliției. Aceasta are polițiști și persoane arestate.
- clasa trebuie să conțină un constructor public cu 1 parametru, acesta fiind numele secției de poliție. Acest constructor va folosi constructorul clasei Building pentru a inițializa numele clădirii cu parametrul dat constructorului, iar tipul clădirii va fi inițializat cu string-ul "PoliceStation". Pe lângă aceasta, constructorul va trebui să dea clear la vectorii mCitizens (persoanele arestate) și mEmployees (polițiștii din secție).
- clasa trebuie să implementeze operatorii virtuali + și binarul - din clasa de bază. Operatorul + va adăuga polițistul în vectorul mEmployees. Operatorul binar - va șterge polițistul dat ca parametru. Ambii operatori vor returna un pointer la obiectul curent modificat. Se consideră că polițistul care se va șterge există în secția de poliție.
- clasa trebuie să implementeze metodele virtuale add și remove din clasa de bază. Acestea vor adăuga persoana arestată în vectorul mCitizens, respectiv va șterge persoana arestată dată ca parametru din vectorul mCitizens. Se va considera că la ștergere există acea persoană în vector.

Să se creeze o clasă cu numele House cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Building. Această clasă reprezintă o casă. Aceasta are un proprietar și locuitorii din acea casă. Se va considera că și proprietarul locuiește în acea casă.
- clasa trebuie să conțină un atribut privat numit mMaxNumber de tip număr întreg fără semn pe 16 biți. Acesta reprezintă numărul maxim de persoane care pot locui în acea casă. Se va număra și proprietarul printre acestea.
- clasa trebuie să conțină un constructor public cu 2 parametri, acestea fiind numele casei și numărul maxim de persoane care pot locui în acea casă. Acest constructor va folosi constructorul clasei Building pentru a inițializa numele clădirii cu parametrul dat constructorului, tipul clădirii va fi inițializat cu string-ul "House", iar atributul mMaxNumber va fi inițializat cu cel dat ca parametru constructorului. Pe lângă aceasta, constructorul va trebui să dea clear la vectorul mCitizens (locuitorii casei) și să inițializeze atributul mCoordinator (proprietarul) cu un obiect gol de tip Person.
- clasa trebuie să implementeze operatorii virtuali + și unarul - din clasa de bază. Operatorul + va inițializa proprietarul cu persoana dată ca parametru, doar dacă nu există un proprietar (mCoordinator este un obiect gol de tip Person). În caz contrar, proprietarul va rămâne cel vechi, iar operatorul + nu va schimba proprietarul. Operatorul unar - va șterge proprietarul, adică va inițializa atribitul mCoordinator cu un obiect gol de tip Person. Ambii operatori vor returna un pointer la obiectul curent modificat.
- clasa trebuie să implementeze metodele virtuale add și remove din clasa de bază. Metoda add va adăuga locuitorul dat ca parametru în vectorul mCitizens, doar dacă există loc în acea casă. În caz contrar, nu se va adăuga persoana respectivă, adică metoda nu va avea efect. Metoda remove va șterge locuitorul dat ca parametru din vectorul mCitizens, doar dacă acel locuitor are vârsta mai mare sau egală cu 18, în caz contrar nu se va șterge, adică metoda nu va avea efect. Se va considera că la ștergere există acea persoană în vector.

Să se creeze o clasă cu numele Block cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Building. Această clasă reprezintă un bloc. Aceasta are un administrator și locuitorii din acel bloc. Se va considera că și adminstratorul locuiește în acel bloc.
- clasa trebuie să conțină 1 atribut privat numit mMaxNumberPerFloor de tip număr întreg fără semn pe 16 biți. Acesta reprezintă numărul maxim de persoane care pot locui pe un etaj în acel bloc.
- clasa trebuie să conțină un constructor public cu 3 parametri, acestea fiind numele blocului, numărul de etaje al blocului (număr întreg fără semn pe 16 biți) și numărul maxim de persoane care pot locui pe un etaj în bloc. Acest constructor va folosi constructorul clasei Building pentru a inițializa numele clădirii cu parametrul dat constructorului, tipul clădirii va fi inițializat cu string-ul "Block", iar atributul mMaxNumberPerFloor va fi inițializat cu cel dat ca parametru constructorului. Pe lângă aceasta, constructorul va trebui să dea clear la vectorul mCitizens (locuitorii blocului) și să inițializeze atributul mCoordinator (adminstratorul) cu un obiect gol de tip Person. După ce se va face clear la vectorul mCitizens, se vor aloca numar_etaje * mMaxNumberPerFloor locații în acest vector, toate aceste locații conținând obiecte goale de tip Person.
- clasa trebuie să implementeze operatorii virtuali + și unarul - din clasa de bază. Operatorul + va inițializa administratorul cu persoana dată ca parametru, doar dacă nu există un administrator (mCoordinator este un obiect gol de tip Person). În caz contrar, administratorul va rămâne cel vechi, iar operatorul + nu va schimba administratorul. Operatorul unar - va șterge adminstratorul, adică va inițializa atribitul mCoordinator cu un obiect gol de tip Person. Ambii operatori vor returna un pointer la obiectul curent modificat.
- clasa trebuie să implementeze metodele virtuale add și remove din clasa de bază. Metoda add va adăuga locuitorul dat ca parametru în vectorul mCitizens, doar dacă există loc în acel bloc. În caz contrar, nu se va adăuga persoana respectivă, adică metoda nu va avea efect. Adăugarea locuitorului se va face pe prima poziție din vector în care nu există un locuitor (pe acea poziție avem un obiect gol de tip Person). Metoda remove va șterge locuitorul dat ca parametru din vectorul mCitizens, doar dacă acel locuitor are vârsta mai mare sau egală cu 18, în caz contrar nu se va șterge, adică metoda nu va avea efect. Deosebirea acestei ștergeri față de ștergerea din clasa House este că nu se va șterge se tot obiectul din vector, ci ștergerea se referă că pe poziția persoanei se va pune din nou un obiect gol de tip Person. Astfel, vectorul mCitizens va trebui să aibă mereu numar_etaje * mMaxNumberPerFloor locații disponibile. Se va considera că la ștergere există acea persoană în vector. 

Cerință
Dându-se de la tastatură comenzi de adăugare/ștergere a unor clădiri sau a unor persoane cu statuturi diferite în acele clădiri, să se facă o statistică asupra anumitor atribute ce țin de anumite tipuri de persoane sau de tipul așezării, așa cum este spus în secțiunea de Date de ieșire. Ceea ce se vrea este crearea unei așezări, care poate fi sat, oraș sau capitală, depinzând de numărul și de tipul clădirilor care se dau de la tastatură să fie adăugate în acea așezare.
Date de intrare 
Se vor linii până la EOF. O linie este alcătuită din următoarele elemente:
- primul cuvânt va fi acțiunea pe care vreți să o faceți. Această comandă poate fi add sau remove. Dacă această comandă este add atunci se va face o adăugare, iar dacă este remove se va face o ștergere.
- al doilea cuvânt este ceea ce vreți să adăugați sau să ștergeți. Clădirile doar se pot adăuga, nu și șterge, iar persoanele suportă ambele comenzi.
        - dacă vrem să adăugăm o clădire, acest al doilea cuvânt poate fi unul din cuvintele CityHall, Hospital, PoliceStation, House sau Block.
        - dacă vrem să adăugăm sau să ștergem o anumită persoană dintr-o clădire, acest al doilea cuvânt poate fi unul din cuvintele coordinator, employee sau citizen. Pentru fiecare tip de clădire, aceste cuvinte au semnificații diferite astfel:
                - coordinator pot fi doar primarii, proprietarii de case și administratorii de bloc.
                - employee pot fi doar doctorii și polițiștii.
                - citizen pot fi doar angajații primăriei, pacienții spitalului, persoanele arestate, locuitorii caselor și locuitorii blocurilor.
- în continuare există următoarele posibilități:
        - dacă vrem să adăugăm o clădire, următoarea dată de intrare va fi numele clădirii. Pentru case (House) după numele clădirii se va citi și numărul maxim de persoane care pot locui în acea casă, iar pentru blocuri (Block) după numele clădirii se vor citi numărul de etaje al blocului și număr maxim de persoane per etaj. De exemplu, linia add Hospital ReginaMaria trebuie să adauge un spital numit ReginaMaria.
        - dacă vrem să adăugăm o persoană, următoarele date de la intrare vor fi numele persoanei, vârsta persoanei, salariul persoanei și numele clădirii în care vrem să adăugăm acea persoană. Este clar acest lucru depinde de al doilea parametru. Ca exemplu, dacă avem o clădire numită ReginaMaria, aceasta fiind un spital, iar linia noastră este add citizen Andrei 23 222.22 ReginaMaria, este clar că Andrei va fi pacient al spitalului deoarece el are statutul de citizen, iar citizenii unui spital sunt pacienții, doctorii fiind considerați employee. Dacă voiam ca persoana să fie doctor în spital, am fi avut o linie de genul add employee Andrei 23 222.22 ReginaMaria.
        - dacă vrem să ștergem o persoană, următoarele date de la intrare vor fi numele persoanei și numele clădirii. Vor considera că nu există citizen sau employee cu același nume în aceeași instituție. Exemplificând în continuare, dacă avem o linie de forma remove citizen Andrei ReginaMaria se va elimina pacientul Andrei din spitalul ReginaMaria.

Date de ieșire 
Ieșirea va consta dintr-o statistică a așezării create folosind aceste clădirii astfel:

Type: tipul așezării. Acest tip poate fi "Village", "Town" sau "Capital". Pentru a știi ce tip de așezare avem, se vor va trebui:
          Capital: CityHall >=3, Hospital >= 2, PoliceStation >= 3, House >= 8, Block >= 4
          City: CityHall >=2, Hospital >= 1, PoliceStation >= 2, House >= 4, Block >= 1
          Village: Orice altceva în afară de condițiile de mai sus
Number of patients in hospitals: numărul total de pacienți din toate spitalele
Average salary for doctors: salariul mediu al tuturor doctorilor din toate spitalele
Average salary for cops: salariul mediu al tuturor polițiștilor din toate secțiile de poliție
Average salary for mayors: salariul mediu al tuturor primarilor din toate primăriile
Average salary for city hall employees: salariul mediu al tuturor angajaților din toate primăriile
Average age of busted in police stations: vârsta medie a tuturor persoanelor arestate din toate secțiile de poliție
Următoarele linii trebuie să fie de forma:
Number of people in House numele_casei: numărul de persoane din acea casă, inclusiv proprietarul dacă există
Number of people in Block numele_blocului: numărul de persoane din acel bloc, inclusiv administratorul dacă există
Liniile de mai sus vor fi puse în ordinea în care au fost date casele și blocurile de la tastatură.
Administrators of house and block: numele persoanelor care sunt și administratoare de bloc și proprietare de casă. Dacă nu există nicio persoană se va pune cuvântul Nobody.

Pentru a vedea exemple, puteți rula bateria de teste să vă uitați la exemple de date de intrare și la expected output.


--------------------------------
*/
#include <iostream>
#include <string>
#include <vector>
class Person{
public:
    std::string mName;
    uint16_t mAge;
    double mSalary;
    Person(){
        mAge=0;
        mSalary=0;
        mName="";
    }
    Person(std::string Name,uint16_t Age,double Salary){
        mName=Name;
        mAge=Age;
        mSalary=Salary;
    }
    bool operator==(const Person & A)const{
        bool f=0;
        if (mName==A.mName && mSalary==A.mSalary && mAge==A.mAge) f=1;
        return f;
    }
    bool operator<(const Person & A)const {
        return A.mName>mName;
    }

};

class Building {
protected:
    std::string mBuildingName;
    std::string mType;
    Person mCoordinator;
    std::vector<Person> mEmployees;
    std::vector<Person> mCitizens;
    friend class CityHall;
    friend class Hospital;
    friend class PoliceStation;
public:
    Building(std::string BuildingName,std::string Type){
        mBuildingName=BuildingName;
        mType=Type;
    }
    virtual void add(const Person & A)=0;
    virtual void remove(const Person & A)=0;
    virtual Building* operator+(const Person & A )=0;
    virtual Building* operator-(){return nullptr;}
    virtual Building* operator-(const Person & A ){return nullptr;}

    std::string getBuildingName() const {
        return mBuildingName;
    }

    std::string getType() const {
        return mType;
    }

    Person getCoordinator() const {
        return mCoordinator;
    }

    uint16_t getEmployeesSize() const {
        return mEmployees.size();
    }

    uint16_t getCitizensSize() const {
        return mCitizens.size();
    }

    Person getEmployee(uint16_t n) const {
        return mEmployees[n];
    }

    Person getCitizen(uint16_t n) const {
        return mCitizens[n];
    }
};
class CityHall: public Building{
public:
    CityHall(std::string numeP) : Building(numeP, "CityHall") {
        mCitizens.clear();
        mCoordinator=Person();
        // mEmployees.clear();
    }
    Building* operator+(const Person & A )override{
        if (mCoordinator==Person()) mCoordinator=A;
        return this;
    }
    Building* operator-()override{
        mCoordinator=Person();
        return this;
    }
    void add(const Person & A)override{
        mCitizens.push_back(A);
    }
    void remove(const Person & A)override{
        for (int i=0;i<mCitizens.size();i++){
            if (mCitizens[i].mName==A.mName) {
                mCitizens.erase(mCitizens.begin()+i);
                break;
            }
        }
    }

};
class Hospital:public Building{
public:
    Hospital(std::string numeP) : Building(numeP, "Hospital") {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building* operator+(const Person & A )override{
        mEmployees.push_back(A);
        return this;
    }
    Building* operator-(const Person & A )override{
        for (int i=0;i<mEmployees.size();i++){
            if (mEmployees[i].mName==A.mName) {
                mEmployees.erase(mEmployees.begin()+i);
                break;
            }
        }
        return this;
    }
    void add(const Person & A)override{
        mCitizens.push_back(A);
    }
    void remove(const Person & A)override{
        for (int i=0;i<mCitizens.size();i++){
            if (mCitizens[i].mName==A.mName) {
                mCitizens.erase(mCitizens.begin()+i);
                break;
            }
        }
    }
};
class PoliceStation: public Building{
public:
    PoliceStation(std::string numeP) : Building(numeP, "PoliceStation") {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building* operator+(const Person & A )override{
        mEmployees.push_back(A);
        return this;
    }
    Building* operator-(const Person & A )override{
        for (int i=0;i<mEmployees.size();i++){
            if (mEmployees[i].mName==A.mName) {
                mEmployees.erase(mEmployees.begin()+i);
                break;
            }
        }
        return this;
    }
    void add(const Person & A)override{
        mCitizens.push_back(A);
    }
    void remove(const Person & A)override{
        for (int i=0;i<mCitizens.size();i++){
            if (mCitizens[i].mName==A.mName) {
                mCitizens.erase(mCitizens.begin()+i);
                break;
            }
        }
    }
};
class House : public Building{
    uint16_t mMaxNumber;
public:
    House(std::string numeP,uint16_t Max) : Building(numeP, "House"){
        mMaxNumber=Max;
        mCitizens.clear();
        mCoordinator=Person();
    }
    Building* operator+(const Person & A )override{
        if (mCoordinator==Person()) mCoordinator=A;
        return this;
    }
    Building* operator-()override{
        mCoordinator=Person();
        return this;
    }
    void add(const Person & A)override{
        if (mCitizens.size()<mMaxNumber) mCitizens.push_back(A);
    }
    void remove(const Person & A)override{
        for (int i=0;i<mCitizens.size();i++){
            if (mCitizens[i].mName==A.mName) {
                if(mCitizens[i].mAge>=18){
                    mCitizens.erase(mCitizens.begin()+i);
                break;}
            }
        }
    }

};
class Block: public Building{
    uint16_t mMaxNumberPerFloor;
public:
    Block(std::string numeP,uint16_t Max,uint16_t maxFloor):Building(numeP,"Block"){
        mMaxNumberPerFloor=maxFloor;
        mCitizens.clear();
        mCoordinator=Person();
        for (int i=0;i<Max*maxFloor;i++){
            mCitizens.push_back(Person());
        }
    }
    Building* operator+(const Person & A )override{
        if (mCoordinator==Person()) mCoordinator=A;
        return this;
    }
    Building* operator-()override{
        mCoordinator=Person();
        return this;
    }
    void add(const Person & A)override{
        for (int i=0;i<mCitizens.size();i++){
            if (mCitizens[i]==Person()){
                mCitizens[i]=A;
                break;
            }
        }

    }
    void remove(const Person & A)override{
        for (int i=0;i<mCitizens.size();i++){
            if (mCitizens[i].mName==A.mName) {
                if(mCitizens[i].mAge>=18){
                    mCitizens[i]=Person();
                }
            }
        }
    }
};
int main() {
    std::vector <Building*> x;
//Building t;
    std::string a,b,c;
    std::string nume,nCladire;
    double sal;
    uint16_t m,mFloor,varsta;
    while (std::cin>>a){
        if (a=="add"){
            std::cin>>b;


            if (b=="CityHall") {
                std::cin>>c;
                x.push_back(new CityHall(c));
            }
            if (b=="PoliceStation") {
                std::cin>>c;
                x.push_back(new PoliceStation(c));
            }
            if (b=="Hospital") {
                std::cin>>c;
                x.push_back(new Hospital(c));
            }
            if (b=="House") {
                std::cin>>c;
                std::cin>>m;
                x.push_back(new House(c,m-1));
            }
            if (b=="Block"){
                std::cin>>c;
                std::cin>>m>>mFloor;
                x.push_back(new Block(c,m,mFloor));
            }
            if (b=="coordinator"){
                std::cin >>nume>>varsta>>sal>>nCladire;
                for (int i=0;i<x.size();i++){
                    if (nCladire==x[i]->getBuildingName()){
                        x[i]->operator+(Person(nume,varsta,sal));
                    }
                }
            }
            if (b=="employee"){
                std::cin >>nume>>varsta>>sal>>nCladire;
                for (int i=0;i<x.size();i++){
                    if (nCladire==x[i]->getBuildingName()){
                        x[i]->operator+(Person(nume,varsta,sal));
                    }
                }
            }
            if (b=="citizen"){
                std::cin >>nume>>varsta>>sal>>nCladire;
                for (int i=0;i<x.size();i++){
                    if (nCladire==x[i]->getBuildingName()){
                        x[i]->add(Person(nume,varsta,sal));
                    }
                }
            }
        }
        if (a=="remove") {
            std::cin >> b;
            std::cin >> nume >> nCladire;
            if (b == "coordinator") {
                // std::cin >> nume >> nCladire;
                for (int i=0;i<x.size();i++){
                    if (nCladire==x[i]->getBuildingName()){
                        x[i]->operator-();
                    }
                }
            }
            if (b == "employee") {
                //std::cin >> nume >> varsta >> sal >> nCladire;
                for (int i=0;i<x.size();i++){
                    if (nCladire==x[i]->getBuildingName()){
                        x[i]->operator-(Person(nume,0,0));
                    }
                }
            }
            if (b == "citizen") {
                // std::cin >> nume >> varsta >> sal >> nCladire;
                for (int i=0;i<x.size();i++){
                    if (nCladire==x[i]->getBuildingName()){
                        x[i]->remove(Person(nume,0,0));
                    }
                }

            }
        }

    }
    int city=0,hos=0,pacientiS=0,pol=0,hous=0,bloc=0;
    double nrAngajatiSp=0,nrPolitisti=0,nrAngajatiPr=0,nrAres=0,nrPrim=0;
    double sumD=0,sumP=0,sumPr=0,sumAngajatiPr=0,anAres=0;
    for(int i=0;i<x.size();i++){
        if (x[i]->getType()=="CityHall"){
            city++;
            Person P=x[i]->getCoordinator();
            if(P==Person()){}else nrPrim++;
            sumPr=sumPr+P.mSalary;
            nrAngajatiPr=nrAngajatiPr+x[i]->getCitizensSize();
            for (uint16_t j=0;j<x[i]->getCitizensSize();j++){
                Person P;
                P=x[i]->getCitizen(j);
                sumAngajatiPr=sumAngajatiPr+P.mSalary;
            }
        }
        if (x[i]->getType()=="Hospital"){
            hos++;
            pacientiS=pacientiS+x[i]->getCitizensSize();
            nrAngajatiSp=nrAngajatiSp+x[i]->getEmployeesSize();
            for (uint16_t j=0;j<x[i]->getEmployeesSize();j++){
                Person P;
                P=x[i]->getEmployee(j);
                sumD=sumD+P.mSalary;
            }
        }
        if (x[i]->getType()=="PoliceStation"){
            pol++;
            nrPolitisti=nrPolitisti+x[i]->getEmployeesSize();
            for (uint16_t j=0;j<x[i]->getEmployeesSize();j++){
                Person P;
                P=x[i]->getEmployee(j);
                sumP=sumP+P.mSalary;
            }
            nrAres=nrAres+x[i]->getCitizensSize();
            for (uint16_t j=0;j<x[i]->getCitizensSize();j++){
                Person P;
                P=x[i]->getCitizen(j);
                anAres=anAres+P.mAge;
            }
        }
        if (x[i]->getType()=="House")hous++;
        if (x[i]->getType()=="Block")bloc++;
    }
    std::string t;
    if (city>=3&&hos>=2&&pol>=3&&hous>=8&&bloc>=4)t="Capital";else
    if (city>=2&&hos>=1&&pol>=2&&hous>=4&&bloc>=1)t="Town";else t="Village";
    std::cout<<"Type: "<<t<<std::endl;

    std::cout<<"Number of patients in hospitals: "<< pacientiS<<std::endl;
    double Asd=sumD/nrAngajatiSp;
    if(sumD==0)Asd=0;
    std::cout<<"Average salary for doctors: "<<Asd <<std::endl;
    double Asc=sumP/nrPolitisti;
    if(sumP==0)Asc=0;
    std::cout<<"Average salary for cops: "<< Asc<<std::endl;
    double Asm=sumPr/nrPrim;
    if(sumPr==0)Asm=0;
    std::cout<<"Average salary for mayors: "<< Asm<<std::endl;
    double Asche=sumAngajatiPr/nrAngajatiPr;
    if (sumAngajatiPr==0)Asche=0;
    std::cout<<"Average salary for city hall employees: "<<Asche<<std::endl;
    double Aa=anAres/nrAres;
    if (anAres==0)Aa=0;
    std::cout<<"Average age of busted in police stations: "<< Aa<<std::endl;
    for (int i =0;i<x.size();i++){
        if (x[i]->getType()=="House") {
            int tot=x[i]->getCitizensSize();
            Person t=x[i]->getCoordinator();
            if ( t==Person()){}else tot++;
            std::cout<<"Number of people in House "<<x[i]->getBuildingName()<<": "<<tot<<std::endl;
        }
        if (x[i]->getType()=="Block") {
            int tot=0;
            for (int j=0;j<x[i]->getCitizensSize();j++){
                if (x[i]->getCitizen(j)==Person()){}else tot++;
            }
            Person t=x[i]->getCoordinator();
            if ( t==Person()){} else {tot++;}
            std::cout<<"Number of people in Block "<<x[i]->getBuildingName()<<": "<<tot<<std::endl;
        }
    }
//std::string numeBH="Nobady";
    bool f=0;
    std::cout<<"Administrators of house and block:";
    for (int i=0;i<x.size();i++){
        if (x[i]->getType()=="House")
            for (int j=0;j<x.size();j++){
                if (x[j]->getType()=="Block"){
                    if(x[i]->getCoordinator().mName==Person().mName){}else
                    if (x[i]->getCoordinator().mName==x[j]->getCoordinator().mName){ f=1;std::cout<<" "<<x[j]->getCoordinator().mName;}
                }

            }

    }

    if (!f){std::cout<<" Nobody";}
    return 0;
}