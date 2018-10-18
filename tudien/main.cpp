#include <iostream>
using namespace std;
# include "dictree.h"
int main()
{
	DicTree t;
	t.Add("HELLO");
	t.Add("AN");
	t.Add("AND");
	t.Add("BY");
	t.Add("BYE");

	cout<<t.Search("AN")<<endl;
	cout<<t.Search("CAN")<<endl;
	return 0;
}