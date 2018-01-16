#include"CrudeTimer.h"
unsigned int timeGetTime()
{
struct timeval now;
gettimeofday(&now, NULL);
return now.tv_usec/1000;
}

CrudeTimer*CrudeTimer::Instance(){
	static CrudeTimer instance;
	return &instance;
}
