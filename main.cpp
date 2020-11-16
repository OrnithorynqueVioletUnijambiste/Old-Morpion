#include <iostream>

using namespace std;

#define columns 6
#define rows 6



void AddCoin(int team, char grid[rows][columns], int choice){
    int i;
    for(i = rows; i >=0; i--){
        if(grid[i][choice] == '_'){
            if(team == 1){
                grid[i][choice] = 'X';
                break;
            }
            else
            {
                grid[i][choice] = 'O';
                break;
            }
        }
    }
}

bool WinCondition(char grid[rows][columns], int team){
    int i, j;
    char p;
    if (team == 1)
    {
        p = 'X';
    }
    else
    {
        p = 'O';
    }
    for(i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {

            //Horizontale
            if (j < 3) {
                if (grid[i][j] == p
                    && grid[i][j + 1] == p
                    && grid[i][j + 2] == p
                    && grid[i][j + 3] == p) {
                    return true;
                }
            }

            //Verticale
            if (i < 3) {
                if (grid[i][j] == p
                    && grid[i + 1][j] == p
                    && grid[i + 2][j] == p
                    && grid[i + 3][j] == p) {
                    return true;
                }
            }

            //Diagonale haut gauche bas droite
            if (i < 3 && j < 3) {
                if (grid[i][j] == p
                    && grid[i + 1][j + 1] == p
                    && grid[i + 2][j + 2] == p
                    && grid[i + 3][j + 3] == p) {
                    return true;
                }
            }
            //Diagonale bas gauche haut droite
            if(i > 2 && j < 3){
                if (grid[i][j] == p
                    && grid[i - 1][j + 1] == p
                    && grid[i - 2][j + 2] == p
                    && grid[i - 3][j + 3] == p) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool FullBoard(char grid[rows][columns]){
    for(int i = 0; i < columns; i++){
        if(grid[0][i] == '_'){
            return false;
        }
    }
    return true;
}

void ClearBoard(char grid[rows][columns]){
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            grid[i][j] = '_';
        }
    }
}


void DisplayBoard(char grid[rows][columns]){
    int i, j;

    for(i = 0; i < rows; i++){
        cout << "|";
        for(j = 0; j < columns; j++){
            if(grid[i][j] !=  'X' && grid[i][j] != 'O') {
                grid[i][j] = '_';
            }
            cout << grid[i][j];
        }
        cout << "|" << endl;
    }
}

int main() {
    char grid[rows][columns];
    int randomKey, playerTurn, pick;
    bool win, full;

    reset:
    DisplayBoard(grid);
    playerTurn = 1;
    do{
        cout << "Joueur " << playerTurn << " doit choisir une colonne (0-5)" << endl;
        cin >> pick;
        AddCoin(playerTurn, grid, pick);
        DisplayBoard(grid);
        win = WinCondition(grid, playerTurn);
        full = FullBoard(grid);
        if(playerTurn == 1)
        {
            playerTurn += 1;
        }
        else
        {
            playerTurn -= 1;
        }

    }while(!win && !full);

    if(full && !win){
        cout << "Le board est plein, entrez 1 pour recommencer, ou n'importe quelle autre touche pour quitter" << endl;
        cin >> randomKey;
        if(randomKey == 1){
            ClearBoard(grid);
            goto reset;
        }
    }

    if(win){
        cout << "Joueur " << playerTurn << " a gagné!" << endl;
        cout << "Entrez 1 pour recommencer, ou n'importe quelle autre touche pour quitter" << endl;
        cin >> randomKey;
        if(randomKey == 1){
            ClearBoard(grid);
            goto reset;
        }
    }
    return 0;
}