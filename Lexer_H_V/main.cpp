//*******************************
//HIGOR ALVES FERREIRA
//VITOR ALMEIDA DA SILVA
//******************************

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include<vector>
#include<fstream>


using namespace std;

//Cabecalho das Funcoes sendo utilizadas
vector <string> abreArquivo(string);
void criaArquivo(vector <string>, string);
void nPrimeiraCondicao(string,int);
void nSegundaCondicao(string,int);
string formataProg(string);
void imprime (vector <string>);
vector <string> transformaVector(vector <string>);
vector <string> corrigeErros(vector <string>);
int verificaIdenticador (vector <string>, string);

//Principal
int main()
{
    //Permite escrever a saÃƒÂ­da em portuguÃƒÂªs sem dar erro nos caracteres
    setlocale(LC_ALL,"PORTUGUESE");
    //Vetor que vai ser armazenado as linhas do programa

    vector <string> prog;
    vector <string> newprog;
    vector <string> progTable;
    vector <string> condicional;
    vector <string> identificador;
    vector <string> comparador;
    vector <string> then ;
    vector <string> numerico;
    vector <string> operador;
	vector <string> progLex;
	vector <string> progLexArq;

    string palavra = "";
    string aux;

    // Abre o arquivo com o programa a ser testado
    prog=abreArquivo("progInicial.txt");
    //Grava as linhas do arquivo em uma vector
    for(unsigned j=0; j<prog.size() ; j++){
        //Corrige a formatacao do texto, tirando espacos excessivos, salta linhas e tabulacao
        aux=formataProg(prog.at(j));
        if(aux!="")
            //Grava na Vector a linha corrigida
            newprog.push_back(aux);
    }

    //Corrige os possiveis erros da analise lexica
    newprog = corrigeErros(newprog);

    //Cria o o arquivo com o novo codigo do programa
    criaArquivo(newprog,"progFormatado.txt");


    //Variavel que vai estar com a linha do arquivo
    unsigned i, linha;

    cout<<"\n*********************Programa em analise*********************\n";
    //For que troca de linha
    for(linha = 0; linha<newprog.size();linha++){
        aux=newprog.at(linha);
        cout<<aux<<endl;

        //FOR que muda a coluna na linha
        for(i=0; i<aux.size();i++){

            //IF
            if(aux[unsigned(i)]=='i'){
                if( i+1 <= aux.size()){
                    if(aux[i+1]=='f'){
                        if(aux[i+2]==' '||aux[i+2]=='(' )
                        {
                            //condicional.push_back("[if, ]");
                            progLex.push_back("[if,]");
                            //posiciona o contador i afrente da palavra IF
                            i=i+2;
                        }
                    }
                }
            }
            
			if(aux[i]=='('){
				//operador.push_back("[(,]");
				progLex.push_back("[(,]");
    
            }
            
            //THEN
            if(aux[unsigned(i)]=='t'){
                if( i+4 < aux.size())
                    if(aux[i+1]=='h' && aux[i+2]=='e' && aux[i+3]=='n' && aux[i+4]==' ')
                    {
                        //Achou o Lexema THEN
                        //then.push_back("[then, ]");
                        progLex.push_back("[then,]");
                        //posiciona o contador i afrente da palavra THEN
                        i=i+4;
                    }
            }

            //OPERADOR
            //Para o == foi tratado no comparador
             // O operador ( foi tratado no if

            if(aux[unsigned(i)]==')'){
                progLex.push_back("[), ]");
                //operador.push_back("[), ]");
                i++;
            }



            //Comparador
            if(aux[unsigned(i)]=='='){
                if( i+1 < aux.size()){
                    if(aux[i+1]=='=')
                    {
                        //Achou o Lexema ==
                        //comparador.push_back("[==,]");
                        progLex.push_back("[==,]");
                        //posiciona o contador i afrente do Comparador
                        i=i+2;
                    }else {
                        //operador.push_back("[=, ]");
                        progLex.push_back("[=,]");
                        i++;
                    }
                }
            }


            //NUMERICO
            if(aux[i]>=48 && aux[i] <= 57){
                string num = "";
                while(true){
                    if(aux[i]>=48 && aux[i] <= 57){
                        num=num+aux[i];
                        i++;
                    }else if ((aux[i] != ' ') && (aux[i] != '=') && (aux[i] != '(') && (aux[i] != ')') && (aux.size() != i) && (aux[i] != ';') ){
                        //num= num + '1';
                        //erro.push_back("Erro Lexico, Linha: "+ to_string(linha+1));
                        i++;
                    }else {
                        break;
                    }

                }
                //numerico.push_back("["+num+", ]");
                progLex.push_back("[NUM,"+num+"]");
            }


            //IDENTIFICADOR


            string ident = "";
            if((aux[i]>=65 && aux[i] <= 90)||(aux[i]>=97 && aux[i] <= 122)){
                while(true){
                    if((aux[i]>=65 && aux[i] <= 90)||(aux[i]>=97 && aux[i] <= 122)||(aux[i+1]>=48 && aux[i+1] <= 57)){
                        ident=ident+aux[i];
                        i++;
                    }else if ((aux[i] != ' ') && (aux[i] != '=') && (aux[i] != '(') && (aux[i] != ')') && (aux.size() != i) && (aux[i] != ';') ){
                        //erro.push_back("Erro Lexico, Linha: "+ to_string(linha+1));
                        //ident=ident+'a';
                        i++;
                    }else {
                        break;
                    }
                }
                
                int teste = verificaIdenticador(identificador, ident);
                
                if(teste == -1){
						identificador.push_back(ident);
						teste = verificaIdenticador(identificador, ident);
						progLex.push_back("[ID,"+to_string(teste)+"]");
				}else{
						progLex.push_back("[ID,"+to_string(teste)+"]");
				}
                //verificaIdenticador(identificador, ident);
                

                //progLex.push_back("[ID,"+ident+"]");
            }


        }//Fim do for que analisa a linha do arquivo
        progLex.push_back("\n");
    }//Fim do for que troca de linha


    //Cria Arquivo tabela de erros
    progLexArq = transformaVector(progLex);
    criaArquivo(progLexArq,"progLex.txt");
	cout<<"\n*********";
	imprime(progLexArq);

    //IMPRIME O RESULTADO
    cout<<"\n*********************Resultado da ANALISE LEXICA*********************\n";


    cout<<endl<<endl;
    imprime(progLex);
    cout<<endl<<endl;
    
}
// DO MAIN

//Verifica se o identificador esta na vector
int verificaIdenticador (vector <string> listaIdent, string identificador){
	unsigned a;
    for( a= 0; a<listaIdent.size(); a++){
        
        if(listaIdent.at(a)== identificador  &&  listaIdent.at(a)!= "\n"){
			return a+1;
        }
    }
    return -1;        
}

void imprime (vector <string> imprimir){
    unsigned a;
    for( a= 0; a<imprimir.size(); a++){
        if(a<imprimir.size()-1){
            cout<<imprimir.at(a);
        }else {
            cout<<imprimir.at(a);
        }
    }
}


//Funcao que separa separa as linhas para gravar no arquivo.

vector <string> transformaVector(vector <string> vetor){
    string line = "";
    vector <string> vetor2;
    for(unsigned i = 0; i < vetor.size() ; i++){
        //cout<<"Antes"<<endl;
        while(!(vetor.at(i)=="\n")){
			
				line = line + vetor.at(i);
				//cout<<line<<endl;
				i++;
		}
        vetor2.push_back(line);
		line = "";
		//cout<<line<<endl;
    }
    return vetor2;

}


//Funcao para abrir o arquivo
vector <string> abreArquivo(string name){
    string line;
    vector <string> arquivo;
    ifstream myfile(name.c_str()); // ifstream = padrÃ£o ios:in
    if (myfile.is_open())
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line); // como foi aberto em modo texto(padrÃ£o)
            //e nÃ£o binÃ¡rio(ios::bin) pega cada linha
            //Joga as linhas do arquivo no vetor para serem usadas.
            arquivo.push_back(line);
        }
    }
    else{
        cout << "Unable to open file"<<endl;
        exit (0);
    }
    myfile.close();
    return arquivo;
}


//Funcao para criar e Salvar o arquivo
void criaArquivo(vector <string> newArquivo, string name){

    string line;

    ofstream myfile (name.c_str()); // Ofstream, abrir e escrever no arquivo
    if (myfile.is_open())
    {
        for(unsigned i = 0; i < newArquivo.size(); i++ )
        {
            //Joga as linhas do arquivo no vetor para serem usadas.
            if(i < newArquivo.size())
                myfile<<newArquivo.at(i)+"\n";
            else
                myfile<<newArquivo.at(i);
        }

    }
    else{
        cout << "Unable to open file"<<endl;
        exit (0);
    }
    myfile.close();
}

string formataProg(string frase){
    unsigned i=0;

    //Remove \n
    if(frase[0]=='\n')
        return "";

    string newfrase ="";
    for(i=0;i<frase.size();i++){


        //Remove tabulacao
        if(frase[i]=='\t')
            i++;

        //Remove Comentario
        if(frase[i]=='/')
            if( i+1 != frase.size())
                if(frase[i+1]=='/')
                    return "";

        //Remove Espacos
        if(frase[i] == ' '){
            newfrase = newfrase+frase[i];
            while(frase[i]==' '){
                i++;
            }

        }
        newfrase=newfrase+frase[i];
    }
    return newfrase;
}

// CORRIGE ERROS EM IDENTIFICADORES E CARACTERES NUMÉRICOS
vector<string> corrigeErros(vector <string> corrigir){
    vector <string> erro;
    erro.push_back("Erros serao enumerados conforme a numeracao do Prog Formatado");
    vector <string> corrigido;
    string line = "";
    for(unsigned i = 0; i<corrigir.size(); i++){
        //Passa uma linha da vector para a variavel line do tipo string
        line =corrigir[i];
        //Percorre a LINHA INTEIRA
        for(unsigned j=0; j<line.size(); j++){




            //Verifica se o caracter e numerico
            if(line[j]>=48 && line[j] <= 57){
                while(true){
                    if(line[j]>=48 && line[j] <= 57){
                        j++;
                    }else if ((line[j] != ' ') && (line[j] != '=') && (line[j] != '(') && (line[j] != ')') && (line.size() != j) && (line[j] != ';') && (line[j] != '+')&& (line[j] != '-')){
                        erro.push_back("Erro Lexico, Linha: "+ to_string(i+1)+ ", possivel erro: " + line[j]);
                        line[j] = '1';
                        j++;
                    }else {
                        break;
                    }

                }




            //Verifica se o caracter pertence a um identificador
            }else if((line[j]>=65 && line[j] <= 90)||(line[j]>=97 && line[j] <= 122))
            {
                while(true){
                    if((line[j]>=65 && line[j] <= 90)||(line[j]>=97 && line[j] <= 122)||(line[j]>=48 && line[j] <= 57)){
                        j++;
                    }else if ((line[j] != ' ') && (line[j] != '=') && (line[j] != '(') && (line[j] != ')') && (line.size() != j) && (line[j] != ';') && (line[j] != '+')&& (line[j] != '-')){
                        erro.push_back("Erro Lexico, Linha: "+ to_string(i+1)+ ", possivel erro: " + line[j]);
                        line[j]='a';
                        j++;
                    }else {
                        break;
                    }
                }
            }
        }corrigido.push_back(line);

    }
    //Cria tabela de erros
    criaArquivo(erro,"tabelaErro.txt");
    return corrigido;
}
