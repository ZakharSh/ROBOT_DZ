#include"Header_DZ2.h"

void MaxDamage(array<int, 5> arr) {
	int maxIndex = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
	{
		if (arr[maxIndex] < arr[i + 1]) {
			maxIndex = i + 1;
		}
	}
	cout << endl << maxIndex + 1 << " Character casted the most dangerous spell" << endl;
}


void MinDamage(array<int, 5> arr) {
	int minIndex = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
	{
		if (arr[minIndex] > 0) {
			if (arr[minIndex] > arr[i + 1] && arr[i + 1] > 0) {
				minIndex = i + 1;
			}
		}
		else {
			minIndex = i + 1;
		}

	}
	cout << endl << minIndex + 1 << " Character casted the less dangerous spell" << endl;
}

void Healing(array<int, 5> arr) {
	int heal = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
	{
		if (arr[heal] < 0) {

			if (arr[heal] > arr[i + 1]) {
				heal = i + 1;
			}
		}
		else {
			heal = i + 1;
		}

	}
	cout << endl << heal + 1 << " Character casted the best healing spell" << endl;

}

void Suma(array<int, 5> arr, int damageHeal) {
	int suma = 0;
	if (damageHeal == 1) {
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			if (arr[i] > 0) {
				suma = suma + arr[i];
			}
		}
		cout << endl << "Full damage = " << suma << endl;

	}
	else
	{
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			if (arr[i] < 0) {
				suma = suma + arr[i];
			}
		}
	}
	cout << endl << "Full heal = " << suma * -1 << endl;
}


void IsZero(array<int, 5> arr) {
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i] == 0) {
			cout << "OPA NOLIK" << endl;
		}
	}

}




void DZ2() {

	array<int, 5> arr = { 0 };
	cout << "5 Characters are going to cast spells on you" << endl;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << endl << i + 1 << " Character is casting the spell on you: ";
		cin >> arr[i];
	}

	MaxDamage(arr);
	MinDamage(arr);
	Healing(arr);

	int check;
	cout << "Full damage(1) or full heal(2)?" << endl;
	cin >> check;
	Suma(arr, check);
	IsZero(arr);
}