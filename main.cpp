#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 FILE *fp;   //�ļ� 
 char fname[50];  //�ļ���
 char cn;    //ͳ�Ƶ��ַ���
 int wn;    //ͳ�Ƶĵ�����
 int flag=0;   //����ǵı��� 
 //����Ϊʹ�ÿ⺯�����������в����Ĺ��� 
 int count=0;
 int ch;
 int sum=0; 
 int opt=0;
 int c=0;
 int w=0;
 while((opt=getopt(argc,argv,"c:w:"))!=-1)
 {
  switch(opt)
  {
   case 'c':
    c=1;
    strcpy(fname,optarg);
    flag=1;
    break;
   case 'w':
    w=1;
    strcpy(fname,optarg);
    flag=2;
    break;
  }
 }
 //���̽���
 fp=fopen(fname, "r");  //���ļ�����ʽΪֻ��
 if(!fp)  //�ж��ļ��ܷ�� 
 {
  printf("error 1!\n");  //���޷��򿪣���ʾ 
  exit(0);     //ֹͣ���� 
 }
 switch(flag)
 {
  case 1:
   while(!feof(fp))
   {
    fgetc(fp);
    cn++;
   }
   printf("�ַ�����%d",cn);
   break;
   
  case 2:
   //���㵥�����Ĵ��� 
   while((ch=fgetc(fp))!=EOF) 
   {
   if(ch==','||ch==' ')
          sum=0;
    else if(sum==0)
        {
         sum =1;
         count++;
     }
   }
   printf("��������%d",count);
   break;
}
return 0;
}

