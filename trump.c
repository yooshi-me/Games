#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	int no;
	char mark;
}card;

void cardset(card *card){
	int i;
	for(i=0;i<52;i++){
		(card+i)->no=i%13+1;
		switch(i/13){
			case 0:
			(card+i)->mark='h';
			break;
			
			case 1:
			(card+i)->mark='q';
			break;
			
			case 2:
			(card+i)->mark='s';
			break;
			
			case 3:
			(card+i)->mark='d';
			break;
			
		}
	}
	printf("*** セット完了しました。******************************\n");
}

void outputcard(card *card){
	int i;
	for(i=0;i<52;i++){
		printf("%d %c\n",(card+i)->no,(card+i)->mark);
	}
}

void shuffle(card *card){
	int i;
	int tmp_no,index;
	char tmp_mark;
	srand((unsigned)time(NULL));
	for(i=0;i<52;i++){
		index=rand()%52;
		tmp_no=(card+i)->no;
		tmp_mark=(card+i)->mark;
		(card+i)->no=(card+index)->no;
		(card+i)->mark=(card+index)->mark;
		(card+index)->no=tmp_no;
		(card+index)->mark=tmp_mark;
	}
	printf("*** シャッフル完了しました。******************************\n");
}
void main(){
	card card[52];
	cardset(card);
	outputcard(card);
	shuffle(card);
	outputcard(card);
}