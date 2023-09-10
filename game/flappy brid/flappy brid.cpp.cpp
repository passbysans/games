#include<iostream>

#include<stdio.h>

#include<ctime>

#include<windows.h>

#include<conio.h>

#include<cstdlib>

#include<fstream>

#include<iomanip>

#pragma GCC optimize(2)

using namespace std;

int l=-1,r=30;

int x=3,y=5;

int fenshu=0;

int nandu;

int map[89][96]= {

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,8,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,3,0,3,0,0,0,0,0,3,0,0,0,0,0,3,0,0,1,0,0,0,0,0,0,0,0,8,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,7,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,1,0,0,1,0,0,0,0,2,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,6,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,8,0,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,8,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,8,

1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,

};

void home();

void win() {

cout<<"你赢了!!!\n\n";

system("pause");

system("cls");

cout<<"你的分数:\n\n"<<fenshu;

system("pause");

system("cls");

cout<<"本游戏主要想反应环保问题:\n\n";

system("pause");

system("cls");

cout<<"游戏中的乌'云'不是别的正是过度排放的二氧化碳\n空气污染会影响鸟的呼吸功能\n能见度降低会影响迁徙候鸟的定位能力和飞行安全!!!\n\n";

system("pause");

system("cls");

cout<<"游戏中的塑料'袋'被鸟类误食,可能无法消化,损害肠胃功能\n就算消化,也会引起化学中毒,造成死亡!!!\n\n";

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"地球很脆弱\n\n";

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"请保护地球!!!\n\n";

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

system("pause");

system("cls");

fenshu=0;

home();

}

void Nandu() {

int n;

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"选择难度\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"1.简单游戏\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"2.困难游戏\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"3.地狱游戏(你确定?)"<<"\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"请输入:";

cin>>n;

nandu=50*(4-n);

system("cls");

}

void jiaocheng() {

cout<<"玩法：长按空格键控制小鸟向上飞（别让小鸟撞到乌'云'和塑料'袋'!!!\n当然也别忘了捡回鸟蛋）\n\n";

system("pause");

system("cls");

home();

}

void over() {

cout<<"你死了\n";

system("pause");

system("cls");

cout<<"你的分数:\n"<<fenshu;

system("pause");

system("cls");

cout<<"本游戏主要想反应环保问题:\n\n";

system("pause");

system("cls");

cout<<"游戏中的乌'云'不是别的正是过度排放的二氧化碳\n空气污染会影响鸟的呼吸功能\n能见度降低会影响迁徙候鸟的定位能力和飞行安全!!!\n\n";

system("pause");

system("cls");

cout<<"游戏中的塑料'袋'被鸟类误食,可能无法消化,损害肠胃功能\n就算消化,也会引起化学中毒,造成死亡!!!\n\n";

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"地球很脆弱\n\n";

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"请保护地球!!!\n\n";

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

system("pause");

system("cls");

fenshu=0;

home();

}

void draw(int a) {

if(a==0) {

printf("  ");

}

if(a==1) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);

printf("云");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==2) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

printf("蛋");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==3) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);

printf("袋");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==5) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);

printf("鸟");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==6) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

printf("线");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==7) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

printf("点");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==8) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

printf("赢");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==9) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

printf("终");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

}

void xianshi(int l,int r) {

while(r<=96) {

map[x][y]=5;

if(r<=56)

l++,r++;

for(int i=0; i<=8; i++) {

for(int j=l; j<=r; j++) {

draw(map[i][j]);

}

if(i!=8)

printf("\n");

}

Sleep(nandu);

map[x][y]=0;

y++;

x++;

if (GetKeyState(' ')<0) {

x-=1;

}

if (GetKeyState(' ')<0) {

x-=1;

}

system("cls");

if(map[x][y]==1||map[x][y]==3) {

over();

return ;

}

if(map[x][y]==2) fenshu+=20;

fenshu++;

if(map[x][y]==8||map[x][y]==9||map[x][y]==7||map[x][y]==6) {

fenshu+=50;

win();

return ;

}

}

}

void home() {

int n;

int l=-1,r=30;

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"1.开始游戏\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"2.退出游戏\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"3.游戏教程\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"请输入:";

cin>>n;

system("cls");

if(n==1) {

Nandu();

x=3,y=5;

xianshi(-1,30);

}

if(n==2)

return ;

if(n==3)

jiaocheng();

}

int main() {

system("mode con cols=65 lines=10");

home();

} 
