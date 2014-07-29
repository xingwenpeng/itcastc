#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int top[10];
int bottom[10];
bool success;

void init()
{
	int i;

	success = false;
	for(i=0;i<10;i++){
		top[i] = i;
		bottom[i] = i;
	}
}
int getfrequecy(int num)
{
	int i;
	int count=0;

	for(i=0;i<10;i++){
		if(bottom[i]==num)
			count++;
	}
	return count;
}
void setbottom()
{
	int i;
	int frequecy;
	while(!success){
		bool temp = true;
		for(i=0;i<10;i++){
			frequecy = getfrequecy(i);
			if(bottom[i]!=frequecy){
				bottom[i] = frequecy;
				temp = false;
			}
		}
		success = temp;
	}

}

int main()
{
	int i;

	init();
	setbottom();
	for(i=0;i<10;i++)
		printf("%4d",bottom[i]);
	printf("\n");
	return 0;
}
