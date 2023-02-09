#include<iostream>
using namespace std;


class Card_pack
{
public:
	int player1[5], player2[5], player3[5], player4[5], dealer[5];
	int player1_points, player2_points, player3_points, player4_points;


public:
	void assign_cards();
	void define_cards(int value,string player);

};

class Poker :public Card_pack
{

public:
	void combination(string player_name);
	

};



