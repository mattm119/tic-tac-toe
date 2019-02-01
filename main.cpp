//Matthew Miles
//10/11/2016
//Plays tic-tac-toe for 2 players

#include <iostream>
using namespace std;
void playGame(int array[][3]);
void showTable(int array[][3]);
void ResetTable(int array[][3]);
int isWinner(int array[][3]);

int main() // initializes a 3x3 board and starts the game
{
    int board[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    playGame(board);
    
}

void playGame(int array[][3])
{
    int position, count = 0; // variables
    int column, row;   // for use in the array
    showTable(array);  //display the board
    
    while(count < 9)  //the game cannot be longer than 9 moves
    {
        cout << "Player No." << (count % 2) + 1 << " turn" << endl; // whose turn is it
        cin >> position; // get a position from the player
        row = (position-1) / 3;
        column = (position-1) % 3;
        
        if(position < 10 && position > 0) //checks if it is a valid position
        {
            if(array[row][column] > -1) // checks if that space has already been used
            {
                if(count % 2 == 0)
                {
                    array[row][column] = -1; // this will later be displayed as X
                }
                else
                {
                    array[row][column] = -2; // this will later be displayed as O
                }
                
                showTable(array);
                count++;
                
                if(isWinner(array) == -1) //if player 1 wins
                {
                    cout << "Player No.1 Wins" << endl << "Congratulations" << endl;
                    count = 10;
                }
                else if(isWinner(array) == -2) //if player 2 wins
                {
                    cout << "Player No.2 Wins" << endl << "Congratulations" << endl;
                    count = 10;
                }
            }
            else
            {
                cout << "Someone has already played in that position" << endl;
            }
        }
        else
        {
            cout << "Invalid board position" << endl;
        }
    }
    
    if(isWinner(array) == 0) //if nobody wins
    {
        cout << "There's no winner" << endl;
    }
    char playAgain;
    cout << "Would you like to play again?" << endl;
    cin >> playAgain;
    if(playAgain == 'Y' || playAgain == 'y') //does the user want to play again
    {
        ResetTable(array);
    }
}

//display the table
void showTable(int array[][3])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "|";
        for(int j = 0; j < 3; j++)
        {
            cout << " ";
            if(array[i][j] == -1)
            {
                cout << "X" << " |";
            }
            else if( array[i][j] == -2 )
            {
                cout << "O" << " |";
            }
            else
            {
                cout << array[i][j] << " |";
            }
        }
        cout << endl;
    }
}

//reset the table and play again
void ResetTable(int array[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            array[i][j] = (i*3)+j+1;
        }
    }
    
    playGame(array);
}

//checks if a player has won the game
int isWinner(int array[][3])
{
    for(int i = 0; i < 3; i++) // checks horizontal wins
    {
        if(array[i][0] == -1 && array[i][1] == -1 && array[i][2] == -1)
        {
            return -1;
        }
        
        if(array[i][0] == -2 && array[i][1] == -2 && array[i][2] == -2)
        {
            return -2;
        }
        
    }
    
    for(int j = 0; j < 3; j++) // checks vertical wins
    {
        if(array[0][j] == -1 && array[1][j] == -1 && array[2][j] == -1)
        {
            return -1;
        }
        
        if(array[0][j] == -2 && array[1][j] == -2 && array[2][j] == -2)
        {
            return -2;
        }
    }
    
    if(array[0][0] == -1 && array[1][1] == -1 && array[2][2] == -1) // checks for diagonal wins for p1
    {
        return -1;
    }
        
    if(array[0][0] == -2 && array[1][1] == -2 && array[2][2] == -2) // checks for diagonal wins for p2
    {
        return -2;
    }
    
    if(array[0][2] == -1 && array[1][1] == -1 && array[2][0] == -1) // checks for diagonal wins for p1
    {
        return -1;
    }
        
    if(array[0][2] == -1 && array[1][1] == -1 && array[2][0] == -1) // checks for diagonal wins for p2
    {
        return -2;
    }
    
    return 0;
}
