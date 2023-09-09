#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<string>
using namespace std;
const int C=22;
const int R=22;
const string SW="¡Ë";
const string SS="  ";
const string SH="¡ñ";
const string SB="¡Ñ";
const string SF="¡ï";
int snake[C*R][2];
int fx,fy;
int S=5;
bool gO=false;
bool iPS(int x,int y){
	for(int i=0;i<C*R;i++){
		if(snake[i][0]==x&&snake[i][1]==y){
			return true;
		}
	}
	return false;
}
char c='d';
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD co;
void l(int x,int y){
	co.X=x*2;
	co.Y=y;
	SetConsoleCursorPosition(h,co);
}
double random(double s,double e){
	return s+(e-s)*rand()/(RAND_MAX+10);
}
void pw(){
	l(0,0);
	cout<<endl;
	for(int i=1;i<=R;i++){
		cout<<" ";
		for(int j=1;j<=C;j++){
			if(i==1||i==R||j==1||j==C){
				cout<<SW<<" ";
			}else{
				cout<<SS;
			}
		}
		cout<<endl;
	}
	cout<<endl; 
}
void ps(){
	for(int i=0;i<C*R;i++){
		if(snake[i][0]<=0){
			break;
		}
		if(i==0){
			l(snake[i][0],snake[i][1]);
			cout<<SH;
		}else{
			l(snake[i][0],snake[i][1]);
			cout<<SB;
		}
	}
}
void pf(){
	l(fx,fy);
	cout<<SF;
}
void m(char c){
	int x=snake[0][0],y=snake[0][1];
	switch(c){
		case'W':
		case'w':
			y--;
			break;
		case'S':
		case's':
			y++;
			break;
		case'A':
		case'a':
			x--;
			break;
		case'D':
		case'd':
			x++;
			break;
		default:
			return;
	}
	if(x<2||x>C-1||y<2||y>R-1){
		gO=true;
		return;
	}
	if(iPS(x,y)){
		gO=true;
		return;
	}
	for(int i=C*R-1;i>=1;i--){
		snake[i][0]=snake[i-1][0];
		snake[i][1]=snake[i-1][1];
	}
	snake[0][0]=x,snake[0][1]=y;
	if(x==fx&&y==fy){
		S+=1;
		do{
			fx=random(3,C-2);
			fy=random(2,R-2);
		}
		while(iPS(fx,fy));
	}else{
		for(int i=C*R-1;i>=1;i--){
			if(snake[i][0]>0){
				l(snake[i][0],snake[i][1]);
				cout<<SS;
				snake[i][0]=0;
				snake[i][1]=0;
				break;
			}
		}
	}
}
int main(){
	system("pause");
	system("cls");
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(h,&cursor_info);
	snake[0][0]=6;
	snake[0][1]=2;
	snake[1][0]=5;
	snake[1][1]=2;
	snake[2][0]=4;
	snake[2][1]=2;
	snake[3][0]=3;
	snake[3][1]=2;
	snake[4][0]=2;
	snake[4][1]=2;
	do{
		fx=random(3,C-2);
		fy=random(2,R-2);
	}
	while(iPS(fx,fy));
	pw();
	clock_t a,b;
	while(true){
		CONSOLE_CURSOR_INFO cursor_info={1,0};
		SetConsoleCursorInfo(h,&cursor_info);
		if(gO){
			system("cls");
			cout<<"Game Over!"<<endl;
			cout<<"You lost!"<<endl;
			cout<<"Score:"<<S<<endl;
			system("pause");
			return 0;
		}
		ps();
		pf();
		a=clock();
		while(1){
			b=clock();
			if(b-a>230){
				break;
			}
		}
		if(kbhit()){
			char nc=getch();
			if(nc>='A'&&nc<='Z'){
				nc+='a'-'A';
			}
			if(('d'==c||'a'==c)&&(nc=='w'||nc=='s')){
				c=nc;
			}else if(('w'==c||'s'==c)&&(nc=='a'||nc=='d')){
				c=nc;
			}
		}
		m(c);
		l(0,C+1);
		cout<<"Now Score:"<<S;
	}
}
