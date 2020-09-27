#include <iostream>
#include <stdlib.h> //Including srand and rand
#include <time.h> //Including time

using namespace std;

int main()
{
    //Initializing different variables that the code needs
    int prediction = 0, gridHighNum = 0, gridLowNum = 0, totGrid = 0, totPings = 0, enemyPos;

    //For loop that creates the grid, first loop being row, second being col, this is more for if we later show off the grid
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            totGrid++;
            //cout << " " << row << "," << col << " ";
        }
        //cout << endl;
    }

    //Initilizes seed value and then calls a random number
    srand(time(NULL));
    enemyPos = rand() % (totGrid + 1);

    //Intro code that provides info
    cout << "Generating enemy location on 8x8 grid...\n";
    cout << "Enemy is located at sector #" << enemyPos << "\n";
    cout << "Skynet HK-Aerial Initializing software...\n";
    cout << "============================================\n";

    //Sets low and high numbers
    gridLowNum = 0;
    gridHighNum = totGrid;

    //checks if prediction is not equal to enemy position, and runs code if the it is still trying to get them to match
    while (prediction != enemyPos)
    {
        //changes prediction based of other variables
        prediction = ((gridHighNum - gridLowNum) / 2) + gridLowNum;
        
        //tells user number of pings
        cout << "Skynet HK-Aerial Radar sending out ping " << (totPings + 1) << "\n";

        if (prediction < enemyPos)
        {
            //if the prediction was to low, changes the lownum and gives user info
            gridLowNum = prediction + 1;
            cout << "The target location of " << prediction << " was lower than the enemy\n";
            cout << "The new low number is = " << gridLowNum;
        }
        else if (prediction > enemyPos)
        {
            //if the prediction was to high, changes the highnum and gives user info
            gridHighNum = prediction - 1;
            cout << "The target location of " << prediction << " was higher than the enemy\n";
            cout << "The new high number is = " << gridHighNum;
        }
        else
        {
            //if the prediction was right, gives the user information that they did, also breaks out of code because while is no longer true
            cout << "The enemy was hiding at sector #" << prediction << "\n";
            cout << "Skynet HK-Aerial Software took " << (totPings + 1) << " predictions to find the enemy";
        }
        //adds barriers between pings
        cout << "\n============================================\n";

        //adds 1 to the number of pings
        totPings++;
    }
    //ends the program
    return 0;
}