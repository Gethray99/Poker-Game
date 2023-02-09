#include<iostream>
#include"Header.h"
#include<ctime>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>

using namespace std;



void Card_pack::assign_cards()
{

	int cards[53];

	for (int i = 1;i <= 52;i++)
	{
		cards[i] = i;
	}

	for (int i = 1;i < 52;i++)
	{
		srand(time(0));
		int k = i + (rand() % (52 - i));

		swap(cards[i], cards[k]);
	}

	cout << endl;
	
	//assign cards to players 
	
	
	for (int i = 1;i < 28;i++)
	{
		if (i >= 1 && i <= 5)
		{
			player1[i-1] = cards[i];
			
		}

		if (i >= 6 && i <= 10)
		{
			player2[i-6] = cards[i];
		}

		if (i >= 11 && i <= 15)
		{
			player3[i-11] = cards[i];
		}

		if (i >= 16 && i <= 20)
		{
			player4[i-16] = cards[i];
		}

		if (i >= 21 && i <= 25)
		{
			dealer[i-21] = cards[i];
		}

	}
	
	
	int value;
	
	for (int u = 0;u < 5;u++)
	{
		define_cards(player1[u],"Player1");
		define_cards(player2[u], "Player2");
		define_cards(player3[u], "Player3");
		define_cards(player4[u], "Player4");
	}
	
	cout << "\nDisplay Dealers cards : " << endl;
	cout << endl;
	for (int u = 0;u < 5;u++)
	{
		
		define_cards(dealer[u],"Dealer");
		
	} 
	

	
}

void Card_pack::define_cards(int value, string player)
{
	string card_name;

	ofstream file1(player, ios::app);

	switch (value)
	{
	case 11:
	case 24:
	case 37:
	case 50:
	{
		card_name = "Jack";
		break;
	}
	case 12:
	case 25:
	case 38:
	case 51:
	{
		card_name = "Queen";
		break;
	}
	case 13:
	case 26:
	case 39:
	case 52:
	{
		card_name = "King";
		break;
	}
	case 1:
	case 14:
	case 27:
	case 40:
	{
		card_name = "Ace";
		break;
	}

	default:
		break;
	}

	
	if (value >= 1 && value <= 13)
	{
		if (value > 1 && value < 11)
		{
			if (player == "Dealer")
			{
				cout << value << " Hearts" << endl;
			}
				
			file1 << value << " Hearts" << endl;
		}
		else
		{
			if (player == "Dealer")
			{
				cout << card_name << " Hearts" << endl;
			}
			

			file1 << card_name << " Hearts" << endl;
		}
	}

	if (value >= 14 && value <= 26)
	{
		if (value > 14 && value < 24)
		{
			if (player == "Dealer")
			{
				cout << value - 13 << " Diamond" << endl;
			}
			
			
			file1 << value - 13 << " Diamond" << endl;
		}
		else
		{
			if (player == "Dealer")
			{
				cout << card_name << " Diamond" << endl;
			}
			
			file1 << card_name << " Diamond" << endl;
		}
	}

	if (value >= 27 && value <= 39)
	{
		if (value > 27 && value < 37)
		{
			if (player == "Dealer")
			{
				cout << value - 26 << " Spade" << endl;
			}
			
			file1 << value - 26 << " Spade" << endl;
		}
		else
		{
			if (player == "Dealer")
			{
				cout << card_name << " Spade" << endl;
			}
			
			file1 << card_name << " Spade" << endl;
		}
	}

	if (value >= 40 && value <= 52)
	{
		if (value > 40 && value < 50)
		{
			if (player == "Dealer")
			{
				cout << value - 39 << " Clubs" << endl;
			}
			
			file1 << value - 39 << " Clubs" << endl;
		}
		else
		{
			if (player == "Dealer")
			{
				cout << card_name << " Clubs" << endl;
			}
			
			file1 << card_name << " Clubs" << endl;
		}
	}
}

void Poker::combination(string player_name)
{
	cout << endl;
	int points=0;
	int order = 0;//to check how many catogories it has gone in to 
	ifstream file1(player_name);
	string card_number, card_suite;
	string card_no[5];
	string card_name[5];
	string card;//check for different groups of similar cards

	for(int a=0;a<5;a++)
	{
		file1 >> card_number >> card_suite;
		card_no[a] = card_number;
		card_name[a] = card_suite;

	} 
	
	
	int same_card = 0;//to count same number cards count
	int flushred = 0;//to couont same color cards
	int flushblack = 0;//to count black color cards
	int same_card2=0;
	string score;


	//straight flush
	if (card_name[0] == card_name[1] && card_name[1]==card_name[2] && card_name[2]==card_name[3])
	{
		points = 200;
		goto label1;
	}


	//four of a kind 

	for(int y=0;y<5;y++)
	{
		for (int k = y+1;k < 5;k++)
		{
			
			if (card_no[y] == card_no[k])
			{
				card = card_no[y];
				if (card != card_no[y])
				{
					same_card2++;
				}
				same_card++;
				

			}

		}

		if (card_name[y] == "Hearts" || card_name[y] == "Diamond")
		{
			flushred++;
		}

		if (card_name[y] == "Spade" || card_name[y] == "Clubs")
		{
			flushblack++;
		}
	}

	
	if (same_card == 4)
	{
		points =  150;
		goto label1;
	}

	//Full house
	if (same_card == 3 && same_card2==1)
	{
		points =  120;
		goto label1;
	}

	//flush
	if (flushred == 5 || flushblack==5)
	{
		points =  90;
		goto label1;
	}
	

	//straight 


	//three of a kind 
	if (same_card == 3)
	{
		points =  50;
		goto label1;
	}

	//two pairs
	if (same_card == 1 && same_card2 == 1)
	{
		points = 30;
		goto label1;
	}

	//one pair 
	if (same_card == 1)
	{
		points =  10;
		goto label1;
	}

	//High card
	
	for (int k = 0;k < 5;k++)
	{
		if (card_no[k] == "Ace")
		{
			points=14;
			card_no[k] = "14";
			goto label1;
		}
		if (card_no[k] == "King")
		{
			points = 13;
			card_no[k] = "13";
			goto label1;
			
		}
		if (card_no[k] == "Queen")
		{
			points = 12;
			card_no[k] = "12";
			goto label1;
			
		}
		if (card_no[k] == "Jack")
		{
			points = 11;
			card_no[k] = "11";
			goto label1;
			
		}

	}

	/*
	for (int k = 0;k < 5;k++)
	{
		cout << card_no[k] << endl;
	}*/
	//cout << "max element : " << *max_element(card_no, card_no+5);
	score = *max_element(card_no, card_no + 5);
	points = stoi(score);
	//label2:
	//cout << "points : " << points << endl;
	//points= stoi(*max_element(card_no, card_no + 5));

label1:;

	map<string, int> playerID;
	playerID.insert(pair<string, int>("Player1", 1));
	playerID.insert(pair<string, int>("Player2", 2));
	playerID.insert(pair<string, int>("Player3", 3));
	playerID.insert(pair<string, int>("Player4", 4));

	switch (playerID[player_name])
	{
	case 1:
	{
		player1_points = points;
		break;
	}

	case 2:
	{
		player2_points = points;
		break;
	}

	case 3:
	{
		player3_points = points;
		break;
	}

	case 4:
	{
		player4_points = points;
		break;
	}

	default:
		break;
	}
	
}