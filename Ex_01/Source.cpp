#include "LV.h"
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	LorentzVector v, y, u;
	int num;
	cout << "V U NUM";
	cin >> v >> u >> num;
	y = v;
	y += u;
	cout << "Sum: " << v + u << " (y == v) +=u ==" << y << endl;
	y -= v;
	cout << "Sub: " << v - u << " y -=v ==" << y << endl;
	y *= v;
	cout << "Mul v u: " << v * u << " y *=v ==" << y << endl;
	y *= num;
	cout << "Sum v num: " << v * num << " y *= num == " << y << endl;
	cout << "Sum num v: " << num * v << endl;
	cout << "Indirect convert v: " << v.IndirectConvert(0.5) << endl;
	cout << "Direct convert v: " << v.DirectConvert(0.5) << endl;
	cout << "Norm v: " << v.norm() << endl;
}
