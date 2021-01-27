#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <fstream> // fluxo de arquivo
using std::ofstream; // insere fluxo de arquivo
using std::ifstream;

using namespace std;

//exercicio sala de aula 1 26/02/2019
//Aluno: Vitor de Almeida Silva
//Aluno: Higor Alves Ferreira

//1)retirar os espaços, ignorar o comentário e retirar os \n sobresalentes.
//2)gerar aquivo com erros, identificar a linha e o caracter errado
//3)gerar arquivo de palavras identificadas, dentro de colchetes e separadas por ,
// [nome,]

//por algum motivo que não descobri, o código não funciona corretamente no linux
//ele da um erro ao abrir o arquivo e buga toda a parte de retirar espaços e de erro
//mas nos pcs com windows ele funcionou normalmente


//por enquanto o codigo fonte exige que se tenha ao menos 1 epaço entre separadores como parenteses e ;
//por exemplo:  if ( a=b )  ou for ( i=0 ; i<=10 ; i=i+1 )



//cria o arquivo teste1, esté é o arquivo sem espaços
bool criarArquivo(char *codigo)
{
	try
	{

		ofstream teste1 ("teste1.cmp", ios::out);
		if (!teste1)
		{
			cerr << "Erro na abertura do arquivo teste1 criação\n" << endl;
			throw(1);
		}

		for(int i = 0; i <= strlen(codigo); i++)
		{
			teste1 << codigo[i];
		}

		teste1.close();


		return true;

	}
	catch(int)
	{
		return false;
	}

}//fim criarArquivo


//função recebe o nome do arquivo e mostra o conteudo do mesmo
void mostrarArquivo(string ArqNome)
{
	
        char saida[ArqNome.size()];
	    strcpy(saida, ArqNome.c_str());
	    string out="";
	    
	    fstream arq;
	    arq.open(saida,ios::in);
		if (!arq.is_open())
		{
			cout<<"Erro na abertura do arquivo"<<ArqNome<<"função mostraArquivo\n" << endl;
			exit(1);
		}
		cout<<"\n\n******Conteudo do arquivo "<<ArqNome<<"******\n\n";
		while(!arq.eof())
		{
			getline(arq,out);
			cout<<out<<endl;
		}
		arq.close();			
			
	
}//fim da função mostrarArquivo



//está função já cria o arquivo teste1.cmp
void retiraEspacos(char *codigo, char *ref)
{

	string resultado = "";
	for(int i = 0; i <= (int)strlen(codigo); i++)
	{
		if(codigo[i] != 32)
		{

			if(i != 0 && codigo[i - 1] == '/' && codigo[i] == '/')
			{

				resultado[i - 2] = ' '; //iginora toda a linha do comentário
				while(codigo[i] != '\n')
					i++;


			}
			//verifica a existencia de mais de um \n
			if(codigo[i] == '\n')
			{

				resultado += '\n';
				//percorre o codigo enquanto existirem \n
				while(codigo[i] == '\n')
					i++;

			}
			if(codigo[i - 1] != '/' && codigo[i] != '/')
				resultado += codigo[i];

			//adiciona um epaço para separação
			if(codigo[i + 1] == 32)
				resultado += " ";

		}



	}

	//converte o resultado em array de char para ser usado na função
	char cod[resultado.size() + 1];
	strcpy(cod, resultado.c_str());

	//cria arquivo sem espaços
	if(criarArquivo(&cod[0]))
		cout << "\n\n****ARQUIVO .CMP GERADO função retiraEspacos 0u0****\n\n" << endl;
	else
		cout << "não foi possível gerar o arquivo 0_0 função retiraEspacos" << endl;

}//fim retirarEspaços


//função para criar os arquivos de erro e de ids;
bool criaArquivosErroId()
{

	//cria arquivo de erros, este comando exclui o conteudo anterior do arquivo;
	ofstream arqErros;
	arqErros.open("arqErros.cmp", ios::out);
	if(!arqErros.is_open())
	{
		cout << "erro ao se abrir o arquivo de erro, função arquivoErro" << endl;
		exit(1);
	}
	arqErros << "ERROS:\n\n";

	//cria arquivos de id, o comando exclui o conteudo anterior do arquivo;
	ofstream arqId;
	arqId.open("arqId.cmp", ios::out);
	if(!arqId.is_open())
	{
		cout << "erro ao se abrir o arquivo de erro, função arquivoErroId" << endl;
		exit(1);
	}

	arqId.close();
	arqErros.close();

	return true;


}//fim função cria arquivosErroId



//a ideia é usar "\0" como um marcador de final, assim não pega os nixos
//o problema é que necessita uma varredura e uma comparação, então tem um custo



//lida com adicionar os erros ao arquivo de erros
bool arquivoErro(char erro[], int linha)
{
	try
	{

		//abrindo arquivo de erro, este comando adiciona coisas ao arquivo
		ofstream arqErros;
		arqErros.open("arqErros.cmp", ios::out | ios::app);
		if(!arqErros.is_open())
		{
			cout << "erro ao se abrir o arquivo de erro, função arquivoErro" << endl;
			throw(1);
		}


		//monta saida para arquivo*********************

		arqErros << linha << ": ";

		for(int i = 0; erro[i] != '\0'; i++)
		{
			if(erro[i] != '\0')
			{
				arqErros << erro[i];
			}
			else
			{
				break; //encerra o laço for
			}

		}
		arqErros << "  inválido\n";

		//************************


		arqErros.close();


		return true;

	}
	catch(int)
	{
		return false;
	}

}//fim arqErro


//adiciona conteudo ao arquivoID
bool arquivoId(char *id)
{
	try
	{
        
		
		//abrindo arquivo de ids, este comando adiciona coisas ao arquivo
		ofstream arqId;
		arqId.open("arqId.cmp", ios::out | ios::app | ios::in);
		if(!arqId.is_open())
		{
			cout << "erro ao se abrir o arquivo de erro, função arquivoId" << endl;
			exit(1);
		}
        

		
		//verifica a já existencia do token no arquivo
		// bool var=false;
		// 
  //       string ver="[";
  //       ver+=id;
  //       ver+=",]";
  //       
	 //    ifstream arq;
	 //    arq.open("arqId.cmp",ios::in);
		// if (!arq.is_open())
		// {
		// 	cout<<"Erro na abertura do arquivo arqId função verificaId\n" << endl;
		// 	exit(1);
		// }
		// while(!arq.eof())
		// {
		// 	string aux;
		// 	getline(arq,aux);
		// 	if(aux==ver)
		// 		var=true;
		// }
		//*******************************************
		
	//	if(!var)
		//{
			
         //monta identificador dentro do arquivo

		arqId << "[";
		int i = 0;
		while(id[i] != '\0')
		{
			arqId << id[i];
			i++;

		}
		arqId << ",]\n";

		//***********************************
				
	//	}

		


		arqId.close();

		return true;

	}
	catch(int)
	{
		return false;
	}

}//fim arquivoId



//está função adiciona os lexemas de forma devida
bool adLex(char *aux, int linha)
{

	int j = 0;
	int k = 0;
	int l = 0;
	char *conc = new char();
	conc[0] = '\0';

	while(aux[j] != '\0')
	{

		int erro2 = 0; //variável que indica se ocorreu algum erro no lex
		char *auxErro2 = new char();
		if(aux[j] >= 65 && aux[j] <= 90 || aux[j] >= 97 && aux[j] <= 122 || (aux[k] >= 48 && aux[k] <= 57))
		{
			conc[k] = aux[j];
			conc[k + 1] = '\0';
			k++;

		}
		else
		{


			//verifica sé é algum simbolo operacional
			if((aux[j] >= 33 && aux[j] <= 47 && (aux[j] != 36 && aux[j] != 44)) ||
					(aux[j] >= 58 && aux[j] <= 62) || (aux[j] >= 91 && aux[j] <= 95) ||
					(aux[j] >= 123 && aux[j] <= 125) )
			{

				if( ((aux[j] == '<' || aux[j] == '>' || aux[j] == '!') && aux[j + 1] == '=') ||
					(aux[j] == '|' && aux[j + 1] == '|') || (aux[j] == '&' && aux[j + 1] == '&') ||
		             (aux[j] == '=' && aux[j + 1] == '=') || (aux[j] == '<' && aux[j + 1] == '<') ||
					 (aux[j] == '>' && aux[j + 1] == '>'))
				{
					char *p = new char();
					p[0] = aux[j];
					p[1] = aux[j + 1];
					p[2] = '\0';
					arquivoId(&p[0]);

					if(conc[0] != '\0')
						arquivoId(&conc[0]);

					//limpa bufer
					k = 0;
					conc[k] = '\0';
					j++;

					delete p;

					
				}
				else
				{
					char *p = new char();
					p[0] = aux[j];
					p[1] = '\0';
					arquivoId(&p[0]);

					if(conc[0] != '\0')
						arquivoId(&conc[0]);

					//limpa bufer
					k = 0;
					conc[k] = '\0';

					
					delete p;


				}



			}
			else
			{

				erro2 = 1;
				auxErro2[l] = aux[j];
				aux[j] = 'P'; //so recebe isso para que se siga adiante
				conc[k] = aux[j];
				conc[k + 1] = '\0';
				k++;
				l++;

			}


		}
		if(erro2 == 1)
			arquivoErro(&auxErro2[0], linha);


		j++;


	}


	if(conc[0] != '\0')
		arquivoId(&conc[0]);




}//fim lex





bool analiseLexica(char *codigo)
{
	int linha = 1;
	int auxLinha;

	//função que cria os arquivos de erro e de ids
	criaArquivosErroId();

	for(int i = 0; i <= strlen(codigo); i++)
	{
		//concatena o lexema para análise
		char *aux = new char();
		for(int j = i, k = 0; j <= strlen(codigo); j++, k++)
		{
			if(codigo[j] != 32)
			{
				if(codigo[j] == '\n')
				{

					auxLinha = linha;
					linha++;
					aux[k] = '\0';
					i = j;
					j = strlen(codigo) + 1;

				}
				else
				{

					aux[k] = codigo[j];

				}


			}
			else
			{
				aux[k] = '\0';
				i = j;
				j = strlen(codigo) + 1;
			}


		}//fim for


		//analise do lexema para encotrar erros ou não e montar tabela

		if(aux[0] != 32 && aux[0] != '\0')
		{



			//analisando valor numerico
			if(aux[0] >= 48 && aux[0] <= 57)
			{
				int erro = 0; //var de erro, seta o erro caso == 1
				char *auxErro = new char();
				for(int k = 0, l = 0; k <= strlen(aux); k++, l++)
				{
					
					if(aux[k] != '\0')
					{

						if(!(aux[k] >= 48 && aux[k] <= 57))
						{
							erro = 1;
							auxErro[l] = aux[k];
							auxErro[l+1]='\0';
							//a posição de erro recebe zero somente para que se siga adiante
							aux[k] = 48;
						}
						else
						{
							l--;
						}

					}
					else
					{
						k = strlen(aux) + 1;
					}


				}

				//se ouve erro ele será mandado para o arquivoErro
				if(erro == 1)
				{
					//pode dar erro de tipo
					erro = 0;
					arquivoErro(auxErro, auxLinha);
				}

				//pode erro de tipo
				arquivoId(&aux[0]);
				delete auxErro;


			}//fim verificação de numero

			else
			{

				//verifica caracteres
				adLex(&aux[0], auxLinha);


			}

		}

	}

	//confirma que a analise foi bem sucedida
	return true;


}//fim ana	string conc;




int main()
{

	//abrindo o arquivo fonte
	ifstream codigo("codigo1.txt", ios::in);

	if (!codigo)
	{
		cerr << "Erro na abertura do arquivo codigo fonte\n" << endl;
		exit( 1 );
	}


	//preenchendo o vetor com o conteudo do arquivo
	string vetor = "";

	for(int i = 0; !codigo.eof(); i++)
	{
		string aux;
		getline(codigo, aux);

		vetor += aux + '\n';

	}

	//convertendo vetor em array de chars
	char cod[vetor.size() + 1];
	strcpy(cod, vetor.c_str());


	//retirando espaçoes e linhas sem importancia
	char *codigofin = new char();
	retiraEspacos(&cod[0], &codigofin[0]);





	//abre o arquivo teste1 para dar continuidade a analise lexica
	ifstream teste1 ("teste1.cmp", ios::in);
	if (!teste1)
	{
		cerr << "Erro na abertura do arquivo teste1 \n" << endl;
		exit( 1 );
	}
	//***********************************************************

	//preenchendo o vetor com o conteudo do arquivo
	string vetor2 = "";

	for(int i = 0; !teste1.eof(); i++)
	{
		string aux;
		getline(teste1, aux);
		vetor2 += aux + '\n';

	}

	//convertendo vetor em array de chars
	char codCmp[vetor2.size() + 1];
	strcpy(codCmp, vetor2.c_str());


	analiseLexica(&codCmp[0]);
	
	mostrarArquivo("codigo1.txt");
	mostrarArquivo("teste1.cmp");
	mostrarArquivo("arqErros.cmp");
	mostrarArquivo("arqId.cmp");

}
