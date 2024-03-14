#include <iostream>
using namespace std;

class Weapon {
public:
	virtual float GetDamage() = 0;

	virtual string GetName() = 0;

};

class DamageModifier {
public:
	DamageModifier() = default;
	virtual float CalculateDamage(float damage) const = 0;
};


class Sword : public Weapon {
public:
	virtual float GetDamage() { return Damage; }

	virtual string GetName() { return Name; }

private:
	float Damage = 50;
	string Name = "Sword";
};

class Knife : public Weapon {
public:
	virtual float GetDamage() { return Damage; }

	virtual string GetName() { return Name; }

private:
	float Damage = 20;
	string Name = "Knife";
};

class Greatsword : public Weapon {
public:
	virtual float GetDamage() { return Damage; }

	virtual string GetName() { return Name; }

private:
	float Damage = 100;
	string Name = "Greatsword";
};



class NewCharacter {
public:
	void SetWeapon(Weapon* weapon) { MyWeapon = weapon; }

	Weapon* GetWeapon() const { return MyWeapon; }

	float GetModifiedDamage(float damage) const {
		if (MyModifier)
			return MyModifier->CalculateDamage(damage);
		else
			return damage;
	}

	void SetDamageModifier(DamageModifier* modifier) { MyModifier = modifier; }


private:
	Weapon* MyWeapon;
	DamageModifier* MyModifier;

};




class MultiplicationDamageModifier : public DamageModifier {
public:
	MultiplicationDamageModifier(float multiplicator) : multiplicator(multiplicator) {}
	virtual float CalculateDamage(float damage) const override {
		return damage * multiplicator;
	}

private:
	float multiplicator;
};


class AdditionDamageModifier : public DamageModifier {
public:
	AdditionDamageModifier(float addition) : addition(addition) {}
	virtual float CalculateDamage(float damage) const override {
		return max(damage + addition, 0.0f);
	}

private:
	float addition;
};


class ParityDamageModifier : public DamageModifier {
public:
	ParityDamageModifier(float multiplicator) : multiplicator(multiplicator) {}
	virtual float CalculateDamage(float damage) const override {
		int dam = damage;
		if (dam % 2 == 0)
			return damage * multiplicator;
		else
			return damage;
	}

private:
	float multiplicator;
};



void DZ6() {

	NewCharacter Bob;
	Weapon* greatsword = new Greatsword;
	Bob.SetWeapon(greatsword);
	cout << "Bob`s weapon is " << Bob.GetWeapon()->GetName() << endl << "Damage = " << Bob.GetWeapon()->GetDamage() << endl;

	DamageModifier* modifier = new ParityDamageModifier(2);


	Bob.SetDamageModifier(modifier);


	cout << "Modified Damage: " << Bob.GetModifiedDamage(Bob.GetWeapon()->GetDamage());

	delete greatsword;
	delete modifier;


}