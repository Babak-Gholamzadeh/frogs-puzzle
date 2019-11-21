#include <iostream>
#include <conio.h>

using namespace std;

int a[7] = {1, 1, 1, 0, 2, 2, 2}, start[7] = {1, 1, 1, 0, 2, 2, 2}, goal[7] = {2, 2, 2, 0, 1, 1, 1}, n[20], np = 0;
int test(void);
int f(int);
int check(int);
void step(void);
void display()
{
	for (int i=0; i<7; i++)
		cout << a[i] << " ";
	cout << endl << "-------------" << endl;
}
int main()
{
	for (int i=0; i<20; i++)
		n[i] = -1;
	display();
	f(3);
	for (int i=0; i<7; i++)
		a[i] = start[i];
    getch();
	step();
	display();
    return 0;
}
int f(int empty)
{
	int s;
	if (test() == 1)
		return 1;
	s = check(empty);
	while (s > 0)
	{
		a[empty] = a[s%10];
		a[s%10] = 0;
		if (f(s%10) == 1)
		{
			n[np++] = empty;
			return 1;
		}
		a[s%10] = a[empty];
		a[empty] = 0;
		s /= 10;
	}
	return 0;
}
int test()
{
	for (int i=0; i<7; i++)
		if (a[i] != goal[i])
			return 0;
	return 1;
}
int check(int empty)
{
	int s = 0;
	if (empty < 5)
		if (a[empty+2] == 2)
			s = s * 10 + (empty + 2);
	if (empty < 6)
		if (a[empty+1] == 2)
			s = s * 10 + (empty + 1);
	if (empty > 0)
		if (a[empty-1] == 1)
			s = s * 10 + (empty - 1);
	if (empty > 1)
		if (a[empty-2] == 1)
			s = s * 10 + (empty - 2);
	return s;
}
void step()
{
	for (int i=np-2; i>=0; i--)
	{
		a[n[i+1]] = a[n[i]];
		a[n[i]] = 0;
		display();
		getch();
	}
	a[n[0]] = a[n[np-1]];
   a[n[np-1]] = 0;
}
