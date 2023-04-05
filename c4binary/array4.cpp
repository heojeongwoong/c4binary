#include <iostream>
using namespace std;
void main() {
	int *sum, N;
	float *root,*woong;
	sum = new int[10];
	root = new float[10];
	woong = new float[10];

	for (int i = 0; i < 10; i++) {
		N = i + 1;
		sum[i] = N * (N + 1) / 2;
		root[i] = sqrt((float)N);
		woong[i] = N +1;

	}
	sum[5] = 1;        //   *(sum + 5) = 1;
	root[6] = 0.0;    //   *(root + 6) = 0.0;
	for (int i = 0; i < 10; i++)
		cout << sum[i] << "   " << root[i] << "                " << woong[i]<< endl;
	getchar();
}