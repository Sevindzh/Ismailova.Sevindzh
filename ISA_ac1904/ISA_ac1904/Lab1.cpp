#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "KS.h"
#include "Truba.h"
#include "ut.h"
#include "KS.cpp"
#include "Truba.cpp"

using namespace std;

/* struct Truba//Труба
{
	string id; // Идентификатор
	double dlina; // Длина
	int diametr; // Диаметр
	bool sostoyanie; // Состояние в ремонте или нет

};
struct KS // Компрессорная станция
{
	string name; // Имя
	string id; // Идентификатор
	int N; // Количество цехов
	int Ninwork; // Количсевто цехов в работе
	int effect; // Эффективность
};

template <typename T>
T getint(string text, T border1, T border2)
{
	T value;
	while (1)
	{
		cout << text << endl;
		cin >> value;
		if (cin.fail() || value < border1 || value >border2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуй ещё раз.\n";
		}
		else
		{
			return value;
		}
	}

}
Truba createTruba() // Создание трубы
{
	Truba t;
	t.id = "1";
	t.dlina = getint("Введи длину трубы (Еденица измерения: м)", 1.0,10000.0);
	t.diametr = getint("Введи диаметр трубы(Еденица измерения : мм)", 1,10000);
	t.sostoyanie = false;
	return t;
}
KS createKS() // Создание компрессорной станции
{
	KS ks;
	cout << "Введи имя компрессорной станции\n";
	cin.get();
	getline(cin, ks.name);
	ks.N = getint("Введи количество цехов", 1,10000);
	ks.Ninwork = getint("Введи количество цехов в работе", 0, ks.N);
	ks.effect = getint("Введи эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0,10000);
	return ks;
}
void printTruba(const Truba& t) // Вывод информации о трубе
{
	cout << "Данные о трубе:\n";
	cout << "Длина трубы: " << t.dlina << " (м)" << endl;
	cout << "Диаметр турбы: " << t.diametr << " (мм)" << endl;
	cout << "Состояние трубы: " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
}
void printKS(const KS& ks) // Вывод информации о компрессорной станции
{
	cout << "Данные о компрессорной станции:\n";
	cout << "Имя компрессорной станции: " << ks.name << endl;
	cout << "Количество цехов на компрессорной станции: " << ks.N << endl;
	cout << "Количество цехов в работе: " << ks.Ninwork << endl;
	cout << "Эффективность компрессорной станции: " << ks.effect << endl;
}
void editTruba(Truba& t) // Отправить трубу в ремонт
{
	t.sostoyanie = !t.sostoyanie;
}
void editKS(KS& ks) // Изменение цехов в работе
{
	ks.Ninwork = getint("Введи количество цехов в работе", 0, ks.N);
}
void savefileTruba(ofstream& fout, const Truba& t) // Сохранение информации о трубе
{
	fout << t.id << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}
Truba inputfileTruba(ifstream& fin) // Считывание информации о трубе
{
	Truba t;
	fin >> t.id;
	fin >> t.dlina;
	fin >> t.diametr;
	fin >> t.sostoyanie;
	return t;
}
void savefileKS(ofstream& fout, const KS& ks) // Сохранение информации о компрессорной станции
{
	fout << ks.name << endl;
	fout << ks.N << endl;
	fout << ks.Ninwork << endl;
	fout << ks.effect << endl;
}
KS inputfileKS(ifstream& fin) // Считывание информации о компрессорной станции
{
	KS ks;
	fin >> ks.name;
	fin >> ks.N;
	fin >> ks.Ninwork;
	fin >> ks.effect;
	return ks;
} */

Truba& selectTruba(vector<Truba>& Truboprovod)
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}
KS& selectKS(vector<KS>& Zavod)
{
	unsigned int index = getint("Введи номер компрессорной станции", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteTruba(vector<Truba>& Truboprovod)
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}

void deleteKS(vector<KS>& Zavod)
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
}
void printmenu()
{
	cout << "1-Добавить трубу\n";
	cout << "2-Добавить компрессорную станцию\n";
	cout << "3-Вывести информацию о трубе и компрессорной станции\n";
	cout << "4-Редактировать состояние трубы\n";
	cout << "5-Редактировать колличество цехов в работе компрессорной станции\n";
	cout << "6-Сохранить данные файл\n";
	cout << "7-Считать данные из файла\n";
	cout << "8-Удалить трубу\n";
	cout << "9-Удалить компрессорную станцию\n";
	cout << "0-Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Truba> Truboprovod;
	vector <KS> Zavod;
	while (1)
	{
		printmenu();
		int i;
		i = getint("Введи номер действия", 0,10000);
		switch (i)
		{
		case 1:
		{
			Truboprovod.push_back(createTruba());
			break;
		}
		case 2:
		{
			Zavod.push_back(createKS());
			break;
		}
		case 3:
		{
			if (Truboprovod.size() > 0 || Zavod.size() > 0)
			{
				if (Truboprovod.size() > 0)
				{
					for (const auto& infoTruba : Truboprovod);
						{
							printTruba(infoTruba);
						}
				}
				else
				{
					cout << "Труба не создана.\n";
				}
				if (Zavod.size() > 0)
				{
					for (const auto& infoKS : Zavod);
					{
						printKS(infoKS);
					}

				}
				else
				{
					cout << "Компрессорная станция не создана.\n";
				}
				break;

			}
			else
			{
				cout << "Труба или Компрессорная станция не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 4:
		{
			if (Truboprovod.size() > 0)
			{
				editTruba(selectTruba(Truboprovod));
				break;
			}
			else
			{
				cout << "Труба не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 5:
		{
			if (Zavod.size() > 0)
			{
				editKS(selectKS(Zavod));
				break;
			}
			else
			{
				cout << "Компрессорная станция не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 6:
		{
			if (Truboprovod.size() > 0 || Zavod.size() > 0)
			{
				ofstream fout;
				fout.open("info.txt", ios::out);
				if (fout.is_open())
				{
					fout << Truboprovod.size() << endl;
					fout << Zavod.size() << endl;
					if (Truboprovod.size() > 0)
					{
						for (const auto& infoTruba : Truboprovod)
						{
							savefileTruba(fout, infoTruba);
						}
					}
					if (Zavod.size() > 0)
					{
						for (const auto& infoKS : Zavod)
						{
							savefileKS(fout, infoKS);
						}
					}
					fout.close();
				}
				break;
			}
			else
			{
				cout << "Труба или Компрессорная станция не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 7:
		{
			ifstream fin;
			fin.open("info.txt", ios::in);
			if (fin.is_open())
			{
				int countt;
				int countks;
				fin >> countt;
				fin >> countks;
				Truba infotruba;
				KS infoKS;
				if (countt > 0)
				{
					while (countt--)
					{
						infotruba = inputfileTruba(fin);
						Truboprovod.push_back(infotruba);
					}
				}
				if (countks > 0)
				{
					while (countks--)
					{
						infoKS = inputfileKS(fin);
						Zavod.push_back(infoKS);
					}
				}
				fin.close();
			}
			break;
		}
		case 8:
		{
			deleteTruba(Truboprovod);
			break;
		}
		case 9:
		{
			deleteKS(Zavod);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуй ещё раз.";
		}
		}
	}
}
