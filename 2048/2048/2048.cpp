#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int bord[4][4];
    int backbord[4][4];
    int i, j, line, column, k;
    bool game = 1;
    bool num2048;
    bool truemode = 0;
    int moves = 0;
    int highnumber = 2;
    char control;
    char gamemode;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            bord[i][j] = 0;
        }
    }
    srand(time(NULL));
    i = rand() % 2;
    j = rand() % 4;
    bord[i][j] = 2;

    j = rand() % 4;
    i = rand() % 2 + 2;
    bord[i][j] = 2;

    cout << "\n\t\t\t\t  2048 PUZZLE  \n " << endl;
    cout << "\n\t\t\t\t CHOSE GAME MODE :\n" << endl;
    cout << "\n\t\t\t EASY ---> e " << endl;
    cout << "\n\t\t\t NORMAL ---> n " << endl;
    cout << "\n\t\t\t HARD ---> h " << endl;
    do
    {
        cout << endl;
        cout << "\n\t\t\t GAME MODE ::" << " ";
        cin >> gamemode;
        if (gamemode == 'e' || gamemode == 'n' || gamemode == 'h')
            truemode = 1;
        else
            cout << "\t\t\t WE DON'T HAVE THIS GAME MODE  ";
    } while (truemode != 1);
    cout << "\t\t\t\t\t\t Moves:" << moves << "\n";
    cout << "\t\t\t\t\t\t HIGH NUMBER:" << highnumber << "\n\n\n\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "\t\t     |";
        for (int j = 0; j < 4; j++)
        {
            if (bord[i][j] != 0)
                printf("%4d    |", bord[i][j]);
            else
                printf("%4c    |", ' ');
        }

        cout << endl << endl;
    }
    cout << "\n\n Controls:\t\tw - UP \t\t Special buttons:\tu-UNDO \n\n\t\t\ts - DOWN \t\t\t\tr-RESET\n\n\t\t\ta - LEFT\t\t\t\tq-QUIT \n\n\t\t\td - RIGHT ";
    while (game == 1)
    {
        int samebord = 0;
        int findzero = 0;
        bool correctbutton = 0;
        do
        {
            cout << endl;
            cout << "\t\t\tPRESS:";
            cin >> control;
            if (control == 'w' || control == 'a' || control == 's' || control == 'd' || control == 'u' || control == 'q' || control == 'r' || control == '!' || control == 'l')
                correctbutton = 1;
            else
                cout << "\t\t YOU CAN'T USE THIS BUTTON  ";
        } while (correctbutton != 1);

        if (control == 'w')
        {
            if (samebord != 16)
            {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        backbord[i][j] = bord[i][j];
            }
            for (int up = 0; up < 3; up++)
                for (int i = 1; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                    {
                        if (bord[i][j] != 0 && bord[i - 1][j] == 0)
                        {
                            bord[i - 1][j] = bord[i][j];
                            bord[i][j] = 0;
                        }
                    }
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 4; j++)
                {
                    if (bord[i][j] != 0 && bord[i][j] == bord[i + 1][j])
                    {
                        bord[i][j] += bord[i][j];
                        bord[i + 1][j] = 0;
                    }
                }

            for (int i = 1; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    if (bord[i][j] != 0 && bord[i - 1][j] == 0)
                    {
                        bord[i - 1][j] = bord[i][j];
                        bord[i][j] = 0;
                    }
                }
        }
        else if (control == 's')
        {
            if (samebord != 16)
            {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        backbord[i][j] = bord[i][j];
            }

            for (int down = 0; down < 3; down++)
                for (int i = 2; i >= 0; i--)
                    for (int j = 0; j < 4; j++)
                    {
                        if (bord[i][j] != 0 && bord[i + 1][j] == 0)
                        {
                            bord[i + 1][j] = bord[i][j];
                            bord[i][j] = 0;
                        }
                    }
            for (int i = 3; i > 0; i--)
                for (int j = 0; j < 4; j++)
                {
                    if (bord[i][j] != 0 && bord[i][j] == bord[i - 1][j])
                    {
                        bord[i][j] += bord[i - 1][j];
                        bord[i - 1][j] = 0;
                    }
                }
            for (int i = 2; i >= 0; i--)
                for (int j = 0; j < 4; j++)
                {
                    if (bord[i][j] != 0 && bord[i + 1][j] == 0)
                    {
                        bord[i + 1][j] = bord[i][j];
                        bord[i][j] = 0;
                    }
                }

        }
        else if (control == 'a')
        {
            if (samebord != 16)
            {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        backbord[i][j] = bord[i][j];
            }

            for (int left = 0; left < 3; left++)
                for (int j = 1; j < 4; j++)
                    for (int i = 0; i < 4; i++)
                    {
                        if (bord[i][j] != 0 && bord[i][j - 1] == 0)
                        {
                            bord[i][j - 1] = bord[i][j];
                            bord[i][j] = 0;
                        }
                    }
            for (i = 0; i < 4; i++)
                for (j = 0; j < 3; j++)
                {
                    if (bord[i][j] != 0 && bord[i][j] == bord[i][j + 1])
                    {
                        bord[i][j] += bord[i][j];
                        bord[i][j + 1] = 0;
                    }
                }
            for (int j = 1; j < 4; j++)
                for (int i = 0; i < 4; i++)
                {
                    if (bord[i][j] != 0 && bord[i][j - 1] == 0)
                    {
                        bord[i][j - 1] = bord[i][j];
                        bord[i][j] = 0;
                    }
                }
        }
        else if (control == 'd')
        {
            if (samebord != 16)
            {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        backbord[i][j] = bord[i][j];
            }

            for (int right = 0; right < 3; right++)
                for (int i = 0; i < 4; i++)
                    for (int j = 2; j >= 0; j--)
                    {
                        if (bord[i][j] != 0 && bord[i][j + 1] == 0)
                        {
                            bord[i][j + 1] = bord[i][j];
                            bord[i][j] = 0;
                        }
                    }

            for (int i = 0; i < 4; i++)
                for (int j = 3; j > 0; j--)
                {
                    if (bord[i][j] != 0 && bord[i][j] == bord[i][j - 1])
                    {
                        bord[i][j] += bord[i][j - 1];
                        bord[i][j - 1] = 0;
                    }
                }

            for (int i = 0; i < 3; i++)
                for (int j = 2; j >= 0; j--)
                {
                    if (bord[i][j] != 0 && bord[i][j + 1] == 0)
                    {
                        bord[i + 1][j + 1] = bord[i][j];
                        bord[i][j] = 0;
                    }
                }

        }
        else if (control == 'u')
        {
            int matched = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (backbord[i][j] == bord[i][j])
                    {
                        matched++;
                    }

            if (moves == 0)
            {
                cout << "\n\n\t\t\tYOU CAN'T DO THAT\n";
                cout << "\t\t\tIT'S YOUR FIRST TURN\n";
            }
            else if (matched < 16)
            {
                moves--;
                highnumber = 2;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        bord[i][j] = backbord[i][j];

                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        if (highnumber < bord[i][j])
                            highnumber = bord[i][j];

                cout << "\t\t\t\t\t\tMOVES:" << moves << " \n";
                cout << "\t\t\t\t\t\tHIGH NUMBER:" << highnumber << " \n";
                for (int i = 0; i < 4; i++)
                {
                    cout << "\t\t     |";

                    for (int j = 0; j < 4; j++)
                    {
                        if (bord[i][j] != 0)
                            printf("%4d    |", bord[i][j]);
                        else
                            printf("%4c    |", ' ');
                    }

                    cout << endl << endl;
                }

            }
            else
                cout << "\t\t\tYOU AlREADY DO THAT\n";
        }
        else if (control == 'q')
        {

            cout << "\n\t\t\t YOU QUIT \n\n";
            cout << "\t\t YOUR HIGH NUMBER IS: " << highnumber << endl;

            return 0;

        }
        else if (control == 'r')
        {
            cout << "\n\n\t\t\t GAME RESET\n\n";
            moves = 0;
            highnumber = 2;
            num2048 = 0;
            bool resetmod = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    bord[i][j] = 0;
                }
            }
            srand(time(NULL));
            i = rand() % 2;
            j = rand() % 4;
            bord[i][j] = 2;

            j = rand() % 4;
            i = rand() % 2 + 2;
            bord[i][j] = 2;

            cout << "\n\t\t\t\t  2048 PUZZLE  \n " << endl;
            cout << "\n\t\t\t\t CHOSE GAME MODE :\n" << endl;
            cout << "\n\t\t\t EASY ---> e " << endl;
            cout << "\n\t\t\t NORMAL ---> n " << endl;
            cout << "\n\t\t\t HARD ---> h " << endl;
            do
            {
                cout << endl;
                cout << "\n\t\t\t GAME MODE ::" << " ";
                cin >> gamemode;
                if (gamemode == 'e' || gamemode == 'n' || gamemode == 'h')
                    resetmod = 1;
                else
                    cout << "\t\t\t WE DON'T HAVE THIS GAME MODE  ";
            } while (resetmod != 1);
            cout << "\t\t\t\t\t\t Moves:" << moves << "\n";
            cout << "\t\t\t\t\t\t HIGH NUMBER:" << highnumber << "\n\n\n\n";

            for (int i = 0; i < 4; i++)
            {
                cout << "\t\t     |";
                for (int j = 0; j < 4; j++)
                {
                    if (bord[i][j] != 0)
                        printf("%4d    |", bord[i][j]);
                    else
                        printf("%4c    |", ' ');
                }

                cout << endl << endl;
            }
            cout << "\n\n Controls:\t\tw - UP \t\t Special buttons:\tu-UNDO \n\n\t\t\ts - DOWN \t\t\t\tr-RESET\n\n\t\t\ta - LEFT\t\t\t\tq-QUIT \n\n\t\t\td - RIGHT ";
        }
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                if (backbord[i][j] == bord[i][j])
                {
                    samebord++;
                }
                if (backbord[i][j] == 0)
                {
                    findzero++;
                }
            }


        if (control == 'u')
        {

        }
        else if (control == 'r')
        {

        }

        else if (samebord == 16 || control == 'l')
        {
            if (findzero != 0 && control != 'l')
            {
                cout << "\n\n\n\t\t\t TRY ANOTHER MOVE\n" << endl;
            }
            else if (findzero == 0 || control == 'l')
            {
                cout << "\n\t\t\t YOU LOSE \n";
                cout << "\t\tYOUR HIGH NUMBER IS: " << highnumber << endl;
                cout << "\t\tRESET THE GAME PRESS ---> r" << endl;
                cout << "\t\tQUIT GAME PRESS ---> q" << endl;
            }
        }
        else if (control == '!' || (highnumber == 2048 && num2048 == 0))
        {
            cout << "\n\t\t\t!!! YOU WIN !!!" << endl;
            cout << "TO CONTINUE PRESS ---> w / s / a / d" << endl;
            cout << "RESET THE GAME PRESS ---> r" << endl;
            cout << "QUIT GAME PRESS ---> q" << endl;
        }
        else
        {
            if (gamemode == 'n')
            {
                do
                {
                    srand(time(NULL));
                    line = rand() % 4;
                    column = rand() % 4;
                    k = rand() % 10;
                } while (bord[line][column] != 0);
                if (k < 3)
                    bord[line][column] = 4;
                else
                    bord[line][column] = 2;
            }
            else if (gamemode == 'h')
            {
                for (int z = 0; z < 2; z++)
                {
                    do
                    {
                        srand(time(NULL));
                        line = rand() % 4;
                        column = rand() % 4;
                        k = rand() % 10;
                    } while (bord[line][column] != 0);
                    if (k < 3)
                        bord[line][column] = 4;
                    else
                        bord[line][column] = 2;
                }
            }
            else if (gamemode == 'e')
            {
                if (bord[0][3] == 0)
                    bord[0][3] = 2;
                else if (bord[0][3] != 0)
                {
                    if (bord[1][3] == 0)
                        bord[1][3] = 2;
                    else if (bord[1][3] != 0)
                    {
                        if (bord[2][3] == 0)
                            bord[2][3] = 2;
                        else if (bord[2][3] != 0)
                        {
                            if (bord[3][3] == 0)
                                bord[3][3] = 2;
                            else
                            {
                                do
                                {
                                    srand(time(NULL));
                                    line = rand() % 4;
                                    column = rand() % 4;

                                } while (bord[line][column] != 0);

                                bord[line][column] = 2;
                            }

                        }
                    }
                }


            }
            moves++;
        }

        for (int i = 0; i < 4; i++)

            for (int j = 0; j < 4; j++)
                if (highnumber < bord[i][j])
                {
                    highnumber = bord[i][j];
                }

        if (highnumber == 2048)
            num2048 = 1;

        cout << "\t\t\t\t\t\tMOVES:" << moves << " \n";
        cout << "\t\t\t\t\t\tHIGH NUMBER:" << highnumber << " \n";
        for (int i = 0; i < 4; i++)
        {
            cout << "\t\t     |";

            for (int j = 0; j < 4; j++)
            {
                if (bord[i][j] != 0)
                    printf("%4d    |", bord[i][j]);
                else
                    printf("%4c    |", ' ');
            }

            cout << endl << endl;
        }

    }

}
