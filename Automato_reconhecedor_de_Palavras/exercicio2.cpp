#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


//Aluno: Vitor de Almeida Silva

int main()
{

	char *cadeiaNum=new char();
	cout << "insira os numero" << endl;
	cin.getline(cadeiaNum,100);
	string confere;
	//s1

	if(cadeiaNum[0] == 48 && cadeiaNum[1] == '\0')
	{
		confere = "aceita";
	}
	else
	{
		if(cadeiaNum[0] == 48 && cadeiaNum[1] != '\0')
		{
			confere = "rejeitada";
		}
		else
		{
			confere = "aceita";
			for(int i=0; i < strlen(cadeiaNum); i++)
			{

				if(!(cadeiaNum[i] >= 48 && cadeiaNum[i] <=57))
				{
					confere = "rejetitada";
					i = strlen(cadeiaNum) + 1;
				}

			}
		}
	}
	cout << confere << endl;
	
}
