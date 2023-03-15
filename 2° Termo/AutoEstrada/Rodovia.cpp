#include <iostream>
using namespace std;
int main()
{
	int c, paineis=0;
	cin >> c;
	char rodovias[c];
	cin >> rodovias;
	for(int i=0; i < c;i++)
	{
		if (rodovias[i] == 'P')
		{
		paineis += 2;
		}
		if (rodovias[i] == 'C')
		{
		paineis += 2;
		}
			if (rodovias[i] == 'A')
		{
		paineis += 1;
		}
			if (rodovias[i] == 'D')
		{
		paineis += 0;
		}
	}
	cout << paineis;
}