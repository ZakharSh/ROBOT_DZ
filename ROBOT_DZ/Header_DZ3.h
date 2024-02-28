#pragma once

#include "Header_DZ1.h"
#include<iostream>
#include <random>
#include <vector>

using namespace std;

struct Character {
	int ID;
	ClassCharacter Class;
	float meleePower;
	float rangePower;
};

int Powerful(vector<Character>& characters);

int PowerfulWarrior(vector<Character>& characters);

int PowerfulMage(vector<Character>& characters);

void DZ3();
