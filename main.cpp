#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
/* ASKING FOR PLAYER NAME*/
string intro(){
	string player;
	cout<<"enter your name\n>>\t";                     
	cin>>player;
	return player;
}
/* STORING PLAYER MOVE */
string player_move(string name){
	string Pmove;
	char move;
	cout<<"Enter your move\t"<<name<<"\n>>\t";
	cin>>move;
	if(move=='r' || move=='R'){
		Pmove="rock";
	}else if(move=='p' || move=='P'){
		Pmove="paper";
	}else if(move=='s' || move=='S'){
		Pmove="scissors";
	}else{
		cout<<"invalid entry\n\n";
		Pmove="end";
	}
	return Pmove;
}
/* STORING COMPUTER MOVE*/
string pc_move(){
	int random;
	string Pmove;
	random=(rand()%3)+1;
	if(random==1){
		Pmove="rock";
	}else if(random==2){
		Pmove="paper";
	}else {
		Pmove="scissors";
	}
	return Pmove;
}
/* CHECKING THE RESULTS*/
int check_moves(string player , string pc){
	int result;
	if(player=="rock"){
		if(pc=="rock"){
			result=2;
		}else if(pc=="paper"){
			result=0;
		}else if(pc=="scissors"){
			result=1;
		}
	}else if(player=="paper"){
		if(pc=="rock"){
			result=1;;
		}else if(pc=="paper"){
			result=2;
		}else if(pc=="scissors"){
			result=0;
		}

	}else if(player=="scissors"){
		if(pc=="rock"){
			result=0;
		}else if(pc=="paper"){
			result=1;
		}else if(pc=="scissors"){
			result=2;
		}
	}
	return result;
}
/* DISPLAYING RESULTS*/
void output(int result , string name , string player , string pc){
	if(result==1){
		cout<<name<<":"<<player<<"\n"<<"Computer:"<<pc<<"\n"<<name<<"\tWon\n\n\n";
	}else if(result==0){
		cout<<name<<":"<<player<<"\n"<<"Computer:"<<pc<<"\n"<<"computer"<<"\tWon\n\n\n";
	}else if(result==2){
		cout<<name<<":"<<player<<"\n"<<"Computer:"<<pc<<"\n"<<"\tMatch Drawn\n\n\n";
	}
}
/* CHECKING PROGRAM STATUS*/
bool Program_status(){

	char choice;
	bool ps;
	cout<<"\apress y to continue or n to exit\n>>\t";
	cin>>choice;
	if(choice=='y' || choice=='Y'){
		ps=true;
	}else if(choice=='n' || choice=='N'){
		ps=false;
	}
	return ps;
}
/* MAIN PROGRAM */
void main(){
	/* VARIABLES */
	srand((unsigned) time(0));
	int random , result;
	string player,Player_move,Pc_move;
	bool program=true;
	/* STARTING POINT */
	while(program){
		player=intro();  
		system("CLS");           
		cout<<"ROCK\t\tPAPER\t\tSCISSORS\n\nRock....r\tPaper....p\tscissors....s\n\n"<<player<<"\t vs \tComputer\n\n"; // MAKING PROGRAM INTERACTIVE
		Player_move=player_move(player);
		if(Player_move!="end"){
			Pc_move=pc_move();
			result=check_moves(Player_move,Pc_move);
			output(result,player,Player_move,Pc_move);
		}
		program=Program_status();   
	}
}