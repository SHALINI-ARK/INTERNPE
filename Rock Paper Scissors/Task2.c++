#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout<<"Welcome to Rock🪨 Paper📃 Scissors✂️ Game!️"<<endl;
    srand(time(0));
    int max_rounds = 5; 
    int player_score = 0;
    int opponent_score = 0;

    for (int round = 1; round <= max_rounds; ++round)
    {
        int number_opponent = 1 + (rand() % 3);
        int number_player;
        string opponent_weapon;
        string player_weapon;
        string winner;
        cout<<endl;
        cout << "Round " << round << "/" << max_rounds << endl;
        cout << "1-Rock, 2-Paper, 3-Scissors" << endl;
        cout << "Choose your weapon: ";
        cin >> number_player;

        switch (number_player)
        {
        case 1:
            player_weapon = "Rock";
            break;
        case 2:
            player_weapon = "Paper";
            break;
        case 3:
            player_weapon = "Scissors";
            break;
        default:
            player_weapon = "Invalid Weapon";
        }

        switch (number_opponent)
        {
        case 1:
            opponent_weapon = "Rock";
            break;
        case 2:
            opponent_weapon = "Paper";
            break;
        case 3:
            opponent_weapon = "Scissors";
            break;
        }

        cout << "Your weapon is: " << player_weapon << endl;
        cout << "Your opponent chooses: " << opponent_weapon << endl;
        if ((player_weapon == "Rock" && opponent_weapon == "Scissors") ||
            (player_weapon == "Paper" && opponent_weapon == "Rock") ||
            (player_weapon == "Scissors" && opponent_weapon == "Paper"))
        {
            cout << "You win this round!" << endl;
            player_score++;
        }
        else if ((opponent_weapon == "Rock" && player_weapon == "Scissors") ||
                 (opponent_weapon == "Paper" && player_weapon == "Rock") ||
                 (opponent_weapon == "Scissors" && player_weapon == "Paper"))
        {
            cout << "Opponent wins this round!" << endl;
            opponent_score++;
        }
        else
        {
            cout << "It's a draw in this round." << endl;
        }

        cout << "Current score - You: " << player_score << ", Opponent: " << opponent_score << endl;
    }
    cout<<endl;
    if (player_score > opponent_score)
    {
        cout << "Congratulations! You win the game!🤩" << endl;
    }
    else if (opponent_score > player_score)
    {
        cout << "Opponent wins the game. Better luck next time!😎" << endl;
    }
    else
    {
        cout << "The game ends in a draw.😊" << endl;
    }

    return 0;
}
