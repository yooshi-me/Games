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
		printf("�����ȓ��͂ł��B������x���͂��Ă��������B\n");
		return 5;
	}
}
	

void turn(){
	int p=0,com=0,j=0;
	srand((unsigned)time(NULL));
	com=rand()%3;
	printf("***  %d�^�[����  **********************************************************\n",turnn);
	printf("�O�[���O�A�`���L���P�A�p�[���Q�@����͂��Ă��������B\n����񂯂�E�E�E�E�E\n");
	scanf("%d",&p);
	printf("�|�����I�I\n");
	j=judge(p,com);
	if(j==0){
		countv++;
		countl=0;
		point=point+countv;
		printf("���Ȃ��̏����I�I�@%d�_�ǉ�����܂��B�@���݂̓��_�@%d�_\n\n",countv,point);
	}
	else if(j==1){
		countv=0;
		countl++;
		point=point-countl;
			printf("���Ȃ��̕���...�@%d�_�����܂��B�@���݂̓��_�@%d�_\n\n",countl,point);
	}
	
	else if(j==2){
			printf("�������ł��B�A���A�A�s�L�^�̓��Z�b�g����܂��B\n\n");
			countv=0;
			countl=0;
	}
	turnn++;
}
//�O�[���O
//�`���L���P
//�p�[���Q

void main(){
	
	char r;
	
	printf("����񂯂�Q�[�����J�n���܂��B\n�����͂�낵���ł����H\ny/n\n");
	scanf("%s",&r);
	if(r == 'n'){
		printf("�ΐ���I�����܂��B\n");
		return;
	}
	else{
		printf("�ΐ���J�n���܂��B\n���Ȃ��̓��_�͂T�_�ł��B\n\n");
	}
	while(point<10){
		if(point<0){
			printf("***  �I��  **********************************************************\n�|�C���g���Ȃ��Ȃ�܂����B\n\n�Q�[�����I�����܂��B\n");
			break;
		}
		turn();
	}
	if(point>10){
		printf("***  �I��  **********************************************************\n");
		printf("\n���_��10�𒴂��܂����B���߂łƂ��������܂��I\n�ΐ���I�����܂��B\n");
	}
}
