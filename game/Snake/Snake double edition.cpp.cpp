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
const string SH1="¡ñ";
const string SB1="¡Ñ";
const string SH2="¡ö";
const string SB2="¡õ";
const string SF="¡ï";
int s[C*R][2];
int s2[C*R][2];
int fx,fy;
int S=0;
int S2=0;
int OO=0;
int TO=0;
bool GO=false;
char c='d';
char c2='j';
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD co;
bool iPS(int x,int y){
	for(int i=0;i<C*R;i++){
		if(s[i][0]==x&&s[i][1]==y){
			return true;
		}if(s2[i][0]==x&&s2[i][1]==y){
			return true;
		}
	}
	return false;
}
void l(int x,int y){
	co.X=x*2;
	co.Y=y;
	SetConsoleCursorPosition(h,co);
}
double r(double st,double e){
	return st+(e-st)*rand()/(RAND_MAX+1.0);
}
void pw(){
	l(0,0);
	cout<<endl;
	for(int i=1;i<=R;i++){
		cout<<"  ";
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
		if(s[i][0]<=0){
			break;
		}
		if(i==0){
			l(s[i][0],s[i][1]);
			cout<<SH1;
		}else{
			l(s[i][0],s[i][1]);
			cout<<SB1;
		}
	}
	for(int i=0;i<C*R;i++){
		if(s2[i][0]<=0){
			break;
		}
		if(i==0){
			l(s2[i][0],s2[i][1]);
			cout<<SH2;
		}else{
			l(s2[i][0],s2[i][1]);
			cout<<SB2;
		}
	}
}
void pf(){
	l(fx,fy);
	cout<<SF;
}
int m(int sn[C*R][2],char ch,bool iP1){
	int x=sn[0][0],y=sn[0][1];
	switch(ch){
		case'i':
		case'w':
		y--;
		break;
	case'k':
	case's':
		y++;
		break;
	case'j':
	case'a':
		x--;
		break;
	case'l':
	case'd':
		x++;
		break;
	default:
		return 0;
	}
	if(x<2||x>C-1||y<2||y>R-1){
		GO=true;
		return 1;
	}if(iPS(x,y)){
		GO=true;
		return 1;
	}
	for(int i=C*R-1;i>=1;i--){
		sn[i][0]=sn[i-1][0];
		sn[i][1]=sn[i-1][1];
	}
	sn[0][0]=x;sn[0][1]=y;
	if(x==fx&&y==fy){
		if(iP1){
			S+=1;
		}else{
			S2+=1;
		}
		do{
			fx=r(3,C-2);
			fy=r(2,R-2);
		}
		while(iPS(fx,fy));
	}else{
		for(int i=C*R-1;i>=1;i--){
			if(sn[i][0]>0){
				l(sn[i][0],sn[i][1]);
				cout<<SS;
				sn[i][0]=0;
				sn[i][1]=0;
				break;
			}
		}
	}
	return 0;
}
int main(){
	system("pause");
	system("cls");
	s[0][0]=6;
	s[0][1]=2;
	s[1][0]=5;
	s[1][1]=2;
	s[2][0]=4;
	s[2][1]=2;
	s[3][0]=3;
	s[3][1]=2;
	s[4][0]=2;
	s[4][1]=2;
	s2[0][0]=C-5;
	s2[0][1]=R-1;
	s2[1][0]=C-4;
	s2[1][1]=R-1;
	s2[2][0]=C-3;
	s2[2][1]=R-1;
	s2[3][0]=C-2;
	s2[3][1]=R-1;
	s2[4][0]=C-1;
	s2[4][1]=R-1;
	do{
		fx=r(11,C-1);
		fy=r(0,R-1);
	}
	while(iPS(fx,fy));
	pw();
	clock_t a,b;
	while(true){
		CONSOLE_CURSOR_INFO cursor_info={1,0};
		SetConsoleCursorInfo(h,&cursor_info);
		if(OO){
			S2+=1;
		}else if(TO){
			S+=1;
		}
		if(GO){
			system("cls");
			cout<<"Game Over!"<<endl;
			cout<<"player1:"<<S<<endl;
			cout<<"player2:"<<S2<<endl;
			if(OO){
				cout<<"player1 over!"<<endl;
			}else if(TO){
				cout<<"player2 over!"<<endl;
			}
			if(S>S2){
				cout<<"player1 win!"<<endl;
				cout<<"player2 lose!"<<endl;
			}else if(S2>S){
				cout<<"player2 win!"<<endl;
				cout<<"player1 lose!"<<endl;
			}else if(S==S2){
				cout<<"draw!"<<endl;
			}
			system("pause");
			return 0;
		}
		ps();
		pf();
		a=clock();
		while(1){
			b=clock();
			if(b-a>=(370+1-1)*1/1+0-0){
				break;
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
				}else if(('j'==c2||'l'==c2)&&(nc=='i'||nc=='k')){
					c2=nc;
				}else if(('i'==c2||'k'==c2)&&(nc=='j'||nc=='l')){
					c2=nc;
				}
			}
		}
		OO=m(s,c,true);
		TO=m(s2,c2,false);
		l(0,C+1);
		cout<<"Now Score:"<<S<<"/"<<S2;
	}
}
