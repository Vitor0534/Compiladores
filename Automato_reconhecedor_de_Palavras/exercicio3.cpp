#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//Aluno: Vitor de Almeida Silva

int main(int argc, char** argv)
{
    string caca;
	char *cadeia=new char();
	string confere;
	cout << "insira a cadeia" << endl;
	cin.getline(cadeia,100);
	
	
	if(cadeia[0] >= 65 && cadeia[0] <= 90 || cadeia[0] >= 97 && cadeia[0] <= 122)
	{
		confere = "aceita";
		for(int i = 1; i < strlen(cadeia); i++)
		{
			if(     !(cadeia[i] >= 65 && cadeia[i] <= 90) &&
					!(cadeia[i] >= 97 && cadeia[i] <= 122) &&
					!(cadeia[i] >= 48 && cadeia[i] <= 57) &&
					!(cadeia[i] == '0') 
			  )

			{
				confere = "rejeitada";
				i = strlen(cadeia)+1;

			}

		}
	}
	else
	{
		confere = "rejeitada";
	}

	cout << confere << endl;


	return 0;
}
