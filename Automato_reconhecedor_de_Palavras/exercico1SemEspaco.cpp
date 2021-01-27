#include <iostream>
#include <string>
using namespace std;


int main()
{
	//implementar um altomato que reconheça as palavras chaves NEW,WHILE e NOT

	string palavra;

	cout << "insira a palavra" << endl;
	getline(cin,palavra);


	for(int i = 0; palavra[i] != '\0' && i != -1; i++)
	{
		if((palavra[i] == 'n' || palavra[i] == 'N'))
		{
			if(palavra[i + 1] == 'e' || palavra[i + 1] == 'E')
			{
				if(palavra[i + 2] == 'w' || palavra[i + 2] == 'W')
				{
					if(palavra[i + 3] == ';' || palavra[i + 3] == '\0')
					{
						
						if(palavra[i + 3] ==';')
						{
							cout<<"aceita"<<endl;
						}
						else
						{
							cout<<"rejeitada,talvez falte o ;"<<endl;
						}
					}
					else
					{
						cout<<"rejeitada,talvez falte o ;"<<endl;

					}
					
				}

			}
			else
			{
				if(palavra[i + 1] == 'o' || palavra[i + 1] == 'O')
				{
					if(palavra[i + 2] == 't' || palavra[i + 2] == 'T')
					{
						if(palavra[i + 3] == ';' || palavra[i + 3] == '\0')
						{
							if(palavra[i + 3] == ';')
							{
								cout<<"aceita"<<endl;
							}
							else
						{
							cout<<"rejeitada,talvez falte o ;"<<endl;
						}
						}
						else
						{
							cout<<"rejeitada,talvez falte o ;"<<endl;

						}
					}

				}


			}


		}
		else //while
		{
			if((palavra[i] == 'w' || palavra[i] == 'W'))
			{
				if(palavra[i + 1] == 'h' || palavra[i + 1] == 'H')
				{
					if(palavra[i + 2] == 'i' || palavra[i + 2] == 'I')
					{
						if(palavra[i + 3] == 'l' || palavra[i + 3] == 'L')
						{
							if(palavra[i + 4] == 'e' || palavra[i + 4] == 'E')
							{
								if(palavra[i + 5] == '\0' || palavra[i + 5] == ';')
								{
									if(palavra[i + 5] == ';')
									{
											cout<<"aceita"<<endl;

									}
									else
						{
							cout<<"rejeitada,talvez falte o ;"<<endl;
						}

								}
								else
								{
									cout<<"rejeitada,talvez falte o ;"<<endl;
								}
							}
							else{
								cout<<"rejeitada,talvez falte o ;"<<endl;
								
							} 
						}
						else{
							cout<<"rejeitada,talvez falte o ;"<<endl;
						} 
					}
					else{
						cout<<"rejeitada,talvez falte o ;"<<endl;
					} 
				}

			}
				
		}
		

	}

}