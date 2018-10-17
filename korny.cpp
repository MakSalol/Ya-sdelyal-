#include <iostream>
#include <cmath>
using namespace std;

int main() {
double a,b,c,d,x1,x2;
cin >> a >> b >> c;
d=b*b-4*a*c;
x1=(-b + sqrt(d))/(2*a);
x2=(-b - sqrt(d))/(2*a);
if (a==0) {
	cout << -c/b;
}
else if (d<0) {
	cout << "Решений нет";
}
else if (d==0) {
	cout << "x=" << -b/(2*a);
}
else cout << "x1=" << x1 << " " << "x2=" << x2;
}


