#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;enum Specialty { ��, ��, ��, ��, Բ };string strSpecialty[] = { "��","��","��","��","Բ" };struct Student{	string prizv;	Specialty specialty;	short unsigned kurs;	short unsigned physics;	short unsigned math;	union	{		short unsigned programming;		short unsigned methods;		short unsigned pedagogika;	};};void Create(Student* s, const int N);void Print(Student* s, const int N);double BestAverage(Student* s, const int N);double physics_five_four(Student* s, const int N);void Sort(Student* s, const int N);int* IndexSort(Student* p, const int N);void PrintIndexSorted(Student* s, int* I, const int N);int BinSearch(Student* s, const int N, const string prizv, double avg, short unsigned math);int main(){	SetConsoleCP(1251);	SetConsoleOutputCP(1251);	int N, MenuItem, found, math_mark;	double avg;	string prizv;	cout << "������ ������� ��������: "; cin >> N;	Student* s = new Student[N];	int menuItem;
	do {
		cout << "������� ��:" << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� ���������� ���������� ���� �������� �������� �� �������� � ������ " << char(34) << "4" << char(34) << " ��� " << char(34) << "5" << char(34) << endl;
		cout << " [4] - ������� ������������� �����" << endl;
		cout << " [5] - �������� ������������� �� ���� �����" << endl;
		cout << " [6] - ������� ����� ��������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl;
		cout << "������ ����� ����: "; cin >> menuItem;
		switch (menuItem)		{		case 1:			Create(s, N);			cout << "����� ��������" << endl;			break;		case 2:			Print(s, N);			break;		case 3:			cout << "================================================================================" << endl;			cout << "| ��������� ������� ���: " << fixed << setprecision(2) << BestAverage(s, N) << setw(49) << "|" << endl;			cout << "| ������� �������� �� �������� � ������ " << char(34) << "4" << char(34) << " ��� " << char(34) << "5" << char(34) << ": " << fixed << setw(6) << setprecision(2) << physics_five_four(s, N) << "%" << setw(18) << "|" << endl;			cout << "================================================================================" << endl;			break;		case 4:			Sort(s, N);			cout << "����� ������������" << endl;			break;		case 5:			PrintIndexSorted(s, IndexSort(s, N), N);			break;		case 6:			cout << "������ ����� ������:" << endl;
			cin.get();
			cin.sync();
			cout << " �������: ";
			getline(cin, prizv);
			cout << " ������� ��� (� ������� �� ���� ����� ���� ����): ";
			cin >> avg;
			cout << " ��� � ����������: "; cin >> math_mark;
			cout << endl;
			if ((found = BinSearch(s, N, prizv, avg, math_mark)) != -1)
				cout << "�������� �������� � ������� " << found + 1 << endl;
			else
				cout << "�������� �������� �� ��������" << endl;
			break;		case 0:			break;		default:
			cout << "[�������] �� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;		}
		cout << endl;	} while (menuItem != 0);	delete[] s;}void Create(Student* s, const int N){	int kurs, specialty;	for (int i = 0; i < N; i++)	{		cout << "������� " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  �������: "; getline(cin, s[i].prizv);
		cout << "  ����: "; cin >> s[i].kurs;
		do
		{
			cout << "  ������������ (0 - ����'����� �����, 1 - ���������� �� ��������, 2 - ������� ��������, 3 - �����������, 4 - Գ���� �� �����������): "; cin >> specialty;
		} while (specialty != 0 && specialty != 1 && specialty != 2 && specialty != 3 && specialty != 4);
		s[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> s[i].physics;
		cout << "  ������ � ����������: "; cin >> s[i].math;
		switch (specialty)		{		case 0:			cout << "  ������ � �������������: "; cin >> s[i].programming;			break;		case 3:			cout << "  ������ � ��������� ������: "; cin >> s[i].methods;			break;		case 1:		case 2:		case 4:			cout << "  ������ � ���������: "; cin >> s[i].pedagogika;			break;		}	}}void Print(Student* s, const int N)
{
	cout << "================================================================================================================="
		<< endl;
	cout << "| �  | �������     | ���� | ������������ | Գ���� | ���������� | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "     ";
			switch (s[i].specialty)
			{			case 0:				cout << "| " << setw(7) << right << s[i].programming << "       |" << setw(18) << "|" << setw(13) << "|" << endl;				break;			case 3:				cout << "| " << setw(15) << "|" << setw(10) << right << s[i].methods << "       |" << setw(13) << "|" << endl;				break;			case 1:			case 2:			case 4:				cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedagogika << "     |" << endl;				break;			}
	}
	cout << "=================================================================================================================" << endl;
}double BestAverage(Student* s, const int N){	double best = 0;	double tmp;	for (int i = 0; i < N; i++)	{			tmp = (s[i].physics + s[i].math + s[i].programming) / 3.;			if (tmp > best)				best = tmp;	}	return best;}double physics_five_four(Student* s, const int N){	int k = 0;	for (int i = 0; i < N; i++)		if (s[i].physics == 4 || s[i].physics == 5)			k++;	return 100.0 * k / N;}void Sort(Student* s, const int N){	Student tmp;
	double si1, si2;

	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
				si1 = (s[i1].physics + s[i1].math + s[i1].programming) / 3.;
				si2 = (s[i1 + 1].physics + s[i1 + 1].math + s[i1 + 1].programming) / 3.;
				if (
					(si1 > si2)
					|| (si1 == si2 && s[i1].math > s[i1 + 1].math)
					|| (si1 == si2 && s[i1].math == s[i1 + 1].math && s[i1].prizv > s[i1 + 1].prizv)
					)
				{
					tmp = s[i1];
					s[i1] = s[i1 + 1];
					s[i1 + 1] = tmp;			}		}}int* IndexSort(Student* s, const int N)
{
	double sIj, svalue;
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;
	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = I[i];
		j = i - 1;
			
			svalue = (s[value].physics + s[value].math + s[value].programming) / 3.;
			for (;
				j >= 0 && (
					((s[I[j]].physics + s[I[j]].math + s[I[j]].programming) / 3. > svalue)
					||
					((s[I[j]].physics + s[I[j]].math + s[I[j]].programming) / 3. == svalue && s[I[j]].math > s[value].math)
					||
					((s[I[j]].physics + s[I[j]].math + s[I[j]].programming) / 3. == svalue && s[I[j]].math == s[value].math && s[I[j]].prizv > s[value].prizv)
					);
				j--)
			{
				I[j + 1] = I[j];
			}
				I[j + 1] = value;
		}
	return I;
}void PrintIndexSorted(Student* s, int* I, const int N)
{
	cout << "================================================================================================================="
		<< endl;
	cout << "| �  | �������     | ���� | ������������ | Գ���� | ���������� | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[I[i]].prizv
			<< "| " << setw(3) << right << s[I[i]].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[I[i]].specialty] << "      "
			<< "| " << setw(4) << right << s[I[i]].physics << "   "
			<< "| " << setw(6) << right << s[I[i]].math << "     ";
		switch (s[i].specialty)
		{
		case 0:
			cout << "| " << setw(7) << right << s[I[i]].programming << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
			break;
		case 3:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[I[i]].methods << "       |" << setw(13) << "|" << endl;
			break;
		case 1:
		case 2:
		case 4:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[I[i]].pedagogika << "     |" << endl;
			break;
		}
	}
	cout << "================================================================================================================="
		<< endl;
	cout << endl;
}int BinSearch(Student* s, const int N, const string prizv, double  avg, short unsigned math)
{
	int L = 0, R = N - 1, m;
	double average;
	do {
		m = (L + R) / 2;
		average = round((s[m].physics + s[m].math + s[m].programming) / 3.0 * 100) / 100.0;
		if (s[m].prizv == prizv && average == avg && s[m].math == math)
			return m;
		if (
			(average < avg)
			|| (average == avg && s[m].math < math)
			|| (average == avg && s[m].math == math && s[m].prizv < prizv)
			)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}