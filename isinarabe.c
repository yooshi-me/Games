#include<stdio.h>

//�l���̑I��
int selectnum(){
	int p;
	while(1){
		printf("�v���C�l����I��ł��������B\n1 or 2\n");
		scanf("%d",&p);
		if(p==1){
			printf("������������܂��B��Ε����܂����B\n");
			return p;
		}
		else if(p==2){
			printf("��l�őΐ킵�܂��B\n");
			return p;
		}
		else{
			printf("�����ȓ��͂ł��B\n");
		}
	}
}

//�΂̌��I��
int select_st(){
	while(1){
		printf("�΂̐���I�����Ă��������B\n");
		int st;
		scanf("%d",&st);
		if(st<6){
			printf("�΂̐������Ȃ����܂��B");
		}
		else{
			printf("�΂̐��́@%d�ł��B\n",st);
			return st;
		}
	}
}

//��l�ΐ�̊֐�
void play1(){
	int st=select_st();
	int turn=1,take_st,v=0;
	if((st-1)%4 == 0){
			printf("\n���Ȃ�����ǂ����B\n");
			 v=1;
		}
		else{
			printf("\n��������܂��B\n");
		}
		
		while(st>0){
		if((turn+v)%2==1){
			printf("\n*** %d�^�[���� ���̔Ԃł��B *************************************\n",turn);
			printf("�c��%d�ł��B",st);
			if(turn==1){
				take_st=(st-1)%4;
			}
			else{
				take_st=4-take_st;
			}
			printf("���� %d���܂��B\n",take_st);
		}
		else{
			printf("\n*** %d�^�[���� ���Ȃ��̔Ԃł��B *************************************\n",turn);
			printf("�c��%d�ł��B",st);
			while(1){
				printf("���΂̌���I�����Ă��������B�i�P�`�R�j\n");
				scanf("%d",&take_st);
				if(take_st<=3&&take_st>=1){
					break;
				}
			}
		}
		st=st-take_st;
		turn++;
	}
	
	printf("\n\n�΂��Ȃ��Ȃ�܂����B");
	if((turn+v)%2==1){
			printf("�@���̏����ł��I\n");
		}
		else{
			printf("�@���Ȃ��̏����ł��I\n");
		}
	
	
}

//��l�ΐ�̊֐�
void play2(){
	int st=select_st();
	int turn=1,take_st;
	
	while(st>0){
		if(turn%2==1){
			printf("\n*** %d�^�[���� playerA����̔Ԃł��B *************************************\n",turn);
		}
		else{
			printf("\n*** %d�^�[���� playerB����̔Ԃł��B *************************************\n",turn);
		}
		
		printf("�c��%d�ł��B",st);
		while(1){
			printf("���΂̌���I�����Ă��������B�i�P�`�R�j\n");
			scanf("%d",&take_st);
			if(take_st<=3&&take_st>=1){
				break;
			}
		}
		st=st-take_st;
		turn++;
	}
	
	printf("\n\n�΂��Ȃ��Ȃ�܂����B");
	if(turn%2==1){
			printf("�@playerA���񏟂��ł��I\n");
		}
		else{
			printf("�@playerB���񏟂��ł��I\n");
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