#include <iostream>
#include <string>

using namespace std;
class Hash{


    public:

    void hash(string txt);

    private:

    struct Nod{
        char litera;

        Nod* next=NULL;

    };
    typedef struct Nod *pointer;
    pointer vec[20]={NULL};

    int HP(char a);
    void make();
};

int main()
{
    string text;
    Hash has;
    cout<<"Text: "; cin>>text;

    has.hash(text);



}


void Hash::hash(string text){
    pointer el,aux=new Nod;

    int a=text.length(),index,i;

     for(i=0;i<a;i++){
        aux=new Nod;
        cout<<"Letter: "<<text[i]<<endl;
        aux->litera=text[i];

        index=HP(text[i]);

        if(vec[index]==NULL){
        vec[index]=aux;

        }
        else{
            el=new Nod;
            aux=vec[index];

            while(aux->next!=NULL){
                aux=aux->next;
            }
                el->litera=text[i];
                aux->next=el;




        }
        //cout<<vec[index]->litera<<endl;

     }


     for(i=0;i<20;i++){
        //aux=vec[i];

        if(vec[i]!=NULL){
            cout<<"vec["<<i<<"]= "<<vec[i]->litera<<endl;
            el=vec[i];
            while(el->next!=NULL){
            el=el->next;
            cout<<"Collision: "<<el->litera<<endl;
            }

        }
    }


}
int Hash::HP(char a){
    int n;

    n=a%13;
    cout<<"Hash Letter="<<n<<endl;
    cout<<"------------"<<endl;
    return n;
}

