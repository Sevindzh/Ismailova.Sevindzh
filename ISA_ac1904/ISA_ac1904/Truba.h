#pragma once
#include <string>

class Truba
{
	static unsigned int IDt;
	unsigned int id; // Идентификатор
	double dlina; // Длина
	int diametr; // Диаметр
	bool sostoyanie; // Состояние в ремонте или нет

public:
	friend Truba createTruba(); // Создание трубы
	friend void printTruba(const Truba& t); // Вывод информации о компрессорной станции
	friend void editTruba(Truba& t); // Изменение цехов в работе
	friend void savefileTruba(std::ofstream& fout, const Truba& t); // Сохранение информации о компрессорной станции
	friend KS inputfileTruba(std::ifstream& fin); // Считывание информации о компрессорной станции
	
	
};

