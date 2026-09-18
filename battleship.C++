#include <bits/stdc++.h>
using namespace std;
void randomizer(bool arr[][99], int r, int c)
{
    int ele = r * c;

    for (int i = ele - 1; i > 0; i--)
    {
        int rando = rand() % (i + 1);

        int r1, r2, c1, c2;

        r1 = i / c;
        c1 = i % c;

        r2 = rando / c;
        c2 = rando % c;

        swap(arr[r1][c1], arr[r2][c2]);
    }
}
int main(void)
{
    srand(time(0));

    int i, j, row, col;
    bool grid[99][99];
    int ships;

    cout << "Choose map size: " << endl;
    cout << "Rows: ";
    cin >> row;
    cout << "Columns: ";
    cin >> col;

    cout << "Ship count (Max = " << row * col << "): ";
    cin >> ships;

    int count = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (count < ships)
            {
                grid[i][j] = true;
                count++;
            }
            else
            {
                grid[i][j] = false;
            }
        }
    }

    randomizer(grid, row, col);

    cout << "Start the gussing game mate!: " << "\n";

    int hit = 0;
    int turns = 0;

    while (hit < ships)
    {
        int guess_row, guess_col;
        cout << "Guess row (between 0 -" << row - 1 << "): ";
        cin >> guess_row;
        cout << "Guess column (between 0 -" << col - 1 << "): ";
        cin >> guess_col;

        turns++;

        if (grid[guess_row][guess_col] == true)
        {
            cout << "HIT!!" << endl;
            grid[guess_row][guess_col] = false;
            hit++;
        }
        else
        {
            cout << "MISS!!" << endl;
        }
        cout << "Ships remain : " << ships - hit << endl;
    }
    cout << "DONE! It took you > " << turns << " < turns to sink all the ships." << endl;
    cout << "Git Gud mate!" << endl;

    return 0;
}