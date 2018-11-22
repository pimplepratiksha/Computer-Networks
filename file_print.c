#include<stdio.h>
#include<stdlib.h>

int main()
{
	char filename[50],s[100],c;
	FILE *fp1,*fp2;
	
	//printf("\nEnter file name:");
	//scanf("%s",filename);
	/*fp1=fopen("study.txt","r");
	fp2=fopen("study1.txt","w+");
	c=fgetc(fp1);	
	while(c!=EOF)
	{
		fputc(c,fp2);
		c=fgetc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
	*/
	fp1=fopen("study.txt","r");
	while(fscanf(fp1,"%s",s)!=EOF)
	{
		printf("\n%s",s);
	}
}
