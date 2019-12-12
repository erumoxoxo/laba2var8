#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file;
	file.open("C:\\Text.txt");
	char* word = new char[10000];
	int numb = 0;
	if (!file.is_open())
	{
		cout << "?? \"Text.txt\" ? ???\n";
		system("pause");
		return 0;
	}
	else
	{
		file.getline(word, 10000, EOF);
		file.close();
		int pr = 0;
		for (int i = 0; i < 10000; i++)
		{
			if (word[i] == '\0')
				break;
			if (word[i] == '\"')
			{
				if ((pr+1)%2)
					cout << endl;
				cout << '\"';
				pr++;
				continue;
			}
			if (pr % 2)
				cout << word[i];
		}
	}
	delete[] word;
	system("pause");
}