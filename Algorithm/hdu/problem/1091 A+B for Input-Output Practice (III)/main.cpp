#include <iostream>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int a,b;
	while(cin>>a>>b,a||b)
	{
		cout<<a+b<<endl;
	}
	return 0;
}