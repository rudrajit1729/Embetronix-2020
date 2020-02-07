//=====Arrays Declarations=====
char Maze[11][11] = { {'.', '-', '.', '-', '.', '-', '.', '-', '.', '-', '.'},
 {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|'},
 {'.', ' ', '.', ' ', '.', '-', '.', '-', '.', ' ', '.'},
 {'|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|'},
 {'.', ' ', '.', ' ', '.', '-', '.', ' ', '.', ' ', '.'},
 {'|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
 {'.', ' ', '.', ' ', '.', '-', '.', '-', '.', ' ', '.'},
 {'|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '|'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|'},
 {'.', '-', '.', '-', '.', '-', '.', '-', '.', '-', '.'} };

char LHW[11][11] = { {'.', '-', '.', '-', '.', '-', '.', '-', '.', '-', '.'},
 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
 {'.', '-', '.', '-', '.', '-', '.', '-', '.', '-', '.'} };
//=====Declarations & Inital values=====
int x = 0;
int y = 0;
int xp = 1;
int yp = 9;
int uTurn = 0;
int i = 0;
char direc = 'S';
//=====Print Maze Function=====
void PrintMaze()
{
 //=====Print-out the maze=====
 x = 0;
 y = 0;
 while(x < 11)
 {
 Serial.print(Maze[y][x]);
 Serial.print(' ');
 x++;

 if(x > 10)
 {
 Serial.print("\n");
 y++;
 x = 0;
 if(y > 10)
 {
 x = 11;
 }
 }
 }
 Serial.print("\n");
 Serial.print("\n");
}
//=====Print LHW Function=====
void PrintLHW()
{
 //=====Print-out the LHW=====
 x = 0;
 y = 0;
 while((x < 11) && (i < 33))
 {
 Serial.print(LHW[y][x]);
 Serial.print(' ');
 x++;

 if(x > 10)

{
 Serial.print("\n");
 y++;
 x = 0;
 if(y > 10)

{
 x = 11;

}
 }
 }
 Serial.print("\n");
 Serial.print("\n");
}
void setup() {
 Serial.begin(9600); // for serial monitor output

 delay(500);

 //=====MAZE Titel=====
 Serial.print("MAZE");
 Serial.print("\n");
 PrintMaze(); //Call Print Maze Function

 //=====LHW Titel=====
 Serial.print("Left Hand Wall");
 Serial.print("\n");
 LHW[9][1] = 'M';
 PrintLHW(); //Call Print LHW Function
 }

void loop()
{
 while(i < 33)

{
 if (xp == 5 && yp == 5){i = 40;}
 i++;
 LHW[yp][xp] = 'X';

 if(direc == 'S'
)

{
 LHW[yp][xp
-1] = Maze[yp][xp
-1];
 LHW[yp
-1][xp] = Maze[yp
-1][xp];
 LHW[yp][xp+1] = Maze[yp][xp+1];

 if(LHW[yp][xp
-1] == ' '){direc = 'L';}
 else if(LHW[yp
-1][xp] == ' '){direc = 'S';}
 else if(LHW[yp][xp+1] == ' '){direc = 'R';}
 else{direc = 'D'; uTurn = 1;}
 }

 else if(direc == 'D'
)

{
 LHW[yp][xp+1] = Maze[yp][xp+1];
 LHW[yp+1][xp] = Maze[yp+1][xp];
 LHW[yp][xp
-1] = Maze[yp][xp
-1];

 if(LHW[yp][xp+1] == ' '){direc = 'R';}
 else if(LHW[yp+1][xp] == ' '){direc = 'D';}
 else if(LHW[yp][xp-1] == ' '){direc = 'L';}
 else{direc = 'S'; uTurn = 1;}
 }

 else if(direc == 'L'
)

{
 LHW[yp+1][xp] = Maze[yp+1][xp];
 LHW[yp][xp-1] = Maze[yp][xp-1];
 LHW[yp-1][xp] = Maze[yp-1][xp];

 if(LHW[yp+1][xp] == ' '){direc = 'D';}
 else if(LHW[yp][xp-1] == ' '){direc = 'L';}
 else if(LHW[yp-1][xp] == ' '){direc = 'S';}
 else{direc = 'R'; uTurn = 1;}
 }

 else if(direc == 'R')
 {
 LHW[yp-1][xp] = Maze[yp-1][xp];
 LHW[yp][xp+1] = Maze[yp][xp+1];
 LHW[yp+1][xp] = Maze[yp+1][xp];

 if(LHW[yp-1][xp] == ' '){direc = 'S';}
 else if(LHW[yp][xp+1] == ' '){direc = 'R';}
 else if(LHW[yp+1][xp] == ' '){direc = 'D';}
 else{direc = 'L'; uTurn = 1;}
 }

 LHW[yp][xp] = 'X';
 if(direc == 'S'){yp = yp-2;}
 else if(direc == 'D'){yp = yp+2;}
 else if(direc == 'L'){xp = xp-2;}
 else if(direc == 'R'){xp = xp+2;}
 LHW[yp][xp] = 'M';

 PrintLHW(); //Call Print LHW Function
 }
 while(1);
}
