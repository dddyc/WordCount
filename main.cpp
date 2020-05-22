#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 FILE *fp;   //文件 
 char fname[50];  //文件名
 char cn;    //统计的字符数
 int wn;    //统计的单词数
 int flag=0;   //做标记的变量 
 //以下为使用库函数解析命令行参数的过程 
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
 //过程结束
 fp=fopen(fname, "r");  //打开文件，方式为只读
 if(!fp)  //判断文件能否打开 
 {
  printf("error 1!\n");  //若无法打开，提示 
  exit(0);     //停止进程 
 }
 switch(flag)
 {
  case 1:
   while(!feof(fp))
   {
    fgetc(fp);
    cn++;
   }
   printf("字符数：%d",cn);
   break;
   
  case 2:
   //计算单词数的代码 
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
   printf("单词数：%d",count);
   break;
}
return 0;
}

