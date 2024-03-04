#include "DZ3.h"



int Powerful(vector<Character>& characters) {
	int strongestID = -1;
	float maxPower = -1;
	for (const Character& Info : characters) {
		float power = Info.meleePower + Info.rangePower;
		if (power > maxPower) {
			maxPower = power;
			strongestID = Info.ID;
		}
	}
	return strongestID;
}

int PowerfulWarrior(vector<Character>& characters) {
	int strongestID = -1;
	float maxPower = -1;
	for (const Character& Info : characters) {
		float power = Info.meleePower + Info.rangePower;
		if (power > maxPower && Info.Class == ClassCharacter::Warrior) {
			maxPower = power;
			strongestID = Info.ID;
		}
	}
	return strongestID;
}

int PowerfulMage(vector<Character>& characters) {
	int strongestID = -1;
	float maxPower = -1;
	for (const Character& Info : characters) {
		float power = Info.meleePower + Info.rangePower;
		if (power > maxPower && Info.Class == ClassCharacter::Mage) {
			maxPower = power;
			strongestID = Info.ID;
		}
	}
	return strongestID;
}


void DZ3() {
	int num;
	cout << "Enter amount of characters: ";
	cin >> num;

	vector<Character> characters(num);

	for (int i = 0; i < num; ++i) {
		cout << endl << "Create a new character: " << endl;
		cout << "ID: ";
		cin >> characters[i].ID;
		cout << "Class: ";
		int ClassNum;
		cin >> ClassNum;
		characters[i].Class = static_cast<ClassCharacter>(ClassNum);
		cout << "Melee power: ";
		cin >> characters[i].meleePower;
		cout << "Range power: ";
		cin >> characters[i].rangePower;
	}

	cout << Powerful(characters) << " Character is the most powerful" << endl;
	cout << PowerfulWarrior(characters) << " Character is the most powerful Warrior" << endl;
	cout << PowerfulMage(characters) << " Character is the most powerful Mage" << endl;

}