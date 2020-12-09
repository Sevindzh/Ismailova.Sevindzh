#pragma once
#include <string>

class KS
{
	static unsigned int IDks;
	std::string name;
	unsigned int id; // �������������
	int N; // ���������� �����
	int Ninwork; // ���������� ����� � ������
	int effect; // �������������

public:
		friend KS createKS(); // �������� ������������� �������
		friend void printKS(const KS& ks); // ����� ���������� � ������������� �������
		friend void editKS(KS& ks); // ��������� ����� � ������
		friend void savefileKS(std::ofstream& fout, const KS& ks); // ���������� ���������� � ������������� �������
		friend KS inputfileKS(std::ifstream& fin); // ���������� ���������� � ������������� �������
};

