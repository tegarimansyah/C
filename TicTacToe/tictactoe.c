/*
 * TicTacToe v1.0 ( Main Kotak 9 ) 
 * Indonesia, December 2013
 *
 * Created by Tegar Imansyah ( tegarimansyah@student.pens.ac.id )
 * Assisted by Handika Artaguna Putra ( handika_ap@student.pens.ac.id )
 * Mechatronics Engineering ( What it is? http://njajali.wordpress.com/teknik-mekatronika )
 * EEPIS ( http://www.eepis.ac.id / http://www.pens.ac.id)
 * 
 * Please give me feedback
 * Thank You and Have Fun :D
 * 
 * 
 * 
 */

#include <stdio.h>

void enter() {
	int i;
	for(i=0;i<100;i++) {
		printf("\n");
		}
}

int mutlak(int a) {
	if (a < 1) {
		a=-a;
	}
	return a;
}

int main() {
	char tictactoe[3][3] = { {32,32,32} , {32,32,32} , {32,32,32} };
	int a,x1,y1,x2,y2,player=2,turn=0,selesai=0;
	do {
	printf(" ___ ___ ___   ___ ___ ___   ___ ___ ___  \n");
	printf("|            ||            ||            |\n");
	printf("|     %c      ||     %c      ||     %c      |\n",tictactoe[0][0],tictactoe[0][1],tictactoe[0][2]);
	printf("|___ ___ ___ ||___ ___ ___ ||___ ___ ___ |\n");
	printf("|            ||            ||            |\n");
	printf("|     %c      ||     %c      ||     %c      |\n",tictactoe[1][0],tictactoe[1][1],tictactoe[1][2]);
	printf("|___ ___ ___ ||___ ___ ___ ||___ ___ ___ |\n");
	printf("|            ||            ||            |\n");
	printf("|     %c      ||     %c      ||     %c      |\n",tictactoe[2][0],tictactoe[2][1],tictactoe[2][2]);
	printf("|___ ___ ___ ||___ ___ ___ ||___ ___ ___ |\n");
	for (a=0;a<3;a++) {
				if ((tictactoe[a][0] == tictactoe[a][1]) && (tictactoe[a][1] == tictactoe[a][2]) && (tictactoe[a][2] != 32)) {
					selesai=1;
					break;
				}
				else if ((tictactoe[0][a] == tictactoe[1][a]) && (tictactoe[1][a] == tictactoe[2][a]) && (tictactoe[2][a] != 32)) {
					selesai=1;
					break;
				}
				else if (((tictactoe[1][1] == tictactoe[2][2]) && (tictactoe[1][1] == tictactoe[0][0]) && (tictactoe[2][2] != 32)) || ((tictactoe[0][2] == tictactoe[1][1]) && (tictactoe[0][2] == tictactoe[2][0]) && (tictactoe[1][1] != 32))) {
					selesai=1;
					break;
				}
				else selesai = 0;
		}
	if (selesai > 0) {break;}
	
	if (player == 1) {player++;} else {player--;}
	printf("Player %d\n",player);
	if (turn<6) {
		printf("Masukan koordinat [ x,y ] ");
		scanf(" %d,%d",&x1,&y1);
		while ( (tictactoe[x1-1][y1-1] != 32) || (x1 > 3) || (y1 > 3) || (x1 < 0) || (y1 < 0) ){
			printf("Maaf, tidak bisa memasukan bidak anda\n");
			printf("Masukan koordinat [ x,y ] ");
			scanf(" %d,%d",&x1,&y1);
		}
		enter();
		if (player == 1) {
		tictactoe[x1-1][y1-1] = 'x';
		}
		else {
		tictactoe[x1-1][y1-1] = 'o';
		}
		turn++;
	}
	else {
		printf("Masukan koordinat awal [ x,y ] ke koordinat akhir [ x,y ] ");
		scanf("%d,%d %d,%d",&x1,&y1,&x2,&y2);	
		while ( ( tictactoe[x2-1][y2-1] != 32) || (mutlak(x1-x2) > 1 ) || (mutlak(y1-y2) > 1 ) || ((x1-x2 == 0) && (y1-y2 == 0)) || ((player == 1) && (tictactoe[x1-1][y1-1] != 'x')) || ((player == 2) && (tictactoe[x1-1][y1-1] != 'o')) ){
			printf("Maaf, tidak bisa memasukan bidak anda\n");
			printf("Masukan koordinat awal [ x,y ] ke koordinat akhir [ x,y ] ");
			scanf("%d,%d %d,%d",&x1,&y1,&x2,&y2);
		}

		enter();
		if (player == 1) {
		tictactoe[x1-1][y1-1] = 32;
		tictactoe[x2-1][y2-1] = 'x';
		}
		else {
		tictactoe[x1-1][y1-1] = 32;
		tictactoe[x2-1][y2-1] = 'o';
		}
			
		}
	} while (1);
	printf("Selamat player %d menang\nThanks for playing :D",player);
	return 0;
}
