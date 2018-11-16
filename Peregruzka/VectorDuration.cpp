#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class  Duration {
public:
	int hour;
	int min;
		 Duration (int h = 0, int m = 0){
		int total = h*60 + m;
		hour = total / 60;
		min = total % 60;
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
bool operator<(Duration& dur1, Duration dur2){
	if (dur1.hour == dur2.hour){
		return dur1.min < dur2.min;
	}
	return dur1.hour < dur2.hour;
}

bool operator>(Duration& dur1, Duration& dur2){
	if (dur1.hour == dur2.hour){
		return dur1.min > dur2.min;
	}
	return dur1.hour > dur2.hour;
}

Duration operator-(Duration& dur1, Duration& dur2){
	if (dur1 < dur2){
		Duration dur3(0,0);
		return dur3;
	}
	Duration dur3(dur1.hour - dur2.hour, dur1.min - dur2.min);
	return dur3;
}

int main() {
	vector <Duration> a;
	Duration dur1(1,20);
	Duration dur2(2,30);
	Duration dur3(1,70);
	a.push_back(dur1);
	a.push_back(dur2);
	a.push_back(dur3);
	auto SortDuration = [&a](){
		sort(a.begin(), a.end());
			for (int i = 0; i < a.size(); i++){
				cout << a[i] << " ";
			}
		};
			SortDuration();

	}
