#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void game();		//Functions
void exit();
void gamestart();
void save(double sav[]);
double NA(double attack);
double SA(double attack);
double RE(double attack);
int random();
int randomcox();
int randomcoy();

int main()
{
	SYSTEM_INFO info;						//Get CPU info
	GetSystemInfo(&info);
	int corenum = info.dwNumberOfProcessors;
	cout << "Your CPU thread-number is " << corenum << " .\nYou can use this program.\n";
Menu:										//Main Menu
	int menu = 0;
	cout << "\n\n\n\n\nMenu\n[1]Start Game\n[2]About\n[3]Exit\n\n\n\n\n";
	cin >> menu;
	if (menu == 1)
	{
		game();
		goto Menu;
	}
	else if (menu == 2)
	{
		cout << "\n\n\n\n\n\n\nMade by Dongsheng\n\n\n\n\n\n\n";
		system("pause");
		goto Menu;
	}
	else if (menu == 3)
	{
		exit();
	}
	else
	{
		goto Menu;
	};
};

void game()								//Main game
{
	long int player_HP, coordinate[2], monster_coordinatex[4], monster_coordinatey[4], monster_type[4], level, talent, score, weapon1, weapon2, money, bag[8];		//Varies
	int  r[4];
	double monster_HP[4], attack, dam;
	char choice, background[30][29], move;
	double sav[34];

	ifstream fin("bob.save");
	if (!fin)												//New Game
	{
		gamestart();
		level = 0;
		talent = 0;
		score = 0;
		money = 0;
		attack = 20;
		weapon1 = 0;
		weapon2 = 0;
		player_HP = 100;
		coordinate[0] = 0;
		coordinate[1] = 4;
		monster_HP[0] = 0;
		monster_HP[1] = 0;
		monster_HP[2] = 0;
		monster_HP[3] = 0;
		bag[0] = 0;
		bag[1] = 0;
		bag[2] = 0;
		bag[3] = 0;
		bag[4] = 0;
		bag[5] = 0;
		bag[6] = 0;
		bag[7] = 0;
	}
	else
	{
	HaveSave:
		cout << "\n[1]Continue\n[2]Start a new game\n";		//Menu2
		choice = _getch();
		if (choice == '1')
		{
			ifstream infile;
			infile.open("bob.save");
			for (int x = 0; x < 34; x++)									//Read Save
			{
				infile >> sav[x];
			};
			infile.close();
			money = sav[0];
			level = sav[1];
			score = sav[2];
			weapon1 = sav[3];
			weapon2 = sav[4];
			talent = sav[5];
			attack = sav[6];
			player_HP = sav[7];
			coordinate[0] = sav[8];
			coordinate[1] = sav[9];
			monster_coordinatex[0] = sav[10];
			monster_coordinatex[1] = sav[11];
			monster_coordinatex[2] = sav[12];
			monster_coordinatex[3] = sav[13];
			monster_coordinatey[0] = sav[14];
			monster_coordinatey[1] = sav[15];
			monster_coordinatey[2] = sav[16];
			monster_coordinatey[3] = sav[17];
			monster_type[0] = sav[18];
			monster_type[1] = sav[19];
			monster_type[2] = sav[20];
			monster_type[3] = sav[21];
			monster_HP[0] = sav[22];
			monster_HP[1] = sav[23];
			monster_HP[2] = sav[24];
			monster_HP[3] = sav[25];
			bag[0] = sav[26];
			bag[1] = sav[27];
			bag[2] = sav[28];
			bag[3] = sav[29];
			bag[4] = sav[30];
			bag[5] = sav[31];
			bag[6] = sav[32];
			bag[7] = sav[33];
		}
		else if (choice == '2')								//New Game
		{
			gamestart();
			level = 0;
			talent = 0;
			score = 0;
			money = 0;
			attack = 20;
			weapon1 = 0;
			weapon2 = 0;
			player_HP = 100;
			coordinate[0] = 0;
			coordinate[1] = 4;
			monster_HP[0] = 0;
			monster_HP[1] = 0;
			monster_HP[2] = 0;
			monster_HP[3] = 0;
			bag[0] = 0;
			bag[1] = 0;
			bag[2] = 0;
			bag[3] = 0;
			bag[4] = 0;
			bag[5] = 0;
			bag[6] = 0;
			bag[7] = 0;
		}
		else
		{
			goto HaveSave;								//Goback
		};
	};
	while (1)
	{
		if (player_HP <= 0)
		{
			cout << "You are died.\nYour level:" << level << "\nYour score:" << score << endl;
			system("pause");
			system("del bob.save");
			main();
		}
		else
		{
			if (monster_HP[0] <= 0 && monster_HP[1] <= 0 && monster_HP[2] <= 0 && monster_HP[3] <= 0)		//Spawn monsters
			{
				level = level + 1;
				talent = talent + 1;
				for (int x = 0; x < 4; x = x + 1)
				{
					r[x] = random();
				};
				for (int x = 0; x < 4; x = x + 1)
				{
					if (r[x] > 5)																				//Monster x
					{
						monster_type[x] = 1;
						monster_HP[x] = 100;
					}
					else
					{
						monster_type[x] = 2;
						monster_HP[x] = 150;
					};
				}

				for (int x = 0; x < 4; x++)																	//Ensure Monster coordinate
				{
					monster_coordinatex[x] = randomcox();
				};
				for (int x = 0; x < 4; x++)
				{
					monster_coordinatey[x] = randomcoy();
				};
			}
			else
			{
				for (int y = 0; y < 9; y++)																	//Put Background
				{
					for (int x = 0; x < 30; x++)
					{
						background[x][y] = ' ';
					};
				};

				for (int x = 0; x < 30; x++)																//Put border
				{
					background[x][0] = 'X';
				};
				for (int x = 0; x < 30; x++)																//Put border
				{
					background[x][8] = 'X';
				};

				background[coordinate[0]][coordinate[1]] = '&';												//Put Player

				for (int x = 0; x < 4; x++)
				{
					if (monster_type[x] == 1)																	//Put Monster
					{
						background[monster_coordinatex[x]][monster_coordinatey[x]] = 'A';
					}
					else if (monster_type[x] == 2)
					{
						background[monster_coordinatex[x]][monster_coordinatey[x]] = 'B';
					};
				};

				cout << "Level:" << level << endl << "Coordinate	X:" << coordinate[0] << " Y:" << coordinate[1] << endl;									//Draw Main Picture
				for (int y = 0; y < 9; y++)
				{
					for (int x = 0; x < 30; x++)
					{
						cout << background[x][y];
					};
					cout << endl;
				};
				cout << "HP:" << player_HP << "			[" << weapon1 << "][" << weapon2 << "]\nScore:" << score << "\n[H]Shop    [T]Talent   [I]Info\n[G]Save Game 	[E]Exit\n\n";

			Move:
				move = _getch();
				if (move == 'w' || move == 'W')
				{
					coordinate[1] = coordinate[1] - 1;
				}
				else if (move == 'a' || move == 'A')
				{
					coordinate[0] = coordinate[0] - 1;
				}
				else if (move == 's' || move == 'S')
				{
					coordinate[1] = coordinate[1] + 1;
				}
				else if (move == 'd' || move == 'D')
				{
					coordinate[0] = coordinate[0] + 1;
				}
				else if (move == 'h' || move == 'H')
				{
					cout << "Shop\nYour money:" << money << "\n[E]Exit\n";
					choice = _getch();
					if (choice == 'e' || choice == 'E')
					{
					};
				}
				else if (move == 't' || move == 'T')
				{
					cout << "Talent\nYour talent:" << talent << "\n[E]Exit\n";
					choice = _getch();
					if (choice == 'e' || choice == 'E')
					{
					};
				}
				else if (move == 'i' || move == 'I')
				{
					cout << "You can see your level,talent,HP,monsters and etc. on this picture.\nYou may fight with monster by reaching them.\nYou will die if you reach the 'X'\n\nYou can go to shop by pressing'H'\nYou can go to talent by pressing'T'\nYou can see these info by pressing'I'\nYou can save the game by pressing'S'\nYou can exit by pressing'E'\n";
					system("pause");
				}
				else if (move == 'c' || move == 'C')
				{
					move = _getch();
					if (move == 'n' || move == 'N')
					{
						move = _getch();
						if (move == 'm' || move == 'M')
						{
							cout << "HP\nAttack\nMoney\nTalent\nLevel\n";
							cin >> player_HP >> attack >> money >> talent >> level;
						};
					};
				}
				else if (move == 'g' || move == 'G')
				{
					sav[0] = money;
					sav[1] = level;
					sav[2] = score;
					sav[3] = weapon1;
					sav[4] = weapon2;
					sav[5] = talent;
					sav[6] = attack;
					sav[7] = player_HP;
					sav[8] = coordinate[0];
					sav[9] = coordinate[1];
					sav[10] = monster_coordinatex[0];
					sav[11] = monster_coordinatex[1];
					sav[12] = monster_coordinatex[2];
					sav[13] = monster_coordinatex[3];
					sav[14] = monster_coordinatey[0];
					sav[15] = monster_coordinatey[1];
					sav[16] = monster_coordinatey[2];
					sav[17] = monster_coordinatey[3];
					sav[18] = monster_type[0];
					sav[19] = monster_type[1];
					sav[20] = monster_type[2];
					sav[21] = monster_type[3];
					sav[22] = monster_HP[0];
					sav[23] = monster_HP[1];
					sav[24] = monster_HP[2];
					sav[25] = monster_HP[3];
					sav[26] = bag[0];
					sav[27] = bag[1];
					sav[28] = bag[2];
					sav[29] = bag[3];
					sav[30] = bag[4];
					sav[31] = bag[5];
					sav[32] = bag[6];
					sav[33] = bag[7];
					save(sav);
					cout << "Saved\n";
				}
				else if (move == 'e' || move == 'E')
				{
					cout << "Sure to exit?\n[0]Yes\n[1]No\n";
					cin >> choice;
					if (choice == '0')
					{
						sav[0] = money;
						sav[1] = level;
						sav[2] = score;
						sav[3] = weapon1;
						sav[4] = weapon2;
						sav[5] = talent;
						sav[6] = attack;
						sav[7] = player_HP;
						sav[8] = coordinate[0];
						sav[9] = coordinate[1];
						sav[10] = monster_coordinatex[0];
						sav[11] = monster_coordinatex[1];
						sav[12] = monster_coordinatex[2];
						sav[13] = monster_coordinatex[3];
						sav[14] = monster_coordinatey[0];
						sav[15] = monster_coordinatey[1];
						sav[16] = monster_coordinatey[2];
						sav[17] = monster_coordinatey[3];
						sav[18] = monster_type[0];
						sav[19] = monster_type[1];
						sav[20] = monster_type[2];
						sav[21] = monster_type[3];
						sav[22] = monster_HP[0];
						sav[23] = monster_HP[1];
						sav[24] = monster_HP[2];
						sav[25] = monster_HP[3];
						sav[26] = bag[0];
						sav[27] = bag[1];
						sav[28] = bag[2];
						sav[29] = bag[3];
						sav[30] = bag[4];
						sav[31] = bag[5];
						sav[32] = bag[6];
						sav[33] = bag[7];
						save(sav);
						break;
					}
					else if (choice == '1')
					{
					};
				}
				else
				{
					goto Move;
				};

				if ((coordinate[1] == 0) || (coordinate[1] == 8))
				{
					cout << "\n\n\n\n\n\n\nYou are died.\n\n\n\n\n\n\n ";
					system("pause");
					break;
				};

				for (int x = 0; x < 4; x++)										//Fight!!
				{
					if ((coordinate[0] == monster_coordinatex[x]) && (coordinate[1] == monster_coordinatey[x]))
					{
						while (1)
						{
							if (player_HP <= 0)
							{
								break;
							}
							else
							{
								if (monster_HP[x] > 0)
								{
									if (monster_type[x] == 1)
									{
										cout << "\n\n\n\nMonster name:Unshowered Bob.\n";
									}
									else if (monster_type[x] == 2)
									{
										cout << "\n\n\n\nMonster name:Untoileted Bob\n";
									};
									cout << "Monster HP:" << monster_HP[x] << "	Your HP:" << player_HP << "\nChoose your skill\n[1]Normal Attack		[2]Skip Attack\n[3]Restore HP		[G]Save Game\n";
								ChooseSkill1:
									choice = _getch();
									if (choice == '1')
									{
										dam = NA(attack);
										monster_HP[x] = monster_HP[x] - dam;
										score = score + dam;
										cout << "Monster HP decreases " << dam << " .\n";
									}
									else if (choice == '2')
									{
										r[0] = random() % 9;
										if (r[0] >= 5)
										{
											dam = SA(attack);
											monster_HP[x] = monster_HP[x] - dam;
											score = score + dam;
											cout << "Monster HP decreases " << dam << " .\n";
										}
										else
										{
											dam = SA(attack);
											monster_HP[x] = monster_HP[x] - dam;
											score = score + dam;
											cout << "Monster HP decreases " << dam << " .\nYour skipped a round.\n";
											goto RoundEnd1;
										}
									}
									else if (choice == '3')
									{
										dam = RE(attack);
										player_HP = player_HP + dam;
										cout << "Your HP increases " << dam << " .\n";
									}
									else if (choice == 'g' || choice == 'G')
									{
										sav[0] = money;
										sav[1] = level;
										sav[2] = score;
										sav[3] = weapon1;
										sav[4] = weapon2;
										sav[5] = talent;
										sav[6] = attack;
										sav[7] = player_HP;
										sav[8] = coordinate[0];
										sav[9] = coordinate[1];
										sav[10] = monster_coordinatex[0];
										sav[11] = monster_coordinatex[1];
										sav[12] = monster_coordinatex[2];
										sav[13] = monster_coordinatex[3];
										sav[14] = monster_coordinatey[0];
										sav[15] = monster_coordinatey[1];
										sav[16] = monster_coordinatey[2];
										sav[17] = monster_coordinatey[3];
										sav[18] = monster_type[0];
										sav[19] = monster_type[1];
										sav[20] = monster_type[2];
										sav[21] = monster_type[3];
										sav[22] = monster_HP[0];
										sav[23] = monster_HP[1];
										sav[24] = monster_HP[2];
										sav[25] = monster_HP[3];
										sav[26] = bag[0];
										sav[27] = bag[1];
										sav[28] = bag[2];
										sav[29] = bag[3];
										sav[30] = bag[4];
										sav[31] = bag[5];
										sav[32] = bag[6];
										sav[33] = bag[7];
										save(sav);
										goto RoundEnd1;
									}
									else
									{
										goto ChooseSkill1;
									};
								}
								else if (monster_HP[x] <= 0)
								{
									cout << "\n\n\n\n\n\n\nMonster was killed.\n";
									if (monster_type[x] == 1)
									{
										money = money + 10;
										cout << "Your money increase 10.\n\n\n\n\n\n";
									}
									else if (monster_type[x] == 2)
									{
										money = money + 15;
										cout << "Your money increase 15.\n\n\n\n\n\n";
									};
									monster_coordinatex[x] = 0;
									monster_coordinatey[x] = 0;
									system("Pause");
									break;
								};
								player_HP = player_HP - 20;
								cout << "Your HP decreases 20.\n\n\n\n";
							RoundEnd1:
								system("pause");
							};		//Else (Monster has HP)
						};			//While (Main Fight)
					};				//If (Whether meet monster)	
				};					//Fight!
			};						//Else (Draw background and Fight!)
		};							//Else (Player has HP)
	};								//Main while
};									//Int Main

double NA(double attack)
{
	double dam;
	int r = random() % 9;
	if (r >= 5)
	{
		dam = attack;
		return dam;
	}
	else
	{
		dam = 2 * attack;
		return dam;
	};
};

double SA(double attack)
{
	double dam;
	int r = random() % 9;
	if (r >= 5)
	{
		dam = attack / 4;
		return dam;
	}
	else
	{
		dam = attack / 2;
		return dam;
	};
};

double RE(double attack)
{
	double dam;
	int r = random() % 9;
	if (r >= 5)
	{
		dam = 1.5 * attack;
		return dam;
	}
	else
	{
		dam = 2 * attack;
		return dam;
	};
};

void save(double sav[])
{
	ofstream outfile;
	outfile.open("bob.save");
	for (int x = 0; x < 34; x++)
	{
		outfile << sav[x] << endl;
	};
	outfile.close();
	cout << "Saved\n";
};

void gamestart()
{
	string player_name, story;
	ifstream infile;
	infile.open("story.txt");
	cout << "Input your name:";
	cin >> player_name;
	cout << "You are " << player_name << ".\n";
	Sleep(1000);
	for (int x = 0; x < 5; x++)
	{
		getline(inFile, buffTmp);
		cout << story << endl;
		Sleep(1000);
	};
	system("pause");
};

int random()
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	return rand() % 9;
};

int randomcox()
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	return rand() % (28 - 2 + 1) + 2;
};

int randomcoy()
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	return rand() % (7 - 1 + 1) + 1;
};

void exit()
{
	int ex;
	cout << "\nSure to exit?\n[0]Yes\n[1]No\n";
	cin >> ex;
	if (ex == 0)
	{
		exit(666);
	}
	else
	{
		main();
	};
}

//Function start with uncapital
//Goto start with capital
//varies start with uncapital
