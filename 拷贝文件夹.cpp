#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h> //判断是否是文件
#include<windows.h>
#include   <io.h>//文件列表头文件
#include<conio.h>
BOOL MyCopyFile(char *oldepath,char*newpath);
void SystemCopyFile(const char *oldepath,const char *newpath,const char *name)
{
	  char cmd[256]={"xcopy /s /i "},EndPath[256];
	  wsprintf(EndPath,"%s\\%s",newpath,name);
	  strcat(cmd,oldepath);strcat(cmd," ");strcat(cmd,EndPath);
	  system(cmd);
}
int getNumber (char* a,char* b)
{
    int len=strlen(a),i,j,time=0;
    char c,a1[len+1];
    strcpy(a1,a);
    for(i=len-1;i>0;i--)
    {
        if(strstr(a1,b)!=NULL)return time;
        if(a1[i]!=b[i])
        {
           c=a1[i];
           for(j=i;j>0;j--)
              a1[j]=a1[j-1];
           a1[0]=c;i++,time++;
           printf("%s\n",a1);getch();
        }
    }
    return 0;
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
int main(void)
{
    //MyCopyFile("d:\\1","d:\\");printf("OVER");getch();
    //
    //SystemCopyFile("d:\\1","d:\\2","我爱你");
    printf("%d",getNumber("tTse","Test"));getch();
} 
BOOL MyCopyFile(char *oldepath,char*newpath)
{
	  struct _finddata_t block;  
      struct _stat buf; 
	  long ret,result; 
	  char str[256],foundpath[256];
	  strcpy(str,oldepath);
	  strcat(str,"\\*.*");
	  if((ret=_findfirst(str,&block))==-1L)
			return FALSE;
	  else 
	  {
		  _findnext(ret,&block);
		  while(_findnext(ret,&block)==0)
		  {		
                wsprintf(foundpath,"%s\\%s",oldepath,block.name);
                _stat(foundpath, &buf ); 
                if(_S_IFDIR & buf.st_mode)MyCopyFile(foundpath,oldepath);
				else 
				{
                     wsprintf(str,"%s\\%s",newpath,block.name);
                     printf("%s %s\n",foundpath,str);
                }
		  }
		  _findclose(ret);
	  }
	return TRUE;
}
