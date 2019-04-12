#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <libconio/conio.c>

using namespace std;
void print(int(*)[4],int);
int main()
{

    int i, j, k, ik, jk, m, key, temp;
    bool flag;
    vector<int> a(16);
    int pyat[4][4];

    for(i = 0; i < 16; i++){
        a[i] = i;
    }
    srand(unsigned(time(0)));
    random_shuffle(a.begin(), a.end());

    for(i = 0, k = 0; i < 4; i++){
        for( j = 0; j < 4; j++){
            pyat[i][j] = a[k];
            k++;
           }
     }
bool f=false;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(pyat[i][j] == 0){
                ik = i;
                jk = j;
                f=true;
                break;

            }
        if(f == true)
            break;
        }

    }
cout<<ik<<" "<<jk<<endl;
    while(1){
        print(pyat,4);
        for(i = 0, flag = 1, m = 1; i < 4; i++){
            for(j = 0; j < 4; j++){
                if(pyat[i][j] % m != 0 || pyat[i][j] / m != 1){

                    flag = 0;
                    break;
                }
                m++;
            }
        }
        if(flag){
            cout << endl << "You won";
            //break;
        }
        //key=getch();
        switch(getch())
        {
        case 'a': if(jk != 0){ temp = pyat[ik][jk]; pyat[ik][jk] = pyat[ik][jk - 1]; pyat[ik][jk - 1] = temp; jk --; }
        case 'w': if(ik != 0){ temp = pyat[ik][jk]; pyat[ik][jk] = pyat[ik - 1][jk]; pyat[ik - 1][jk] = temp; ik --; }
        case 'd': if(jk != 3) { temp = pyat[ik][jk]; pyat[ik][jk] = pyat[ik][jk + 1]; pyat[ik][jk + 1] = temp; jk ++; }
        case 's': if(ik != 3) { temp = pyat[ik][jk]; pyat[ik][jk] = pyat[ik + 1][jk]; pyat[ik + 1][jk] = temp; ik ++; }
        }

        system("clear");







    }




    return 0;
}

void print(int (*a)[4],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%3d ",a[i][j]);
        }
        cout<<endl;
    }
}
/* // инициализация (должна быть выполнена
  // перед использованием ncurses)


  // перемещение курсора в стандартном экране y=10 x=30
  move(10,30);

  printw("Hello world !!!"); // вывод строки


  endwin(); // завершение работы с ncurses*/
