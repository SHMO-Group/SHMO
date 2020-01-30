#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <conio.h>
#include <sstream> 
using namespace std;

int Menu();
string getequa();
string Calculate();

int main() 
{
	while(1)
	{
		int choice;
		choice=Menu();
		if(choice==1)
		{
			while(1)
			{ 
			string answer;
			answer=Calculate();
			cout<<answer<<endl;
			}
			system("cls"); 
		}
		else if(choice==2)
		{
			cout<<"Still Making.."<<endl;
			system("pause");
			system("cls");
		}
		else if(choice==3)
		{
			return 0;
		};
	};
}

int Menu()
{
	char choice;
	while(1)
	{
		cout<<"Math Calculator New"<<endl;
		cout<<"[1]Simple Calculation\n[2]Functions\n[3]About\n[4]Quit"<<endl;
		choice=getch();
		system("cls");
		if(choice=='1'||choice=='!')
		{
			return 1;
			break;
		}
		else if(choice=='2'||choice=='@')
		{
			return 2;
			break;
		}
		else if(choice=='3'||choice=='#')
		{
			cout<<"Made by Dongsheng\nlast updated at 2020/1/29"<<endl;
			system("pause");
			system("cls");
		}
		else if(choice=='4'||choice=='$')
		{
			return 3;
			break;
		}
		else
		{
		};
	};
};

string Calculate()
{
	vector<long double> data;
	vector<char> symbol;
	string temp,output,equation;
	long double answer;
	equation=getequa();
	if(equation[0]<48||equation[0]>57)
	{
		return "Error"; 
	}; 
	for(int i=0;i<equation.size();i++)
	{
		string temp1;
		string temp2;
		for(;(i<equation.size()-1&&equation[i]>=48&&equation[i]<=57)||equation[i]==46;i++)
		{
			temp2+=equation[i];
		};
		if(temp2.empty())
		{
			return "Error";
		};
		data.push_back(stold(temp2,0));
		symbol.push_back(equation[i]);
	};
	for(int i=0;i<symbol.size();)
	{ 
		if(symbol[i]=='*')
		{
			data[i]=data[i]*data[i+1];
			data.erase(data.begin()+i+1);
			symbol.erase(symbol.begin()+i);
		}
		else if(symbol[i]=='/')
		{
			data[i]=data[i]/data[i+1];
			data.erase(data.begin()+i+1);
			symbol.erase(symbol.begin()+i);
		}
		else
		{
			i++;
		};
	};
	while(symbol.size()>1)
	{
		if(symbol[0]=='+')
		{
			data[0]=data[0]+data[1];
			data.erase(data.begin()+1);
			symbol.erase(symbol.begin());
		}
		else if(symbol[0]=='-')
		{
			data[0]=data[0]-data[1];
			data.erase(data.begin()+1);
			symbol.erase(symbol.begin());
		}
	}
	stringstream temp3;
	temp3<<data[0];
	temp3>>output;
	return output;
};

string getequa()
{
	string temp1;
	char temp2;
	cout<<"Input an equation"<<endl;
	while(1)
	{
		temp2=getch();
		temp1+=temp2;
		cout<<temp2;
		if(temp2=='=')
		{
			return temp1; 
		};
	};
};
