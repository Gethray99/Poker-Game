#include<iostream>
#include<string>
#include"Header.h"
#include<fstream>
#include<map>
#include<cstdlib>



using namespace std;

int player1_score=0, player2_score=0, player3_score=0, player4_score=0;
float player1_tot=0, player2_tot=0, player3_tot=0, player4_tot=0;
int game_1=0, game2=0, game3=0, game4=0;

int Find_max(int number1, int number2, int number3, int number4)
{
	int max1, max2, max_final;
	
	if (number1 > number2)
	{
		max1 = number1;
	}
	else
	{
		max1 = number2;
	}

	if (number3 > number4)
	{
		max2 = number3;
	}
	else
	{
		max2 = number4;
	}

	return max(max1, max2);
}


int main()
{
	int n = 1;
	int playerscore1[4], playerscore2[4], playerscore3[4], playerscore4[4];
	char input,user;
	ofstream folder2("log_file", ios::trunc);
	while (n <5)
	{
		cout << "\t\t------------  Round " << n <<" ---------------"<< endl;
	//Number of players are 4 number of rounds are 4
	ofstream file2("Player1", ios::trunc);
	ofstream file4("Player2", ios::trunc);
	ofstream file5("Player3", ios::trunc);
	ofstream file6("Player4", ios::trunc);
	ofstream file3("Dealer", ios::trunc);

	Card_pack obj1;
	obj1.assign_cards();
	cout << "\n\n======== Dealer is shuffeling cards ===============\n";

	cout << "\n\n=========== Dealer is distributing cards =================\n" << endl;

	Poker game1;
	game1.combination("Player1");
	game1.combination("Player2");
	game1.combination("Player3");
	game1.combination("Player4");

	player1_score = game1.player1_points;
	player2_score = game1.player2_points;
	player3_score = game1.player3_points;
	player4_score = game1.player4_points;

	cout << "\nPlayer 1 want to withdraw?(y/n) ";
	cin >> user;
	if (user == 'y')
	{
		player1_score = 0;
		game_1 = game_1 + 1;
	}
	

	cout << "\nPlayer 2 want to withdraw?(y/n) ";
	cin >> user;
	if (user == 'y')
	{
		player2_score = 0;
		game2 = game2 + 1;
	}
	

	cout << "\nPlayer 3 want to withdraw?(y/n) ";
	cin >> user;
	if (user == 'y')
	{
		player3_score = 0;
		game3 = game3 + 1;
	}
	
	
	cout << "\nPlayer 4 want to withdraw?(y/n) ";
	cin >> user;
	if (user == 'y')
	{
		player4_score = 0;
		game4 = game4 + 1;
	}
	
	

	map<int, string> score_board;
	score_board.insert(pair<int, string>(player1_score, "Player 1"));
	score_board.insert(pair<int, string>(player2_score, "Player 2"));
	score_board.insert(pair<int, string>(player3_score, "Player 3"));
	score_board.insert(pair<int, string>(player4_score, "Player 4"));

	map<string, int> game_score;
	game_score.insert(pair<string, int>("Player 1", game_1));
	game_score.insert(pair<string, int>("Player 2", game2));
	game_score.insert(pair<string, int>("Player 3", game3));
	game_score.insert(pair<string, int>("Player 4", game4));



	//annouce the winner
	string player;
	if (score_board.find(Find_max(player1_score, player2_score, player3_score, player4_score)) != score_board.end())
	{
		cout << "\n\n\t!!!!!! The Winner for this round is " << score_board[Find_max(player1_score, player2_score, player3_score, player4_score)] <<" !!!!!!!!!!"<< endl;
		player = score_board[Find_max(player1_score, player2_score, player3_score, player4_score)];
	}

	if (player == "Player 1")
	{
		game_1 = game_1 + 11;
	}
	if (player == "Player 2")
	{
		game2 = game2 + 11;
	}
	if (player == "Player 3")
	{
		game3 = game3 + 11;
	}
	if (player == "Player 4")
	{
		game4 = game4 + 11;
	}


	game2 = game2 - 1;
	game_1 = game_1 - 1;
	game3 = game3 - 1;
	game4 = game4 - 1;



	player1_tot = player1_tot + player1_score;
	player2_tot = player2_tot + player2_score;
	player3_tot = player3_tot + player3_score;
	player4_tot = player4_tot + player4_score;

	
	float tot1, tot2, tot3, tot4;
	tot1 = (player1_tot / 800) * 100;
	tot2 = (player2_tot / 800) * 100;
	tot3 = (player3_tot / 800) * 100;
	tot4 = (player4_tot / 800) * 100;

	cout << "\n\nProbabilities of winning in round " << n << endl;
	cout << "player 1 : " << tot1 <<" %"<< endl;
	cout << "player 2 : " << tot2 << " %" << endl;
	cout << "player 3 : " << tot3 << " %" << endl;
	cout << "player 4 : " << tot4 << " %" << endl;

	cout << "\n\nScores : " << endl;
	cout << "player 1 : " << game_1 << endl;
	cout << "player 2 : " << game2 << endl;
	cout << "player 3 : " << game3 << endl;
	cout << "player 4 : " << game4 << endl;

	ofstream folder("log_file", ios::app);
	folder << "\n\t\tRound " << n << endl;
	folder << "\nWinner of the round : " << player << endl;
	folder << "\nPlayer 1 score : " << game_1 << endl;
	folder << "Player 2 score : " << game2 << endl;
	folder << "Player 3 score : " << game3 << endl;
	folder << "Player 4 score : " << game4 << endl;


	cout << "\nDo you want to continue round : (y/n) ";
	cin >> input;
	if (input == 'y')
	{
		system("CLS");
		n++;
	}
	else
	{
		return 0;
	}


	}

	system("CLS");
	cout << "\n\tScore board : " << endl;
	cout << "player 1 : " << game_1 << endl;
	cout << "player 2 : " << game2 << endl;
	cout << "player 3 : " << game3 << endl;
	cout << "player 4 : " << game4 << endl;
	map<int, string> final_score_board;
	final_score_board.insert(pair<int, string>(game_1, "Player 1"));
	final_score_board.insert(pair<int, string>(game2, "Player 2"));
	final_score_board.insert(pair<int, string>(game3, "Player 3"));
	final_score_board.insert(pair<int, string>(game4, "Player 4"));

	if (final_score_board.find(Find_max(game_1, game2, game3, game4)) != final_score_board.end())
	{
		cout << "\n\n!!!!!!!!!   Champion is  " << final_score_board[Find_max(game_1, game2, game3, game4)] <<" !!!!!!!!!!!!!!!!! "<< endl;
	}

	ofstream folder1("log_file", ios::app);
	folder1 << "\n\t\tChampion is : " << final_score_board[Find_max(game_1, game2, game3, game4)] << endl;


	return 0;
}