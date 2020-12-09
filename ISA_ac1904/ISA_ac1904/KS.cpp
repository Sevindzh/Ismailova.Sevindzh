#include "KS.h"
#include <iostream>
#include <fstream>
#include "ut.h"
#include <string>

unsigned int KS::IDks = 0;

KS createKS() // �������� ������������� �������
{
	KS ks;
	cout << "����� �������� ������������� �������\n";
	cin.get();
	getline(cin, ks.name);
	ks.N = getint("����� ���������� �����", 1, 10000);
	ks.Ninwork = getint("����� ���������� ����� � ������", 0, ks.N);
	ks.effect = getint("����� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)", 0, 10000);
	return ks;
}

void printKS(const KS& ks) // ����� ���������� � ������������� �������
{
	cout << "������ � ������������� �������:\n";
	cout << "��� ������������� �������: " << ks.name << endl;
	cout << "���������� ����� �� ������������� �������: " << ks.N << endl;
	cout << "���������� ����� � ������: " << ks.Ninwork << endl;
	cout << "������������� ������������� �������: " << ks.effect << endl;
}

void editKS(KS& ks) // ��������� ����� � ������
{
	ks.Ninwork = getint("����� ���������� ����� � ������", 0, ks.N);
}

void savefileKS(ofstream& fout, const KS& ks) // ���������� ���������� � ������������� �������
{
	fout << ks.name << endl;
	fout << ks.N << endl;
	fout << ks.Ninwork << endl;
	fout << ks.effect << endl;
}

KS inputfileKS(ifstream& fin) // ���������� ���������� � ������������� �������
{
	KS ks;
	fin >> ks.name;
	fin >> ks.N;
	fin >> ks.Ninwork;
	fin >> ks.effect;
	return ks;
}
