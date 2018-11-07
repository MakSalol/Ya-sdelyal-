#include <iostream>
#include <iomanip>
using namespace std;

class  Duration {
public:
	int hour;
	int min;
	void change(int h, int m){
		h=hour;
		m=min;
		hour = hour + min/60;
		min = min % 60;
	}
	};

ostream& operator<<(ostream& stream, Duration& dur){
stream<< setfill('0');
stream<< setw(2) << dur.hour << ":" << setw(2) << dur.min;

return stream;
}

istream& operator>>(istream& stream, Duration& dur){
	stream >> dur.hour >> dur.min;
	return stream;
}






int main() {
	Duration dur1;
	cin >> dur1;
	Duration dur2;
	cin >> dur2;
	cout << dur1 << endl << dur2;

}
