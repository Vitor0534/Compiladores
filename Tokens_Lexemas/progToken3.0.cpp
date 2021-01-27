#include <iostream>
#include <iomanip>
#include <fstream> // fluxo de arquivo
using std::ofstream; // insere fluxo de arquivo

#include <string.h>
#include <cstring>
#include <stdlib.h>

#include <iomanip>
using std::setw;
using std::setprecision;

using namespace std;



//Trabalho tabela de Tokens/lexemas
//Aluno: vitor de Almeida Silva




//classe com os parametros da tabela tokens/lexemas
class tabela
{
private:
	string tokens[7];
	string lexemas[7];
public:
	tabela();
	~tabela();
	string * getTokens()
	{
		return tokens;
	}
	string *getLexemas()
	{
		return lexemas;
	}
	void setLexema(string lexema, int tipo)
	{
		lexemas[tipo] +=lexema + ",";
	}
	void mostrarLex();


};
tabela::~tabela() {}

//construtor
tabela::tabela()
{
	tokens[0] = "if: ";
	tokens[1] = "op: ";
	tokens[2] = "id: ";
	tokens[3] = "comp: ";
	tokens[4] = "then: ";
	tokens[5] = "num: ";
	tokens[6] = "não reconhecido: ";

	lexemas[0] = "";
	lexemas[1] = "";
	lexemas[2] = "";
	lexemas[3] = "";
	lexemas[4] = "";
	lexemas[5] = "";
	lexemas[6] = "";
}

void tabela::mostrarLex()  //fução para imprimir parametros tokens e lexemas
{
	cout<<"tokens"<<"\t"<<"lexemas\n"<<endl;
	for(int i = 0; i <= 6; i++)
	{
		cout <<this->tokens[i]<<"\t"<< this->lexemas[i] << "\n" << endl;
	}
		
}


// testa if,then e qq identificador,já seta para a tabela
int testaToken(char aux[], tabela *tab1)
{
//	cout << "testa token:" << aux << endl;

	if(aux[0] == 'i' && aux[1] == 'f' && aux[2] == ',')
	{
		aux[2] = ' ';
		tab1->setLexema("if", 0);
		return 0;
	}

	else
	{
		if(aux[0] == 't' && aux[1] == 'h' && aux[2] == 'e' && aux[3] == 'n' && aux[4] == ',')
		{
			aux[4] = ' ';
			tab1->setLexema("then", 4);
			return 4;
		}

		else
		{
			
			char *op=new char();
			for(int i=0;i<=strlen(aux);i++)
			{
				//cout<<"id:"<<aux<<endl;
				if(aux[i]!=',')
					op[i]=aux[i];
				else
				{
					op[i]=' ';
					i=strlen(aux)+1;
				}
				
			}
			op[strlen(op)-1] = ' ';
			tab1->setLexema(&op[0], 2);
			delete op;
			return 2;
		}
	}

	return -1;
}

//testar comp, pega  todos os comparadores
int testaOpComp(char aux[], tabela *tab1)
{
//	cout << "testaOpComp:" << aux << endl;

	if((aux[0] == '(' && aux[1] == ','))
		tab1->setLexema("(", 1);
	else
	{
		if((aux[0] == ')' && aux[1] == ','))
			tab1->setLexema(")", 1);
		else
		{
			if((aux[0] == '=' && aux[1] == ','))
				tab1->setLexema("=", 1);
			else
			{
				if((aux[0] == ';' && aux[1] == ','))
					tab1->setLexema(";", 1);
				else
				{
					if((aux[0] == '=' && aux[1] == '=' && aux[2] == ','))
						tab1->setLexema("==", 3);
					else
					{
						if((aux[0] == '!' && aux[1] == '=' && aux[2] == ','))
	      	               tab1->setLexema("!=", 3);
					else
					{
						if((aux[0] == '>' && aux[1] == '=' && aux[2] == ','))
					     	tab1->setLexema(">=", 3);
					else
					{
							if((aux[0] == '<' && aux[1] == '=' && aux[2] == ','))
						        tab1->setLexema("<=", 3);
						else
						{
								if((aux[0] == '<' && aux[1] == ','))
						        tab1->setLexema("<", 3);
						    else
							{
								if((aux[0] == '>' && aux[1] == ','))
						        tab1->setLexema(">", 3);
						    else
							{
								//seta os caracteres não reconhecidos
								char *op=new char();
					   			for(int i=0;i<=strlen(aux);i++)
	   		   					{
					   		   		if(aux[i]!=',')
					   	   	   	   	op[i]=aux[i];
					   		   		else
					   		     	{
										op[i]=' ';
  	   									i=strlen(aux)+1;
				   	   	   	   	 	}
				
							   	}
							
			   	   	   	   	op[strlen(op)-1] = ' ';
							tab1->setLexema(&op[0],6);
							delete op;
						   	return 0;
								
							}
								
							}
                        
						}
							
						
					}
					
						
					}
						
					}
				}

			}

		}


	}

	return 1;
}


//trata numero
int trataNum(char aux[], tabela *tab1)
{
	char *op=new char();
	for(int i = 0; i < strlen(aux); i++)
	{
		if((aux[i] >= 48 && aux[i] <= 57 ))
		{

			op[i] = aux[i];

		}
		else
		{
			op[strlen(op)-1]=' ';
			tab1->setLexema(&op[0], 5);
			delete op;
			return 5;
		}


	}
	delete op;
	
	return -1;

}



int main()
{
	tabela tab1;

	//abrindo o arquivo fonte
	ifstream codigo("codigo1.txt", ios::out);

	if (!codigo)
	{
		cerr << "Erro na abertura do arquivo\n" << endl;
		exit( 1 );
	}


	//preenchendo o vetor com o conteudo do arquivo
	string vetor = "";

	for(int i = 0; !codigo.eof(); i++)
	{
		string aux;
		getline(codigo, aux);
		vetor += aux;
	}
	//cout<<vetor<<endl;
	char cod[vetor.size() + 1];
	strcpy(cod, vetor.c_str()); //converte string em array de chars
	cout <<"conteudo do arquivo:\n"<< cod <<"\n\n\n"<<endl;

	

	bool very = false;
//	cout << "tam:" << strlen(cod);
	for(int i = 0; i <= strlen(cod); i++)
	{
		//cout << "entrei no for" << endl;
	//	cout << "cod[" << i << "]=" << cod[i] << endl;

		//verificando letras
		if((cod[i] >= 65 && cod[i] <= 90 ) || (cod[i] >= 97 && cod[i] <= 122))
		{
			//cout << "verifiquei letra" << endl;
		//	cout << "cod[" << i << "]=" << cod[i] << endl;
			char aux[50];
			for(int j = i, k = 0; j <= strlen(cod); j++, k++)
			{
				if((cod[j] >= 65 && cod[j] <= 90 ) || (cod[j] >= 97 && cod[j] <= 122) ||
						(cod[j] >= 48 && cod[j] <= 57 ))
				{
				//	cout << "pega letra1" << endl;
					aux[k] = cod[j];
				//	cout << cod[j] << endl;
				}
				else
				{
					//if((cod[j]>=33 && cod[j]<=47 )||(cod[j]>=58 && cod[j]<=64))
					//{
				//	cout << "pega letra2" << endl;
					aux[k] = ',';
					int x = testaToken(&aux[0], &tab1);
					i = j - 1;
					j = strlen(cod) + 10;
					//	}
				}
			//	cout << "\n\n" << aux << endl;
			}

		}

		else
		{

			if((cod[i] >= 48 && cod[i] <= 57 ))
			{
			//	cout << "\n\npega numero1" << endl;
				char aux2[50];
				for(int j = i, k = 0; j <= strlen(cod); j++, k++)
				{
					//cout << "\n\npega numero2" << endl;
					if((cod[j] >= 48 && cod[j] <= 57 ))
					{
						aux2[k] = cod[j];
						//cout << aux2[k] << endl;
					}
					else
					{
						aux2[k] = ',';
						//cout << "o numero pego foi:" << aux2 << endl;
						//tab1.setLexema(&aux2[0], 5);
						int x = trataNum(&aux2[0], &tab1);
						i = j - 1;
						j = strlen(cod) + 1;
					}

				}
			}
			else
			{

				if((cod[i] >= 33 && cod[i] <= 47) || (cod[i] >= 58 && cod[i] <= 64) ||
						(cod[i] >= 91 && cod[i] <= 96) || (cod[i] >= 124 && cod[i] <= 126))
				{
					//cout << "caracter especial" << endl;
					char aux3[4];
					for(int j = i, k = 0; j <= strlen(cod); j++, k++)
					{
					//	cout << "pega especial" << endl;
						if((cod[j] >= 33 && cod[j] <= 47) || (cod[j] >= 58 && cod[j] <= 64) ||
								(cod[j] >= 91 && cod[j] <= 96) || (cod[j] >= 124 && cod[j] <= 126))
						{
							aux3[k] = cod[j];
						//	cout << "especial:" << endl;

						}
						else
						{
							i = j - 1;
							j = strlen(cod) + 1;
							aux3[k] = ',';
							int tipo = testaOpComp(&aux3[0], &tab1);
						}

					}

				}
			}

			//cout << "fim prog" << endl;
			//i=strlen(cod)+1;
		}

	} //end for

	cout << "\n tabela Token/Lexemas:\n\n" << endl;
	tab1.mostrarLex();
	

}

