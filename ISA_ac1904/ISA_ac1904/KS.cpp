#include "KS.h"
#include <iostream>
#include <fstream>
#include "ut.h"
#include <string>
#include <vector>

unsigned int KS::IDks = 0;

istream& operator >> (istream& in, KS& ks) // �������� ������������� �������
{
	ks.id = ++KS::IDks;
	cout << "����� �������� ������������� �������\n";
	cin.get();
	getline(cin, ks.name);
	ks.N = getint("����� ���������� �����", 1, 10000);
	ks.Ninwork = getint("����� ���������� ����� � ������", 0, ks.N);
	ks.effect = getint("����� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)", 0, 10000);
	return in;
}

ostream& operator << (ostream& out, const KS& ks) // ����� ���������� � ������������� �������
{
	out << "������ � ������������� �������:\n";
	out << "id ������������� �������: " << ks.id << endl;
	out << "�������� ������������� �������: " << ks.name << endl;
	out << "���������� ����� �� ������������� �������: " << ks.N << endl;
	out << "���������� ����� � ������: " << ks.Ninwork << endl;
	out << "������������� ������������� �������: " << ks.effect << endl;
	return out;
}

void KS::editKS() // ��������� ����� � ������
{
	Ninwork = getint("����� ���������� ����� � ������", 0, N);
}

void KS::savefileKS(std::ofstream& fout) // ���������� ���������� � ������������� �������
{
	fout << id << endl;
	fout << name << endl;
	fout << N << endl;
	fout << Ninwork << endl;
	fout << effect << endl;
}

void KS::inputfileKS(std::ifstream& fin) // ���������� ���������� � ������������� �������
{
	fin >> id;
	fin >> name;
	fin >> N;
	fin >> Ninwork;
	fin >> effect;
}

std::string KS::getname()
{
	return name;
}

int KS::getN()
{
	return N;
}

int KS::getNinwork()
{
	return Ninwork;
}

unsigned int KS::getid()
{
	return id;
}
