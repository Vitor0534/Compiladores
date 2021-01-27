#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//Aluno: Vitor de Almeida Silva


int main()
{
	//implementar um altomato que reconhe√ßa as palavras chaves NEW,WHILE e NOT

	string palavra;
	string aceitas;
	string naoAceitas;


	cout << "insira a palavra" << endl;
	getline(cin, palavra);

	int veri = 0;
	string cheq[palavra.size()];

	for(int i = 0; palavra[i] != '\0'; i++)
	{

		if(veri == 0 && (palavra[i] == 'n' || palavra[i] == 'N'))
		{
			if(palavra[i + 1] == 'e' || palavra[i + 1] == 'E')
			{
				if(palavra[i + 2] == 'w' || palavra[i + 2] == 'W')
				{

					if(palavra[i + 3] == '\0')
						cheq[i] = "aceita";
					else
						cheq[i] = "n„oAceita";

				}
				else
					cheq[i] = "n„oAceita";
			}
			else
			{
				if(palavra[i + 1] == 'o' || palavra[i + 1] == 'O')
				{
					if(palavra[i + 2] == 't' || palavra[i + 2] == 'T')
					{

						if(palavra[i + 3] == '\0')
							cheq[i] = "aceita";
						else
							cheq[i] = "n„oAceita";

					}

					else
						cheq[i] = "n„oAceita";
				}
				else
					cheq[i] = "n„oAceita";

			}

		}
		else
		{
			if(veri == 0 && (palavra[i] == 'w' || palavra[i] == 'W'))
			{
				if(palavra[i + 1] == 'h' || palavra[i + 1] == 'H')
				{
					if(palavra[i + 2] == 'i' || palavra[i + 2] == 'I')
					{
						if(palavra[i + 3] == 'l' || palavra[i + 3] == 'L')
						{
							if(palavra[i + 4] == 'e' || palavra[i + 4] == 'E')
							{
								if(palavra[i + 5] == '\0')
									cheq[i] = "aceita";
								else
									cheq[i] = "n„oAceita";
							}
							else cheq[i] = "naoAceita";
						}
						else cheq[i] = "naoAceita";
					}
					else cheq[i] = "naoAceita";
				}
				else
					cheq[i] = "n„oAceita";

			}
			else
			{
				cheq[i] = "naoAceita";
			}

		}

	}
	for(int i = 0; i <= 0; i++)
	{
		cout << cheq[i] << endl;
	}

}
