#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *fp;
	int i,j,staddr1;
	char line[50],name1[50],stadrr[200];

	fp = fopen("ab.txt","r");

	fscanf(fp,"%s",line);
		name1[j]=line[0];
	name1[1]='\0';
	printf("Name from Obj.%s\n",name1);
	fclose(fp);
	return 0;
}
