#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

void Create_File(const string File_Name);
void Print_File(const string File_Name);
void Process_File(const string File_Name, const string File_Name_Second);
void Search_Max_Sequence_Of_Numbers(ofstream& f_second, const string line_of_numbers, const string File_Name_Second);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int action;

	string File_Name, File_Name_Second;

	do
	{
		cout << endl << endl << endl;
		cout << "Оберіть дію" << endl;
		cout << "1 - Створити файл" << endl;
		cout << "2 - Вивід файлу" << endl;
		cout << "3 - Опрацювання файлу" << endl;
		cout << "0 - Завершити роботу програми" << endl;
		cout << "Введіть: "; cin >> action;

		switch (action)
		{
		case 1:
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; getline(cin, File_Name);

			Create_File(File_Name);

			break;
		case 2:
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; getline(cin, File_Name);

			Print_File(File_Name);
			break;
		case 3:
			cin.get();
			cin.sync();
			cout << "Введіть назву нового файлу: "; getline(cin, File_Name_Second);

			Process_File(File_Name, File_Name_Second);
			break;
		case 0:
			exit(1);
		default:
			cout << "Помилка!" << endl;
		}
	} while (action != 0);

	return 0;
}
void Create_File(const string File_Name)
{
	ofstream f(File_Name, ios::out);

	string line, action;

	do
	{
		cout << "Введіть строку: ";
		cin.get(); cin.sync();
		getline(cin, line);
		f << line << endl;

		cout << "Бажаєте продовжити?(Так, ні)";
		getline(cin, action);

	} while (action == "так" || action == "Так" ||
		action == "yes" || action == "Yes" ||
		action == "Y" || action == "y" ||
		action == "Та" || action == "та" || action == "1");
}
void Print_File(const string File_Name)
{
	string line;

	ifstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "Файл не відкрито!" << endl;
		return;
	}

	cout << endl << endl;
	while (!f.eof())
	{
		getline(f, line);
		cout << line << endl;
	}
}
void Process_File(const string File_Name, const string File_Name_Second)
{
	ifstream f(File_Name, ios::in);
	ofstream f_second(File_Name_Second, ios::out);

	string line;

	if (!f.is_open())
	{
		cout << "Файл не відкрито!" << endl;
		return;
	}

	while (!f.eof())
	{
		string line_of_numbers;

		getline(f, line);

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == '0' ||
				line[i] == '1' ||
				line[i] == '2' ||
				line[i] == '3' ||
				line[i] == '4' ||
				line[i] == '5' ||
				line[i] == '6' ||
				line[i] == '7' ||
				line[i] == '8' ||
				line[i] == '9')
			{
				line_of_numbers += line[i];
			}
			else
				line_of_numbers += ' ';
		}
		Search_Max_Sequence_Of_Numbers(f_second, line_of_numbers, File_Name_Second);		
	}
}
void Search_Max_Sequence_Of_Numbers(ofstream& f_second,  const string line_of_numbers, const string File_Name_Second)
{
	string workingWord;  
	string maxWord;  
	unsigned i = 0;

	for (i = 0; i < line_of_numbers.size(); i++)
	{
		if (line_of_numbers[i] != ' ')    
			workingWord += line_of_numbers[i]; 
		else workingWord = "";

		if (workingWord.size() > maxWord.size()) 
			maxWord = workingWord;
	}
	f_second << maxWord << endl;
	f_second << "\n";
}
