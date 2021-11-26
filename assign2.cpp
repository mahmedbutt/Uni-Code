#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int *SearchAndReverse(char**q,int *&row_num,int rows,int *temp,int &num);
int main()
{
	string text;
	ofstream write;
write.open("text.txt");
cout<<"First you have to enter the number of rows of your text then[space] and then the whole text";
getline(cin,text);
int length=text.size();
write<<text;
char *p=new char[length];
for(int i=0;i<length;i++)
{
p[i]=text[i];
}
write.close();
int rows=0;
ifstream read;
read.open("text.txt");
read>>rows;
cout<<"rows from file are "<<rows;
char **q=new char *[rows];
int previous=0;
	int j=0;
	int *temp=new int[rows];
for(int i=0;i<length;i++)
	{
		if((p[i]=='.')||(p[i]=='?'))
		{
			         temp[j]=i-previous;
					 if(j==0)
					 {
					 temp[0]=(i-previous)-1;
					
					 }
					 cout<<endl<<temp[j]<<endl;
		             q[j]=new char[temp[j]];
		     	         for(int k=0,l=previous;k<=temp[j],l<=i+1;k++,l++)
			           {
			              q[j][k]=p[l];
			           }
						 previous=i+1;
		 j++;
	      }
		
    }
cout<<endl<<"DATA FROM FILE IS LOADED IN 2-D ARRAY AS "<<endl;
for(int i=0;i<rows;i++)
{
	for(int a=0;a<=temp[i];a++)
		{
				cout<<q[i][a];
		}
  	cout<<endl;
}
int *row_numm=nullptr;
int num=0;
int*row_number=new int[num];

row_numm=SearchAndReverse(q,row_number,rows,temp,num);
row_number[num];
for(int i=0;i<num;i++)
cout<<"rows detected "<<row_number[i]<<endl;
for(int h=0;h<num;h++)
cout<<row_number[h];
cout<<endl<<endl<<"REVERSED DATA IS "<<endl<<endl;
for(int i=0;i<rows;i++)
{
	for(int a=0;a<=temp[i];a++)
		{
				cout<<q[i][a];
		}
  	cout<<endl;
}

return 0;
}
int *SearchAndReverse(char**q,int *&row_num,int rows,int *temp,int &num)
{
	bool flag=false;
	int lennum=0;
	int *number=new int[lennum];
	char *word=new char[];
	cout<<"Enter the word you want to search"<<" ";
	cin>>word;
	int len=strlen(word);
	char *word2=new char[len];
	char *word3=new char[len];
	if(word[0]>=65&&word[0]<=90&&word[len-1]>=97&&word[len-1]<=122)
	{
		word2[0]=word[0]+32;
for(int j=1;j<len;j++)
	word2[j]=word[j];
	}
	for(int i=0;i<len;i++)
	{
if(word[i]>=65&&word[i]<=90)
	word2[i]=word[i]+32;
if(word[i]>=97&&word[i]<=122)
	word2[i]=word[i]-32;
word3[i]=word[i];
word3[0]=word[0]-32;
	}
	for(int i=0;i<rows;i++)
	{
		for (int j=0;j<temp[i];j++)
		{
			if(word[0]==q[i][j]||word2[0]==q[i][j])
			{
		for(int k=0;k<len;k++)
		{
		if(word[k]==q[i][j+k]||word2[k]==q[i][j+k])
			flag=true;
		else
		{
		  flag=false;
		  k=len;
		}
		}
		}
			if(flag==true)
			{
			  number[lennum]=i;
			  lennum++;
			  flag=false;
			}
		}
	}
	int pre=0;
	int end=0;
	cout<<word<<" is in sentence ";
	for(int k=0;k<lennum;k++)
	{
		cout<<number[k]<<" ";
		char *ptr=new char [temp[number[k]]-1];
		ptr[temp[number[k]]-1]=q[k][temp[number[k]]-1];
		for(int l=temp[number[k]]-2;l>=0;l--)
		{
		
		if(q[k][l]==32){
			pre=l+1;
			for(int h=end;h<temp[number[k]]-1;h++)
			{
				ptr[h]=q[number[k]][pre];
				pre++;
			}

			end=(temp[number[k]]-l)+1;
			ptr[temp[number[k]]-l]=' ';
		}
		}
		for(int y=0;y<temp[k];y++)
		q[number[k]][y]=ptr[y];
		
	}
	
return number;
}
