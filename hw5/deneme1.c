#include <stdio.h>
#include <stdlib.h>
void initBoard(char *board);
void switc(char arr[],int i);
void switc2(char arr[],int i);
int isPieceMovable(char *board);
void emptyBuffer();
void printBoard(char *board);
void getPosition(char *col,int *row);
int isValidCell(char col,int row);
int find_stone(char col,int row);
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow);
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow);
void emptyBuffer()
{
	while ( getchar() != '\n' );
}
int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}
void initBoard(char *board)
{
	int i,j;
	j=1;
	for(i=0; i<16; i++)
	{
		switc(board,i);		
		if(i>7)
		{	
			board[i]='p';
		}	
	}
	for(i=16; i<48; i++)
	{
		board[i]=' ';
	}	
	for(i=48; i<64; i++)
	{
		if(i<56)
		{
			board[i]=' ';
		}		
		switc2(board,i);		
	}
	printBoard(board);
}
void printBoard(char *board)
{
	int i,k,j;
	j=8;
	k=7;
	printf("  a b c d e f g h \n");
	for(i=0; i<8; i++)
	{
		if(i==0)
			printf("  - ");
		else
		printf("- ");

	}
	printf("\n");
	for(i=0; i<64; i++)
	{					
		if(i==0)
		{
			printf("%d",j);
			printf("|");		
			printf("%c",board[i]);		
		}
		else if(i==8 || i==56 || i==48 || i==24 || i==16 || i==32 || i==40){		
		printf("%c",board[i]);
}
		else
			printf("%2c",board[i]);
		if(i==k)
		{
			printf("|");
			printf("\n");
			j--;
			if(j!=0)
			{		
				printf("%d",j);						
				printf("|");			
			}			
			k+=8;		
		}
	}
	for(i=0; i<8; i++)
	{
		if(i==0)
			printf("  - ");
		else
		printf("- ");
		
	}
	printf("\n");

}
int isPieceMovable(char *board)
{
	char sourceCol;
	int sourceRow;
	char targetCol;
	int targetRow;
	getPosition(&sourceCol,&sourceRow);
	getPosition(&targetCol,&targetRow);
	if(isValidCell(sourceCol,sourceRow)==0 || isValidCell(targetCol,targetRow)==0)
		return 0; 
	switch(board[find_stone(sourceCol,sourceRow)])
{
	case 'p':
	case 'P':return isPawnMovable(board,sourceCol,sourceRow,targetCol,
targetRow);	break;	
	case 'r':
	case 'R':return isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			break;
	case 'k':
	case 'K':return isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			break;
	case 'n':
	case 'N':return isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			break;	
	case 'q':
	case 'Q':return isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			break;	
	case 'b':
	case 'B':return isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			break;
	default: return 0;
}
}
void switc(char arr[],int i)
{
		switch(i){
		case 0:arr[i]='r';break;
		case 1:arr[i]='n';break;
		case 2:arr[i]='b';break;
		case 3:arr[i]='q';break;
		case 4:arr[i]='k';break;
		case 5:arr[i]='b';break;
		case 6:arr[i]='n';break;
		case 7:arr[i]='r';break;	
		default:break;		
		}

}
void switc2(char arr[],int i)
{
	switch(i){
		case 56:arr[i]='R';break;
		case 57:arr[i]='N';break;
		case 58:arr[i]='B';break;
		case 59:arr[i]='Q';break;
		case 60:arr[i]='K';break;
		case 61:arr[i]='B';break;
		case 62:arr[i]='N';break;
		case 63:arr[i]='R';break;
		default:break;		
	}
	
}
void getPosition(char *col,int *row)
{
	*col='0';
	*row=0;
	scanf(" %c",col);
	scanf("%d",row);

}

int isValidCell(char col,int row)
{
	if((int)col>=97 && (int)col<=104 && row>=1 && row<=8)
		return 1;
	
	return 0;
}

int find_stone(char col,int row)
{
	int index_row;
	int index_col;
	int index_stone;
	index_col=abs((int)col-97);
	index_row=abs(8-row);
	index_stone=index_row*8 + index_col;
	if(index_stone>=0 && index_stone<=63)
		return index_stone;
	
}
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow)
{
	if(board[find_stone(sourceCol,sourceRow)]=='p')
	{
		if((int)targetCol==(int)sourceCol && targetRow-sourceRow==-1 && 
board[find_stone(targetCol,targetRow)]==' ')
			return 1;
	else if(abs((int)targetCol-(int)sourceCol==1) &&  targetRow-sourceRow==-1 && 
	(int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
	(targetCol,targetRow)]<=90)
		return 1;
 	
	}
	else if(board[find_stone(sourceCol,sourceRow)]=='P')
	{
		if((int)targetCol==(int)sourceCol && targetRow-sourceRow==1 && 
board[find_stone(targetCol,targetRow)]==' ')
			return 1;
		else if(abs((int)targetCol-(int)sourceCol==1) &&  targetRow-sourceRow==1 && 
	(int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
	(targetCol,targetRow)]<=122)
		return 1;
	}
	return 0;
}
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow)
{
	if(board[find_stone(sourceCol,sourceRow)]=='r' || board[find_stone
(sourceCol,sourceRow)]=='q' )	
	{	if(sourceCol==targetCol && abs(targetRow-sourceRow)==1 && !((int)board[
find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,
targetRow)]<=122))
		return 1;
	
	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==2 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow-1)]==' ')
		return 1;
	
	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==3 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==4 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ')
		return 1;
	
	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==5 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ' && board[find_stone
(targetCol,targetRow-4)]==' ')
		return 1;

	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==6 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ' && board[find_stone
(targetCol,targetRow-4)]==' ' && board[find_stone(targetCol,targetRow-5)]==' ')
		return 1;

	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==7 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ' && board[find_stone
(targetCol,targetRow-4)]==' ' && board[find_stone(targetCol,targetRow-5)]==' '
 && board[find_stone(targetCol,targetRow-6)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==2 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow+1)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==3 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' ')
		return 1;


	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==4 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' )
		return 1;


	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==5 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' && board[find_stone
(targetCol,targetRow+4)]==' ' )
		return 1;
	

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==6 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' && board[find_stone
(targetCol,targetRow+4)]==' ' && board[find_stone(targetCol,targetRow+5)]==' ')
		return 1;

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==7 && !((int)board[find_stone(targetCol,targetRow)]>=97
 && (int)board[find_stone(targetCol,targetRow)]<=122) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' && board[find_stone
(targetCol,targetRow+4)]==' ' && board[find_stone(targetCol,targetRow+5)]==' '
 && board[find_stone(targetCol,targetRow+6)]==' ' )
		return 1;

	else if(sourceRow==targetRow && abs((int)sourceCol-(int)targetCol)==1 && 
!((int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
(targetCol,targetRow)]<=122))
		return 1;
	
	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==2 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122)
&& board[find_stone((char)((int)targetCol-1),targetRow)]==' ')
		return 1;
	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow &&
 abs((int)sourceCol-(int)targetCol)==3 && !((int)board[find_stone
(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,targetCol)]<=122)
 && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow &&
 abs((int)sourceCol-(int)targetCol)==4 && !((int)board
[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==5 && !((int)board
[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-4),targetRow)]==' ' )
		return 1;
	
		else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==6 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-5),targetRow)]==' ' )
		return 1;

		else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==7 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-5),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-6),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==2 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ')
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==3 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ')
		return 1;


	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==4 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==5 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+4),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==6 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+5),targetRow)]==' '  )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==7 && !((int)
board[find_stone(targetCol,targetCol)]>=97 && (int)board[find_stone(targetCol,
targetCol)]<=122) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+5),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+6),targetRow)]==' ' )
		return 1;
	
	else return 0;
}
	else
{
	if(sourceCol==targetCol && abs(targetRow-sourceRow)==1 && !((int)board[
find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,
targetRow)]<=90))
		return 1;
	
	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==2 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow-1)]==' ')
		return 1;
	
	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==3 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==4 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ')
		return 1;
	
	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==5 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ' && board[find_stone
(targetCol,targetRow-4)]==' ')
		return 1;

	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==6 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ' && board[find_stone
(targetCol,targetRow-4)]==' ' && board[find_stone(targetCol,targetRow-5)]==' ')
		return 1;

	else if(targetRow-sourceRow>=0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==7 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow-1)]==' ' && board[find_stone(targetCol,targetRow-2)]==' '
 && board[find_stone(targetCol,targetRow-3)]==' ' && board[find_stone
(targetCol,targetRow-4)]==' ' && board[find_stone(targetCol,targetRow-5)]==' '
 && board[find_stone(targetCol,targetRow-6)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==2 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow+1)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==3 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' ')
		return 1;


	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==4 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' )
		return 1;


	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==5 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' && board[find_stone
(targetCol,targetRow+4)]==' ' )
		return 1;
	

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==6 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' && board[find_stone
(targetCol,targetRow+4)]==' ' && board[find_stone(targetCol,targetRow+5)]==' ')
		return 1;

	else if(targetRow-sourceRow<0 && sourceCol==targetCol && 
abs(targetRow-sourceRow)==7 && !((int)board[find_stone(targetCol,targetRow)]>=65
 && (int)board[find_stone(targetCol,targetRow)]<=90) && board[find_stone
(targetCol,targetRow+1)]==' ' && board[find_stone(targetCol,targetRow+2)]==' '
 && board[find_stone(targetCol,targetRow+3)]==' ' && board[find_stone
(targetCol,targetRow+4)]==' ' && board[find_stone(targetCol,targetRow+5)]==' '
 && board[find_stone(targetCol,targetRow+6)]==' ' )
		return 1;


	else if(sourceRow==targetRow && abs((int)sourceCol-(int)targetCol)==1 && 
!((int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
(targetCol,targetRow)]<=90))
		return 1;
	
	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==2 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90)
&& board[find_stone((char)((int)targetCol-1),targetRow)]==' ')
		return 1;
	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow &&
 abs((int)sourceCol-(int)targetCol)==3 && !((int)board[find_stone
(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,targetCol)]<=90)
 && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow &&
 abs((int)sourceCol-(int)targetCol)==4 && !((int)board
[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==5 && !((int)board
[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-4),targetRow)]==' ' )
		return 1;
	
		else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==6 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-5),targetRow)]==' ' )
		return 1;

		else if((int)targetCol-(int)sourceCol>=0 && sourceRow==targetRow && 
abs((int)sourceCol-(int)targetCol)==7 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol-1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol-2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol-3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-5),targetRow)]==' ' && board[find_stone
((char)((int)targetCol-6),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==2 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ')
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==3 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ')
		return 1;


	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==4 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==5 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+4),targetRow)]==' ' )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==6 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+5),targetRow)]==' '  )
		return 1;

	else if((int)targetCol-(int)sourceCol<0 && sourceRow==targetRow && 
abs((int)sourceCol+(int)targetCol)==7 && !((int)
board[find_stone(targetCol,targetCol)]>=65 && (int)board[find_stone(targetCol,
targetCol)]<=90) && board[find_stone((char)((int)targetCol+1),targetRow)]==' ' 
&& board[find_stone((char)((int)targetCol+2),targetRow)]==' ' && board
[find_stone((char)((int)targetCol+3),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+4),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+5),targetRow)]==' ' && board[find_stone
((char)((int)targetCol+6),targetRow)]==' ' )
		return 1;

	else return 0;

}

}
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow)
{
	if(board[find_stone(sourceCol,sourceRow)]=='k')
{
	if(sourceCol==targetCol && abs(targetRow-sourceRow)==1 && !((int)board[
find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
(targetCol,targetRow)]<=122))
		return 1;
	else if(sourceRow==targetRow && abs((int)sourceCol-(int)targetCol)==1 && 
!((int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
(targetCol,targetRow)]<=122))
		return 1;
	else if(abs((int)targetCol-(int)sourceCol==1) &&  targetRow-sourceRow==1 && 
!((int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
	(targetCol,targetRow)]<=122))
		return 1;
	else return 0;

}
	else
{
	if(sourceCol==targetCol && abs(targetRow-sourceRow)==1 && !((int)board[
find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
(targetCol,targetRow)]<=90))
		return 1;
	else if(sourceRow==targetRow && abs((int)sourceCol-(int)targetCol)==1 && 
!((int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
(targetCol,targetRow)]<=90))
		return 1;
	else if(abs((int)targetCol-(int)sourceCol==1) && abs(targetRow-sourceRow)==1
 && !((int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
	(targetCol,targetRow)]<=90))
		return 1;
	else return 0;
}

}
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow)
{
	if(board[find_stone(sourceCol,sourceRow)]=='b')
{
	if(abs((int)targetCol-(int)sourceCol==1) &&  abs(targetRow-sourceRow)==1 &&
!((int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
(targetCol,targetRow)]<=122))
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==2) && 
 abs(targetRow-sourceRow)==2 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==3) &&  
abs(targetRow-sourceRow)==3 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' )
		return 1;
	
	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==4) &&
  abs(targetRow-sourceRow)==4 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' && 
board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==5) &&
  abs(targetRow-sourceRow)==5 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' && 
board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' &&
 board[find_stone((char)((int)targetCol-4),targetRow-4)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==6) && 
 abs(targetRow-sourceRow)==6 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' &&
 board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' &&
 board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' && 
board[find_stone((char)((int)targetCol-4),targetRow-4)]==' ' &&
 board[find_stone((char)((int)targetCol-5),targetRow-5)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==7) &&
  abs(targetRow-sourceRow)==7 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' &&
 board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' && 
board[find_stone((char)((int)targetCol-4),targetRow-4)]==' ' && 
board[find_stone((char)((int)targetCol-5),targetRow-5)]==' ' && 
board[find_stone((char)((int)targetCol-6),targetRow-6)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==2) &&
abs(targetRow-sourceRow)==2 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==3) &&
abs(targetRow-sourceRow)==3 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' '  )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==4) &&
abs(targetRow-sourceRow)==4 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==5) &&
abs(targetRow-sourceRow)==5 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' && 
board[find_stone((char)((int)targetCol+4),targetRow+4)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==6) &&
abs(targetRow-sourceRow)==6 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' && 
board[find_stone((char)((int)targetCol+4),targetRow+4)]==' ' && 
board[find_stone((char)((int)targetCol+5),targetRow+5)]==' ')
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==7) &&
abs(targetRow-sourceRow)==7 && !((int)board[find_stone
(targetCol,targetRow)]>=97 && (int)board[find_stone(targetCol,targetRow)]<=122) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' && 
board[find_stone((char)((int)targetCol+4),targetRow+4)]==' ' && 
board[find_stone((char)((int)targetCol+5),targetRow+5)]==' ' && 
board[find_stone((char)((int)targetCol+6),targetRow+6)]==' ' )
		return 1;


	else return 0;
}
	else
{
	if(abs((int)targetCol-(int)sourceCol==1) &&  abs(targetRow-sourceRow)==1 &&
!((int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
(targetCol,targetRow)]<=90))
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==2) && 
 abs(targetRow-sourceRow)==2 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==3) &&  
abs(targetRow-sourceRow)==3 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' )
		return 1;
	
	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==4) &&
  abs(targetRow-sourceRow)==4 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' && 
board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==5) &&
  abs(targetRow-sourceRow)==5 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' && 
board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' &&
 board[find_stone((char)((int)targetCol-4),targetRow-4)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==6) && 
 abs(targetRow-sourceRow)==6 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90)
 && board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' &&
 board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' &&
 board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' && 
board[find_stone((char)((int)targetCol-4),targetRow-4)]==' ' &&
 board[find_stone((char)((int)targetCol-5),targetRow-5)]==' ' )
		return 1;

	else if(targetRow-sourceRow>=0 && abs((int)targetCol-(int)sourceCol==7) &&
  abs(targetRow-sourceRow)==7 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol-1),targetRow-1)]==' ' && 
board[find_stone((char)((int)targetCol-2),targetRow-2)]==' ' &&
 board[find_stone((char)((int)targetCol-3),targetRow-3)]==' ' && 
board[find_stone((char)((int)targetCol-4),targetRow-4)]==' ' && 
board[find_stone((char)((int)targetCol-5),targetRow-5)]==' ' && 
board[find_stone((char)((int)targetCol-6),targetRow-6)]==' ' )
		return 1;
	
	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==2) &&
abs(targetRow-sourceRow)==2 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==3) &&
abs(targetRow-sourceRow)==3 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' '  )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==4) &&
abs(targetRow-sourceRow)==4 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==5) &&
abs(targetRow-sourceRow)==5 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' && 
board[find_stone((char)((int)targetCol+4),targetRow+4)]==' ' )
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==6) &&
abs(targetRow-sourceRow)==6 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' && 
board[find_stone((char)((int)targetCol+4),targetRow+4)]==' ' && 
board[find_stone((char)((int)targetCol+5),targetRow+5)]==' ')
		return 1;

	else if(targetRow-sourceRow<0 && abs((int)targetCol-(int)sourceCol==7) &&
abs(targetRow-sourceRow)==7 && !((int)board[find_stone
(targetCol,targetRow)]>=65 && (int)board[find_stone(targetCol,targetRow)]<=90) 
&& board[find_stone((char)((int)targetCol+1),targetRow+1)]==' ' && 
board[find_stone((char)((int)targetCol+2),targetRow+2)]==' ' &&
 board[find_stone((char)((int)targetCol+3),targetRow+3)]==' ' && 
board[find_stone((char)((int)targetCol+4),targetRow+4)]==' ' && 
board[find_stone((char)((int)targetCol+5),targetRow+5)]==' ' && 
board[find_stone((char)((int)targetCol+6),targetRow+6)]==' ' )
		return 1;

	else return 0;

}

}

int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow)
{
	if(board[find_stone(sourceCol,sourceRow)]=='n')
	{
		if(abs((int)sourceCol-(int)targetCol)==2 && abs(sourceRow-targetRow)==1
&& !((int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
(targetCol,targetRow)]<=122))
			return 1;
		else if(abs((int)sourceCol-(int)targetCol)==1 && abs(sourceRow-targetRow)==2
&& !((int)board[find_stone(targetCol,targetRow)]>=97 && (int)board[find_stone
(targetCol,targetRow)]<=122))
			return 1;
	else return 0;
	}
	else
{
			if(abs((int)sourceCol-(int)targetCol)==2 && abs(sourceRow-targetRow)==1
&& !((int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
(targetCol,targetRow)]<=90))
			return 1;
		else if(abs((int)sourceCol-(int)targetCol)==1 && abs(sourceRow-targetRow)==2
&& !((int)board[find_stone(targetCol,targetRow)]>=65 && (int)board[find_stone
(targetCol,targetRow)]<=90))
			return 1;

		else return 0;
}
}
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,
int targetRow)
{
	if(sourceCol==sourceRow || sourceRow==targetRow)
		return	isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
	else
		return isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);

}


