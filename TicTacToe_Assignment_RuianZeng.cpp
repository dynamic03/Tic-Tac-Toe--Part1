#include <iostream>
#include <string>
#include<iomanip>
#include <stdio.h>

using namespace std;

string Winner;
string playerA;
string playerB;
int InitialRow,InitialColumn;

struct Board
{
	bool flag;
	int value;
}board[3][3];

bool CheckWhetherEnd()// judge whether the game is over
{
	int x,y;
	int result=0;
	for(x=0;x<3;x++)// calculate the sum of the value of rows
	{
		for(y=0;y<3;y++)
		{

			result += board[x][y].value;

		}
		if(6==result ) 
		{
			Winner=playerB;
			return true;
		}
		if(9==result)
		{
			Winner=playerA;
			return true;
		}
		result=0;
	}
	for(x=0;x<3;x++)// calculate the sum of the value of columns
	{
		for(y=0;y<3;y++)	result += board[y][x].value;
				
		if(6==result ) 
		{
			Winner=playerB;
			return true;
		}
		if(9==result)
		{
			Winner=playerA;
			return true;
		}
		result=0;
	}


	if(9==board[0][0].value+board[1][1].value+board[2][2].value ) // calculate the sum of the value of diagonal line 
	{
		Winner=playerA;
		return true;
	}
	if(6==board[0][0].value+board[1][1].value+board[2][2].value )
	{
		Winner=playerB;
		return true;
	}
	if(9==board[2][0].value+board[1][1].value+board[0][2].value ) 
	{
		Winner=playerA;
		return true;
	}
	if(6==board[2][0].value+board[1][1].value+board[0][2].value ) 
	{
		Winner=playerB;
		return true;
	}

	int allflag=0;//if the board is full and still have no winner
	for(x=0;x<3;x++)
		for(y=0;y<3;y++) if(board[x][y].flag) allflag++;
	if (9==allflag) 
	{
		Winner="No one";
		return true;
	}
	return false;
}

int main()
{
	int InitialRow1,InitialColumn1;

	string output[6][12];
	int i,j;

	//the initial output format
	for(i=0;i<6;i++)
		for(j=0;j<12;j++)
		{
			if (i==0 && j==2) output[i][j]="1";
			if (i==0 && j==6) output[i][j]="2";
			if (i==0 && j==10) output[i][j]="3";
			if (i==0&&j!=2&&j!=6&&j!=10) output[i][j]=" ";

			if(i==1&&j==0) output[i][j]="1";
			if(i==1 && (j==4||j==8)) output[i][j]="|";
			if(i==1 && j!=0 &&j!=4 && j!=8 )output[i][j]=" ";

			if(i==2&&j==0) output[i][j]=" ";
			if(i==2&&j!=0&&j!=4&&j!=8) output[i][j]="-";
			if(i==2 && (j==4 || j==8))  output[i][j]="+";

			if(i==3&&j==0) output[i][j]="2";
			if(i==3 && (j==4||j==8)) output[i][j]="|";
			if(i==3&&j!=0&&j!=4&&j!=8 )output[i][j]=" ";

			if(i==4&&j==0) output[i][j]=" ";
			if(i==4&&j!=0&&j!=4&&j!=8) output[i][j]="-";
			if(i==4 && (j==4 || j==8))  output[i][j]="+";

			if(i==5&&j==0) output[i][j]="3";
			if(i==5 && (j==4||j==8)) output[i][j]="|";
			if(i==5&&j!=0&&j!=4&&j!=8 )output[i][j]=" ";
		}

		for(i=0;i<6;i++)
		{
			for(j=0;j<12;j++)
			{
				cout<<output[i][j];
			}
			cout<<endl;
		}
		cout<<endl;


		int ii,jj;

		//initialize board
		for(ii=0;ii<3;ii++)
			for(jj=0;jj<3;jj++)
			{
				board[ii][jj].flag=false;
				board[ii][jj].value=-1;
			}

			int flagplayer=1;//judge whether the current step is 'X' or 'O'
			int x,y;
			bool ir,ic;

			
					cout<<"Please input two players' name: "<<endl;
					cout<<"Player1: ";
					cin>>playerA;
					cout<<"Player2: ";
					cin>>playerB;
					cout<<"Using X represents "<<playerA<<endl;
					cout<<"Using O represents "<<playerB<<endl;
					cout<<endl;
					while(false==CheckWhetherEnd())
					{
						cout<<"Please input row and column: "<<endl;						
						ir=cin>>InitialRow1;
						ic=cin>>InitialColumn1;
						InitialRow=InitialRow1-1;
						InitialColumn=InitialColumn1-1;	
						//asking user for a row and column number 
							while(InitialRow1<1||InitialRow1>3|| InitialColumn1<1||InitialColumn1>3||!ir||!ic||board[InitialRow][InitialColumn].flag==true)
						{
							cin.clear();
			               cin.sync();
							if(InitialRow1<1||InitialRow1>3|| InitialColumn1<1||InitialColumn1>3||!ir||!ic)
							{
							cout<<"Wrong input. Please try again."<<endl<<endl;
							cout<<"Please input row and column: "<<endl;							
							}
							else 
							{
								cout<<"this grid has been filled, please try other row or column: "<<endl<<endl;
							    cout<<"Please input row and column: "<<endl;
							}
							ir=cin>>InitialRow1;
							ic=cin>>InitialColumn1;
							InitialRow=InitialRow1-1;
						    InitialColumn=InitialColumn1-1;	
						}
							
					
						if(InitialRow==0) x=1;
						if(InitialRow==1)x=3;
						if(InitialRow==2)x=5;
						if(InitialColumn==0) y=2;
						if(InitialColumn==1)y=6;
						if(InitialColumn==2)y=10;
						
						if(flagplayer%2==1) 
						{

							output[x][y]="X";
							board[InitialRow][InitialColumn].value=3;//using value 3 represents X
							board[InitialRow][InitialColumn].flag=true;//now this grid has been filled

							for(i=0;i<6;i++)
							{
								for(j=0;j<12;j++)
								{
									cout<<output[i][j];
								}
								cout<<endl;
							}
							cout<<endl;
						}
						else
						{
							output[x][y]="O";
							board[InitialRow][InitialColumn].value=2;//using value 3 represents X
							board[InitialRow][InitialColumn].flag=true;//now this grid has been filled

							for(i=0;i<6;i++)
							{
								for(j=0;j<12;j++)
								{
									cout<<output[i][j];
								}
								cout<<endl;
							}
							cout<<endl;

						}
						flagplayer++;

					}
					cout<<Winner<<" wins"<<endl;
					cout<<"game over"<<endl;			
			
			return 0;
}
