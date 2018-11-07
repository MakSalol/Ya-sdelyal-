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
		 if (min < 0) {
			hour = hour - 1;
			min = min + 60;
		}
	}
	};

ostream& operator<<(ostream& stream, Duration& dur)
{
stream<< setfill('0');
stream<< setw(2) << dur.hour << ":" << setw(2) << dur.min;

return stream;
}

Duration operator-(Duration& dur1, Duration& dur2){
	int a=dur1.hour-dur2.hour;
	int b=dur1.min-dur2.min;

	Duration dur3;
	dur3.hour=a;
	dur3.min=b;
	dur3.change(a,b);
	return dur3;
}

int main() {
	Duration dur1;
	cin >> dur1.hour >> dur1.min;
	Duration dur2;
	cin >> dur2.hour >> dur2.min;
	Duration dur3;
	dur3=dur1 - dur2;
	if (dur3.hour < 0){
		cout << "Error";
	}
	else cout << dur3;
}



