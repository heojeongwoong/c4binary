#include <iostream>
using namespace std;
void main() {
	int sum[10], N;
	float root[10];
	for (int i = 0; i < 10; i++) {
		N = i + 1;
		*(sum + i) = N * (N + 1) / 2;
		*(root + i) = sqrt((float)N);
	}
	sum[3] = 99999;
	root[3] = 77777;

	for (int i = 0; i < 10; i++)
		cout << sum[i] << "   " << root[i] << endl;
	getchar();
}
 