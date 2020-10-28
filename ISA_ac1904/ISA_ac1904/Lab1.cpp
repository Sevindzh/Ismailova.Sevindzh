#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Truba//�����
{
	string id; // �������������
	double dlina; // �����
	int diametr; // �������
	bool sostoyanie; // ��������� � ������� ��� ���

};
struct KS // ������������� �������
{
	string name; // ���
	string id; // �������������
	int N; // ���������� �����
	int Ninwork; // ���������� ����� � ������
	int effect; // �������������
};
template <typename T>
T getint(string text, T border1, T border2 = 100)
{
	T value;
	while (1)
	{
		cout << text << endl;
		cin >> value;
		if (cin.fail() || value < border1 || value >border2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. �������� ��� ���.\n";
		}
		else
		{
			return value;
		}
	}

}
Truba creatTruba() // �������� �����
{
	Truba t;
	t.id = "1";
	t.dlina = getint("����� ����� ����� (������� ���������: �)", 1.0);
	t.diametr = getint("����� ������� �����(������� ��������� : ��)", 1);
	t.sostoyanie = false;
	return t;
}
KS creatKS() // �������� ������������� �������
{
	KS ks;
	cout << "����� ��� ������������� �������\n";
	cin.get();
	getline(cin, ks.name);
	ks.N = getint("����� ���������� �����", 1);
	ks.Ninwork = getint("����� ���������� ����� � ������", 0, ks.N);
	ks.effect = getint("����� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)", 0);
	return ks;
}
void printTruba(const Truba& t) // ����� ���������� � �����
{
	cout << "������ � �����:\n";
	cout << "����� �����: " << t.dlina << " (�)" << endl;
	cout << "������� �����: " << t.diametr << " (��)" << endl;
	cout << "��������� �����: " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
}
void printKS(const KS& ks) // ����� ���������� � ������������� �������
{
	cout << "������ � ������������� �������:\n";
	cout << "��� ������������� �������: " << ks.name << endl;
	cout << "���������� ����� �� ������������� �������: " << ks.N << endl;
	cout << "���������� ����� � ������: " << ks.Ninwork << endl;
	cout << "������������� ������������� �������: " << ks.effect << endl;
}
void editTruba(Truba& t) // ��������� ����� � ������
{
	t.sostoyanie = !t.sostoyanie;
}
void editKS(KS& ks) // ��������� ����� � ������
{
	ks.Ninwork = getint("����� ���������� ����� � ������", 0, ks.N);
}
void savefileTruba(ofstream& fout, const Truba& t) // ���������� ���������� � �����
{
	fout << t.id << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}
Truba inputfileTruba(ifstream& fin) // ���������� ���������� � �����
{
	Truba t;
	fin >> t.id;
	fin >> t.dlina;
	fin >> t.diametr;
	fin >> t.sostoyanie;
	return t;
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
Truba& selectTruba(vector<Truba>& Truboprovod)
{
	unsigned int index = getint("������� ����� �����", 1u, Truboprovod.size());
	return Truboprovod[index - 1];
}
KS& selectKS(vector<KS>& Zavod)
{
	unsigned int index = getint("����� ����� ������������� �������", 1u, Zavod.size());
	return Zavod[index - 1];
}
void printmenu()
{
	cout << "1-�������� �����\n";
	cout << "2-�������� ������������� �������\n";
	cout << "3-������� ���������� � ����� � ������������� �������\n";
	cout << "4-������������� ��������� �����\n";
	cout << "5-������������� ����������� ����� � ������ ������������� �������\n";
	cout << "6-��������� ������ ����\n";
	cout << "7-������� ������ �� �����\n";
	cout << "0-�����\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Truba> Truboprovod;
	vector <KS> Zavod;
	while (1)
	{
		printmenu();
		int i;
		i = getint("����� ����� ��������", 0);
		switch (i)
		{
		case 1:
		{
			Truboprovod.push_back(creatTruba());
			break;
		}
		case 2:
		{
			Zavod.push_back(creatKS());
			break;
		}
		case 3:
		{
			if (Truboprovod.size() > 0 || Zavod.size() > 0)
			{
				if (Truboprovod.size() > 0)
				{
					printTruba(selectTruba(Truboprovod));
				}
				else
				{
					cout << "����� �� �������.\n";
				}
				if (Zavod.size() > 0)
				{
					printKS(selectKS(Zavod));
				}
				else
				{
					cout << "������������� ������� �� �������.\n";
				}
				break;

			}
			else
			{
				cout << "����� ��� ������������� ������� �� �������. �������� ��� ���.\n";
				break;
			}
		}
		case 4:
		{
			if (Truboprovod.size() > 0)
			{
				editTruba(selectTruba(Truboprovod));
				break;
			}
			else
			{
				cout << "����� �� �������. �������� ��� ���.\n";
				break;
			}
		}
		case 5:
		{
			if (Zavod.size() > 0)
			{
				editKS(selectKS(Zavod));
				break;
			}
			else
			{
				cout << "������������� ������� �� �������. �������� ��� ���.\n";
				break;
			}
		}
		case 6:
		{
			if (Truboprovod.size() > 0 || Zavod.size() > 0)
			{
				ofstream fout;
				fout.open("info.txt", ios::out);
				if (fout.is_open())
				{
					fout << Truboprovod.size() << endl;
					fout << Zavod.size() << endl;
					if (Truboprovod.size() > 0)
					{
						for (Truba infotruba : Truboprovod)
						{
							savefileTruba(fout, infotruba);
						}
					}
					if (Zavod.size() > 0)
					{
						for (KS infoKS : Zavod)
						{
							savefileKS(fout, infoKS);
						}
					}
					fout.close();
				}
				break;
			}
			else
			{
				cout << "����� ��� ������������� ������� �� �������. �������� ��� ���.\n";
				break;
			}
		}
		case 7:
		{
			ifstream fin;
			fin.open("info.txt", ios::in);
			if (fin.is_open())
			{
				int countt;
				int countks;
				fin >> countt;
				fin >> countks;
				Truba infotruba;
				KS infoKS;
				if (countt > 0)
				{
					while (countt--)
					{
						infotruba = inputfileTruba(fin);
						Truboprovod.push_back(infotruba);
					}
				}
				if (countks)
				{
					while (countks--)
					{
						infoKS = inputfileKS(fin);
						Zavod.push_back(infoKS);
					}
				}
			}
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "������ ������� �� ���������. �������� ��� ���.";
		}
		}
	}
}
