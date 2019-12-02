#include <iostream>
#include <math.h>
using namespace std;
int main() 
{
Start:
	int menu=0;																																				//Menu
	cout << "Menu\n[1]slove quadratic equation\n[2]Normal calculator\n[3]For updating\n[4]information\n[5]Exit\nChoose a Program\n" ;						//Menu info
	cin >> menu;																																			//Menu input
	if (menu == 1)		//Menu
	{
		double a, b, c, xi, xii, delta, i;	//varies
		cout << "ax^2+bx+c=0 " << endl << "input a=";
		cin >> a;
		cout << "input b=";
		cin >> b;
		cout << "input c=";
		cin >> c;
		delta = b * b - 4 * a * c;	//calculate
		i = sqrt(delta);
		xi = (-b - i) / (2 * a);
		xii = (-b + i) / (2 * a);
		if (delta > 0)
		{
			cout << "x1=" << xi << endl << "x2=" << xii << endl;
			system("pause");
			goto Start;								//go back
		}
		else if (delta < 0)
		{
			cout << "No solution" << endl;
			system("pause");
			goto Start;								//go back
		}
		else
		{
			cout << "x=" << xi << endl;
			system("pause");
			goto Start;								//go back
		};
	}
	else if (menu == 2)		//Menu
	{
	Calculate:
		int calculation, e;			//Menu 2 and varies
		double a, b, c, d, f, g, h;	//varies
		cout << "Choose the calculation" << endl << "[1]Addition and Subtraction" << endl << "[2]Multiplication" << endl << "[3]Division" << endl << "[4]Exit" << endl;		//Menu 2 info
		cin >> calculation;																																					//Menu 2 input
		if (calculation == 1)	//Menu 2
		{
			cout << "a+b=c" << endl << "input a" << endl;	//Addition
			cin >> a;
			cout << "input b" << endl;
			cin >> b;
			c = a + b;
			if (b < 0)
			{
				cout << a << b << "=" << c << endl;
			}
			else
			{
				cout << a << "+" << b << "=" << c << endl;
			};
			system("pause");
			goto Calculate;									//go back
		}
		else if (calculation == 2)	//Menu 2
		{
			cout << "a*b=c" << endl << "input a" << endl;	//Multiplication
			cin >> a;
			cout << "input b" << endl;
			cin >> b;
			c = a * b;
			if (b < 0)
			{
				cout << a << "*" << "(" << b << ")" << "=" << c << endl;
			}
			else
			{
				cout << a << "*" << b << "=" << c << endl;
			};
			system("pause");
			goto Calculate;									//go back
		}
		else if (calculation == 3)	//Menu 2
		{
			cout << "a/b=c" << endl << "input a" << endl;	//Division
			cin >> a;
			cout << "input b" << endl;
			cin >> b;
			f = a / b;
			g = a;
			h = b;
			d = 0;
			c = 0;
			if (b == 0)
			{
				cout << "error" << endl;
				system("pause");
				goto Calculate;
			}
			else
			{
				if(a < 0)
				{
					cout << g << "/" << h << "=" << f << endl;
					system("pause");
					goto Calculate;								//go back
				}
				else if(b < 0)
				{
					cout << g << "/" << h << "=" << f << endl;
					system("pause");
					goto Calculate;								//go back
				}
				else if ((a - b) < 0)
				{
					cout << g << "/" << h << "=" << f << endl << "Or  " << g << "/" << h << "=" << "0" << "......" << g << endl;
					system("pause");
					goto Calculate;								//go back
				}
				else
				{
					for (int e = 0; e >= 0; e = c - b)
					{
						c = a - b;
						d = d + 1;
						a = c;
					}
					cout << g << "/" << h << "=" << f << endl << "Or  " << g << "/" << h << "=" << d << "......" << c << endl;
					system("pause");
					goto Calculate;								//go back
				}
			};
		}
		else if (calculation == 4)							//Menu 2
		{
			goto Start;										//go back
		};
	}
	else if (menu == 3)
	{
		cout << "To be continue" << endl;
		system("pause");
		goto Start;
	}
	else if (menu == 4)
	{
		cout << "build it together" << endl << " https://github.com/SHMO-Group/SHMO" << endl;
		system("pause");
		goto Start;
	}
	else													//Menu																															//Menu
	{
		return 0;											//Exit
	};
}
