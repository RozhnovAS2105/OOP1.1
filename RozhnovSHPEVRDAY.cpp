#include "RozhnovSHPEVRDAY.h"


using namespace std;

void RozhnovSHPEVRDAY::AddCustomer()
{
	string name;
	int age;
	double avg_check;

	cout << "������� ���: ";
	cin.ignore();
	getline(cin, name);

	cout << "������� �������: ";
	cin >> age;

	cin.ignore();
	cout << "������� ������� �������� ����: ";
	cin >> avg_check;
	RozhnovStudent* Visitor = new RozhnovStudent(name, age, avg_check);
	Visitors.push_back(Visitor);
}

void RozhnovSHPEVRDAY::ShowCustomersList()
{
	cout << "------------------------------" << endl;
	if (Visitors.size() > 0)
	{
		for (const auto& Visitor : Visitors)
		{
			Visitor->ShowData();
		}
	}
	cout << "------------------------------" << endl;
}

void RozhnovSHPEVRDAY::FileRead()
{
	//Visitors.clear();
	int CustomersAmount;
	string FileName;
	

	cout << "������� �������� ����� ��� ������: ";
	cin.ignore();
	getline(cin, FileName);
	ifstream InData;
	InData.open(FileName);

	if (InData.is_open())
	{
		
		InData >> CustomersAmount;
		for (int i = 0; i < CustomersAmount; i++)
		{
			RozhnovStudent Customer;
			InData >> Customer;
			RozhnovStudent* Visitor = new RozhnovStudent;
			//Customer.ReadFile(InData);
			*Visitor = Customer;
			Visitors.push_back(Visitor);
			Visitor->ShowData();
		}

		InData.close();

		cout << "������ ������� ���������!" << endl;
	}
	else cout << "�� ������� ������� ����!" << endl;
}

void RozhnovSHPEVRDAY::FileSave()
{
	string FileName;

	cout << "������� �������� ����� ��� ����������: ";
	cin >> FileName;
	ofstream OutData(FileName);
	if(OutData.is_open())
	{
		OutData << Visitors.size() << endl;
		for (auto Visitor : Visitors)
		{
			OutData << *Visitor;
		}
		OutData.close();

		cout << "���� �������� ��������!" << endl;
	}

	//OutData.close();

	//cout << "���� �������� ��������!" << endl;
}

void RozhnovSHPEVRDAY::ClearCustomersList()
{
	for (RozhnovStudent* Visitor : Visitors)
	{
		delete Visitor;

	}
	Visitors.clear();
	cout << "������ ��������� ������!" << endl;
}


