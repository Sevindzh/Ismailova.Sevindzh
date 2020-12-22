#pragma once
#include <string>
#include <vector>

class KS
{
	unsigned int id; // �������������
	std::string name; // ��������
	int N; // ���������� �����
	int Ninwork; // ���������� ����� � ������
	int effect; // �������������

public:

	float pometka = 0;
	int pred;
	static unsigned int IDks;
	friend std::istream& operator >> (std::istream& in, KS& ks); // �������� ������������� �������
	friend std::ostream& operator << (std::ostream& out, const KS& ks);  // ����� ���������� � ������������� �������
	void editKS(); // ��������� ����� � ������
	void savefileKS(std::ofstream& fout); // ���������� ���������� � ������������� �������
	void inputfileKS(std::ifstream& fin); // ���������� ���������� � ������������� �������
	std::string getname(); // ����������� ��������
	int getN(); // ����������� ���������� �����
	int getNinwork(); // ����������� ���������� ����� � ������
	unsigned int getid(); // ����������� id
};


