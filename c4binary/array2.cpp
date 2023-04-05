#include <iostream>
using namespace std;
void main() {
	int sum[15], N;
	float root[15];
	for (int i = 0; i < 15; i++) {
		N = i + 1;
		sum[i] = N * (N + 1) / 2;
		root[i] = sqrt((float)N);
	}
	sum[6] = 9999;      
	root[7] = 8888;    
	for (int i = 0; i < 15; i++)
		cout << sum[i] << "   " << root[i] << endl;
	getchar();
}