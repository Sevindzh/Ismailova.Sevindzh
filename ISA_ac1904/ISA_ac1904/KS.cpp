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
	out << "��� ������������� �������: " << ks.name << endl;
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

/* KS& selectKS(vector<KS>& Zavod) // ����� ������������� �������
{
	unsigned int index = getint("������� ����� ������������� �������", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(vector<KS>& Zavod) // �������� ������������� ������
{
	unsigned int index = getint("������� ����� ������������� �������", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
}

bool SearchKSByName(const KS& ks, std::string parametr) // ����� �� ��������
{
	return ks.name == parametr;
}

bool SearchKSByNinwork(const KS& ks, double parametr) // ����� �� ���������� ����� �� %
{
	return 1 - ks.n / ks.Ninwork >= parametr;
}
*/
