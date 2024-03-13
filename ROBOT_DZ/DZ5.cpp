#include <iostream>
using namespace std;


class Building {
public:

	Building(int _Id, int _MaxAge, int _InitialCost) : Id(_Id), MaxAge(_MaxAge), InitialCost(_InitialCost), currentAge(0) {}

	int GetCost() {

		if (MaxAge <= currentAge) return 0;
		else
			return InitialCost - (currentAge * InitialCost / MaxAge);
	}


	void ToAge(int years) {
		currentAge += years;
		if (MaxAge <= currentAge) { Destroy(); }
	}

private:
	void Destroy() {
		cout << "Building was destroyed. ID: " << Id << endl;
	}

private:
	int Id;
	int MaxAge;
	int InitialCost;
	int currentAge;

};


void DZ5() {

	Building building1(1, 80, 200000);
	cout << "Initial cost of building:" << building1.GetCost() << endl;

	building1.ToAge(20);
	cout << "Cost of building 1 after 10 years:" << building1.GetCost() << endl;

	building1.ToAge(70);
	cout << "Cost of building 1 after 70 years:" << building1.GetCost() << endl;


}