#pragma once

#include <windows.h>
#include <iostream>
using namespace std;

class Clock {
public:
	Clock(const WORD &hour, const WORD &minute, const WORD &second);
	void run();
	void showTime();
private:
	WORD hour;
	WORD minute;
	WORD second;
};

inline
Clock::Clock(const WORD &hour, const WORD &minute, const WORD &second) :
	hour(hour), minute(minute), second(second) {}

inline
void Clock::showTime() {
	printf("%02d:%02d:%02d", hour, minute, second);
}

void Clock::run() {
	WORD ringsTime(0);
	while (true) {
		second = ++second % 60;
		if (second == 0) {
			minute = ++minute % 60;
			if (minute == 0)
				ringsTime = hour = ++hour % 24;
		}

		//cout << "\r                                             \r";
		cout << "\r��ǰʱ�䣺";
		showTime();

		if (minute == 0 && second == 0) {
			cout << endl << "�����ʱ���ǣ�";
			showTime();
			cout << endl;
		}
		if (minute == 0 && second < ringsTime) cout << '\007';
		if (hour == 0 && minute == 0 && second == 0) cout << '\007';		/*0��Ҳ����һ��*/
		Sleep(1000);
	}
}