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

ostream& operator<<(ostream& stream, Duration& dur)
{
stream<< setfill('0');
stream<< setw(2) << dur.hour << ":" << setw(2) << dur.min;

return stream;
}

istream& operator>>(istream& stream, Duration& dur){
	stream >> dur.hour >> dur.min;
	return stream;
}


bool operator>(Duration& dur1, Duration& dur2){
	return dur1.hour > dur2.hour;
	return dur1.min > dur2.min;
}

bool operator<(Duration& dur1, Duration& dur2){
	return dur1.hour < dur2.hour;
	return dur1.min < dur2.min;
}



int main() {
	Duration dur1;
	cin >> dur1;
	dur1.change(dur1.hour, dur1.min);
	Duration dur2;
	cin >> dur2;
	dur2.change(dur2.hour, dur2.min);
	if (dur1.hour > dur2.hour){
			cout << dur1 ;
		}
		else if (dur2.hour > dur1.hour){
			cout << dur2 ;
		}
		else if (dur1.hour == dur2.hour) {
			if (dur1.min > dur2.min){
				cout << dur1 ;
			}
			else if (dur2.min > dur1.min){
			cout << dur2;
			}
		}
		if (dur1.hour == dur2.hour && dur1.min == dur2.min){
			cout << "dur1 = dur2";
		}
}
