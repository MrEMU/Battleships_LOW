#include <iostream>
#include "Field.h"
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

vector<int> parsecoord(string coords) //Methode translates user input in the equivalent numbers
 {
     vector<int> givitback(4);
     char stringpart;
     for (int i=0;i<4;i+=1)
     {

         stringpart = coords[i];

        if (stringpart == 'A')
            {
                givitback[i] = 1;
            }

        else if (stringpart == 'B')
            {
                givitback[i] = 2;
            }

        else if (stringpart == 'C')
            {
                givitback[i] = 3;
            }

        else if (stringpart == 'D')
            {
                givitback[i] = 4;
            }

        else if (stringpart == 'E')
            {
                givitback[i] = 5;
            }

        else if (stringpart == 'F')
            {
                givitback[i] = 6;
            }

        else if (stringpart == 'G')
            {
                givitback[i] = 7;
            }

        else if (stringpart == 'H')
            {
                givitback[i] = 8;
            }

        else if (stringpart == 'I')
            {
                givitback[i] = 9;
            }
        else if (stringpart == '1')
            {
                givitback[i] = 1;
            }

        else if (stringpart == '2')
            {
                givitback[i] = 2;
            }

        else if (stringpart == '3')
            {
                givitback[i] = 3;
            }

        else if (stringpart == '4')
            {
                givitback[i] = 4;
            }

        else if (stringpart == '5')
            {
                givitback[i] = 5;
            }

        else if (stringpart == '6')
            {
                givitback[i] = 6;
            }

        else if (stringpart == '7')
            {
                givitback[i] = 7;
            }

        else if (stringpart == '8')
            {
                givitback[i] = 8;
            }

        else if (stringpart == '9')
            {
                givitback[i] = 9;
            }

        else
            {
                   return givitback;
            }
     }

      return givitback;
}


int main()
{
    int choice; // Menu
    string position; // Array is catching user input
    string position2;
    int player = 1; // shows which players turn it is
    char ship[7][20] = {"Ultradezztroyaship", "Psychokillaship", "Psychokillaship", "Common ship", "Common ship", "Common ship", "Sneaky hidden ship"}; // List for descriptions
    int lenght[7] = {5,4,4,3,3,3,2}; // ship lenght list
    bool success = false;
    vector<int> compiled_P;
    bool victory;
    int hit1 = 0;
    int hit2 = 0;



    cout << "Startup..." << endl;
    cout << "Creating Battlegrounds...";
    Field  Field1;       //Setup objects
    Field  Field2;
    Field  Field3;
    Field  Field4;
    cout << "DONE\n" << endl;

    cout << "\n\n---WELCOME TO BATTLESHIPS---\n" << endl;  // Main Menu
    cout << "1. Single Player" << endl;
    cout << "2. Multiplayer\n"  << endl;
    cout << "3. Beenden\n"  << endl;
    cin >> choice;

    while (choice != 3) // 3 ends the programm
    {

        if (choice == 1) // Not ready yet
        {
            system("cls");
            cout << "I'm sorry, but actually I didn't thought, you have no friends, thatswhy I hadn't programmed this Modi yet, pls try again later" <<endl;
            cout << "Press any key to continue";
            system("pause");
            system("cls");
        }


        else if (choice == 2) // Multiplayer
        {
            system("cls");
            cout << "Okay so lets start then" << endl << "I will give each of you these ships:"<< endl <<"- 1 Ultradezztroyaship (5 positions)" << endl <<"- 1 Psychokillaship (4 positions)" << endl;
            cout << "- 3 Common ships (3 positions)" << endl << "- 1 Sneaky hidden ship (2 positions)" << endl;
            system("pause");

            for (int i=0;i<7;i++) // until every ship is set
            {
                while (!success)
                {
                    system("cls");
                    Field1.show();
                    cout << "\nPlayer" << player <<": Please enter the first coordinates of your " << ship[i]  << ".\n"; //User Inputs
                    cin >> position;
                    cout << "\nPlayer" << player <<": Please enter the second coordinates of your " << ship[i]  << ".\n";
                    cin >> position2;
                    position = position + position2;
                    compiled_P = parsecoord(position);  // User coords become parsed
                    success = Field1.setship(compiled_P, lenght[i]);  // In case a ship was set false, sucess is false, too
                    if (!success)
                    {
                        cout << "I wasn't able to set your ship. Please try again"<<endl;
                        system("pause");
                    }
                }
                success = false;
            }

            player += 1;

            for (int a=0;a<7;a++) // until every ship is set
            {
                success = false;
                while (!success)
                {
                    system("cls");
                    Field3.show();
                    cout << "\nPlayer" << player <<": Please enter the first coordinates of your " << ship[a]  << ".\n"; //User Inputs
                    cin >> position;
                    cout << "\nPlayer" << player <<": Please enter the second coordinates of your " << ship[a]  << ".\n";
                    cin >> position2;
                    position = position + position2;
                    compiled_P = parsecoord(position);  // User coords become parsed
                    success = Field3.setship(compiled_P, lenght[a]);  // In case a ship was set false, sucess is false, too
                    if (!success)
                    {
                        cout << "I wasn't able to set your ship. Please try again"<<endl;
                        system("pause");
                    }
                }
                success = false;
            }

            cout << "Okay now, the game is starting now"<< endl;
            system("pause");
            victory = false;

            while (!victory)
            {
                if (player != 1)
                {
                    player = 1;
                }
                else
                {
                    player = 2;
                }


                if (player == 1)
                {
                    system("cls");
                    Field1.show();
                    Field2.show();
                    cout << "\nPlayer" << player <<": You are ready to fire now, please enter your target-coords"; //User Inputs
                    cin >> position;
                    compiled_P = parsecoord(position);
                    success = Field3.testhit(compiled_P);


                    if (success)
                    {
                        cout <<endl << "HIT!!!"<<endl;
                        Field2.write_position('#', compiled_P);
                        Field3.write_position('X', compiled_P);
                        cout << position;
                        Field2.show();
                        system("pause");
                        hit2++;
                    }
                    else
                    {
                        cout <<endl << "Water!";
                        Field2.write_position('0', compiled_P);
                        Field3.write_position('0', compiled_P);
                        cout << position;
                        Field2.show();
                        system("pause");
                    }
                }
                else
                {
                    system("cls");
                    Field3.show();
                    Field4.show();
                    cout << "\nPlayer" << player <<": You are ready to fire now, please enter your target-coords"; //User Inputs
                    cin >> position;
                    cout << position;
                    compiled_P = parsecoord(position);
                    success = Field1.testhit(compiled_P);


                    if (success)
                    {
                        cout <<endl << "HIT!!!";
                        Field4.write_position('#', compiled_P);
                        Field1.write_position('X', compiled_P);
                        cout << position;
                        Field4.show();
                        system("pause");
                        hit1++;
                    }
                    else
                    {
                        cout <<endl << "Water!";
                        Field4.write_position('0', compiled_P);
                        Field1.write_position('0', compiled_P);
                        cout << position;
                        Field4.show();
                        system("pause");
                    }
                }
                if ((hit1 == 24) || (hit2 == 24))
                {
                    victory = true;
                }

            }
            cout <<endl << "Player " << player << " wins that battle";
                system("pause");



        }


        else
        {
            cout << "Oh cmn, it\'s war...BE SERIOUS, SOLDIER!!!" << endl; // Every other input
            system("pause");
            system("cls");
        }

    system("pause");
    cout << "\n\n---WELCOME TO BATTLESHIPS---\n" << endl ; //Menu rewriting
    cout << "1. Single Player" << endl;
    cout << "2. Multiplayer\n"  << endl;
    cout << "3. Beenden\n"  << endl;
    cin >> choice;
    }

    return 0;
}
