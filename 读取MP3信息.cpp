#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char tag[3]={"\0"};//ID3V1标志
    char mname[30]={"\0"};//音乐名
    char artist[30]={"\0"};//艺术家
    char album[30]={"\0"};//专辑
    char year[4]={"\0"};//年份
    char comments[28]={"\0"};//注释
    char reseved[1];//保留位(没什么意思)
    char track[1];//音轨(曲号),就是第几首歌
    char genre[1];//风格
    FILE *p;
    if((p=fopen("d:/1.mp3","rb"))==NULL)return 0;
    fseek(p,-128,SEEK_END);
    fread(tag,3,1,p);
    if(strstr(tag,"TAG")==NULL)
    {
        printf("不是音乐文件");getch();return 0;                       
    }
    fread(mname,30,1,p);
    fread(artist,30,1,p);
    fread(album,30,1,p);
    fread(year,3,1,p);
    fread(comments,28,1,p);
    fread(reseved,1,1,p);
    fread(track,1,1,p);
    fread(genre,1,1,p);
    printf("%s\n歌曲名：%s\n唱片集：%s\n歌  手：%s\n年  代：%s\n注  释：%s\n音  轨：%s\n风  格：%s",tag,mname,artist,album,year,comments,track,genre);
    fclose(p);
    getch();
} 
