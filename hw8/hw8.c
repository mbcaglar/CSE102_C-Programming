#include <stdio.h>
/***********************************************************/
/*                M.BEDİRHAN ÇAĞLAR                        */
/*                                                         */
/*                  22.04.2016                             */
/*                                                         */
/* Bu program bir satranç oyunu olup şah çekildiği halde   */
/*iki hatalı hamle yapıldığında mat olduğunu bildirerek    */
/* oyunu sonlandırmaktadır.                                */
/***********************************************************/
#define BOARD_SIZE 8
int find_stone(char col,int row);/*tasin indexini return eder*/

int isInCheck(char* board);/*siyahın şah olup olmama durumunu return eder*/

int makeMove(char *board, char sc, int sr, char tc, int tr);/*taşları 
hareket ettirip şah durumunu yada kendine çekilen şahı return eder*/
void initBoard(char *board); /* boardın initialize gerçekleşir */
int isValidCell(char col,int row);/*girilen hamlenin board da olup olmamasını
return eder */
void printBoard(char *board);/*tabloyu yazdırır*/
void switc(char arr[],int i);/* kücük harfli tasların yerlestirilmesidir */
void switc2(char arr[],int i);/* büyük harfli tasların yerlestirilmesidir */

void getPosition(char *col,int *row);/*source ve target değerlerini alır*/
char getPlayer(char *board,char sc,int sr);/*oynanan taşı return eder*/

/* taşların hareketini uygun olup olmadığına bakarak gerçekleitirir*/

int isRookMovable(char *board,char sc,int sr,char tc,
int tr);
int isPawnMovable(char *board,char sc,int sr,char tc,
int tr);
int isKingMovable(char *board,char sc,int sr,char tc,
int tr);
int isBishopMovable(char *board,char sc,int sr,char tc,
int tr);
int isKnightMovable(char *board,char sc,int sr,char tc,
int tr);
int isQueenMovable(char *board,char sc,int sr,char tc,
int tr);

/*kalenin oynanack targeta kadar gerçekleşip gerçekleşmeyeceğini
bu fonksiyonlar yardımı ile kontrol ederiz*/ 

int kale_bosluk1(char *board,char sc,int sr,char tc,int tr);
int kale_bosluk2(char *board,char sc,int sr,char tc,int tr);
int kale_bosluk3(char *board,char sc,int sr,char tc,int tr);
int kale_bosluk4(char *board,char sc,int sr,char tc,int tr);

/*filin oynanack targeta kadar gerçekleşip gerçekleşmeyeceğini
bu fonksiyonlar yardımı ile kontrol ederiz*/ 

int bosluk1(char *board,char sc,int sr,char tc,int tr);
int bosluk2(char *board,char sc,int sr,char tc,int tr);
int bosluk3(char *board,char sc,int sr,char tc,int tr);
int bosluk4(char *board,char sc,int sr,char tc,int tr);
/*oynayacağın taşın senin taşın olup olmadığını bu fonksiyonlar ile kontrol 
ederiz*/
int isWhite(char currPlayer);
int isBlack(char currPlayer);

/*beyazın şah olup olmama durumunu return eder*/
int isinCheck(char* board);

/*bu fonksiyonlar şahın etrafında kale veya vezir olup olmamasını konrol ederek şah
çekilip çekilmediğini return eder */
int sah_kale_bosluk1(char *board,char sc,int sr);
int sah_kale_bosluk2(char *board,char sc,int sr);
int sah_kale_bosluk3(char *board,char sc,int sr);
int sah_kale_bosluk4(char *board,char sc,int sr);

/*bu fonksiyonlar şahın etrafında fil veya vezir olup olmamasını konrol ederek şah
çekilip çekilmediğini return eder */
int sah_fil_bosluk1(char *board,char sc,int sr);
int sah_fil_bosluk2(char *board,char sc,int sr);
int sah_fil_bosluk3(char *board,char sc,int sr);
int sah_fil_bosluk4(char *board,char sc,int sr);

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black"); 
		getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
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
			board[i]='P';
		}		
		switc2(board,i);		
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

void printBoard(char *board)
{
	int i,k,j;
	j=8;
	k=7;
	printf("  a b c d e f g h \n");
    printf("  - - - - - - - - \n");
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
char getPlayer(char *board,char sc,int sr)
{
	return board[find_stone(sc,sr)];
}
int isBlack(char currPlayer)
{
	switch(currPlayer)
	{
		case 'p':	
		case 'r':
		case 'n':
		case 'b':
		case 'q':
		case 'k':return 1; break;	
		default: return 0; break;		
	
	}

}
int isWhite(char currPlayer)
{
		switch(currPlayer)
	{
		case 'P':		
		case 'R':
		case 'N':
		case 'B':
		case 'Q':
		case 'K':return 1; 
				 break;	
		default: return 0; break;		
	
	}
}
int find_stone(char col,int row)/*tasin indexini return eder.2 boyutlu arrayi */
{								/*tek boyuta indirir */
	int index_row;
	int index_col;
	int index_stone;
	index_col=abs((int)col-97);
	index_row=abs(8-row);
	index_stone=index_row*8 + index_col;
	if(index_stone>=0 && index_stone<=63)
		return index_stone;
	

    return 0;
}
int isPieceMovable(char *board,char sc,int sr,char tc,int tr)
{
	switch(board[find_stone(sc,sr)])
	{
		case 'p':
		case 'P':return isPawnMovable(board,sc,sr,tc,tr);	
				break;	
		case 'r':
		case 'R':return isRookMovable(board,sc,sr,tc,tr);
				break;
		case 'k':
		case 'K':return isKingMovable(board,sc,sr,tc,tr);
				break;
		case 'n':
		case 'N':return isKnightMovable(board,sc,sr,tc,tr);
				break;	
		case 'q':if(isQueenMovable(board,sc,sr,tc,tr)==1)
					{
					board[find_stone(tc,tr)]='q';
					board[find_stone(sc,sr)]=' ';			
						return 1;
					}
					return 0;
					break;

		case 'Q':	if(isQueenMovable(board,sc,sr,tc,tr)==1)
					{
					board[find_stone(tc,tr)]='Q';
					board[find_stone(sc,sr)]=' ';			
						return 1;
					}
					return 0;
					break;
		case 'b':
		case 'B':return isBishopMovable(board,sc,sr,tc,tr);
				break;
		default: return 0;
	}
}
int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	
	if(isPieceMovable(board,sc,sr,tc,tr)==1)
	{	
		if((board[find_stone(tc,tr)]>=65 && (int)board
[find_stone(tc,tr)]<=90 && isinCheck(board)==1) || (board[find_stone(tc,tr)]>=97
 && board[find_stone(tc,tr)]<=122 && isInCheck(board)==1)){
		isPieceMovable(board,tc,tr,sc,sr);	
		return 1;
	}		

		if((int)board[find_stone(tc,tr)]>=65 && (int)board
[find_stone(tc,tr)]<=90 ){
			if(isInCheck(board)==1)
				return 3;
		}
		else if((int)board[find_stone(tc,tr)]>=97 && 
(int)board[find_stone(tc,tr)]<=122 ){
			if(isinCheck(board)==1)
				return 3;
		}
		return 2;
	}	
	else
		return 0;

		
}	
int isInCheck(char* board)
{
	char col_index;
	char col;
	int row;
	int i;

	for(i=0; i<64; i++)
	{
		if(board[i]=='k')
		{
			col_index=(i%8)+1;
			row=9-((i/8)+1);
			break;
		}
	}
			switch(col_index){
			
			case 1:col='a';
					break;
			case 2:col='b';
					break;
			case 3:col='c';
					break;
			case 4:col='d';
					break;
			case 5:col='e';
					break;
			case 6:col='f';
					break;
			case 7:col='g';
					break;
			case 8:col='h';
					break;
			default:break;
		}			

		if(board[find_stone(col+1,row-1)]=='P' || 
board[find_stone(col-1,row-1)]=='P')
				return 1;

		else if(board[find_stone(col+2,row-1)]=='N' || 
board[find_stone(col-2,row-1)]=='N' || board[find_stone(col+2,row+1)]=='N' ||
board[find_stone(col-2,row+1)]=='N' || board[find_stone(col+1,row-2)]=='N' || 
board[find_stone(col+1,row+2)]=='N' || board[find_stone(col-1,row-2)]=='N' || 
board[find_stone(col-1,row+2)]=='N' )
				return 1;

	else if(sah_kale_bosluk1(board,col,row)==1 || 
sah_kale_bosluk2(board,col,row)==1 || sah_kale_bosluk3(board,col,row)==1 ||
sah_kale_bosluk4(board,col,row)==1 )			
				return 1;

	else if(sah_fil_bosluk1(board,col,row)==1 || 
sah_fil_bosluk2(board,col,row)==1 || sah_fil_bosluk3(board,col,row)==1 ||
sah_fil_bosluk4(board,col,row)==1 )					
				return 1;
		return 0;

}
int isinCheck(char* board)
{
	char col_index;
	char col;
	int row;
	int i;

	for(i=0; i<64; i++)
	{
		if(board[i]=='K')
		{
			col_index=(i%8)+1;
			row=9-((i/8)+1);
			break;
		}
	}
			switch(col_index){
			
			case 1:col='a';
					break;
			case 2:col='b';
					break;
			case 3:col='c';
					break;
			case 4:col='d';
					break;
			case 5:col='e';
					break;
			case 6:col='f';
					break;
			case 7:col='g';
					break;
			case 8:col='h';
					break;
			default:break;
		}			

		if(board[find_stone(col+1,row+1)]=='p' || 
board[find_stone(col-1,row+1)]=='p')
				return 1;

		else if(board[find_stone(col+2,row-1)]=='n' || 
board[find_stone(col-2,row-1)]=='n' || board[find_stone(col+2,row+1)]=='n' ||
board[find_stone(col-2,row+1)]=='n' || board[find_stone(col+1,row-2)]=='n' || 
board[find_stone(col+1,row+2)]=='n' || board[find_stone(col-1,row-2)]=='n' || 
board[find_stone(col-1,row+2)]=='n' )
			return 1;

	else if(sah_kale_bosluk1(board,col,row)==1 || 
sah_kale_bosluk2(board,col,row)==1 || sah_kale_bosluk3(board,col,row)==1 ||
sah_kale_bosluk4(board,col,row)==1 )
			return 1;

	else if(sah_fil_bosluk1(board,col,row)==1 || 
sah_fil_bosluk2(board,col,row)==1 || sah_fil_bosluk3(board,col,row)==1 ||
sah_fil_bosluk4(board,col,row)==1 )
		   return 1;

		return 0;
}

int isPawnMovable(char *board,char sc,int sr,char tc,int tr)
{
	if(board[find_stone(sc,sr)]=='p')
	{
		if(tc==sc && tr-sr==-2 && sr==7 &&
board[find_stone(tc,tr)]==' ' && board[find_stone(sc,sr-1)]==' ' )
		{
			board[find_stone(tc,tr)]='p';
			board[find_stone(sc,sr)]=' ';			
				return 1;
		}


	else if(tc==sc && tr-sr==-1 && board[find_stone(tc,tr)]==' ')
		{
			board[find_stone(tc,tr)]='p';
			board[find_stone(sc,sr)]=' ';			
				return 1;
		}
	else if(abs(tc-sc)==1 &&  tr-sr==-1 && 
	(int)board[find_stone(tc,tr)]>=65 && (int)board[find_stone
	(tc,tr)]<=90)
		{
			board[find_stone(tc,tr)]='p';
			board[find_stone(sc,sr)]=' ';			
			return 1;
		}
	}
	else 
	{
		if(tc==sc && tr-sr==2 && sr==2 &&
board[find_stone(tc,tr)]==' ' && board[find_stone(sc,sr+1)]==' ')
		{
			board[find_stone(tc,tr)]='P';
			board[find_stone(sc,sr)]=' ';			
				return 1;
		}

	else if(tc==sc && tr-sr==1 && 
board[find_stone(tc,tr)]==' ')
		{
			board[find_stone(tc,tr)]='P';
			board[find_stone(sc,sr)]=' ';			
			return 1;
		}	
		else if(abs(tc-sc)==1 &&  tr-sr==1 && 
	(int)board[find_stone(tc,tr)]>=97 && (int)board[find_stone
	(tc,tr)]<=122)
		{
			board[find_stone(tc,tr)]='P';
			board[find_stone(sc,sr)]=' ';			
			return 1;
		}	
		
	}
	return 0;
}
int isRookMovable(char *board,char sc,int sr,char tc,
int tr)
{
	if(board[find_stone(sc,sr)]=='r' || board[find_stone
(sc,sr)]=='q' )	/* q ve r kontrolü ilerde vezir fonksiyonumda 
kaleyi çağırdığım icindir */
	{	
		if(sc==tc && abs(tr-sr)==1 && !((int)board[find_stone(tc,tr)]>=97 && 
(int)board[find_stone(tc,tr)]<=122))
		{		
			if(board[find_stone(sc,sr)]=='r')
			{
				board[find_stone(tc,tr)]='r';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}
		else if(abs(sc-tc)==1 && tr==sr && !((int)board[
find_stone(tc,tr)]>=97 && (int)board[find_stone(tc,
tr)]<=122))
		{		
			if(board[find_stone(sc,sr)]=='r')
			{
				board[find_stone(tc,tr)]='r';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}
		else if(sc==tc	&& tr-sr>1 && !((int)board[find_stone(tc,tr)]>=97 && 
(int)board[find_stone(tc,tr)]<=122) )
	{	
		if(kale_bosluk1(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='r')
			{
				board[find_stone(tc,tr)]='r';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(sc==tc	&& tr-sr<0 && !((int)board[find_stone(tc,tr)]>=97 && 
(int)board[find_stone(tc,tr)]<=122) )
	{	
		if(kale_bosluk2(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='r')
			{
				board[find_stone(tc,tr)]='r';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tc-sc<0 && tr==sr && !((int)board[find_stone(tc,tr)]>=97 && 
(int)board[find_stone(tc,tr)]<=122))
	{	
		if(kale_bosluk3(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='r')
			{
				board[find_stone(tc,tr)]='r';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tc-sc>0 && tr==sr && !((int)board[find_stone(tc,tr)]>=97 && 
(int)board[find_stone(tc,tr)]<=122) )
	{	
		if(kale_bosluk4(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='r')
			{
				board[find_stone(tc,tr)]='r';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else return 0;
}
	else
{
		if(sc==tc && abs(tr-sr)==1 && !((int)board[
find_stone(tc,tr)]>=65 && (int)board[find_stone(tc,
tr)]<=90))
		{		
			if(board[find_stone(sc,sr)]=='R')
			{
				board[find_stone(tc,tr)]='R';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

		else if(abs(sc-tc)==1 && tr==sr && !((int)board[
find_stone(tc,tr)]>=65 && (int)board[find_stone(tc,
tr)]<=90))
		{		
			if(board[find_stone(sc,sr)]=='R')
			{
				board[find_stone(tc,tr)]='R';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

		else if(sc==tc	&& tr-sr>0 && !((int)board[find_stone(tc,tr)]>=65 && 
(int)board[find_stone(tc,tr)]<=90) )
	{	
		if(kale_bosluk1(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='R')
			{
				board[find_stone(tc,tr)]='R';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		

		else if(sc==tc	&& tr-sr<0 && !((int)board[find_stone(tc,tr)]>=65 && 
(int)board[find_stone(tc,tr)]<=90) )
	{	
		if(kale_bosluk2(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='R')
			{
				board[find_stone(tc,tr)]='R';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tc-sc>0 && tr==sr && 
!((int)board[find_stone(tc,tr)]>=65 && 
(int)board[find_stone(tc,tr)]<=90))
	{	
		if(kale_bosluk4(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='R')
			{
				board[find_stone(tc,tr)]='R';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tc-sc<0 && tr==sr && 
!((int)board[find_stone(tc,tr)]>=65 && 
(int)board[find_stone(tc,tr)]<=90) )
	{	
		if(kale_bosluk3(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='R')
			{
				board[find_stone(tc,tr)]='R';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else return 0;

}

}
int isKingMovable(char *board,char sc,int sr,char tc,
int tr)
{
	if(board[find_stone(sc,sr)]=='k')
{
	if(sc==tc && abs(tr-sr)==1 && !((int)board[
find_stone(tc,tr)]>=97 && (int)board[find_stone
(tc,tr)]<=122))
{
		board[find_stone(tc,tr)]='k';
		board[find_stone(sc,sr)]=' ';			
				return 1;
}
	else if(sr==tr && abs(sc-tc)==1 && 
!((int)board[find_stone(tc,tr)]>=97 && (int)board[find_stone
(tc,tr)]<=122))
{
		board[find_stone(tc,tr)]='k';
		board[find_stone(sc,sr)]=' ';			
				return 1;
}
	else if(abs(tc-sc)==1 &&  abs(tr-sr)==1 && 
!((int)board[find_stone(tc,tr)]>=97 && (int)board[find_stone
	(tc,tr)]<=122))
{
		board[find_stone(tc,tr)]='k';
		board[find_stone(sc,sr)]=' ';			
				return 1;
}
	else return 0;

}
	else
{
	if(sc==tc && abs(tr-sr)==1 && !((int)board[
find_stone(tc,tr)]>=65 && (int)board[find_stone
(tc,tr)]<=90))
{
		board[find_stone(tc,tr)]='K';
		board[find_stone(sc,sr)]=' ';			
				return 1;
}

	else if(sr==tr && abs(sc-tc)==1 && 
!((int)board[find_stone(tc,tr)]>=65 && (int)board[find_stone
(tc,tr)]<=90))
{
		board[find_stone(tc,tr)]='K';
		board[find_stone(sc,sr)]=' ';			
				return 1;
}
	else if(abs(tc-sc)==1 && abs(tr-sr)==1
 && !((int)board[find_stone(tc,tr)]>=65 && (int)board[find_stone
	(tc,tr)]<=90))
{
		board[find_stone(tc,tr)]='K';
		board[find_stone(sc,sr)]=' ';			
				return 1;
}
	else return 0;
}

}
int isBishopMovable(char *board,char sc,int sr,char tc,
int tr)
{
	if(board[find_stone(sc,sr)]=='b' || board[find_stone
(sc,sr)]=='q') /* q ve r kontrolü ilerde vezir fonksiyonumda fili çağırdığım icindir */
	{
		if(abs(tc-sc)==1 &&  abs(tr-sr)==1 &&
!((int)board[find_stone(tc,tr)]>=97 && (int)board[find_stone
(tc,tr)]<=122))
		{		
			if(board[find_stone(sc,sr)]=='b')
			{
				board[find_stone(tc,tr)]='b';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

		else if(tr-sr>0 && (int)tc-(int)sc>0 && 
!((int)board[find_stone(tc,tr)]>=97 && (int)board
[find_stone(tc,tr)]<=122 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk1(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='b')
			{
				board[find_stone(tc,tr)]='b';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tr-sr<0 && (int)tc-(int)sc<0 && 
!((int)board[find_stone(tc,tr)]>=97 && (int)board
[find_stone(tc,tr)]<=122 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk2(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='b')
			{
				board[find_stone(tc,tr)]='b';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tr-sr>0 && (int)tc-(int)sc<0 && 
!((int)board[find_stone(tc,tr)]>=97 && (int)board
[find_stone(tc,tr)]<=122 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk3(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='b')
			{
				board[find_stone(tc,tr)]='b';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tr-sr<0 && (int)tc-(int)sc>0 && 
!((int)board[find_stone(tc,tr)]>=97 && (int)board
[find_stone(tc,tr)]<=122 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk4(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='b')
			{
				board[find_stone(tc,tr)]='b';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else return 0;
}
	else{

		if(abs(tc-sc)==1 &&  abs(tr-sr)==1 &&
!((int)board[find_stone(tc,tr)]>=65 && (int)board[find_stone
(tc,tr)]<=90))
	{	
		if(board[find_stone(sc,sr)]=='B')
		{
			board[find_stone(tc,tr)]='B';
				board[find_stone(sc,sr)]=' ';			
		}	
			return 1;	
	}		
		else if(tr-sr>0 && (int)tc-(int)sc>0 && 
!((int)board[find_stone(tc,tr)]>=65 && (int)board
[find_stone(tc,tr)]<=90 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk1(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='B')
			{
				board[find_stone(tc,tr)]='B';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tr-sr<0 && (int)tc-(int)sc<0 && 
!((int)board[find_stone(tc,tr)]>=65 && (int)board
[find_stone(tc,tr)]<=90 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk2(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='B')
			{
				board[find_stone(tc,tr)]='B';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tr-sr>0 && (int)tc-(int)sc<0 && 
!((int)board[find_stone(tc,tr)]>=65 && (int)board
[find_stone(tc,tr)]<=90 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk3(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='B')
			{
				board[find_stone(tc,tr)]='B';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
		else if(tr-sr<0 && (int)tc-(int)sc>0 && 
!((int)board[find_stone(tc,tr)]>=65 && (int)board
[find_stone(tc,tr)]<=90 ) && abs(tc-sc)==abs(tr-sr))
	{	
		if(bosluk4(board,sc,sr,tc,tr)==1)
		{		
			if(board[find_stone(sc,sr)]=='B')
			{
				board[find_stone(tc,tr)]='B';
				board[find_stone(sc,sr)]=' ';			
			}	
				return 1;	
		}

	}		
	else return 0;
	}
}

int isKnightMovable(char *board,char sc,int sr,char tc,
int tr)
{
	if(board[find_stone(sc,sr)]=='n')
	{
		if(abs((int)sc-(int)tc)==2 && abs(sr-tr)==1
&& !((int)board[find_stone(tc,tr)]>=97 && (int)board[find_stone
(tc,tr)]<=122))
	{
		board[find_stone(tc,tr)]='n';
		board[find_stone(sc,sr)]=' ';			
				return 1;
	}		
		else if(abs((int)sc-(int)tc)==1 && abs(sr-tr)==2
&& !((int)board[find_stone(tc,tr)]>=97 && (int)board[find_stone
(tc,tr)]<=122))
	{
		board[find_stone(tc,tr)]='n';
		board[find_stone(sc,sr)]=' ';			
				return 1;
	}
		else return 0;
	}
	else
{
			if(abs((int)sc-(int)tc)==2 && abs(sr-tr)==1
&& !((int)board[find_stone(tc,tr)]>=65 && (int)board[find_stone
(tc,tr)]<=90))
	{
		board[find_stone(tc,tr)]='N';
		board[find_stone(sc,sr)]=' ';			
				return 1;
	}
		else if(abs((int)sc-(int)tc)==1 && abs(sr-tr)==2
&& !((int)board[find_stone(tc,tr)]>=65 && (int)board[find_stone
(tc,tr)]<=90))
	{
		board[find_stone(tc,tr)]='N';
		board[find_stone(sc,sr)]=' ';			
				return 1;
	}
		else return 0;
}
}
int isQueenMovable(char *board,char sc,int sr,char tc,
int tr)
{
	if(sc==tc || sr==tr)
		return	isRookMovable(board,sc,sr,tc,tr);
	else if(abs(sc-tc)==abs(sr-tr))
		return isBishopMovable(board,sc,sr,tc,tr);
	else return 0;
}
int bosluk1(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<tr-sr; i++)
	{
		if(board[find_stone(sc+i,sr+i)]!=' ')
			return 0;
	}
	return 1;
}
int bosluk2(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tr-sr); i++)
	{
		if(board[find_stone(tc+i,tr+i)]!=' ')
			return 0;
	}
	return 1;

}
int bosluk3(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tr-sr); i++)
	{
		if(board[find_stone(tc+i,tr-i)]!=' ')
			return 0;
	}
	return 1;

}
int bosluk4(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tr-sr); i++)
	{
		if(board[find_stone(tc-i,tr+i)]!=' ')
			return 0;
	}
	return 1;

}
int kale_bosluk1(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tr-sr); i++)
	{
		if(board[find_stone(tc,tr-i)]!=' ')
			return 0;
		
	}
	return 1;
}
int kale_bosluk2(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tr-sr); i++)
	{
		if(board[find_stone(tc,tr+i)]!=' ')
			return 0;
	}
	return 1;
}
int kale_bosluk3(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tc-sc); i++)
	{
		if(board[find_stone(tc+i,tr)]!=' ')
			return 0;
	}
	return 1;
}
int kale_bosluk4(char *board,char sc,int sr,char tc,int tr)
{
	int i;
	for(i=1; i<abs(tc-sc); i++)
	{
		if(board[find_stone(tc-i,tr)]!=' ')
			return 0;
	}
	return 1;
}
int sah_kale_bosluk1(char *board,char sc,int sr)
{
	int i;
	int tmp;
	tmp=sr+2;

	for(i=1; i<=8; i++)
	{
	if(tmp<=8){
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,sr+1)]=='Q' || board[find_stone(sc,sr+1)]=='R' ))
			return 1;
		
			if(kale_bosluk1(board,sc,sr,sc,tmp)==0)
					return 0;			

			else{
			
				if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,tmp)]=='Q' ||board[find_stone(sc,tmp)]=='R' ))
				return 1;
			}
		}

		else if(board[find_stone(sc,sr)]=='K')
		{	
			if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,sr+1)]=='q' || board[find_stone(sc,sr+1)]=='r' ))
				return 1;
		
			if(kale_bosluk1(board,sc,sr,sc,tmp)==0)
					return 0;			

			else
			{
			
				if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,tmp)]=='q' || board[find_stone(sc,tmp)]=='r' ))
				return 1;
			}
		}
	}	
		tmp++;
	}
	return 0;
}

int sah_kale_bosluk2(char *board,char sc,int sr)
{
	int i;
	int tmp;
	tmp=sr-2;
	for(i=1; i<=8; i++)
	{

	if(tmp>=1 && tmp <=6){

		if(board[find_stone(sc,sr)]=='k' )
		{
			if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,sr-1)]=='Q' || board[find_stone(sc,sr-1)]=='R' ))
				return 1;
		
			if(kale_bosluk2(board,sc,sr,sc,tmp)==0)
					return 0;			

			else
			{
				if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,tmp)]=='Q' ||board[find_stone(sc,tmp)]=='R' ))
					return 1;
			}
		}

		else if(board[find_stone(sc,sr)]=='K')
		{	
			if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,sr-1)]=='q' || board[find_stone(sc,sr-1)]=='r' ))
				return 1;
		
			if(kale_bosluk2(board,sc,sr,sc,tmp)==0)
					return 0;			

			else
			{
			
				if(find_stone(sc,tmp)<64 && find_stone(sc,tmp)>-1 && 
(board[find_stone(sc,tmp)]=='q' ||board[find_stone(sc,tmp)]=='r' ))
					return 1;
			}

		}
	}
		tmp--;
	}
	return 0;
}
int sah_kale_bosluk3(char *board,char sc,int sr)
{
	int i;
	char tmp;
	tmp=sc+2;
	for(i=1; i<=8; i++)
	{
	if(tmp<=106){
	
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(sc+1,sr)]=='Q' || board[find_stone(sc+1,sr)]=='R' ))
				return 1;
			if(kale_bosluk4(board,sc,sr,tmp,sr)==0)
					return 0;			
			else
			{
			
				if(find_stone(tmp,sr)<64 && (board[find_stone(tmp,sr)]=='Q' ||
 board[find_stone(tmp,sr)]=='R' ))
					return 1;
			}
		}
		else if(board[find_stone(sc,sr)]=='K')
		{
			if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(sc+1,sr)]=='q' || board[find_stone(sc+1,sr)]=='r' ))
				return 1;
			if(kale_bosluk4(board,sc,sr,tmp,sr)==0)
					return 0;			
			else
			{
			
				if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(tmp,sr)]=='q' || board[find_stone(tmp,sr)]=='r' ))
					return 1;
			}
		}	
	}
	tmp ++;

	}
	return 0;
}
int sah_kale_bosluk4(char *board,char sc,int sr)
{
	int i;
	char tmp;
	tmp=sc-2;
	for(i=1; i<=8; i++)
	{
	if(tmp>=97 && tmp<=104){
		
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(sc-1,sr)]=='Q' || board[find_stone(sc-1,sr)]=='R' ))
				return 1;
			if(kale_bosluk3(board,sc,sr,tmp,sr)==0)
					return 0;			
			else{
			
				if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(tmp,sr)]=='Q' || board[find_stone(tmp,sr)]=='R' ))
				return 1;
			}
		}
		else if(board[find_stone(sc,sr)]=='K')
		{
			if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(sc-1,sr)]=='q' || board[find_stone(sc-1,sr)]=='r' ))
				return 1;
			if(kale_bosluk3(board,sc,sr,tmp,sr)==0)
					return 0;			
			else
			{
				if(find_stone(tmp,sr)<64 && find_stone(tmp,sr)>-1 && 
(board[find_stone(tmp,sr)]=='q' || board[find_stone(tmp,sr)]=='r' ))
					return 1;
			}
		}
	}
		tmp --;
	}
	
	return 0;
}
int sah_fil_bosluk1(char *board,char sc,int sr)
{
	int i;
	char tmp_c;
	int tmp_i;
	
	tmp_c = sc+2;
	tmp_i = sr+2;
	for(i=1; i<=8; i++)
	{
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc+1,sr+1)]=='B' || board[find_stone(sc+1,sr+1)]=='Q'))
					return 1;
			if(bosluk1(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(tmp_c,tmp_i)]=='B' || board[find_stone(tmp_c,tmp_i)]=='Q'))
					return 1;
			}
		}
		else if(board[find_stone(sc,sr)]=='K')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc+1,sr+1)]=='b' || board[find_stone(sc+1,sr+1)]=='q'))
					return 1;
			if(bosluk1(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(tmp_c,tmp_i)]=='b' || board[find_stone(tmp_c,tmp_i)]=='q'))
					return 1;
			}
		}
		
		tmp_i++;
		tmp_c++; 
	}
	return 0;
}

int sah_fil_bosluk2(char *board,char sc,int sr)
{
	int i;
	char tmp_c;
	int tmp_i;
	
	tmp_c = sc-2;
	tmp_i = sr-2;
	for(i=1; i<=8; i++)
	{
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc-1,sr-1)]=='B' || board[find_stone(sc-1,sr-1)]=='Q'))
					return 1;
			if(bosluk2(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 && 
(board[find_stone(tmp_c,tmp_i)]=='B'|| board[find_stone(tmp_c,tmp_i)]=='Q'))
					return 1;
			}
		}
		else if(board[find_stone(sc,sr)]=='K')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc-1,sr-1)]=='b' || board[find_stone(sc-1,sr-1)]=='q'))
					return 1;
			if(bosluk2(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
 (board[find_stone(tmp_c,tmp_i)]=='b' || board[find_stone(tmp_c,tmp_i)]=='q'))
					return 1;
			}
		}
		
		tmp_i--;
		tmp_c--; 
	}
	return 0;
}
int sah_fil_bosluk3(char *board,char sc,int sr)
{
	int i;
	char tmp_c;
	int tmp_i;
	
	tmp_c = sc-2;
	tmp_i = sr+2;
	for(i=1; i<=8; i++)
	{
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc-1,sr+1)]=='B' || board[find_stone(sc-1,sr+1)]=='Q'))
				return 1;

			if(bosluk3(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 && 
(board[find_stone(tmp_c,tmp_i)]=='B'|| board[find_stone(tmp_c,tmp_i)]=='Q'))
					return 1;
			}
		}
		else if(board[find_stone(sc,sr)]=='K')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc-1,sr+1)]=='b' || board[find_stone(sc-1,sr+1)]=='q'))
					return 1;
			if(bosluk3(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
 (board[find_stone(tmp_c,tmp_i)]=='b' || board[find_stone(tmp_c,tmp_i)]=='q'))
					return 1;
			}
		}
		
		tmp_c--;
		tmp_i++; 
	}
	return 0;
}
int sah_fil_bosluk4(char *board,char sc,int sr)
{
	int i;
	char tmp_c;
	int tmp_i;
	
	tmp_c = sc+2;
	tmp_i = sr-2;
	for(i=1; i<=8; i++)
	{
		if(board[find_stone(sc,sr)]=='k')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc+1,sr-1)]=='B' || board[find_stone(sc+1,sr-1)]=='Q'))
				return 1;

			if(bosluk4(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 && 
(board[find_stone(tmp_c,tmp_i)]=='B'|| board[find_stone(tmp_c,tmp_i)]=='Q'))
					return 1;
			}
		}
		else if(board[find_stone(sc,sr)]=='K')
		{
			if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
(board[find_stone(sc+1,sr-1)]=='b' || board[find_stone(sc+1,sr-1)]=='q'))
					return 1;
			if(bosluk4(board,sc,sr,tmp_c,tmp_i)==0)
					return 0;			

			else{ 
				if(find_stone(tmp_c,tmp_i)<64 && find_stone(tmp_c,tmp_i)>-1 &&
 (board[find_stone(tmp_c,tmp_i)]=='b' || board[find_stone(tmp_c,tmp_i)]=='q'))
					return 1;
			}
		}
		
		tmp_c++;
		tmp_i--; 
	}
	return 0;
}
