/*In domeniul transmisiunii informatiei, una din cele mai utilizate mecanisme matematice este acela al vectorului n-dimensional. Vom considera n>1.

Cerință
Să se creeze clasa Vector, implementând conținutul acesteia astfel:

Clasa trebuie să conțină 1 atribut privat numite mDim. Acesta este dimensiunea matricii, iar tipul acestuia este număr întreg fără semn pe 16 biți.
Clasa trebuie să conțină 1 atribut privat numit mValues. Acesta este un pointer la numere fracționare pe dublă precizie, iar memoria pentru acest pointer va fi alocată în constructor.
Un constructor ce ia ca argument un numar intreg fără semn ce reprezintă dimensiunea vectorului și să aloce memorie pentru a stoca aceste valori.
Un al doilea constructor care să nu ia niciun argument. Acesta doar va inițializa atributele întregi cu valoarea 0.
Un al treilea constructor, care va fi constructorul de copiere. Acesta primește ca argument un obiect de tip const Vector & și rolul lui este de a copia toate valorile atributelor obiectului dat ca parametru în obiectul curent (this).
Operatorul binar + care sa adune doi vectori, element cu element si sa intoarca valoarea vecotrului suma. In cazul in care dimensiunile vectorilor difera, se va returna un obiect de tip Vector gol.
Operatorul binar * care sa calculeze produsul scalar al vectorilor. Produsul scalar se poate calcula utilizand formula a⃗ =(a1,a2,...,an) b⃗ =(b1,b2,...,bn) a⃗ ⋅b⃗ =∑ai⋅bi. Acest operator va lua ca argument un obiect de tip const Vector&. Operatorul "*" va intoarce un numar fractionar, in dubla precizie. In cazul a 2 vectori cu dimensiuni diferite, se vor ignora acele valori ale vectorului cu dimensiune mai mare ce depasesc dimensiunea vectorului mic.
Operatorul unar ! care calculeaza modulul vectorului.
Operatorul binar ^ care sa calculeze produsul vectorial al celor 2 vectori. Produsul vectorial se poate calcula utilizand formulele urmatoare. In cazul in care dimensiunea este 2, formula de calcul este: a⃗ =(a1,a2) b⃗ =(b1,b2) c⃗ =a⃗ ×b⃗ =(0,0,a1⋅b2−a2⋅b1). In cazul in care dimensiunea este 3, formula de calcul este: a⃗ =(a1,a2,a3)  b⃗ =(b1,b2,b3)  c⃗ =a⃗ ×b⃗ =(a2⋅b3−a3⋅b2,a1⋅b3−a3⋅b1,a1⋅b2−a2⋅b1)  Acest operator va lua ca argument un obiect de tip const Vector&. Operatorul "^" va intoarce un alt vector, reprezentat de vectorul produs vectorial. Produsul vectorial se va calcula DOAR pentru dimensiunile 2 si 3 ale vectorului. In cazul in care dimensiunea depaseste valoarea 3, se va intoarce vectorul ce are pe fiecare pozitie valoarea 1 de dimensiunea respectiva. In cazul in care cei doi vectori au dimensiuni diferite, se va returna vectorul de dimensiune 0.
O metodă de tip getter numită getValue care să ia ca argumente o valoare intreaga fără semn ce reprezintă coordonata valorii din vector ce trebuie întoarsă. Tipul de dată returnat trebuie să îl deduceți voi.
O metodă de tip setter numită setValue care să ia ca argumente un numar intreg fara semn ce reprezinta coordonata valorii din vector ce trebuie întoarsă și o valoare ce trebuie plasată în vector pe poziția respectivă. Tipul de dată returnat trebuie să îl deduceți voi.
Destructorul care să elibereze memoria alocată de constructor.
În funcția main se vor citi 2 vectori (A si B), de dimensiuni oarecare. In cazul in care cei 2 vectori au aceeasi dimensiune si dimensiunea este 2 sau 3, se va calcula produsul vectorial al celor 2 vectori. La produsul acesta se va aduna vectorul A si se va imparti fiecare element din vectorul rezultat la modulul sau. In cazul in care vectorii au dimensiunea 2, rezultatul produsului vectorial va avea dimensiunea 3. Se va crea un vector cu dimensiunea 3, ce are pe primele 2 pozitii valorile din vectorul A, iar pe a 3-a are valoarea 0. Daca cei 2 vectori au dimensiuni diferite sau au dimensiuni egale si dimensiunea mai mare ca 3, se va calcula produsul lor scalar, se va construi un vector ce are dimensiunea vectorului mai mare si are pe fiecare pozitie valoarea produsului scalar al celor 2 vectori. Se va aduna vectorul cu dimensiunea mai mare la acesta, apoi se va imparti fiecare element la modulul vectorului.

Date de intrare
Pe prima linie se află 2 valori întregi fără semn: dim_vector_1 dim_vector_2;
Pe următoarea linie se vor gasi dim_vector_1 valori fractionare, reprezentate in dubla precizie;
Pe urmatoarea linie se vor gasi dim_vector_2 valori fractionare, reprezentate in dubla precizie;
Date de ieșire
Se va afișa un singur număr cu două zecimale reprezentand media aritmetica a elementelor din vectorul calculat.
Observații
Alocați memorie dinamic pentru pentru mValues, folosind operatorul new. Cel mai simplu (și eficient) este să alocați un array de mDim locații de memorie.

--------------------------
*/
#include <iostream>
#include  <cstdint>
#include <math.h>
#include <iomanip>
#include <new> 
class Vector {
    uint16_t mDim ;
    double *mValues;
public:
    Vector (uint16_t n){
        mDim=n;
        mValues = new double [n];
    }
    Vector (){
        mDim=0;
    }
    Vector (const Vector & vec){
        this->mDim=vec.mDim;
        this->mValues=vec.mValues;
    }
    Vector operator+(const Vector & A){
        if(A.mDim!=mDim) return 0;
        Vector C(A.mDim);
        for (int i=0;i<A.mDim;i++){
            C.mValues[i]=mValues[i]+A.mValues[i];
            
        }
        return C;
    }
     double operator*(const Vector & A){
         int n;
        if(A.mDim>mDim) n=mDim; else n=A.mDim;
        double sum=0;
        for (int i=0;i<n;i++){
            sum=sum+A.mValues[i]*mValues[i];
        }
        return sum;
    }
    double operator!(){
        
        double sum=0;
        for (int i=0;i<mDim;i++){
            sum=sum+(abs(mValues[i])*abs(mValues[i]));
        }
        return sqrt(sum);
    }
    Vector operator^(const Vector & A){
       
        if (A.mDim==mDim&&mDim==2){
            Vector B(3);
            double a=A.mValues[0];
            double a1=A.mValues[1];
            B.setValue(0,0);
            B.setValue(1,0);
            B.setValue(2,mValues[0]*a1-mValues[1]*a);
            return B;
        }else
        if (A.mDim==mDim&&mDim==3){
            Vector B(3);
            double a=A.mValues[0];
            double a1=A.mValues[1];
            double a2=A.mValues[2];
            B.setValue(0,mValues[1]*a2-mValues[2]*a1);
            B.setValue(1,mValues[0]*a2-mValues[2]*a);
            B.setValue(2,mValues[0]*a1-mValues[1]*a);
            return B;
        }else
         if (A.mDim==mDim){
             Vector C(mDim);
             for (int i=0;i<mDim;i++){
                 C.mValues[i]=1;
                 
             }
             return C;
         }
       
        return Vector(0);
    }
    
   
    double getValue(uint16_t n){
        return mValues[n];
        }
    void setValue(uint16_t n,double v){
        double a=mValues[n];
        mValues[n]=v;
        
    }
     ~Vector(){
        
    }
    
};
//Vector::~Vector(){}
int main (){
    uint16_t dim_vector_1,dim_vector_2;
    
    double l;
    std::cin>>dim_vector_1;
    std::cin>>dim_vector_2;
    Vector A(dim_vector_1);
    Vector B(dim_vector_2);
   // std::cout<<"."<<dim_vector_2<<".";
    for (int i=0;i<dim_vector_1;i++){
        std::cin>>l;
       A.setValue(i,l);
        
    }
    for (int i=0;i<dim_vector_2;i++){
        std::cin>>l;
       B.setValue(i,l);
    }
   
    if ((dim_vector_1==dim_vector_2)&&(dim_vector_1==2||dim_vector_1==3)&&(dim_vector_2==2||dim_vector_2==3)){
        Vector C(3);
        Vector D(3);
      if(dim_vector_1==2){
         
           C.setValue(0,A.getValue(0));
      C.setValue(1,A.getValue(1));
          D=A^B;
          C=C+D;
          double f=!C;
          //std::cout<<f;
          for (int i=0;i<3;i++){
              double e=C.getValue(i)/f;
              C.setValue(i,e);
          }
           
      }else
       if (dim_vector_1==3){
           
            D=A^B;
          C=C+D;
           double f=!C;
          //std::cout<<f;
          for (int i=0;i<3;i++){
              double e=C.getValue(i)/f;
              C.setValue(i,e);
          }
           
       }
       
        
    
        double sum=0;
        
      for (int i=0;i<3;i++){
        
        sum=sum+C.getValue(i);
        
    }
      std::cout<<std::fixed<<std::setprecision(2)<<sum/3<<std::endl;  
    }else{
        uint16_t l;
        if (dim_vector_1>dim_vector_2){
        l=dim_vector_1;
        }else{
            l=dim_vector_2;
        }
        Vector C(l);
     double t=0;
        t=A*B;
       for (int i=0;i<l;i++){
           C.setValue(i,t);
       }
       Vector D(l);
        if (dim_vector_1>dim_vector_2){D=C+A;}else {D=C+B;}
        double f=!D;
          //std::cout<<t;
          for (int i=0;i<l;i++){
             // std::cout<<C.getValue(i)<<std::endl;
              double e=D.getValue(i)/f;
              D.setValue(i,e);
          }
             double sum=0;
        
      for (int i=0;i<l;i++){
       // std::cout<<D.getValue(i)<<std::endl;
        sum=sum+D.getValue(i);
        
    }
   std::cout<<std::fixed<<std::setprecision(2)<<sum/l<<std::endl;
          
    }
    
    
    
    
    
    
    
}