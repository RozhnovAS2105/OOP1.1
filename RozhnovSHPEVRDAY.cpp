#include "RozhnovSHPEVRDAY.h"


using namespace std;

void RozhnovSHPEVRDAY::AddCustomer()
{
	string name;
	int age;
	double avg_check;

	cout << "Введите имя: ";
	cin.ignore();
	getline(cin, name);

	cout << "Введите возраст: ";
	cin >> age;

	cin.ignore();
	cout << "Введите среднее значение чека: ";
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
	

	cout << "Введите название файла для чтения: ";
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

		cout << "Данные успешно прочитаны!" << endl;
	}
	else cout << "Не удалось открыть файл!" << endl;
}

void RozhnovSHPEVRDAY::FileSave()
{
	string FileName;

	cout << "Введите название файла для сохранения: ";
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

		cout << "Файл успешено сохранен!" << endl;
	}

	//OutData.close();

	//cout << "Файл успешено сохранен!" << endl;
}

void RozhnovSHPEVRDAY::ClearCustomersList()
{
	for (RozhnovStudent* Visitor : Visitors)
	{
		delete Visitor;

	}
	Visitors.clear();
	cout << "Список студентов очищен!" << endl;
}


