#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,l,m,n,a,zj=0;
    for(i=1;i<10;i++)
      for(j=0;j<10;j++)
        for(k=0;k<10;k++)
          if(i!=j&&i!=k&&j!=k)
            for(l=9;l>0;l--)
              for(m=9;m>=0;m--)
                for(n=9;n>=0;n--)
                  if(l!=m&&l!=n&&m!=n)
                    if(i!=l&&i!=m&&i!=n&&j!=l&&j!=m&&j!=n&&k!=l&&k!=m&&k!=n)
                    {
                      a=(i*100+j*10+k)+(l*100+m*10+n);
                      if(a<10000&&a>=1000)
                          //if(++zj%100==0)getch();//±‹√‚Ã´∂‡…¡∆¡°£°£°£ 
                          //else printf("%d%d%d+%d%d%d=%d ",i,j,k,l,m,n,a);
                          ++zj;
                    }   
    printf("%d",zj); 
    getch(); 
} 



