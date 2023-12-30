#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <array>

#define CYAN 3
#define WHITE 7

using namespace std;

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void textcolor(int color)
{
	SetConsoleTextAttribute(Console, color);
}

void gotoxy(int x, int y)
{
	/*
		pindahkan kursor ke koordinat x horizontal atau kolom
		dan koordinat y vertikal atau baris
	*/
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(Console, CursorPosition);
}

void scoreboard(void) //input data score
{
	array<int,50>score = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    array<string,50>playerName;
    string sortnameplayer;
    int sortscore;
	short i=0;

	ifstream ScoreBoard("leadb.txt");

	system("cls");
	textcolor(CYAN);
	cout << "SCORERBOARD";
	cout << "\n----------------\n";
	if (ScoreBoard.is_open()) {
    	while (ScoreBoard >> playerName[i])
		{
			ScoreBoard >> score[i];
			i++;
		}
		for (int i = 0 ; i <= 49 ; i++){
 	       for( int j = i+1 ; j <= 49 ; j++){
  	          	if (score[j] > score[i]){
   	            	sortscore = score[j];
  	            	score[j] = score[i];
    	        	score[i] = sortscore;

                	sortnameplayer = playerName[i];
                	playerName[i] = playerName[j];
                	playerName[j] = sortnameplayer;
            	}
        	}
    	}
    	for (int i = 0; i <= 4; i++) {
			gotoxy(0, 4+i);
	        cout <<i+1<<". "<< playerName[i];
			gotoxy (10,4+i);
			cout <<"|| " ;
			gotoxy (14,4+i);
			cout<<score[i]; 
			gotoxy (19,4+i);
			cout<<"||"<< endl;
  	  	}
		cout << "\n\nPress any key to go back to menu";
		textcolor(WHITE);
		getch();
		ScoreBoard.close();
    }
	else {
    	cout << "Error opening file";
  	}
}
	

int main()
{
	do{
	cout << "ini diluar fungsi";
	char pilih = getche();
	if (pilih == '0') {
		scoreboard();
	}else if (pilih == '4'){
		exit(0);
	}
	}while(true);
    return 0;
}
