#include <iostream>
#include <vector>
using namespace std;





class pos
{
    private:
        string conteudo;
        pos *proximo;

    public:
        pos();
        string getConteudo() { return conteudo;}
        pos *getProximo() {return this->proximo;}

        void setConteudo(string cont) {conteudo=cont;}
        void setProximo(pos *prox){this->proximo=prox;}
};

pos::pos()
{
    conteudo="";
    proximo=NULL;
}

int funcaoHash(string token)
{
    int x=token[0];
    return (x);
}


class hashTable
{
    private:
        vector<pos> vetor[10];
    public:
        hashTable();
        pos * getPos(string token);

        void setPos(pos *pp);

        pos * buscaPos(string pp);



};

hashTable::hashTable()
{
    //this->vetor= new (vector<pos>);
    vetor->resize(500);

    pos aux;
    aux.setConteudo(",");

    for(int i=0;i<500;i++)
        vetor->at(i)=aux;

   // this->vetor= NULL;

}



pos * hashTable::buscaPos(string pp)
{
    pos *aux=new pos();
    aux=&vetor->at(funcaoHash(pp));
    if(aux->getConteudo()==pp)
    {
        return aux;
    }
    else
    {
        if(aux->getConteudo()==",")
            return aux;

        while(aux->getProximo()!=NULL)
        {
            aux=aux->getProximo();
            if(aux->getConteudo()==pp)
                   return aux;
        }
    }
    delete aux;
    return NULL;

}

pos * hashTable:: getPos(string token)
{
//    pos *aux=new pos();
//    aux=&vetor->at(funcaoHash(token));
//    return aux;

    return &vetor->at(funcaoHash(token));
}

void  hashTable::setPos(pos *pp)
{
  cout<<"set poss"<<endl;

    int x=funcaoHash(pp->getConteudo());
    cout<<"passei da hash set pos"<<endl;
    pos *aux = new pos();
    aux=&vetor->at(x);
  cout<<"linha 94 set pos"<<endl;

    if(aux->getConteudo() == ",")
    {
        cout<<"inseri o primeiro : "<<pp->getConteudo()<<endl;
        aux=pp;

        //tem problema nessa insersão, eu não consegui inserir na posição correta
        //não to conseguindo inserir na posição correta mesmo usando a função certa


        //vetor->push_back(&aux);
    }
    else
    {

            while( aux->getProximo()!=NULL)
               {
                    aux=aux->getProximo();
                    if(aux==NULL)
                       {
                        aux->setProximo(pp);
                       }
               }

    }

    delete aux;

}



int main()
{

    hashTable *hash=new hashTable();

    vector<pos> *teste=new vector<pos>();



    pos pp1,pp2,pp3,pp4;

    pp1.setConteudo("while");
    pp2.setConteudo("id1");
    pp3.setConteudo("while2");
    pp4.setConteudo("while3");
   // cout<<"iiruuuu inicio"<<endl;

//    teste->push_back(pp1);
//    teste->push_back(pp2);
//    teste->push_back(pp3);
//    teste->push_back(pp4);

//    int i=0;
//    while(i<teste->size())
//    {
//       cout<<"testererere----: "<<teste->at(i).getConteudo()<<endl;
//       i++;
//    }


    pp1.setProximo(&pp4);

   // cout<<funcaoHash("while")<<endl;

    hash->setPos(&pp1);

    cout<<"passei do primeiro"<<endl;

    hash->setPos(&pp2);
    hash->setPos(&pp3);



   cout<<hash->getPos("while")<<endl;

    cout<<"imprimindo: "<<hash->getPos("id1")->getConteudo()<<endl;

    cout<<"imprimindo: "<<hash->buscaPos("while3")->getConteudo()<<endl;


}



//class pos
//{
//    private:
//        string conteudo;
//        pos *proximo;

//    public:
//        pos();
//        string getConteudo() { return conteudo;}
//        pos *getProximo() {return this->proximo;}

//        void setConteudo(string cont) {conteudo=cont;}
//        void setProximo(pos *prox){this->proximo=prox;}
//};

//pos::pos()
//{
//    conteudo="";
//    proximo=NULL;
//}

//int funcaoHash(string token)
//{
//    int x=token[0];
//    return (x-64);
//}


//class hashTable
//{
//    private:
//        vector<pos> *vetor;
//    public:
//        hashTable();
//        pos * getPos(int posicao);

//        void setPos(pos *pp);

//        pos * buscaPos(string pp);



//};

//hashTable::hashTable()
//{
//    this->vetor= new (vector<pos>);
//    vetor->resize(500);
//    this->vetor= NULL;

//}


//pos * hashTable::buscaPos(string pp)
//{
//    pos *aux=new pos();
//    aux=&vetor->at(funcaoHash(pp));
//    if(aux->getConteudo()==pp)
//    {
//        return aux;
//    }
//    else
//    {
//        while(aux->getProximo()!=NULL)
//        {
//            aux=aux->getProximo();
//            if(aux->getConteudo()==pp)
//                   return aux;
//        }
//    }
//    delete aux;
//    return NULL;

//}

//pos * hashTable:: getPos(int posicao)
//{
//    pos *aux=new pos();
//    aux=&vetor->at(posicao);
//    return aux;
//}

//void  hashTable::setPos(pos *pp)
//{
//  cout<<"set poss"<<endl;

//    int x=funcaoHash(pp->getConteudo());
//    cout<<"passei da hash set pos"<<endl;
//    pos *aux = new pos();
//    aux=&vetor->at(x);
//cout<<"linha 94 set pos"<<endl;
//    if(aux == NULL)
//    {
//        aux=pp;
//       // vetor[x]=aux;
//    }
//    else
//    {

//            while( aux->getProximo()!=NULL)
//               {
//                    aux=aux->getProximo();
//                    if(aux==NULL)
//                       {
//                        aux->setProximo(pp);
//                       }
//               }

//    }

//    delete aux;

//}



//int main()
//{

//    hashTable *hash=new hashTable();

//    pos pp1,pp2,pp3;

//    pp1.setConteudo("while");
//    pp2.setConteudo("id1");
//    pp3.setConteudo("while2");

//   // cout<<"iiruuuu inicio"<<endl;


//   // cout<<funcaoHash("while")<<endl;

//    hash->setPos(&pp1);

//    cout<<"passei do primeiro"<<endl;

//    hash->setPos(&pp2);
//    hash->setPos(&pp3);


//}
