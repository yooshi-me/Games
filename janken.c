#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int point=5,countl=0,countv=0,turnn=1;

int judge(int a,int b){
	if(a==b){
		return 2;
	}
	else if(b-a==1||b-a==-2){
		return 0;
	}
	else if(b-a==2||b-a==-1){
		return 1;
	}
	else{
		printf("無効な入力です。もう一度入力してください。\n");
		return 5;
	}
}
	

void turn(){
	int p=0,com=0,j=0;
	srand((unsigned)time(NULL));
	com=rand()%3;
	printf("***  %dターン目  **********************************************************\n",turnn);
	printf("グー＝０、チョキ＝１、パー＝２　を入力してください。\nじゃんけん・・・・・\n");
	scanf("%d",&p);
	printf("ポンっ！！\n");
	j=judge(p,com);
	if(j==0){
		countv++;
		countl=0;
		point=point+countv;
		printf("あなたの勝ち！！　%d点追加されます。　現在の得点　%d点\n\n",countv,point);
	}
	else if(j==1){
		countv=0;
		countl++;
		point=point-countl;
			printf("あなたの負け...　%d点失います。　現在の得点　%d点\n\n",countl,point);
	}
	
	else if(j==2){
			printf("あいこです。連勝、連敗記録はリセットされます。\n\n");
			countv=0;
			countl=0;
	}
	turnn++;
}
//グー＝０
//チョキ＝１
//パー＝２

void main(){
	
	char r;
	
	printf("じゃんけんゲームを開始します。\n準備はよろしいですか？\ny/n\n");
	scanf("%s",&r);
	if(r == 'n'){
		printf("対戦を終了します。\n");
		return;
	}
	else{
		printf("対戦を開始します。\nあなたの得点は５点です。\n\n");
	}
	while(point<10){
		if(point<0){
			printf("***  終了  **********************************************************\nポイントがなくなりました。\n\nゲームを終了します。\n");
			break;
		}
		turn();
	}
	if(point>10){
		printf("***  終了  **********************************************************\n");
		printf("\n得点が10を超えました。おめでとうございます！\n対戦を終了します。\n");
	}
}
