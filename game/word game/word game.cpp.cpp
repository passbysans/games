#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;
int mx=20,mstx,bx;
bool gO=false;
string m="ÎÒ";
string mst="¹Ö";
string d="ÃÅ";
string a="¸«";
string da="µ¶";
string ma="Ã¬";
void PM(int x){
	for(int i=0;i<x;i++){
		cout<<"  ";
	}
	cout<<m;
}
void move(char c){
	for(int i=0;i<30;i++){
		cout<<endl;
	}
	for(int i=0;i<mx;i++){
		cout<<"  ";
	}
	cout<<"  ";
	switch(c){
		case'A':
		case'a':
			mx--;
			break;
		case'D':
		case'd':
			mx++;
			break;
		case'Q':
		case'q':
			mx=mx-5;
			break;
		case'E':
		case'e':
			mx=mx+5;
			break;
		default:
			return;
	}
	if(mx==mstx){
		gO=true;
	}
	if(mx==bx){
		gO=true;
	}
	if(mx<0){
		mx=0;
	}
}
int main(){
	char c;
	system("pause");
	system("cls");
	for(int i=0;i<30;i++){
		cout<<endl;
	}
	while(true){
		c=getch();
		move(c);
		PM(mx);
	}
	return 0;
}
