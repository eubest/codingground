#include <iostream>

using namespace std;

struct nod { int info; nod *ad;};
nod *v,*sf;
struct nod1 {int info; nod1 *adu;nod1 *adi;};
nod1 *v1,*sf1;
struct nod2 {int info;nod2 *ad;};
nod2 *v2;

class llsi_cozi
{
    public:

        void adaugare(nod *&v, nod *&sf, int val)
        {
        nod *c;
            if(v==0)
            {
                v=new nod;
                v->info=val;
                v->ad=0;
                sf=v;
            }
            else
            {
                c=new nod;
                c->info=val;
                c->ad=0;
                sf->ad=c;
                sf=c;
            }
        }
        void afisare(nod *v)
        {
            nod *c;
            c=v;
            while(c!=0)
            {
                cout<<c->info<<" ";
                c=c->ad;
            }
        }
        void stergere(nod *v,int val)
        {
            nod *c,*c1;
            c=v;
            c1=v->ad;
            while(c1->info!=val&&c1->ad!=0)
            {
                c=c->ad;
                c1=c1->ad;
            }
            c->ad=c1->ad;
        }
        void inserare ( nod *v,int poz,int val)
        {
            nod *c,*c1,*c2;
            c2=new nod;
            c2->info=val;
            c2->ad=0;
            c=v;
            c1->ad=0;
            c=v;
            c1=v->ad;
            int k=0;
            while (k<poz)
            {
                c=c->ad;
                c1=c1->ad;
                k++;
            }
                c2->ad=c->ad;
                c->ad=c2;
        }
        void inserare_poz_cun(nod *&v,int val)
        {
            nod *c;
            c=new nod;
            c->info=val;
            c->ad=v;
            v=c;
        }
        void eliminare_cozi(nod *&v)
        {
            nod *c;
            c = v;
            v = v -> ad;
            delete c;
        }
};
class lldi
{

    public:
        void creare(nod1 *&v1,nod1 *&sf1, int val)
        {
            nod1 *c;
            if(v1==0)
            {
                v1= new nod1;
                v1->info=val;
                v1->adu=0;
                v1->adi=0;
                sf1=v1;
            }
            else
            {
                c=new nod1;
                c->info=val;
                c->adu=0;
                c->adi=sf1;
                sf1->adu=c;
                sf1=c;
            }
        }
        void afisarei(nod1 *sf1)
        {
            nod1 *c;
            c=sf1;
            while(c!=0)
            {
                cout<<c->info << " ";
                c=c->adi;
            }
        }
        void afisareu(nod1 *v1)
        {
            nod1 *c;
            c=v1;
            while(c!=0)
            {
                cout<<c->info << " ";
                c=c->adu;
            }
        }
};
class stive
{
    public:
        void push(nod2 *&v2,int val)
        {
            if(v2==0)
            {
                v2=new nod2;
                v2->info=val;
                v2->ad=0;
            }
            else
            {
                nod2 *c;
                c=new nod2;
                c->info=val;
                c->ad=v2;
                v2=c;
            }
        }
        void pop(nod2 *&v2)
        {
            nod2 *c;
            c=v2;
            v2=v2->ad;
            delete c;
        }
        void afisare(nod2 *v2)
        {
            nod2 *c;
            c=v2;
            while(c!=0)
            {
                cout<<c->info<<" ";
                c=c->ad;
            }
        }
};

int main()
{
    int i;
    int k;

    llsi_cozi llsi_c;
    lldi lldi;
    stive stive;


    while(cin)
    {
        int operatie = 0;
        cout << "1.Creare si afisare a unei liste liniare simplu inlantuite.\n"
             << "2.Stergerea unui nod dintr-o lista liniara simplu inlantuita.\n"
             << "3.Adaugarea unui nod pe prima pozitie a listei liniare simplu inlantuite.\n"
             << "4.Crearea si afisare a unei liste liniare dublu inlantuite.\n"
             << "5.Construire nod cu nod a unei stive.\n"
             << "6.Stergerea unui element dintr-o stiva.\n"
             << "7.Construirea unei cozi si un exemplu al principiului FIFO.\n"
             << endl;
        cin >> operatie;
        switch(operatie)
        {
        case 1:
            cout << endl;
            for(i=1; i <= 10; i++)
                llsi_c.adaugare(v,sf,i);
            llsi_c.afisare(v);
            cout << endl << endl;
            break;
        case 2:
            cout << endl;
            cout << "Care este nodul pe care doriti sa-l stergeti?";
            cin >> k;
            cout << endl;
            llsi_c.stergere(v,k);
            cout << "Noua lista va fi:\n";
            llsi_c.afisare(v);
            cout << endl << endl;
            break;
        case 3:
            cout << endl;
            cout << "Ce valoare doriti sa aiba noul nod?\n";
            cin >> k;
            cout << "Noua lista va fi:\n";
            llsi_c.inserare_poz_cun(v,k);
            llsi_c.afisare(v);
            cout << endl << endl;
            break;
        case 4:
            cout << endl;
            for(i = 1; i <= 10; i++)
                lldi.creare(v1,sf1,i);
            lldi.afisarei(sf1);
            cout << endl;
            lldi.afisareu(v1);
            cout << endl << endl;
            break;
        case 5:
            cout << endl;
            for(i = 1; i <= 10; i++)
                stive.push(v2,i);
            stive.afisare(v2);
            cout<< endl << endl;
            break;
        case 6:
            cout << endl;
            stive.pop(v2);
            cout << "Noua stiva va fi:\n";
            stive.afisare(v2);
            cout << endl << endl;
            break;
        case 7:
            cout << endl;
            llsi_c.eliminare_cozi(v);
            llsi_c.afisare(v);
            cout << endl << endl;
            break;
        default:
            cout << "Nu ati ales o operatie corecta!\n\n";
            break;
        }
    }
}
