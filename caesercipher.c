#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	int k,ch;
	printf("1.Encryption\n2.Decryption\nEnter your operarion:");
	scanf("%d",&ch);
	printf("Enter the string : ");
	scanf("%s",str);
	printf("Enter the key : ");
	scanf("%d",&k);
	if(ch==1){
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='a' && str[i]<='z'){
		
		int d=int(str[i])-96;
		int n=(d+k)%26;
		char c=char(n+96);
		printf("%c",c);}
		else if(str[i]>='0' && str[i]<='9')
		{
			printf("%c",str[i]+k);
		}
		else if(str[i]>='A' && str[i]<='Z')
		{
		int d=int(str[i])-64;
		int n=(d+k)%26;
		char c=char(n+64);
		printf("%c",c);
			
		}
	}}
	if(ch==2){
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='a' && str[i]<='z'){
		int d=int(str[i])-96;
		int n=(d-k)%26;
		char c=char(n+96);
		printf("%c",c);}
		else if(str[i]>='0' && str[i]<='9')
		{
			printf("%c",str[i]-k);
		}
		else if(str[i]>='A' && str[i]<='Z')
		{
		int d=int(str[i])-64;
		int n=(d-k)%26;
		char c=char(n+64);
		printf("%c",c);
			
		}
		
	}}
}


