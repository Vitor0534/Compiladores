#include <QCoreApplication>
#include <vector>
#include <iostream>
using namespace std;

class lista
{
private:
    vector<string> *vetor;

public:
    lista();

    void setToken(string t){vetor->push_back(t);}
    //void setPosition(int pos,string t){vetor->insert(pos,t);}

    string buscaToken(string t);
    string getPosition(int pos){return vetor->at(pos);}

};

lista::lista()
{
    vetor=new vector<string>();
}

string lista::buscaToken(string t)
{
    int i=0;
    while(i<vetor->size())
    {
        if(vetor->at(i)==t)
            return vetor->at(i);
        i++;
   }

    return "-50";
}




int main()
{


    lista *list=new lista();

    list->setToken("1");

    cout<<"inserido"<<endl;

    list->setToken("2");

     cout<<"inserido2"<<endl;


    if(list->buscaToken("2")!="-50")
        cout<<"busaca 2:  "<<"2"<<endl;

    cout<<"getPosition:   "<<list->getPosition(0)<<endl;



}
