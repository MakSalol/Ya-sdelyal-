#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
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
	dur.change(dur.hour, dur.min);
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
	vector<Duration> a;
	Duration dur1;
		cin >> dur1;
		dur1.change(dur1.hour, dur1.min);
		a.push_back(dur1);
	Duration dur2;
		cin >> dur2;
		dur2.change(dur2.hour, dur2.min);
		a.push_back(dur2);
	Duration dur3;
		cin >> dur3;
		dur3.change(dur3.hour, dur3.min);
		a.push_back(dur3);
			auto SortDuration = [&a](){
	sort(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++){
			cout << a[i] << " ";
		}
	};
		SortDuration();

}


