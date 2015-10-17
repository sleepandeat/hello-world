#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
const int Number=15;
double a[Number][Number],b[Number],copy_a[Number][Number],copy_b[Number];
int A_y[Number];
int lenth,copy_lenth;
double a_sum;
char *x;
void input();
void print_menu();
int choose();
void cramer();
void gauss_row();
void gauss_all();
void Doolittle();
int Doolittle_check(double a[][Number],double b[Number]);
void xiaoqu_u_l();
void calculate_u_l();
double & calculate_A(int n,int m);
double quanpailie_A();
void exchange(int m,int i);
void exchange_lie(int j);
void exchange_hang(int m,int n);
void gauss_row_xiaoqu();
void gauss_all_xiaoqu();
void gauss_calculate();
void exchange_a_lie(int m,int n);
void exchange_x(int m,int n);
void recovery();


void main()
{
	int flag=1;
	input();
	while(flag)
	{
		print_menu();
		flag=choose();
	}
}

void print_menu()
{
	system("cls");
	cout<<"方程系数和常数矩阵表示如下：\n";
	int i,j;
	for(j=0;j<lenth;j++)
	{
		cout<<"系数"<<j+1<<"";
	}
	cout<<"\t常数";
	cout<<endl;
	for(i=0;i<lenth;i++)
	{
		for(j=0;j<lenth;j++)
		{
			cout<<setw(8)<<setiosflags(ios::left)<<a[i][j];
		}
		cout<<"\t"<<b[i]<<endl;
	}
	cout<<"请选择方程解答的方案";
	cout<<"\n1.克拉默(Cramer)法则";
	cout<<"\n2.Guass列主元消去法";
	cout<<"\n3.Guass全主元消去法";
	cout<<"\n4.Doolittle分解法";
	cout<<"\n5.退出";
	cout<<"\n输入你的选择：";
}

void input()
{
	int i,j;
	cout<<"方程的个数：";
	cin>>lenth;
	if(lenth>Number)
	{
		cout<<"It is too big.\n";
		return;
	}
	x=new char[lenth];
	for(i=0;i<lenth;i++)
	{
		x[i]='a'+1;
	}
	cout<<"===============================================================\n";
	cout<<"请在每个方程里输入"<<lenth<<"系数和一个常数：\n";
	cout<<"例：\n方程：a";
	for(i=1;i<lenth;i++)
	{
		cout<<"+"<<i+1<<x[i];

	}
	cout<<"=10\n";
	cout<<"应输入：";
	for(i=0;i<lenth;i++)
	{
		cout<<i+1<<" ";
	}
	cout<<"=10\n";
	cout<<"==================================";
	for(i=0;i<lenth;i++)
	{
		cout<<"输入方程"<<i+1<<":";
		for(j=0;j<lenth;j++)
		{
			cin>>a[i][j];
		}
		cin>>b[i];
	}
	for(i=0;i<lenth;i++)
	{
		for(j=0;j<lenth;j++)
		{
			copy_a[i][j]=a[i][j];
		}
	}
	for(i=0;i<lenth;i++)
	{
		copy_b[i]=b[i];
	}
	copy_lenth=lenth;
}

int choose()
{
	int choice;
	char ch;
	cin>>choice;
	switch(choice)
	{
	    case 1:cramer();
			break;
		case 2:gauss_row();
			break;
		case 3:gauss_all();
			break;
		case 4:Doolittle();
			break;
		case 5:return 0;
		default:cout<<"输入错误，请重新输入";
			choose();
			break;
	}
	cout<<"\n是否换种方法求解（Y/N）";
	cin>>ch;
	if(ch=='n'||ch=='N')
		return 0;
	recovery();
	cout<<"\n\n\n";
	return 1;
}

void cramer()
{
	int i,j;
	double sum,sum_x;
	char ch;
	cout<<"用克拉默（Cramer）法则结果如下：\n";
	for(i=0;i<lenth;i++)
	{
		A_y[i]=i;
	}
	sum=calculate_A(lenth,0);
	if(sum!=0)
	{

		cout<<"系数行列式不为零，方程有唯一的解。";
		for(i=0;i<lenth;i++)
		{
			ch='a'+i;
			a_sum=0;
			for(j=0;j<lenth;j++)
			{
				A_y[j]=j;
			}
			exchange_lie(i);
			sum_x=calculate_A(lenth,0);
			cout<<endl<<ch<<"="<<sum_x/sum;
			exchange_lie(i);
		}
	}
	else
	{
		cout<<"系数行列式等于零，方程没有唯一的解。";
	}
	cout<<"\n";
}

double & calculate_A(int n,int m)
{
	int i;
	if(n==1)
	{
		a_sum+=quanpailie_A();
	}
	else
	{
		for(i=0;i<lenth;i++)
		{
			exchange(m,m+1);
			calculate_A(n-1,m+1);
			exchange(m,m+1);
		}
	}
	return a_sum;
}

double quanoaille_A()
{
	int i,j,l;
	double sum=0,p;
	for(i=0,l=0;i<lenth;i++)
	{
		for(j=0;A_y[j]!=i&&j<lenth;j++)
		{
			if(A_y[j]>i)
			{
				l++;
			}
		}
	}
	for(p=1,i=0;i<lenth;i++)
	{
		p*=a[i][A_y[i]];
	}
	sum+=p*((1%2==0)?(1):(-1));
	return sum;
}

void gauss_row()
{
	int i,j;
	gauss_row_xiaoqu();
	for(i=0;i<lenth;i++)
	{
		for(j=0;j<lenth;j++)
		{
			cout<<setw(10)<<setprecision(5)<<a[i][j];
		}
		cout<<setw(10)<<b[i]<<endl;
	}
	if(a[lenth-1][lenth-1]!=0)
	{
		cout<<"系数行列式不为零，方程有唯一的解：\n";
		gauss_calculate();
		for(i=0;i<lenth;i++)
		{
			cout<<x[i]<<"="<<b[i]<<"\n";
		}
	}
	else
	{
		cout<<"系数行列式等于零，方程没有唯一的解。\n";
	}
}

void gauss_row_xiaoqu()
{
	int i,j,k,maxi,maxj;
	double lik;
	cout<<"用Gauss列主元消去法结果如下：\n";
	for(k=0;k<lenth;k++)
	{
		for(maxi=maxj=i=k;i<lenth;i++)
		{
			for(j=k;j<lenth;j++)
			{
				if(a[i][j]>a[maxi][maxj])
				{
					maxi=i;
					maxj=j;
				}
			}
		}
		if(maxi!=k)
		{
			exchange_hang(k,maxi);
		}
		if(maxj!=k)
		{
			exchange_a_lie(maxj,k);
			exchange_x(maxj,k);
		}
		for(i=k+1;i<lenth;i++)
		{
			lik=a[i][k]/a[k][k];
			for(j=k;j<lenth;j++);
			{
				a[i][j]=a[i][j]-a[k][j]*lik;
			}
			b[i]=b[i]-b[k]*lik;
		}
	}
}

void gauss_calculate()
{
	int i,j;
	double sum_ax;
	b[lenth-1]=b[lenth-1]/a[lenth-1][lenth-1];
	for(i=lenth-2;i>=0;i--)
	{
		for(j=i+1,sum_ax=0;j<lenth;j++)
		{
			sum_ax+=a[i][j]*b[j];
		}
		b[i]=(b[i]-sum_ax)/a[i][i];
	}
}

void Doolittle()
{
	double temp_a[Number][Number],temp_b[Number][Number];
	int i,j,flag;
	for(i=0;i<lenth;i++)
	{
		for(j=0;j<lenth;j++)
		{
			temp_a[i][j]=a[i][j];
		}
	}
	flag=Doolittle_check(temp_a[Number][Number],temp_b[Number][Number]);
	if(flag==0)
	{
		cout<<"\n行列式为零，无法使用Doolittle求解.";
	}
	xiaoqu_u_l();
	calculate_u_l();
	cout<<"用Doolittle方法求得结果如下：\n";
	for(i=0;i<lenth;i++)
	{
		for(j=0;x[j]!='a'&&j<lenth;j++)
		{
			cout<<x[j]<<"="<<b[j]<<endl;
		}
	}
}

void calculate_u_l()
{
	int i,j;
	double sum_ax=0;
	for(i=0;i<lenth;i++)
	{
		for(j=0,sum_ax=0;j<i;j++)
		{
			sum_ax+=a[i][j]*b[j];
		}
		b[i]=b[i]-sum_ax;
	}
	for(i=lenth-1;i>=0;i--)
	{
		for(j=i+1,sum_ax=0;j<lenth;j++)
		{
			sum_ax+=a[i][j]*b[j];
		}
		b[i]=(b[i]-sum_ax)/a[i][j];
	}
}

void xiaoqu_u_l()
{
	int i,j,n,k;
	double temp;
	for(i=1,j=0;i<lenth;i++)
	{
		a[i][j]=a[i][j]/a[0][0];
	}
	for(n=1;n<lenth;n++)
	{
		for(j=n;j<lenth;j++)
		{
			for(k=0,temp=0;k<n;k++)
			{
				temp+=a[n][k]*a[k][j];
			}
			a[n][j]-=temp;
		}
		for(i=n+1;i<lenth;i++)
		{
			for(k=0,temp=0;k<n;k++)
			{
				temp+=a[i][k]*a[k][n];
			}
			a[i][n]=(a[i][n]-temp)/a[n][n];
		}
	}

}

int Doolittle_check(double temp_a[][Number],double temp_b[Number])
{
	int i,j,k,maxi;
	double lik,temp;
	for(k=0;k<lenth-1;k++)
	{
		j=k;
		for(maxi=i=k;i<lenth;i++)
		{
			if(temp_a[i][j]>temp_a[maxi][j])
			{
				maxi=i;
			}
		}
		if(maxi!=k)
		{
			exchange_hang(k,maxi);
			for(j=0;j<lenth;j++)
			{
				temp=temp_a[k][j];
				temp_a[k][j]=temp_a[maxi][j];
				temp_a[maxi][j]=temp;
			}
		}
		for(i=k+1;i<lenth;i++)
		{
			lik=temp_a[i][k]/temp_a[k][k];
			for(j=k;j<lenth;j++)
			{
				temp_a[i][j]=temp_a[i][j]-temp_a[k][j]*lik;
			}
			temp_b[i]=temp_b[i]-temp[k]*lik;
		}
	}
	if(temp_a[lenth-1][lenth-1]==0)
	{
		return 0;
	}
	return 1;
}

void exchange_hang(int m,int n)
{
	int j;
	double temp;
	for(j=0;j<lenth;j++)
	{
		temp=a[m][j];
		a[m][j]=a[n][j];
		a[n][j]=temp;
	}
	temp=b[m];
	b[m]=b[n];
	b[n]=temp;
}

void exchange(int m,int i)
{
	int temp;
	temp=A_y[m];
	A_y[m]=A_y[i];
	A_y[i]=temp;
}

void exchange_lie(int j)
{
	double temp;
	int i;
	for(i=0;i<lenth;i++)
	{
		temp=a[i][j];
		a[i][j]=b[i];
		b[i]=temp;
	}
}

void exchange_a_lie(int m,int n)
{
	double temp;
	int i;
	for(i=0;i<lenth;i++)
	{
		temp=a[i][m];
		a[i][m]=a[i][n];
		a[i][n]=temp;
	}
}

void exchange_x(int m,int n)
{
	char temp;
	temp=x[m];
	x[m]=x[n];
	x[n]=temp;
}

void recovery()
{
	int i,j;
	for(i=0;i<lenth;i++)
	{
		for(j=0;j<lenth;j++)
		{
			a[i][j]=copy_a[i][j];
		}
	}
	for(i=0;i<lenth;i++)
	{
		b[i]=copy_b[i];
	}
	for(i=0;i<lenth;i++)
	{
		x[i]='a'+1;
	}
	a_sum=0;
	lenth=copy_lenth;
}