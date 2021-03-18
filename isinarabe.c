#include<stdio.h>

//人数の選択
int selectnum(){
	int p;
	while(1){
		printf("プレイ人数を選んでください。\n1 or 2\n");
		scanf("%d",&p);
		if(p==1){
			printf("私が相手をします。絶対負けませんよ。\n");
			return p;
		}
		else if(p==2){
			printf("二人で対戦します。\n");
			return p;
		}
		else{
			printf("無効な入力です。\n");
		}
	}
}

//石の個数選択
int select_st(){
	while(1){
		printf("石の数を選択してください。\n");
		int st;
		scanf("%d",&st);
		if(st<6){
			printf("石の数が少なすぎます。");
		}
		else{
			printf("石の数は　%d個です。\n",st);
			return st;
		}
	}
}

//一人対戦の関数
void play1(){
	int st=select_st();
	int turn=1,take_st,v=0;
	if((st-1)%4 == 0){
			printf("\nあなたからどうぞ。\n");
			 v=1;
		}
		else{
			printf("\n私から取ります。\n");
		}
		
		while(st>0){
		if((turn+v)%2==1){
			printf("\n*** %dターン目 私の番です。 *************************************\n",turn);
			printf("残り%d個です。",st);
			if(turn==1){
				take_st=(st-1)%4;
			}
			else{
				take_st=4-take_st;
			}
			printf("私は %d個取ります。\n",take_st);
		}
		else{
			printf("\n*** %dターン目 あなたの番です。 *************************************\n",turn);
			printf("残り%d個です。",st);
			while(1){
				printf("取る石の個数を選択してください。（１～３個）\n");
				scanf("%d",&take_st);
				if(take_st<=3&&take_st>=1){
					break;
				}
			}
		}
		st=st-take_st;
		turn++;
	}
	
	printf("\n\n石がなくなりました。");
	if((turn+v)%2==1){
			printf("　私の勝ちです！\n");
		}
		else{
			printf("　あなたの勝ちです！\n");
		}
	
	
}

//二人対戦の関数
void play2(){
	int st=select_st();
	int turn=1,take_st;
	
	while(st>0){
		if(turn%2==1){
			printf("\n*** %dターン目 playerAさんの番です。 *************************************\n",turn);
		}
		else{
			printf("\n*** %dターン目 playerBさんの番です。 *************************************\n",turn);
		}
		
		printf("残り%d個です。",st);
		while(1){
			printf("取る石の個数を選択してください。（１～３個）\n");
			scanf("%d",&take_st);
			if(take_st<=3&&take_st>=1){
				break;
			}
		}
		st=st-take_st;
		turn++;
	}
	
	printf("\n\n石がなくなりました。");
	if(turn%2==1){
			printf("　playerAさん勝ちです！\n");
		}
		else{
			printf("　playerBさん勝ちです！\n");
		}
}

void main(){
	int p;
	p=selectnum();
	if(p==2){
		play2();
	}
	else {
		play1();
	}
	
	
}