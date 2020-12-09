#pragma once
#include <string>

class KS
{
	static unsigned int IDks;
	std::string name;
	unsigned int id; // Идентификатор
	int N; // Количество цехов
	int Ninwork; // Количсевто цехов в работе
	int effect; // Эффективность

public:
		friend KS createKS(); // Создание компрессорной станции
		friend void printKS(const KS& ks); // Вывод информации о компрессорной станции
		friend void editKS(KS& ks); // Изменение цехов в работе
		friend void savefileKS(std::ofstream& fout, const KS& ks); // Сохранение информации о компрессорной станции
		friend KS inputfileKS(std::ifstream& fin); // Считывание информации о компрессорной станции
};

