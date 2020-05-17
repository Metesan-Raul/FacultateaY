#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <vector>

using namespace std;
static int numarexamene=0;
///template <typename nr_matricol,typename nr_examene,typename examene>

class Examen{
protected:
public: string nume;
        double nota;

    Examen(string,double);
    Examen();
    ~Examen();
    virtual void citire (istream &in);
    virtual void afisare(ostream &out);
    virtual operator=(const Examen&);
    friend istream& operator>>(istream&, Examen&);
    friend ostream& operator<<(ostream&, Examen&);
};

Examen::Examen(string nume,double nota){

    numarexamene++;
    this->nume=nume;
    this->nota=nota;
}

Examen::Examen(){

    numarexamene++;
    this->nume="";
    this->nota=0;
}

Examen::~Examen(){
numarexamene--;
nume="";
nota=0;
}

istream& operator>>(istream& in, Examen &e){
    e.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Examen &e){
    e.afisare(out);
    return out;
}


void Examen::citire(istream& in){
    numarexamene++;
    cout << "Introdu numele examenului: ";
    in >> nume;
    cout << "Introdu nota examenului: ";
    in >> nota;
    try{
        if(nota<=0)
            throw 1;
    }
    catch(int i){
    cout << "Valorile trebuie sa fie STRICT POZITIVE \n";
    throw 1;
    }
}
void Examen::afisare(ostream& out){
}

Examen::operator=(const Examen& e){
    nume=e.nume;
    nota=e.nota;

}

class Partial:public Examen{
    public: double notaoral;
            Partial();
            Partial(double notaoral);
            ~Partial();
            void citire(istream&);
            void afisare(ostream&);

            friend istream& operator>>(istream&, Partial&);
            friend ostream& operator<<(ostream&, Partial&);

};

void Partial::citire(istream& in)
{
    Examen::citire(in);

}

void Partial::afisare(ostream& out)
{
    Examen::afisare(out);
}


void menu_output()
{
    cout<<"\nFACULTATEA Y\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1.Adauga un nou examen ";
    cout<<"\n";
    cout<<"2.Afla cate examene avem ";
    cout<<"\n";
    cout<<"3.Arata toti elevii ";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}
void menu()
{   Examen examen;
    int option;
    option=0;
    int n=0;
    int id_examen=0;
    vector<Examen> elev;

    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Introduceti numarul de obiecte citite: ";
            cin>>n;
            if (n>0)
            {

                for(int i=0;i<n;i++)
                   {   /// cin>>elev[i];
                        cin>>examen;
                        cout<<"\n";
                        cout<<"--------------------------\n";
                   }
            }
            else
                cout<<"Numarul introdus trebuie sa fie pozitiv.\n";
        }
        if (option==3)
        {
        unordered_map<int,string> umap;
        for(auto& elevi: umap){
            cout<<elevi.first<<" "<<elevi.second<<endl;
        }
        }


        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
           if (option==2)
        {
            cout<<numarexamene;
        }
        if (option<0||option>3)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }
    while(option!=0);
}
int main()
{
menu();
    return 0;
}
