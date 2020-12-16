#include "Truba.h"
#include "ut.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


unsigned int Truba::IDt = 0;

istream& operator >> (istream& in, Truba& t) // �������� �����
{
	t.id = ++Truba::IDt;
	cout << "����� �������� �����\n";
	cin.get();
	getline(cin, t.name);
	t.dlina = getint("����� ����� ����� (������� ���������: �)", 1.0, 10000.0);
	t.diametr = getint("����� ������� �����(������� ��������� : ��)", 1, 10000);
	t.sostoyanie = false;
	return in;
}

ostream& operator << (ostream& out, const Truba& t) // ����� ���������� � �����
{
	out << "������ � �����:\n";
	out << "�������� �����: " << t.name << endl;
	out << "����� �����: " << t.dlina << " (�)" << endl;
	out << "������� �����: " << t.diametr << " (��)" << endl;
	out << "��������� �����: " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
	return out;
}

void Truba::editTruba() // ��������� ����� � ������
{
	sostoyanie = !sostoyanie;
}

void Truba::savefileTruba(std:: ofstream& fout) // ���������� ���������� � �����
{
	fout << id << endl;
	fout << name << endl;
	fout << dlina << endl;
	fout << diametr << endl;
	fout << sostoyanie << endl;
}
void Truba::inputfileTruba(std::ifstream& fin) // ���������� ���������� � �����
{
	fin >> id;
	fin >> name;
	fin >> dlina;
	fin >> diametr;
	fin >> sostoyanie;

}

/* Truba& selectTruba(vector<Truba>& Truboprovod) // ����� �����
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(vector<Truba>& Truboprovod) // �������� �����
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}

bool SearchTrubaByName(const Truba& t, std::string parametr) // ����� �� ��������
{
	return t.name == parametr;
}

bool SearchTrubaBySostoyanie(const Truba& t, double parametr) // 
{
	return t.sostoyanie == parametr;
}
*/