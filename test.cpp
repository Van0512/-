#include "Clock.h"

int main(void) {
	SYSTEMTIME time;
	GetLocalTime(&time);

	Clock clock(time.wHour, time.wMinute, time.wSecond);
	cout << "启动程序时间是：";
	clock.showTime();
	cout << endl;
	clock.run();

	system("pause");
	return 0;
}