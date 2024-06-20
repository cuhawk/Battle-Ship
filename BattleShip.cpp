#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<windows.h>
#include<conio.h>

using namespace std;

char map[11][11];

// Generating map

void generate_map(){
		int j=0,i,num;
		char ch ,c;
		srand(time(0));
		for(i=1;i<=11;i++){
			c='0'+j;
			map[i][0]=c;
			map[0][i]=c;
			j=j+1;
		}
		map[0][0]=' ';
		for (i=1;i<11;i++){
			for(j=1;j<11;j++){
				num=rand()%2;
				if (num==0){
					ch='-';
				}
				else{
					ch='^';
				}
				map[i][j]=ch;
			}
		}
}


// Display map on screen

void display_map(){
	int i ,j;
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}


// Game Loop

void game_loop(int &missiles,int ship_location_X, int ship_location_Y){
	int missile_X_cordinate, missile_Y_cordinate;
	while(missiles>=0){
		system("cls");

		cout<<"Missiles\t"<<missiles<<endl;
		cout<<"********** MAP **********"<<endl;
		
		// displaying map
		
		display_map();
		
		// Getting missile cordinate from user
		
		cout<<"Enter Missile X Cordinate range(0,9): ";
		cin>>missile_X_cordinate;
		cout<<"Enter Missile Y Cordinate range(0,9): ";
		cin>>missile_Y_cordinate;
		missile_X_cordinate=missile_X_cordinate+1;
		missile_Y_cordinate=missile_Y_cordinate+1;
		
		// Checking is missile hit the target
		
		if(missile_X_cordinate==ship_location_X && missile_Y_cordinate==ship_location_Y){
			cout<<"Missile hit.";
			break;
		}
		else{
			cout<<"Missile miss.";
			missiles=missiles-1;
			cout<<"Press any key to continue...";
			getch();
		}
	}
}

// main function

int main(){
	int i, j, num,missiles=10;
	int ship_location_X,ship_location_Y;
	generate_map();

// Generating ship location

	while(true){
		ship_location_X=rand()%11;
		ship_location_Y=rand()%11;
		if(map[ship_location_Y][ship_location_X]='^'){
			break;
		}
		else{
			ship_location_X=rand()%11;
			ship_location_Y=rand()%11;
		}
	}

	// Starting game loop

	game_loop(missiles,ship_location_X,ship_location_Y);
	
	// Displaying final map
	system("cls");
	map[ship_location_Y][ship_location_X]='S';
	cout<<"\n\n********** Ship Location **********"<<endl;
	display_map();
	return 0;
}
