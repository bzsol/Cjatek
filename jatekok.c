#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 25
#include <time.h>
#include <MMsystem.h>

void gotoxy(int x,int y) {
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main() {
PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
system("title Labirintus jatek");
system("cls");
system("color F");
char palya[N][N] = {0};
int x,y,baj;
int ex,ey;
srand(time(NULL));
// Keret generálása
for(x=0;x<=N;x++){
    for(y=0;y<=N;y++){
        if(x == 0 || x == N-1 || y == 0 || y == N-1) {
            palya[x][y] = '#';
        }
        else{
            palya[x][y] = ' ';

        }
    }
}
for(int i=0;i<=150;i++){
    palya[rand()%25][rand()%25] = '#';
}
ex = 10;
ey = 10;
palya[ex][ey] = 'X';

// "D Tömb kiírása!
for (x=0; x<N; x++){
for (y=0; y<N; y++){
 //printf("\033[0;32m");
 printf("%c",palya[y][x]);
 }
 printf("\n");
 }
x = 4;y = 4;
//printf("\033[0m"); // Reset color
gotoxy(x,y);
palya[x][y] = 'O';
while(1) {

// Ha nekimegyünk a falnak



printf("\033[0;32m");
    // Irányítás
    Sleep(1);
    gotoxy(x,y);
    int control1,control2;
        control1 = getch();
        if(control1 == 0xE0){
        control2 = getch();
        //Fel
        if(control2 == 72 && palya[x][y-1] != '#'){
            --y;
            gotoxy(x,y);
            palya[x][y] = 'O';
            printf("%c",palya[x][y]);
            gotoxy(x,y+1);
            palya[x][y+1] = ' ';
            printf("%c",palya[x][y+1]);
            gotoxy(x,y);



    }
        //Le
        if(control2 == 80 && palya[x][y+1] != '#'){
            ++y;
            gotoxy(x,y);
            palya[x][y] = 'O';
            printf("%c",palya[x][y]);
            gotoxy(x,y-1);
            palya[x][y-1] = ' ';
            printf("%c",palya[x][y-1]);
            gotoxy(x,y);


    }
        //Balra
        if(control2 == 75 && palya[x-1][y] != '#'){
            --x;
            gotoxy(x,y);
            palya[x][y] = 'O';
            printf("%c",palya[x][y]);
            gotoxy(x+1,y);
            palya[x+1][y] = ' ';
            printf("%c",palya[x+1][y]);
            gotoxy(x,y);


    }
        // Jobbra
        if(control2 == 77 && palya[x+1][y] != '#'){
            ++x;
            gotoxy(x,y);
            palya[x][y] = 'O';
            printf("%c",palya[x][y]);
            gotoxy(x-1,y);
            palya[x-1][y] = ' ';
            printf("%c",palya[x-1][y]);
            gotoxy(x,y);


    }
        if(control2 == 27) exit(1); // ESC kilepes
printf("\033[0m"); //Resets the text to default color
        }
// Ellenség
// Ellenség mozgása:
printf("\033[0;31m");
if(palya[x][y] != palya[ex][ey]){
    if(y-ey > 0 && palya[ex][ey+1] != '#'){
        ++ey;
        gotoxy(ex,ey);
        palya[ex][ey] = 'X';
        printf("%c",palya[ex][ey]);
        gotoxy(ex,ey-1);
        palya[ex][ey-1] = ' ';
        printf("%c",palya[ex][ey-1]);
    }
     if(y-ey < 0 && palya[ex][ey-1] != '#'){
        --ey;
        gotoxy(ex,ey);
        palya[ex][ey] = 'X';
        printf("%c",palya[ex][ey]);
        gotoxy(ex,ey+1);
        palya[ex][ey+1] = ' ';
        printf("%c",palya[ex][ey+1]);
    }
     if(x-ex > 0 && palya[ex+1][ey] != '#'){
        ++ex;
        gotoxy(ex,ey);
        palya[ex][ey] = 'X';
        printf("%c",palya[ex][ey]);
        gotoxy(ex-1,ey);
        palya[ex-1][ey] = ' ';
        printf("%c",palya[ex-1][ey]);
    }
     if(x-ex < 0 && palya[ex-1][ey] != '#'){
        --ex;
        gotoxy(ex,ey);
        palya[ex][ey] = 'X';
        printf("%c",palya[ex][ey]);
        gotoxy(ex+1,ey);
        palya[ex+1][ey] = ' ';
        printf("%c",palya[ex+1][ey]);
    }
printf("\033[0m");
if(palya[x][y] == 'X'){
system("cls");
gotoxy(10,10);
Beep(400,200);
system("color 4");
system("echo YOU DIED!");
break;
}



}



}
return 0;
}
