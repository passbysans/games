#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int i;
char c;
int q;
int m=100;
char PH(){
	cout<<"欢迎来到幸运小店！！！"<<endl;
	cout<<"Welcome lucky shop!!!"<<endl;
	cout<<"试试？<y/n>      Try?<y/n>"<<endl;
	cout<<"你的选择       Your choice:";
	cin>>c;
	return c;
}
void S(int l){
	int am=0;
	int ll[7][5]={{0},{0},{0},{0},{0},{0},{0}};
	int g=1; 
	srand(time(0));
	int rt=rand()%99+1;
	cout<<"中奖号码        Winning number："<<rt<<endl;
	for(int j=1;i<=7;i++){
		cout<<endl;
		for(int j=1;j<=5;j++){
			cout<<0<<"  ";
		}
	}
	cout<<endl;
	for(int j=1;j<=7;j++){
		cout<<"请输入第"<<g<<"次你要刮开的层数："<<endl;
		cout<<"Please enter the number of layers you want to scrape for the "<<g<<"th time:"; 
		cin>>l;
		g++;
		system("cls");
		for(int q=0;q<7;q++){
			if(q+1!=l){
				if(ll[q]==0){
					for(int e=1;e<=5;e++){
						cout<<0<<"  ";
					}
					cout<<endl;			
				}else{
					for(int e=0;e<5;e++){
						cout<<ll[q][e]<<"  ";
					}
					cout<<endl;
				}
			}else{
				for(int e=0;e<5;e++){
					int r=rand()%99+1;
					cout<<r<<"  ";
					if(r==rt){
						am+=50;
					}
					ll[q][e]=r;
				}
				cout<<endl;
			}
		} 
		cout<<endl;
	}
	cout<<"恭喜你，获得了"<<am<<"元"<<endl;
	cout<<"Congratulations, you won the "<<am<<" yuan."<<endl;
	m+=am;
	Sleep(2000);
}
void L(int nl[5]){
	int qw=0;
	cout<<"欢迎来玩幸运彩票！待会儿，你得输入五个数字！"<<endl;
	cout<<"5个全中特等奖（10000元），中了4个一等奖（5000元），中了3个二等奖（1000元），中了2个三等奖（500元）。"<<endl;
	cout<<"Welcome to play the lucky lottery! Later, you have to enter five numbers!"<<endl;
	cout<<"Five grand prizes (10,000 yuan), four first prizes (5,000 yuan), three second prizes (1000 yuan) and two third prizes (500 yuan)."<<endl;
	cout<<"你的选择       your choice:";
	for(int j=0;j<5;j++){
		cin>>nl[j];
	}
	system("cls");
	for(int j=0;j<3;j++){
		cout<<"等待开奖.";
		cout<<"Waiting for the lottery.";
		Sleep(1000);
		system("cls");
		cout<<"等待开奖..";
		cout<<"Waiting for the lottery..";
		Sleep(1000);
		system("cls");
		cout<<"等待开奖...";
		cout<<"Waiting for the lottery...";
		Sleep(1000);
		system("cls");
	}
	srand(time(0));
	for(int j=0;j<5;j++){
		int re=rand()%99+1;
		cout<<re<<"  ";
		for(int q=0;q<5;q++){
			if(re==nl[q]){
				qw++;
			}
		}
		Sleep(1000);
	}
	cout<<endl;
	cout<<"中了"<<qw<<"个        Got"<<qw<<endl;
	if(qw==2){
		m+=500;
		cout<<"恭喜你，中了三等奖！"<<endl;
		cout<<"Congratulations, you won the third prize!";
	}
	if(qw==3){
		m+=1000;
		cout<<"恭喜你，中了二等奖！"<<endl; 
		cout<<"Congratulations, you won the second prize!";
	}
	if(qw==4){
		m+=5000;
		cout<<"恭喜你，中了一等奖！"<<endl; 
		cout<<"Congratulations, you won the first prize!";
	}
	if(qw==5){
		m+=10000;
		cout<<"恭喜你，中了特等奖！"<<endl; 
		cout<<"Congratulations, you won the grand prize!";
	}
	if(qw==1||qw==0){
		cout<<"太遗憾了，没中奖！"<<endl;
		cout<<"What a pity! I didn't win the prize!";
	}
	Sleep(5000);
}
int main(){
	int nl[5];
	int l;
	PH();
	system("cls");
	while(true){
		if(c='y'){
			if(m<20){
				return 0;
			}
			cout<<"1.刮刮乐     1.Scratch     0=▇"<<endl;
			cout<<"2.幸运彩票      2.Lucky lottery"<<endl;
			cout<<"一次20元        现在钱数："<<m<<"元"<<endl;
			cout<<"20 yuan once.    Now the amount of money:"<<m<<"yuan"<<endl;
			cout<<"你的选择       Your choice：";
			cin>>q;
			m-=20;
			system("cls");
			if(q==1){
				S(l);
			}else if(q==2){
				L(nl);
			}else{
				return 0;
			}
			system("cls");
		}else{
			return 0;
		}
	}
}
