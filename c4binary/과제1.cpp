#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    const float pi = 3.141592;

    // Sprint 1
    char *header;
    header = new char[12];
    int* n;
    float* f;
    short* p;
    short* a;


    // Memory allocation
    
    p = (short*)(header + 10);
    n = (int*)header;
    f = (float*)(header + 4);

    // Casting
    *n = 500;
    *f = 1000.0;
    *p = 12;
    *a = 1000;

    // Binary file write
    ofstream out("a.dat", ios::binary | ios::out);
    if (!out) return 666;
    out.write(header, 12 * sizeof(char));
    out.close();

    // Sprint 2
 

    // Binary file read
    ifstream in("a.dat", ios::binary | ios::in);
    if (!in) return 666;
    in.read(header, 12 * sizeof(char));
    in.close();

    // Memory allocation
  
    f = (float*)(header + 4);


    // Confirmation
    cout << "f: " << *f <<  endl;

    // Value modification

    *f = 700.0;

    cout << "f: " << *f << endl;
    // Binary file write
    ofstream out2("b.dat", ios::binary | ios::out);
    if (!out2) return 666;
    out2.write(header, 12 * sizeof(char));
    out2.close();

    // Sprint 3
    short* data;
    // Memory allocation
    data = new short[*n];
  
   
        // Data calculation

    float dt = 1.0 / f[0] / 20.0;
    for (int i = 0; i < n[0]; i++) {
        data[i] = (short)(a[0] * sin(2 * pi * i * dt *f[0]));
        
    }

    // Binary file write
    ofstream out3("a.dat", ios::binary | ios::out);
    if (!out3) return 666;
    out3.write(header, 12 * sizeof(char));
    out3.write((char*)data, n[0] * sizeof(short));
    out3.close();

    delete[] data;
    delete[] a;
   
    // Sprint 4
    short *data1,*data2;
    data1 = new short[n[0]];
    data2 = new short[n[0]];


    // Read data from binary file

    ifstream in2("a.dat", ios::binary | ios::in);
    if (!in2) return 666;
    in2.read(header, 12 * sizeof(char));
    in2.read((char*)data1, *n * sizeof(short));
    in2.close();

    ifstream in3("b.dat", ios::binary | ios::in);
    if (!in3) return 666;
    in3.read(header, 12 * sizeof(char));
    in3.read((char*)data2, *n * sizeof(short));
    in3.close();

    // Write data to text file
    ofstream out4("c.txt");
    if (!out4) return 666;
    for (int i = 0; i <n[0]; i++) {
        out4 << i * dt << " " << data1[i] << " " << data2[i] << endl;
    }
    out4.close();

  
    return 0;
}