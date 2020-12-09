#include "KS.h"
#include <iostream>
#include <fstream>
#include "ut.h"
#include <string>

unsigned int KS::IDks = 0;

KS createKS() // Создание компрессорной станции
{
	KS ks;
	cout << "Введи название компрессорной станции\n";
	cin.get();
	getline(cin, ks.name);
	ks.N = getint("Введи количество цехов", 1, 10000);
	ks.Ninwork = getint("Введи количество цехов в работе", 0, ks.N);
	ks.effect = getint("Введи эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0, 10000);
	return ks;
}

void printKS(const KS& ks) // Вывод информации о компрессорной станции
{
	cout << "Данные о компрессорной станции:\n";
	cout << "Имя компрессорной станции: " << ks.name << endl;
	cout << "Количество цехов на компрессорной станции: " << ks.N << endl;
	cout << "Количество цехов в работе: " << ks.Ninwork << endl;
	cout << "Эффективность компрессорной станции: " << ks.effect << endl;
}

void editKS(KS& ks) // Изменение цехов в работе
{
	ks.Ninwork = getint("Введи количество цехов в работе", 0, ks.N);
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
}
