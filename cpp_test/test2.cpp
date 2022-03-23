//自动生成真值表 
//varchar变长字符数组类型
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int Getlength(char* start);//用于测量字符数组中的有效长度 
int Copyalpha(char *a,char* b);//用于将a字符数组中字母复制到b数组中并存储 
bool compare(char a,char b);//用于和sort函数搭配使得函数的排序顺序变为由大到小 
void testprint(char* start);//用于测试其他函数工作是否正常
void printheadline(char* b,int numbersofalpha,char* a);
void simplify(char* start);//用于将已经得到的真值表进行化简 
char trans(int);//用于将整数转化为对应的字符 
//用于打印真值表的首行 
//参数为a、b数组和b数组中的有效字母的个数 
void translate(int len,char* list);//用于解释已经储存的主析取和主合取的范式（数字编码转字符编码） 
int dothemathandprintandstorage(char* a,char* b,char* result,int* truetable,int times);
//用于将每行的真值表自动生成
//并将计算结果（0/1）返回 
//参数的接口有
/* 
	原来的逻辑语句储存数组a
	储存有效字母的字符数组（按照升序排列）b
	用于储存每一次真值表的暂存数组truetable
	记录是第几行的参数times 
*/ 
int zxq[1050000];
int zhq[1050000];//最大可以承受20个不同变量的运算 
int main(){
    system("chcp 65001");
	char a[100],b[100];
	for(int i=0;i<1050000;i++){
		zxq[i]=zhq[i]=-1;
	}	
	cout<<"  ____________________________"<<endl;
	cout<<" |公式输入规范：              |"<<endl;
	cout<<" |析取+                       |"<<endl;
	cout<<" |合取*                       |"<<endl;
	cout<<" |条件-                       |"<<endl;
	cout<<" |双条件=                     |"<<endl;
	cout<<" |否定！                      |"<<endl;
	cout<<" |括号()                      |"<<endl;
	cout<<" |                            |"<<endl;  
	cout<<" |     最大20个变量上限       |"<<endl; 
	cout<<" |Versin 18.4.5 软件 lift |"<<endl;
	cout<<" |____________________________|"<<endl;
	cout<<endl; 
	cout<<"请输入公式："; 
	cin>>a;  
	cout<<endl<<"真值表:"<<endl; 
	int lenofalpha=Copyalpha(a,b);
	printheadline(b,lenofalpha,a);
	char result[lenofalpha+1];
	int truenumber[lenofalpha];
	int times=0,max=pow(2,lenofalpha);
	zhq[0]=zxq[0]=0;
	while(times<max){
		for(int i=0;i<lenofalpha;i++){
			truenumber[i]=0;
		}
		dothemathandprintandstorage(a,b,result,truenumber,times);
		times++;
	}
	int lengthofline=Getlength(b)*2+3+Getlength(a);
	for(int i=0;i<lengthofline;i++){
		cout<<'-';
	}
	cout<<endl;
	translate(lenofalpha,b);
	return 0;
} 
int Copyalpha(char* a,char* b){
	int lenofa=Getlength(a);
	for(int i=0;i<lenofa;i++){
		b[i]=1;
	}
	int lenofb=Getlength(b);
	int endposition=0,pd=0;
	for(int i=0;i<lenofa;i++){
		if((a[i]>='a')&&(a[i]<='z')||(a[i]>='A')&&(a[i]<='Z')){
			pd=0;
			for(int j=0;j<endposition;j++){
				if(a[i]==b[j])pd=1;
			}
			if(pd==0){
				b[endposition]=a[i]; 
				endposition++;
			}
		}
	}	
	b[endposition]='\0'; 
	char temp=1;
	for(int i=0;i<endposition;i++){
		for(int j=i+1;j<endposition;j++){
			if(b[i]>b[j]){
				temp=b[i];b[i]=b[j];b[j]=temp;
			}
		}
	}
	return endposition;
}
void testprint(char* start){
	char *p=start;
	while(*p!='\0'){
		cout<<*p;
		p++;
	}
	p=NULL; 
	start=NULL; 
	cout<<endl;
} 
int Getlength(char* start){
	char* p=start;
	int len=0;
	while(*p!='\0'){
		p++;
		len++;
	}
	p=NULL;
	start=NULL;
	return len;
}
int dothemathandprintandstorage(char* a,char* b,char* result,int* truetable,int times){
	int lenofa=Getlength(a);
	int iforresult=0;
	for(iforresult=0;iforresult<lenofa;iforresult++){
		result[iforresult]=a[iforresult];
	} 
	result[iforresult]='\0';
	int lenofalpha=Getlength(b);
	int position=0;
	int temptimes=times;
	while(temptimes>0){
		truetable[position]=temptimes%2;
		position++;
		temptimes/=2;
	} 
	int temp=0,exlimit=0;
	int realtable[lenofalpha];
	for(int i=0;i<lenofalpha;i++){
		realtable[i]=truetable[lenofalpha-i-1];
	} 
	for(int i=0;i<lenofalpha;i++){
		truetable[i]=realtable[i];
	}
	//开始对其中的字母与标准字母进行比对并分配真值 
	for(int i=0;i<lenofa;i++){
		for(int j=0;j<lenofalpha;j++){
			if(result[i]==b[j]){
				result[i]=trans(truetable[j]);
			}	
		}
	} 
	int formerlength=Getlength(result);
	simplify(result);
	int latterlength=Getlength(result);
	if(formerlength!=latterlength){
		while(formerlength!=Getlength(result)){
			formerlength=Getlength(result);
			simplify(result);
			latterlength=Getlength(result); 
		}
	}
	int jforrem=0;
	if(Getlength(result)!=1){
		result[0]='e';
		result[1]='r';
		result[2]='r';
		result[3]='o';
		result[4]='r';
		result[5]='\0';
	} 
	//用于储存主析取范式或主合取范式
	else if(result[0]=='1'){
		jforrem=0;
		int end=1+zxq[0]*lenofalpha+lenofalpha;
		for(int i=1+zxq[0]*lenofalpha;i<end;i++){
			zxq[i]=truetable[jforrem];
			jforrem++;
		}
		zxq[0]+=1;
	}
	else if(result[0]=='0'){
		jforrem=0;
		int end=1+zhq[0]*lenofalpha+lenofalpha;
		for(int i=1+zhq[0]*lenofalpha;i<end;i++){
			zhq[i]=truetable[jforrem];
			jforrem++;
		}
		zhq[0]+=1;
	}
	for(int i=0;i<lenofalpha;i++){
		cout<<setw(2)<<truetable[i];
	}
	cout<<" | "<<result<<endl;
	return 0;	 
}  
void printheadline(char* b,int numbersofalpha,char* a){
	int lengthofline=numbersofalpha*2+3+Getlength(a);
	for(int i=0;i<lengthofline;i++){
		cout<<'-';
	}
	cout<<endl;
	for(int i=0;i<numbersofalpha;i++){
		cout<<right<<setw(2)<<b[i];
	} 
	cout<<' '<<'|'<<' '<<a;
	cout<<endl;
	for(int i=0;i<lengthofline;i++){
		cout<<'-';
	}
	cout<<endl;
} 
char trans(int a){
	return a+'0';
} 
void simplify(char* a){
	int point=0,j=point,pd=0;
	//化简！,优先级最高 
	while(point<Getlength(a)){
		j=point;pd=0;
		if(((j+1)<Getlength(a))&&(a[j]=='!')&&(a[j+1]=='1')){
			a[j]='0';pd=1;
		}
		else if(((j+1)<Getlength(a))&&(a[j]=='!')&&(a[j+1]=='0')){
			a[j]='1';pd=1;
		}
		if(pd==1){
			j++;
			while(a[j+1]!='\0'){
				a[j]=a[j+1];//所有的都向前面挪动一个单位，包括'\0' 
				j++;
			}
			a[j]='\0';
		}
		else point++; 
	} 
	//化简合取范式
	point=j=0,pd=0;
	while(point<Getlength(a)){
		j=point;pd=0;
		if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='*')&&(a[j+2]=='0')){
			a[j]='0';pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='*')&&(a[j+2]=='1')){
			a[j]='0',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='*')&&(a[j+2]=='1')){
			a[j]='1',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='*')&&(a[j+2]=='0')){
			a[j]='0',pd=1;
		}
		if(pd==1){
			j++;
			while(a[j+2]!='\0'){
				a[j]=a[j+2];
				j++;
			}
			a[j]='\0';
		}
		else point++;
	} 
	//化简（） 
	point=j=0,pd=0;
	while(point<Getlength(a)){
		j=point;pd=0;
		if((j+2<Getlength(a))&&(a[j]=='(')&&(a[j+1]=='1')&&(a[j+2]==')')){
			a[j]='1';pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='(')&&(a[j+1]=='0')&&(a[j+2]==')')){
			a[j]='0',pd=1;
		}
		if(pd==1){
			j++;
			while(a[j+2]!='\0'){
				a[j]=a[j+2];
				j++;
			}
			a[j]='\0';
		}
		else point++;
	}
	//化简双条件 
	point=j=0,pd=0;
	while(point<Getlength(a)){
		j=point;pd=0;
		if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='=')&&(a[j+2]=='0')){
			a[j]='1';pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='=')&&(a[j+2]=='1')){
			a[j]='0',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='=')&&(a[j+2]=='1')){
			a[j]='1',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='=')&&(a[j+2]=='0')){
			a[j]='0',pd=1;
		}
		if(pd==1){
			j++;
			while(a[j+2]!='\0'){
				a[j]=a[j+2];
				j++;
			}
			a[j]='\0';
		}
		else point++;
	}
	//化简单条件 
	point=j=0,pd=0;
	while(point<Getlength(a)){
		j=point;pd=0;
		if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='-')&&(a[j+2]=='0')){
			a[j]='1';pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='-')&&(a[j+2]=='1')){
			a[j]='1',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='-')&&(a[j+2]=='1')){
			a[j]='1',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='-')&&(a[j+2]=='0')){
			a[j]='0',pd=1;
		}
		if(pd==1){
			j++;
			while(a[j+2]!='\0'){
				a[j]=a[j+2];
				j++;
			}
			a[j]='\0';
		}
		else point++;
	}	
	//化简析取范式
	point=j=0,pd=0;
	while(point<Getlength(a)){
		j=point;pd=0;
		if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='+')&&(a[j+2]=='0')){
			a[j]='0';pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='0')&&(a[j+1]=='+')&&(a[j+2]=='1')){
			a[j]='1',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='+')&&(a[j+2]=='1')){
			a[j]='1',pd=1;
		}
		else if((j+2<Getlength(a))&&(a[j]=='1')&&(a[j+1]=='+')&&(a[j+2]=='0')){
			a[j]='1',pd=1;
		}
		if(pd==1){
			j++;
			while(a[j+2]!='\0'){
				a[j]=a[j+2];
				j++;
			}
			a[j]='\0';
		}
		else point++;
	} 
}
void translate(int len,char* list){
	cout<<endl;
	if(zhq[0]==0)cout<<"主合取范式不存在";
	else{
		cout<<"主合取范式："<<endl; 
		int i=1,yc=1;
		while(zhq[i]!=-1){
			if(yc==1){
				cout<<'(';
				yc=0;
			}
			else cout<<"*(";
			for(int j=0;(j<len)&&(zhq[i]!=-1);j++,i++){
				if(j==len-1){
					if(zhq[i]==0){
						cout<<list[j]<<')';
					}
					else cout<<"!"<<list[j]<<')';
				}
				else{
					if(zhq[i]==0){
						cout<<list[j]<<'+';
					}
					else cout<<"!"<<list[j]<<'+';
				} 
			}	 
		}
	} 
	if(zxq[0]==0)cout<<endl<<"主析取范式不存在";
	else{
		cout<<endl<<"主析取范式："<<endl; 
		int i=1,yc=1;
		while(zxq[i]!=-1){
			if(yc==1){
				cout<<'(';
				yc=0;
			}
			else cout<<"+(";
			for(int j=0;(j<len)&&(zxq[i]!=-1);j++,i++){
				if(j==len-1){
					if(zxq[i]==1){
						cout<<list[j]<<')';
					}
					else cout<<"!"<<list[j]<<')';
				}
				else{
					if(zxq[i]==1){
						cout<<list[j]<<'*';
					}
					else cout<<"!"<<list[j]<<'*';
				}
			}	 
		}
	}
    system("pause"); 
}
