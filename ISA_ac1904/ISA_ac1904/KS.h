#pragma once
#include <string>
#include <vector>

class KS
{
	static unsigned int IDks;
	unsigned int id; // �������������
	int effect; // �������������

public:
	
		std::string name; // ��������
		int N; // ���������� �����
		int Ninwork; // ���������� ����� � ������

		/*static KS createKS(); // �������� ������������� �������
		friend void printKS(const KS& ks); // ����� ���������� � ������������� �������
		friend void editKS(KS& ks); // ��������� ����� � ������*/
		
		friend std::istream& operator >> (std::istream& in, KS& ks); // �������� ������������� �������
		friend std::ostream& operator << (std::ostream& out, const KS& ks); // ����� ���������� � ������������� �������
		void editKS(); // ��������� ����� � �����e
 		void savefileKS(std::ofstream& fout); // ���������� ���������� � ������������� �������
		void inputfileKS(std::ifstream& fin); // ���������� ���� � ������������� �������

		/* static KS inputfileKS(std::ifstream& fin); // ���������� ���������� � ������������� �������
		friend KS& selectKS(vector<KS>& Zavod); // ����� ������������� �������
		friend void deleteKS(vector<KS>& Zavod); // �������� ������������� �������
		friend bool SearchKSByName(const KS& ks, std::string parametr); // ����� �� ��������
		friend bool SearchKSByNinwork(const KS& ks, double parametr); // ����� �� ���������� ����� �� % */
		
};

