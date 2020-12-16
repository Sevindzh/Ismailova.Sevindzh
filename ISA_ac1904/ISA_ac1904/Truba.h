#pragma once
#include <string>
#include <iostream>

class Truba
{
	static unsigned int IDt;
	unsigned int id; // �������������
	double dlina; // �����
	int diametr; // �������
	

public:
	/* static Truba createTruba(); // �������� �����
	friend void printTruba(const Truba& t); // ����� ���������� � ������������� �������
	friend void editTruba(Truba& t); // ��������� ����� � ������ */

	std::string name; // ��������
	bool sostoyanie; // ��������� � ������� ��� ���
	friend std::istream& operator >> (std::istream& in, Truba& t); // �������� �����
	friend std::ostream& operator << (std::ostream& out, const Truba& t); // ����� ���������� � �����
	void editTruba(); // ��������� ����� � ������
	void savefileTruba(std::ofstream& fout); // ���������� ���������� � ������������� �������
	void inputfileTruba(std::ifstream& fin);

	/* static Truba inputfileTruba(std::ifstream& fin); // ���������� ���������� � ������������� �������
	friend void selectTruba(vector<Truba>& Truboprovod); // ����� �����
	friend void SearchTrubaByName(const Truba& t, std::string parametr); // ����� �� ��������
	friend void SearchTrubaBySostoyanie(const Truba& t, double parametr); // ����� �� ���������
	*/
};

