#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int judge(int guess,int ans){
	if(guess==ans){
		printf("Correct!!\n");
		return 0;
	}
	else if(guess>ans){
		printf("small\n");
		return -1;
	}
	else if(guess<ans){
		printf("big\n");
		return 1;
	}
	
}

void game(int p_num){
	int turn=1;
	int guess;
	int c_guess,result,guess_max=99,guess_min=1;
	srand((unsigned)time(NULL));
	int c_num=rand()%99+1; //CPの数字代入
	while(1){
		if(turn==1){
			printf("****　%dst turn　***************************\n",turn);
		}
		else if(turn==2){
			printf("\n****　%dnd turn　***************************\n",turn);
		}
		else if(turn==3){
			printf("\n****　%drd turn　***************************\n",turn);
		}else{
			printf("\n****　%dth turn　***************************\n",turn);
		}
		printf("What's my number?\nanswer:");
		scanf("%d",&guess);
		if(judge(guess,c_num)==0){
			printf("You win!!!\n");
			break;
		}
		c_guess=rand()%(guess_max-guess_min+1)+guess_min;
		//printf("Max=%d,Min=%d\n",guess_max,guess_min);
		printf("\nIs your number %d?\n",c_guess);
		result=judge(c_guess,p_num);
		if(result==0){
			printf("I win!!!\n");
			break;
		}
		else if(result==1){
			guess_min=c_guess+1;
		}
		else if(result==-1){
			guess_max=c_guess-1;
		}
		turn++;	
	}
	printf("This game ended in %d turns.\n ",turn);
	
}
void game_strong(int p_num){
	int turn=1;
	int guess;
	int c_guess,result,guess_max=99,guess_min=1;
	srand((unsigned)time(NULL));
	int c_num=rand()%99+1; //CPの数字代入
	while(1){
		if(turn==1){
			printf("****　%dst turn　***************************\n",turn);
		}
		else if(turn==2){
			printf("\n****　%dnd turn　***************************\n",turn);
		}
		else if(turn==3){
			printf("\n****　%drd turn　***************************\n",turn);
		}else{
			printf("\n****　%dth turn　***************************\n",turn);
		}
		printf("What's my number?\nanswer:");
		scanf("%d",&guess);
		if(judge(guess,c_num)==0){
			printf("You win!!!\n");
			break;
		}
		c_guess=(guess_max + guess_min)/2;
		//printf("Max=%d,Min=%d\n",guess_max,guess_min);
		printf("\nIs your number %d?\n",c_guess);
		result=judge(c_guess,p_num);
		if(result==0){
			printf("I win!!!\n");
			break;
		}
		else if(result==1){
			guess_min=c_guess+1;
		}
		else if(result==-1){
			guess_max=c_guess-1;
		}
		turn++;	
	}
	printf("This game ended in %d turns.\n ",turn);
	
}
void main(){
	int p_num;
	char mode;
	printf("Welcome to Big or Small game!!\n");
	printf("Please, select mode:e or s\nmode:");
	scanf("%s",&mode);
	printf("Please, type your number(1～99)\n");
	while(1){
		printf("your number:");
		scanf("%d",&p_num);
		if(p_num<0||p_num>99){
			printf("You can't select this number....\n");
		}else{
			break;
		}
	}
	printf("Let's start!!\n\n");
	if(mode=='s'){
		game_strong(p_num);
	}
	else if(mode =='e'){
		game(p_num);
	}
	
}