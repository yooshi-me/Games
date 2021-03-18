#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	int no;
	char mark;
}card;

int drawn_index[20],drawn_p_index[10],drawn_c_index[10];
int num=0,p_num=2,c_num=2;
int sum1=0,sum2=0;
int flag_p=0,flag_c=0;//バーストフラグ
int flag_jp=0,flag_jc=0;//1を引いたフラグ
int bj_p=0,bj_c=0;//ブラックジャックフラグ
int chip=100,kake,bai=0;

void reset(){
	flag_p=0;
	flag_c=0;
	flag_jp=0;
	flag_jc=0;
	bj_p=0;
	bj_c=0;
	bai=0;
	num=0;
	p_num=2;
	c_num=2;
    sum1=0;
    sum2=0;
	
}

int sum(int p,card *card){
	int sum=0;
	int t=1;
	if(p==1){            //playerの合計計算　drawn_index[0...num]
		for(int i=0;i<p_num;i++){
			if((card + drawn_p_index[i])->no == 1){
				if(flag_jp==0){
					flag_jp=1;
				}else{
					sum=sum+1;
					t++;
				}
			}
			else if((card + drawn_p_index[i])->no > 10){
				sum=sum+10;
				t++;
			}
			else {
				sum=sum + (card + drawn_p_index[i])->no;
				t++;
			}
		}
		if(flag_jp==1 && sum > 10){
			sum = sum + 1;
			t++;
		}
		else if(flag_jp==1){
			sum = sum + 11;
			t++;
		}
		return sum;
	}
	else{
		for(int i=0;i<c_num;i++){
			if((card + drawn_c_index[i])->no == 1){//syuusei
				if(flag_jc==0){
					flag_jc=1;
				}else{
					sum=sum+1;
				}
			}
			else if((card + drawn_c_index[i])->no > 10){
				sum=sum+10;
			}
			else {
				sum=sum + (card + drawn_c_index[i])->no;
			}
		}
		if(flag_jc==1 && sum > 10){
			sum = sum + 1;
		}
		else if(flag_jc==1){
			sum = sum + 11;
		}
		return sum;
	}
}

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
}

void draw(){
	int i=0,index;
	srand((unsigned)time(NULL));
	index=rand()%52;
	while(1){		
		if(drawn_index[i]==index){    //i番目でかぶったら乱数引き直し＆最初から
			srand((unsigned)time(NULL));
			index=rand()%52;
			i=0;
		}
		else if(i==num){           //すべてのチェック完了
			break;
		}
		else{                      //次の確認へ
			i++;
		}
	}
	drawn_index[num]=index;
	num++;
}

void card_provider(card *card){
	int index,i=0;
	printf("***** Providing Card now ****************************\n");
	while(1){
		srand((unsigned)time(NULL));
		index=rand()%52;
		drawn_index[num]=index;
		num++;                       //1枚目
		draw();
		if(num==4){
			break;
		}
	}
	drawn_p_index[0]=drawn_index[0];
	drawn_p_index[1]=drawn_index[1];
	drawn_c_index[0]=drawn_index[2];
	drawn_c_index[1]=drawn_index[3];
	
	sum1=sum(1,card);
	sum2=sum(2,card);
	printf("Player\n　1st　%d\n　2nd　%d\n 　Sum　%d\n",(card+drawn_p_index[0])->no,(card+drawn_p_index[1])->no,sum1);
	printf("COM    \n　1st　%d\n　2nd　?\n 　Sum　?\n",(card+drawn_c_index[0])->no);
	if(flag_jp==1){
		if((card+drawn_p_index[0])->no==11||(card+drawn_p_index[1])->no==11){
			bj_p=1;
		}
	}
	if(flag_jc==1){
		if((card+drawn_c_index[0])->no==11||(card+drawn_c_index[1])->no==11){
			bj_c=1;
		}
	}
			
}
void judge(card *card){
	char j;
	while(1){
		printf("\n***** Player's turn　number %d*************************************\n",p_num+1);
		printf("Do you draw a Crad？\ny or n:");
		scanf("%s",&j);
		if(j=='y'){
			//もう一枚引く
			draw();
			drawn_p_index[p_num]=drawn_index[num-1];
			p_num++;
			sum1=sum(1,card);
			printf("Drawn Card　%d\nSum：%d \n",(card+drawn_p_index[p_num-1])->no,sum1);
			if(sum1>21){
				flag_p=1;
				printf("!!! Over 21 !!!!!!!!!!!\n");
				return;
			}	
		}
		else if(j == 'n'){//終了
			printf("Player：%d\n",sum1);
			return;
		}
		else{
			printf("Sorry...Please type y/n.\n");
		}
	}
}

void judge_p(card *card){
	while(1){
		if(sum2 < 15){
			//もう一枚引く
			printf("\n***** COM's turn　number%d*************************************\n",c_num+1);
			draw();
			drawn_c_index[c_num]=drawn_index[num-1];
			c_num++;
			sum2=sum(2,card);
			printf("Drawn Card　%d\nSum：%d \n",(card+drawn_c_index[c_num-1])->no,sum2);	
		}else {
			printf("COM：%d\n",sum2);
			if(sum2>21){
				flag_c=1;
				printf("!!! Over 21 !!!!!!!!!!!!\n");
			}
			return;
		}
	}
}

int result(){//勝ち１　負け－１　引き分け０
	int resu_p=21-sum1;
	int resu_c=21-sum2;;
	if(flag_p==1 && flag_c==1){
		printf("Resut:Both bursted......\n");
		return 0;
	}
	else if(flag_p==1){
		printf("Result：Payer bursedt\nPlayer lose\n");
		return -1;
	}
	else if(flag_c==1){
		printf("Result：COM bursted...\nPlayer win\n");
		return 1;
	}
	
	else if(sum1 == sum2){
		printf("Result：Draw\n");
		return 0;
	}
	else if(resu_p>resu_c){
		printf("Result：COM win\n");
		return -1;
	}
	else{
		printf("Result:Player win!!!\n");
		return 1;
	}
}
int game(card *card){
	reset();
	shuffle(card);
	card_provider(card);
	while(1){
		printf("Bet your chip!\nYou have：%d\nBet：",chip);
		scanf("%d",&kake);
		if(kake>chip){
			printf("It's too much!\n");
		}else {
			break;
		}
	}
	if(bj_p==1){
		if(bj_c==1){
			printf("Result：Both Brack Jack!!\n");
		}else{
			printf("Brack Jack！！！！！\nCongratulations！\n");
			bai=1;
		}
	}else if(bj_c==1){
		printf("Result:COM win.\n");
	}else{
		judge(card);
		judge_p(card);
		return result();
	}
}

void main(){
	int gamek=1;
	int resu_game;
	printf("Welcome to the Brack Jack Game！\n");
	card card[52];
	cardset(card);
	while(1){
		printf("\n\n～～～～GAME;%d～～～～～～～～～\n",gamek);
		printf("Your chip：%d\n",chip);
		resu_game=game(card);
		if(bai==1){
			chip=chip+(kake*4);
		}
		else if(resu_game==1){
			chip=chip+kake;
		}
		else if(resu_game==-1){
			chip=chip-kake;
		}
		gamek++;
		if(chip<=0){
			printf("You can't continue,Because you have no chip...\n");
			break;
		}else if(chip>=200){
			printf("Your chip exceeded 200!!\n");
		}
	}
	
}