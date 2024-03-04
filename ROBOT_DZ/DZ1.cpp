#include"DZ1.h"

void DZ1() {
	cout << "Create character" << endl;

	cout << "Your name: ";
	string name;
	cin >> name;

	cout << "Amount of Health: ";
	int MaxHealth = 0;
	cin >> MaxHealth;


	cout << "Choose your class(1 - Mage; 2 - Warrior): ";
	ClassCharacter yourClass;
	int yourClassInt;
	cin >> yourClassInt;
	switch (yourClassInt) {
	case 1: {
		yourClass = Mage;
		break;
	}
	case 2: {
		yourClass = Warrior;
		break;
	}
	default: {
		cout << "ERROR!!! TRY AGAIN!!!";
		return;
	}
	}

	cout << "Level of Power:";
	int Power;
	cin >> Power;

	cout << endl << "------------------------------------" << endl << endl;
	cout << "OH NO! The Dragon is attacking you!" << endl;
	int currentHealth = MaxHealth;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);
	random_device rd2;
	mt19937 gen2(rd2());
	uniform_int_distribution<> dis2(0, 1);
	switch (yourClass) {
	case Mage: {
		while (currentHealth >= 0) {
			cout << "I am alive. Health: " << currentHealth << endl;
			int DamageByDragon = dis(gen);
			cout << "The Dragon is casting a spell. Damage of Spell: " << DamageByDragon << endl;

			int chance = dis2(gen);



			if (DamageByDragon % 2 == 0) {
				if (DamageByDragon * 2 > Power * 2 && chance == 1) {
					cout << "MISS!!!" << endl;
					continue;
				}
				currentHealth = currentHealth - (2 * DamageByDragon);
				cout << "Critical hit(x2): " << 2 * DamageByDragon << endl;
			}
			else
			{
				if (DamageByDragon > Power * 2 && chance == 1) {
					cout << "MISS!!!" << endl;
					continue;
				}
				currentHealth = currentHealth - (DamageByDragon);
				cout << "Damage taken: " << DamageByDragon << endl;
			}

		}
		break;
	}
	case Warrior: {
		while (currentHealth >= 0) {
			cout << "I am alive. Health: " << currentHealth << endl;
			int DamageByDragon = dis(gen);
			cout << "The Dragon is casting a spell. Damage of Spell: " << DamageByDragon << endl;

			if ((currentHealth * 100) / MaxHealth <= 30) {
				if (DamageByDragon % 2 > 0) {
					currentHealth = currentHealth - (3 * DamageByDragon) + Power;
					cout << "Critical hit(x3) - Power: " << (3 * DamageByDragon) - Power << endl;
				}
				else
				{
					cout << "HAHA!! THE DRAGON IS MISSED" << endl;
				}
				continue;
			}
			else
			{
				if (DamageByDragon % 2 > 0) {
					currentHealth = currentHealth - (3 * DamageByDragon);
					cout << "Critical hit(x3): " << 3 * DamageByDragon << endl;
				}
				else
				{
					cout << "HAHA!! THE DRAGON IS MISSED" << endl;
				}

			}

		}
		break;
	}
	}
	cout << "YOU DIED";

}

