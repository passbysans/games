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

cout<<"��Ӯ��!!!\n\n";

system("pause");

system("cls");

cout<<"��ķ���:\n\n"<<fenshu;

system("pause");

system("cls");

cout<<"����Ϸ��Ҫ�뷴Ӧ��������:\n\n";

system("pause");

system("cls");

cout<<"��Ϸ�е���'��'���Ǳ�����ǹ����ŷŵĶ�����̼\n������Ⱦ��Ӱ����ĺ�������\n�ܼ��Ƚ��ͻ�Ӱ��Ǩ�����Ķ�λ�����ͷ��а�ȫ!!!\n\n";

system("pause");

system("cls");

cout<<"��Ϸ�е�����'��'��������ʳ,�����޷�����,�𺦳�θ����\n��������,Ҳ������ѧ�ж�,�������!!!\n\n";

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"����ܴ���\n\n";

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"�뱣������!!!\n\n";

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

cout<<"ѡ���Ѷ�\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"1.����Ϸ\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"2.������Ϸ\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"3.������Ϸ(��ȷ��?)"<<"\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"������:";

cin>>n;

nandu=50*(4-n);

system("cls");

}

void jiaocheng() {

cout<<"�淨�������ո������С�����Ϸɣ�����С��ײ����'��'������'��'!!!\n��ȻҲ�����˼���񵰣�\n\n";

system("pause");

system("cls");

home();

}

void over() {

cout<<"������\n";

system("pause");

system("cls");

cout<<"��ķ���:\n"<<fenshu;

system("pause");

system("cls");

cout<<"����Ϸ��Ҫ�뷴Ӧ��������:\n\n";

system("pause");

system("cls");

cout<<"��Ϸ�е���'��'���Ǳ�����ǹ����ŷŵĶ�����̼\n������Ⱦ��Ӱ����ĺ�������\n�ܼ��Ƚ��ͻ�Ӱ��Ǩ�����Ķ�λ�����ͷ��а�ȫ!!!\n\n";

system("pause");

system("cls");

cout<<"��Ϸ�е�����'��'��������ʳ,�����޷�����,�𺦳�θ����\n��������,Ҳ������ѧ�ж�,�������!!!\n\n";

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"����ܴ���\n\n";

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

system("pause");

system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

cout<<"�뱣������!!!\n\n";

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

printf("��");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==2) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

printf("��");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==3) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);

printf("��");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==5) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);

printf("��");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==6) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

printf("��");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==7) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

printf("��");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==8) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);

printf("Ӯ");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

}

if(a==9) {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

printf("��");

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

cout<<"1.��ʼ��Ϸ\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"2.�˳���Ϸ\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"3.��Ϸ�̳�\n";

for(int i=1; i<=25; i++)

cout<<" ";

cout<<"������:";

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
