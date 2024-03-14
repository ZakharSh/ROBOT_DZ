#include "DZ3.h"
#include<map>

struct Player {

	string name;
	float power = 0;
};

map<string, vector<Player>> clanData;


int GetPlayerCount(const string& ClanName) {
	if (clanData.find(ClanName) != clanData.end()) {
		return clanData[ClanName].size();
	}
	else {
		cout << "No such clan";
		return 0;
	}
}



int ClanFight(const string& FirstClanName, const string& SecondClanName) {
	float firstClanStrength = 0;
	float secondClanStrength = 0;

	if (clanData.find(FirstClanName) != clanData.end()) {
		for (const auto& player : clanData[FirstClanName]) {
			firstClanStrength += player.power;
		}
	}

	if (clanData.find(SecondClanName) != clanData.end()) {
		for (const auto& player : clanData[SecondClanName]) {
			secondClanStrength += player.power;
		}
	}

	if (firstClanStrength > secondClanStrength) {
		return 1;
	}
	else if (secondClanStrength > firstClanStrength) {
		return -1;
	}
	else {
		return 0;
	}
}



void DZ4() {

	string clan, playerName;
	float powerOfPlayer;

	while (true) {
		cout << "Enter the name of the clan(or type 'end' to exit) :";
		cin >> clan;
		if (clan == "end") { break; }

		Player player;
		cout << "Enter the name of the player: ";
		cin >> playerName;
		player.name = playerName;

		cout << "Enter the power of the player: ";
		cin >> powerOfPlayer;
		player.power = powerOfPlayer;

		clanData[clan].push_back(player);
	}

	cout << endl << "The amount of members in the clan. Enter the name of the clan: " << endl;
	cin >> clan;
	cout << "The amount of members: " << GetPlayerCount(clan);

	string FirstClan, SecondClan;
	cout << endl << "----The Fight between two clans----";
	cout << "The name of the first clan: ";
	cin >> FirstClan;
	cout << "The name of the second clan: ";
	cin >> SecondClan;
	int result = ClanFight(FirstClan, SecondClan);
	if (result == 1) {
		cout << "THE WINNER IS - " << FirstClan << endl;
	}
	else if (result == -1) {
		cout << "THE WINNER IS - " << SecondClan << endl;
	}
	else {
		cout << "DRAW" << endl;
	}

}