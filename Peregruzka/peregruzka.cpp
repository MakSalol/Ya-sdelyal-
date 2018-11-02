#include <iostream>
#include <iomanip>
using namespace std;

class  Duration {
public:
	int hour;
	int min;
	};

ostream& operator<<(ostream& stream, Duration& dur)
{
stream<< setfill('0');
stream<< setw(2) << dur.hour << ":" << setw(2) << dur.min;

return stream;
}

Duration operator+(Duration& dur1, Duration& dur2){
	int a=dur1.hour+dur2.hour;
	int b=dur1.min+dur2.min;

	dur1.hour=a;
	dur1.min=b;
	return dur1;
}

int main() {
	int a,b;
	Duration dur1;
	cin >> a >> b;
	Duration dur2;
	cin >> a >> b;
	Duration dur3;
	dur3=dur1+dur2;
	if (dur3.min > 60) {
		dur3.hour = dur3.hour + (dur3.min/60);
		dur3.min %= 60;
	}
	cout << dur3;
}














/*class Duration
   {

   public:
    int hour;
	int min;
	void change(int h,int m)
	{
		hour=h;
		min=m;
		if(min>60)
		{
			hour=hour+(min/60);
			min%=60;
		}
		if(hour>24)
		{
			hour%=24;
		}
	}
};*/



/*Duration operator+( Duration& dur1, const Duration& dur2)
{
    int a=dur1.hour+dur2.hour;
    int b=dur1.min+dur2.min;

    dur1.hour=a;
    dur1.min=b;
    return dur1;*/




/*
 *int main()
{
	int a,b;


   Duration dur1;
   cin>>a>>b;
   dur1.change(a,b);
   Duration dur2;
    cin>>a>>b;
   dur2.change(a,b);
   Duration dur3;
   dur3=dur1+dur2;
   if (dur3.min>60)
   {
	   dur3.hour=dur3.min/60+dur3.hour;
	   dur3.min=dur3.min%60;
   }
   if (dur3.hour>24)
    {
	   dur3.hour%=24;
	}
   cout<<dur3;
}
 */
